/*
Farmer John has built a new long barn, with N (2 <= N <= 100,000) stalls. The stalls are located along a straight line at positions x1 ... xN 
(0 <= xi <= 1,000,000,000).His C (2 <= C <= N) cows don't like this barn layout and become aggressive towards each other once put into a stall. 
To prevent the cows from hurting each other, FJ wants to assign the cows to the stalls, such that the minimum distance between any two of them is 
as large as possible. What is the largest minimum distance?

Input
t – the number of test cases, then t test cases follows.
* Line 1: Two space-separated integers: N and C
* Lines 2..N+1: Line i+1 contains an integer stall location, xi

Output
For each test case output one integer: the largest minimum distance.

Example
Input:

1
5 3
1
2
8
4
9
Output:

3

1 3 5 8 10
c=3

Output: 4
1 5 10
*/

#include <bits/stdc++.h>
using namespace std;

// Function to count the number of positions satisfying the distance constraint
int count(vector<int>& position, int d) {
    int ans = 1, last = position[0];
    for (int i = 1; i < position.size(); ++i) {
        if (position[i] - last >= d) {
            ans++;
            last = position[i];
        }
    }
    return ans;
}

// Function to find the maximum distance
int maxDistance(vector<int>& position, int m) {
    sort(position.begin(), position.end());
    int l = 0, r = position.back() - position.front();
    while (l <= r) {
        int mid = r - (r - l) / 2;
        if (count(position, mid) >= m)
            l = mid + 1;
        else
            r = mid - 1;
    }
    return r;
}

int main() { // Fix: Declare `main()` with `int`
    int t;
    cin >> t; // Number of test cases
    while (t--) {
        vector<int> nums;
        int n, x, m;
        cin >> n; // Number of positions
         cin >> m; // Number of elements to place
        for (int i = 0; i < n; i++) {
            cin >> x;
            nums.push_back(x); // Input positions
        }
       
        cout << maxDistance(nums, m) << endl; // Output result
    }
    return 0; // Fix: Explicitly return 0 to indicate successful execution
}