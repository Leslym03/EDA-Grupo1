function pad(n, width, z){
	z = z || '0';
	n = n + '';
	return n.length >= width ? n : new Array(width - n.length +1).join(z) + n;
}

function numberToBinaryString(n){
	let numberInString = Number((n >>> 0).toString(2));
	numberInString = pad(numberInString, 3);
	return numberInString;
}

class Color{
	constructor(r, g, b, a){
		this.red = r;
		this.green = g;
		this.blue = b;
		this.alfa = a;
	}
}
class Point{
	constructor(x, y, z){
		this.x = x;
		this.y = y;
		this.z = z;
	}
}
class Cube{
	constructor(inPoint, scale, color){
		this.point = inPoint;
		this.scale = scale;
		this.color = color;
		this.coords = [[],[],[]];
		this.vertices = [];	
		this.colors = [];
		this.indices = [];
	}

	init(){
		let x = this.point.x;
		let y = this.point.y;
		let z = this.point.z;	
		
		for(let i = 7; i >= 0; i--){
			let pointInBinary = numberToBinaryString(i);
			let tempPoint = [x,y,z];
			let indexToChange = 2;
			for(let j = 2 ; j >= 0; j--){
				if(pointInBinary[j] == '1'){
					tempPoint[indexToChange] -= this.scale;
				}else if(pointInBinary[j] == '0')
					tempPoint[indexToChange] += this.scale;	
				indexToChange--;
			}

			let newPoint = new Point(tempPoint[0], tempPoint[1], tempPoint[2]);
			this.coords[0].push(newPoint.x);
			this.coords[1].push(newPoint.y);
			this.coords[2].push(newPoint.z);

			this.vertices.push(newPoint.x);
			this.vertices.push(newPoint.y);
			this.vertices.push(newPoint.z);
		}
		
		this.indices = [
			0,4,6, 0,6,2,
			1,5,7, 1,7,3,
			0,2,3, 0,3,1,
			4,6,7, 4,7,5,
			0,1,5, 0,5,4,
			2,3,7, 2,7,6
		];	

		for(let i = 0; i < 8; i++){
			this.colors.push(this.color.red);
			this.colors.push(this.color.green);
			this.colors.push(this.color.blue);
			this.colors.push(this.color.alfa);
		}

	}

	getMinCoords() {
		let minCoordX = Math.min.apply(null,this.coords[0]);
		let minCoordY = Math.min.apply(null,this.coords[1]);
		let minCoordZ = Math.min.apply(null,this.coords[2]);
		return new Point(minCoordX, minCoordY, minCoordZ);
	}

	getMaxCoords() {
		let maxCoordX = Math.max.apply(null,this.coords[0]);
		let maxCoordY = Math.max.apply(null,this.coords[1]);
		let maxCoordZ = Math.max.apply(null,this.coords[2]);
		return new Point(maxCoordX, maxCoordY, maxCoordZ);
	}

	contains( point ) {
		let minCoords = this.getMinCoords();
		let maxCoords = this.getMaxCoords();

		if(minCoords.x <= point.x && point.x <= maxCoords.x &&
		   minCoords.y <= point.y && point.y <= maxCoords.y &&
		   minCoords.z <= point.z && point.z <= maxCoords.z )
			return true;
		else
			return false;
	}

	intersects( range ) {
		let minCoordsOwn = this.getMinCoords();
		let maxCoordsOwn = this.getMaxCoords();
		let minCoordsRange = range.getMinCoords();
		let maxCoordsRange = range.getMaxCoords();

		if(minCoordsOwn.x <= maxCoordsRange.x && maxCoordsOwn.x >= minCoordsRange.x &&
		   minCoordsOwn.y <= maxCoordsRange.y && maxCoordsOwn.y >= minCoordsRange.y &&
		   minCoordsOwn.z <= maxCoordsRange.z && maxCoordsOwn.z >= minCoordsRange.z )
			return true;
		else
			return false;
	}

	move( direccion ){
		for(let i = 0; i < this.coords[0].length; i++){
			this.coords[0][i] += direccion.x * CONSTANTE_MOVIMIENTO;
			this.coords[1][i] += direccion.y * CONSTANTE_MOVIMIENTO;
			this.coords[2][i] += direccion.z * CONSTANTE_MOVIMIENTO;
		}
		//TODO add mesh
	}
}

class OcTree {
	constructor( boundary, capacity ) {
		this.boundary = boundary;
		this.boundary.init();
		this.capacity = capacity;
		this.points = [];
		this.divided = false;
		this.childs= [];
		this.meshModels =[];//puntos en forma de cubos

		this.mesh = new Mesh(boundary.point,boundary.vertices, boundary.colors, boundary.indices);
		this.mesh.initBuffers();

		meshes.push(this.mesh);
	}

	subdivide() {
		let x = this.boundary.point.x;
		let y = this.boundary.point.y;
		let z = this.boundary.point.z;
		let dimension = this.boundary.scale;

		var colorRed = new Color(1, 0, 0, 0.5);
		var colorGreen = new Color(0, 1, 0, 0.5);
		var colorBlue = new Color(0, 0, 1, 0.5);
		var colorYellow = new Color(1, 1, 0, 0.5);

		let otTopLeftFront = new Cube( new Point( x - dimension / 2, y + dimension / 2, z + dimension / 2 ), this.boundary.scale / 2, colorRed);
		otTopLeftFront.init();
		this.childs.push(otTopLeftFront);
		
		let otTopRightFront = new Cube( new Point( x + dimension / 2, y + dimension / 2, z + dimension / 2 ), this.boundary.scale / 2, colorBlue);
		otTopRightFront.init();
		this.childs.push(otTopRightFront);
		
		let otBottomRightFront = new Cube( new Point( x + dimension / 2, y - dimension / 2, z + dimension / 2 ), this.boundary.scale / 2, colorYellow);
		otBottomRightFront.init();
		this.childs.push(otBottomRightFront);

		let otBottomLeftFront = new Cube( new Point( x - dimension / 2, y - dimension / 2, z + dimension / 2 ), this.boundary.scale / 2, colorGreen);
		otBottomLeftFront.init();	 
		this.childs.push(otBottomLeftFront);

		let otTopLeftBack  = new Cube( new Point( x - dimension / 2, y + dimension / 2, z - dimension / 2 ), this.boundary.scale / 2, colorGreen);
		otTopLeftBack.init();		
		this.childs.push(otTopLeftBack);

		let otTopRightBack = new Cube( new Point( x + dimension / 2, y + dimension / 2, z - dimension / 2 ), this.boundary.scale / 2, colorYellow);
		otTopRightBack.init();
		this.childs.push(otTopRightBack);

		let otBottomRightBack = new Cube( new Point( x + dimension / 2, y - dimension / 2, z - dimension / 2 ), this.boundary.scale / 2, colorBlue);
		otBottomRightBack.init();
		this.childs.push(otBottomRightBack);

		let otBottomLeftBack = new Cube( new Point( x - dimension / 2, y - dimension / 2, z - dimension / 2 ), this.boundary.scale / 2, colorRed);
		otBottomLeftBack.init();
		this.childs.push(otBottomLeftBack);

		this.topLeftFront = new OcTree( otTopLeftFront, this.capacity );
		this.topRightFront = new OcTree( otTopRightFront, this.capacity );
		this.bottomRightFront = new OcTree( otBottomRightFront, this.capacity );
		this.bottomLeftFront = new OcTree( otBottomLeftFront, this.capacity );
		this.topLeftBack = new OcTree( otTopLeftBack, this.capacity );
		this.topRightBack = new OcTree( otTopRightBack, this.capacity ); 
		this.bottomRightBack = new OcTree( otBottomRightBack, this.capacity );
		this.bottomLeftBack = new OcTree( otBottomLeftBack, this.capacity );
		this.divided = true;
	}

	insert(point) {
		if(!this.boundary.contains(point)) {
			return false;
		}
		
		if(this.points.length < this.capacity) {
			var color = new Color(this.boundary.color.red, this.boundary.color.green, this.boundary.color.blue, 1 );
			var randomPoint = new Cube(point, 0.02, color);
			randomPoint.init();
			
			var meshPoint = new Mesh(point, randomPoint.vertices, randomPoint.colors, randomPoint.indices );
			meshPoint.initBuffers();
			meshPoints.push(meshPoint);
			this.points.push(point);
			this.meshModels.push(meshPoint);

			return true;
		} else {
			if(!this.divided)
				this.subdivide();
			
			if(this.topLeftFront.insert(point))
				return true;
			else if(this.topRightFront.insert(point))
				return true;
			else if(this.bottomRightFront.insert(point))
				return true;
			else if(this.bottomLeftFront.insert(point))
				return true;
			else if(this.topLeftBack.insert(point))
				return true;
			else if(this.topRightBack.insert(point))
				return true;
			else if(this.bottomRightBack.insert(point))
				return true;
			else if(this.bottomLeftBack.insert(point))
				return true;
		}
	}
	
	query(range, found) {
		
		if(!this.boundary.intersects(range)) {
			return;
		} else {
			for( let mesh of this.meshModels) {
				if( range.contains(mesh.point)) {
					var color = new Color(range.color.red, range.color.green, range.color.blue, 1);
					mesh.pintar(color);
					found.push(mesh.point);
				}else{
					var parentColor = new Color(this.boundary.color.red, this.boundary.color.green, this.boundary.color.blue, 1);
					mesh.pintar(parentColor);
				}		
			}
			if(this.divided) {
				this.topLeftFront.query(range, found);
				this.topRightFront.query(range, found);
				this.bottomRightFront.query(range, found);
				this.bottomLeftFront.query(range, found);
				this.topLeftBack.query(range, found);
				this.topRightBack.query(range, found);
				this.bottomRightBack.query(range, found);
				this.bottomLeftBack.query(range, found);
			}
		}
	}
}