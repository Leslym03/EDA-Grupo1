class VertexShaderSource{
	constructor(){
        this.source = 'attribute vec3 position;'+
            'uniform mat4 Pmatrix;'+
            'uniform mat4 Vmatrix;'+
            'uniform mat4 Mmatrix;'+
			'attribute vec4 color;'+//the color of the point
			'varying vec4 vColor;'+
            'void main(void) { '+//pre-built function
               'gl_Position = Pmatrix*Vmatrix*Mmatrix*vec4(position, 1.);'+
			   'vColor = color;'+
            '}';
	}
}

class FragmentShaderSource{
	constructor(){
		this.source = 
			'precision mediump float;'+
			'varying vec4 vColor;'+
			'void main(void) {'+
               'gl_FragColor = vec4(vColor);'+
            '}';
	}
}

class Shader{
	constructor(){
		this.loadShaderSource();
		this.loadShader();
		this.linkProgram();
		this.useProgram();	
	}
	loadShaderSource(){
		var vertCodeSource = new VertexShaderSource();
		this.vertCode = vertCodeSource.source;
		var fragCodeSource = new FragmentShaderSource();
		this.fragCode = fragCodeSource.source;
	}
	loadShader(){
		 this.vertShader = gl.createShader(gl.VERTEX_SHADER);
         gl.shaderSource(this.vertShader, this.vertCode);
         gl.compileShader(this.vertShader);

         this.fragShader = gl.createShader(gl.FRAGMENT_SHADER);
         gl.shaderSource(this.fragShader, this.fragCode);
         gl.compileShader(this.fragShader);
	}
	linkProgram(){
         this.shaderProgramId = gl.createProgram();
         gl.attachShader(this.shaderProgramId, this.vertShader);
         gl.attachShader(this.shaderProgramId, this.fragShader);
		 gl.linkProgram(this.shaderProgramId);
		 gl.useProgram(this.shaderProgramId);	 

		//maybe we need to initiliaze use program here >C
	}
	useProgram(){
		 gl.useProgram(this.shaderProgramId);	 
	}
	quitProgram(){
		 gl.useProgram(0);
	}
		
}
