#pragma once

#include <SFMLSimpleEngine/LWidget.h>

class LAbstractInput : public LWidget
{

private:

	// Border width. Needed to increment border width
	// when user clicks on Input.
	float m_border;

public:

	LAbstractInput(LAbstractWidget* parent);

	void onPaint(sf::RenderTarget& target, sf::RenderStates states) override;

	void onReleaseMouse(sf::Event& e) override;

	void onTextEnter(sf::Event& e) override;

};

