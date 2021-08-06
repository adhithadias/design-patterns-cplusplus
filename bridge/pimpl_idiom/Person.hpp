#pragma once

#include <string>

/**
the idea of the pimpl idiom is that the implementation detail which could
be inside the Person class itself -- they are actually differed, relayed or bridged
into a seperate class, what ends up happening is you end up declaring an inner class
inside Person and then you define a pointer to the new inner class
**/

/**
 * One advantage is that you are hiding the implementation details
 You are not exposing the inner mechanisms of the class to whoever is using your library
 Remember, you are actually
 * 
 */
class Person {
public:
    std::string name;

    class PersonImpl;
    PersonImpl* impl;

    Person();
    ~Person();

    void greet();
};