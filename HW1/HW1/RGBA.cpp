#include "RGBA.h"
#include <iostream> 

using namespace EX2;

void RGBA::printRGBA()
{
    std::cout << "RGB values: " << static_cast<int>(m_red) << ", " << static_cast<int>(m_green) << ", " << static_cast<int>(m_blue) << ", " << static_cast<int>(m_alpha) << std::endl;
}