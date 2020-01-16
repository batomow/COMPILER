extends Node2D

class_name Valvula

var dragging:bool = false
onready var rosca = $Rosca/Sprite2D
const EMPTYING_AMOUNT = 0.24
var emptying_velocity:float = 0

func _on_Rosca_input_event(viewport, event, shape_idx):
	if event is InputEventMouseButton:
		dragging = true

func _input(event):
	if dragging:
		if event is InputEventMouseMotion:
			var motion = event.relative
			var new_pos = get_global_mouse_position()
			var previous_pos = new_pos - motion
			var center = rosca.global_position
			var angle = (previous_pos - center).angle_to(new_pos - center)
			if rosca.rotation_degrees <= 360 * GM.DIFFICULTY:
				rosca.rotate(angle)

func _process(delta):
	if Input.is_action_just_released("left_mouse_button"):
		dragging = false
	if not dragging and rosca.rotation_degrees > 0:
		rosca.rotate(-1 * GM.DIFFICULTY * delta)
	emptying_velocity = rosca.rotation_degrees / (360 * GM.DIFFICULTY)

func _on_Timer_timeout():
	GM.update_flooding( -emptying_velocity * EMPTYING_AMOUNT)
