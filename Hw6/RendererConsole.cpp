//
// Created by Brady Bodily on 11/5/19.
//

#include "RendererConsole.hpp"

void RendererConsole::render(const LifeSimulator& simulation)
{
    rlutil::hidecursor();
    rlutil::cls();
    std::uint8_t y = simulation.getSizeY();
    std::uint8_t x = simulation.getSizeX();

    for (std::uint8_t i = 0; i < y; i++)
    {
        for (std::uint8_t j = 0; j < x; j++)
        {
            if (simulation.getCell(j, i))
            {
                rlutil::locate(j + 1, i + 1);
                rlutil::setChar('X');
            }
        }
    }
    rlutil::showcursor();
}