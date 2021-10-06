We are going to evaluate a tree of expressions

This method is intrusive because you go to your original classes and stuff to it.
For example, in the given code we add print statements to all the Expression classes
in the class hierarchy.

If you had 20 classes in 20 different files, it would be a bit difficult to go to 
20 different files and edit them. We can just organize all the prints in one file
using a different visitor pattern.
