extends Node2D
var quads:Array = []
# warning-ignore:unused_class_variable
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
	# Initialize pointer stack, used to know where we are reading
	stackPointer.append(0)
	
	# Initialize localsArray, the structure used to hold the memory arrays with local memory
	var mainLocal = []
	mainLocal.resize(100)
	localsArray.append(mainLocal)
	
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
		for i in range(quads.size() - 1):
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
		elif quad.opcode == 15: # LARGER THAN OR EQUAL
			_op_lte(quad)
		elif quad.opcode == 19: # EQUALS
			_op_eeq(quad)
		elif quad.opcode == 21: # END PROCEDURE
			_op_endproc(quad)
		elif quad.opcode == 22: # END PROGRAM 
			flag = false
			if DEBUGGING:
				print("Globals: ", globals, "\nConstants: ", constants)
		elif quad.opcode == 24: # FORCHECK
			_op_forcheck(quad)
		elif quad.opcode == 25: # ERA
			_op_era(quad)
		elif quad.opcode == 26: # PARAM
			_op_param(quad)
		elif quad.opcode == 27: # RETURN
			_op_return(quad)
		elif quad.opcode == 28: # CHECKLIM
			_op_checklim(quad)
		
		if stackPointer.empty():
			flag = false
		else:
			stackPointer[-1] += 1

func _get_mem_val(addr, local = -1):
	
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
			if constants[addr-100] == 0:
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
	_set_mem_addr(quad.result, left + right)
	if DEBUGGING:
		print(left, " + ", right, " = ", _get_mem_val(quad.result))

# warning-ignore:unused_argument
func _op_res(quad):
	if DEBUGGING:
		print("RES: ", quad)
	var left = _get_mem_val(quad.left)
	var right = _get_mem_val(quad.right)
	_set_mem_addr(quad.result, left - right)
	if DEBUGGING:
		print(left, " - ", right, " = ", _get_mem_val(quad.result))

# warning-ignore:unused_argument
func _op_root(quad):
	pass

# warning-ignore:unused_argument
func _op_div(quad):
	pass

# warning-ignore:unused_argument
func _op_mult(quad):
	if DEBUGGING:
		print("MULT: ", quad)
	var left = _get_mem_val(quad.left)
	var right = _get_mem_val(quad.right)
	_set_mem_addr(quad.result, left * right)
	if DEBUGGING:
		print(left, " * ", right, " = ", _get_mem_val(quad.result))

# warning-ignore:unused_argument
func _op_pow(quad):
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
	pass

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
	print(">> ", _get_mem_val(quad.result));

# warning-ignore:unused_argument
func _op_read(quad):
	pass

# warning-ignore:unused_argument
func _op_lt(quad):
	pass

# warning-ignore:unused_argument
func _op_gt(quad):
	if DEBUGGING:
		print("GT: ", quad)
	var left = _get_mem_val(quad.left)
	var right = _get_mem_val(quad.right)
	_set_mem_addr(quad.result, left > right)
	
	if DEBUGGING:
		print(left, " > ", right, " = ", _get_mem_val(quad.result))

# warning-ignore:unused_argument
func _op_lte(quad):
	if DEBUGGING:
		print("LTE: ", quad)
	var left = _get_mem_val(quad.left)
	var right = _get_mem_val(quad.right)
	_set_mem_addr(quad.result, left <= right)
	
	if DEBUGGING:
		print(left, " <= ", right, " = ", _get_mem_val(quad.result))

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
		print("EQUALS: ", quad)
	var left = _get_mem_val(quad.left)
	var right = _get_mem_val(quad.right)
	_set_mem_addr(quad.result, left == right)
	
	if DEBUGGING:
		print(left, " == ", right, " = ", _get_mem_val(quad.result))

# warning-ignore:unused_argument
func _op_neq(quad):
	pass

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
		print (quad.left,  " = ", left)
	_set_mem_addr(quad.result, left, 1)
	if DEBUGGING:
		print("Assigned parameter in ", quad.result, " as ", _get_mem_val(quad.result))

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
