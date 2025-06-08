extends Node3D

func test(pq):
	var arr: Array = []
	for i in 5:
		pq.push({"val": i, "pqval": roundf(randf() * 100.)})

	while !pq.is_empty():
		print(pq.pop())
	print(pq.pop())

func _ready() -> void:
	var max: MaxQueue = MaxQueue.new()
	var min: MinQueue = MinQueue.new()
	
	print("max first")
	test(max)

	
	print("min first")
	test(min)
