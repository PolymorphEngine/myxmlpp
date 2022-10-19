/*
** EPITECH PROJECT, 2021
** PermissionDeniedException.cpp.cc
** File description:
** PermissionDeniedException.cpp.cc
*/


#include "myxmlpp/exceptions/PermissionDeniedException.hpp"

std::string myxmlpp::PermissionDeniedException::baseWhat() const noexcept {
    return FileException::baseWhat()
        + std::string(" : permission denied at the given filepath");
}

myxmlpp::PermissionDeniedException::PermissionDeniedException(
        const std::string &filepath, const std::string &file, int line)
        : FileException(filepath, file, line) {
    build();
}
