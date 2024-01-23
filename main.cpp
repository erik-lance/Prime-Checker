#include <iostream>

// Constants
const int MAX_LIMIT = 1000000000;
const int MAX_THREADS = 100;

// Function prototypes
int validate_inputs(int limit, int threads);

int main()
{
    int LIMIT = 0;
    int n_threads = 1;

    std::cout << "Enter the upper bound for the prime numbers: ";
    std::cin >> LIMIT;
    std::cout << "Enter the number of threads: ";
    std::cin >> n_threads;

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
 * This simply checks if the inputs are valid based on the constants defined at the start.
 * @param limit The upper bound for the prime numbers.
 * @param threads The number of threads to use.
 * @return 1 if the inputs are valid, 0 otherwise.
*/
int validate_inputs(int limit, int threads)
{
    if (limit < MAX_LIMIT)
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
