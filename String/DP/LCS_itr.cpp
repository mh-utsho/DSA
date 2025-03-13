#include <bits/stdc++.h>
using namespace std;

#define Hello_2025 ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);

int LCS(string &s, string &t) {
    int n = s.size();
    int m = t.size();
    vector<vector<int>> dp(n + 1, vector<int>(m + 1, 0));
    
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            if (s[i - 1] == t[j - 1]) {
                dp[i][j] = dp[i - 1][j - 1] + 1;
            } else {
                dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
            }
        }
    }
    return dp[n][m];
}

int main() {
    Hello_2025
    string s, t;
    cin >> s >> t;
    cout << LCS(s, t) << endl;
    return 0;
}
