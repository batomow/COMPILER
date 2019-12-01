extends Node
###-- gameplay stuff -- ###
var console:RichTextLabel
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
			console.text += ">>\t%s : %s\n" % [String(i), String(quads[i])]
	
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
		elif quad.opcode == 4: # MULT
			_op_mult(quad)
		elif quad.opcode == 6: # GOTO
			_op_goto(quad)
		elif quad.opcode == 7: # GOTOF
			_op_gotof(quad)
		elif quad.opcode == 9: # GOSUB
			_op_gosub(quad)
		elif quad.opcode == 10: # ASSIGN
			_op_assign(quad)
		elif quad.opcode == 11: # PRINT
			_op_print(quad)
		elif quad.opcode == 14: # GREATER THAN
			_op_gt(quad)
		elif quad.opcode == 19: # EQUALS
			_op_eeq(quad)
		elif quad.opcode == 21: # END PROCEDURE
			_op_endproc(quad)
		elif quad.opcode == 22: # END PROGRAM 
			flag = false
			if DEBUGGING:
				console.text += ">>\tGlobals: %s\n>>\tConstants: %s\n" % [String(globals), String(constants)]
		elif quad.opcode == 25: # ERA
			_op_era(quad)
		elif quad.opcode == 26: # PARAM
			_op_param(quad)
		elif quad.opcode == 27: # RETURN
			_op_return(quad)
		
		if stackPointer.empty():
			flag = false
		else:
			stackPointer[-1] += 1

func _get_mem_val(addr, local = -1):
	
	if(addr == 66 ): #return buffer
		return return_buffer
	if (addr < 2000): #is a constant
		if DEBUGGING:
			console.text += ">>\t_get_mem_val|Constants: %s\n" % String(constants)
		var i = addr - 1000
		return constants[i]
	if(addr >= 2000 && addr < 3000): #is global
		if DEBUGGING:
			console.text += ">>\t_get_mem_val|Globals: %s\n" % String(globals)
		var i = addr - 2000
		return globals[i]
	if(addr >= 3000): # is local
		if DEBUGGING:
			console.text += ">>\t_get_mem_val|Locals: %s\n" % String(localsArray)
		var i = addr - 3000
		return localsArray[local][i]

func _set_mem_addr(addr, val, isParam = 0):
	if isParam:
		eraArray[-1][addr-3000] = val
		if DEBUGGING:
			console.text += ">>\t_set_mem_addr|Eras: %s\n" % String(eraArray)
	else:
		if(addr == 66 ): #return buffer
			return_buffer = val
		elif (addr < 2000): #is a constant
			if DEBUGGING:
				console.text += ">>\t_set_mem_addr|Constants: %s\n" % String(constants)
			if constants[addr-100] == 0:
				constants_counter += 1
			constants[addr-1000] = val
		elif(addr >= 2000 && addr < 3000): #is global
			if DEBUGGING:
				console.text += ">>\t_set_mem_addr|Globals: %s\n" % String(globals)
			if globals[addr-2000] == 0:
				globals_counter += 1
			globals[addr-2000] = val
		elif(addr >= 3000): # is local
			if DEBUGGING:
				console.text += ">>\t_set_mem_addr|Locals: %s\n" % String(localsArray)
			localsArray[-1][addr-3000] = val
		

func _op_sum(quad):
	if DEBUGGING:
		console.text += ">>\tSUM: %s\n" % String(quad)
	var left = _get_mem_val(quad.left)
	var right = _get_mem_val(quad.right)
	_set_mem_addr(quad.result, left + right)
	if DEBUGGING:
		console.text += ">>\t%s + %s = %s\n" % [String(left), String(right), String(_get_mem_val(quad.result))]

# warning-ignore:unused_argument
func _op_res(quad):
	if DEBUGGING:
		console.text += ">>\tRES: %s\n" % String(quad)
	var left = _get_mem_val(quad.left)
	var right = _get_mem_val(quad.right)
	_set_mem_addr(quad.result, left - right)
	if DEBUGGING:
		console.text += ">>\t%s - %s = %s\n" % [String(left), String(right), String(_get_mem_val(quad.result))]

# warning-ignore:unused_argument
func _op_root(quad):
	pass

# warning-ignore:unused_argument
func _op_div(quad):
	pass

# warning-ignore:unused_argument
func _op_mult(quad):
	if DEBUGGING:
		console.text += ">>\tMULT: %s\n" % String(quad)
	var left = _get_mem_val(quad.left)
	var right = _get_mem_val(quad.right)
	_set_mem_addr(quad.result, left * right)
	if DEBUGGING:
		console.text += ">>\t%s * %s = %s\n" % [String(left), String(right), String(_get_mem_val(quad.result))]

# warning-ignore:unused_argument
func _op_pow(quad):
	pass

# warning-ignore:unused_argument
func _op_goto(quad):
	if DEBUGGING:
		console.text += ">>\tGOTO: %s\n" % String(quad)
	var jump = quad.result
	stackPointer[-1] = jump - 1
	if DEBUGGING:
		console.text += ">>\tJumped to %s\n" % String(stackPointer.back())

# warning-ignore:unused_argument
func _op_gotof(quad):
	if DEBUGGING:
		console.text += ">>\tGOTOF: %s\n" % String(quad)
	var left = _get_mem_val(quad.left)
	if(!left):
		var jump = quad.result
		stackPointer[-1] = jump - 1
	if DEBUGGING:	
		console.text += ">>\tJumped to %s\n" % String(stackPointer.back())

# warning-ignore:unused_argument
func _op_gotov(quad):
	pass

# warning-ignore:unused_argument
func _op_gosub(quad):
	if DEBUGGING:
		console.text += "GOSUB: %s" % String(quad)
	localsArray.push_back(eraArray.back())
	eraArray.pop_back()
	stackPointer.push_back(quad.result - 1)
	if DEBUGGING:
		console.text += ">>\tJumped to %s to start procedure\n" % String(stackPointer.front())

func _op_assign(quad):
	if DEBUGGING:
		console.text += ">>\tASSIGN: %s\n" % String(quad)
	var left = _get_mem_val(quad.left)
	var res = quad.result
	
	_set_mem_addr(res, left)
	if DEBUGGING:
		console.text += ">>\t%s = %s (check: %s )\n" % [String(res), String(left), String(_get_meme_val(res))]

# warning-ignore:unused_argument
func _op_print(quad):
	if DEBUGGING:
		console.text += ">>\tPRINT: %s\n" % String(quad)
	console.text = ">>\t%s\n" % String(_get_mem_val(quad.result))

# warning-ignore:unused_argument
func _op_read(quad):
	pass

# warning-ignore:unused_argument
func _op_lt(quad):
	pass

# warning-ignore:unused_argument
func _op_gt(quad):
	if DEBUGGING:
		console.text += ">>\tGT: %s\n" % String(quad)
	var left = _get_mem_val(quad.left)
	var right = _get_mem_val(quad.right)
	_set_mem_addr(quad.result, left > right)
	
	if DEBUGGING:
		console.text += ">>\t%s > %s = %s\n"% [String(left), String(right), String(_get_mem_val(quad.result))]

# warning-ignore:unused_argument
func _op_lte(quad):
	pass

# warning-ignore:unused_argument
func _op_gte(quad):
	pass

# warning-ignore:unused_argument
func _op_and(quad):
	pass

# warning-ignore:unused_argument
func _op_or(quad):
	pass

# warning-ignore:unused_argument
func _op_eeq(quad):
	if DEBUGGING:
		console.text += ">>\tEQUALS: %s\n" % String(quad)
	var left = _get_mem_val(quad.left)
	var right = _get_mem_val(quad.right)
	_set_mem_addr(quad.result, left == right)
	
	if DEBUGGING:
		console.text +=  ">>\t%s == %s = %s\n" % [String(left), String(right), String(_get_mem_val(quad.result))]

# warning-ignore:unused_argument
func _op_neq(quad):
	pass

# warning-ignore:unused_argument
func _op_endproc(quad):
	if DEBUGGING:
		console.text += ">>\tENDPROC: %s\n" % String(quad)
	return_buffer = -1
	stackPointer.pop_back()
	localsArray.pop_back()
	if DEBUGGING:
		console.text += ">>\tControl now to: %s\n>>\tReturned: %s\n" % [String(stackPointer[-1]), String(return_buffer)]

# warning-ignore:unused_argument
func _op_endprog(quad):
	if DEBUGGING:
		console.text += ">>\tENDPROG: %s\n" % String(quad)
	flag = false

# warning-ignore:unused_argument
func _op_neg(quad):
	pass

# warning-ignore:unused_argument
func _op_forcheck(quad):
	pass

# warning-ignore:unused_argument
func _op_era(quad):
	if DEBUGGING:
		console.text += ">>\tERA: %s\n" % String(quad)
	var newLocal = []
	newLocal.resize(quad.result)
	eraArray.append(newLocal)
	if DEBUGGING:
		console.text += ">>\tAdded new memory chunk of size %s to ERA array\n" % localsArray.back().size()

# warning-ignore:unused_argument
func _op_param(quad):
	if DEBUGGING:
		console.text += ">>\tPARAM: %s\n" % String(quad)
	var left = _get_mem_val(quad.left)
	if DEBUGGING:
		console.text += ">>\t%s = %s\n" % [String(quad.left),  String(left)]
	_set_mem_addr(quad.result, left, 1)
	if DEBUGGING:
		console.text += ">>\tAssigned parameter in %s as %s\n" % [String(quad.result), String(_get_mem_val(quad.result))]

# warning-ignore:unused_argument
func _op_return(quad):
	if DEBUGGING:
		console.text += ">>\tRETURN: %s\n" % String(quad)
	return_buffer = _get_mem_val(quad.result)
	stackPointer.pop_back()
	localsArray.pop_back()
	if DEBUGGING:
		if stackPointer.empty() :
			console.text += ">>\tProgram finished\n"
		else:
			console.text += ">>\tControl now to: %s\n>>\tReturned: %s\n" % [String(stackPointer.back()), String(return_buffer)]
