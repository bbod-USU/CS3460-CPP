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
    // Renderer and Simulator
    RendererConsole rendererConsole = RendererConsole();
    LifeSimulator lifeSimulator = LifeSimulator(100, 40);
    // Objects
    PatternGosperGliderGun patternGosperGliderGun = PatternGosperGliderGun();
    PatternBlock patternBlock = PatternBlock();
    PatternGlider patternGlider = PatternGlider();
    PatternBlinker patternBlinker = PatternBlinker();
    PatternAcorn patternAcorn = PatternAcorn();

    // Adding objects to simulator
    lifeSimulator.insertPattern(patternGosperGliderGun, 20, 20);
    lifeSimulator.insertPattern(patternBlock, 0, 10);
    lifeSimulator.insertPattern(patternGlider, 5, 10);
    lifeSimulator.insertPattern(patternBlinker, 50, 10);
    lifeSimulator.insertPattern(patternAcorn, 0, 23);

    // Animation Demonstration
    int x = 0;
    while (x < 200)
    {
        rendererConsole.render(lifeSimulator);
        lifeSimulator.update();
        std::cout << std::endl;
        std::this_thread::sleep_for(std::chrono::milliseconds(10));
        x++;
    }
    return 0;
}