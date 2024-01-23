#include "primes.h"

/**
 * This function finds the number of primes in the range [start, end].
 * @param start The start of the range.
 * @param end The end of the range.
 * @return The number of primes in the range [start, end].
 */
int find_primes(int start, int end)
{
    int count = 0;

    for (int i = start; i <= end; i++)
    {
        if (is_prime(i))
        {
            count++;
        }
    }

    return count;
}

/**
 * This function checks if a number is prime.
 * @param n The number to check.
 * @return true if the number is prime, false otherwise.
 */
bool is_prime(int n)
{
    if (n <= 1) return false;
    if (n <= 3) return true;

    if (n % 2 == 0 || n % 3 == 0) return false;

    for (int i = 5; i * i <= n; i += 6)
    {
        if (n % i == 0 || n % (i + 2) == 0) return false;
    }

    return true;
}