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

bool check(const vector<string> &s)
{
    ll n = sz(s), m = sz(s);
    vector<vector<ll>> arr(n, vector<ll>(n, 0));

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            if (s[i][j] == 'Q')
            {
                for (int k = 0; k < n; k++)
                {
                    for (int l = 0; l < n; l++)
                    {
                        if (k == i)
                            arr[k][l]++;
                        if (l == j)
                            arr[k][l]++;
                        if (k + l == i + j)
                            arr[k][l]++;
                        if (k - l == i - j)
                            arr[k][l]++;
                    }
                }
            }
        }
    }

    bool ok = 1;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            if (arr[i][j] == 0)
                ok = 0;
        }
    }

    return ok;
}
void solve()
{
    /* check for testcases */
    ll n;
    cin >> n;

    vector<string> s;
    rep(i, n)
    {
        string t;
        rep(j, n) t.pb('.');
        s.pb(t);
    }

    FOR(i, 1, n - 2)
    {
        s[n - 1 - i][i] = 'Q';
    }

    if (n % 2 == 0)
    {
        s[n / 2][n / 2 - 1] = '.', s[n / 2 - 1][n / 2 - 1] = 'Q';
        s[n / 2 - 1][n / 2] = '.', s[n / 2][n / 2] = 'Q';
    }

    if (n == 4)
    {
        rep(i, n)
        {
            rep(j, n) s[i][j] = '.';
        }

        s[0][3] = 'Q', s[2][1] = 'Q';
    }

    rep(i, n)
    {
        rep(j, n) cout << s[i][j];
        cout << "\n";
    }

    cerr << "status : " << check(s) << "\n";
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
    cerr << "Time : " << 1000 * ((double)clock()) / (double)CLOCKS_PER_SEC << "ms\n";
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
