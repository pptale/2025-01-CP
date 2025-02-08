#include <bits/stdc++.h>
using namespace std;


/*
Problem name-Minimizing Coins
reference-https://cses.fi/problemset/result/12017528/

In Minimizing Coins problem, we are given a set of n coins , and a target sum of money x , and we are asked to construct the sum x using minimum number of coins. Any coin can be used multiple times.

Input
The first input line has two integers n and x: the number of coins and the desired sum of money.
The second line has n distinct integers c1,c2,.....,cn: the value of each coin.

Output
one integer: the minimum number of coins. If it is not possible to produce the desired sum, print -1.

This question can be solved using Dynamic Programming.
*/




int main() {

    cout << "20001\t" << "Donald Knuth\t" << "Minimizing_coins" <<"\n";
    cout << endl;

    int n; // number of coins
    long long int x; //target sum
    cin >> n >> x;


    vector<long long int> coins(n);
    for (int i = 0; i < n; i++) {
        cin >> coins[i];
    }

    //since in the question the max value of x is 1000000, the infinity is defined as 1000001.
    const long long int INF = 1000001;

    //initialising a vector with a large value except value[0] which is 0(our base case)
    //value[x] is the minimum number of coins that is required to form the sum x 

    vector<long long int> value(x + 1, INF);
    value[0] = 0; //base case

    //we iteratively construct the vector 'value' by recursively calculating from its smaller values , and storing its value.
    for (int j = 1; j <= x; j++) {
        for (int k = 0; k < n; k++) {
            if (j - coins[k] >= 0) {
                value[j] = min(value[j], value[j - coins[k]] + 1);
            }
        }
    }

    //if the value[x] is still INF , it means it cannot be constructed and hence we print -1.
    if (value[x] == INF) {
        cout << -1 << endl;
    } else {
        cout << value[x] << endl;
    }

    return 0;
}

