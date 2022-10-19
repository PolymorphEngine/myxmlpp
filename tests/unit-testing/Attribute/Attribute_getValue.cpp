/*
** EPITECH PROJECT, 2022
** Attribute_getValue.cpp
** File description:
** Attribute_getValue.cpp
*/

#include <gtest/gtest.h>
#include "myxmlpp/Attribute.hpp"

TEST(Attribute_getValue, simple)
{
    std::string k = "key";
    std::string v = "value";
    myxmlpp::Attribute a(k, v);

    EXPECT_EQ(a.getValue(), "value");
}