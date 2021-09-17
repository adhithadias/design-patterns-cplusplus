

# Motivation

* Ordinary C++ statements are perishable
    * Cannot undo a field/property assignment
    * Cannot directly serialize a sequence of actions (calls)

* Want an object that represents an operation
    * X should change its field Y to the value Z
    * X should do W()

* User: GUI commands, multi-level ndo/redo, macro recording and more!

# Command

An object which represents an instruction to perform a particular action. Contains all the necessary information for the action to be taken.

# Command Quary Separation

* Command = asking for an action or change (e.g., please set your attack value to 2) -- you don't get any result, cause a change in the system
* Query = asking for information (e.g., please give me your attack) - does not change anything in the system
* CQS = having separate means of sending commands and queries.

Gang of does not mention queries. They just give the command design pattern.

* In GoF context, both commands and queries are represented with the Command design pattern.

# Summary

