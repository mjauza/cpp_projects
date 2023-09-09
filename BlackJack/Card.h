#pragma once
#include <string>
#include <map>
class Card
{
	public:
		//Card();
		Card(std::string color, std::string value);
		int get_bj_numeric_value();
		std::string get_color();
		std::string get_value();
		static const struct {
			std::string diamond = "D";
			std::string heart = "H";
			std::string spade = "S";
			std::string cross = "C";
		} colors;
		static std::map<std::string, int> bj_value_mapper;
		bool operator==(const Card& other);
		
	
	private:
		std::string color;
		std::string value;
		
};

