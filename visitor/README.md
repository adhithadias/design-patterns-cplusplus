# Visitor Pattern

There are sevaral visitor patters that is used.
1. Intrusive Visitor
2. Reflective Visitor
3. Classic Visitor (Double Dispatch)
4. Acyclic Visitor
5. Multimethods
6. Variant and std::visitor

Typically a tool for structure traversal rather than anything else

## Motivation

* Need to define a new operation on an entire class hierarchy
  * eg: make a document model printable to HTML/Markdown
* Do not want to keep modifying every class in the hierarchy - single responsibility principle
* Need access to the non-common aspects of classes in the hierarchy
  * Cannot put everything into a single interface
* Create an external component to handle rendering
  * But preferably avoiid type checks - for scalability (reflecitive approach)

Visitor - A pattern where a component (visitor) is allowed to traverse the entire inheritance hierarchy. 
Implemented by propagating a single visit() method throughout the entire hierarchy.