//
// Created by Brady Bodily on 11/5/19.
//

#ifndef CS3460_CPP_LIFESIMULATOR_HPP
#define CS3460_CPP_LIFESIMULATOR_HPP

#include "Pattern.hpp"

class LifeSimulator
{
  private:
    std::uint8_t sizeX;
    std::uint8_t sizeY;
    std::vector<std::vector<bool>> nextScreen;
    std::vector<std::vector<bool>> currentScreen;

  public:
    LifeSimulator(std::uint8_t sizeX, std::uint8_t sizeY);

    void insertPattern(const Pattern& pattern, std::uint8_t startX, std::uint8_t startY);
    void update();

    std::uint8_t getSizeX() const { return sizeX; };
    std::uint8_t getSizeY() const { return sizeY; };
    bool getCell(std::uint8_t x, std::uint8_t y) const { return currentScreen[y + 1][x + 1]; };
    ;
};

#endif //CS3460_CPP_LIFESIMULATOR_HPP
