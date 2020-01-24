extends Control

class_name Reloj

onready var normal_timer:Timer = $Normal
onready var fast_timer:Timer = $Fast
onready var total_timer:Timer = $Total
onready var anim:AnimationPlayer = $AnimationPlayer
var total_time:float = 0
onready var time_text:Label = $Panel/Label

func _ready():
	GM.reloj = self
	if GM.DIFFICULTY == GM.difficulty.easy: 
		set_time(60)
	elif GM.DIFFICULTY == GM.difficulty.normal: 
		set_time(120)
	elif GM.DIFFICULTY == GM.difficulty.hard: 
		set_time(180)

func _process(delta):
	time_text.text = String(int(total_timer.time_left))

func set_time(value:float)->void:
	total_time = value
	total_timer.wait_time = total_time
	normal_timer.wait_time = total_time*0.75
	fast_timer.wait_time = total_time*0.25
	normal_timer.start()
	total_timer.start()
	anim.play("Reloj_Normal_Time")

func pause_timers()->void:
	normal_timer.paused = true
	fast_timer.paused = true
	total_timer.paused = true
	anim.stop(false)

func unpause_timers()->void:
	normal_timer.paused = false
	fast_timer.paused = false
	total_timer.paused = false
	anim.play()

func _on_Normal_timeout():
	fast_timer.start()
	anim.play("Reloj_Fast_Time")

func _on_Fast_timeout():
	GM.current_state = GM.game_states.TIMEOUT
