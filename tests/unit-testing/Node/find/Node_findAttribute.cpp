/*
** EPITECH PROJECTNode 2022
** Node_findAttribute.cpp
** File description:
** Node_findAttribute.cpp
*/

#include <gtest/gtest.h>
#include "myxmlpp/Doc.hpp"
#include "myxmlpp/Node.hpp"
#include "myxmlpp/exceptions/AttributeNotFoundException.hpp"

TEST(Node_findAttribute, not_exist)
{
    std::vector<std::shared_ptr<myxmlpp::Attribute>> attrs = {
            std::make_shared<myxmlpp::Attribute>("key", "value"),
            std::make_shared<myxmlpp::Attribute>("key2", "value2")
    };
    myxmlpp::Node n(nullptr, "tag", attrs);

    try {
        n.findAttribute("!exist");
        FAIL() << "Should have thrown an exception";
    } catch (myxmlpp::AttributeNotFoundException &e) {
        SUCCEED();
    }
}

TEST(Node_findAttribute, first_attr)
{
    std::vector<std::shared_ptr<myxmlpp::Attribute>> attrs = {
            std::make_shared<myxmlpp::Attribute>("key", "value"),
            std::make_shared<myxmlpp::Attribute>("key2", "value2")
    };
    myxmlpp::Node n(nullptr, "tag", attrs);

    try {
        n.findAttribute("key");
        SUCCEED();
    } catch (myxmlpp::AttributeNotFoundException &e) {
        FAIL() << "Should not have thrown an exception";
    }
}

TEST(Node_findAttribute, second_attr)
{
    std::vector<std::shared_ptr<myxmlpp::Attribute>> attrs = {
            std::make_shared<myxmlpp::Attribute>("key", "value"),
            std::make_shared<myxmlpp::Attribute>("key2", "value2")
    };
    myxmlpp::Node n(nullptr, "tag", attrs);

    try {
        n.findAttribute("key2");
        SUCCEED();
    } catch (myxmlpp::AttributeNotFoundException &e) {
        FAIL() << "Should not have thrown an exception";
    }
}