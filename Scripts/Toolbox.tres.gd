extends Control

class_name ToolBox

onready var Tape = $HBoxContainer/Tape
onready var Cubeta = $HBoxContainer/Cubeta
onready var Martillo = $HBoxContainer/Martillo
onready var HBox = $HBoxContainer
onready var Holder = $MouseHolder

onready var tape_anim:AnimationPlayer = $HBoxContainer/Tape/TapeAnim
onready var cubeta_anim:AnimationPlayer = $HBoxContainer/Cubeta/CubetaAnim
onready var martillo_anim:AnimationPlayer = $HBoxContainer/Martillo/MartilloAnim

var tape_uses:int = 2
var small_buffer:bool = true
var small_buffer2:bool = true

export (Resource) var tape_original_sprite
export (Resource) var tape_runout_sprite
export (Resource) var cubeta_original_sprite 
export (Resource) var martillo_oritinal_sprite

var _tape_flag := false
var _cubeta_flag := false
var _martillo_flag := false
var _has_object := false

func _ready(): 
	GM.toolbox = self

# warning-ignore:unused_argument
func _process(delta):
	if small_buffer2: 
		if _tape_flag:
			Tape.rect_position = (get_global_mouse_position() - Vector2(100, 57) * 0.4) * 2.5 
		elif _cubeta_flag:
			Cubeta.rect_position = (get_global_mouse_position() - Vector2(100, 57) * 0.4) * 2.5
		elif _martillo_flag:
			Martillo.rect_position = (get_global_mouse_position() - Vector2(100, 57) * 0.4) * 2.5
	else: 
		if _tape_flag:
			Tape.rect_position = (get_global_mouse_position() - Vector2(122, 97) * 0.4) * 2.5 
		elif _cubeta_flag:
			Cubeta.rect_position = (get_global_mouse_position() - Vector2(122, 97) * 0.4) * 2.5
		elif _martillo_flag:
			Martillo.rect_position = (get_global_mouse_position() - Vector2(122, 97) * 0.4) * 2.5
	
	if _has_object and Input.is_action_just_pressed("right_mouse_button"):
		if _tape_flag:
			Holder.remove_child(Tape)
			HBox.add_child(Tape)
			_tape_flag = false
			_has_object = false
			if tape_uses > 0:
				Tape.texture = tape_original_sprite
			else: 
				Tape.texture = tape_runout_sprite
		elif _cubeta_flag:
			Holder.remove_child(Cubeta)
			HBox.add_child(Cubeta)
			_cubeta_flag = false
			_has_object = false
			Cubeta.texture = cubeta_original_sprite
		elif _martillo_flag:
			Holder.remove_child(Martillo)
			HBox.add_child(Martillo)
			_martillo_flag = false
			_has_object = false
			Martillo.texture = martillo_oritinal_sprite
		small_buffer = true
		small_buffer2 = true

	if _has_object and Input.is_action_just_pressed("left_mouse_button"):
		if _tape_flag and tape_uses > 0 and !small_buffer:
			if tape_uses == 1: 
				tape_anim.play("tape_runout")
			elif tape_uses > 1: 
				tape_anim.play("tape_normal")
			tape_uses -= 1
		elif _cubeta_flag and !small_buffer:
			cubeta_anim.play("cubeta_normal")
		elif _martillo_flag and !small_buffer:
			martillo_anim.play('martillo_normal')
		if !small_buffer: 
			small_buffer2 = false
		small_buffer = false 

func _on_Tape_gui_input(event):
	if event is InputEventMouseButton and !_has_object:
		HBox.remove_child(Tape)
		Holder.add_child(Tape)
		_tape_flag = true
		_has_object = true

func _on_Cubeta_gui_input(event):
	if event is InputEventMouseButton and !_has_object:
		HBox.remove_child(Cubeta)
		Holder.add_child(Cubeta)
		_cubeta_flag = true
		_has_object = true

func _on_Martillo_gui_input(event):
	if event is InputEventMouseButton and !_has_object:
		HBox.remove_child(Martillo)
		Holder.add_child(Martillo)
		_martillo_flag = true
		_has_object = true

