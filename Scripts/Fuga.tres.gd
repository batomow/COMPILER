extends Node2D

class_name Fuga

var anim:Array
var key:Label

var letter:String setget _set_letter
var state:int setget _set_anim

var ascii_letter:int
var pos_index:int

func _ready():
	anim = get_node("Animations").get_children()
	key = get_node("Letter/Panel/Label")

func _set_letter(value):
	letter = value
	key.text = value

func _set_anim(value):
	state = value
	if value == GM.EFUGA.SPAWN:
		anim[0].visible = true
		anim[1].visible = false
		GM.change_to_big_leak()
	elif value == GM.EFUGA.HELD:
		anim[0].visible = false
		anim[1].visible = true
		GM.change_to_small_leak()
	elif value == GM.EFUGA.PATCH:
		#play some animation
		GM.delete_leak(self)

