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
    RendererConsole rendererConsole;
    PatternAcorn patternAcorn;
    PatternBlock patternBlock;
    PatternGosperGliderGun patternGosperGliderGun;
    PatternGlider patternGlider;
    PatternBlinker patternBlinker;

    LifeSimulator lifeSimulator = LifeSimulator(100, 28);
    LifeSimulator lifeSimulator1 = LifeSimulator(100, 28);
    LifeSimulator lifeSimulator2 = LifeSimulator(100, 28);

    lifeSimulator.insertPattern(patternBlinker, 50, 10);

    lifeSimulator.insertPattern(patternGlider, 5, 10);

    lifeSimulator1.insertPattern(patternGosperGliderGun, 0, 0);

    lifeSimulator.insertPattern(patternBlock, 0, 10);

    lifeSimulator2.insertPattern(patternAcorn, 5, 5);

    int x = 0;
    while (x < 200)
    {
        rendererConsole.render(lifeSimulator);
        lifeSimulator.update();
        std::cout << std::endl;
        std::this_thread::sleep_for(std::chrono::milliseconds(10));
        x++;
    }

    int y = 0;
    while (y < 200)
    {
        rendererConsole.render(lifeSimulator1);
        lifeSimulator1.update();
        std::cout << std::endl;
        std::this_thread::sleep_for(std::chrono::milliseconds(10));
        y++;
    }

    int z = 0;
    while (z < 200)
    {
        rendererConsole.render(lifeSimulator2);
        lifeSimulator2.update();
        std::cout << std::endl;
        std::this_thread::sleep_for(std::chrono::milliseconds(25));
        z++;
    }
    return 0;
}