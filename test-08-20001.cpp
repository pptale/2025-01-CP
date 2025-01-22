/*
Name: Tower of Hanoi
Reference: https://cses.fi/problemset/task/2165

The Tower of Hanoi game consists of three stacks (left, middle and right)
and n round disks of different sizes.
Initially, the left stack has all the disks, 
in increasing order of size from top to bottom.
The goal is to move all the disks to the right stack 
using the middle stack. 
On each move you can move the uppermost disk from a stack 
to another stack.
In addition, it is not allowed to place a larger disk on a smaller disk.
Your task is to find a solution that minimizes the number of moves.

Input: There are t test cases. In each test case, you are given an intger n.

Output: For each case, first print an integer k: the minimum number of moves.
After this, print k lines that describe the moves. 
Each line has two integers a and b: you move a disk from stack a to stack b. 
*/

#include <iostream>
#include <cmath> // For using pow function
using namespace std;

int toh_steps(int n) {
    return pow(2, n) - 1;
}

void print_toh(int n, int from_stack, int using_stack, int to_stack) {
    /**
     * Keep in mind the position of the stacks
     */
    if (n == 1) {
        cout << from_stack << " " << to_stack << "\n";
        return;
    }

    print_toh(n - 1, from_stack, to_stack, using_stack);
    cout << from_stack << " " << to_stack << "\n";
    print_toh(n - 1, using_stack, from_stack, to_stack);
}

int main() {    
    int n;
    cin >> n;   
    long long num_steps = toh_steps(n);
    
    //Critical line
    cout << "20001\t" << "Donald Knuth\t" << num_steps <<"\n";
    print_toh(n, 1, 2, 3); // Prints the steps in order
    return 0;
}
