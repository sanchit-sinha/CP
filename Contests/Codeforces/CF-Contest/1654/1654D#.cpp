// jai ganeshdeva 
#include <bits/stdc++.h>
#define i64 long long

using namespace std;

const i64 MOD = 998244353;


/* template for modular arithmetic */
i64 modexp(i64 a, i64 b, i64 md) {
    assert(b >= 0);
    i64 x = a, res = 1LL, p = b;
    while (p > 0) {
        if (p & 1) res *= x;
        x *= x;
        p >>= 1;
        res %= md;
        x %= md;
    }
    return res;
}
struct mint {
    i64 val;

    mint(i64 _val = 0) {
        val = _val % MOD;
        if (val < 0) val += MOD;
    }

    mint operator+ (mint other) const {
        return mint(val + other.val);
    }

    mint operator- (mint other) const {
        return mint(val - other.val);
    }
    void operator+= (mint other) {
        val += other.val;
        val %= MOD;
    }

    mint operator- () const {
        return mint(-val);
    }

    void operator-= (mint other) {
        val += MOD - other.val;
        val %= MOD;
    }

    mint operator* (mint other) const {
        return mint(val * other.val);
    }

    void operator*= (mint other) {
        val *= other.val;
        val %= MOD;
    }

    bool operator== (mint other) const {
        return val == other.val;
    }

    bool operator!= (mint other) const {
        return val != other.val;
    }

    mint operator/ (mint other) const {
        i64 p = modexp(other.val, MOD - 2, MOD);
        p *= val;
        p %= MOD;
        return mint(p);
    }

    void operator/= (mint other) {
        i64 p = modexp(other.val, MOD - 2, MOD);
        p *= val;
        p %= MOD;
        val = p;
    }

    mint pow(int M) {
        return mint(modexp(val, M, MOD));
    }
};

ostream& operator<< (ostream& out, mint p) {
    out << p.val;
    return out;
}



#define SIEVE
const int MAXN = 1e6 + 7;
int lp[MAXN + 1];
vector<int> pr;

void construct() {
    for (int i = 2; i <= MAXN; i++) {
        if (lp[i] == 0) {
            lp[i] = i;
            pr.push_back(i);
        }
        for (int j = 0; j < (int)pr.size() && pr[j] <= lp[i] && i * pr[j] <= MAXN; ++j) {
            lp[i * pr[j]] = pr[j];
        }
    }
}

vector<pair<int, int>> factorize(int num) {
    vector<pair<int, int>> factors;
    while (num != 1) {
        int mnDiv = lp[num];
        int c = 0;
        while (num % mnDiv == 0) {
            num /= mnDiv;
            c++;
        }
        factors.emplace_back(mnDiv, c);
    }
    return factors;
}


const int M = 2e5 + 7;
int tot[M], mn[M];
void solve() {
    int n;
    cin >> n;
    vector<vector<pair<pair<int, int>, int>>> g(n + 1);
    for (int i = 0; i < n - 1; i++) {
        int ii, jj, xx, yy;
        cin >> ii >> jj >> xx >> yy;
        g[ii].push_back(make_pair(make_pair(yy, xx), jj));
        g[jj].push_back(make_pair(make_pair(xx, yy), ii));
    }
    vector<bool> vis(n + 1, false);
    vector<mint> ans(n + 1, false);
    function<void(int, int)> Dfs = [&](int s, int p) {
        vis[s] = 1;
        for (auto c : g[s]) {
            int child = c.second;
            int xx = c.first.first;
            int yy = c.first.second;
            if (vis[child]) continue;
            ans[child] = ans[s] * mint(xx) / mint(yy);
            vector<pair<int, int>> XF = factorize(xx);
            vector<pair<int, int>> YF = factorize(yy);

            for (auto v : XF) {
                tot[v.first] += v.second;
            }
            for (auto v : YF) {
                tot[v.first] -= v.second;
                mn[v.first] = min(mn[v.first], tot[v.first]);
            }
            Dfs(child, s);

            for (auto v : XF) {
                tot[v.first] -= v.second;
            }
            for (auto v : YF) {
                tot[v.first] += v.second;
            }
        }
    };
    for (int i = 1; i <= n; i++) {
        tot[i] = 0;
        mn[i] = 0;
    }
    ans[1] = 1;
    Dfs(1, -1);
    mint start = 1;
    for (int i = 1; i <= n; i++) {
        if (mn[i] < 0) {
            start *= mint(i).pow(-mn[i]);
            cerr << i << ": " << mn[i] << "\n";
        }
    }
    cout << "start " << start << "\n";
    mint x = 0;
    for (int i = 1; i <= n; i++) {
        x += (start * ans[i]);
    }
    cout << x << endl;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int tt = 1;
    construct();
    cin >> tt;
    for (int i = 0; i < tt; i++) {
        cerr << " TC : " << i << "\n";
        solve();
    }
}
