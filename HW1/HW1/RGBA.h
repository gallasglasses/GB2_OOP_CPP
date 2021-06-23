#pragma once
#include <cstdint>

namespace EX2
{
    class RGBA
    {
    private:
        std::uint8_t m_red,
            m_green,
            m_blue,
            m_alpha;
    public:
        RGBA()
            : m_red(0),
            m_green(0),
            m_blue(0),
            m_alpha(255)
        {

        }
        RGBA(uint8_t red, uint8_t green, uint8_t blue, uint8_t alpha)
            : m_red(red),
            m_green(green),
            m_blue(blue),
            m_alpha(alpha)
        {

        }
        void printRGBA();
    };
}