#include "Entity/Product.h"

Product::Product(int id, QString name, double cost) :
	m_id(id),
	m_name(name),
	m_cost(cost) {
}

bool Product::isValid() const {
	return (m_id >= 0) &&
		   (!m_name.isEmpty()) &&
		   (m_cost > 0.0);
}

int Product::id() const {
	return m_id;
}

void Product::setId(int id) {
	m_id = id;
}

QString Product::name() const {
	return m_name;
}

void Product::setName(const QString& name) {
	m_name = name;
}

double Product::cost() const {
	return m_cost;
}

void Product::setCost(double cost) {
	m_cost = cost;
}

bool operator ==(const Product& p1, const Product& p2) {
	return (p1.id() == p2.id()) &&
		   (p1.name() == p2.name()) &&
		   (p1.cost() == p2.cost());
}
