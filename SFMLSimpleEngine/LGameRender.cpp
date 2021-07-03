#include <SFMLSimpleEngine/LGameRender.h>
#include <SFMLSimpleEngine/LAbstractWidget.h>

LGameRender::LGameRender(const sf::VideoMode& vmode, const sf::String& title) 
	: sf::RenderWindow(vmode, title), m_widgets(new std::vector<LAbstractWidget*>) {

	this->setVerticalSyncEnabled(true);

}

LGameRender::~LGameRender() {

	for (auto widget : *m_widgets) {
		delete widget;
	}

	delete m_widgets;

}

////////////////////////////////////////////////
//               PRIVATE
///////////////////////////////////////////////

void LGameRender::event_loop() {

	sf::Event e;
	while (this->pollEvent(e)) {

		// Calling events in window

		if (e.type == sf::Event::Closed)
			this->onClose(e);

		if (e.type == sf::Event::Resized)
			this->onResize(e);

		// Calling event handlers of all child widgets

		for (auto widget : *m_widgets) {
			widget->eventHandler(e);
		}

	}

}

void LGameRender::drawWidgets() {

	for (auto widget : *m_widgets) {
		widget->onPaint(*this, sf::RenderStates::Default);
		this->draw(*widget);
	}

}

////////////////////////////////////////////////
//               METHODS
///////////////////////////////////////////////

void LGameRender::add(LAbstractWidget* widget) {

	widget->setWindow(this);
	m_widgets->push_back(widget);

}

void LGameRender::update() {

	this->event_loop();
	this->clear();
	this->drawWidgets();
	this->display();

}

////////////////////////////////////////////////
//               EVENTS
///////////////////////////////////////////////

void LGameRender::onClose(sf::Event& e) {

	this->close();

}

void LGameRender::onResize(sf::Event& e) {

	sf::FloatRect visibleArea(0.f, 0.f, static_cast<float> (e.size.width), static_cast<float> (e.size.height));
	this->setView(sf::View(visibleArea));

}