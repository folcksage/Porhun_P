﻿#include <iostream>
class Integer
{
public:
	Integer(int number)
	{
		value = number;
	}
	Integer& add(const Integer& obj)
	{
		value += obj.value;
		return *this;
	}
	Integer& subtract(const Integer& obj)
	{
		value -= obj.value;
		return *this;
	}
	Integer& multiply(const Integer& obj)
	{
		value *= obj.value;
		return *this;
	}
	void print() const
	{
		std::cout << "Value: " << value << std::endl;
	}
private:
	int value;
};
void main() {
	Integer num{ 10 };
	num.add(Integer{ 30 }).subtract(Integer{ 15 }).multiply(Integer{ 2 });
	num.print(); // Value: 50
}