/*
** EPITECH PROJECT, 2022
** Node_findChildren.cpp
** File description:
** Node_findChildren.cpp
*/

#include <gtest/gtest.h>
#include "myxmlpp/Doc.hpp"
#include "myxmlpp/exceptions/NodeNotFoundException.hpp"

TEST(Node_popChildrenR, not_found)
{
    myxmlpp::Doc d("tests/files/unit-testing/findChildren.xml");

    try {
        auto children = d.getRoot()->popChildrenR("!exists");
        EXPECT_TRUE(children.empty());
    } catch (myxmlpp::NodeNotFoundException &e) {
        FAIL() << "Should not have thrown an exception";
    }
}

TEST(Node_popChildrenR, one_found)
{
    myxmlpp::Doc d("tests/files/unit-testing/findChildren.xml");

    try {
        auto children = d.getRoot()->popChildrenR("Head");

        EXPECT_EQ(children.size(), 1);
        EXPECT_TRUE(children[0]->getTag() == "Head");
        auto found = d.getRoot()->findChildrenR("Head");
        EXPECT_TRUE(0);
    } catch (myxmlpp::NodeNotFoundException &e) {
        SUCCEED();
    }
}

TEST(Node_popChildrenR, many_found)
{
    myxmlpp::Doc d("tests/files/unit-testing/findChildren.xml");

    try {
        auto children = d.getRoot()->popChildrenR("DepthTest");

        EXPECT_EQ(children.size(), 6);
        EXPECT_TRUE(children[0]->getTag() == "DepthTest");
        auto found = d.getRoot()->findChildrenR("DepthTest");
        EXPECT_TRUE(0);
    } catch (myxmlpp::NodeNotFoundException &e) {
        SUCCEED();
    }
}