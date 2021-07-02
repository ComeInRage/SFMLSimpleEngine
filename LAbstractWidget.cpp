#include <cassert>

#include <SFMLSimpleEngine/LAbstractWidget.h>

LAbstractWidget::LAbstractWidget() 
	: m_parent(0), m_childs(new std::map<sf::String, LAbstractWidget*>), m_window(0), m_key("") {}

LAbstractWidget::LAbstractWidget(const sf::String& key, LGameRender* render) 
	: m_parent(0), m_childs(new std::map<sf::String, LAbstractWidget*>), m_window(render), m_key(key) {

	render->add(key, this);

}

LAbstractWidget::LAbstractWidget(const sf::String& key, LAbstractWidget* parent)
	: m_parent(parent), m_childs(new std::map<sf::String, LAbstractWidget*>), m_window(0), m_key(key) {

	parent->addChild(key, this);

}

LAbstractWidget::~LAbstractWidget() {

	for (auto pair : *m_childs) {
		delete pair.second;
	}

	delete m_childs;

}


////////////////////////////////////////////////
//               METHODS
///////////////////////////////////////////////


void LAbstractWidget::addChild(const sf::String& key, LAbstractWidget* child) {

	if (m_childs->find(key) != m_childs->end()) {
		std::cout << "Child with key '" << static_cast<std::string>(key) << "' is already exists.\n";
		return;
	}

	child->setWindow(m_window);
	child->setParent(this);
	(*m_childs)[key] = child;

}

LAbstractWidget::CHILDS_CREF LAbstractWidget::getChilds() const {

	return *m_childs;

}

const sf::String& LAbstractWidget::getKey() const {

	return m_key;

}

sf::Vector2u LAbstractWidget::getSize() const {

	assert(m_window != 0 && "LAbstractWidget has no pointer to window!");
	return m_window->getSize();

}

const sf::RenderWindow& LAbstractWidget::getWindow() const {

	assert(m_window != 0 && "LAbstractWidget has no pointer to window!");
	return *m_window;

}

void LAbstractWidget::removeChild(const sf::String& key) {

	if (m_childs->find(key) == m_childs->end()) {
		std::cout << static_cast<std::string> (key) << " is not exists!\n";
		return;
	}

	delete (*m_childs)[key];
	m_childs->erase(key);

}

void LAbstractWidget::setFocus(bool state) {

	m_focus = state;

}

void LAbstractWidget::setParent(LAbstractWidget* parent) {

	m_parent = parent;

}

void LAbstractWidget::setWindow(sf::RenderWindow* window) {

	if (m_window == 0)
		m_window = window;

}


////////////////////////////////////////////////
//               EVENTS
///////////////////////////////////////////////


bool LAbstractWidget::eventHandler(sf::Event& e) {

	bool success = false;

	if (e.type == sf::Event::MouseButtonReleased) {

		sf::Vector2i mouse_pos = sf::Mouse::getPosition(*m_window);
		bool clicked = this->contains(sf::Vector2f(mouse_pos));
		this->setFocus(clicked);
		if (clicked) {
			this->onReleaseMouse(e);
			success = true;
		}

	}

	for (auto pair : *m_childs) {
		bool child_success = pair.second->eventHandler(e);
		if (!success && child_success)
			success = child_success;
	}

	return success;

}

// Some events do nothing cause child classes should make logic by their own
// We can use abstract class but it is not correct because child classes of abstract class
// have to define any event function

void LAbstractWidget::onReleaseMouse(sf::Event& e) {}