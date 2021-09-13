#include "bits/stdc++.h"
using namespace std;
#define ll long long
const ll N = 1e5 + 11;
long highestProfit(int n, vector <long> arr, long tot) {
    vector<ll> cnt(N, 0ll);
    for (int i = 0; i < n; i++) {
        cnt[arr[i]]++;
    }

    ll ans = 0ll;
    for (ll i = N - 1; i >= 1; i--) {
        if (tot <= cnt[i]) {
            ans += i * tot;
            tot = 0;
            break;
        }
        else {
            ans += i * cnt[i];
            cnt[i - 1] += cnt[i];
            tot -= cnt[i];
            cnt[i] = 0;
        }
    }
    return ans;
}
int main() {
    int n;
    cin >> n;

    vector<long> a;
    for (int i = 0; i < n; i++) {
        long x;
        cin >> x;

        a.push_back(x);
    }

    ll tot;
    cin >> tot;

    cout << highestProfit(n, a, tot) << "\n";
}

