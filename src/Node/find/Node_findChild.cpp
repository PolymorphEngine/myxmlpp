/*
** EPITECH PROJECT, 2022
** Node_findChild.cpp
** File description:
** Node_findChild.cpp
*/

#include "myxmlpp/Node.hpp"
#include "myxmlpp/exceptions/NodeNotFoundException.hpp"

std::shared_ptr<myxmlpp::Node>
myxmlpp::Node::findChild(const std::string& tag) const
{
    for (auto & it : _children) {
        if (it->getTag() == tag)
            return it;
    }
    throw NodeNotFoundException(tag, MYXMLPP_ERROR_LOCATION);
}