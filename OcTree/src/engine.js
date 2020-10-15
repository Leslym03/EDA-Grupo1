class Engine{

	constructor(canvasId){
      this.canvas = document.getElementById(canvasId);
      this.THETA = 0,
      this.PHI = 0;
      this.time_old = 0;      
      this.drag = false;
      this.AMORTIZATION = 0.95;
      this.old_x;
      this.old_y;
      this.dX = 0;
      this.dY = 0;
   }
	init(){
		this.initMatrix();
		this.initShaders();
		this.initModels();
		this.initUniforms();
	}	
	initMatrix(){
         this.getProjection = function(angle, a, zMin, zMax) {
            var ang = Math.tan((angle*.5)*Math.PI/180);//angle*.5
            return [
               0.5/ang, 0 , 0, 0,
               0, 0.5*a/ang, 0, 0,
               0, 0, -(zMax+zMin)/(zMax-zMin), -1,
               0, 0, (-2*zMax*zMin)/(zMax-zMin), 0 
			   ];
         }

         this.projectionMatrix = this.getProjection(40, this.canvas.width/this.canvas.height, 1, 100);
         this.modelMatrix = [ 1,0,0,0, 0,1,0,0, 0,0,1,0, 0,0,0,1 ];
         this.viewMatrix = [ 1,0,0,0, 0,1,0,0, 0,0,1,0, 0,0,0,1 ];

         this.viewMatrix[14] = this.viewMatrix[14]-6;
		 
	}

	initShaders(){
      this.shaderProgram = new Shader();		
	}
	
	initModels(){
      var point = new Point(0, 0, 0);
      var colorPurple = new Color(0.56, 0, 0.66, 0.5);      
      this.cube = new Cube(point, 2, colorPurple);
      this.ot = new OcTree(this.cube, 4);
      
      for( let i = 0; i < 0; ++i ) {
         var p = new Point(this.randomNumber(-2, 2), this.randomNumber(-2,2), this.randomNumber(-2,2));
         this.ot.insert(p);
      }
   
      var colorQuery = new Color(0,0,0,0.5);
      var pQuery = new Point(0.5,0.5,0.5);
      this.consulta = new Cube(pQuery, 1, colorQuery);
      this.consulta.init();
      this.meshQuery = new Mesh(pQuery, this.consulta.vertices, this.consulta.colors, this.consulta.indices);
      this.meshQuery.initBuffers();
      
      var puntos = [];
      this.ot.query(this.consulta, puntos);
      console.log(puntos);
      console.log(this.ot);
   }

   changeOctreeTransparency(){
      if(meshes[0].colors[3] === 0.5){
         for(let i = 0; i < meshes.length; ++i){
            let colorTransparente = new Color(meshes[i].colors[0], meshes[i].colors[1], meshes[i].colors[2], 0);
            meshes[i].pintar(colorTransparente);
         }
      }else{
         for(let i = 0; i < meshes.length; ++i){
            let colorTransparente = new Color(meshes[i].colors[0], meshes[i].colors[1], meshes[i].colors[2], 0.5);
            meshes[i].pintar(colorTransparente);
         }
      }

   }
   QueryDinamic(){
      var puntos = [];
      this.ot.query(this.consulta, puntos);
      console.log(puntos);
   }

   addRandomPoint() {
      var point = new Point(this.randomNumber(-2, 2), this.randomNumber(-2,2), this.randomNumber(-2,2));
      if (this.ot.insert(point))
      console.log(point);
      else{
         console.log("ERROR! El punto no ha sido insertado");
      }
   }

   addPoint() {
      var x = parseFloat(document.getElementById('coordX').value);
      var y = parseFloat(document.getElementById('coordY').value);
      var z = parseFloat(document.getElementById('coordZ').value);
      var point = new Point(x, y, z);
      this.ot.insert(point);
      console.log(point);
   }

   //xd bajitos
   randomNumber(minimo, maximo){
      return (Math.random() * (maximo - minimo) + minimo );
    }

	initUniforms(){
         this.projectionMatrixUniformLocation = gl.getUniformLocation(this.shaderProgram.shaderProgramId, "Pmatrix");
         this.viewMatrixUniformLocation = gl.getUniformLocation(this.shaderProgram.shaderProgramId, "Vmatrix");
         this.modelMatrixUniformLocation = gl.getUniformLocation(this.shaderProgram.shaderProgramId, "Mmatrix");
   }
   
	updateMouseEvent(){
         
         this.mouseDown = function(e) {
            engine.drag = true;
            engine.old_x = e.pageX, engine.old_y = e.pageY;
            e.preventDefault();
            return false;
         };

         this.mouseUp = function(e){
            engine.drag = false;
         };

         this.mouseMove = function(e) {
            if (!engine.drag) return false;
            engine.dX = (e.pageX - engine.old_x)*2*Math.PI/engine.canvas.width,
            engine.dY = (e.pageY - engine.old_y)*2*Math.PI/engine.canvas.height;
            engine.THETA += engine.dX;
            engine.PHI += engine.dY;
            engine.old_x = e.pageX, engine.old_y = e.pageY;
            e.preventDefault();
         };

         this.canvas.addEventListener("mousedown", this.mouseDown, false);
         this.canvas.addEventListener("mouseup", this.mouseUp, false);
         this.canvas.addEventListener("mouseout", this.mouseUp, false);
         this.canvas.addEventListener("mousemove", this.mouseMove, false);
           
   }
   
   updateModelMovementEvent(mesh, model){
      this.keyDown = function(e){
         let aKey = 'A', dKey = 'D', wKey = 'W', sKey = 'S', qKey = 'Q', eKey = 'E';
         let direccion = new Point(0,0,0);         
         var puntos =[];

         switch(e.keyCode){
            case aKey.charCodeAt():
               direccion.x = -1;
               break;
            case dKey.charCodeAt():
               direccion.x = 1;
               break;
            case wKey.charCodeAt():
               direccion.y = 1;
               break;
            case sKey.charCodeAt():
               direccion.y = -1;
               break;
            case qKey.charCodeAt():
               direccion.z = 1;
               break;
            case eKey.charCodeAt():
               direccion.z = -1;
               break;
            default:
               break;
         }
         mesh.move(direccion);
         model.move(direccion);
         var cont = 0;
         engine.ot.query(engine.consulta, puntos);
      }
      document.addEventListener("keydown", this.keyDown); 
   }

   updateEvents(){
      this.updateMouseEvent();
      this.updateModelMovementEvent(this.meshQuery, this.consulta);
   }

	render(){
      this.animate = function(time) {
            if (!engine.drag) {
               engine.dX *= engine.AMORTIZATION, engine.dY *= engine.AMORTIZATION;
               engine.THETA += engine.dX, engine.PHI += engine.dY;
            }

            //set model matrix to I4

            engine.modelMatrix[0] = 1, engine.modelMatrix[1] = 0, engine.modelMatrix[2] = 0,
            engine.modelMatrix[3] = 0,

            engine.modelMatrix[4] = 0, engine.modelMatrix[5] = 1, engine.modelMatrix[6] = 0,
            engine.modelMatrix[7] = 0,

            engine.modelMatrix[8] = 0, engine.modelMatrix[9] = 0, engine.modelMatrix[10] = 1,
            engine.modelMatrix[11] = 0,

            engine.modelMatrix[12] = 0, engine.modelMatrix[13] = 0, engine.modelMatrix[14] = 0,
            engine.modelMatrix[15] = 1;

            engine.rotateX = function(m, angle) {
               var c = Math.cos(angle);
               var s = Math.sin(angle);
               var mv1 = m[1], mv5 = m[5], mv9 = m[9];
               
               m[1] = m[1]*c-m[2]*s;
               m[5] = m[5]*c-m[6]*s;
               m[9] = m[9]*c-m[10]*s;
               
               m[2] = m[2]*c+mv1*s;
               m[6] = m[6]*c+mv5*s;
               m[10] = m[10]*c+mv9*s;
               }
               
            engine.rotateY = function(m, angle) {
               var c = Math.cos(angle);
               var s = Math.sin(angle);
               var mv0 = m[0], mv4 = m[4], mv8 = m[8];
               
               m[0] = c*m[0]+s*m[2];
               m[4] = c*m[4]+s*m[6];
               m[8] = c*m[8]+s*m[10];
               
               m[2] = c*m[2]-s*mv0;
               m[6] = c*m[6]-s*mv4;
               m[10] = c*m[10]-s*mv8;
               }

            engine.rotateY(engine.modelMatrix, engine.THETA);
            engine.rotateX(engine.modelMatrix, engine.PHI);

            engine.time_old = time; 
          
            // gl.depthFunc(gl.LEQUAL);

            gl.clearColor(0.5, 0.5, 0.5, 0.0);
            gl.disable(gl.DEPTH_TEST);
            gl.depthFunc(gl.LEQUAL)
            gl.depthMask(false);
            gl.enable(gl.BLEND);
            gl.blendFunc(gl.SRC_ALPHA, gl.ONE_MINUS_SRC_ALPHA);
            

            gl.clearColor(0.5, 0.5, 0.5, 0.9);
            gl.clearDepth(1.0);
            gl.viewport(0.0, 0.0, engine.canvas.width, engine.canvas.height);
            gl.clear(gl.COLOR_BUFFER_BIT | gl.DEPTH_BUFFER_BIT);


            gl.uniformMatrix4fv(engine.projectionMatrixUniformLocation, false, engine.projectionMatrix);
            gl.uniformMatrix4fv(engine.viewMatrixUniformLocation, false, engine.viewMatrix);
            gl.uniformMatrix4fv(engine.modelMatrixUniformLocation, false, engine.modelMatrix);
            
            for(let i=0;i<meshes.length;i++){
               meshes[i].associateShadersBuffer(engine.shaderProgram.shaderProgramId);
               gl.drawElements(gl.TRIANGLES, meshes[i].indices.length, gl.UNSIGNED_SHORT, 0);
            }
            
            for(let i=0;i<meshPoints.length;i++){
               meshPoints[i].associateShadersBuffer(engine.shaderProgram.shaderProgramId);
               gl.drawElements(gl.TRIANGLES, meshPoints[i].indices.length, gl.UNSIGNED_SHORT, 0);
            }

            engine.meshQuery.associateShadersBuffer(engine.shaderProgram.shaderProgramId);
            gl.drawElements(gl.TRIANGLES, engine.meshQuery.indices.length, gl.UNSIGNED_SHORT, 0);
          
            for(let i=0;i<queryPoints.length;i++){
               queryPoints[i].associateShadersBuffer(engine.shaderProgram.shaderProgramId);
               gl.drawElements(gl.TRIANGLES, queryPoints[i].indices.length, gl.UNSIGNED_SHORT, 0);
            }

            window.requestAnimationFrame(engine.animate);
        }
        this.animate(0);	 
 
	} 
	
}
