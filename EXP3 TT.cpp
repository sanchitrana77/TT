#include <bits/stdc++.h>
#include <vector>

using namespace std;

int equalStacks(vector<int>& h1, vector<int>& h2, vector<int>& h3) {
    int n1 = h1.size();
    int n2 = h2.size();
    int n3 = h3.size();
    for (int i = n1 - 2; i >= 0; --i) {
        h1[i] += h1[i + 1];
    }

    for (int i = n2 - 2; i >= 0; --i) {
        h2[i] += h2[i + 1];
    }

    for (int i = n3 - 2; i >= 0; --i) {
        h3[i] += h3[i + 1];
    }

    for (int i = 0; i < n1; ++i) {
        for (int j = 0; j < n2; ++j) {
            for (int k = 0; k < n3; ++k) {
                if (h1[i] == h2[j] && h1[i] == h3[k]) {
                    return h1[i];
                }
            }
        }
    }

    return 0; 
}

int main() {
    vector<int> h1 = {3, 2, 1, 1, 1};
    vector<int> h2 = {4, 3, 2};
    vector<int> h3 = {1, 1, 4, 1};

    int result = equalStacks(h1, h2, h3);
    cout << "Maximum possible height of equal stacks: " << result << endl;

    return 0;
}
