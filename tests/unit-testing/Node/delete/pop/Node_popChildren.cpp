/*
** EPITECH PROJECT, 2022
** Node_findChildren.cpp
** File description:
** Node_findChildren.cpp
*/

#include <gtest/gtest.h>
#include "myxmlpp/Doc.hpp"
#include "myxmlpp/exceptions/NodeNotFoundException.hpp"

TEST(Node_popChildren, not_found)
{
    myxmlpp::Doc d("tests/files/unit-testing/findChildren.xml");

    try {
        auto children = d.getRoot()->popChildren("!exists");
        EXPECT_TRUE(children.empty());
    } catch (myxmlpp::NodeNotFoundException &e) {
        FAIL() << "Should not have thrown an exception";
    }
}

TEST(Node_popChildren, one_found)
{
    myxmlpp::Doc d("tests/files/unit-testing/findChildren.xml");

    try {
        auto children = d.getRoot()->popChildren("Head");

        EXPECT_EQ(children.size(), 1);
        EXPECT_TRUE(children[0]->getTag() == "Head");
        auto found = d.getRoot()->findChildren("Head");
    } catch (myxmlpp::NodeNotFoundException &e) {
        SUCCEED();
    }
}

TEST(Node_popChildren, many_found)
{
    myxmlpp::Doc d("tests/files/unit-testing/findChildren.xml");

    try {
        auto children = d.getRoot()->popChildren("EmptyNode");

        EXPECT_EQ(children.size(), 5);
        EXPECT_TRUE(children[0]->getTag() == "EmptyNode");
        auto found = d.getRoot()->findChildren("EmptyNode");
    } catch (myxmlpp::NodeNotFoundException &e) {
        SUCCEED();
    }
}