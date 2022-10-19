/*
** EPITECH PROJECTNode 2022
** Node_findChildR.cpp
** File description:
** Node_findChildR.cpp
*/

#include <gtest/gtest.h>
#include "myxmlpp/Doc.hpp"
#include "myxmlpp/exceptions/NodeNotFoundException.hpp"

TEST(Node_findChildR, not_existR) {
    myxmlpp::Doc d("tests/files/unit-testing/findChild.xml");

    try {
        d.getRoot()->findChildR("!exist");
        FAIL() << "Should have thrown an exception";
    } catch (myxmlpp::NodeNotFoundException &e) {
        SUCCEED();
    }
}

TEST(Node_findChildR, found_sub_childR) {
    myxmlpp::Doc d("tests/files/unit-testing/findChild.xml");

    try {
        d.getRoot()->findChildR("Block1");
        SUCCEED();
    } catch (myxmlpp::NodeNotFoundException &e) {
        FAIL() << "Should not have thrown an exception";
    }
}

TEST(Node_findChildR, not_exist_sub_childR) {
    myxmlpp::Doc d("tests/files/unit-testing/findChild.xml");

    try {
        d.getRoot()->findChildR("Block5");
        FAIL() << "Should have thrown an exception";
    } catch (myxmlpp::NodeNotFoundException &e) {
        SUCCEED();
    }
}

TEST(Node_findChildR, found_empty_inline_childR) {
    myxmlpp::Doc d("tests/files/unit-testing/findChild.xml");

    try {
        d.getRoot()->findChildR("EmptyNode");
        SUCCEED();
    } catch (myxmlpp::NodeNotFoundException &e) {
        FAIL() << "Should not have thrown an exception";
    }
}


TEST(Node_findChildR, found_empty_data_childR)
{
    myxmlpp::Doc d("tests/files/unit-testing/findChild.xml");

    try {
        d.getRoot()->findChildR("EmptyBlock");
        SUCCEED();
    } catch (myxmlpp::NodeNotFoundException &e) {
        FAIL() << "Should not have thrown an exception";
    }
}

TEST(Node_findChildR, found_last_empty_data_childR) {
    myxmlpp::Doc d("tests/files/unit-testing/findChild.xml");

    try {
        d.getRoot()->findChildR("Tail");
        SUCCEED();
    } catch (myxmlpp::NodeNotFoundException &e) {
        FAIL() << "Should not have thrown an exception";
    }
}

TEST(Node_findChildR, found_last_empty_inline_childR)
{
    myxmlpp::Doc d("tests/files/unit-testing/findChild.xml");

    try {
        d.getRoot()->findChildR("EmptyNode2");
        SUCCEED();
    } catch (myxmlpp::NodeNotFoundException &e) {
        FAIL() << "Should not have thrown an exception";
    }
}

TEST(Node_findChildR, found_subnode_depth1_childR)
{
    myxmlpp::Doc d("tests/files/unit-testing/findChild.xml");

    try {
        d.getRoot()->findChildR("MiddleSubBlock1");
        SUCCEED();
    } catch (myxmlpp::NodeNotFoundException &e) {
        FAIL() << "Should not have thrown an exception";
    }
}

TEST(Node_findChildR, found_subnode_depth1_wchildren_childR)
{
    myxmlpp::Doc d("tests/files/unit-testing/findChild.xml");

    try {
        d.getRoot()->findChildR("MiddleSubBlock2");
        SUCCEED();
    } catch (myxmlpp::NodeNotFoundException &e) {
        FAIL() << "Should not have thrown an exception";
    }
}

TEST(Node_findChildR, found_subnode_depth2_wchildren_childR)
{
    myxmlpp::Doc d("tests/files/unit-testing/findChild.xml");

    try {
        d.getRoot()->findChildR("MiddleSub2Block1");
        SUCCEED();
    } catch (myxmlpp::NodeNotFoundException &e) {
        FAIL() << "Should not have thrown an exception";
    }
}

TEST(Node_findChildR, found_subnode_depth2_last_childR)
{
    myxmlpp::Doc d("tests/files/unit-testing/findChild.xml");

    try {
        d.getRoot()->findChildR("MiddleSub2Block3");
        SUCCEED();
    } catch (myxmlpp::NodeNotFoundException &e) {
        FAIL() << "Should not have thrown an exception";
    }
}

TEST(Node_findChildR, found_subnode_depth3_childR)
{
    myxmlpp::Doc d("tests/files/unit-testing/findChild.xml");

    try {
        d.getRoot()->findChildR("MiddleSub3Block2");
        SUCCEED();
    } catch (myxmlpp::NodeNotFoundException &e) {
        FAIL() << "Should not have thrown an exception";
    }
}

TEST(Node_findChildR, found_subnode_depth4_childR)
{
    myxmlpp::Doc d("tests/files/unit-testing/findChild.xml");

    try {
        d.getRoot()->findChildR("MiddleSub4Block1");
        SUCCEED();
    } catch (myxmlpp::NodeNotFoundException &e) {
        FAIL() << "Should not have thrown an exception";
    }
}

TEST(Node_findChildR, found_subnode_depth1_childR_Hard)
{
    myxmlpp::Doc d("tests/files/unit-testing/findChild.xml");

    try {
        d.getRoot()->findChildR("SubBlock1");
        SUCCEED();
    } catch (myxmlpp::NodeNotFoundException &e) {
        FAIL() << "Should not have thrown an exception";
    }
}

TEST(Node_findChildR, found_subnode_depth1_wchildren_childR_Hard)
{
    myxmlpp::Doc d("tests/files/unit-testing/findChild.xml");

    try {
        d.getRoot()->findChildR("SubBlock2");
        SUCCEED();
    } catch (myxmlpp::NodeNotFoundException &e) {
        FAIL() << "Should not have thrown an exception";
    }
}

TEST(Node_findChildR, found_subnode_depth2_wchildren_childR_Hard)
{
    myxmlpp::Doc d("tests/files/unit-testing/findChild.xml");

    try {
        d.getRoot()->findChildR("Sub2Block1");
        SUCCEED();
    } catch (myxmlpp::NodeNotFoundException &e) {
        FAIL() << "Should not have thrown an exception";
    }
}

TEST(Node_findChildR, found_subnode_depth2_last_childR_Hard)
{
    myxmlpp::Doc d("tests/files/unit-testing/findChild.xml");

    try {
        d.getRoot()->findChildR("Sub2Block3");
        SUCCEED();
    } catch (myxmlpp::NodeNotFoundException &e) {
        FAIL() << "Should not have thrown an exception";
    }
}

TEST(Node_findChildR, found_subnode_depth3_childR_Hard)
{
    myxmlpp::Doc d("tests/files/unit-testing/findChild.xml");

    try {
        d.getRoot()->findChildR("Sub3Block2");
        SUCCEED();
    } catch (myxmlpp::NodeNotFoundException &e) {
        FAIL() << "Should not have thrown an exception";
    }
}

TEST(Node_findChildR, found_subnode_depth4_childR_Hard)
{
    myxmlpp::Doc d("tests/files/unit-testing/findChild.xml");

    try {
        d.getRoot()->findChildR("Sub4Block1");
        SUCCEED();
    } catch (myxmlpp::NodeNotFoundException &e) {
        FAIL() << "Should not have thrown an exception";
    }
}

TEST(Node_findChildR, subnode_depth_test_0)
{
    myxmlpp::Doc d("tests/files/unit-testing/findChild.xml");

    try {
        d.getRoot()->findChildR("DepthTest", 0);
        FAIL() << "Should have thrown an exception";
    } catch (myxmlpp::NodeNotFoundException &e) {
        SUCCEED();
    }
}

TEST(Node_findChildR, subnode_depth_test_1)
{
    myxmlpp::Doc d("tests/files/unit-testing/findChild.xml");

    try {
        std::shared_ptr<myxmlpp::Node> n =
                d.getRoot()->findChildR("DepthTest", 1);
        if (n->findAttribute("d")->getValue() == "0")
            SUCCEED();
        else
            FAIL() << "Should have found an attribute";
    } catch (myxmlpp::NodeNotFoundException &e) {
        FAIL() << "Should not have thrown an exception";
    }
}

TEST(Node_findChildR, subnode_depth_test_2)
{
    myxmlpp::Doc d("tests/files/unit-testing/findChild.xml");

    try {

        std::shared_ptr<myxmlpp::Node> n =
                d.getRoot()->findChildR("DepthTest", 2);
        if (n->findAttribute("d")->getValue() == "0")
            SUCCEED();
        else
            FAIL() << "Should have found an attribute";
    } catch (myxmlpp::NodeNotFoundException &e) {
        FAIL() << "Should not have thrown an exception";
    }
}

TEST(Node_findChildR, subnode_depth_test_3)
{
    myxmlpp::Doc d("tests/files/unit-testing/findChild.xml");

    try {

        std::shared_ptr<myxmlpp::Node> n =
                d.getRoot()->findChildR("DepthTest", 3);
        if (n->findAttribute("d")->getValue() == "0")
            SUCCEED();
        else
            FAIL() << "Should have found an attribute";
    } catch (myxmlpp::NodeNotFoundException &e) {
        FAIL() << "Should not have thrown an exception";
    }
}

TEST(Node_findChildR, subnode_depth_test_4)
{
    myxmlpp::Doc d("tests/files/unit-testing/findChild.xml");

    try {

        std::shared_ptr<myxmlpp::Node> n =
                d.getRoot()->findChildR("DepthTest", 4);
        if (n->findAttribute("d")->getValue() == "0")
            SUCCEED();
        else
            FAIL() << "Should have found an attribute";
    } catch (myxmlpp::NodeNotFoundException &e) {
        FAIL() << "Should not have thrown an exception";
    }
}

TEST(Node_findChildR, depth4_child_but_lower_max_depth)
{
    myxmlpp::Doc d("tests/files/unit-testing/findChild.xml");

    try {
        d.getRoot()->findChildR("Sub4Block2", 2);
        FAIL() << "Should have thrown an exception";
    } catch (myxmlpp::NodeNotFoundException &e) {
        SUCCEED();
    }
}