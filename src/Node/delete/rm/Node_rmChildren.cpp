/*
** EPITECH PROJECT, 2022
** Node_rmChildren.cpp
** File description:
** Node_rmChildren.cpp
*/

#include "myxmlpp/Node.hpp"

void myxmlpp::Node::rmChildren(const std::string &tag) noexcept
{
    auto children = popChildren(tag);
}

void myxmlpp::Node::rmChildren() noexcept
{
    auto children = popChildren();
}
