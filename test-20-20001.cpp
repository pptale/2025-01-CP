#include <bits/stdc++.h>

#define ll long long
#define mod 1000000007
#define pb push_back

using namespace std;

// Function to find the number of unique paths from top-left (0,0) to bottom-right (n-1,n-1)
ll number_of_paths(int n, vector <string> grid){

    // Initializing a 2D vector to store the number of paths to reach each cell
    vector <vector <ll>> paths(n, vector <ll> (n, 0));

    // Base Case: If the starting cell is not trapped, set paths[0][0] = 1
    if(grid[0][0] != '*'){
        paths[0][0] = 1;
    }
    else{
        paths[0][0] = 0;
    }

    // Dynamic Programming approach to fill the paths matrix
    for (int i = 0; i < n; i++){
        for (int j = 0; j < n; j++){

            // Only process the cell if it's not trapped
            if (grid[i][j] != '*'){
                
                // If the cell above (i-1, j) is not trapped, add its number of paths
                if (i - 1 >= 0 && grid[i-1][j] != '*'){
                    paths[i][j] = (paths[i][j] + paths[i-1][j]) % mod;
                }

                // If the cell to the left (i, j-1) is not trapped, add its number of paths
                if (j - 1 >= 0 && grid[i][j-1] != '*'){
                     paths[i][j] = (paths[i][j] + paths[i][j-1]) % mod;
                }
            }
        }
    }
    
    // Return the number of paths to reach the bottom-right corner (n-1, n-1)
    return paths[n-1][n-1];
}

int main() {
    int n;
    cin >> n;
    ll ans;

    vector <string> grid (n);
    for (int i = 0; i < n; i++){
        cin >> grid[i];
    }
    
    ans = number_of_paths(n, grid);
    cout << ans << endl;

    return 0;
}