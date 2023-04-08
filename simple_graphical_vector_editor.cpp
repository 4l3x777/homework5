#include <iostream>
#include "controller.h"


int main(int argc, char* argv[]) 
{

    Controller controller;

    auto circle = controller.CreateCircle();
    controller.DeleteGraphicalPrimitive(circle);

    std::cout << std::endl;

    controller.CreateNewDocument();
    auto polygon = controller.CreatePolygon();
    controller.DeleteGraphicalPrimitive(polygon);

    std::cout << std::endl;

    controller.DeleteGraphicalPrimitive(polygon);
    return 0;
}
