#include <iostream>

using namespace std;

int main()
{
    int LIMIT = 0;
    int n_threads = 1;

    cout << "Enter the upper bound for the prime numbers: ";
    cin >> LIMIT;
    cout << "Enter the number of threads: ";
    cin >> n_threads;

    /**
     * TODO: Threaded Prime Number Finder
     * 1. Implement threading to split the range of integers across the specified number of threads.
     * 2. Implement mutual exclusion for the `primes` list.
     * 3. Implement the computation of the runtime of your algorithm. The timer starts after user input is collected, and the timer stops before printing the number of primes found.
    */

    return 0;
}
