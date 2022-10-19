/*
** EPITECH PROJECT, 2022
** Node_findChildren.cpp
** File description:
** Node_findChildren.cpp
*/

#include <gtest/gtest.h>
#include "myxmlpp/Doc.hpp"
#include "myxmlpp/exceptions/NodeNotFoundException.hpp"

TEST(Node_findChildrenR, not_found)
{
    myxmlpp::Doc d("tests/files/unit-testing/findChildren.xml");

    try {
        d.getRoot()->findChildrenR("!exist");
        FAIL() << "Should have thrown an exception";
    } catch (myxmlpp::NodeNotFoundException &e) {
        SUCCEED();
    }
}

TEST(Node_findChildrenR, one_level)
{
    myxmlpp::Doc d("tests/files/unit-testing/findChildren.xml");

    try {
        auto children = d.getRoot()->findChildrenR("DepthTest", 1);

        EXPECT_EQ(children.size(), 1);
        EXPECT_TRUE(children[0]->findAttribute("d")->getValue() == "0");
    } catch (myxmlpp::NodeNotFoundException &e) {
        FAIL() << "Should not have thrown an exception";
    }
}

TEST(Node_findChildrenR, many_found_without_depth)
{
    myxmlpp::Doc d("tests/files/unit-testing/findChildren.xml");

    try {
        auto children = d.getRoot()->findChildrenR("DepthTest");

        EXPECT_EQ(children.size(), 6);
    } catch (myxmlpp::NodeNotFoundException &e) {
        FAIL() << "Should not have thrown an exception";
    }
}

TEST(Node_findChildrenR, many_found_overkill_depth)
{
    myxmlpp::Doc d("tests/files/unit-testing/findChildren.xml");

    try {
        auto children = d.getRoot()->findChildrenR("DepthTest", 50);

        EXPECT_EQ(children.size(), 6);
    } catch (myxmlpp::NodeNotFoundException &e) {
        FAIL() << "Should not have thrown an exception";
    }
}

TEST(Node_findChildrenR, many_found_depth4)
{
    myxmlpp::Doc d("tests/files/unit-testing/findChildren.xml");

    try {
        auto children = d.getRoot()->findChildrenR("DepthTest", 4);

        EXPECT_EQ(children.size(), 4);
    } catch (myxmlpp::NodeNotFoundException &e) {
        FAIL() << "Should not have thrown an exception";
    }
}

TEST(Node_findChildrenR, many_found_depth3)
{
    myxmlpp::Doc d("tests/files/unit-testing/findChildren.xml");

    try {
        auto children = d.getRoot()->findChildrenR("DepthTest", 3);

        EXPECT_EQ(children.size(), 3);
    } catch (myxmlpp::NodeNotFoundException &e) {
        FAIL() << "Should not have thrown an exception";
    }
}

TEST(Node_findChildrenR, many_found_no_search_depth)
{
    myxmlpp::Doc d("tests/files/unit-testing/findChildren.xml");

    try {
        auto children = d.getRoot()->findChildrenR("DepthTest", 0);

        EXPECT_TRUE(children.empty());
    } catch (myxmlpp::NodeNotFoundException &e) {
        FAIL() << "Should not have thrown an exception";
    }
}