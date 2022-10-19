/*
** EPITECH PROJECTNode 2022
** Node_findChildBySPath.cpp
** File description:
** Node_findChildBySPath.cpp
*/

#include <gtest/gtest.h>
#include "myxmlpp/Doc.hpp"
#include "myxmlpp/exceptions/NodeNotFoundException.hpp"

TEST(Node_findChildBySPath, not_exist_path) {
    myxmlpp::Doc d("tests/files/unit-testing/findChild.xml");

    try {
        d.getRoot()->findChildBySPath("path/fictive/!exist");
        FAIL() << "Should have thrown an exception";
    } catch (myxmlpp::NodeNotFoundException &e) {
        SUCCEED();
    }
}

TEST(Node_findChildBySPath, half_exist_path) {
    myxmlpp::Doc d("tests/files/unit-testing/findChild.xml");

    try {
        d.getRoot()->findChildBySPath("Blocks/fictive/Block1");
        FAIL() << "Should have thrown an exception";
    } catch (myxmlpp::NodeNotFoundException &e) {
        SUCCEED();
    }
}

TEST(Node_findChildBySPath, starting_from_nowhere_path) {
    myxmlpp::Doc d("tests/files/unit-testing/findChild.xml");

    try {
        d.getRoot()->findChildBySPath("MiddleSub2Block1/MiddleSub3Block2");
        FAIL() << "Should have thrown an exception";
    } catch (myxmlpp::NodeNotFoundException &e) {
        SUCCEED();
    }
}

TEST(Node_findChildBySPath, hard_good_path) {
    myxmlpp::Doc d("tests/files/unit-testing/findChild.xml");

    try {
        d.getRoot()->findChildBySPath("MiddleBlock/MiddleSubBlock2/MiddleSub2Block1/MiddleSub3Block2");
        SUCCEED();
    } catch (myxmlpp::NodeNotFoundException &e) {
        FAIL() << "Should not have thrown an exception";
    }
}

TEST(Node_findChildBySPath, hard_2_good_path) {
    myxmlpp::Doc d("tests/files/unit-testing/findChild.xml");

    try {
        std::shared_ptr<myxmlpp::Node> n =
                d.getRoot()->findChildBySPath("TailBlock/SubBlock2/Sub2Block1/Sub3Block2/DepthTest");
        if (n->findAttribute("d")->getValue() != "Last")
            FAIL() << "Should have found last attribute";
        else
            SUCCEED();
    } catch (myxmlpp::Exception &e) {
        FAIL() << "Should not have thrown an exception";
    }
}
