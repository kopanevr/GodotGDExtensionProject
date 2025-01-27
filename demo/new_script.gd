extends Node

@export var scene : PackedScene

# Called when the node enters the scene tree for the first time.
func _ready() -> void:
	if scene == null:
		return;

	var instance = scene.instantiate()
	add_child(instance)


# Called every frame. 'delta' is the elapsed time since the previous frame.
func _process(_delta: float) -> void:
	pass
