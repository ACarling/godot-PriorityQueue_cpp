#include "PriorityQueue.h"
#include <godot_cpp/core/class_db.hpp>

using namespace godot;

void MaxQueue::_bind_methods() {
    ClassDB::bind_method(D_METHOD("push", "item"), &MaxQueue::push);
    ClassDB::bind_method(D_METHOD("pop"), &MaxQueue::pop);
    ClassDB::bind_method(D_METHOD("size"), &MaxQueue::size);
    ClassDB::bind_method(D_METHOD("is_empty"), &MaxQueue::is_empty);
}
void MinQueue::_bind_methods() {
    ClassDB::bind_method(D_METHOD("push", "item"), &MinQueue::push);
    ClassDB::bind_method(D_METHOD("pop"), &MinQueue::pop);
    ClassDB::bind_method(D_METHOD("size"), &MinQueue::size);
    ClassDB::bind_method(D_METHOD("is_empty"), &MinQueue::is_empty);
}

MaxQueue::MaxQueue() {}
MaxQueue::~MaxQueue() {}

MinQueue::MinQueue() {}
MinQueue::~MinQueue() {}

void MaxQueue::push(Variant item) {
	pq.push(item);
}
Variant MaxQueue::pop() {
	Variant top = pq.top(); 
	pq.pop();
	return top;
}
int MaxQueue::size() {
	return pq.size();
}
bool MaxQueue::is_empty() {
	return pq.size() == 0;
}


void MinQueue::push(Variant item) {
	pq.push(item);
}
Variant MinQueue::pop() {
	Variant top = pq.top(); 
	pq.pop();
	return top;
}
int MinQueue::size() {
	return pq.size();
}
bool MinQueue::is_empty() {
	return pq.size() == 0;
}

// void PriorityQueue::_process(double delta) {
// 	time_passed += delta;

// 	Vector2 new_position = Vector2(10.0 + (10.0 * sin(time_passed * 2.0)), 10.0 + (10.0 * cos(time_passed * 1.5)));

// 	set_position(new_position);
// }