#include <iostream>
using namespace std;

//(a^n)%p in O(logy)
int power(int a, unsigned int n, int p)
{
	int res = 1;      
	a = a % p;  
	while (n > 0)
	{
		if (n & 1)
			res = (res * a) % p;

		n = n >> 1; 
		a = (a * a) % p;
	}
	return res;
}

/*Recursive function to calculate gcd of 2 numbers*/
int gcd(int a, int b)
{
	if (a < b)
		return gcd(b, a);
	else if (a % b == 0)
		return b;
	else return gcd(b, a % b);
}

bool isPrime(unsigned int n, int k)
{
	// Corner cases 
	if (n <= 1 || n == 4)  return false;
	if (n <= 3) return true;

	while (k > 0)
	{
		int a = 2 + rand() % (n - 4);

		if (gcd(n, a) != 1)
			return false;

		// Fermat's theorem 
		if (power(a, n - 1, n) != 1)
			return false;

		k--;
	}

	return true;
}

int main()
{
	int a, b;

	cout << "Enter A:  ";
	cin >> a;
	cout << "\nEnter B: ";
	cin >> b;

	int k = 3;
	isPrime(a, k) ? cout << " true\n" : cout << " false\n";
	isPrime(b, k) ? cout << " true\n" : cout << " false\n";
	return 0;
}