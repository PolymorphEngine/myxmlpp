/*
** EPITECH PROJECT, 2022
** Node_findChildren.cpp
** File description:
** Node_findChildren.cpp
*/

#include <gtest/gtest.h>
#include "myxmlpp/Doc.hpp"
#include "myxmlpp/exceptions/NodeNotFoundException.hpp"

TEST(Node_findChildren, not_found)
{
    myxmlpp::Doc d("tests/files/unit-testing/findChildren.xml");

    try {
        d.getRoot()->findChildren("kappa");
        FAIL() << "Should have thrown an exception";
    } catch (myxmlpp::NodeNotFoundException &e) {
        SUCCEED();
    }
}

TEST(Node_findChildren, one_found)
{
    myxmlpp::Doc d("tests/files/unit-testing/findChildren.xml");

    try {
        auto children = d.getRoot()->findChildren("Head");

        EXPECT_EQ(children.size(), 1);
        EXPECT_TRUE(children[0]->getTag() == "Head");
    } catch (myxmlpp::NodeNotFoundException &e) {
        FAIL() << "Should not have thrown an exception";
    }
}

TEST(Node_findChildren, many_found)
{
    myxmlpp::Doc d("tests/files/unit-testing/findChildren.xml");

    try {
        auto children = d.getRoot()->findChildren("EmptyNode");

        EXPECT_EQ(children.size(), 5);
        EXPECT_TRUE(children[0]->getTag() == "EmptyNode");
    } catch (myxmlpp::NodeNotFoundException &e) {
        FAIL() << "Should not have thrown an exception";
    }
}