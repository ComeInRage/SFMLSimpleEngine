#include "LAbstractInput.h"

LAbstractInput::LAbstractInput(LAbstractWidget* parent) : LWidget(parent) {

	sf::Vector2f size(100, 30);
	sf::Vector2f pos(2, 2);
	float padding = 10.f;
	m_border = 1.f;

	this->setSize(size.x - padding * 2 - m_border * 2, size.y);
	this->setPosition(pos.x + m_border + padding, pos.y + m_border + padding);
	this->setBorder(m_border, sf::Color::Red);
	this->setColor(sf::Color::Transparent);

}

void LAbstractInput::onPaint(sf::RenderTarget& target, sf::RenderStates states) {

	this->setBorderWidth(this->isInFocus() ? m_border + 1 : m_border);

}

void LAbstractInput::onReleaseMouse(sf::Event& e) {}

void LAbstractInput::onTextEnter(sf::Event& e) {

	if (this->isInFocus())
		std::cout << "KEY ENTERED: " << static_cast<char> (e.text.unicode) << "\n";

}