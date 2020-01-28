extends Node2D

class_name Game_Root

onready var early_timer = $EarlyGame
onready var mid_timer = $MidGame
onready var late_timer = $LateGame
onready var leak_timer = $Leak

onready var base_fuga = preload("res://Main Scenes/Game/Fuga.tscn")

onready var points = ($Pipe/Line).points
onready var points_size:int = points.size()
onready var fuga_container = $FugaContainer

var alphabet:Dictionary = {
	65:"A", 66:"B", 67:"C", 68:"D", 69:"E", 70:"F",
	71:"G", 72:"H", 73:"I", 74:"J", 75:"K", 76:"L",
	77:"M", 78:"N", 79:"O", 80:"P", 81:"Q", 82:"R",
	83:"S", 84:"T", 85:"U", 86:"V", 87:"W", 88:"X",
	89:"Y", 90:"Z"
}

onready var letter_stack:Array = range(65,91)
onready var position_stack:Array = range(0, points_size)

var fugas_counter:int = 0
var keys_to_press:Dictionary = {}

var input_queue:Array = []

func _unhandled_key_input(event:InputEventKey): #filter key presses
	if (event.scancode in keys_to_press.keys()):
		if (!event.echo):
			input_queue.push_back(event)
#			print(alphabet[event.scancode])

# warning-ignore:unused_argument
func _process(delta):
	if GM.current_state == GM.game_states.PAUSED:
		return
	if !input_queue.empty(): #process key press or release
		var event:InputEventKey = input_queue.front()
		if (event.pressed):
			keys_to_press[event.scancode].state = ((keys_to_press[event.scancode].state + 1) % 2)
		input_queue.pop_front()

func _ready():
	GM.game_root = self
	randomize()
	letter_stack.shuffle()
	position_stack.shuffle()
	early_timer.start()
	leak_timer.wait_time = ( 5 - GM.DIFFICULTY/3) #DIFICULTY (0, 1, 2) EASY, NORMAL, HARD

func _on_EarlyGame_timeout():
	mid_timer.start()
	_on_Leak_timeout()
	leak_timer.start()

func _on_MidGame_timeout():
	late_timer.start()

func _on_LateGame_timeout():
	pass # Replace with function body.

func _on_Leak_timeout():
	if GM.current_state == GM.game_states.PAUSED:
		return
	if letter_stack.empty() or position_stack.empty():
		return
	var new_fuga = base_fuga.instance()
	fuga_container.add_child(new_fuga)
	new_fuga.position = points[position_stack.front()]
	new_fuga.pos_index = position_stack.front()
	position_stack.pop_front()
	new_fuga.letter = alphabet[letter_stack.front()]
	new_fuga.ascii_letter = letter_stack.front()
	keys_to_press[letter_stack.front()] = new_fuga
	letter_stack.pop_front()
	new_fuga.state = GM.EFUGA.SPAWN
	new_fuga.name = new_fuga.letter
	fugas_counter += 1

func delete_fuga(fuga):
	letter_stack.push_back(fuga.ascii_letter)
	position_stack.push_back(fuga.pos_index)
	fuga.queue_free()