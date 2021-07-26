#include "Bar.h"

Bar::Bar()
	: m_y(0)
{

}

void Bar::setBar(float a)
{
	if (m_y + a > 100)
		throw Ex (a*m_y);
	else m_y = a;
}

float Bar::getBar()
{
	return m_y;
}

Bar::~Bar()
{

}