#include <iostream>
using namespace std; 
  
int main() 
{ 
    int a, b, i, j; 
  
    cout << "Enter lower bound of the interval: "; 
    cin >> a;   
    cout << "\nEnter upper bound of the interval: "; 
    cin >> b; 

    cout << "\nPrime numbers between "
         << a << " and " << b << " are: "; 
  
    // Explicitly handling the cases when a is less than 2 
    if (a == 1) { 
        cout << a << " "; 
        a++; 
        if (b >= 2) { 
            cout << a << " "; 
            a++; 
        } 
    } 
    if (a == 2) 
        cout << a << " "; 
  
    // THE LOOP 
    if (a % 2 == 0) 
        a++; 
  
    for (i = a; i <= b; i = i + 2) { 
  
        bool flag = 1; 

        for (j = 2; j * j <= i; ++j) { 
            if (i % j == 0) { 
                flag = 0; 
                break; 
            } 
        } 
  
        // flag = 1 means i is prime 
        // and flag = 0 means i is not prime 
        if (flag == 1) 
            cout << i << " "; 
    } 
  
    return 0; 
}