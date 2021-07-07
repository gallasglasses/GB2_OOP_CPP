#pragma once
#include <iostream>

class Fraction
{
private:
	int m_numerator = 0;
	int m_denominator = 1;

public:
	Fraction(int numerator = 0, int denominator = 1);
	void printFraction();
	int Reduction(int numerator, int denominator);

	friend Fraction operator+ (const Fraction& f1, const Fraction& f2);
	friend Fraction operator- (const Fraction& f1, const Fraction& f2);
	friend Fraction operator* (const Fraction& f1, const Fraction& f2);
	friend Fraction operator/ (const Fraction& f1, const Fraction& f2);

	Fraction operator- () const;

	//(==, !=, <, >, <=, >=)
	friend bool operator== (const Fraction& f1, const Fraction& f2);
	friend bool operator!= (const Fraction& f1, const Fraction& f2);
	friend bool operator> (const Fraction& f1, const Fraction& f2);
	friend bool operator< (const Fraction& f1, const Fraction& f2);
	friend bool operator>= (const Fraction& f1, const Fraction& f2);
	friend bool operator<= (const Fraction& f1, const Fraction& f2);
};

