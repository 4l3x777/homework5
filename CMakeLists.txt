cmake_minimum_required(VERSION 3.25)

set(PATCH_VERSION "1" CACHE INTERNAL "Patch version")
set(PROJECT_VESRION 0.0.${PATCH_VERSION})
project(simple_graphical_vector_editor VERSION ${PROJECT_VESRION})

include(FetchContent)

FetchContent_Declare(
    googletest
    GIT_REPOSITORY https://github.com/google/googletest.git
    GIT_TAG v1.13.0
)

FetchContent_GetProperties(googletest)
if(NOT googletest_POPULATED)
  FetchContent_Populate(googletest)
  add_subdirectory(${googletest_SOURCE_DIR} ${googletest_BINARY_DIR})
endif()

add_executable(
    simple_graphical_vector_editor 
    simple_graphical_vector_editor.cpp
)

add_executable(
    test_simple_graphical_vector_editor_gtest 
    test_simple_graphical_vector_editor_gtest.cpp
)

add_library(controller controller.cpp)

add_library(model model.cpp)

add_library(view view.cpp)

set_target_properties(
    simple_graphical_vector_editor
    test_simple_graphical_vector_editor_gtest
    controller
    model
    view
    PROPERTIES
    CXX_STANDARD 17
    CXX_STANDARD_REQUIRED ON
)

set_target_properties(
    test_simple_graphical_vector_editor_gtest 
    PROPERTIES 
    COMPILE_DEFINITIONS 
    STATIC_LINK
)

target_link_libraries(
    simple_graphical_vector_editor
    controller
    model
    view    
)

target_link_libraries(
    test_simple_graphical_vector_editor_gtest
    controller
    model
    view     
    gtest 
    gtest_main
)

target_link_options(simple_graphical_vector_editor PRIVATE -static -static-libgcc -static-libstdc++)

target_link_options(test_simple_graphical_vector_editor_gtest PRIVATE -static -static-libgcc -static-libstdc++)

if (MSVC)
    target_compile_options(simple_graphical_vector_editor PRIVATE /W4)
    target_compile_options(test_simple_graphical_vector_editor_gtest PRIVATE /W4)
else ()
    target_compile_options(
        simple_graphical_vector_editor 
        PRIVATE
        -Wall 
        -Wextra 
        -pedantic 
    )
    target_compile_options(
        test_simple_graphical_vector_editor_gtest 
        PRIVATE
        -Wall 
        -Wextra 
        -pedantic 
    )
endif()

install (
    TARGETS 
    simple_graphical_vector_editor 
    RUNTIME 
    DESTINATION 
    bin
)

# CPack area
if (WIN32)
    set(CPACK_GENERATOR "ZIP")
else ()
    set(CPACK_GENERATOR "DEB")
endif()
set(CPACK_PACKAGE_VERSION_MAJOR "${PROJECT_VERSION_MAJOR}")
set(CPACK_PACKAGE_VERSION_MINOR "${PROJECT_VERSION_MINOR}")
set(CPACK_PACKAGE_VERSION_PATCH "${PROJECT_VERSION_PATCH}")
set(CPACK_PACKAGE_CONTACT https://github.com/4l3x777/homework1)
include(CPack)

# Tests area
enable_testing()

add_test(
    NAME 
    unit_tests_test_simple_graphical_vector_editor_gtest 
    COMMAND 
    test_simple_graphical_vector_editor_gtest
)
