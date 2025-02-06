#include <bits/stdc++.h>

#define ll long long
#define pb push_back
#define MIN 1e-12

using namespace std;

ll solve(int n, int x, vector <pair<ll, ll>> book){
    vector<ll> dp(x + 1, MIN);
    dp[0] = 0;

    for(int j = 0; j < n; j++){
        for(int i = x; i >= book[j].first; i--){ // sum of pages before price of given book is useless in calculations for given book
            // if(book[j].first > i){continue;} // this is needed if we iterate the inner loop till 0
            // else{
                dp[i] = max(dp[i], book[j].second + dp[i-book[j].first]);
            // }
        }
    }

    return dp[x];
}

int main (){
    int n, x;
    cin >> n >> x;
    cin.ignore();

    vector <pair<ll, ll>> book(n);
    string line1;
    getline(cin, line1);
    stringstream ss1(line1);

    string line2;
    getline(cin, line2);
    stringstream ss2(line2);
    
    for (int i = 0; i < n; i++) {
        ss1 >> book[i].first;
        ss2 >> book[i].second;
    }
    sort(book.begin(), book.end());
    
    ll ans;
    ans = solve(n, x, book);
    cout << ans << endl;

    return 0;
}