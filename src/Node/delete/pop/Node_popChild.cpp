/*
** EPITECH PROJECT, 2022
** Node_rmChild.cpp
** File description:
** Node_rmChild.cpp
*/

#include "myxmlpp/Node.hpp"
#include "myxmlpp/exceptions/NodeNotFoundException.hpp"

std::shared_ptr<myxmlpp::Node>
myxmlpp::Node::popChild(const std::string &tag) noexcept
{
    std::shared_ptr<Node> found;

    for (auto it = _children.begin(); it != _children.end(); ++it) {
        if ((*it)->getTag() == tag) {
            found = *it;
            _children.erase(it);
            return found;
        }
    }
    return {nullptr};
}