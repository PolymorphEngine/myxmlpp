/*
** EPITECH PROJECT, 2022
** Node_popChildren.cpp
** File description:
** Node_popChildren.cpp
*/

#include "myxmlpp/Node.hpp"
#include "myxmlpp/exceptions/NodeNotFoundException.hpp"

std::vector<std::vector<std::shared_ptr<myxmlpp::Node>>::iterator>
myxmlpp::Node::_findChildrenIt(const std::string &tag)
{
    std::vector<std::vector<std::shared_ptr<Node>>::iterator> list;

    for (auto it = _children.begin(); it != _children.end(); ++it) {
        if ((*it)->getTag() == tag)
            list.push_back(it);
    }
    return list;
}

std::vector<std::shared_ptr<myxmlpp::Node>>
myxmlpp::Node::popChildren(const std::string& tag) noexcept
{
    std::vector<std::shared_ptr<Node>> toPopNodes;

    try {
        auto toPop = _findChildIt(tag);
        while (toPop != _children.end()) {
            toPopNodes.push_back(*toPop);
            _children.erase(toPop);
            toPop = _findChildIt(tag);
        }
    } catch (NodeNotFoundException& e) {}
    return toPopNodes;
}