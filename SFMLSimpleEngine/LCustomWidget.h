#pragma once

#include <SFMLSimpleEngine/LAbstractWidget.h>
 
// Custom widget that can be of any shape. The shape can be set by Vertex Array
class LCustomWidget : public LAbstractWidget
{

private:

	// Vertices which describe and draw widget.
	// First Vertex in Array is main. 
	// All coordinates of widget are calculated relative to main Vertex.
	sf::VertexArray* m_vertices;

public:

	// Constructor that you can use if your widget is child. 
	// Initialize pointer to parent widget. Copies pointer to sf::RenderWindow from parent
	LCustomWidget(LAbstractWidget* parent);

	// Constructor that you can use if your widget has no parent widget.
	// Initialize pointer to parent widget by nullptr, adds widget to widgets vector in LGameRender
	LCustomWidget(LGameRender* render = nullptr);

	// Constructor that you can use if your widget is child.
	// Initialize Vertex Array by pointer to Array which already exists
	LCustomWidget(sf::VertexArray* vertices, LAbstractWidget* parent);

	// Constructor that you can use if your widget has no parent widget.
	// Initialize Vertex Array by pointer to Array which already exists
	LCustomWidget(sf::VertexArray* vertices, LGameRender* render = nullptr);

	// Destructor which release all occipied memory
	~LCustomWidget();


	////////////////////////////////////////////////
	//               METHODS
	///////////////////////////////////////////////


	// Appends Vertex to Vertex Array
	void appendVertex(const sf::Vertex& vertex);

	// Creates Vertex with X, Y coordinates, color "color" and appends it to Vertex Array
	// Default color is sf::Color::White
	void appendVertex(float X, float Y, const sf::Color& color = sf::Color::White);

	// Returns true if widget contains point. Else returns false
	bool contains(const sf::Vector2f& point) const override;

	// Draws Vertex Array in target window with states of rendering
	// Calls OnPaint() event.
	void draw(sf::RenderTarget& target, sf::RenderStates states) const override final;

	// Moves widget relative to current position.
	// NOTICE: LCustomWidget::move() don't set new position! Use LCustomWidget::setPosition() to do that.
	void move(float X, float Y);

	// Sets new position of widget. Coordinates of Vertices are relative to the main Vertex.
	// Returns false if new position is equal to current one. Else returns true
	bool setPosition(float X, float Y);

	// Sets primitive type to Vertex Array
	void setPrimitive(const sf::PrimitiveType& ptype);

};