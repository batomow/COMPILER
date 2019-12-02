extends Node
###-- gameplay stuff ---###
var console:RichTextLabel
var input:LineEdit
enum TableTypes {TableInt, TableFloat, TableChar, TableString, TableElement, TableVector, TableNull, TableDouble, TableBool, TableMat}
var scanQuad
var object_list:Dictionary = {}
###---------------------###
var quads:Array = []
var globals_counter:int = 0
var globals := []
var localsArray := []
var eraArray := []
var constants_counter:int = 0
var constants := []
var flag = true
var stackPointer= []
const DEBUGGING = 0

var return_buffer:int

func _ready():
	# Initialize console object
	console = get_node("UI/background/console")
	
	# Initialize console input
	input = get_node("UI/background2/input")
	input.connect("text_entered", self, "_op_scan")
	input.get_parent().visible = false
	# Initialize pointer stack, used to know where we are reading
	stackPointer.push_back(0)
	
	# Initialize localsArray, the structure used to hold the memory arrays with local memory
	var mainLocal = []
	mainLocal.resize(100)
	localsArray.push_back(mainLocal)
	
	# Initialize Global memory
	globals.resize(100)

	_load() 

func _load():
	# Load object file
	var file = File.new(); 
	file.open("res://main.fso", file.READ);
	
	# Parse object file's json code
	var text:String = file.get_as_text()
	var input = parse_json(text)
	
	# Get quadruple list from json
	quads = input.quads
	
	if(DEBUGGING):
		for i in range(quads.size()):
			print(i, ": ", quads[i])
	
	# Set constants in memory
	var constantAux = input.globals
	constantAux.pop_back()
	constants.resize(constantAux.size())
	for registro in constantAux:
		var i = int(registro.memdir - 1000)
		constants[i] = registro.valor
	
	# Close object file
	file.close()


# warning-ignore:unused_argument
func _physics_process(delta):
	if (flag && !stackPointer.empty()):
		# Get current quad 
		var quad = quads[stackPointer.back()]
		if quad.opcode == 0: # SUM
			_op_sum(quad)
		elif quad.opcode == 1: # SUBSTRACT
			_op_res(quad)
		elif quad.opcode == 2: # ROOT (!)
			_op_root(quad)
		elif quad.opcode == 3: # DIVISION
			_op_div(quad)
		elif quad.opcode == 4: # MULT
			_op_mult(quad)
		elif quad.opcode == 5: # POWER
			_op_pow(quad)
		elif quad.opcode == 6: # GOTO
			_op_goto(quad)
		elif quad.opcode == 7: # GOTOF
			_op_gotof(quad)
		elif quad.opcode == 8: # GOTOV
			_op_gotov(quad)
		elif quad.opcode == 9: # GOSUB
			_op_gosub(quad)
		elif quad.opcode == 10: # ASSIGN
			_op_assign(quad)
		elif quad.opcode == 11: # PRINT
			_op_print(quad)
		elif quad.opcode == 12: # SCAN
			stackPointer[-1] -= 1 
			scanQuad = quad
			input.get_parent().visible = true
		elif quad.opcode == 13: # LESS THAN
			_op_lt(quad)
		elif quad.opcode == 14: # GREATER THAN
			_op_gt(quad)
		elif quad.opcode == 15: # LESS THAN OR EQUAL 
			_op_lte(quad)
		elif quad.opcode == 16: # GREATER THAN OR EQUAL 
			_op_gte(quad)
		elif quad.opcode == 17: # AND 
			_op_and(quad)
		elif quad.opcode == 18: # OR
			_op_or(quad)
		elif quad.opcode == 19: # EQUALS
			_op_eeq(quad)
		elif quad.opcode == 20: # NOT EQUALS
			_op_neq(quad)
		elif quad.opcode == 21: # END PROCEDURE
			_op_endproc(quad)
		elif quad.opcode == 22: # END PROGRAM 
			flag = false
			if DEBUGGING:
				print("Globals: ", globals, "\nConstants: ", constants)
		elif quad.opcode == 23: # NEGATION (!)
			_op_neg(quad)
		elif quad.opcode == 24: # FORCHECK
			_op_forcheck(quad)
		elif quad.opcode == 25: # ERA
			_op_era(quad)
		elif quad.opcode == 26: # PARAM
			_op_param(quad)
		elif quad.opcode == 27: # RETURN
			_op_return(quad)
		elif quad.opcode == 29: #REGISTER
			_op_register(quad)
		elif quad.opcode == 30: # CHECKLIM
			_op_checklim(quad)
		
		if stackPointer.empty():
			flag = false
		else:
			stackPointer[-1] += 1

func _op_register(quad):
	var llave = quad.result - 3000
	if object_list.has(llave):
		console.text += ">>\tLlave ya existe\n"
	else:
		var isKinematic = localsArray[-1][llave]
		var type:int = localsArray[-1][llave+1]
		var color:int = localsArray[-1][llave+2]
		var position := Vector2()
		position.x = localsArray[-1][llave+3]
		position.y = localsArray[-1][llave+4]
		var scale := Vector2()
		scale.x = localsArray[-1][llave+5]
		scale.y = localsArray[-1][llave+6]
		
		var new_object:Sprite = Sprite.new()
		match(type):
			0 : new_object.texture = load("res://basic.png")
			1 : new_object.texture = load("res://basic2.png")
			_ : print("THIS SHIT FAILED")
		
		new_object.position = position
		new_object.scale = scale
		
		if color == 0 : 
			new_object.modulate = Color.white
		elif color == 1 :
			 new_object.modulate = Color.red
		elif color == 2 : 
			new_object.modulate = Color.green
		elif color == 3 : 
			new_object.modulate = Color.blue
		elif color == 4 :
			 new_object.modulate = Color.yellow
		elif color == 5 : 
			new_object.modulate = Color.cyan
		elif color == 6 : 
			new_object.modulate = Color.magenta
		elif color == 7 : 
			new_object.modulate = Color.black
		
		get_node("Game").add_child(new_object)
	



func _get_mem_val(addr, local = -1):
	if addr < 0:
		addr = _get_mem_val(addr * (-1))
	
	if(addr == 66 ): #return buffer
		return return_buffer
	if (addr < 2000): #is a constant
		if DEBUGGING:
			print("_get_mem_val|Constants: ", constants)
		var i = addr - 1000
		return constants[i]
	if(addr >= 2000 && addr < 3000): #is global
		if DEBUGGING:
			print("_get_mem_val|Globals: ", globals)
		var i = addr - 2000
		return globals[i]
	if(addr >= 3000): # is local
		if DEBUGGING:
			print("_get_mem_val|Locals: ", localsArray)
		var i = addr - 3000
		return localsArray[local][i]

func _set_mem_addr(addr, val, isParam = 0):
	if addr < 0:
		addr = _get_mem_val(addr*(-1))

	if isParam:
		eraArray[-1][addr-3000] = val
		if DEBUGGING:
			print("_set_mem_addr|Eras: ", eraArray)
	else:
		if(addr == 66 ): #return buffer
			return_buffer = val
		elif (addr < 2000): #is a constant
			if DEBUGGING:
				print("_set_mem_addr|Constants: ", constants)
			if constants[addr-1000] == 0:
				constants_counter += 1
			constants[addr-1000] = val
		elif(addr >= 2000 && addr < 3000): #is global
			if DEBUGGING:
				print("_set_mem_addr|Globals: ", globals)
			if globals[addr-2000] == 0:
				globals_counter += 1
			globals[addr-2000] = val
		elif(addr >= 3000): # is local
			if DEBUGGING:
				print("_set_mem_addr|Locals: ", localsArray)
			localsArray[-1][addr-3000] = val
		

func _op_sum(quad):
	if DEBUGGING:
		print("SUM: ", quad)
	var left = _get_mem_val(quad.left)
	var right = _get_mem_val(quad.right)
	if(left == null || right == null):
		console.text += "!!\tERROR: Operation on null not valid\n"
		flag = false
		return
	_set_mem_addr(quad.result, left + right)
	if DEBUGGING:
		print(left, " + ", right, " = ", _get_mem_val(quad.result))

# warning-ignore:unused_argument
func _op_res(quad):
	if DEBUGGING:
		print("RES: ", quad)
	var left = _get_mem_val(quad.left)
	var right = _get_mem_val(quad.right)
	if(left == null || right == null):
		console.text += "!!\tERROR: Operation on null not valid\n"
		flag = false
		return
	_set_mem_addr(quad.result, left - right)
	if DEBUGGING:
		print(left, " - ", right, " = ", _get_mem_val(quad.result))

# warning-ignore:unused_argument
func _op_root(quad):
	pass

# warning-ignore:unused_argument
func _op_div(quad):
	if DEBUGGING:
		print("DIVISION: ", quad)
	var left = _get_mem_val(quad.left)
	var right = _get_mem_val(quad.right)
	if(left == null || right == null):
		console.text += "!!\tERROR: Operation on null not valid\n"
		flag = false
		return
	if(right == 0):
		console.text += "!!\tERROR: Math error\n"
		flag = false
		return

	_set_mem_addr(quad.result, floor(left / right))
	if DEBUGGING:
		print(left, " / ", right, " = ", _get_mem_val(quad.result))

# warning-ignore:unused_argument
func _op_mult(quad):
	if DEBUGGING:
		print("MULT: ", quad)
	var left = _get_mem_val(quad.left)
	var right = _get_mem_val(quad.right)
	if(left == null || right == null):
		console.text += "!!\tERROR: Operation on null not valid\n"
		flag = false
		return
	_set_mem_addr(quad.result, left * right)
	if DEBUGGING:
		print(left, " * ", right, " = ", _get_mem_val(quad.result))

# warning-ignore:unused_argument
func _op_pow(quad):
	if DEBUGGING:
		print("POWER: ", quad)
	var left = _get_mem_val(quad.left)
	var right = _get_mem_val(quad.right)
	if(left == null || right == null):
		console.text += "!!\tERROR: Operation on null not valid\n"
		flag = false
		return
	_set_mem_addr(quad.result, pow(left, right))
	if DEBUGGING:
		print(left, " ^ ", right, " = ", _get_mem_val(quad.result))
	pass

# warning-ignore:unused_argument
func _op_goto(quad):
	if DEBUGGING:
		print("GOTO: ", quad)
	var jump = quad.result
	stackPointer[-1] = jump - 1
	if DEBUGGING:
		print("Jumped to ", stackPointer[-1])

# warning-ignore:unused_argument
func _op_gotof(quad):
	if DEBUGGING:
		print("GOTOF: ", quad)
	var left = _get_mem_val(quad.left)
	if(!left):
		var jump = quad.result
		stackPointer[-1] = jump - 1
	if DEBUGGING:	
		print("Jumped to ", stackPointer[-1])

# warning-ignore:unused_argument
func _op_gotov(quad):
	if DEBUGGING:
		print("GOTOV: ", quad)
	var left = _get_mem_val(quad.left)
	if(left):
		var jump = quad.result
		stackPointer[-1] = jump - 1
	if DEBUGGING:	
		print("Jumped to ", stackPointer[-1])

# warning-ignore:unused_argument
func _op_gosub(quad):
	if DEBUGGING:
		print("GOSUB: ", quad)
	localsArray.append(eraArray.back())
	eraArray.pop_back()
	stackPointer.append(quad.result - 1)
	if DEBUGGING:
		print("Jumped to ", stackPointer[-1], " to start procedure")

func _op_assign(quad):
	if DEBUGGING:
		print("ASSIGN: ", quad)
	var res = quad.result
	
	if(quad.left == -1):
		var right = _get_mem_val(_get_mem_val(quad.right))
		_set_mem_addr(res, right)
		if DEBUGGING:
			print(res, " = ", right, " (check: ", _get_mem_val(res), ")")
	else:
		var left = _get_mem_val(quad.left)
		_set_mem_addr(res, left)
		if DEBUGGING:
			print(res, " = ", left, " (check: ", _get_mem_val(res), ")")

# warning-ignore:unused_argument
func _op_print(quad):
	if DEBUGGING:
		print("PRINT: ", quad)
	console.text += ">>\t%s\n" % String(_get_mem_val(quad.result))

# warning-ignore:unused_argument
func _op_scan(var scanned_text):
	var parsed_data
	var type:int = scanQuad.left
	match(type):
		0:parsed_data = int(scanned_text)  
		2: parsed_data = scanned_text[0]
		3: parsed_data = scanned_text
		7: parsed_data = float(scanned_text)
		8: parsed_data = true if scanned_text == "truth" else false
		_ : print("Failed Parse")
	if DEBUGGING:
		print("Scanned: ", parsed_data)
	console.text += "<<\t%s\n" % parsed_data
	input.text = ""
	input.get_parent().visible = false
	_set_mem_addr(scanQuad.result, parsed_data)
	stackPointer[-1] += 1

# warning-ignore:unused_argument
func _op_lt(quad):
	if DEBUGGING:
		print("LT: ", quad)
	var left = _get_mem_val(quad.left)
	var right = _get_mem_val(quad.right)
	if(left == null || right == null):
		console.text += "!!\tERROR: Operation on null not valid\n"
		flag = false
		return
	_set_mem_addr(quad.result, left < right)
	
	if DEBUGGING:
		print(left, " < ", right, " = ", _get_mem_val(quad.result))

# warning-ignore:unused_argument
func _op_gt(quad):
	if DEBUGGING:
		print("GT: ", quad)
	var left = _get_mem_val(quad.left)
	var right = _get_mem_val(quad.right)
	if(left == null || right == null):
		console.text += "!!\tERROR: Operation on null not valid\n"
		flag = false
		return
	_set_mem_addr(quad.result, left > right)
	
	if DEBUGGING:
		print(left, " > ", right, " = ", _get_mem_val(quad.result))

# warning-ignore:unused_argument
func _op_lte(quad):
	if DEBUGGING:
		print("LTE: ", quad)
	var left = _get_mem_val(quad.left)
	var right = _get_mem_val(quad.right)
	if(left == null || right == null):
		console.text += "!!\tERROR: Operation on null not valid\n"
		flag = false
		return
	_set_mem_addr(quad.result, left <= right)
	
	if DEBUGGING:
		print(left, " <= ", right, " = ", _get_mem_val(quad.result))

# warning-ignore:unused_argument
func _op_gte(quad):
	if DEBUGGING:
		print("GTE: ", quad)
	var left = _get_mem_val(quad.left)
	var right = _get_mem_val(quad.right)
	if(left == null || right == null):
		console.text += "!!\tERROR: Operation on null not valid\n"
		flag = false
		return
	_set_mem_addr(quad.result, left >= right)
	
	if DEBUGGING:
		print(left, " >= ", right, " = ", _get_mem_val(quad.result))

# warning-ignore:unused_argument
func _op_and(quad):
	if DEBUGGING:
		print("AND: ", quad)
	var left = _get_mem_val(quad.left)
	var right = _get_mem_val(quad.right)
	if(left == null || right == null):
		console.text += "!!\tERROR: Operation on null not valid\n"
		flag = false
		return
	_set_mem_addr(quad.result, left && right)
	
	if DEBUGGING:
		print(left, " && ", right, " = ", _get_mem_val(quad.result))

# warning-ignore:unused_argument
func _op_or(quad):
	if DEBUGGING:
		print("OR: ", quad)
	var left = _get_mem_val(quad.left)
	var right = _get_mem_val(quad.right)
	if(left == null || right == null):
		console.text += "!!\tERROR: Operation on null not valid\n"
		flag = false
		return
	_set_mem_addr(quad.result, left || right)
	
	if DEBUGGING:
		print(left, " || ", right, " = ", _get_mem_val(quad.result))

# warning-ignore:unused_argument
func _op_eeq(quad):
	if DEBUGGING:
		print("EQUALS: ", quad)
	var left = _get_mem_val(quad.left)
	var right = _get_mem_val(quad.right)
	if(left == null || right == null):
		console.text += "!!\tERROR: Operation on null not valid\n"
		flag = false
		return
	_set_mem_addr(quad.result, left == right)
	
	if DEBUGGING:
		print(left, " == ", right, " = ", _get_mem_val(quad.result))

# warning-ignore:unused_argument
func _op_neq(quad):
	if DEBUGGING:
		print("NOT EQUALS: ", quad)
	var left = _get_mem_val(quad.left)
	var right = _get_mem_val(quad.right)
	if(left == null || right == null):
		console.text += "!!\tERROR: Operation on null not valid\n"
		flag = false
		return
	_set_mem_addr(quad.result, left != right)
	
	if DEBUGGING:
		print(left, " != ", right, " = ", _get_mem_val(quad.result))

# warning-ignore:unused_argument
func _op_endproc(quad):
	if DEBUGGING:
		print("ENDPROC: ", quad)
	return_buffer = -1
	stackPointer.pop_back()
	localsArray.pop_back()
	if DEBUGGING:
		print("Control now to: ", stackPointer[-1], ", Returned: ", return_buffer)

# warning-ignore:unused_argument
func _op_endprog(quad):
	if DEBUGGING:
		print("ENDPROG: ", quad)
	flag = false

# warning-ignore:unused_argument
func _op_neg(quad):
	pass

# warning-ignore:unused_argument
func _op_forcheck(quad):
	var left = _get_mem_val(quad.left)
	var right = _get_mem_val(quad.right)
	
	if(left > right):
		flag = false

# warning-ignore:unused_argument
func _op_era(quad):
	if DEBUGGING:
		print("ERA: ", quad)
	var newLocal = []
	newLocal.resize(quad.result)
	eraArray.append(newLocal)
	if DEBUGGING:
		print("Added new memory chunk of size ", localsArray[-1].size(), "to ERA array")

# warning-ignore:unused_argument
func _op_param(quad):
	if DEBUGGING:
		print("PARAM: ", quad)
	var left = _get_mem_val(quad.left)
	if DEBUGGING:
		print(">>", quad.left, " = ", left) 
	_set_mem_addr(quad.result, left, 1)
	if DEBUGGING:
		print (quad.left,  " = ", left)

# warning-ignore:unused_argument
func _op_return(quad):
	if DEBUGGING:
		print("RETURN: ", quad)
	return_buffer = _get_mem_val(quad.result)
	stackPointer.pop_back()
	localsArray.pop_back()
	if DEBUGGING:
		if stackPointer.empty() :
			print("Program finished");
		else:
			print("Control now to: ", stackPointer[-1], ", Returned: ", return_buffer)
			
func _op_checklim(quad):
	var tocheck = _get_mem_val(quad.left)
	var sup = quad.result
	
	if(tocheck >= sup || tocheck < 0):
		print("Index out of bounds")
		flag = false
		
	if(DEBUGGING):
		print("Checking limits: 0 - ", tocheck, " - ", sup)
