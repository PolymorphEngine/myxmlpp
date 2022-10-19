/*
** EPITECH PROJECT, 2022
** Attribute_getValue.cpp
** File description:
** Attribute_getValue.cpp
*/

#include <gtest/gtest.h>
#include "myxmlpp/Attribute.hpp"
#include "myxmlpp/exceptions/IllegalValueException.hpp"

TEST(Attribute_getValueInt, positive)
{
    std::string k = "key";
    std::string v = "1";
    myxmlpp::Attribute a(k, v);

    EXPECT_EQ(a.getValueInt(), 1);
}

TEST(Attribute_getValueInt, negative)
{
    std::string k = "key";
    std::string v = "-1";
    myxmlpp::Attribute a(k, v);

    EXPECT_EQ(a.getValueInt(), -1);
}

TEST(Attribute_getValueInt, zero)
{
    std::string k = "key";
    std::string v = "0";
    myxmlpp::Attribute a(k, v);

    EXPECT_EQ(a.getValueInt(), 0);
}

TEST(Attribute_getValueInt, illegal)
{
    std::string k = "key";
    std::string v = "1kappa";
    myxmlpp::Attribute a(k, v);

    try {
        (void)a.getValueInt();
        FAIL() << "Should have thrown an exception";
    } catch (const myxmlpp::IllegalValueException) {
        SUCCEED();
    }
}