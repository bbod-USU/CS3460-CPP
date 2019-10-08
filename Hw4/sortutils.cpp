//
// Created by Brady Bodily on 10/2/19.
//

#include "sortutils.hpp"

void initializeRawArrayFromStdArray(const std::array<int, HOW_MANY_ELEMENTS>& source, int* dest)
{
    for (int i = 0; i < source.size(); i++)
    {
        dest[i] = source[i];
    }
}

void organPipeStdArray(std::array<int, HOW_MANY_ELEMENTS>& data)
{
    int half = data.size() / 2;
    for (int i = 0; i < half; i++)
    {
        data[half + i] = data[half - (i + 1)];
    }
}

std::chrono::time_point<std::chrono::steady_clock> getTime()
{
    return std::chrono::steady_clock::now();
}

void evaluateRawArray(const SourceArray& random, const SourceArray& sorted, const SourceArray& reversed, const SourceArray& organPipe, const SourceArray& rotated)
{
    int array[HOW_MANY_ELEMENTS];
    std::chrono::milliseconds duration(0);
    std::cout << " ---- Raw Array Performance ----" << std::endl;
    for (int i = 0; i < HOW_MAMY_TIMES; i++)
    {
        initializeRawArrayFromStdArray(random, array);
        auto start = getTime();
        std::sort(array, array + HOW_MANY_ELEMENTS);
        auto end = getTime();
        duration += std::chrono::duration_cast<std::chrono::milliseconds>(end - start);
    }

    std::cout << std::setw(25) << "Random Time "
              << ":  " << duration.count() << "ms" << std::endl;

    duration = std::chrono::milliseconds(0);
    for (int i = 0; i < HOW_MAMY_TIMES; i++)
    {
        initializeRawArrayFromStdArray(sorted, array);
        auto start = getTime();
        std::sort(array, array + HOW_MANY_ELEMENTS);
        auto end = getTime();
        duration += std::chrono::duration_cast<std::chrono::milliseconds>(end - start);
    }
    std::cout << std::setw(25) << "Sorted Time "
              << ":  " << duration.count() << "ms" << std::endl;

    duration = std::chrono::milliseconds(0);
    for (int i = 0; i < HOW_MAMY_TIMES; i++)
    {
        initializeRawArrayFromStdArray(reversed, array);

        auto start = getTime();
        std::sort(array, array + HOW_MANY_ELEMENTS);
        auto end = getTime();
        duration += std::chrono::duration_cast<std::chrono::milliseconds>(end - start);
    }
    std::cout << std::setw(25) << "Reversed Time "
              << ":  " << duration.count() << "ms" << std::endl;

    duration = std::chrono::milliseconds(0);
    for (int i = 0; i < HOW_MAMY_TIMES; i++)
    {
        initializeRawArrayFromStdArray(organPipe, array);

        auto start = getTime();
        std::sort(array, array + HOW_MANY_ELEMENTS);
        auto end = getTime();
        duration += std::chrono::duration_cast<std::chrono::milliseconds>(end - start);
    }
    std::cout << std::setw(25) << "Organ Pipe Time "
              << ":  " << duration.count() << "ms" << std::endl;

    duration = std::chrono::milliseconds(0);
    for (int i = 0; i < HOW_MAMY_TIMES; i++)
    {
        initializeRawArrayFromStdArray(rotated, array);

        auto start = getTime();
        std::sort(array, array + HOW_MANY_ELEMENTS);
        auto end = getTime();
        duration += std::chrono::duration_cast<std::chrono::milliseconds>(end - start);
    }
    std::cout << std::setw(25) << "Rotated Time "
              << ":  " << duration.count() << "ms" << std::endl
              << std::endl;
}

void evaluateStdArray(const SourceArray& random, const SourceArray& sorted, const SourceArray& reversed, const SourceArray& organPipe, const SourceArray& rotated)
{
    std::chrono::milliseconds duration(0);
    std::array<int, HOW_MANY_ELEMENTS> array{};
    std::cout << " ---- std::array Performance ----" << std::endl;

    for (int i = 0; i < HOW_MAMY_TIMES; i++)
    {
        std::copy(random.begin(), random.end(), array.begin());
        auto start = getTime();
        std::sort(array.begin(), array.end());
        auto end = getTime();
        duration += std::chrono::duration_cast<std::chrono::milliseconds>(end - start);
    }
    std::cout << std::setw(25) << "Random Time "
              << ":  " << duration.count() << "ms" << std::endl;
    duration = std::chrono::milliseconds(0);

    for (int i = 0; i < HOW_MAMY_TIMES; i++)
    {
        std::copy(sorted.begin(), sorted.end(), array.begin());
        auto start = getTime();
        std::sort(array.begin(), array.end());
        auto end = getTime();
        duration += std::chrono::duration_cast<std::chrono::milliseconds>(end - start);
    }
    std::cout << std::setw(25) << "Sorted Time "
              << ":  " << duration.count() << "ms" << std::endl;
    duration = std::chrono::milliseconds(0);
    for (int i = 0; i < HOW_MAMY_TIMES; i++)
    {
        std::copy(reversed.begin(), reversed.end(), array.begin());
        auto start = getTime();
        std::sort(array.begin(), array.end());
        auto end = getTime();
        duration += std::chrono::duration_cast<std::chrono::milliseconds>(end - start);
    }
    std::cout << std::setw(25) << "Reversed Time "
              << ":  " << duration.count() << "ms" << std::endl;
    duration = std::chrono::milliseconds(0);
    for (int i = 0; i < HOW_MAMY_TIMES; i++)
    {
        std::copy(organPipe.begin(), organPipe.end(), array.begin());
        auto start = getTime();
        std::sort(array.begin(), array.end());
        auto end = getTime();
        duration += std::chrono::duration_cast<std::chrono::milliseconds>(end - start);
    }
    std::cout << std::setw(25) << "Organ Pipe Time "
              << ":  " << duration.count() << "ms" << std::endl;
    duration = std::chrono::milliseconds(0);
    for (int i = 0; i < HOW_MAMY_TIMES; i++)
    {
        std::copy(rotated.begin(), rotated.end(), array.begin());
        auto start = getTime();
        std::sort(array.begin(), array.end());
        auto end = getTime();
        duration += std::chrono::duration_cast<std::chrono::milliseconds>(end - start);
    }
    std::cout << std::setw(25) << "Rotated Time "
              << ":  " << duration.count() << "ms" << std::endl
              << std::endl;
}

void evaluateStdVector(const SourceArray& random, const SourceArray& sorted, const SourceArray& reversed, const SourceArray& organPipe, const SourceArray& rotated)
{
    std::chrono::milliseconds duration(0);
    std::vector<int> vector(HOW_MANY_ELEMENTS, 0);
    std::cout << " ---- std::vector Performance ----" << std::endl;

    for (int i = 0; i < HOW_MAMY_TIMES; i++)
    {
        std::copy(random.begin(), random.end(), vector.begin());
        auto start = getTime();
        std::sort(vector.begin(), vector.end());
        auto end = getTime();
        duration += std::chrono::duration_cast<std::chrono::milliseconds>(end - start);
    }

    std::cout << std::setw(25) << "Random Time "
              << ":  " << duration.count() << "ms" << std::endl;
    duration = std::chrono::milliseconds(0);

    for (int i = 0; i < HOW_MAMY_TIMES; i++)
    {
        std::copy(sorted.begin(), sorted.end(), vector.begin());
        auto start = getTime();
        std::sort(vector.begin(), vector.end());
        auto end = getTime();
        duration += std::chrono::duration_cast<std::chrono::milliseconds>(end - start);
    }

    std::cout << std::setw(25) << "Sorted Time "
              << ":  " << duration.count() << "ms" << std::endl;
    duration = std::chrono::milliseconds(0);

    for (int i = 0; i < HOW_MAMY_TIMES; i++)
    {
        std::copy(reversed.begin(), reversed.end(), vector.begin());
        auto start = getTime();
        std::sort(vector.begin(), vector.end());
        auto end = getTime();
        duration += std::chrono::duration_cast<std::chrono::milliseconds>(end - start);
    }

    std::cout << std::setw(25) << "Reversed Time "
              << ":  " << duration.count() << "ms" << std::endl;
    duration = std::chrono::milliseconds(0);

    for (int i = 0; i < HOW_MAMY_TIMES; i++)
    {
        std::copy(organPipe.begin(), organPipe.end(), vector.begin());
        auto start = getTime();
        std::sort(vector.begin(), vector.end());
        auto end = getTime();
        duration += std::chrono::duration_cast<std::chrono::milliseconds>(end - start);
    }

    std::cout << std::setw(25) << "Organ Pipe Time "
              << ":  " << duration.count() << "ms" << std::endl;
    duration = std::chrono::milliseconds(0);

    for (int i = 0; i < HOW_MAMY_TIMES; i++)
    {
        std::copy(rotated.begin(), rotated.end(), vector.begin());
        auto start = getTime();
        std::sort(vector.begin(), vector.end());
        auto end = getTime();
        duration += std::chrono::duration_cast<std::chrono::milliseconds>(end - start);
    }
    std::cout << std::setw(25) << "Rotated Time "
              << ":  " << duration.count() << "ms" << std::endl;
}
