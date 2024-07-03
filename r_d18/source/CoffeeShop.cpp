#include "CoffeeShop.h"

CoffeeShop::CoffeeShop(std::string title, unsigned int tablesCount)
{
	this->title = title;
	this->tablesCount = tablesCount;

	m_Tables = new bool[tablesCount];
	std::memset(m_Tables, 0, tablesCount * sizeof(bool));

	m_Orders = new Drink*[tablesCount];
	for (unsigned int i = 0; i < tablesCount; ++i) {
		m_Orders[i] = nullptr;
	}
}

CoffeeShop::~CoffeeShop()
{
	delete[] m_Tables;

	for (unsigned int i = 0; i < tablesCount; ++i) {
		delete m_Orders[i];
	}
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
	int coffeTypeChoose;
	char coffeSizeChoose;
	Size size;
	DrinkType type;

	bool isInvalid = true;
	do {

		std::cout << "Choose type of coffee/drink and size:\n"
			<< "0. Simple water S/M/L/X\n"
			<< "1. Arabica S/M/L/X\n"
			<< "2. Black M/L/X:\n"
			<< "3. Cappuccino S/M/L/X:\n"
			<< "4. Espresso S:\n"
			<< "5. Latte S/M/L/X:\n" << std::endl;

		std::cout << "\tYour choose: ";
		std::cin >> coffeTypeChoose;

		std::cout << "\tYour size: ";
		std::cin >> coffeSizeChoose;
		std::cout << '\n';

		switch (coffeTypeChoose)
		{
		case 0: {
			type = DrinkType::Water;
			break;
		}
		case 1: {
			type = DrinkType::Arabica;
			break;
		}
		case 2: {
			type = DrinkType::Black;
			break;
		}
		case 3: {
			type = DrinkType::Cappuccino;
			break;
		}
		case 4: {
			type = DrinkType::Espresso;
			break;
		}
		case 5: {
			type = DrinkType::Latte;
			break;
		}
		default:
			type = DrinkType::Unknown;
			break;
		}
		switch (coffeSizeChoose)
		{
		case 's': {
			size = Size::Small;
			break;
		}
		case 'S': {
			size = Size::Small;
			break;
		}
		case 'm': {
			size = Size::Medium;
			break;
		}
		case 'M': {
			size = Size::Medium;
			break;
		}
		case 'l': {
			size = Size::Large;
			break;
		}
		case 'L': {
			size = Size::Large;
			break;
		}
		case 'x': {
			size = Size::XLarge;
			break;
		}
		case 'X': {
			size = Size::XLarge;
			break;
		}
		default:
			break;
		}

		m_Orders[tableNumber] = Drink::createDrink(type, size);

		isInvalid = m_Orders[tableNumber] == nullptr || m_Orders[tableNumber]->size == Size::Invalid;
		if (isInvalid) std::cout << "Invalid input!\n";
	} while (isInvalid);
}

bool CoffeeShop::prepare(int tableNumber)
{
	if (!m_Tables[tableNumber]) return false;
	m_Orders[tableNumber]->prepare();
	return true;
}

bool CoffeeShop::getReceipt(int tableNumber)
{
	if (!m_Tables[tableNumber]) return false;

	std::cout << "You order cost: " << m_Orders[tableNumber]->getCost() << std::endl;
	m_Tables[tableNumber] = false;
	m_Orders[tableNumber]->~Drink();
	return true;
}
