extends Node3D


func _ready() -> void:
	var pq: MaxQueue = MaxQueue.new()
	
	for i in 100:
		pq.push({"val": i, "pqval": randf()})

	while !pq.is_empty():
		print(pq.pop())
