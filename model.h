/*!
    \file
    \brief Header file

    That file contain document class
*/
#pragma once
#include <memory>
#include <list>
#include <iostream>
#include "view.h"

/*!
	\brief Document class.
    \version 1.0
    \author 4l3x77

	That class contain document methods

    \defgroup document
    @{
*/
class Document 
{
    /*!
        \brief Field of current primitives.
    */
    std::list<std::shared_ptr<IGraphicalPrimitive>> _primitives;
public: 
    /*!
        \brief Method for add square.
        \returns Pointer to square.
    */
    std::shared_ptr<Square> AddSquare();

    /*!
        \brief Method for add polygon.
        \returns Pointer to polygon.
    */    
    std::shared_ptr<Polygon> AddPolygon();

    /*!
        \brief Method for add triangle.
        \returns Pointer to triangle.
    */    
    std::shared_ptr<Triangle> AddTriangle();

    /*!
        \brief Method for add circle.
        \returns Pointer to circle.
    */
    std::shared_ptr<Circle> AddCircle();

    /*!
        \brief Method for delete graphical primitive.
        \param primitive is any graphical primitive in current work document.
    */
    void DeletePrimitive(std::shared_ptr<IGraphicalPrimitive> primitive);
};
/*! @} */