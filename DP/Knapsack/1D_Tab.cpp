

// https://cses.fi/problemset/task/1158/

#include <iostream>
#include <algorithm>

using namespace std;

// Speed
#define Hello_2025 ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);

using ll = long long;

void solve() {
    ll N, W;
    cin >> N >> W;
    ll weight[N + 1], value[N + 1];

    for (ll i = 1; i <= N; i++) {
        cin >> weight[i];
    }
    for (ll i = 1; i <= N; i++) {
      cin >> value[i];
    }

    // 1D DP array: dp[w] will store the maximum value for a given weight capacity w
    ll dp[W + 1] = {0};

    // Process each item
    for (ll i = 1; i <= N; i++) {
        // Update the dp array in reverse order to avoid overwriting values
        for (ll w = W; w >= weight[i]; w--) {
            // dp[w] is the max of either:
            // - not taking the item: dp[w]
            // - taking the item: dp[w - weight[i]] + value[i]
            dp[w] = max(dp[w], dp[w - weight[i]] + value[i]);
        }
    }

    // The answer will be in dp[W], which is the maximum value with full capacity W
    cout << dp[W] << endl;
}

int main() {
    Hello_2025
    solve();
    return 0;
}
