//
// Created by Brady Bodily on 11/5/19.
//

#ifndef CS3460_CPP_RENDERERCONSOLE_HPP
#define CS3460_CPP_RENDERERCONSOLE_HPP

#include "Renderer.hpp"
#include "rlutil.h"

class RendererConsole : public Renderer
{
  public:
    void render(const LifeSimulator& simulation);
};
#endif //CS3460_CPP_RENDERERCONSOLE_HPP
