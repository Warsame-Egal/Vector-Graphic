class GraphicElement : public vector<Shape*> // is-a vector
{
	static const int SIZE = 256;
	char name[SIZE];
public:
	GraphicElement(Shape**, char*, unsigned int);
	GraphicElement(const GraphicElement&);
	GraphicElement& operator=(GraphicElement&);
	~GraphicElement();
	friend ostream& operator<<(ostream&, GraphicElement&);
};

