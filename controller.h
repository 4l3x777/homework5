/*!
    \file
    \brief Header file

    That file contain controller class
*/
#pragma once
#include <memory>
#include <list>
#include "model.h"

/*!
	\brief Controller class.
    \version 1.0
    \author 4l3x77

	That class contain controller methods

    \defgroup controller
    @{
*/
class Controller
{
    /*!
        \brief Field of current work document.
    */
    std::unique_ptr<Document> _document;
public:
    /*!
        \brief Method for create new document.
    */
    void CreateNewDocument();

    /*!
        \brief Method for imort document from file.
    */
    void ImportDocumentFromFile();

    /*!
        \brief Method for export document to file.
    */
    void ExportDocumentToFile();

    /*!
        \brief Method for create square.
        \returns Pointer to square.
    */
    std::shared_ptr<Square> CreateSquare();

    /*!
        \brief Method for create polygon.
        \returns Pointer to polygon.
    */
    std::shared_ptr<Polygon> CreatePolygon();

    /*!
        \brief Method for create triangle.
        \returns Pointer to triangle.
    */
    std::shared_ptr<Triangle> CreateTriangle();

    /*!
        \brief Method for create circle.
        \returns Pointer to circle.
    */
    std::shared_ptr<Circle> CreateCircle();

    /*!
        \brief Method for delete graphical primitive.
        \param primitive is any graphical primitive in current work document.
    */
    void DeleteGraphicalPrimitive(std::shared_ptr<IGraphicalPrimitive> primitive);
};
/*! @} */