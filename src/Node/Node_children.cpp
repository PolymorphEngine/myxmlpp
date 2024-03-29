/*
** EPITECH PROJECT, 2022
** Node_children.cpp
** File description:
** Node_children.cpp
*/

#include "myxmlpp/Node.hpp"

unsigned int myxmlpp::Node::getNbChildren() const noexcept
{
    return _children.size();
}

unsigned int myxmlpp::Node::getNbChildrenR() const noexcept
{
    size_t total = _children.size();

    for (const auto & child : _children)
        total += child->getNbChildrenR();
    return total;
}

bool myxmlpp::Node::empty() const noexcept
{
    return _children.empty();
}

void myxmlpp::Node::move(myxmlpp::Node &newParent) noexcept
{
    auto popped = _parent->popChild(_tag);
    popped->setParent(&newParent);
    newParent.addChild(popped);
}