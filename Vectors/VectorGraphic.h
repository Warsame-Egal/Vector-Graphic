class VectorGraphic : public vector<GraphicElement> // is-a vector
{
public:
	VectorGraphic();
	~VectorGraphic();
	void AddGraphicElement();
	void DeleteGraphicElement();
	friend ostream& operator<<(ostream&, VectorGraphic&);
};
