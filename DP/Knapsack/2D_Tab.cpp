
// https://atcoder.jp/contests/dp/tasks/dp_d

#include <iostream>
#include <algorithm>

using namespace std;

// Speed
#define Hello_2025 ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);

using ll = long long;

void solve() {
    ll N, W;
    cin >> N >> W;

    // Arrays to store the weights and values of the items
    ll weight[N + 1], value[N + 1];

    // Read the weight and value for each item
    for (ll i = 1; i <= N ; i++) {
        cin >> weight[i] >> value[i];
    }
    ll dp[N + 1][W + 1];

    // Initialize the dp array with 0s
    for (ll i = 0; i <= N; i++) {
        for (ll w = 0; w <= W; w++) {
            dp[i][w] = 0;
        }
    }

    // Process each item
    for (ll i = 1; i <= N; i++) {
        for (ll w = 0; w <= W; w++) {
            // If we don't take the current item
            dp[i][w] = dp[i - 1][w];

            // If we can take the current item (i.e., weight[i] <= w)
            if (w >= weight[i]) {
                dp[i][w] = max(dp[i][w], dp[i - 1][w - weight[i]] + value[i]);
            }
        }
    }

    // The answer will be in dp[N][W], which is the maximum value with N items and weight capacity W
    cout << dp[N][W] << endl;
}

int main() {
    Hello_2025
    solve();
    return 0;
}
