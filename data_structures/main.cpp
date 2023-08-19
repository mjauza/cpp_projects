#include <iostream>
#include "VecExample.h"
#include <vector>
#include <string>
#include "ListExample.h"
#include "MapExample.h"


using namespace std;

void vector_example();
void list_example();


int main()
{
    MapExample me = MapExample();
    me.print_data();
    std::cout << (me.data.find("David") != me.data.end()) << std::endl;
    std::cout << (me.data.find("Dani") != me.data.end()) << std::endl;
    me.data.insert({"Dani", 34});
    std::cout << me.data.count("David") << std::endl;
    std::cout << me.data.count("Dani") << std::endl;
    return 0;
}

void list_example()
{
    ListExample le = ListExample(5);
    le.print_data();
}

void vector_example()
{
    VecExample ve = VecExample(5);
    ve.print_data();
    std::vector<int>data =  ve.get_data();
    std::cout << "Vector size: " << data.size() << std::endl;
    std::vector<float> add_data = {1.5,2.5,3.5,4.5,5.5};
    std::vector<float> new_data = ve.add_to_data(add_data);
    for(auto it = new_data.begin(); it != new_data.end(); it++){
        std::cout << std::to_string(*it) << std::endl;
    }
}
