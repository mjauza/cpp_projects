#pragma once
#include <string>
#include <map>

/*
struct Colors {
	std::string diamond = "D";
	std::string heart = "H";
	std::string spade = "S";
	std::string cross = "C";
};
*/

class Card
{
	public:
		Card();
		Card(std::string color, std::string value);
		int get_bj_numeric_value() const;
		std::string get_color() const;
		std::string get_value() const;
		int get_num_value() const;
		void operator=(const Card& C);
		struct Colors {
			std::string diamond = "D";
			std::string heart = "H";
			std::string spade = "S";
			std::string cross = "C";
		};
		
		static Colors colors;
		static std::map<std::string, int> bj_value_mapper;
		bool operator==(const Card& other);
		std::string to_string();
		
	
	private:
		std::string color;
		std::string value;
		
};

