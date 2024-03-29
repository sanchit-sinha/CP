#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
#include "bits/stdc++.h"
using namespace __gnu_pbds;
using namespace std;

#define f                   first
#define s                   second
#define pb                  push_back
#define ll                  long long
#define ld                  long double
#define lb                  lower_bound
#define ub                  upper_bound
#define mp                  make_pair
#define mt                  make_tuple
#define pll                 pair<ll, ll>
#define vll                 vector<ll>
#define vvll                vector<vll>
#define vpll                vector<pll>
#define all(c)              (c).begin(),(c).end()
#define sz(c)               (ll)((c).size())
#define getT(x,c)           get<x>(c)
#define trav(a,x)           for(auto a = (x).begin(); a != (x).end(); a++)
#define rep(i, n)           for(ll i = 0; i < (n) ; i++)
#define FOR(i, a, b)        for(ll i = (a); i <= (b); i++)
#define FORR(i, b, a)       for(ll i = (b); i >= (a); i--)

#ifdef LOCAL
bool DEBUGG = 1;
#include "debug.cpp"
#else
bool DEBUGG = 0;
#define debug(...) 42
#define cerr if(false) cerr
#endif

inline ll gcd(ll a, ll b) { if (b == 0) return a; a %= b; return gcd(b, a); }
inline ll max(ll a, ll b) { return ((a > b) ? a : b); }
inline ll min(ll a, ll b) { return ((a > b) ? b : a); }
ll power(ll x, ll ex);
ll powermod(ll x, ll ex, ll md);

const ll mod = 1e9 + 7;
const ld PI = acos(-1);
const ld eps = 1e-9;

const int ALPHABET_SIZE = 2;
struct TrieNode {
    struct TrieNode* children[ALPHABET_SIZE];
    bool isEndOfWord;
};
struct TrieNode* getNode(void) {
    struct TrieNode* pNode = new TrieNode;
    pNode->isEndOfWord = false;
    for (int i = 0; i < ALPHABET_SIZE; i++)
        pNode->children[i] = NULL;
    return pNode;
}
void insert(struct TrieNode* root, string key) {
    struct TrieNode* pCrawl = root;
    for (int i = 0; i < (int) key.size(); i++) {
        int index = key[i] - '0';
        if (!pCrawl->children[index]) pCrawl->children[index] = getNode();
        pCrawl = pCrawl->children[index];
    }
    pCrawl->isEndOfWord = true;
}

void solve() {
    ll n, m;
    cin >> n >> m;

    ll mx = (1ll << 20);
    vector<bool> vis(mx + 1, 1ll);

    rep(i, n) {
        ll x;
        cin >> x;
        vis[x] = 0;
    }

    auto conv = [&](ll x) {
        string bin(21, '0');
        ll i = 0, temp = x;
        while (temp) {
            if (temp & 1) bin[i] = '1';
            temp /= 2;i++;
        }

        reverse(all(bin));
        return bin;
    };

    TrieNode* root = getNode();
    rep(i, mx) if (vis[i]) insert(root, conv(i));

    auto minxor = [&](string& s) {
        debug(s);
        ll ans = 0ll;
        int c = 0;

        struct TrieNode* pCrawl = root;
        for (int i = 0; i < (int) s.size(); i++) {
            int index = s[i] - '0';
            if (pCrawl->children[index]) pCrawl = pCrawl->children[index];
            else {
                ans += (1ll << (sz(s) - i - 1));
                pCrawl = pCrawl->children[index ^ 1];
            }
        }

        return ans;
    };

    ll p = 0;
    rep(i, m) {
        ll x;
        cin >> x;

        x ^= p;p = x;

        string t = conv(x);
        cout << minxor(t) << "\n";
    }

}

int main() {
#ifdef ERROR
    freopen("../error.txt", "w", stderr);
#endif
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
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
    while ((PTC++) < NTC) {
        cerr << "Testcase # " << PTC << "\n";
        // cout << "Case #" << PTC << ":" << ' ';
        solve();
        cerr << "*************************\n";
    }
    // cerr << "Time : " << 1000 * ((double)clock()) / (double)CLOCKS_PER_SEC << "ms\n";
}

ll power(ll x, ll y) { if (y == 0) return 1; ll a = power(x, y / 2); if (y % 2 == 0) return a * a; else return x * a * a; }
ll powermod(ll x, ll ex, ll md) { ll ans = 1ll; while (ex > 0) { if (ex & 1ll) ans = (ans * x) % md; ex >>= 1ll; x = (x * x) % md; } return ans; }