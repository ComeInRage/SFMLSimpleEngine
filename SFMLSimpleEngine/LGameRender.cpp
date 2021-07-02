#include <SFMLSimpleEngine/LGameRender.h>
#include <SFMLSimpleEngine/LAbstractWidget.h>

LGameRender::LGameRender(const sf::VideoMode& vmode, const sf::String& title) 
	: sf::RenderWindow(vmode, title), m_widgets(new std::map<sf::String, LAbstractWidget*>) {

	this->setVerticalSyncEnabled(true);

}

LGameRender::~LGameRender() {

	for (auto pair : *m_widgets) {
		delete pair.second;
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

		for (auto pair : *m_widgets) {
			pair.second->eventHandler(e);
		}

	}

}

void LGameRender::drawWidgets() {

	for (auto pair : *m_widgets) {
		this->draw(*(pair.second));
	}

}

////////////////////////////////////////////////
//               METHODS
///////////////////////////////////////////////

void LGameRender::add(const sf::String& key, LAbstractWidget* widget) {

	if (m_widgets->find(key) != m_widgets->end()) {
		std::cout << "[RENDER]: Element with key '" << static_cast<std::string>(key) << "' is already exists.\n";
		return;
	}

	widget->setWindow(this);
	(*m_widgets)[key] = widget;

}

void LGameRender::remove(const sf::String& key) {

	if (m_widgets->find(key) == m_widgets->end()) {
		std::cout << "Element with key '" << static_cast<std::string>(key) << "' is not exists.\n";
		return;
	}

	delete (*m_widgets)[key];
	m_widgets->erase(key);

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