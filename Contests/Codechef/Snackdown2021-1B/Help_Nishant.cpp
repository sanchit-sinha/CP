#include "bits/stdc++.h"
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
#define get(x, c) get<x>(c)
#define trav(a, x) for (auto a = x.begin(); a != x.end(); a++)
#define rep(i, n) for (ll i = 0; i < (n); i++)
#define FOR(i, a, b) for (ll i = (a); i <= (b); i++)
#define FORR(i, b, a) for (ll i = (b); i >= (a); i--)

#ifdef LOCAL
bool DBG = 1;
#include "../debug.cpp"
#else
bool DBG = 0;
#define debug(...) 42
#define cerr   \
    if (false) \
    cerr
#endif

ll power(ll x, ll ex);
inline ll gcd(ll a, ll b);
inline ll max(ll a, ll b);
inline ll min(ll a, ll b);
ll powermod(ll x, ll ex, ll md);

const ll inf = 4e18 + 9;
const ll mod = 1e9 + 7;
const ld PI = acos(-1);
const ld eps = 1e-9;

const ll N = 1001;
const ll M = 51;
ll dp[N][M][M][M];
ll brute(ll n)
{
    FOR(i, 1, N - 1)
    FOR(j, 0, n)
    FOR(k, 0, n)
    FOR(l, 0, n)
    dp[i][j][k][l] = 0;

    FOR(i, 1, n)
    FOR(j, 1, n)
    FOR(k, 1, n)
    dp[1][i][j][k] = dp[2][i][j][k] = 1;

    FOR(i, 1, n)
    {
        FOR(j, 1, n)
        {
            // i, j, k
            ll k = j + j - i;
            FORR(l, k - 1, 1)
            dp[3][i][j][l] = 1;
        }
    }

    FOR(i, 4, M - 1)
    {
        bool ok = 0;
        // a b c d e
        FOR(a, 1, n)
        {
            FOR(b, 1, n)
            {
                FOR(c, 1, n)
                {
                    FOR(d, 1, n)
                    {
                        ll e = d + d - c;
                        FORR(l, e - 1, 1)
                        {
                            if (dp[i - 1][b][c][d] && dp[i - 2][a][b][c])
                            {
                                ok = 1;
                                dp[i][c][d][l] = 1;
                            }
                        }
                    }
                }
            }
        }

        if (!ok)
        {
            return (i - 1);
        }
    }

    return -1;
}

void brutee(ll n)
{
    ll x = 2;
    map<ll, ll> m;
    while (x <= n)
    {
        ll y = brute(x);
        cout << x << ": " << y << "\n";
        m[y]++;
        x++;
    }
    cout << "#############################\n";
    for (auto &x : m)
    {
        cout << x.f << ": " << x.s << "\n";
    }
}
void solve()
{
    ll n;
    cin >> n;

    // brutee(n);
    ll l = 2, r = 1e5, ans = 2;
    while (l <= r)
    {
        ll mid = l + (r - l) / 2;
        ll y = (mid * (mid + 1)) / 2;
        if (y < n)
            l = mid + 1;
        else
            ans = mid, r = mid - 1;
    }

    cout << ans * 2 << "\n";
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    cout << fixed << setprecision(20);

    ll NTC = 1;
    cin >> NTC;

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
    // cerr << "Time : " << 1000 * ((double)clock()) / (double)CLOCKS_PER_SEC << "ms\n";
}
inline ll max(ll a, ll b) { return ((a > b) ? a : b); }
inline ll min(ll a, ll b) { return ((a > b) ? b : a); }
inline ll gcd(ll a, ll b)
{
    if (b == 0)
        return a;
    a %= b;
    return gcd(b, a);
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
