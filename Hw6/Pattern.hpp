//
// Created by Brady Bodily on 11/5/19.
//

#ifndef CS3460_CPP_PATTERN_HPP
#define CS3460_CPP_PATTERN_HPP

#include "rlutil.h"

#include <array>
#include <cstdint>
#include <iostream>
#include <vector>

class Pattern
{
  public:
    [[nodiscard]] virtual std::uint8_t getSizeX() const = 0;
    [[nodiscard]] virtual std::uint8_t getSizeY() const = 0;
    [[nodiscard]] virtual bool getCell(std::uint8_t x, std::uint8_t y) const = 0;
};

#endif //CS3460_CPP_PATTERN_HPP
