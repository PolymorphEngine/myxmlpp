/*
** EPITECH PROJECT, 2022
** Node_parseUtils.cpp
** File description:
** Node_parseUtils.cpp
*/

#include <memory>
#include <regex>
#include "myxmlpp/Node.hpp"
#include "myxmlpp/exceptions/ParsingException.hpp"

bool myxmlpp::Node::_isEndOfNode(std::string &str)
{
    std::string rgx("[\r\n\t\f\v ]*(?:(?:<[a-zA-Z0-9_\\-]*"
                    "(?:[\r\n\t\f\v ].*\"[\r\n\t\f\v ]*?)* ?/?>)|(?:<(/).*>))");
    std::smatch matches;

    if (!_performRegex(matches, rgx, str, nullptr))
        throw ParsingException(str, MYXMLPP_ERROR_LOCATION, "no tag end found");
    else if (matches[1].str().empty())
        return false;
    else
        return true;
}

void myxmlpp::Node::_checkEndOfNode(std::string &str,
                                    std::string &remaining)
{
    std::string rgx("[\r\n\t\f\v ]*</([^>]*)>");
    std::smatch matches;

    if (!_performRegex(matches, rgx, str, &remaining))
        throw ParsingException(str, MYXMLPP_ERROR_LOCATION, "no tag end found");
    else if (matches[1].str() != _tag)
        throw ParsingException(str, MYXMLPP_ERROR_LOCATION, "tag end doesn't match tag start");
    else
        str = matches.suffix().str();
}

bool myxmlpp::Node::_performRegex(std::smatch &matches, std::string &regexStr,
                                  std::string &str, std::string *remaining)
{
    std::regex rgx(regexStr);
    std::smatch remainingMatches;
    bool res = std::regex_search(str, matches, rgx, std::regex_constants::match_continuous);

    if (remaining) {
        if (!std::regex_search(*remaining, remainingMatches, rgx, std::regex_constants::match_continuous))
            throw myxmlpp::ParsingException(*remaining, MYXMLPP_ERROR_LOCATION,
                                            "Malformed file");
        remaining->replace(remainingMatches.position(),
                           remainingMatches.length(),
                           "");
    }
    return res;
}

void myxmlpp::Node::_parseNodeString(std::string &str, std::string &remaining)
{
    std::string rgx("[\r\n\t\f\v ]*(<([a-zA-Z0-9_\\-]*)"
                    "((?:[\r\n\t\f\v ](?:[^=\r\n\t\f\v ]+)=\"(?:[^\"]*)\"[\r\n\t\f\v ]*?)*)"
                    "[\\r\\n\\t\\f\\v ]*(/?)>)");
    std::smatch matches;

    if (!_performRegex(matches, rgx, str, &remaining))
        throw myxmlpp::ParsingException(remaining, MYXMLPP_ERROR_LOCATION, "No tag found");
    _tag = matches[2].str();
    if (!matches[3].str().empty()) {
        std::string attributes = matches[3].str();
        _extractAttributes(attributes);
    }
    if (!matches[4].length()) {
        str = matches.suffix().str();
        while (!_isEndOfNode(str)) {
            addChild(std::shared_ptr<Node>(new Node(this, str, remaining)));
        }
        _checkEndOfNode(str, remaining);
    } else
        str = matches.suffix().str();
}

void myxmlpp::Node::_extractAttributes(std::string &str) noexcept
{
    std::regex rgx("[\r\n\t\f\v ]*([a-zA-Z0-9_]+)=\"([^\"]*)\"");
    std::smatch matches;

    while (std::regex_search(str, matches, rgx, std::regex_constants::match_continuous)) {
        _attributes.push_back(
                std::make_unique<Attribute>(matches[1], matches[2])
        );
        str = matches.suffix().str();
    }
}