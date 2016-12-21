/******************************************************************************************************************************
FILE:				 Pair.cpp
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
Purpose:			Using pair.h this class contains a addition and division operators aswel as a report function that adds and
divies the x and y values and also prints them using report
*******************************************************************************************************************************/

#include "Pair.h"
#include <iostream>
using namespace std;

/******************************************************************************************************************************
Function Name: 	operator+
Purpose:		Addition operator adds this x,y to Pair value of x and y
In parameters:
Out parameters:
Version: 		3.0
Student Name:	Warsame Egal
*******************************************************************************************************************************/
Pair Pair::operator+(Pair& p){
	Pair value; //result 

	value.x = x + p.x; // add x at p(x)
	value.y = y + p.y; // add y at p(y)

	return value;
}

/******************************************************************************************************************************
Function Name: 	operator/
Purpose:		Division operator divies this x to a double parameter
In parameters:
Out parameters:
Version: 		3.0
Student Name:	Warsame Egal
*******************************************************************************************************************************/
Pair Pair::operator/(double dub){
	Pair value; //holds the result of the division


	value.x = x / dub; //divide x and store into this x
	value.y = y / dub; //divide y and store into this y

	return value;

}

/******************************************************************************************************************************
Function Name: 	Report
Purpose:		This is the simplest function that finally outputs the x and y values
In parameters:
Out parameters: void
Version: 		3.0
Student Name:	Warsame Egal
*******************************************************************************************************************************/
void Pair::Report(){
	cout << "x = " << x << "; ";
	cout << "y = " << y;
}