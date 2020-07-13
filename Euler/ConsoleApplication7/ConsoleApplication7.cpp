#include <iostream>
using namespace std;


unsigned long NWD(unsigned long a, unsigned long b);
unsigned long Euler(unsigned long n, unsigned long tab[]);


void main()
{
	unsigned long n;
	unsigned long* tab;
	unsigned long p;
	char h;

	cout << "Euler's function" << endl;

	cout << "Enter N: " << endl;
	cin >> n;

	tab = new unsigned long[n];


	p = Euler(n, tab);
	cout << "Function's result :" << p << endl;

	cout << "Uncover the numbers :" << endl;
	cout << "Enter D to show series: " << endl;
	cin >> h;

	if (h == 'D' || h == 'd')
	{
		cout << "Series: ";

		for (int i = 0; i < p; i++)
		{
			cout << tab[i] << "\t";

		}
		cout << endl;
	}
}

unsigned long Euler(unsigned long n, unsigned long tab[])
{
	int pom = 0;


	for (int i = 1; i < n; i++)
	{
		if (NWD(i, n) == 1)
		{
			tab[pom] = i;
			pom++;

		}
	}
	return pom;
}


unsigned long NWD(unsigned long a, unsigned long b)
{
	while (a != b) if (a > b) a -= b; else b -= a;
	return(a);
}