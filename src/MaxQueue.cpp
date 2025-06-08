#include "MaxQueue.h"
#include <godot_cpp/core/class_db.hpp>

using namespace godot;

void MaxQueue::_bind_methods() {
    ClassDB::bind_method(D_METHOD("push", "item"), &MaxQueue::push);
    ClassDB::bind_method(D_METHOD("pop"), &MaxQueue::pop);
    ClassDB::bind_method(D_METHOD("size"), &MaxQueue::size);
    ClassDB::bind_method(D_METHOD("is_empty"), &MaxQueue::is_empty);
}

MaxQueue::MaxQueue() {}
MaxQueue::~MaxQueue() {}

void MaxQueue::push(Variant item) {
	pq.push(item);
}
Variant MaxQueue::pop() {
    if (is_empty()) {
        return Variant();
    }
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
