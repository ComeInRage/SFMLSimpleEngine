#pragma once

#include <iostream>
#include <SFML/Graphics.hpp>

class LAbstractWidget;

class LGameRender : public sf::RenderWindow
{

private:

	// This map is needed for render child widgets and their unique keys
	std::vector<LAbstractWidget*>* m_widgets;

	// Loop in which all event functions are called
	void event_loop();

	// Function in which draw() function of widgets are called
	void drawWidgets();

public:

	// Constructor in which we initialize main window and set the VSync
	LGameRender(const sf::VideoMode& vmode, const sf::String& title);

	// In destructor we delete and release the memory
	// that is occupied by child widgets
	~LGameRender();

	////////////////////////////////////////////////
	//               METHODS
	///////////////////////////////////////////////

	// Adds any child LWidget with unique key to map of widgets
	void add(LAbstractWidget* widget);

	// This function have to be called in infinite loop.
	// It starts event loop, clears windows and updates it after all
	void update();

	////////////////////////////////////////////////
	//               EVENTS
	///////////////////////////////////////////////

	// Called if you closed the window
	virtual void onClose(sf::Event& e);

	// Called if you resized the window
	virtual void onResize(sf::Event& e);

};

