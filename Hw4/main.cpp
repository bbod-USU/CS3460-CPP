#include "sortutils.hpp"

#include <random>

SourceArray createRandom();

int main()
{
    auto random = createRandom();

    SourceArray sorted(random);
    std::sort(sorted.begin(), sorted.end());
    SourceArray reversed(sorted);
    std::reverse(reversed.begin(), reversed.end());
    SourceArray organPipe(sorted);
    organPipeStdArray(organPipe);
    SourceArray rotated(sorted);
    std::rotate(rotated.begin(), rotated.begin() + 1, rotated.end());

    // Evaluate functions
    evaluateRawArray(random, sorted, reversed, organPipe, rotated);
    evaluateStdArray(random, sorted, reversed, organPipe, rotated);
    evaluateStdVector(random, sorted, reversed, organPipe, rotated);

    return 0;
}

SourceArray createRandom()
{
    std::random_device rd;
    std::default_random_engine engine(rd());
    std::uniform_int_distribution<int> distribution(-10'000'000, 10'000'000);
    SourceArray random;
    for (int i = 0; i < HOW_MANY_ELEMENTS; i++)
    {
        random[i] = distribution(engine);
    }
    return random;
}