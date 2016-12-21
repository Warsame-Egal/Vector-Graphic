class Line :public Shape  // is-a Shape
{
public:
	Line(char* name, Pair start, Pair end) :Shape(name, start, end){};
	~Line(){}
	Pair CalculateCentre();
	void Report();
};

