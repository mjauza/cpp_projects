#pragma once
#include <string>
#include <map>
class Card
{
	public:
		Card(std::string color, std::string value);
		Card();
		//Card(Card& t);
		void operator=(const Card& C);
		static std::map<std::string, int> bj_value_mapper;

		std::string get_color() const;
		std::string get_value() const;
		int get_num_value() const;

		std::string to_string();

		static bool compare_by_value(const Card& a, const Card& b);
		static bool same_value(const Card& a, const Card& b);


		const struct {
			std::string diamond = "D";
			std::string heart = "H";
			std::string spade = "S";
			std::string cross = "C";
		} colors;

	
	private:
		std::string color;
		std::string value;
};

