#include "MinQueue.h"
#include <godot_cpp/core/class_db.hpp>

using namespace godot;


void MinQueue::_bind_methods() {
    ClassDB::bind_method(D_METHOD("push", "item"), &MinQueue::push);
    ClassDB::bind_method(D_METHOD("pop"), &MinQueue::pop);
    ClassDB::bind_method(D_METHOD("size"), &MinQueue::size);
    ClassDB::bind_method(D_METHOD("is_empty"), &MinQueue::is_empty);
}


MinQueue::MinQueue() {}
MinQueue::~MinQueue() {}

void MinQueue::push(Variant item) {
	pq.push(item);
}
Variant MinQueue::pop() {
    if (is_empty()) {
        return Variant();
    }
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