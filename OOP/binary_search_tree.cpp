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

struct Node {
    int data;
    Node* left;
    Node* right;

    Node(int d) {
        data = d;
        left = NULL;
        right = NULL;
    }
};

Node* insertNode(Node* &root, int x) {
    Node* newnode = new Node(x);
    if (root == NULL) return newnode;

    Node* temp = root;
    while (temp != NULL) {
        int val = temp->data;
        if (x <= val) {
            if (temp->left != NULL) temp = temp->left;
            else {
                temp->left = newnode;
                return root;
            }
        }
        else {
            if (temp->right != NULL) temp = temp->right;
            else {
                temp->right = newnode;
                return root;
            }
        }
    }

    return root;
}
void display(Node* root) {
    if (root == NULL) return;
    cout << root->data << "\n";
    display(root->left);
    display(root->right);
}
Node* getHead(Node* root, int x) {
    if (root == NULL) return root;
    Node* temp = root;
    while (temp != NULL) {
        if (temp->data == x) return temp;
        else if (x < temp->data) temp = temp->left;
        else if (x > temp->data) temp = temp->right;
    }

    return root;
}
void solve() {
    int n;
    cin >> n;

    vector<int> a(n);
    for (auto &x : a) cin >> x;

    debug(a);
    Node* root = NULL;
    for (auto x : a) root = insertNode(root, x);

    // display(root);
    int q;
    cin >> q;
    Node* reqHead = getHead(root, q);
    display(reqHead);
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

ll power(ll x, ll y) {if (y == 0) return 1; ll a = power(x, y / 2); if (y % 2 == 0) return a * a; else return x * a * a;}
ll powermod(ll x, ll ex, ll md) {ll ans = 1ll; while (ex > 0) {if (ex & 1ll) ans = (ans * x) % md; ex >>= 1ll; x = (x * x) % md;} return ans;}
