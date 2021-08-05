# Singleton

A design pattern everyone loves to hate. It is as bad as people say it is?

When discussing which patterns to drop, we found that we still love them all. (Not really -- I'm in favor of dropping Singleton. Its use is almost always a design smell.)
- Erich Gamma (One of the original authors of the design pattern book)

- because raw use of a Singleton is a design smell. Particularly theoretically should be able to test and extendable.

## Motivation

* For some components it only makes sense to have one in the system
    * Database repository
    * Object factory
* E.g. the constructor call is expensive
    * We only do it once
    * We provide everyone with the same instance
* Want to prevent anyone creating additional copies
* Need to take care of lazy instantiation and thread safety

Singleton is just a component which is instantiated only once.

# Summary

* Making a 'safe' singleton is easy
    - Hide or delete the type's constructor, copy constructor and copy assignment operators
    - Create a static method that returns a reference to a static member
    - Guaranteed to be thread-safe dince C++11
* Types with 'hard' depedencies on singletons are difficult to test
    - Cannot decouple the singleton and supply fake object
* Instread of directly using a singleton, consider depending on an abstraction (e.g. an interface)
* Consider defining a singleton lifetime in DI container




