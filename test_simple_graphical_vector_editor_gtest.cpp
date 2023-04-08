#include "gtest/gtest.h"
#include "controller.h"
#include <iostream>
#include <list>

class TestController : public ::testing::Test 
{
	std::streambuf* old_stdout{nullptr};
protected:
	void SetUp() 
	{
		old_stdout = std::cout.rdbuf(new_stdout.rdbuf());
	}

	void TearDown() 
	{
		old_stdout = std::cout.rdbuf(old_stdout);
	}

	std::stringstream new_stdout;
    std::unique_ptr<Controller> controller;
};

TEST_F(TestController, test_create_document)
{	
    controller = std::make_unique<Controller>();
    controller->CreateNewDocument();
#if defined(_MSC_VER)
	ASSERT_EQ(new_stdout.str(), "void __cdecl Controller::CreateNewDocument(void)\n");
#else
	ASSERT_EQ(new_stdout.str(), "void Controller::CreateNewDocument()\n");
#endif
}

TEST_F(TestController, test_create_polygon)
{
    controller = std::make_unique<Controller>();
    controller->CreateNewDocument();
    auto polygon = controller->CreatePolygon();  
#if defined(_MSC_VER) 
	ASSERT_EQ(new_stdout.str(), "void __cdecl Controller::CreateNewDocument(void)\nclass std::shared_ptr<class Polygon> __cdecl Controller::CreatePolygon(void)\nclass std::shared_ptr<class Polygon> __cdecl Document::AddPolygon(void)\nvoid __cdecl Polygon::Draw(void)\n");
#else
	ASSERT_EQ(new_stdout.str(), "void Controller::CreateNewDocument()\nstd::shared_ptr<Polygon> Controller::CreatePolygon()\nstd::shared_ptr<Polygon> Document::AddPolygon()\nvirtual void Polygon::Draw()\n");
#endif
}

TEST_F(TestController, test_delete_polygon)
{
    controller = std::make_unique<Controller>();
    controller->CreateNewDocument();
    auto polygon = controller->CreatePolygon();  
    controller->DeleteGraphicalPrimitive(polygon);
#if defined(_MSC_VER) 
	ASSERT_EQ(new_stdout.str(), "void __cdecl Controller::CreateNewDocument(void)\nclass std::shared_ptr<class Polygon> __cdecl Controller::CreatePolygon(void)\nclass std::shared_ptr<class Polygon> __cdecl Document::AddPolygon(void)\nvoid __cdecl Polygon::Draw(void)\nvoid __cdecl Controller::DeleteGraphicalPrimitive(class std::shared_ptr<class IGraphicalPrimitive>)\nvoid __cdecl Document::DeletePrimitive(class std::shared_ptr<class IGraphicalPrimitive>)\nPrimitive deleted!\n");
#else
	ASSERT_EQ(new_stdout.str(), "void Controller::CreateNewDocument()\nstd::shared_ptr<Polygon> Controller::CreatePolygon()\nstd::shared_ptr<Polygon> Document::AddPolygon()\nvirtual void Polygon::Draw()\nvoid Controller::DeleteGraphicalPrimitive(std::shared_ptr<IGraphicalPrimitive>)\nvoid Document::DeletePrimitive(std::shared_ptr<IGraphicalPrimitive>)\nPrimitive deleted!\n");
#endif
}

int main(int argc, char *argv[])
{
	::testing::InitGoogleTest(&argc, argv);
	return RUN_ALL_TESTS();
}