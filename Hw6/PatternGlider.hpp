//
// Created by Brady Bodily on 11/5/19.
//

#ifndef CS3460_CPP_PATTERNGLIDER_HPP
#define CS3460_CPP_PATTERNGLIDER_HPP

#include <array>
#include "Pattern.hpp"

class PatternGlider : public Pattern
{
private:
    int X;
    int Y;
    std::array<std::array<bool, 5>, 5> cells;
public:
    PatternGlider();
    int getSizeX()
    {
        return X;
    };
    int getSizeY(){
        return Y;
    };
    bool getCell(int x, int y){
        return cells[x][y];
    };

};

#endif //CS3460_CPP_PATTERNGLIDER_HPP
