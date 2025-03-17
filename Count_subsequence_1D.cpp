#include <bits/stdc++.h>
using namespace std;

long long int countWays(string s1, string s2) {
    long long int n = s1.length(), m = s2.length();
    vector<long long int> dp(m + 1, 0);
    
    // Base case: dp[0] = 1 because there's one way to match an empty string
    dp[0] = 1;
    
    for (int i = 1; i <= n; i++) {
        // Traverse the dp array from left to right (front to back)
        for (int j = 1; j <= m; j++) {
            if (s1[i - 1] == s2[j - 1]) {
                dp[j] = dp[j] + dp[j - 1];  // Update the number of ways
            }
        }
    }
    
    return dp[m];
}

int main() {
    string s1;
    long long int n;
    cin >> n >> s1;
    string s2 = "NSUPS";
    cout << countWays(s1, s2) << endl;
    return 0;
}
