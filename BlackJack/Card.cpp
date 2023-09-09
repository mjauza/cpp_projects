#include "Card.h"
#include <stdexcept>

/*
Card::Card()
{

}
*/

std::map<std::string, int> Card::bj_value_mapper = {
			{"2", 2},
			{"3", 3},
			{"4", 4},
			{"5", 5},
			{"6", 6},
			{"7", 7},
			{"8", 8},
			{"9", 9},
			{"10", 10},
			{"J", 10},
			{"Q", 10},
			{"K", 10},
			{"A", 11}
};

Card::Card(std::string color, std::string value)
{
	if ((color != colors.diamond) && (color != colors.cross) && (color != colors.heart) && (color != colors.spade)) {
		throw std::invalid_argument("invalid color");
	}

	if (this->bj_value_mapper.find(value) == this->bj_value_mapper.end()) {
		throw std::invalid_argument("invalid value");
	}

	this->color = color;
	this->value = value;
}

int Card::get_bj_numeric_value()
{
	int res = this->bj_value_mapper[this->value];
	return res;
}

std::string Card::get_color()
{
	return this->color;
}

std::string Card::get_value()
{
	return this->value;
}

bool Card::operator==(const Card& other) {
	return this->value == (other.get_value());
}