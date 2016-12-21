class Rectangle :public Shape // is-a Shape
{
public:
	Rectangle(char* name, Pair topLeft, Pair bottomRight) :Shape(name, topLeft, bottomRight){};
	~Rectangle(){}
	Pair CalculateCentre();
	void Report();
};
