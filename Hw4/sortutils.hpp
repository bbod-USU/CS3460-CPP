//
// Created by Brady Bodily on 10/2/19.
//

#ifndef HW4_SORTUTILS_HPP
#define HW4_SORTUTILS_HPP

#include <algorithm>
#include <array>
#include <chrono>
#include <iomanip>
#include <iostream>
#include <vector>

const std::size_t HOW_MANY_ELEMENTS = 250000;
const std::uint8_t HOW_MAMY_TIMES = 25;
using SourceArray = std::array<int, HOW_MANY_ELEMENTS>;

void initializeRawArrayFromStdArray(const std::array<int, HOW_MANY_ELEMENTS>& source, int dest[]);
void organPipeStdArray(std::array<int, HOW_MANY_ELEMENTS>& data);
void evaluateRawArray(const SourceArray& random, const SourceArray& sorted, const SourceArray& reversed, const SourceArray& organPipe, const SourceArray& rotated);
void evaluateStdArray(const SourceArray& random, const SourceArray& sorted, const SourceArray& reversed, const SourceArray& organPipe, const SourceArray& rotated);
void evaluateStdVector(const SourceArray& random, const SourceArray& sorted, const SourceArray& reversed, const SourceArray& organPipe, const SourceArray& rotated);

#endif // HW4_SORTUTILS_HPP
