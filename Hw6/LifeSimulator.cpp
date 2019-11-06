#include "LifeSimulator.hpp"

LifeSimulator::LifeSimulator(std::uint8_t sizeX, std::uint8_t sizeY) :
    sizeX(sizeX), sizeY(sizeY)
{
    // Initializing vectors with padding for easy searches
    for (std::uint8_t i = 0; i < sizeY + 2; i++)
    {
        currentScreen.emplace_back();
        nextScreen.emplace_back();
        for (std::uint8_t j = 0; j < sizeX + 2; j++)
        {
            currentScreen[i].push_back(false);
            nextScreen[i].push_back(false);
        }
    }
}

void LifeSimulator::insertPattern(const Pattern& pattern, std::uint8_t startX, std::uint8_t startY)
{
    startX += 1;
    startY += 1;
    //    std::cout << pattern.getCell(0, 0) << std::endl;
    if (((currentScreen.size() - 1) >= pattern.getSizeY() + startY) &&
        (pattern.getSizeX() + startX) <= (currentScreen[0].size() - 1))
    {
        for (std::uint8_t y = 0; y < pattern.getSizeY(); y++)
        {
            for (std::uint8_t x = 0; x < pattern.getSizeX(); x++)
            {
                if (pattern.getCell(x, y))
                {
                    currentScreen[y + startY][x + startX] = true;
                }
            }
        }
    }
    else
    {
        std::cout << "Screen size is not big enough." << std::endl;
    }
}

void LifeSimulator::update()
{
    // Temp vector to update day
    for (std::uint8_t i = 0; i < unsigned(sizeY) + 2; i++)
    {
        for (std::uint8_t j = 0; j < unsigned(sizeX) + 2; j++)
        {
            nextScreen[i][j] = false;
        }
    }

    for (int i = 1; i < currentScreen.size() - 1; i++)
    {
        for (int j = 1; j < currentScreen[0].size() - 1; j++)
        {
            int liveCount = 0;
            for (int y = -1; y < 2; y++)
            {
                for (int x = -1; x < 2; x++)
                {
                    if (!(y == 0 && x == 0))
                        if (currentScreen[i + y][j + x])
                            liveCount++;
                }
            }

            if (liveCount > 1 && liveCount < 4)
            {
                if (currentScreen[i][j])
                {
                    nextScreen[i][j] = true;
                }
                else
                {
                    if (liveCount == 3)
                    {
                        nextScreen[i][j] = true;
                    }
                }
            }
        }
    }
    currentScreen = nextScreen;
}