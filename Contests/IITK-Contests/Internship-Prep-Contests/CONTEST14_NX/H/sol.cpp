#include "bits/stdc++.h"
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
#define pll                 pair<ll , ll>
#define vll                 vector<ll>
#define vvll                vector<vll>
#define vpll                vector<pll>
#define all(c)              (c).begin(),(c).end()
#define sz(c)               (int)((c).size())
#define get(x,c)            get<x>(c)
#define trav(a,x)           for(auto a = x.begin() ; a != x.end() ; a++)
#define rep(i, n)           for(int i = 0; i < (n) ; i++)
#define FOR(i, a, b)        for(int i = (a); i <= (b); i++)
#define FORR(i, b, a)       for(int i = (b); i >= (a); i--)

#ifdef LOCAL
#include "debug.cpp"
#define debug(...) cerr << "[" << #__VA_ARGS__ << "]: ", debug_out(__VA_ARGS__)
#else
#define debug(...) 42
#define cerr if(false) cerr
#endif


inline ll gcd(ll a, ll b) {if (b == 0) return a; a %= b; return gcd(b , a);}
inline ll max(ll a, ll b) {return ((a > b) ? a : b);}
inline ll min(ll a, ll b) {return ((a > b) ? b : a);}
ll power(ll x, ll ex);
ll powermod(ll x, ll ex, ll md);

const ll inf = 1e18 + 9;
const ll mod = 1e9 + 7;
const ld PI = acos(-1);
const ld eps = 1e-9;

struct heap {
    vector<long long> v;
    int last;

    heap() {
        last = 0;
    }

    bool function(long long parent_val, long long child_val) {
        return parent_val > child_val;
    }
    long long INITITALISE() {
        return -inf;
    }

    long long top() {
        assert(v.size() >= 1);
        return v[0];
    }

    void update(int child) {
        if (child == 0) return;
        int parent = child / 2;
        if (parent == child || function(v[parent], v[child])) return;
        else {
            swap(v[parent], v[child]);
            update(parent);
        }
    }

    void push(long long val) {
        v.push_back(val);
        update(last);
        last++;
    }

    void heapify(int parent) {
        int child1 = parent * 2;
        int child2 = parent * 2 + 1;

        int choosen = parent;
        if (child1 < last && function(v[child1], v[choosen])) choosen = child1;
        if (child2 < last && function(v[child2], v[choosen])) choosen = child2;

        if (choosen == parent) return;
        else {
            swap(v[parent], v[choosen]);
            heapify(choosen);
        }
    }

    void pop() {
        assert(last > 0);
        int last_index = last - 1;
        v[0] = INITITALISE(); // update;
        heapify(0);
        last--;
    }

    long long extract() {
        long long val = top();
        pop();
        return val;
    }

    bool empty() {
        return last == 0;
    }

};

void display(heap q) {
    while (!q.empty()) {
        cout << q.top() << " ";
        q.pop();
    }

    cout << "\n";
}

#define NCR
const ll mX = N;
ll fact[mX + 11] , invfact[mX + 11];
void factorial() {
    fact[0] = invfact[0] = 1;
    for (ll i = 1 ; i < mX ; i++) {
        fact[i] = i * fact[i - 1];
        fact[i] %= mod;
    }
    invfact[mX - 1] = powermod(fact[mX - 1] , mod - 2 , mod); // if mod is prime
    for (ll i = mX - 2 ; i > 0 ; i--) {
        invfact[i] = invfact[i + 1] * (i + 1);
        invfact[i] %= mod;
    }
}
ll ncr(ll n , ll r) {
    if (r > n || n < 0 || r < 0)return 0;
    ll p = (fact[n] * invfact[r]) % mod;
    p *= invfact[n - r];
    return p % mod;
}
void solve() {
    heap q;
    q.push(3);
    q.push(5);
    q.push(2);
    q.push(2);
    q.push(121);
    q.push(121212);
    q.push(6);
    display(q);
}

int main() {
#ifdef LOCAL
    freopen("../error.txt", "w", stderr);
#endif
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    cout << fixed << setprecision(20);

    ll NTC = 1;
    // cin >> NTC;

#ifdef SIEVE
    sieve();
#endif
#ifdef NCR
    factorial();
#endif
#ifdef PREPROCESS
    preprocess();
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

ll power(ll x, ll y) {if (y == 0) return 1; ll a = power(x, y / 2); if (y % 2 == 0) return a * a; else return x * a * a;}
ll powermod(ll x, ll ex, ll md) {ll ans = 1ll; while (ex > 0) {if (ex & 1ll) ans = (ans * x) % md; ex >>= 1ll; x = (x * x) % md;} return ans;}
