extends Node

class_name State

#state machine behaviour 
#states
var current:State = null
var next:State = null
var states
export (NodePath) var entity_path

func _ready():
	states = self.get_children() 
	for state in states: 
		state.setup(self, entity)

func play(delta): 
	if current:
		current.evaluate(delta) 
		current.execute(delta)

func switch():
	if current: 
		current.exit() 
	if next: 
		current = next
		current.enter()

func stop(): 
	if current: 
		current.exit() 
	current = null  

#state behaviour
var entity
var machine

func setup(_machine:State, _entity = null): 
	machine = _machine
	entity = _entity

func enter(): 
	pass

func evaluate(delta): 
	pass

func execute(delta): 
	pass

func exit(): 
	pass
