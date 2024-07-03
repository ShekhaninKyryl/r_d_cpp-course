#include "CoffeeShop.h"

CoffeeShop::CoffeeShop(std::string title, unsigned int tablesCount)
{
	this->title = title;
	this->tablesCount = tablesCount;

	m_Tables = new bool[tablesCount];
	std::memset(m_Tables, 0, tablesCount * sizeof(bool));

	m_Orders = new Coffee[tablesCount];
}

CoffeeShop::~CoffeeShop()
{
	delete[] m_Tables;
	delete[] m_Orders;
}

int CoffeeShop::takePlace()
{
	for (int i = 0; i < tablesCount; i++) {
		if (!m_Tables[i]) {
			m_Tables[i] = true;
			return i;
		}
	}
	return -1;
}

void CoffeeShop::order(int tableNumber)
{
	int choose;
	CoffeeType type;

	do {

		std::cout << "Choose type of coffee:\n"
			<< "1. Arabica\n"
			<< "2. Black\n"
			<< "3. Cappuccino\n"
			<< "4. Espresso\n"
			<< "5. Latte\n"
			<< "6. Robusta\n" << std::endl;

		std::cout << " Your choose: ";
		std::cin >> choose;

		switch (choose)
		{
		case 1: {
			type = CoffeeType::Arabica;
			break;
		}
		case 2: {
			type = CoffeeType::Black;
			break;
		}
		case 3: {
			type = CoffeeType::Cappuccino;
			break;
		}
		case 4: {
			type = CoffeeType::Espresso;
			break;
		}
		case 5: {
			type = CoffeeType::Latte;
			break;
		}
		case 6: {
			type = CoffeeType::Robusta;
			break;
		}
		default:
			type = CoffeeType::Unknown;
			break;
		}
	} while (type == CoffeeType::Unknown);

	m_Orders[tableNumber] = Coffee(type);
}

bool CoffeeShop::prepare(int tableNumber)
{
	if (!m_Tables[tableNumber]) return false;
	m_Orders[tableNumber].prepare();
	return true;
}

bool CoffeeShop::getReceipt(int tableNumber)
{
	if (!m_Tables[tableNumber]) return false;

	std::cout << "You order cost: " << m_Orders[tableNumber].getCost() << std::endl;
	m_Tables[tableNumber] = false;
	m_Orders[tableNumber].~Coffee();
	return true;
}
