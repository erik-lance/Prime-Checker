#include <iostream>

using namespace std;

// Constants
#define MAX_LIMIT 1000000000
#define MAX_THREADS 100

int main()
{
    int LIMIT = 0;
    int n_threads = 1;

    cout << "Enter the upper bound for the prime numbers: ";
    cin >> LIMIT;
    cout << "Enter the number of threads: ";
    cin >> n_threads;

    // Input validation
    if (LIMIT < MAX_LIMIT)
    {
        cout << "The upper bound must be less than " << MAX_LIMIT << endl;
        return 0;
    }

    if (n_threads > MAX_THREADS)
    {
        cout << "The number of threads must be less than " << MAX_THREADS << endl;
        return 0;
    }

    /**
     * TODO: Threaded Prime Number Finder
     * 1. Implement threading to split the range of integers across the specified number of threads.
     * 2. Implement mutual exclusion for the `primes` list.
     * 3. Implement the computation of the runtime of your algorithm. The timer starts after user input is collected, and the timer stops before printing the number of primes found.
    */

    return 0;
}
