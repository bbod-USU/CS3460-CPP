//
// Created by Brady Bodily on 11/5/19.
//

#ifndef CS3460_CPP_PATTERNBLOCK_HPP
#define CS3460_CPP_PATTERNBLOCK_HPP
#include "Pattern.hpp"

class PatternBlock : public Pattern
{
  private:
    std::uint8_t X;
    std::uint8_t Y;
    std::array<std::array<bool, 4>, 4> cells;

  public:
    PatternBlock();
    std::uint8_t getSizeX() const
    {
        return X;
    };
    std::uint8_t getSizeY() const
    {
        return Y;
    };
    bool getCell(std::uint8_t x, std::uint8_t y) const
    {
        return cells[x][y];
    };
};

#endif //CS3460_CPP_PATTERNBLOCK_HPP
