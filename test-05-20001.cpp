/*
Name: Two Knights
Reference: https://cses.fi/problemset/task/1072

Input: There are t test cases. In each test case, 
you are given an integer k.
Your task is to count the number of ways two knights can be placed 
on a k \times k chessboard so that they do not attack each other.

Output: Print the sum of number of ways in each case.
Contributer: Rohan Mehra
git: rohmeh
*/

#include <iostream>
#include <vector>
using namespace std;

int main() {    
    int t;
    cin >> t;   
    long long sum_ways = 0;
    
    while(t--) {
        int k;
        cin >> k;
        
        // Total ways to place 2 knights
        long long total = ((long long)k * k * (k * k - 1)) / 2;
        
        // Number of positions where knights attack each other
        long long attack = 4LL * (k - 1) * (k - 2);

        sum_ways += (total - attack);
    }

    cout << "20001\t" << "Donald Knuth\t" << sum_ways <<"\n";
    return 0;
}