#include <cassert>

#include <SFMLSimpleEngine/LAbstractWidget.h>

LAbstractWidget::LAbstractWidget()
	: m_parent(nullptr), m_childs(new std::vector<LAbstractWidget*>), m_window(nullptr) {}

LAbstractWidget::LAbstractWidget(LGameRender* render) 
	: m_parent(nullptr), m_childs(new std::vector<LAbstractWidget*>), m_window(render) {

	if (render)
		render->add(this);

}

LAbstractWidget::LAbstractWidget(LAbstractWidget* parent)
	: m_parent(parent), m_childs(new std::vector<LAbstractWidget*>), m_window(nullptr) {

	if (parent)
		parent->addChild(this);

}

LAbstractWidget::~LAbstractWidget() {

	for (auto child : *m_childs) {
		delete child;
	}

	delete m_childs;

}


////////////////////////////////////////////////
//               METHODS
///////////////////////////////////////////////


void LAbstractWidget::addChild(LAbstractWidget* child) {

	child->setWindow(m_window);
	child->setParent(this);
	m_childs->push_back(child);

}

LAbstractWidget::CHILDS_CREF LAbstractWidget::getChilds() const {

	return *m_childs;

}

const LAbstractWidget& LAbstractWidget::getParent() const {

	return *m_parent;

}

const sf::RenderWindow& LAbstractWidget::getWindow() const {

	assert(m_window != 0 && "LAbstractWidget has no pointer to window!");
	return *m_window;

}

void LAbstractWidget::removeChild(int key) {

	delete m_childs->at(key);
	m_childs->erase(m_childs->begin() + key);

}

void LAbstractWidget::setFocus(bool state) {

	m_focus = state;

}

void LAbstractWidget::setParent(LAbstractWidget* parent) {

	if (!m_parent)
		m_parent = parent;

}

void LAbstractWidget::setWindow(sf::RenderWindow* window) {

	if (!m_window)
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

	for (auto child : *m_childs) {
		bool child_success = child->eventHandler(e);
		if (!success && child_success)
			success = child_success;
	}

	return success;

}

// Some events do nothing cause child classes should make logic by their own
// We can use abstract class but it is not correct because child classes of abstract class
// have to define any event function

void LAbstractWidget::onReleaseMouse(sf::Event& e) {

	this->setFocus(true);

}

void LAbstractWidget::onPaint(sf::RenderTarget& target, sf::RenderStates states) {}