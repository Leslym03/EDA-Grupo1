/*============= Creating a canvas ======================*/
var engine = new Engine("my_Canvas");
var gl = engine.canvas.getContext('experimental-webgl');
/*========== Defining and storing the geometry ==========*/
var meshes = [];
var meshPoints = [];
var queryPoints = [];
var CONSTANTE_MOVIMIENTO = 0.2;
engine.initShaders();
engine.initModels();
engine.initUniforms();
engine.initMatrix();
engine.updateEvents();
engine.render();
