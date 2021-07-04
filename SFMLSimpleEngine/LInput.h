#pragma once

#include <SFMLSimpleEngine/LWidget.h>

class LInput : public LWidget
{

private:

	float m_border = 1.f;
	float m_padding = 2.f;

public:

	LInput(LAbstractWidget* parent);

	void onPaint(sf::RenderTarget& target, sf::RenderStates states) override;

	void onReleaseMouse(sf::Event& e) override;

};

