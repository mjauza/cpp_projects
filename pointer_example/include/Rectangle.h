#ifndef RECTANGLE_H
#define RECTANGLE_H
#include <string>

class Rectangle
{
    public:

        Rectangle();
        Rectangle(float x, float y);
        float get_area();
        std::string to_string();
        virtual ~Rectangle();
        float x;
        float y;


    protected:

    private:
};

#endif // RECTANGLE_H
