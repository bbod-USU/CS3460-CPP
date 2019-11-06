//
// Created by Brady Bodily on 11/5/19.
//
#include "LifeSimulator.hpp"
#include "PatternAcorn.hpp"
#include "PatternBlinker.hpp"
#include "PatternBlock.hpp"
#include "PatternGlider.hpp"
#include "PatternGosperGliderGun.hpp"
#include "RendererConsole.hpp"

#include <iostream>
#include <thread>

int main()
{
    RendererConsole rendererConsole = RendererConsole();
    LifeSimulator lifeSimulator = LifeSimulator(100, 100);

    PatternBlinker patternBlinker = PatternBlinker();
    lifeSimulator.insertPattern(patternBlinker, 50, 10);

    PatternGlider patternGlider = PatternGlider();
    lifeSimulator.insertPattern(patternGlider, 5, 10);

    PatternGosperGliderGun patternGosperGliderGun = PatternGosperGliderGun();
    lifeSimulator.insertPattern(patternGosperGliderGun, 20, 20);

    PatternBlock patternBlock = PatternBlock();
    lifeSimulator.insertPattern(patternBlock, 0, 10);

    PatternAcorn patternAcorn = PatternAcorn();
    lifeSimulator.insertPattern(patternAcorn, 0, 23);

    int x = 0;
    while (x < 400)
    {
        rendererConsole.render(lifeSimulator);
        lifeSimulator.update();
        std::cout << std::endl;
        std::this_thread::sleep_for(std::chrono::milliseconds(10));
        x++;
    }
    return 0;
}