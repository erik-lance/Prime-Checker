# Prime-Checker
 A project for Distributed Computing Course.

# Research Questions to Answer:
- Q1: How does the number of threads affect the performance of a concurrent program?
- Q2: How do the processor's specifications affect the optimal thread count of a concurrent program?
- Q3: Why can introducing too many threads lead to worse performance for a concurrent program than a single-threaded program?

# Tasks
1. Implement user input to specify
    - the upper bound of integers to check (currently set to LIMIT) and
    - the number of threads to use (default=1, i.e., no threading)
2. Implement threading to split the range of integers across the specified number of threads.
3. Implement mutual exclusion for the `primes` list.
4. Implement the computation of the runtime of your algorithm. The timer starts after user input is collected, and the timer stops before printing the number of primes found.
5. Run experiments on the effect of different thread counts on the runtime.
    - Independent Variable: Thread counts are powers of 2, going from 1, 2, 4, ..., 128, 512, 1024.
    - Control Variable: Only check primes from 2 to 10^7. Use the same machine for all experiments.
    - Dependent Variable: Measure the runtime as described above.
    - Run the program for each thread count value 2-3 times to allow the OS to cache the memory locations. Afterward, run the program five times and take the arithmetic mean of the five runs. Tabulate your results and generate a graph visualizing the relationship between the two variables.
6. Reference your results against the physical cores of your machine and the logical cores of your machine.
    - What is the optimal thread count? (If you have different processor specs in the group, consider running the experiment on different machines and comparing the results).
    - At what point does the concurrent program perform worse than a single-threaded program?
    - What are your conclusions about the research questions presented above?