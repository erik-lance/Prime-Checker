#include <iostream>
#include <chrono>
#include <string>
#include <thread>
#include <vector>
#include <mutex>

// Constants
const int MAX_LIMIT = 10000000;
const int MAX_THREADS = 1024;

// Function prototypes
int user_input(int &limit, int &threads);
int validate_inputs(int limit, int threads);
bool is_prime(int n);

// Mutex
std::mutex mtx;

// Thread Object
class thread_obj
{
	public:
		int start;
		int end;
		std::vector<int> &curPrimes;
		std::mutex &mtx;
		
		// Constructor
		thread_obj(int start, int end, std::vector<int> &curPrimes, std::mutex &mtx) : start(start), end(end), curPrimes(curPrimes), mtx(mtx) {}
		
		void run()
		{
			// Find Primes
			for (int i = start; i <= end; i++)
			{
				if (is_prime(i))
				{
					// Add to primes list
					mtx.lock();
					curPrimes.push_back(i);
					mtx.unlock();
				}
			}
		}
};

int main()
{
	int LIMIT = 0;
	int n_threads = 1;
	std::vector<int> primes;

	// Get user input
	if (!user_input(LIMIT, n_threads))
		return 0;

	// Input validation
	if (!validate_inputs(LIMIT, n_threads))
		return 0;

	/**
	 * TODO: Threaded Prime Number Finder
	 * 1. Implement threading to split the range of integers across the specified number of threads.
	 * 2. Implement mutual exclusion for the `primes` list.
	 * 3. Implement the computation of the runtime of your algorithm. The timer starts after user input is collected, and the timer stops before printing the number of primes found.
	 */

	// Start timer
	auto start = std::chrono::high_resolution_clock::now();

	// Create vector of thread objects
	std::vector<thread_obj> threads;
	
	// Create threads
	for (int i = 0; i < n_threads; i++)
	{
		int start = (LIMIT / n_threads) * i;
		int end = (LIMIT / n_threads) * (i + 1) - 1;
		threads.push_back(thread_obj(start, end, primes, mtx));
	}

	// Start threads
	for (int i = 0; i < n_threads; i++)
	{
		threads[i].run();
	}
	

	// End timer
	auto end = std::chrono::high_resolution_clock::now();

	// Print the number of primes found
	std::cout << "Found " << primes.size() << " prime numbers" << std::endl;

	// Print the runtime
	std::cout << "Runtime: " << std::chrono::duration_cast<std::chrono::milliseconds>(end - start).count() << "ms" << std::endl;

	return 0;
}

/**
 * This function collects the user input for the upper bound and number of threads.
 * @param limit The upper bound for the prime numbers.
 * @param threads The number of threads to use.
 * @return 1 if the inputs are valid, 0 otherwise.
 */
int user_input(int &limit, int &threads)
{
	std::string input;

	std::cout << "Enter the upper bound for the prime numbers: ";
	std::getline(std::cin, input);
	if (input.empty())
	{
		std::cerr << "No input provided" << std::endl;
		return 0;
	}
	else
	{
		try
		{
			limit = std::stoi(input);
		}
		catch (std::invalid_argument &e)
		{
			std::cerr << "Invalid input provided" << std::endl;
			return 0;
		}
	}

	std::cout << "Enter the number of threads: ";
	std::getline(std::cin, input);
	if (input.empty())
	{
		std::cerr << "No input provided" << std::endl;
		return 0;
	}
	else
	{
		try
		{
			threads = std::stoi(input);
		}
		catch (std::invalid_argument &e)
		{
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
		std::cout << "The upper bound must be less than or equal to " << MAX_LIMIT << std::endl;
		return 0;
	}

	if (threads > MAX_THREADS)
	{
		std::cout << "The number of threads must be less than or equal to" << MAX_THREADS << std::endl;
		return 0;
	}

	return 1;
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