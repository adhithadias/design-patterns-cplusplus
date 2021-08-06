#pragma once

#include "pimpl.h"

class Foo
{
  class FooImpl;
  pimpl<FooImpl> impl;
  std::string name;

public:
  Foo(std::string name);

  void greet();
};


