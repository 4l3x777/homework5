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
	ASSERT_EQ(new_stdout.str(), "void Controller::CreateNewDocument()\n");
}

TEST_F(TestController, test_create_polygon)
{
    controller = std::make_unique<Controller>();
    controller->CreateNewDocument();
    auto polygon = controller->CreatePolygon();    	
	ASSERT_EQ(new_stdout.str(), "void Controller::CreateNewDocument()\nstd::shared_ptr<Polygon> Controller::CreatePolygon()\nstd::shared_ptr<Polygon> Document::AddPolygon()\nvirtual void Polygon::Draw()\n");
}

TEST_F(TestController, test_delete_polygon)
{
    controller = std::make_unique<Controller>();
    controller->CreateNewDocument();
    auto polygon = controller->CreatePolygon();  
    controller->DeleteGraphicalPrimitive(polygon);    	
	ASSERT_EQ(new_stdout.str(), "void Controller::CreateNewDocument()\nstd::shared_ptr<Polygon> Controller::CreatePolygon()\nstd::shared_ptr<Polygon> Document::AddPolygon()\nvirtual void Polygon::Draw()\nvoid Controller::DeleteGraphicalPrimitive(std::shared_ptr<IGraphicalPrimitive>)\nvoid Document::DeletePrimitive(std::shared_ptr<IGraphicalPrimitive>)\nPrimitive deleted!\n");
}

int main(int argc, char *argv[])
{
	::testing::InitGoogleTest(&argc, argv);
	return RUN_ALL_TESTS();
}