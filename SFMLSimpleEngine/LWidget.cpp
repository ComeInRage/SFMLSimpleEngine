#include <SFMLSimpleEngine/LWidget.h>

LWidget::LWidget()
	: m_shape(new sf::RectangleShape()) {}

LWidget::LWidget(sf::RectangleShape* shape)
	: m_shape(shape) {}

LWidget::LWidget(float W, float H)
	: m_shape(new sf::RectangleShape(sf::Vector2f(W, H))) {}

LWidget::~LWidget() {
	delete m_shape;
}


////////////////////////////////////////////////
//               METHODS
///////////////////////////////////////////////


bool LWidget::contains(const sf::Vector2f& point) const {

	return m_shape->getGlobalBounds().contains(point);

}

void LWidget::draw(sf::RenderTarget& target, sf::RenderStates states) const {

	target.draw(*m_shape);

	const auto childs = this->getChilds();

	for (auto pair : childs) {
		target.draw(*pair.second);
	}

	this->onPaint(target, states);

}

void LWidget::move(float X, float Y) {

	if (X == 0 && Y == 0)
		return;

	m_shape->move(X, Y);

}

void LWidget::setBorders(float thickness, const sf::Color& color) {

	m_shape->setOutlineThickness(thickness);
	m_shape->setOutlineColor(color);

}

void LWidget::setColor(const sf::Color& color) {

	m_shape->setFillColor(color);

}

bool LWidget::setPosition(float X, float Y) {

	const auto pos = m_shape->getPosition();

	if (pos.x == X && pos.y == Y)
		return false;

	m_shape->setPosition(X, Y);

	return true;

}


////////////////////////////////////////////////
//               EVENTS
///////////////////////////////////////////////


// Some events do nothing cause child classes should make logic by their own
// We can use abstract class but it is not correct because child classes of abstract class
// have to define any event function

void LWidget::onPaint(sf::RenderTarget& target, sf::RenderStates states) const {}