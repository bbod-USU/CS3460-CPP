//
// Created by Brady Bodily on 11/5/19.
//

#ifndef CS3460_CPP_PATTERNACORN_HPP
#define CS3460_CPP_PATTERNACORN_HPP

#include "Pattern.hpp"

class PatternAcorn : public Pattern
{
  private:
    std::uint8_t X;
    std::uint8_t Y;
    std::array<std::array<bool, 9>, 5> cells{};

  public:
    PatternAcorn();
    [[nodiscard]] std::uint8_t getSizeX() const override
    {
        return X;
    };
    [[nodiscard]] std::uint8_t getSizeY() const override
    {
        return Y;
    };
    [[nodiscard]] bool getCell(std::uint8_t x, std::uint8_t y) const override
    {
        return cells[y][x];
    };
};

#endif //CS3460_CPP_PATTERNACORN_HPP
