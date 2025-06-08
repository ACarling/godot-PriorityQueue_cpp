#ifndef MINQUEUE_H
#define MINQUEUE_H

#include <godot_cpp/classes/object.hpp>
#include <queue>


namespace godot {

    class ComparePQValMin
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

            return apqval > bpqval;
        }
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