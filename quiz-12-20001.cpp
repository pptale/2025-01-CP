#include <iostream>
#include <vector>
#include <cmath>
using namespace std;

// Function to check if a number is prime number
bool isPrime(int n) {
    if (n <= 1) return false;
    for (int i = 2; i * i <= n; ++i) {
        if (n % i == 0) return false;
    }
    return true;
}

// Function to find the largest prime multiple of a number
int largestPrimeMultiple(int n) {
    for (int i = n; i >= 2; --i) {
        if (n % i == 0 && isPrime(i)) {
            return i;
        }
    }
    return -1; // Return -1 if no prime multiple is found (shouldn't happen for n >= 2)
}

int main() {
    cout << "20001 \t" << "Alan Turing \n";
    // Replace 20001 with your Roll Number and Alan Turing by your name.

    int t;
    cin >> t;

    vector<int> testCases(t);
    for (int i = 0; i < t; ++i) {
        cin >> testCases[i];
    }
    
    int sum_largest_prime_factor = 0;

    for (int i = 0; i < t; ++i) {
        sum_largest_prime_factor += largestPrimeMultiple(testCases[i]);
    }
    
    cout << sum_largest_prime_factor;
    cout << endl;

    return 0;
}
