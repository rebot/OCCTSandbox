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

#include <Standard_Boolean.hxx>
#include <Standard_Integer.hxx> // Primitive type of the Standard package
#include <Standard_Transient.hxx> // Primitive type of the Standard package

// Retrieve type descriptor -> STANDARD_TYPE(Geom_Line) for example
#include <gp_Pnt.hxx> // Point - short lived
#include <Geom_Point.hxx> // Type manipulated by handle - Abstract class
#include <Geom_CartesianPoint.hxx>  // Concrete class

// OCCT BrepPrimAPI
#include <BRepPrimAPI_MakeBox.hxx> // Make a Box
#include <BRepPrimAPI_MakeCylinder.hxx> // Make a Cylinder
#include <BRepMesh_IncrementalMesh.hxx> // Make a mesh from a topological data structure

// OCCT Boolean operation / Algoritms
#include <BRepAlgoAPI_Cut.hxx>

// Writa a STL file
#include <StlAPI_Writer.hxx>

// Write a STEPfile
#include <STEPControl_Writer.hxx>

// Include GProp package - calculate global properties
#include <GProp_GProps.hxx>
#include <BRepGProp.hxx>

// Include goodbye if set
#ifdef USE_GOODBYE
#  include "goodbye.h"
#endif

int main(int argc, char *argv[])
{
  std::cout << "Hello world - by " << AUTHOR << std::endl;
  #ifdef USE_GOODBYE
    Handle(Geom_CartesianPoint) aPnt1 = new Geom_CartesianPoint(1, 0, 0);

    if (aPnt1->IsKind(STANDARD_TYPE(Geom_Point)))
    {
      std::cout << "It's a point" << std::endl;
    }
  #endif

  // Create a simple box
  gp_Pnt lowerLeftCornerOfBox(-50.0, -50.0, 0.0);
  BRepPrimAPI_MakeBox boxMaker(lowerLeftCornerOfBox, 100, 100, 100);
  TopoDS_Shape box = boxMaker.Shape();

  // Create a cylinder
  BRepPrimAPI_MakeCylinder cylinderMaker(25.0, 50.0);
  TopoDS_Shape cylinder = cylinderMaker.Shape();

  // Cut the cylinder out of the box
  BRepAlgoAPI_Cut cutMaker(box, cylinder);
  TopoDS_Shape boxWithHole = cutMaker.Shape();

  // Write a STEP file
  STEPControl_Writer writer;
  writer.Transfer(boxWithHole, STEPControl_AsIs);
  writer.Write("boxWithHole.stp");

  // Write a STL file
  BRepMesh_IncrementalMesh BMesh(boxWithHole, 5, Standard_True);
  TopoDS_Shape boxForExport = BMesh.Shape();

  StlAPI_Writer STLwriter;
  STLwriter.Write(boxForExport, "boxWithHole.stl");

  // Calculate the volume
  GProp_GProps volumeProperties;
  BRepGProp::VolumeProperties(boxWithHole, volumeProperties);
  std::cout << std::setprecision(5) << "Volume of the model is: " << volumeProperties.Mass() << std::endl;

  BRepGProp::VolumeProperties(box, volumeProperties);
  std::cout << std::setprecision(5) << "Volume of the original model is: " << volumeProperties.Mass() << std::endl;

  return 0;
}
