extends Node2D
var quads:Array = []
# warning-ignore:unused_class_variable
var globals_counter:int = 0
var globals := []
var locals_counter:int = 0
var locals := []
var constants_counter:int = 0
var constants := []
var flag = true
var stackPointer= []
var currentPointer:int

var return_buffer:int

func _ready():
	stackPointer.append(0)
	currentPointer = 0
	for n in range(100):
		globals.append(0)
		locals.append(0)
		constants.append(0)
	_load() 

func _load():
	var file = File.new(); 
	file.open("res://main.fso", file.READ);
	var text:String = file.get_as_text()
	var input = parse_json(text)
	quads = input.quads
	var constantAux = input.globals
	for registro in constantAux:
		var i = int(registro.memdir - 1000)
		if i >= 0:
			constants[i] = registro.valor
	file.close()


# warning-ignore:unused_argument
func _physics_process(delta):
	if flag: 
		var quad = quads[stackPointer[currentPointer]]
		if quad.opcode == 0:
			_op_sum(quad)
		elif quad.opcode == 10:
			_op_assign(quad)
		elif quad.opcode == 22:
			flag = false
			print(locals, "\n", globals, "\n", constants)
		stackPointer[currentPointer] += 1

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
		if constants[addr-100] == 0:
			constants_counter += 1
		constants[addr-1000] = val
	elif(addr >= 2000 && addr < 3000): #is global
		if globals[addr-2000] == 0:
			constants_counter += 1
		globals[addr-2000] = val
	elif(addr >= 3000): # is local
		if locals[addr-3000] == 0:
			locals_counter += 1
		locals[addr-3000] = val

func _op_sum(quad):
	var left = _get_mem_val(quad.left)
	var right = _get_mem_val(quad.right)
	_set_mem_addr(quad.result, left + right)
#
# warning-ignore:unused_argument
func _op_res(quad):
	var left = _get_mem_val(quad.left)
	var right = _get_mem_val(quad.right)
	_set_mem_addr(quad.result, left - right)

# warning-ignore:unused_argument
func _op_root(quad):
	pass

# warning-ignore:unused_argument
func _op_div(quad):
	pass

# warning-ignore:unused_argument
func _op_mult(quad):
	pass

# warning-ignore:unused_argument
func _op_pow(quad):
	pass

# warning-ignore:unused_argument
func _op_goto(quad):
	pass

# warning-ignore:unused_argument
func _op_gotof(quad):
	pass

# warning-ignore:unused_argument
func _op_gotov(quad):
	pass

# warning-ignore:unused_argument
func _op_gosub(quad):
	pass

func _op_assign(quad):
	var left = _get_mem_val(quad.left)
	var res = quad.result
	
	_set_mem_addr(res, left)

# warning-ignore:unused_argument
func _op_print(quad):
	pass

# warning-ignore:unused_argument
func _op_read(quad):
	pass

# warning-ignore:unused_argument
func _op_lt(quad):
	pass

# warning-ignore:unused_argument
func _op_gt(quad):
	pass

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
	pass

# warning-ignore:unused_argument
func _op_neq(quad):
	pass

# warning-ignore:unused_argument
func _op_endproc(quad):
	#free mem
	pass

# warning-ignore:unused_argument
func _op_endprog(quad):
	flag = false

# warning-ignore:unused_argument
func _op_neg(quad):
	pass

# warning-ignore:unused_argument
func _op_forcheck(quad):
	pass

# warning-ignore:unused_argument
func _op_era(quad):
	pass

# warning-ignore:unused_argument
func _op_param(quad):
	pass

# warning-ignore:unused_argument
func _op_return(quad):
	return_buffer = _get_mem_val(quad.result)
	