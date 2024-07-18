#include "Recursion.h"

int Recursion::NaturalSum(int n)
{
	if (n == 0) return 0;

	return NaturalSum(n - 1) + n;
}

int Recursion::Factorial(int n)
{
	if(n == 0) return 1;

	return Factorial(n - 1) * n;
}

int Recursion::Exponent(int n, int pow)
{
	if (pow == 0) return 1;

	return n * Exponent(n, pow - 1);
}
