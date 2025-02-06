#include <bits/stdc++.h>
#include <vector>
#define ll long long
#define INF 1e10

using namespace std;

// function to find the minimum amount of coins req.
ll min_coins(ll n, ll sum, vector<ll>& coins){
    vector<ll> arr(sum + 1, INF);
    arr[0] = 0; // initialization so that if sum is 0, it returns 0

<<<<<<< HEAD
    // dp[i] = minimum no of coins required to get sum i
=======
    // arr[i] = minimum no of coins required to get sum i
>>>>>>> 3a22fcc0f0f92c261b1c41dea862f06fe059355b
    for (int i = 1; i <= sum; i++) {
        for (int j = 0; j < n; j++) {
            if (coins[j] > i || arr[i - coins[j]] == INF)
                continue; // sum of coins exceeds the req. sum
            else{    
                arr[i] = min(arr[i], arr[i - coins[j]] + 1);
            }
        }
    }
    
    if (arr[sum] != INF)
        return arr[sum]; // returns the minimum no of coins to make required sum 

    return -1; // return -1, if the sum is not possible
}

int main(){
    int t;
    cin >> t;

    int req_coins = 1;

    vector <ll> answer;

	for (int i = 0; i < t; ++i){
        ll sum;
        cin >> sum;
        cin.ignore();

		string line;
		getline(cin, line);
		stringstream ss(line);
        
        vector<ll> coins;
        ll num;
		while (ss >> num){
			coins.push_back(num);
        }
    
		req_coins = min_coins(coins.size(), sum, coins);
		answer.push_back(req_coins);
	}

    cout << "20001\t Donald Knuth\n";
    
    // printing minimum coins for all test cases
    for (auto j: answer){
        cout << j << "\n";
    }

    return 0;
}


// // CSES Website submission code
// #include <bits/stdc++.h>
// #include <vector>
// #define ll long long
// #define INF 1e10

// using namespace std;

// // function to find the minimum amount of coins req.
// ll min_coins(ll n, ll sum, vector<ll>& coins){
//     vector<ll> arr(sum + 1, INF);
//     arr[0] = 0; // initialization so that if sum is 0, it returns 0

<<<<<<< HEAD
//     // dp[i] = minimum no of coins required to get sum i
=======
//     // arr[i] = minimum no of coins required to get sum i
>>>>>>> 3a22fcc0f0f92c261b1c41dea862f06fe059355b
//     for (int i = 1; i <= sum; i++) {
//         for (int j = 0; j < n; j++) {
//             if (coins[j] > i || arr[i - coins[j]] == INF)
//                 continue; // sum of coins exceeds the req. sum
//             else{    
//                 arr[i] = min(arr[i], arr[i - coins[j]] + 1);
//             }
//         }
//     }
    
//     if (arr[sum] != INF)
//         return arr[sum]; // returns the minimum no of coins to make required sum 

//     return -1; // return -1, if the sum is not possible
// }

// int main(){
//     int n, sum;
//     cin >> n >> sum;

//     vector<ll> coins(n);
//     ll ans;

//     for (int i = 0; i < n; i++) {
//         cin >> coins[i];
//     }

//     ans = min_coins(n, sum, coins);
//     cout << ans << endl;

//     return 0;
<<<<<<< HEAD
// }
=======
// }
>>>>>>> 3a22fcc0f0f92c261b1c41dea862f06fe059355b
