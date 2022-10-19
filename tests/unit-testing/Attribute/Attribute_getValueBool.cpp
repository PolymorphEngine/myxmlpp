/*
** EPITECH PROJECT, 2022
** Attribute_getValue.cpp
** File description:
** Attribute_getValue.cpp
*/

#include <gtest/gtest.h>
#include "myxmlpp/Attribute.hpp"
#include "myxmlpp/exceptions/IllegalValueException.hpp"

TEST(Attribute_getValueBool, simple_true)
{
    std::string k = "key";
    std::string v = "true";
    myxmlpp::Attribute a(k, v);

    EXPECT_TRUE(a.getValueBool());
}

TEST(Attribute_getValueFalse, simple_false)
{
    std::string k = "key";
    std::string v = "false";
    myxmlpp::Attribute a(k, v);

    EXPECT_FALSE(a.getValueBool());
}

TEST(Attribute_getValueBool, overriden_true_num)
{
    std::string k = "key";
    std::string v = "1";
    myxmlpp::Attribute a(k, v);

    EXPECT_TRUE(a.getValueBool("1"));
}

TEST(Attribute_getValueBool, overriden_false_num)
{
    std::string k = "key";
    std::string v = "0";
    myxmlpp::Attribute a(k, v);

    EXPECT_FALSE(a.getValueBool("1", "0"));
}

TEST(Attribute_getValueBool, overriden_true_str)
{
    std::string k = "key";
    std::string v = "TRUE";
    myxmlpp::Attribute a(k, v);

    EXPECT_TRUE(a.getValueBool("TRUE"));
}

TEST(Attribute_getValueBool, overriden_false_str)
{
    std::string k = "key";
    std::string v = "FALSE";
    myxmlpp::Attribute a(k, v);

    EXPECT_TRUE(!a.getValueBool("TRUE", "FALSE"));
}

TEST(Attribute_getValueBool, illegal)
{
    std::string k = "key";
    std::string v = "1kappa";
    myxmlpp::Attribute a(k, v);

    try {
        (void)a.getValueBool();
        FAIL() << "Should have thrown an exception";
    } catch (const myxmlpp::IllegalValueException &e) {
        SUCCEED();
    }
}

TEST(Attribute_getValueBool, illegal_overriden)
{
    std::string k = "key";
    std::string v = "true";
    myxmlpp::Attribute a(k, v);

    try {
        (void)a.getValueBool("TRUE");
        FAIL() << "Should have thrown an exception";
    } catch (const myxmlpp::IllegalValueException &e) {
        SUCCEED();
    }
}