Prototype design pattern is all about object copying

#Motivation

* Complicated objects (e.g. cars) aren't designed from scratch
    * They reiterate existing designs
* An existing (partially or fully constructed) design is a Prototype
* We make a copy (clone) the prototype and customize it
    * Requires 'deep copy' support
* We make the cloning convenient (e.g. via a Factory)

# Prototype

A partially or fully initialized object that you copy (clone) and make use of it. You make a copy and then you subsequently use if for your own benifit.


