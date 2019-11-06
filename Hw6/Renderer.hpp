//
// Created by Brady Bodily on 11/5/19.
//

#ifndef HW6_RENDER_HPP
#define HW6_RENDER_HPP

#include "LifeSimulator.hpp"

class Renderer
{
public:
    virtual void render(const LifeSimulator& simulation) = 0;
};

#endif //HW6_RENDER_HPP
