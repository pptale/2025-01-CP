#include <bits/stdc++.h>
#include <vector>
#define ll long long
#define pb push_back

using namespace std;

// function to calculate max number of customers in a restaurant at any given time
ll customers(vector <ll> arrival, vector <ll> depart, int n){
    sort(arrival.begin(), arrival.end());
    sort(depart.begin(), depart.end());
    ll a = 0, d = 0, curr_customers = 0, max_customers = 0;
    
    while(a<n && d<n){

        //if current arrival time is less than current depart time, increase curr customer by 1, 
        //else decrease by 1 and increase the pointer in resp vector by 1
        if (arrival[a] < depart[d]){
            curr_customers += 1;
            max_customers = max(max_customers, curr_customers);
            a+=1;
        }
        else{
            curr_customers -= 1;
            d+=1;
        }
    }

    return max_customers;
}


int main(){
    int t;
    cin >> t;
    vector <ll> answer;
        
    for(int i = 0; i<t; i++){
        int n;
        cin >> n;
        vector <ll> arrival(n,0), depart(n,0);
        
        for(int j=0; j<n; j++){
            cin >> arrival[j] >> depart[j];        
        }

        answer.pb(customers(arrival, depart, n));
    }

    cout << "20001\t Donald Knuth\n";
    
    // printing max current customers for all test cases
    for (auto i: answer){
        cout << i << endl;
    }

    return 0;
}



// // CSES Website submission code
// #include <bits/stdc++.h>
// #include <vector>
// #define ll long long
// #define pb push_back

// using namespace std;

// ll solve(vector <ll> arrival, vector <ll> depart, int n){
//     sort(arrival.begin(), arrival.end());
//     sort(depart.begin(), depart.end());
//     ll a = 0, d = 0, curr_customers = 0, max_customers = 0;
    
//     while(a<n && d<n){
//         if (arrival[a] < depart[d]){
//             curr_customers += 1;
//             max_customers = max(max_customers, curr_customers);
//             a+=1;
//         }
//         else{
//             curr_customers -= 1;
//             d+=1;
//         }
//     }

//     return max_customers;
// }


// int main(){
//     int n;
//     cin >> n;
//     ll ans;
//     vector <ll> arrival(n,0), depart(n,0);
    
//     for(int i=0; i<n; i++){
//         cin >> arrival[i] >> depart[i];        
//     }

//     ans = solve(arrival, depart, n);
//     cout << ans << endl;

//     return 0;
// }