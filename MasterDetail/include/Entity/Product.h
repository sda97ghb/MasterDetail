#ifndef ORDERITEM_H
#define ORDERITEM_H

#include <QString>

class Product {
public:
	Product(int id = -1, QString name = "", double cost = 0.0);

	bool isValid() const;

	int id() const;
	void setId(int id);

	QString name() const;
	void setName(const QString& name);

	double cost() const;
	void setCost(double cost);

private:
	int m_id;
	QString m_name;
	double m_cost;
};

bool operator ==(const Product& p1, const Product& p2);

#endif // ORDERITEM_H
