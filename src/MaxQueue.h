#ifndef MAXQUEUE_H
#define MAXQUEUE_H

#include <godot_cpp/classes/object.hpp>
#include <queue>


namespace godot {

    class ComparePQValMax
    {
    public:
        bool operator() (Variant a, Variant b)
        {
            bool at;
            bool bt;

            float apqval = (float)a.get_named("pqval", at);
            float bpqval = (float)b.get_named("pqval", bt);

            if(at && !bt) {return true;}
            if(!at && !bt) {return true;}
            if(!at && bt) {return false;}

            return apqval < bpqval;
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

}

#endif