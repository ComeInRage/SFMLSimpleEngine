#pragma once

#include <iostream>
#include <SFML/Graphics.hpp>

#include <SFMLSimpleEngine/LGameRender.h>

class LAbstractWidget : public sf::Drawable
{

private:

	// Map with unique keys and pointers to child widgets
	std::map<sf::String, LAbstractWidget*>* m_childs;

	// All widgets have unique keys. They are needed to store pointers to widgets
	sf::String m_key;

	// Pointer to parent widget
	LAbstractWidget* m_parent;

	// Static pointer to parent window sf::RenderWindow
	sf::RenderWindow* m_window;

	// Events parameters

	bool m_focus = false;

public:

	// Default constructor. Initialize childs map by empty map and parent pointer by zero
	LAbstractWidget();

	// Constructor that you can use if your widget has no parent widget.
	// You have to specify unique key of your widget in first argument.
	// Initialize pointer to parent widget by 0, adds widget to widgets map in render
	LAbstractWidget(const sf::String& key, LGameRender* render);

	// Constructor that you can use if your widget is child. 
	// You have to specify unique key of your widget in first argument.
	// Initialize pointer to parent widget
	LAbstractWidget(const sf::String& key, LAbstractWidget* parent);

	// Destructor which releases all occupied memory by child widgets
	~LAbstractWidget();


	////////////////////////////////////////////////
	//               METHODS
	///////////////////////////////////////////////


	// Adds child widget to m_childs map with unique key
	void addChild(const sf::String& key, LAbstractWidget* child);

	// Returns true if widget contains point. Else returns false
	virtual bool contains(const sf::Vector2f& point) const = 0;

	// Returns const reference to childs map
	typedef const std::map<sf::String, LAbstractWidget*>& CHILDS_CREF;
	CHILDS_CREF getChilds() const;

	// Returns unique key of this widget
	const sf::String& getKey() const;

	// Returns size of parent main window
	sf::Vector2u getSize() const;

	// Returns const pointer to main window
	const sf::RenderWindow& getWindow() const;

	// Removes child from map and release memory
	void removeChild(const sf::String& key);
		 
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