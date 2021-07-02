#include <SFMLSimpleEngine/LCustomWidget.h>

LCustomWidget::LCustomWidget() 
	: m_vertices(new sf::VertexArray()) {}

LCustomWidget::~LCustomWidget() {
	delete m_vertices;
}


////////////////////////////////////////////////
//               METHODS
///////////////////////////////////////////////


void LCustomWidget::appendVertex(const sf::Vertex& vertex) {

	m_vertices->append(vertex);

}

void LCustomWidget::appendVertex(float X, float Y, const sf::Color& color) {

	m_vertices->append(sf::Vertex(sf::Vector2f(X, Y), color));

}

bool LCustomWidget::contains(const sf::Vector2f& point) const {

	return m_vertices->getBounds().contains(point);

}

void LCustomWidget::draw(sf::RenderTarget& target, sf::RenderStates states) const {

	target.draw(*m_vertices);

	const auto childs = this->getChilds();

	for (auto pair : childs) {
		target.draw(*pair.second);
	}

	this->onPaint(target, states);

}

void LCustomWidget::move(float X, float Y) {

	if (X == 0 && Y == 0)
		return;

	for (int i = 0; i < m_vertices->getVertexCount(); i++) {
		(*m_vertices)[i].position.x += X;
		(*m_vertices)[i].position.y += Y;
	}

}

bool LCustomWidget::setPosition(float X, float Y) {

	float delta_x = X - (*m_vertices)[0].position.x; // First Vertex in Array is main.
	float delta_y = Y - (*m_vertices)[0].position.y; // Calculate difference between current position and new position

	if (delta_x == 0 && delta_y == 0) // Return false if current position equals to new position
		return false;

	for (int i = 0; i < m_vertices->getVertexCount(); i++) {
		(*m_vertices)[i].position.x += delta_x;
		(*m_vertices)[i].position.y += delta_y;
	}

	return true;

}

void LCustomWidget::setPrimitive(const sf::PrimitiveType& ptype) {

	m_vertices->setPrimitiveType(ptype);

}


////////////////////////////////////////////////
//               EVENTS
///////////////////////////////////////////////


// Some events do nothing cause child classes should make logic by their own
// We can use abstract class but it is not correct because child classes of abstract class
// have to define any event function

void LCustomWidget::onPaint(sf::RenderTarget& target, sf::RenderStates states) const {}