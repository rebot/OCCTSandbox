#include <iostream>
#include <hello.h>

// OCCT library
// - Basic data structures (geometry)
// - Modeling algorithms
// - Working with mesh (faceted) data
// - Data interoperability

// Grouped in packages > toolkits (libraries; .so or .dll) > modules

// Data types:
// 1. Primitive types (Boolean, Character, Integer, Real,..) --> Manipulated by value
// 2. OCCT classes --> Manupulated by handle (= on reference to an instance)
// Handle = safe way to manipulate object

#include <Standard_Integer.hxx> // Primitive type of the Standard package
#include <Standard_Transient.hxx> // Primitive type of the Standard package

// Retrieve type descriptor -> STANDARD_TYPE(Geom_Line) for example
#include <Geom_Point.hxx> // Type manipulated by handle - Abstract class
#include <Geom_CartesianPoint.hxx>  // Concrete class

// Include goodbye if set
#ifdef USE_GOODBYE
#  include "goodbye.h"
#endif

int main()
{
  std::cout << "Hello world - by " << AUTHOR << std::endl;
  #ifdef USE_GOODBYE
    Handle(Geom_CartesianPoint) aPnt1 = new Geom_CartesianPoint(1, 0, 0);

    if (aPnt1->IsKind(STANDARD_TYPE(Geom_Point)))
    {
      std::cout << "It's a point" << std::endl;
    }
  #endif
  return 0;
}
