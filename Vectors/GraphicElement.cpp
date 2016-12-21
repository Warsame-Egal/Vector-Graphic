/******************************************************************************************************************************
FILE:				 GraphicElement.cpp
Version:			 3.0
Author/Student Name: Warsame Egal
Student Number		 040-693-092
Course Name and Number: C++ Programming CST8219
Lab Section:		300
Assignment Number:	Assignment 3
Assignment Name:	Vector Graphic with Polymorphic Inheritance and Templates
Due Date:			December 03, 2016
Submission Date:	December 04, 2016
Professor's Name:	Andrew Tyler
Purpose:			Using GraphicElement.cpp processes the GraphicElement object with several functions
*******************************************************************************************************************************/

#include <iostream>
using namespace std;
#include <vector>
#include "Pair.h"
#include "Shape.h"
#include "Line.h"
#include "Rectangle.h"
#include "Ellipse.h"
#include "GraphicElement.h"

/******************************************************************************************************************************
Function Name: 	GraphicElement
Purpose:		Overloaded constructor for GraphicElement object
In parameters:	Shape**, char*, unsigned int
Out parameters:
Version: 		3.0
Student Name:	Warsame Egal
*******************************************************************************************************************************/
GraphicElement::GraphicElement(Shape** thisShapes, char* names, unsigned int value){
	unsigned int i = 0;
	while (i < value) {
		if (dynamic_cast<Line*>(thisShapes[i]) != NULL){ //if the line is not null
			push_back(new Line(*dynamic_cast<Line*>(thisShapes[i]))); //call pushback with the appropriate line type 
		}

		else if (dynamic_cast<Rectangle*>(thisShapes[i]) != NULL){ //if the rectangle is not null
			push_back(new Rectangle(*dynamic_cast<Rectangle*>(thisShapes[i]))); //call pushback with the appropriate rectangle type 
		}

		else if (dynamic_cast<Ellipse*>(thisShapes[i]) != NULL){ //if the ellipse is not null
			push_back(new Ellipse(*dynamic_cast<Ellipse*>(thisShapes[i]))); //call pushback with the appropriate ellipse type 
		}
		i++;
	}

	strcpy_s(name, names); //copy 

}


/******************************************************************************************************************************
Function Name: 	GraphicElement
Purpose:		Copy constructor for GraphicElement objects
In parameters:	const GraphicElement&
Out parameters:
Version: 		3.0
Student Name:	Warsame Egal
*******************************************************************************************************************************/
GraphicElement::GraphicElement(const GraphicElement& graphicElements){

	vector<int>::size_type i = 0;
	while (i < graphicElements.size()) {
		if (dynamic_cast<Line*>(graphicElements[i]) != NULL){ //null check
			push_back(new Line(*dynamic_cast<Line*>(graphicElements[i]))); //call pushback with the appropriate graphicElement type
		}
		else if (dynamic_cast<Rectangle*>(graphicElements[i]) != NULL){ //null check
			push_back(new Rectangle(*dynamic_cast<Rectangle*>(graphicElements[i])));  //call pushback with the appropriate graphicElement type
		}
		else if (dynamic_cast<Ellipse*>(graphicElements[i]) != NULL){ //null check
			push_back(new Ellipse(*dynamic_cast<Ellipse*>(graphicElements[i]))); //call pushback with the appropriate graphicElement type
		}
		i++;
	}
	strcpy_s(name, graphicElements.name);

}


/******************************************************************************************************************************
Function Name: 	GraphicElement
Purpose:		Equals operator
In parameters:	GraphicElement&
Out parameters:
Version: 		3.0
Student Name:	Warsame Egal
*******************************************************************************************************************************/
GraphicElement& GraphicElement::operator=(GraphicElement& graphicElements){
	GraphicElement::iterator value = begin();
	vector<int>::size_type i = 0;

	while (value != end()) {
		delete *value; //delete what value points to
		value++;
	}
	while (i < graphicElements.size()) {
		if (dynamic_cast<Line*>(graphicElements[i]) != NULL){ //check fo null
			push_back(new Line(*dynamic_cast<Line*>(graphicElements[i]))); //call pushback with the appropriate type
		}
		else if (dynamic_cast<Rectangle*>(graphicElements[i]) != NULL){ //check fo null
			push_back(new Rectangle(*dynamic_cast<Rectangle*>(graphicElements[i]))); //call pushback with the appropriate type
		}
		else if (dynamic_cast<Ellipse*>(graphicElements[i]) != NULL){ //check fo null
			push_back(new Ellipse(*dynamic_cast<Ellipse*>(graphicElements[i]))); //call pushback with the appropriate type
		}
		i++;
	}

	strcpy_s(name, graphicElements.name);

	return *this;
}


/******************************************************************************************************************************
Function Name: 	GraphicElement
Purpose:		Destructor
In parameters:
Out parameters:
Version: 		3.0
Student Name:	Warsame Egal
*******************************************************************************************************************************/
GraphicElement::~GraphicElement(){
	GraphicElement::iterator value = begin();

	while (value != end()) {
		delete *value; //delete what value points to
		value++;
	}

	clear();
}

/******************************************************************************************************************************
Function Name: 	GraphicElement
Purpose:		prints the ostream for shapes
In parameters: ostream&, GraphicElement&
Out parameters:
Version: 		3.0
Student Name:	Warsame Egal
*******************************************************************************************************************************/
ostream& operator<<(ostream& os, GraphicElement& graphicElements){

	Pair pair;
	typedef GraphicElement::iterator iterators;

	for (iterators i = graphicElements.begin(); i != graphicElements.end(); i++){
		pair = pair + (*i)->CalculateCentre(); //Add the pair with the current alculated center of shapes
	}

	os << endl << "Graphic Element " << graphicElements.name;
	os << endl << "The center is: ";

	pair = pair / graphicElements.size(); //divide pair by the elements size
	pair.Report();

	os << endl << "List of shapes in " << graphicElements.name;

	for (iterators i = graphicElements.begin(); i != graphicElements.end(); i++){ //loop and print using report
		(*i)->Report();
	}

	return os; //return ostream
}
