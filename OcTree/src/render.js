var cubeRotation = 0.0;

class Canvas{
	constructor(htmlId){
		let canvas = document.querySelector(htmlId);
		this.gl = canvas.getContext('webgl') || canvas.getContext('experimental-webgl');
	}
	init(){
		if(!this.gl){
			alert('No se pudo inicializar WebGL');
			return;
		}	
		var shader = new Shader();
		this.shaderProgram = shader.initShaderProgram(this.gl);
		this.programInfo = {
			program: this.shaderProgram,
			attribLocations: {
				vertexPosition: this.gl.getAttribLocation(this.shaderProgram, 'aVertexPosition'),
				vertexColor: this.gl.getAttribLocation(this.shaderProgram, 'aVertexColor'),
			},
			uniformLocations: {
				projectionMatrix: this.gl.getUniformLocation(this.shaderProgram, 'uProjectionMatrix'),
				modelViewMatrix: this.gl.getUniformLocation(this.shaderProgram, 'uModelViewMatrix'),
			}
		};
		this.buffers = this.initBuffers();
		var then = 0;

		this.render = function(now){
			now *= 0.001;
			const deltaTime = now - then;
			then = now;
			this.drawScene(deltaTime);
			requestAnimationFrame(this.render);
		}	
		requestAnimationFrame(this.render);
	}

	initBuffers(){
		var positionBuffer = this.gl.createBuffer();
		this.gl.bindBuffer(this.gl.ARRAY_BUFFER, positionBuffer);
		//TODO add cubes positions
		var positions = [
			// Front face
			-1.0, -1.0,  1.0,
			 1.0, -1.0,  1.0,
			 1.0,  1.0,  1.0,
			-1.0,  1.0,  1.0,

			// Back face
			-1.0, -1.0, -1.0,
			-1.0,  1.0, -1.0,
			 1.0,  1.0, -1.0,
			 1.0, -1.0, -1.0,

			// Top face
			-1.0,  1.0, -1.0,
			-1.0,  1.0,  1.0,
			 1.0,  1.0,  1.0,
			 1.0,  1.0, -1.0,

			// Bottom face
			-1.0, -1.0, -1.0,
			 1.0, -1.0, -1.0,
			 1.0, -1.0,  1.0,
			-1.0, -1.0,  1.0,

			// Right face
			 1.0, -1.0, -1.0,
			 1.0,  1.0, -1.0,
			 1.0,  1.0,  1.0,
			 1.0, -1.0,  1.0,

			// Left face
			-1.0, -1.0, -1.0,
			-1.0, -1.0,  1.0,
			-1.0,  1.0,  1.0,
			-1.0,  1.0, -1.0,
		];
		this.gl.bufferData(this.gl.ARRAY_BUFFER, new Float32Array(positions), this.gl.STATIC_DRAW);
		//TODO add face colors
		var faceColors = [
			[1.0, 1.0, 1.0, 1.0],
			[1.0, 0.0, 0.0, 1.0],
			[0.0, 1.0, 0.0, 1.0],
			[0.0, 0.0, 1.0, 1.0],
			[1.0, 1.0, 0.0, 1.0],
			[1.0, 0.0, 1.0, 1.0],
		];
		var colors = [];
		
		for(let i=0; i< faceColors.length; ++i){
			let c = faceColors[i];
			colors = colors.concat(c, c, c, c);
		}
		
		var colorBuffer = this.gl.createBuffer();
		this.gl.bindBuffer(this.gl.ARRAY_BUFFER, colorBuffer);
		this.gl.bufferData(this.gl.ARRAY_BUFFER, new Float32Array(colors), this.gl.STATIC_DRAW);
		
		var indexBuffer = this.gl.createBuffer();
		this.gl.bindBuffer(this.gl.ELEMENT_ARRAY_BUFFER, indexBuffer);

		//TODO add indices
		var indices =[
			0, 1, 2, 0, 2, 3,
			4, 5, 6, 4, 6, 7,
			8, 9, 10, 8, 10, 11,
			12, 13, 14, 12, 14, 15,
			16, 17, 18, 16, 18, 19,
			20, 21, 22, 20, 22, 23,
		];

	this.gl.bufferData(this.gl.ELEMENT_ARRAY_BUFFER, new Uint16Array(indices), this.gl.STATIC_DRAW);
		
		return{
			position: positionBuffer,
			color: colorBuffer,
			indices: indexBuffer,
		};
	}

	drawScene(deltaTime){
		this.gl.clearColor(0.0, 0.0, 0.0, 1.0);
		this.gl.clearDepth(1.0);
		this.gl.enable(this.gl.DEPTH_TEST);
		this.gl.depthFunc(this.gl.LEQUAL);

		this.gl.clear(this.gl.COLOR_BUFFER_BIT | this.gl.DEPTH_BUFFER_BIT);
		
		const fieldOfView = 45 * Math.PI / 180;
		const aspect = this.gl.canvas.clientWidth / this.gl.canvas.clientHeight;
		const zNear = 0.1;
		const zFar = 100.0;
		const projectionMatrix = mat4.create();

		mat4.perspective(projectionMatrix, fieldOfView, aspect, zNear, zFar);
		const modelViewMatrix = mat4.create();

		mat4.translate(modelViewMatrix, modelViewMatrix, [-0.0, 0.0, -6.0]);
		mat4.rotate(modelViewMatrix, modelViewMatrix, cubeRotation, [0, 0, 1]);
		mat4.rotate(modelViewMatrix, modelViewMatrix, cubeRotation * .7, [0, 1, 0]);
		{
			const numComponents = 3;
			const type = this.gl.FLOAT;
			const normalize = false;
			const stride = 0;
			const offset = 0;
			this.gl.bindBuffer(this.gl.ARRAY_BUFFER, this.buffers.position);
			this.gl.vertexAttribPointer(
				this.programInfo.attribLocations.vertexPosition,
				numComponents,
				type,
				normalize,
				stride,
				offset
			);
			this.gl.enableVertexAttribArray(this.programInfo.attribLocations,vertexPosition);
		}
		{
			const numComponents = 4;
			const type = this.gl.FLOAT;
			const normalize = false;
			const stride = 0;
			const offset = 0;
			this.gl.bindBuffer(this.gl.ARRAY_BUFFER, this.buffers.color);
			this.gl.vertexAttribPointer(
				this.programInfo.attribLocations.vertexColor,
				numComponents,
				type,
				normalize,
				stride,
				offset
			);
			this.gl.enableVertexAttribArray(this.programInfo.attribLocations,vertexColor);
		}
		this.gl.bindBuffer(this.gl.ELEMENT_ARRAY_BUFFER, this.buffers.indices);
		this.useProgram(this.programInfo.program);

		this.gl.uniformMatrix4fv(
			this.programInfo.uniformLocations.projectionMatrix,
			false,
			projectionMatrix);
		
		this.gl.uniformMatrix4fv(
			this.programInfo.uniformLocations.modelViewMatrix,
			false,
			modelViewMatrix);
		{
			const vertexCount = 36;
			const type = this.gl.UNSIGNED_SHORT;
			const offset = 0;
			this.gl.drawElements(this.gl.TRIANGLES, vertexCount, type, offset);
		}
		
		cubeRotation += deltaTime;
	}
}
