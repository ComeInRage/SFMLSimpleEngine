#include <SFMLSimpleEngine/LWidget.h>

LWidget::LWidget(LAbstractWidget* parent)
	: LAbstractWidget(parent), m_shape(sf::RectangleShape()) {}

LWidget::LWidget(LGameRender* render)
	: LAbstractWidget(render), m_shape(sf::RectangleShape()) {}

LWidget::LWidget(float W, float H, LAbstractWidget* parent)
	: LAbstractWidget(parent), m_shape(sf::Vector2f(W, H)) {}

LWidget::LWidget(float W, float H, LGameRender* render)
	: LAbstractWidget(render), m_shape(sf::Vector2f(W, H)) {}

LWidget::LWidget(const sf::RectangleShape& shape, LAbstractWidget* parent)
	: LAbstractWidget(parent), m_shape(shape) {}

LWidget::LWidget(const sf::RectangleShape& shape, LGameRender* render)
	: LAbstractWidget(render), m_shape(shape) {}


////////////////////////////////////////////////
//               METHODS
///////////////////////////////////////////////


bool LWidget::contains(const sf::Vector2f& point) const {

	return m_shape.getGlobalBounds().contains(point);

}

void LWidget::draw(sf::RenderTarget& target, sf::RenderStates states) const {

	target.draw(m_shape);

}

float LWidget::getBorderWidth() const {

	return m_shape.getOutlineThickness();

}

float LWidget::getPadding() const {

	return m_padding;

}

sf::Vector2f LWidget::getPosition() const {

	//sf::Vector2f pos = m_shape.getPosition();
	//pos.x += m_padding;
	//pos.y += m_padding;

	return m_shape.getPosition();//pos;

}

sf::Vector2f LWidget::getSize() const {

	return m_shape.getSize();

}

void LWidget::move(float X, float Y) {

	if (X == 0 && Y == 0)
		return;

	m_shape.move(X, Y);

}

void LWidget::setBorder(float thickness, const sf::Color& color) {

	m_shape.setOutlineThickness(thickness);
	m_shape.setOutlineColor(color);

}

void LWidget::setBorderColor(const sf::Color& color) {

	m_shape.setOutlineColor(color);

}

void LWidget::setBorderWidth(float width) {

	m_shape.setOutlineThickness(width);

}

void LWidget::setColor(const sf::Color& color) {

	m_shape.setFillColor(color);

}

void LWidget::setPadding(float padding) {

	m_padding = padding;

}

bool LWidget::setPosition(float X, float Y) {

	const auto pos = this->getPosition();

	if (pos.x == X && pos.y == Y)
		return false;

	m_shape.setPosition(X + m_padding, Y + m_padding);

	return true;

}

void LWidget::setSize(float X, float Y) {

	m_shape.setSize(sf::Vector2f(X, Y));

}

void LWidget::update(sf::RenderTarget& target, sf::RenderStates states) {

	this->onPaint(target, states);
	this->draw(target, states);

	const auto childs = this->getChilds();

	for (auto child : childs) {
		child->update(target, states);
	}

}