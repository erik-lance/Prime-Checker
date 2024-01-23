#include <iostream>
#include<string>
#include <thread>
#include "primes.h"

// Constants
const int MAX_LIMIT = 1000000000;
const int MAX_THREADS = 100;

// Function prototypes
int user_input(int& limit, int& threads);
int validate_inputs(int limit, int threads);
int main()
{
    int LIMIT = 0;
    int n_threads = 1;
    
    // Get user input
    if (!user_input(LIMIT, n_threads)) return 0;

    // Input validation
    if (!validate_inputs(LIMIT, n_threads)) return 0;

    /**
     * TODO: Threaded Prime Number Finder
     * 1. Implement threading to split the range of integers across the specified number of threads.
     * 2. Implement mutual exclusion for the `primes` list.
     * 3. Implement the computation of the runtime of your algorithm. The timer starts after user input is collected, and the timer stops before printing the number of primes found.
    */

    return 0;
}

/**
 * This function collects the user input for the upper bound and number of threads.
 * @param limit The upper bound for the prime numbers.
 * @param threads The number of threads to use.
 * @return 1 if the inputs are valid, 0 otherwise.
*/
int user_input(int& limit, int& threads)
{
    std::string input;

    std::cout << "Enter the upper bound for the prime numbers: ";
    std::getline(std::cin, input);
    if (input.empty()) {
        std::cerr << "No input provided" << std::endl;
        return 0;
    } else {
        try {
            limit = std::stoi(input);
        } catch (std::invalid_argument& e) {
            std::cerr << "Invalid input provided" << std::endl;
            return 0;
        }
    }

    std::cout << "Enter the number of threads: ";
    std::getline(std::cin, input);
    if (input.empty()) {
        std::cerr << "No input provided" << std::endl;
        return 0;
    } else {
        try {
            threads = std::stoi(input);
        } catch (std::invalid_argument& e) {
            std::cerr << "Invalid input provided" << std::endl;
            return 0;
        }
    }

    return 1;
}

/**
 * This simply checks if the inputs are valid based on the constants defined at the start.
 * @param limit The upper bound for the prime numbers.
 * @param threads The number of threads to use.
 * @return 1 if the inputs are valid, 0 otherwise.
*/
int validate_inputs(int limit, int threads)
{
    if (limit > MAX_LIMIT)
    {
        std::cout << "The upper bound must be less than " << MAX_LIMIT << std::endl;
        return 0;
    }

    if (threads > MAX_THREADS)
    {
        std::cout << "The number of threads must be less than " << MAX_THREADS << std::endl;
        return 0;
    }

    return 1;
}