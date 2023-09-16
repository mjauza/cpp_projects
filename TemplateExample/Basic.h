#pragma once
#include <iostream>
template <class T>
class Basic
{
public:
	Basic(T var) : var(var) {};
	T get_var() {
		return this->var;
	};
private:
	T var;

};

template <class T>
class Calculator
{
public:
	Calculator(T n1, T n2) {
		this->n1 = n1;
		this->n2 = n2;
	};
	T add() {
		return n1 + n2;
	}
	T subtract() {
		return n1 - n2;
	}

	T multiply() {
		return n1 * n2;
	}
	T divide() {
		return n1 / n2;
	}
	void display_results() {
		std::cout << n1 << " + " << n2 << " = " << add() << std::endl;
		std::cout << n1 << " - " << n2 << " = " << subtract() << std::endl;
		std::cout << n1 << " * " << n2 << " = " << multiply() << std::endl;
		std::cout << n1 << " / " << n2 << " = " << divide() << std::endl;
	}
private:
	T n1;
	T n2;

};
