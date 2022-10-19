/*
** EPITECH PROJECTNode 2022
** Node_findChild.cpp
** File description:
** Node_findChild.cpp
*/

#include <gtest/gtest.h>
#include "myxmlpp/Doc.hpp"
#include "myxmlpp/Node.hpp"
#include "myxmlpp/exceptions/NodeNotFoundException.hpp"

TEST(Node_popChild, not_exist)
{
    myxmlpp::Doc d("tests/files/unit-testing/findChild.xml");

    try {
        d.getRoot()->popChild("!exist");
        SUCCEED();
    } catch (myxmlpp::NodeNotFoundException &e) {
        FAIL() << "Should not have thrown an exception";
    }
}

TEST(Node_popChild, simple)
{
    myxmlpp::Doc d("tests/files/unit-testing/findChild.xml");

    try {
        d.getRoot()->popChild("Head");
        d.getRoot()->findChild("Head");
        FAIL() << "Should have thrown an exception";
    } catch (myxmlpp::NodeNotFoundException &e) {
        SUCCEED();
    }
}