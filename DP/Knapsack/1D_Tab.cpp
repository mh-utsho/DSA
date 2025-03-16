

// https://cses.fi/problemset/task/1158/

#include <iostream>
#include <bits/stdc++.h>
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

    vector<ll>pre(W+1,0);

    // Process each item
    for (ll i = 1; i <= N; i++) {
        vector<ll>cur(W+1,0);
         for (ll w = 0; w <= W; w++) {
            // If we don't take the current item
            cur[w] = pre[w];

            // If we can take the current item (i.e., weight[i] <= w)
            if (w >= weight[i]) {
                cur[w] = max(pre[w], pre[w - weight[i]] + value[i]);
            }
        }
        pre=cur;
    }
   cout << pre[W] << endl;
}

int main() {
    Hello_2025
    solve();
    return 0;
}
