/*!
    \file
    \brief Header file

    That file contain grapical primitives class
*/
#pragma once

#if !defined(__PRETTY_FUNCTION__) && !defined(__GNUC__)
#define __PRETTY_FUNCTION__ __FUNCSIG__
#endif

/*!
	\brief Interface Graphical Primitive class.
    \version 1.0
    \author 4l3x77

	That class contain interface methods

    \defgroup igraphicalprimitive
    @{
*/
class IGraphicalPrimitive
{
public:
    /*!
        \brief Interface method for draw.
    */   
    virtual void Draw() = 0;
};
/*! @} */

class Square: public IGraphicalPrimitive 
{
public:
    void Draw() override;
};

class Polygon: public IGraphicalPrimitive
{
public:
    void Draw() override;
};

class Triangle: public IGraphicalPrimitive
{
public:
    void Draw() override;
};

class Circle: public IGraphicalPrimitive
{
public:
    void Draw() override;
};