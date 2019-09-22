#include <iostream>
#include <random>
#include <string>
#include <cstdint>
#include <iomanip>

//
// If the default clang follows the the one true brace style is that not
// obviously the better brace style???
//
class DistributionPair
{
  public:
    DistributionPair(std::uint32_t minValue, std::uint32_t maxValue) :
        minValue(minValue), maxValue(maxValue), count(0) {}

    std::uint32_t minValue;
    std::uint32_t maxValue;
    std::uint32_t count;
};

std::vector<DistributionPair>
generateUniformDistribution(std::uint32_t howMany, std::uint32_t min,
                            std::uint32_t max, std::uint8_t numberBins);
std::vector<DistributionPair>
generateNormalDistribution(std::uint32_t howMany, float mean, float stdev,
                           std::uint8_t numberBins);
std::vector<DistributionPair>
generatePoissonDistribution(std::uint32_t howMany, std::uint8_t howOften,
                            std::uint8_t numberBins);
void plotDistribution(std::string title,
                      const std::vector<DistributionPair>& distribution,
                      const std::uint8_t maxPlotLineSize);
std::vector<DistributionPair> createBins(int min, int max, int binCount);

std::random_device randomDevice;
std::default_random_engine randomEngine(randomDevice());






// ------------------------------------------------------------------
//
// Testing Code
//
// ------------------------------------------------------------------
#include <functional>
#include <iostream>
#include <numeric>
#include <string>

namespace testing::detail
{
using namespace std::string_literals;

using Bins = std::vector<std::pair<std::uint32_t, std::uint32_t>>;
using DistFunc = std::function<std::vector<DistributionPair>()>;

#define CS3460_ASSERT_EQ(expected, actual, message)                    \
    if (expected != actual)                                            \
    {                                                                  \
        fail(message, "[ Expected", expected, "but got", actual, "]"); \
        return;                                                        \
    }

#define CS3460_CASE(x) \
    [] { return x; };  \
    std::cout << " Case " << #x << "\n";

template <typename Message>
void failInternal(const Message& message)
{
  std::cout << message << " ";
}

template <typename Message, typename... Messages>
void failInternal(const Message& message, const Messages&... messages)
{
  failInternal(message);
  failInternal(messages...);
}

template <typename... Messages>
void fail(const Messages&... messages)
{
  std::cout << "  Assertion failed: ";
  failInternal(messages...);
  std::cout << "\n";
}

Bins generateBins(const std::uint32_t min, const std::uint32_t max, const std::uint8_t numberBins)
{
  const auto binRange = (max - min) / numberBins;
  auto minBin = min;
  auto maxBin = min + binRange;

  Bins results(numberBins);
  for (std::uint8_t bin = 0u; bin < numberBins; bin++)
  {
    results[bin] = {minBin, maxBin};
    minBin = maxBin + 1;
    maxBin = minBin + binRange;
  }

  return results;
}

void returnsTheExpectedBins(const DistFunc& func, const Bins& bins)
{
  const auto result = func();
  CS3460_ASSERT_EQ(bins.size(), result.size(), "Wrong number of bins");
  for (auto i = 0u; i < bins.size(); i++)
  {
    CS3460_ASSERT_EQ(bins[i].first, result[i].minValue, "Wrong minimum value for bin "s + std::to_string(i));
    CS3460_ASSERT_EQ(bins[i].second, result[i].maxValue, "Wrong maximum value for bin "s + std::to_string(i));
  }
}

void hasTheCorrectTotalAcrossAllBins(const DistFunc& func, const std::uint32_t howMany)
{
  const auto result = func();
  const auto add_counts = [](std::uint32_t total, const DistributionPair& bin) { return total + bin.count; };
  CS3460_ASSERT_EQ(howMany, std::accumulate(result.cbegin(), result.cend(), 0u, add_counts),
                   "Wrong number of elements across all bins");
}

void testUniformDistribution()
{
  std::cout << "Testing generateUniformDistribution\n";
  auto func = CS3460_CASE(generateUniformDistribution(100000, 0, 79, 40));
  returnsTheExpectedBins(func, generateBins(0, 79, 40));
  hasTheCorrectTotalAcrossAllBins(func, 100000);
}

void testNormalDistribution()
{
  std::cout << "Testing generateNormalDistribution\n";
  auto func = CS3460_CASE(generateNormalDistribution(100000, 50, 5, 40));
  returnsTheExpectedBins(func, generateBins(30, 69, 40));
  hasTheCorrectTotalAcrossAllBins(func, 100000);
}

void testPoissonDistribution()
{
  std::cout << "Testing generatePoissonDistribution\n";
  auto func = CS3460_CASE(generatePoissonDistribution(100000, 6, 40));
  returnsTheExpectedBins(func, generateBins(0, 39, 40));
  hasTheCorrectTotalAcrossAllBins(func, 100000);
}
} // namespace testing::detail

void test()
{
  using namespace testing::detail;

  testUniformDistribution();
  testNormalDistribution();
  testPoissonDistribution();

  std::cout << "\n\n";
}

int main()
{
    auto uniform = generateUniformDistribution(100000, 0, 79, 40);
    plotDistribution("--- Uniform ---", uniform, 80);

    auto normal = generateNormalDistribution(100000, 50, 5, 40);
    plotDistribution("--- Normal ---", normal, 80);

    auto poisson = generatePoissonDistribution(100000, 6, 40);
    plotDistribution("--- Poisson ---", poisson, 80);

    test();
    return 0;
}

std::vector<DistributionPair>
generateUniformDistribution(std::uint32_t howMany, std::uint32_t min,
                            std::uint32_t max, std::uint8_t numberBins)
{
    std::uniform_int_distribution<int> distribution(min, max);
    auto bins = createBins(min, max, numberBins);
    for (int i = 0; i < static_cast<int>(howMany); i++)
    {
        float number = distribution(randomEngine);

        for(int i = 0; i <= numberBins; i++)
        {
            if(bins[i].maxValue >= number && bins[i].minValue <= number)
                bins[i].count++;
        }
    }
    return bins;
}

std::vector<DistributionPair>
generateNormalDistribution(std::uint32_t howMany, float mean, float stdev,
                           std::uint8_t numberBins)
{
    int min = static_cast<int>(mean - (4 * stdev));
    int max = static_cast<int>(mean + (4 * stdev) - 1);
    std::normal_distribution<double> distribution(mean, stdev);
    auto bins = createBins(min, max, numberBins);

    for (int i = 0; i < static_cast<int>(howMany); i++)
    {
        double number = distribution(randomEngine);
        int position =
            static_cast<int>(number - min / ((max - min) / float(numberBins)));
        if (position > numberBins - 1)
            bins[numberBins - 1].count++;
        else if (position < 0)
            bins[0].count++;
        else
            bins[position].count++;
    }
    return bins;
}
std::vector<DistributionPair>
generatePoissonDistribution(std::uint32_t howMany, std::uint8_t howOften,
                            std::uint8_t numberBins)
{
    std::poisson_distribution<int> distribution(howOften);
    int min = 0;
    int max = numberBins - 1;
    auto bins = createBins(min, max, numberBins);
    for (int i = 0; i < static_cast<int>(howMany); i++)
    {
        int number = distribution(randomEngine);
        if (number > numberBins - 1)
            bins[numberBins - 1].count++;
        else if (number < 0)
            bins[0].count++;
        else
            bins[number].count++;
    }
    return bins;
}

std::vector<DistributionPair> createBins(int min, int max, int binCount)
{
    std::vector<DistributionPair> myVector;
    int difference = static_cast<int>(float(max - min + 1) / binCount);
    for (int i = 0; i < binCount; i++)
    {
        DistributionPair dpair((min + i) * difference,
                               (min + i) * difference + difference - 1);
        myVector.push_back(dpair);
    }
    return myVector;
}

void plotDistribution(std::string title,
                      const std::vector<DistributionPair>& distribution,
                      const std::uint8_t maxPlotLineSize)
{
    std::cout << title << std::endl;
    auto max = 0;
    for (auto currentBin : distribution)
    {
        if (static_cast<int>(currentBin.count) > static_cast<int>(max))
            max = currentBin.count;
    }
    for (auto currentBin : distribution)
    {
        int starCount =
            static_cast<int>(currentBin.count / float(max) * maxPlotLineSize);
        std::string info = "[ " + std::to_string(currentBin.minValue) + ", "
            + std::to_string(currentBin.maxValue) + " ] : ";
        std::string starString;
        for (int i = 0; i < starCount; i++)
            starString += "*";
        std::cout << std::setw(15) <<  info << starString;
        std::cout << std::endl;
    }
}
