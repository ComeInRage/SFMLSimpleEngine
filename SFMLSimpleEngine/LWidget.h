#pragma once

#include <SFMLSimpleEngine/LAbstractWidget.h>

// Default widget that is rectangle
class LWidget : public LAbstractWidget
{

private:

	// Shape which describes the object. Will be drawn in target window
	sf::RectangleShape m_shape;

	// Padding width
	float m_padding = 0.f;

public:

	// Default constructor. Creates empty shape. Initialize pointer to parent LAbstractWidget object
	LWidget(LAbstractWidget* parent);

	// Default constructor. Creates empty shape. Initialize pointer to parent LGameRender object
	LWidget(LGameRender* render = nullptr);

	// Creates new shape with W, H size.
	// Initialize parent pointer. Use if parent of your widget is LAbstractWidget
	LWidget(float W, float H, LAbstractWidget* parent);

	// Creates new shape with W, H size.
	// Initialize parent pointer. Use if parent of your widget is LGameRender
	LWidget(float W, float H, LGameRender* render = nullptr);

	// Initialize shape by const reference to another shape which already exists.
	// Initialize parent pointer. Use if parent of your widget is LAbstractWidget
	LWidget(const sf::RectangleShape& shape, LAbstractWidget* parent);

	// Initialize shape by const reference to another shape which already exists.
	// Initialize parent pointer. Use if parent of your widget is LGameRender
	LWidget(const sf::RectangleShape& shape, LGameRender* render = nullptr);


	////////////////////////////////////////////////
	//               METHODS
	///////////////////////////////////////////////


	// Returns true if widget contains point. Else returns false
	bool contains(const sf::Vector2f& point) const override;

	// Draws object shape in target window with states of rendering
	void draw(sf::RenderTarget& target, sf::RenderStates states) const override;

	// Returns border width
	float getBorderWidth() const;

	// Returns padding width
	float getPadding() const;

	// Returns position of widget. 
	// Position include padding, but don't include border width
	sf::Vector2f getPosition() const;

	// Returns size of widget. 
	// Size don't include padding and border widths
	sf::Vector2f getSize() const;

	// Moves widget relative to current position.
	// NOTICE: LWidget::move() don't set new position! Use LWidget::setPosition() to do that.
	void move(float X, float Y);

	// Creates borders of widget with color and thickness.
	// Set thickness to 0 if you want remove all borders
	void setBorder(float thickness = 1, const sf::Color& color = sf::Color::White);

	// Sets color of borders
	void setBorderColor(const sf::Color& color);

	// Sets border width
	void setBorderWidth(float width);

	// Sets the color of which the widget will filled
	void setColor(const sf::Color& color);

	// Sets padding width
	void setPadding(float padding);

	// Sets new position of widget.
	// Returns false if new position is equal to current one. Else returns true
	// Position include padding, but don't include border width
	bool setPosition(float X, float Y);

	// Sets wiaght and height of rectangle shape of widget
	// Size don't include padding and border widths
	void setSize(float X, float Y);

	// Calls draw() and onPaint() functions.
	// Called by LGameRender 
	void update(sf::RenderTarget& target, sf::RenderStates states = sf::RenderStates::Default);

};

