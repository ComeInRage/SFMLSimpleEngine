#pragma once

#include <iostream>
#include <SFML/Graphics.hpp>

#include <SFMLSimpleEngine/LGameRender.h>

class LAbstractWidget : public sf::Drawable
{

private:

	// Vector with pointers to child widgets
	std::vector<LAbstractWidget*>* m_childs;

	// Pointer to parent widget
	LAbstractWidget* m_parent;

	// Static pointer to parent window sf::RenderWindow
	sf::RenderWindow* m_window;

	// Events parameters

	bool m_focus = false;

public:

	// Default constructor. Initialize all pointers by nullptr
	LAbstractWidget();

	// Constructor that you can use if your widget has no parent widget.
	// Initialize pointer to parent widget by nullptr, adds widget to widgets vector in LGameRender
	LAbstractWidget(LGameRender* render);

	// Constructor that you can use if your widget is child. 
	// Initialize pointer to parent widget. Copies pointer to sf::RenderWindow from parent
	LAbstractWidget(LAbstractWidget* parent);

	// Destructor which releases all occupied memory
	~LAbstractWidget();


	////////////////////////////////////////////////
	//               METHODS
	///////////////////////////////////////////////


	// Adds child widget to m_childs vector
	void addChild(LAbstractWidget* child);

	// Returns true if widget contains point. Else returns false
	virtual bool contains(const sf::Vector2f& point) const = 0;

	// Returns const reference to childs vector
	typedef const std::vector<LAbstractWidget*>& CHILDS_CREF;
	CHILDS_CREF getChilds() const;

	// Returns size of parent main window
	sf::Vector2u getSize() const;

	// Returns const reference to parent window
	const sf::RenderWindow& getWindow() const;

	// Removes child from vector and release memory
	void removeChild(int key);
		 
	// Sets focus by "state" value
	void setFocus(bool state);

	// Sets the pointer to parent window with sf::RenderWindow type
	void setParent(LAbstractWidget* parent);

	// Sets static pointer to main window
	void setWindow(sf::RenderWindow* window);


	////////////////////////////////////////////////
	//               EVENTS
	///////////////////////////////////////////////


	/*
		This have to be called in event loop
		If you want to process any events
		Returns true if event was processes successfully, else returns false
	*/
	virtual bool eventHandler(sf::Event& e);

	// Called when any mouse button released
	virtual void onReleaseMouse(sf::Event& e);

};