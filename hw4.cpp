/*
Kevin Alvarez
CS 131
Hw 4
*/

//using c++ precoded bernoulli function

#include <iostream>
#include <random>
#include <ctime>
//using ctime in order for random generator to work correctly

int main() {
    std::default_random_engine generator(std::time(0)); // use current time as seed for random generator
    std::uniform_real_distribution<double> p_distribution(0.0, 1.0);
    std::bernoulli_distribution bernoulli_distribution(0.5); // initial probability of 0.5

    double p = p_distribution(generator); // generate a random value for p
    std::cout << "p = " << p << std::endl;
    bernoulli_distribution.param(std::bernoulli_distribution::param_type(p)); // set the initial probability for the Bernoulli distribution

    std::cout << "Bernoulli distribution: ";
    for (int i = 0; i < 10; ++i) {
        bool outcome = bernoulli_distribution(generator);
        std::cout << outcome << " ";
    }
    std::cout << std::endl;

    return 0;
}

/*
Test 1:
p = 0.701069
Bernoulli distribution: 1 1 0 0 1 0 1 1 1 1 

Test 2: 
p = 0.126232
Bernoulli distribution: 0 0 0 0 0 1 0 0 0 0 

Test 3:
p = 0.891524
Bernoulli distribution: 1 0 1 1 1 1 1 0 1 1 

Test 4:
p = 0.486291
Bernoulli distribution: 1 1 1 1 0 0 1 1 1 0 

Test 5:
p = 0.591713
Bernoulli distribution: 0 1 1 0 1 1 1 1 0 1 
*/