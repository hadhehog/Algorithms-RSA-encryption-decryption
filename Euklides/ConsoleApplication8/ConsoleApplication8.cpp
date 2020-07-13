#include <iostream>

using namespace std;

int NWD(int a, int b) {
	if (b > a)
		swap(a, b);
	int amount, t;
	do {
		amount = a / b;
		t = (a - amount * b);

		cout << a << " = " << amount << "*" << b;
		cout << " + " << (a - amount * b) << endl;
		a = b;
		b = t;
	} while (b != 0);
	return a;
}

int main() {
	int a, b;

	cout << "Enter a and b: " << endl;
	cin >> a >> b;

	int nwd = NWD(a, b);
	cout << "NWD(" << a << ", " << b << ") = " << nwd << endl;
	system("pause");
	return 0;
}