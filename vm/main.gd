extends Node2D
var quads:Array = []
var temp_counter:int = 0
var temps = []
func _ready():
	_load() 
	for quad in quads:
		print(quad)

func _load():
	var file = File.new(); 
	file.open("res://main.fso", file.READ);
	var text:String = file.get_as_text()
	quads = parse_json(text).quads
	file.close() 
    