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

TEST(Node_popChildR, not_exist)
{
    myxmlpp::Doc d("tests/files/unit-testing/findChild.xml");

    try {
        d.getRoot()->popChildR("!exist");
        SUCCEED();
    } catch (myxmlpp::NodeNotFoundException &e) {
        FAIL() << "Should not have thrown an exception";
    }
}

TEST(Node_popChildR, simple)
{
    myxmlpp::Doc d("tests/files/unit-testing/findChild.xml");

    try {
        auto before = d.getRoot()->findChildrenR("DepthTest");
        d.getRoot()->popChildR("DepthTest");
        auto after = d.getRoot()->findChildrenR("DepthTest");
        EXPECT_EQ(before.size() - 1, after.size());
    } catch (myxmlpp::NodeNotFoundException &e) {
        SUCCEED();
    }
}