/*
** EPITECH PROJECTNode 2022
** Node_findChildByPath.cpp
** File description:
** Node_findChildByPath.cpp
*/

#include <gtest/gtest.h>
#include "myxmlpp/Doc.hpp"
#include "myxmlpp/exceptions/NodeNotFoundException.hpp"

TEST(Node_findChildByPath, not_exist_path) {
    myxmlpp::Doc d("tests/files/unit-testing/findChild.xml");

    try {
        d.getRoot()->findChildByPath("path/fictive", "!exist");
        FAIL() << "Should have thrown an exception";
    } catch (myxmlpp::NodeNotFoundException &e) {
        SUCCEED();
    }
}

TEST(Node_findChildByPath, half_exist_path) {
    myxmlpp::Doc d("tests/files/unit-testing/findChild.xml");

    try {
        d.getRoot()->findChildByPath("Blocks/fictive", "Block1");
        FAIL() << "Should have thrown an exception";
    } catch (myxmlpp::NodeNotFoundException &e) {
        SUCCEED();
    }
}

TEST(Node_findChildByPath, starting_from_nowhere_path) {
    myxmlpp::Doc d("tests/files/unit-testing/findChild.xml");

    try {
        d.getRoot()->findChildByPath("MiddleSub2Block1", "MiddleSub3Block2");
        FAIL() << "Should have thrown an exception";
    } catch (myxmlpp::NodeNotFoundException &e) {
        SUCCEED();
    }
}

TEST(Node_findChildByPath, hard_good_path) {
    myxmlpp::Doc d("tests/files/unit-testing/findChild.xml");

    try {
        d.getRoot()->findChildByPath("MiddleBlock/MiddleSubBlock2/MiddleSub2Block1", "MiddleSub3Block2");
        SUCCEED();
    } catch (myxmlpp::NodeNotFoundException &e) {
        FAIL() << "Should not have thrown an exception";
    }
}

TEST(Node_findChildByPath, hard_2_good_path) {
    myxmlpp::Doc d("tests/files/unit-testing/findChild.xml");

    try {
        std::shared_ptr<myxmlpp::Node> n =
                d.getRoot()->findChildByPath("TailBlock/SubBlock2/Sub2Block1/Sub3Block2", "DepthTest");
        if (n->findAttribute("d")->getValue() != "Last")
            FAIL() << "Should have found last attribute";
        else
            SUCCEED();
    } catch (myxmlpp::Exception &e) {
        FAIL() << "Should not have thrown an exception";
    }
}
