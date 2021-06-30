#include "RGBA.h"

using namespace EX2;

RGBA::RGBA()
    : m_red(0),
    m_green(0),
    m_blue(0),
    m_alpha(255)
{

}

RGBA::RGBA(uint8_t red, uint8_t green, uint8_t blue, uint8_t alpha)
    : m_red(red),
    m_green(green),
    m_blue(blue),
    m_alpha(alpha)
{

}

void RGBA::printRGBA()
{
    std::cout << "RGB values: " << static_cast<int>(m_red) << ", " << static_cast<int>(m_green) << ", " << static_cast<int>(m_blue) << ", " << static_cast<int>(m_alpha) << std::endl;
}