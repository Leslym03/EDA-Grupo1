class Mesh{
	constructor(point, vertices, colors, indices){
      this.point = point;
		this.vertices = vertices;
      this.indices = indices;
      this.colors = colors;
   }
   move(direccion){
      for(let i = 0; i < this.vertices.length; i+=3){
         this.vertices[i] += direccion.x * CONSTANTE_MOVIMIENTO;
         this.vertices[i + 1] += direccion.y * CONSTANTE_MOVIMIENTO;
         this.vertices[i + 2] += direccion.z * CONSTANTE_MOVIMIENTO;
      }
      gl.bindBuffer(gl.ARRAY_BUFFER, this.vertexBuffer);
      gl.bufferData(gl.ARRAY_BUFFER, new Float32Array(this.vertices), gl.STATIC_DRAW);
      gl.bindBuffer(gl.ARRAY_BUFFER,null);
   }
   pintar(color){
      for(let i = 0; i < this.colors.length; i+=4){
         this.colors[i] = color.red;
         this.colors[i + 1] = color.green;
         this.colors[i + 2] = color.blue;
         this.colors[i + 3] = color.alfa;
      }
      gl.bindBuffer(gl.ARRAY_BUFFER, this.colorBuffer);
      gl.bufferData(gl.ARRAY_BUFFER, new Float32Array(this.colors), gl.STATIC_DRAW);
      gl.bindBuffer(gl.ARRAY_BUFFER,null);
   }
	initBuffers(){
      this.vertexBuffer = gl.createBuffer();
      gl.bindBuffer(gl.ARRAY_BUFFER, this.vertexBuffer);
      gl.bufferData(gl.ARRAY_BUFFER, new Float32Array(this.vertices), gl.STATIC_DRAW);
      gl.bindBuffer(gl.ARRAY_BUFFER,null);

      this.colorBuffer = gl.createBuffer ();
      gl.bindBuffer(gl.ARRAY_BUFFER, this.colorBuffer);
      gl.bufferData(gl.ARRAY_BUFFER, new Float32Array(this.colors), gl.STATIC_DRAW);
      gl.bindBuffer(gl.ARRAY_BUFFER,null);


      this.indexBuffer = gl.createBuffer ();
      gl.bindBuffer(gl.ELEMENT_ARRAY_BUFFER, this.indexBuffer);
      gl.bufferData(gl.ELEMENT_ARRAY_BUFFER, new Uint16Array(this.indices), gl.STATIC_DRAW);
      gl.bindBuffer(gl.ARRAY_BUFFER,null);

   }
   
   associateShadersBuffer(shaderProgram){
      // Position
      gl.bindBuffer(gl.ARRAY_BUFFER, this.vertexBuffer);
      var position = gl.getAttribLocation(shaderProgram, "position");
      gl.vertexAttribPointer(position, 3, gl.FLOAT, false,0,0) ;
      gl.enableVertexAttribArray(position);
      // Color
      gl.bindBuffer(gl.ARRAY_BUFFER, this.colorBuffer);
      var color = gl.getAttribLocation(shaderProgram, "color");
      gl.vertexAttribPointer(color, 4, gl.FLOAT, false,0,0) ;
      gl.enableVertexAttribArray(color);
   }
}
