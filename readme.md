# C++ Priority Queue for godot 4.4
GDExtension bindings for std::priority_queue using godot dictionaries as input.

Can either wrap data in a dictionary containing a pqval key or use an object which has the pqval property 

```
	var max: MaxQueue = MaxQueue.new()
	pq.push({"pqval": 3})
	pq.push({"pqval": 8})
	pq.push({"pqval": 5})

	while !max.is_empty():
		print(max.pop().pqval)
	
	# -> 8, 5, 3

	var min: MinQueue = MinQueue.new()
	min.push({"pqval": 3})
	min.push({"pqval": 8})
	min.push({"pqval": 5})

	while !min.is_empty():
		print(min.pop().pqval)
	
	# -> 3, 5, 8
```