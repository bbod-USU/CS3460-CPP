#include <iostream>
#include <vector>
#include <numeric>
#include <cmath>
#include <stdio.h>

long nbonacci(unsigned int series, unsigned int n);
void computeNbonacciRatio(std::string title, unsigned int series);

int main() {

    std::string fib, trib, fourb, fiveb;

    for (int i = 1; i <= 20; i++){
        fib += " " + std::to_string(nbonacci(2, i));
        trib += " " + std::to_string(nbonacci(3, i));
        fourb += " " + std::to_string(nbonacci(4, i));
        fiveb += " " + std::to_string(nbonacci(5, i));
    }

    std::cout << "---Fibonacci Sequence---" << std::endl << fib << std::endl;
    std::cout << "---Tribonacci Sequence---" << std::endl << trib << std::endl;
    std::cout << "---Fourbonacci Sequence---" << std::endl << fourb << std::endl;
    std::cout << "---Fivebonacci Sequence---" << std::endl << fiveb << std::endl;

    std::cout << std::endl << std::endl << std::endl;

    computeNbonacciRatio("Fibonacci Sequence ", 2);
    computeNbonacciRatio("Tribonacci Sequence ", 3);
    computeNbonacciRatio("Fourbonacci Sequence ", 4);
    computeNbonacciRatio("Fivebonacci Sequence ", 5);

    return 0;
}

long nbonacci(unsigned int series, unsigned int n){
    if(n < series + 1) return 1;
    else {
        long sum = 0;
        for (int i = series; i > 0; i--) {
            sum += nbonacci(series, n - i);
        }
        return sum;
    }


}

void computeNbonacciRatio(std::string title, unsigned int series){
    int i = 0;
    double last = series, current = series;
    while(std::abs(last-current) >  0.000001 || current - last == 0){
        i++;
        last = current;
        current = static_cast<double>(nbonacci(series,
                                               (unsigned int) (i + 1))) / static_cast<double>(nbonacci(series, (unsigned int) i));
    }
    std::cout<< title << "approaches " << current << " after " << i << " iterations." << std::endl;
}