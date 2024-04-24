#include <iostream>
#include <vector>

using namespace std;

bool isSubsetSum(const vector<int>& set, int sum) {
    int n = set.size();
    vector<vector<bool>> dp(n + 1, vector<bool>(sum + 1, false));

    // Base case: an empty set can only have a sum of 0
    for (int i = 0; i <= n; ++i) {
        dp[i][0] = true;
    }

    // Fill the dp table
    for (int i = 1; i <= n; ++i) {
        for (int j = 1; j <= sum; ++j) {
            if (j < set[i - 1]) {
                // If the current element is greater than the current sum, it cannot be included
                dp[i][j] = dp[i - 1][j];
            } else {
                // Include or exclude the current element
                dp[i][j] = dp[i - 1][j] || dp[i - 1][j - set[i - 1]];
            }
        }
    }

    // Return the value in the bottom-right corner of the dp table
    return dp[n][sum];
}

int main() {
    int n;
    cout << "Enter the number of elements in the set: ";
    cin >> n;

    vector<int> set(n);
    cout << "Enter the elements of the set: ";
    for (int i = 0; i < n; ++i) {
        cin >> set[i];
    }

    int sum;
    cout << "Enter the target sum: ";
    cin >> sum;

    if (isSubsetSum(set, sum)) {
        cout << "Yes, there exists a subset with the given sum." << endl;
    } else {
        cout << "No, there is no subset with the given sum." << endl;
    }

    return 0;
}
