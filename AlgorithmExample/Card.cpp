#include "Card.h"
#include <stdexcept>

Card::Card()
{

}

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

std::string Card::get_color() const
{
	return this->color;
}

std::string Card::get_value() const
{
	return this->value;
}

std::string Card::to_string()
{
	return this->color + this->value;

}

int Card::get_num_value() const
{
	return this->bj_value_mapper[this->value];
}

bool Card::compare_by_value(const Card& a, const Card& b)
{
	return a.get_num_value() > b.get_num_value();
}

bool Card::same_value(const Card& a, const Card& b)
{
	return a.get_num_value() == b.get_num_value();
}

/*
Card::Card(Card& t)
{
	this->color = t.get_color();
	this->value = t.get_value();
}
*/

void Card::operator=(const Card& C)
{
	this->color = C.get_color();
	this->value = C.get_value();
}

