#include "LInput.h"

LInput::LInput(LAbstractWidget* parent) : LWidget(parent) {

	sf::Vector2f size(100, 30);
	sf::Vector2f pos(100, 100);

	this->setSize(size.x - m_padding * 2 - m_border * 2, 30);
	this->setPosition(m_padding + m_border + pos.x, size.y - this->getSize().y + pos.y - m_padding - m_border);
	this->setBorders(m_border, sf::Color::Red);
	this->setColor(sf::Color::Transparent);

}

void LInput::onPaint(sf::RenderTarget& target, sf::RenderStates states) {}

void LInput::onReleaseMouse(sf::Event& e) {



}