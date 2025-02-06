#include <bits/stdc++.h>
#include <vector>
#define ll long long
#define INF 1e10

using namespace std;

// function to calculate minimum no of steps
ll min_steps(int n){
    vector <ll> arr(n+1, INF);
    arr[0] = 0; // initialization so that if number is 0, it returns 0

    // arr[i] = minimum no of steps required to get number at index i to 0
    for (int i=1; i<=n; i++){
        int temp = i;
        while(temp>=1){
            int d = temp % 10;
            arr[i] = min(arr[i], arr[i-d]+1);

            temp /= 10;
        }
    }

    return arr[n]; //return the steps required for number "n" to get to 0
}

int main(){
    int t;
    cin >> t;
    vector <ll> answer(t,0); // initializing answer vector of size t, such that all elements are 0

    for (int i=0; i<t; i++){
        int n;
        cin >> n;

        answer[i] = min_steps(n); // replacing the req. steps at test case number index in answer vector
    }

    cout << "20001\t Donald Knuth\n";
    
    // printing minimum steps required for all test cases
    for (auto i: answer){
        cout << i << endl;
    }
    return 0;
}


// // CSES Website submission code
// #include <bits/stdc++.h>
// #include <vector>
// #define ll long long
// #define INF 1e10

// using namespace std;

// ll min_steps(int n){
//     vector <ll> arr(n+1, INF);
//     arr[0] = 0;

//     for (int i=1; i<=n; i++){
//         int temp = i;
//         while(temp>=1){
//             int d = temp % 10;
//             arr[i] = min(arr[i], arr[i-d]+1);

//             temp /= 10;
//         }
//     }

//     return arr[n];
// }

// int main(){
//     int n;
//     cin >> n;

//     ll ans;
//     ans = min_steps(n); 

//     cout << ans << endl;

//     return 0;
// }