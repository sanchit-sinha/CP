/**
 *    author:  tourist
 *    created: 23.01.2022 15:02:47
**/
#include <bits/stdc++.h>

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n;
    cin >> n;
    vector<vector<int>> a(2 * n, vector<int>(2 * n));
    for (int i = 0; i < 2 * n; i++) {
        for (int j = i + 1; j < 2 * n; j++) {
            cin >> a[i][j];
        }
    }
    vector<bool> used(2 * n, false);
    int ans = 0;
    function<void(int)> Dfs = [&](int w) {
        int i = 0;
        while (i < 2 * n && used[i]) {
            ++i;
        }
        if (i == 2 * n) {
            ans = max(ans, w);
            return;
        }
        for (int j = i + 1; j < 2 * n; j++) {
            if (!used[j]) {
                used[i] = used[j] = true;
                Dfs(w ^ a[i][j]);
                used[i] = used[j] = false;
            }
        }
    };
    Dfs(0);
    cout << ans << '\n';
    return 0;
}
