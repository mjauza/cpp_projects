#ifndef LOCATION_H
#define LOCATION_H
#include <string>

class Location
{
    public:
        Location(float x, float y);
        Location();
        virtual ~Location();
        float get_distance(const Location &loc);
        void operator=(const Location& loc);
        std::string to_string();

    protected:
        float x;
        float y;

    private:
};

#endif // LOCATION_H
