#include "di.hpp"
#include "headers.hpp"
using namespace std;
using namespace boost;

struct IFoo {
  virtual string name() = 0;
};

struct Foo : IFoo {
  static int id;
  Foo() { ++id; }

  string name() override {
    return "foo "s + lexical_cast<string>(id);
  }
};

int Foo::id = 0;

// Bar needs a singleton instance of Foo
struct Bar {
  std::shared_ptr<IFoo> foo;
};

int main() {
  auto injector = di::make_injector(
    // bar has a dependence on IFoo - so we need to provide IFoo to bind
    // and convert it to Foo - since we want an instance of Foo
    // However this will create a new instance of Foo but we want it to be Singleton
    // Now Foo is a Singleton when it is actually injected
    di::bind<IFoo>().to<Foo>().in(di::singleton)
  );

  auto bar1 = injector.create<std::shared_ptr<Bar>>();
  auto bar2 = injector.create<std::shared_ptr<Bar>>();

  // Now if only one instance of Foo was created the static id of Foo should be 1
  // Not 2 because the constructor has only been called once
  cout << bar1->foo->name() << endl;
  cout << bar2->foo->name() << endl;

  cout << boolalpha << (bar1->foo.get() == bar2->foo.get()) << endl;
}

