#include <iostream>
#include <map>
#include <unistd.h>

std::map<unsigned long long,unsigned long long> memoization;

unsigned long long fibonacci_simples(unsigned long long);
unsigned long long fibonacci_recursivo(unsigned long long);
unsigned long long fibonacci_memorizacao(unsigned long long);

int main()
{
	unsigned long long n = 0;
	unsigned long long fib = 0;

	clock_t start, end;

	for (unsigned long long n = 2; n <= 30; n++) {
		start = clock();
		fib = fibonacci_simples(n-1);
		end = clock();
		std::cout << (((float)(end - start))/CLOCKS_PER_SEC) << std::endl;
//		std::cout << fib << ',' << n << ',' << (((float)(end - start))/CLOCKS_PER_SEC) << std::endl;
//		std::cout << "Simples\t\t(" << n << ") = " << fib << " in " << (((float)(end - start))/CLOCKS_PER_SEC) << " seconds" << std::endl;
//
		start = clock();
		fib = fibonacci_recursivo(n);
		end = clock();
		std::cout << (((float)(end - start))/CLOCKS_PER_SEC) << std::endl;
//		std::cout << fib << ',' << n << ',' << (((float)(end - start))/CLOCKS_PER_SEC) << std::endl;
//
		start = clock();
		fib = fibonacci_memorizacao(n-1);
		end = clock();
		std::cout << (((float)(end - start))/CLOCKS_PER_SEC) << std::endl;
//		std::cout << "Memorização\t(" << n << ") = " << fib << " in " << (((float)(end - start))/CLOCKS_PER_SEC) << " seconds" << std::endl << std::endl;
	}

    return 0;
}

unsigned long long fibonacci_simples(unsigned long long n)
{
    unsigned long long fib_number = 0;

    unsigned long long a_0 = 1;
    unsigned long long a_1 = 1;
    for (unsigned long long i = n; n > 0; n--) {
        fib_number = a_0 + a_1;

        a_0 = a_1;
        a_1 = fib_number;
    }

    return fib_number;
}

unsigned long long fibonacci_recursivo(unsigned long long n)
{
    if (n == 1 || n == 0) {
        return 1;
    }

    return fibonacci_recursivo(n-1) + fibonacci_recursivo(n-2);
}

unsigned long long fibonacci_memorizacao(unsigned long long n)
{
	if (n == 1 || n == 0) {
		return 1;
	}

	auto it = memoization.find(n);
	if (it != memoization.end()) {
		return memoization.at(n);
	}

	unsigned long long fib_number = fibonacci_memorizacao(n-1) + fibonacci_memorizacao(n-2);
	memoization[n] = fib_number;

    return fib_number;
}
