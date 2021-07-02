#pragma once

#include <SFMLSimpleEngine/LAbstractWidget.h>

// Default widget that is rectangle
class LWidget : public LAbstractWidget
{

protected:

	// Pointer to shape which describes the object. Will be drawn in target window
	sf::RectangleShape* m_shape;

public:

	// Default constructor. Create empty shape and initialize the pointer
	LWidget();

	// Create new shape with W, H size and initialize the pointer
	LWidget(float W, float H);

	// Initialize pointer to shape by another pointer to shape which already exists
	LWidget(sf::RectangleShape* shape);

	// Destructor which release all occipied memory
	~LWidget();


	////////////////////////////////////////////////
	//               METHODS
	///////////////////////////////////////////////


	// Returns true if widget contains point. Else returns false
	bool contains(const sf::Vector2f& point) const override;

	// Draws object shape in target window with states of rendering
	void draw(sf::RenderTarget& target, sf::RenderStates states) const override;

	// Moves widget relative to current position.
	// NOTICE: LWidget::move() don't set new position! Use LWidget::setPosition() to do that.
	void move(float X, float Y);

	// Creates borders of widget with color and thickness.
	// Set thickness to 0 if you want remove all borders
	void setBorders(float thickness = 1, const sf::Color& color = sf::Color::White);

	// Sets the color of which the widget will filled
	void setColor(const sf::Color& color);

	// Sets new position of widget.
	// Returns false if new position is equal to current one. Else returns true
	bool setPosition(float X, float Y);


	////////////////////////////////////////////////
	//               EVENTS
	///////////////////////////////////////////////


	// Calls after widget and it's childs painted
	// NOTICE: It is CONST method cause SFML library created sf::Drawable::draw() as const method!
	virtual void onPaint(sf::RenderTarget& target, sf::RenderStates states) const;

};

