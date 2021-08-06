#include "Foo.h"
#include <iostream>

class Foo::FooImpl
{
public:
    void greet(Foo *foo);
};

void Foo::FooImpl::greet(Foo *foo) {
    std::cout << "Hello Adhitha\n";
}

Foo::Foo(std::string name) : name{name}, impl{} 
{}


void Foo::greet() {
    impl->greet(this);
}