#include <string>
#include <iostream>

/*
** EPITECH PROJECT, 2020
** test.cpp
** File description:
** test.cpp
*/

#include "myxmlpp/Node.hpp"
#include "myxmlpp/Doc.hpp"
#include "myxmlpp/exceptions/Exception.hpp"

/*
class SuperClass
{
    public:

        explicit SuperClass(int foo)
        {
            std::cout << "foo" << std::endl;
        }
};

class SubClass : public SuperClass
{
    private:
        int property;

        [
        {
            name: "property";
            fct: setProperty
        }
        ]
    public:

        SubClass(int foo, int bar)
                : SuperClass(foo)    // Call the superclass constructor in the subclass' initialization list.
        {
            std::cout << "bar" << std::endl;
        }
};
 */

std::string cut(std::string& s) {
    std::cout << s[1] << std::endl;
    return s.erase(0, 4);
}

int main(int argc, char **argv) {
    return 0;
}