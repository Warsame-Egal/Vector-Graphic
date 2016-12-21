/******************************************************************************************************************************
FILE:				 VectorGraphic.cpp
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
Purpose:			Using GraphicElement.cpp contains main functionality for this assignment
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
#include "VectorGraphic.h"

/******************************************************************************************************************************
Function Name: 	VectorGraphic
Purpose:		default constructor
In parameters:
Out parameters:
Version: 		3.0
Student Name:	Warsame Egal
*******************************************************************************************************************************/
VectorGraphic::VectorGraphic() {
}

/******************************************************************************************************************************
Function Name: 	~VectorGraphic
Purpose:		destructor
In parameters:	Shape**, char*, unsigned int
Out parameters:
Version: 		3.0
Student Name:	Warsame Egal
*******************************************************************************************************************************/
VectorGraphic::~VectorGraphic(){
	vector<GraphicElement> element; //allocate memory for a graphic eement
	swap(element); //call swap function  for the graphic element
}


/******************************************************************************************************************************
Function Name: 	AddGraphicElement
Purpose:		Adds a new graphicElement upon user execution
In parameters:
Out parameters: void
Version: 		3.0
Student Name:	Warsame Egal
*******************************************************************************************************************************/
void VectorGraphic::AddGraphicElement(){
	double x1, y1, x2, y2; //start and end x and y
	int numberOfShapes, i = 0, x = 0; // shape count and loop counter
	char name[256], shapeName[256], type; //the name and shapes name and shapes type

	cout << "Adding a Graphic Element" << endl;
	cout << "Please enter the name of the new Graphic Element(<256 characters) : ";
	fflush(stdin);
	cin.getline(name, 255);

	cout << "Please enter the number of Shapes it contains : ";
	cin >> numberOfShapes;

	Shape** pShapes = new Shape *[numberOfShapes]; //array to collect all shapes

	while (i < numberOfShapes) { //main loop for add
		cout << "Please enter the type(L for line, R for rectangle, E for ellipse) for Shape #" << i << ": " << endl;
		cin >> type;
		switch (type) {

		case 'L':
		{
					cout << "Please enter the name of the new Line(<256 characters) : ";
					fflush(stdin);
					cin.getline(shapeName, 255);
					cout << "please enter the coordinates of the start point : (x, y)";
					cin >> x1;
					cin >> y1;
					cout << "please enter the coordinates of the end point : (x, y)";
					cin >> x2;
					cin >> y2;
					Pair start(x1, y1); //pass start x and y
					Pair end(x2, y2); //pass end x and y
					pShapes[i] = new Line(shapeName, start, end); //allocate memory for new line
		}
			break;

		case 'R':
		{
					cout << "Please enter the name of the new Rectangle(<256 characters) : ";
					fflush(stdin); //flush or the input messes up
					cin.getline(shapeName, 255); //256-1 for the terminator character
					cout << " please enter the coordinates of the top - left: (x, y) ";
					cin >> x1;
					cin >> y1;
					cout << "please enter the coordinates of the bottom - right : (x, y) ";
					cin >> x2;
					cin >> y2;
					Pair start(x1, y1); //pass start x and y
					Pair end(x2, y2); //pass end x and y
					pShapes[i] = new Rectangle(shapeName, start, end); //allocate memory for new line
		}
			break;

		case 'E':
		{
					cout << "Please enter the name of the new Ellipse(<256 characters) : ";
					fflush(stdin); //flush or the input messes up
					cin.getline(shapeName, 255); //256-1 for the terminator character
					cout << " please enter the coordinates of the centre: (x,y)  ";
					cin >> x1;
					cin >> y1;
					cout << "please enter the width and height: (width, height) ";
					cin >> y2;
					cin >> y2;
					Pair start(x1, y1);  //pass start x and y
					Pair end(x2, y2);//pass end x and y
					pShapes[i] = new Ellipse(shapeName, start, end); //allocate memory for new line
		}
			break;
		}

		i++; //counter
	}
	push_back(GraphicElement(pShapes, name, numberOfShapes)); //call pushback function and pass the shapes, name and number of shapes that we obtained from user input
	cout << "";
	while (x < numberOfShapes) { //delete local shapes
		delete[] pShapes[x];
		x++;
	}
	delete[] pShapes;
}

/******************************************************************************************************************************
Function Name: 	DeleteGraphicElement
Purpose:		Deletes a GraphicElement
In parameters:
Out parameters: void
Version: 		3.0
Student Name:	Warsame Egal
*******************************************************************************************************************************/
void VectorGraphic::DeleteGraphicElement(){
	vector<GraphicElement> temp; // temo graphic element
	VectorGraphic::iterator i = begin();
	int num;
	int x = 0; //x the elements

	cout << endl << "Please enter index of element you want to delete: ";
	cin >> num;

	while (i != end()) {
		if (x == num){ //if x is equal to the user input
			x++; //increment x
		}
		else if (x != num) { //otherwise not equal 
			temp.push_back(*i); // call push_back and pass to temp
			x++;
		}
		i++;
	}

	clear(); //finally clear before calling swap
	swap(temp); //swaps two elements
}

/******************************************************************************************************************************
Function Name: 	operator<<
Purpose:		outputs VectorGraphic
In parameters:  ostream&, VectorGraphic&
Out parameters: ostream&
Version: 		3.0
Student Name:	Warsame Egal
*******************************************************************************************************************************/
ostream& operator<<(ostream& os, VectorGraphic& vG){
	int i = 0;
	VectorGraphic::iterator temp = vG.begin();
	os << endl << "VectorGraphic Report";
	os << endl;

	while (temp != vG.end()) { //loop
		os << endl << "Reporting Graphic Element: " << i;
		os << *temp << endl; //print the vectorgraphic
		i++;
		temp++;
	}

	return os;
}