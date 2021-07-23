#include "Colours.h"

Colours::Colours(Code cColour)
    : codeColour(cColour)
{

}

int Colours::getCode() const
{
    return static_cast<int>(codeColour);
}

Colours::~Colours()
{

}