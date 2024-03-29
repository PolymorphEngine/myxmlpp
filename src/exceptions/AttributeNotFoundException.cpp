/*
** EPITECH PROJECT, 2021
** AttributeNotFoundException.cpp.cc
** File description:
** AttributeNotFoundException.cpp.cc
*/


#include "myxmlpp/exceptions/AttributeNotFoundException.hpp"

#include <utility>

myxmlpp::AttributeNotFoundException::AttributeNotFoundException(
        std::string  key,
        const std::string& file,
        int line,
        const std::string& description) noexcept
    : _key(std::move(key)), Exception(file, line, description)
{
    build();
}

std::string myxmlpp::AttributeNotFoundException::baseWhat() const noexcept {
    return Exception::baseWhat()
           + std::string(" : cannot find attribute ")
           + _key;
}

std::string myxmlpp::AttributeNotFoundException::getKey() const {
    return _key;
}