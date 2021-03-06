/******************************************************************************************************************************
FILE:				 Rectangle.cpp
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
Purpose:			Using Ellipse.cpp returnes the shapes center and reports the name for a ellipse
*******************************************************************************************************************************/

#include <iostream>
using namespace std;
#include "Pair.h"
#include "Shape.h"
#include "Ellipse.h"

/******************************************************************************************************************************
Function Name: 	CalculateCentre
Purpose:		Simple function that returns a pair shape
In parameters:
Out parameters:
Version: 		3.0
Student Name:	Warsame Egal
*******************************************************************************************************************************/
Pair Ellipse::CalculateCentre(){
	return p1; //return p1
}

/******************************************************************************************************************************
Function Name: 	Report
Purpose:		Small function that prints the name and calls report function
In parameters:
Out parameters: void
Version: 		3.0
Student Name:	Warsame Egal
*******************************************************************************************************************************/
void Ellipse::Report(){

	cout << endl << "Shape ELLIPSE " << name;
	cout << endl << "centre coordinates : ";
	p1.Report();
	cout << endl << "axes dimensions : ";
	p2.Report();

}