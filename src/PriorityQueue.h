#ifndef GDEXAMPLE_H
#define GDEXAMPLE_H

#include <godot_cpp/classes/object.hpp>
#include <queue>


namespace godot {

class ComparePQValMax
{
public:
    bool operator() (Dictionary a, Dictionary b)
    {
		bool at = a.has("pqval");
		bool bt = b.has("pqval");
		if(at && !bt) {return true;}
		if(!at && !bt) {return true;}
		if(!at && bt) {return false;}

        return (float)a["pqval"] < (float)b["pqval"];
    }
};

class ComparePQValMin
{
public:
    bool operator() (Dictionary a, Dictionary b)
    {
		bool at = a.has("pqval");
		bool bt = b.has("pqval");
		if(at && !bt) {return true;}
		if(!at && !bt) {return true;}
		if(!at && bt) {return false;}

        return (float)a["pqval"] > (float)b["pqval"];
    }
};


class MaxQueue: public Object {
	GDCLASS(MaxQueue, Object)

	private:
		std::priority_queue<Variant, std::vector<Variant>, ComparePQValMax> pq;

	protected:
		static void _bind_methods();

	public:
		MaxQueue();
		~MaxQueue();
		void push(Variant item);
		Variant pop();
		int size();
		bool is_empty();
};


class MinQueue: public Object {
	GDCLASS(MinQueue, Object)

	private:
		std::priority_queue<Variant, std::vector<Variant>, ComparePQValMin> pq;

	protected:
		static void _bind_methods();

	public:
		MinQueue();
		~MinQueue();
		void push(Variant item);
		Variant pop();
		int size();
		bool is_empty();
};
}

#endif