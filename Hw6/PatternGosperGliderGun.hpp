//
// Created by Brady Bodily on 11/5/19.
//

#ifndef CS3460_CPP_PATTERNGOSPERGLIDERGUN_HPP
#define CS3460_CPP_PATTERNGOSPERGLIDERGUN_HPP

#include "Pattern.hpp"

class PatternGosperGliderGun : public Pattern
{
  private:
    std::uint8_t X;
    std::uint8_t Y;
    std::array<std::array<bool, 4>, 4> cells{};

  public:
    PatternGosperGliderGun();
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
        return cells[x][y];
    };
};

#endif //CS3460_CPP_PATTERNGOSPERGLIDERGUN_HPP
