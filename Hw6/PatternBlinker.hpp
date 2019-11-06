//
// Created by Brady Bodily on 11/5/19.
//

#ifndef CS3460_CPP_PATTERNBLINKER_HPP
#define CS3460_CPP_PATTERNBLINKER_HPP

#include "Pattern.hpp"

class PatternBlinker : public Pattern
{
  private:
    uint8_t X;
    uint8_t Y;
    std::array<std::array<bool, 5>, 5> cells;

  public:
    PatternBlinker();

    std::uint8_t getSizeX() const { return X; };

    std::uint8_t getSizeY() const { return Y; };

    bool getCell(std::uint8_t x, std::uint8_t y) const { return cells[y][x]; };
};

#endif //CS3460_CPP_PATTERNBLINKER_HPP
