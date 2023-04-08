#include "model.h"

std::shared_ptr<Square> Document::AddSquare()
{
    std::cout << __PRETTY_FUNCTION__ << std::endl;
    auto primitive = std::make_shared<Square>();
    _primitives.push_back(primitive);
    primitive->Draw();
    return primitive;
}

std::shared_ptr<Polygon> Document::AddPolygon()
{
    std::cout << __PRETTY_FUNCTION__ << std::endl;
    auto primitive = std::make_shared<Polygon>();
    _primitives.push_back(primitive);
    primitive->Draw();
    return primitive;
}

std::shared_ptr<Triangle> Document::AddTriangle()
{
    std::cout << __PRETTY_FUNCTION__ << std::endl;
    auto primitive = std::make_shared<Triangle>();
    _primitives.push_back(primitive);
    primitive->Draw();
    return primitive;
}

std::shared_ptr<Circle> Document::AddCircle()
{
    std::cout << __PRETTY_FUNCTION__ << std::endl;
    auto primitive = std::make_shared<Circle>();
    _primitives.push_back(primitive);
    primitive->Draw();
    return primitive;
}

void Document::DeletePrimitive(std::shared_ptr<IGraphicalPrimitive> primitive)
{
    std::cout << __PRETTY_FUNCTION__ << std::endl;
    for(auto iter = _primitives.begin(); iter != _primitives.end(); ++iter)
    {
        if(*iter == primitive) 
        {
            std::cout << "Primitive deleted!" << std::endl;
            _primitives.erase(iter);
            return;
        }
    }
    std::cout << "Primitive not found!" << std::endl;
}
