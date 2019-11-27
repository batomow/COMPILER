extends Node2D
var quads:Array = []
var temp_counter:int = 0
var globals := [1000]
var locals := [1000]
var constants := [1000]
var flag = true
var quadPointer = 0
func _ready():
	_load() 

func _load():
	var file = File.new(); 
	file.open("res://main.fso", file.READ);
	var text:String = file.get_as_text()
	quads = parse_json(text).quads
	file.close()
	
func _process(delta):
	if(flag):
		_main_loop()
 
func _main_loop():
	var  thisQuad = quads[quadPointer]
	match(thisQuad.opcode):
		0:
			_op_sum(thisQuad)
		1:
			_op_res(thisQuad)
		2:
			_op_root(thisQuad)
		3:
			_op_div(thisQuad)
		4:
			_op_mult(thisQuad)
		5:
			_op_pow(thisQuad)
		6:
			_op_goto(thisQuad)
		7:
			_op_gotof(thisQuad)
		8:
			_op_gotov(thisQuad)
		9:
			_op_gosub(thisQuad)
		10:
			_op_assign(thisQuad)
		11:
			_op_print(thisQuad)
		12:
			_op_read(thisQuad)
		13:
			_op_lt(thisQuad)
		14:
			_op_gt(thisQuad)
		15:
			_op_lte(thisQuad)
		16:
			_op_gte(thisQuad)
		17:
			_op_and(thisQuad)
		18:
			_op_or(thisQuad)
		19:
			_op_eeq(thisQuad)
		20:
			_op_neq(thisQuad)
		21:
			_op_endproc(thisQuad)
		22:
			flag = false
		23:
			_op_neg(thisQuad)
		24:
			_op_forcheck(thisQuad)
		25:
			_op_era(thisQuad)
		26:
			_op_param(thisQuad)
		27:
			_op_return(thisQuad)
		_: 
			pass
	print(constants)
	print(globals)
	print(locals)
	quadPointer+= 1

func _get_mem_val(addr):
	if (addr < 2000): #is a constant
		var i = addr - 1000
		return constants[i]
	if(addr >= 2000 && addr < 3000): #is global
		var i = addr - 2000
		return constants[i]
	if(addr >= 3000): # is local
		var i = addr - 3000
		return constants[i]

func _set_mem_addr(addr, val):
	if (addr < 2000): #is a constant
		constants[addr-1000] = val
	elif(addr >= 2000 && addr < 3000): #is global
		globals[addr-2000] = val
	elif(addr >= 3000): # is local
		locals[addr-3000] = val

func _op_sum(quad):
	var left = _get_mem_val(quad.left)
	var right = _get_mem_val(quad.left)
	var res = quad.result
	
	print(left)
	print(right)
	print(res)
	
	_set_mem_addr(res, left + right)

func _op_res(quad):
	pass

func _op_root(quad):
	pass

func _op_div(quad):
	pass

func _op_mult(quad):
	pass

func _op_pow(quad):
	pass

func _op_goto(quad):
	pass

func _op_gotof(quad):
	pass

func _op_gotov(quad):
	pass

func _op_gosub(quad):
	pass

func _op_assign(quad):
	var left = _get_mem_val(quad.left)
	var res = quad.result
	
	_set_mem_addr(res, left)

func _op_print(quad):
	pass

func _op_read(quad):
	pass

func _op_lt(quad):
	pass

func _op_gt(quad):
	pass

func _op_lte(quad):
	pass

func _op_gte(quad):
	pass

func _op_and(quad):
	pass

func _op_or(quad):
	pass

func _op_eeq(quad):
	pass

func _op_neq(quad):
	pass

func _op_endproc(quad):
	pass

func _op_endprog(quad):
	pass

func _op_neg(quad):
	pass

func _op_forcheck(quad):
	pass

func _op_era(quad):
	pass

func _op_param(quad):
	pass

func _op_return(quad):
	pass
