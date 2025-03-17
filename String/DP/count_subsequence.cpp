// https://www.geeksforgeeks.org/problems/find-number-of-times-a-string-occurs-as-a-subsequence3020/1
// https://toph.co/p/find-nsups

#include <bits/stdc++.h>
using namespace std;

long long int countWays(string s1, string s2) {
    long long int n = s1.length(), m = s2.length();
    vector<vector<long long int>> dp(n + 1, vector<long long int>(m + 1, 0));
    
    for (int i = 0; i <= n; i++)  dp[i][0] = 1;
    
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            if (s1[i - 1] == s2[j - 1])
                dp[i][j] = (dp[i - 1][j - 1] + dp[i - 1][j]);
            else
                dp[i][j] = dp[i - 1][j];
        }
    }
    
    return dp[n][m];
}

int main() {
    string s1;
    long long int n;
    cin >>n>>s1;
    string s2 = "NSUPS";
    cout << countWays(s1, s2) << endl;
    return 0;
}
