class Ellipse :public Shape  // is-a Shape
{
public:
	Ellipse::Ellipse(char* name, Pair centre, Pair axes) :Shape(name, centre, axes){}
	~Ellipse(){}
	Pair CalculateCentre();
	void Report();
};
