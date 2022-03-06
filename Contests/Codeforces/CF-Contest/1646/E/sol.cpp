#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
#include "bits/stdc++.h"
using namespace __gnu_pbds;
using namespace std;

#define f first
#define s second
#define pb push_back
#define ll long long
#define ld long double
#define lb lower_bound
#define ub upper_bound
#define mp make_pair
#define mt make_tuple
#define pll pair<ll, ll>
#define vll vector<ll>
#define vvll vector<vll>
#define vpll vector<pll>
#define all(c) (c).begin(), (c).end()
#define sz(c) (ll)((c).size())
#define getT(x, c) get<x>(c)
#define trav(a, x) for (auto a = (x).begin(); a != (x).end(); a++)
#define rep(i, n) for (ll i = 0; i < (n); i++)
#define FOR(i, a, b) for (ll i = (a); i <= (b); i++)
#define FORR(i, b, a) for (ll i = (b); i >= (a); i--)

#ifdef LOCAL
#include "debug.cpp"
#else
#define debug(...) 42
#define cerr   \
    if (false) \
    cerr
#endif

inline ll gcd(ll a, ll b)
{
    if (b == 0)
        return a;
    a %= b;
    return gcd(b, a);
}
inline ll max(ll a, ll b) { return ((a > b) ? a : b); }
inline ll min(ll a, ll b) { return ((a > b) ? b : a); }
ll power(ll x, ll ex);
ll powermod(ll x, ll ex, ll md);

const ll mod = 1e9 + 7;
const ld PI = acos(-1);
const ld eps = 1e-9;

const ll T = 21;
ll dp[T + 5][T + 5]; // number of nos in [1,m] divisible by [2,t]

const ll mX = 1e6 + 3;
ll spf[mX];

void process(ll m)
{
    vvll g(T + 1, vll(T + 1, 0));
    rep(i, T + 1) rep(j, T + 1) g[i][j] = gcd(i, j);

    FOR(y, 1, T)
    {
        vector<bool> vis(m + 1, 0);

        FOR(i, y + 1, T)
        {
            ll cnt = 0ll;
            ll lcm = (i * y) / g[i][y];
            for (ll j = lcm; j <= m * y; j += lcm)
            {
                if (!vis[j / y])
                {
                    cnt++, vis[j / y] = 1;
                }
            }
            dp[y][i] = dp[y][i - 1] + cnt;
        }
    }

    spf[1] = 1;
    for (ll i = 2; i < mX; i++)
    {
        if (spf[i] == 0)
        {
            spf[i] = i;
            for (ll j = 1ll * i * i; j < mX; j += i)
            {
                if (spf[j] == 0)
                    spf[j] = i;
            }
        }
    }
}

void brute(ll n, ll m)
{
    set<ll> st;
    rep(i, n) rep(j, m) st.insert(power(i + 1, j + 1));
    cerr << sz(st) << "\n";
    debug(st);
}
void solve()
{
    ll n, m;
    cin >> n >> m;

    // brute(n, m);

    process(m);
    ll ans = (n * m);

    ans -= (m - 1);
    FOR(i, 2, n)
    {
        ll x = i, y = 1;

        // i = x^y
        unordered_map<ll, ll> factors;
        ll temp = x, g = 0ll;
        while (temp > 1)
        {
            ll div = spf[temp], cnt = 0ll;
            while (temp % div == 0)
                temp /= div, cnt++;
            g = gcd(g, cnt);
            factors[div] = cnt;
        }

        x = 1ll, y = g;
        for (auto &z : factors)
        {
            x *= power(z.f, z.s / y);
        }

        ll t = 1, cur = x;
        FOR(j, 2, T)
        {
            cur *= x;
            if (cur <= n)
                t = j;
            else
                break;
        }

        ans -= dp[y][t];
    }

    cout << ans << "\n";
}

int main()
{
#ifdef LOCAL
    freopen("../error.txt", "w", stderr);
#endif
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    cout << fixed << setprecision(20);

    ll NTC = 1;
    // cin >> NTC;

#ifdef PREPROCESS
    preprocess();
#endif
#ifdef SIEVE
    sieve();
#endif
#ifdef NCR
    factorial();
#endif

    ll PTC = 0;
    while ((PTC++) < NTC)
    {
        cerr << "Testcase # " << PTC << "\n";
        // cout << "Case #" << PTC << ":" << ' ';
        solve();
        cerr << "*************************\n";
    }
    cout << "Time : " << 1000 * ((double)clock()) / (double)CLOCKS_PER_SEC << "ms\n";
}

ll power(ll x, ll y)
{
    if (y == 0)
        return 1;
    ll a = power(x, y / 2);
    if (y % 2 == 0)
        return a * a;
    else
        return x * a * a;
}
ll powermod(ll x, ll ex, ll md)
{
    ll ans = 1ll;
    while (ex > 0)
    {
        if (ex & 1ll)
            ans = (ans * x) % md;
        ex >>= 1ll;
        x = (x * x) % md;
    }
    return ans;
}
