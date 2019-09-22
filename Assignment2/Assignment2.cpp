#include <iostream>
#include <random>

//
//If the default clang follows the the one true brace style is that not obviously the better brace style???
//
class DistributionPair
{
public:
    DistributionPair(std::uint32_t minValue, std::uint32_t maxValue) :
            minValue(minValue),
            maxValue(maxValue),
            count(0)
    {
    }

    std::uint32_t minValue;
    std::uint32_t maxValue;
    std::uint32_t count;
};


std::vector<DistributionPair> generateUniformDistribution(std::uint32_t howMany, std::uint32_t min, std::uint32_t max, std::uint8_t numberBins);
std::vector<DistributionPair> generateNormalDistribution(std::uint32_t howMany, float mean, float stdev, std::uint8_t numberBins);
std::vector<DistributionPair> generatePoissonDistribution(std::uint32_t howMany, std::uint8_t howOften, std::uint8_t numberBins);
void plotDistribution(std::string title, const std::vector<DistributionPair>& distribution, const std::uint8_t maxPlotLineSize);
std::vector<DistributionPair> createBins (int min, int max, int binCount);

std::random_device randomDevice;
std::default_random_engine randomEngine(randomDevice());


int main() {
    auto uniform = generateUniformDistribution(100000, 0, 79, 40);
    plotDistribution("--- Uniform ---", uniform, 80);

    auto normal = generateNormalDistribution(100000, 50, 5, 40);
    plotDistribution("--- Normal ---", normal, 80);

    auto poisson = generatePoissonDistribution(100000, 6, 40);
    plotDistribution("--- Poisson ---", poisson, 80);
    return 0;
}


std::vector<DistributionPair> generateUniformDistribution(std::uint32_t howMany, std::uint32_t min, std::uint32_t max, std::uint8_t numberBins){
    std::uniform_int_distribution<int> distribution(min, max);
    auto bins = createBins(min, max, numberBins);
    for(int i = 0; i < howMany; i++){
        int number = distribution(randomEngine);
       bins[number].count ++;

    }
    return bins;
}



std::vector<DistributionPair> generateNormalDistribution(std::uint32_t howMany, float mean, float stdev, std::uint8_t numberBins){
    int min = mean - (4 * stdev);
    int max = mean + (4 * stdev) -1;
    std::normal_distribution<double> distribution(mean, stdev);
    auto bins = createBins(min, max, numberBins);

    for(int i = 0; i < howMany; i++) {
        double number = distribution(randomEngine);
        int position = number - min / ((max - min) / float(numberBins));
        if (position > numberBins - 1)
            bins[numberBins - 1].count++;
        else if (position < 0) {
            bins[0].count++;
        } else {
            bins[position].count++;
        }
    }
    return bins;
}
std::vector<DistributionPair> generatePoissonDistribution(std::uint32_t howMany, std::uint8_t howOften, std::uint8_t numberBins){
    std::poisson_distribution<int> distribution(howOften);
    int min = 0;
    int max = numberBins - 1;
    auto bins = createBins(min, max, numberBins);
    for(int i = 0; i < howMany; i++){
        int number = distribution(randomEngine);
        //int position = number / (max / float(numberBins));
        if (number > numberBins - 1)
            bins[numberBins - 1].count++;
        else if (number < 0) {
            bins[0].count++;
        } else {
            bins[number].count++;
        }

    }
    return bins;

}


std::vector<DistributionPair> createBins (int min, int max, int binCount){
    std::vector<DistributionPair> myVector;
    int difference = float(max - min + 1) / binCount;
    for(int i = 0; i < binCount; i++){
        DistributionPair dpair((min + i) * difference, (min + i) * difference + difference - 1);
        myVector.push_back(dpair);
    }
    return myVector;
}


void plotDistribution(std::string title, const std::vector<DistributionPair>& distribution, const std::uint8_t maxPlotLineSize){
    std::cout << title << std::endl;
    auto max = 0;
    for(auto currentBin : distribution){
        if(currentBin.count > max)
            max = currentBin.count;
    }
    for(auto currentBin : distribution){
        int starCount = currentBin.count / float(max)  * maxPlotLineSize;
        std::cout << "[ " << currentBin.minValue << ", " << currentBin.maxValue << " ]" << " : ";
        for(int i = 0; i < starCount; i++)
            std::cout << "*";
        std::cout << std::endl;
    }
}



