#include "view.h"
#include <iostream>

void Square::Draw()
{
    std::cout << __PRETTY_FUNCTION__ << std::endl;
}

void Polygon::Draw()
{
    std::cout << __PRETTY_FUNCTION__ << std::endl;
}

void Triangle::Draw()
{
    std::cout << __PRETTY_FUNCTION__ << std::endl;    
}

void Circle::Draw()
{
    std::cout << __FUNCTION__ << std::endl;     
}
