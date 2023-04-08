#include "controller.h"
#include <iostream>

void Controller::CreateNewDocument()
{
    std::cout << __PRETTY_FUNCTION__ << std::endl;
    _document = std::make_unique<Document>();
}

void Controller::ImportDocumentFromFile()
{
    std::cout << __PRETTY_FUNCTION__ << std::endl;
    _document = std::make_unique<Document>();
}

void Controller::ExportDocumentToFile()
{
    std::cout << __PRETTY_FUNCTION__ << std::endl;
    if (_document)
    {
        std::cout << "Document exported" << std::endl;
    }
    else
    {
        std::cout << "No document for export" << std::endl;
    }
}

std::shared_ptr<Square> Controller::CreateSquare()
{
    std::cout << __PRETTY_FUNCTION__ << std::endl;
    if(_document) 
    {
        return _document->AddSquare();
    }
    else
    {
        std::cout << "No opened document" << std::endl;
        return nullptr;        
    }
}

std::shared_ptr<Polygon> Controller::CreatePolygon()
{
    std::cout << __PRETTY_FUNCTION__ << std::endl;
    if(_document) 
    {
        return _document->AddPolygon();
    }
    else
    {
        std::cout << "No opened document" << std::endl;
        return nullptr;
    }
}

std::shared_ptr<Triangle> Controller::CreateTriangle()
{
    std::cout << __PRETTY_FUNCTION__ << std::endl;
    if(_document) 
    {
        return _document->AddTriangle();
    }
    else
    {
        std::cout << "No opened document" << std::endl;
        return nullptr;
    }
}

std::shared_ptr<Circle> Controller::CreateCircle()
{
    std::cout << __PRETTY_FUNCTION__ << std::endl;
    if(_document) 
    {
        return _document->AddCircle();
    }
    else
    {
        std::cout << "No opened document" << std::endl;
        return nullptr;
    }
}

void Controller::DeleteGraphicalPrimitive(std::shared_ptr<IGraphicalPrimitive> primitive)
{
    std::cout << __PRETTY_FUNCTION__ << std::endl;
    if(_document)
    {
        return _document->DeletePrimitive(primitive);
    }
    else
    {
        std::cout << "No opened document" << std::endl;        
    }
}

