/*
** EPITECH PROJECT, 2022
** Node_findChildren.cpp
** File description:
** Node_findChildren.cpp
*/

#include <gtest/gtest.h>
#include "myxmlpp/Doc.hpp"
#include "myxmlpp/exceptions/NodeNotFoundException.hpp"

TEST(Node_findChildrenBySPath, not_found)
{
    myxmlpp::Doc d("tests/files/unit-testing/findChildren.xml");

    try {
        d.getRoot()->findChildrenBySPath("MiddleBlock/MiddleSubBlock2/MiddleSub2Block1/MiddleSub3Block2/NotFound");
        FAIL() << "Should have thrown an exception";
    } catch (myxmlpp::NodeNotFoundException &e) {
        SUCCEED();
    }
}

TEST(Node_findChildrenBySPath, good_path)
{
    myxmlpp::Doc d("tests/files/unit-testing/findChildren.xml");

    try {
        auto children = d.getRoot()->findChildrenBySPath("MiddleBlock/MiddleSubBlock2/MiddleSub2Block1/MiddleSub3Block2/MiddleSub4Block");

        EXPECT_EQ(children.size(), 4);
        EXPECT_TRUE(children[3]->findAttribute("d")->getValue() == "last");
    } catch (myxmlpp::NodeNotFoundException &e) {
        FAIL() << "Should not have thrown an exception";
    }
}