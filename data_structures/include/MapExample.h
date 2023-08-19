#ifndef MAPEXAMPLE_H
#define MAPEXAMPLE_H
#include <map>
#include <string>
class MapExample
{
    public:
        MapExample();
        void print_data();
        virtual ~MapExample();
        std::map<std::string, int> data = {{"David", 10}, {"Mia", 11}, {"Masa", 20}, {"Peter", 3}};

    protected:


    private:
};

#endif // MAPEXAMPLE_H
