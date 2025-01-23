#include <iostream>
#include <vector>
#include <map>
using namespace std;
using ll = long long;

// Prints indices of the elements according to 1-based indexing
void two_sum_indices(vector<ll> arr, ll n, ll target) {
    if (n == 1) {
        cout << "IMPOSSIBLE" << endl;
        return;
    }

    map<ll, ll> hashmap;
    for (int i = 0; i<n; i++) {
        hashmap[arr[i]] = i;
    }

    for(int i = 0; i<n; i++) {
        if (hashmap.find(target - arr[i]) != hashmap.end() && i != hashmap[target - arr[i]]) {
            cout << i + 1 << " " << hashmap[target - arr[i]] + 1 << endl;
            return;
        }
    }

    cout << "IMPOSSIBLE" << endl;
}

int main() {
    ll n = 0, x = 0;
    cin >> n >> x;
    vector<ll> arr(n);
    for(ll i = 0; i<n; i++) cin >> arr[i];

    cout << "20001 \t" << "Donald Knuth \t";
    two_sum_indices(arr, n, x);
    return 0;
}