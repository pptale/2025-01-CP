#include <bits/stdc++.h>

#define ll long long
#define pb push_back

using namespace std;

int main() {
    int n;
    cin >> n;

    ll sum = 0;
    vector<ll> coins(n);

    // Read the coin values and compute the total sum
    for (auto &i : coins) {
        cin >> i;
        sum += i;
    }

    vector<bool> dp(sum + 1, false);  
    dp[0] = true;  // Base case: sum 0 is always possible
    dp[coins[0]] = true;  // The first coin alone can be a valid sum

    // Iterating through the remaining n-1 coins to fill the DP table
    for (int i = 1; i < n; i++) {
        vector<bool> temp = dp;  // Create a temporary copy of dp before updating
        for (int j = 0; j <= sum; j++) {
            if (j - coins[i] >= 0) {  // If the current sum `j` can be formed
                dp[j] = dp[j] || temp[j - coins[i]];  // Update DP table
            }
        }
    }

    vector<ll> possible_sum;

    for (int i = 1; i <= sum; i++) {
        if (dp[i]) {
            possible_sum.pb(i);
        }
    }

    cout << possible_sum.size() << endl;
    for (auto i : possible_sum) {
        cout << i << " ";
    }

    return 0;
}