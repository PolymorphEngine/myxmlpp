/*
** EPITECH PROJECT, 2022
** Attribute_getValue.cpp
** File description:
** Attribute_getValue.cpp
*/

#include <gtest/gtest.h>
#include "myxmlpp/Attribute.hpp"
#include "myxmlpp/exceptions/IllegalValueException.hpp"

TEST(Attribute_getValueFloat, positive)
{
    std::string k = "key";
    std::string v = "1.5";
    myxmlpp::Attribute a(k, v);

    EXPECT_FLOAT_EQ(a.getValueFloat(), 1.5);
}

TEST(Attribute_getValueFloat, negative)
{
    std::string k = "key";
    std::string v = "-1.5";
    myxmlpp::Attribute a(k, v);

    EXPECT_FLOAT_EQ(a.getValueFloat(), -1.5);
}

TEST(Attribute_getValueFloat, zero)
{
    std::string k = "key";
    std::string v = "0";
    myxmlpp::Attribute a(k, v);

    EXPECT_FLOAT_EQ(a.getValueFloat(), 0);
}

TEST(Attribute_getValueFloat, illegal)
{
    std::string k = "key";
    std::string v = "1kappa";
    myxmlpp::Attribute a(k, v);

    try {
        (void)a.getValueFloat();
        FAIL() << "Should have thrown an exception";
    } catch (const myxmlpp::IllegalValueException) {
        SUCCEED();
    }
}