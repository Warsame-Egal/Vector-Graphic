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
Purpose:			Using Rectangle.cpp calculates the shapes centers and reports the name for a rectangle 
*******************************************************************************************************************************/

#include <iostream>
using namespace std;
#include "Pair.h"
#include "Shape.h"
#include "Rectangle.h"

/******************************************************************************************************************************
Function Name: 	CalculateCentre
Purpose:		Simple function that returns a the adition of two shaoes and divides the total
In parameters:
Out parameters:
Version: 		3.0
Student Name:	Warsame Egal
*******************************************************************************************************************************/
Pair Rectangle::CalculateCentre(){

	return (p1 + p2) / 2; //calculation
}

/******************************************************************************************************************************
Function Name: 	Report
Purpose:		Small function that prints the name and calls report function
In parameters:
Out parameters: void
Version: 		3.0
Student Name:	Warsame Egal
*******************************************************************************************************************************/
void  Rectangle::Report(){

	cout << endl << "Shape RECTANGLE " << name;
	cout << endl << "top left coordinates ";
	p1.Report();
	cout << endl << "bottom right coordinates : ";
	p2.Report();

}