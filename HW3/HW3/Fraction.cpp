#include "Fraction.h"

Fraction::Fraction(int numerator, int denominator) const
{
	m_numerator = numerator;
	m_denominator = denominator;
}

int Fraction::Reduction(int numerator, int denominator) const
{
	return (denominator == 0) ? (numerator > 0 ? numerator : -numerator) : Reduction(denominator, numerator % denominator);
}

void Fraction::printFraction() const
{
	int LCM = Fraction::Reduction(m_numerator, m_denominator);
	std::cout << m_numerator / LCM << "/" << m_denominator / LCM;
}

Fraction Fraction::operator- () const
{
	return Fraction(-m_numerator, m_denominator);
}