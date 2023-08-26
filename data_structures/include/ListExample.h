#ifndef LISTEXAMPLE_H
#define LISTEXAMPLE_H
#include <list>

class ListExample
{
    public:
        ListExample();
        ListExample(int n);
        static bool sort_desc(const float &first, const float& second);
        void print_data();
        virtual ~ListExample();

    protected:
        std::list<float> even;
        std::list<float> odd;

    private:
};

#endif // LISTEXAMPLE_H
