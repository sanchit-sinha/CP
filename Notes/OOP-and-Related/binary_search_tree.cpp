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
#define pll                 pair<ll, ll>
#define vll                 vector<ll>
#define vvll                vector<vll>
#define vpll                vector<pll>
#define all(c)              (c).begin(),(c).end()
#define sz(c)               (ll)((c).size())
#define get(x,c)            get<x>(c)
#define trav(a,x)           for(auto a = x.begin(); a != x.end(); a++)
#define rep(i, n)           for(ll i = 0; i < (n) ; i++)
#define FOR(i, a, b)        for(ll i = (a); i <= (b); i++)
#define FORR(i, b, a)       for(ll i = (b); i >= (a); i--)

inline ll gcd(ll a, ll b) {if (b == 0) return a; a %= b; return gcd(b , a);}
inline ll max(ll a, ll b) {return ((a > b) ? a : b);}
inline ll min(ll a, ll b) {return ((a > b) ? b : a);}
ll power(ll x, ll ex);
ll powermod(ll x, ll ex, ll md);

const ll inf = 4e18 + 9;
const ll mod = 1e9 + 7;
const ld PI = acos(-1);
const ld eps = 1e-9;

/* implementing BST
BST contains only distinct element */
struct node {
    int data;
    node* left;
    node* right;

    node() {
        data = 0, left = right = NULL;
    }

    node(int x) {
        data = x, left = right = NULL;
    }
};

/* functions */
node* insert(node* root, int x); // inserts an element in BST
bool member(node* root, int x);  // returns true if x belongs to root
int min(node* root); // returns the minimum element of BST
node* Deletemin(node* root); // returns root - {min(root)}
node* Delete(node* root, int x); // returns root - {x}

bool member(node* root, int x) { // returns true if x belongs to root
    if (root == NULL) return false;

    if (x == root->data) return true;
    else if (x < root->data) return member(root->left, x);
    else return member(root->right, x);
}

node* insert(node* root, int x) { // inserts an element in BST
    if (root == NULL) {
        return new node(x);
    }

    if (x < root->data) root->left = insert(root->left, x);
    else if (x > root->data) root->right = insert(root->right, x);
    else return root;

    return root;
}

int min(node* root) { // returns the minimum element of BST
    if (root == NULL) return INT_MAX;

    if (root->left == NULL) return root->data;
    else return min(root->left);
}

node* Deletemin(node* root) { // returns root - {min(root)}
    if (!root) return root;

    if (!root -> left) return root->right;
    else {
        root->left = Deletemin(root->left);
        return root;
    }
}

node* Delete(node* root, int x) { // returns root - {x}
    if (!root || !member(root, x)) return root;
    if (x == root->data) {
        if (!root->right) return root->left;
        else if (!root->left) return root->right;
        else {
            int mn = min(root->right);
            root->right = Deletemin(root->right);
            root->data = mn;

            return root;
        }
    }
    else if (x < root->data) {
        root->left = Delete(root->left, x);
        return root;
    }
    else if (x > root->data) {
        root->right = Delete(root->right, x);
        return root;
    }

    return NULL;
}

void levelorder(node *root) {
    if (root == NULL) {
        cout << "Empty\n";
        return;
    }

    queue<node*> q;
    q.push(root);
    while (!q.empty()) {
        auto cur = q.front();
        cout << cur->data << " ";
        q.pop();

        if (cur->left) q.push(cur->left);
        if (cur->right) q.push(cur->right);
    }
    cout << "\n";
}

/* checking if the BST is valid or not */

void printinorder(node* root) {
    if (root == NULL) return;
    printinorder(root->left);
    cout << root->data << " ";
    printinorder(root->right);
}
void inorder(vector<int> &arr, node * root) {
    if (root == NULL) return;
    inorder(arr, root->left);
    arr.push_back(root->data);
    inorder(arr, root->right);
}

bool validateBST(node * root) {
    if (root == NULL) return 1;
    vector<int> arr;
    inorder(arr, root);

    for (int i = 1; i < (int)arr.size(); i++) {
        if (arr[i] > arr[i - 1]) continue;
        else return 0;
    }

    return 1;
}

/* generating random input */
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
ll range(ll l , ll r) {
    ll n = uniform_int_distribution<int> (l , r)(rng);
    return n;
}

void solve() {
    node* root = NULL;

    /*
    root = insert(root, 22);
    cout << "levelorder : "; levelorder(root);
    cout << "inorder:  "; printinorder(root);
    cout << "\n";
    cout << "\n";

    root = insert(root, 70);
    cout << "levelorder : "; levelorder(root);
    cout << "inorder:  "; printinorder(root);
    cout << "\n";
    cout << "\n";

    root = insert(root, 21);
    cout << "levelorder : "; levelorder(root);
    cout << "inorder:  "; printinorder(root);
    cout << "\n";
    cout << "\n";

    return;
    */

    int iter = 100;
    set<int> arr;
    vector<int> ops;
    while (iter--) {
        ll x = range(0, 2);
        if (x == 0) {
            ll n = range(1, 100);
            ops.pb(n);

            cout << "insert " << n << "\n";
            arr.insert(n);
            root = insert(root, n);
        }
        else if (x == 1) {
            cout << "Delete min " << "\n";
            root = Deletemin(root);
            if (sz(arr)) arr.erase(arr.begin());
        }
        else if (x == 2) {
            ll index = range(0, sz(ops) - 1);

            ll n = range(1, 100);
            if (index >= 0) {
                n = ops[index];
            }

            cout << "Delete " << n << " " << "\n";

            auto it = arr.find(n);
            if (it != arr.end()) arr.erase(it);

            root = Delete(root, n);
        }

        if (!validateBST(root)) {
            cout << "false\n";
            cout << "inorder : ";

            vector<int> srted;
            inorder(srted, root);
            rep(i, sz(srted)) cout << srted[i] << " ";
            cout << "\n";

            return;
        }
        else {
            cout << "BST: ";
            levelorder(root);
            cout << "\n";
        }
    }

    cout << "final : "; levelorder(root);
}

int main() {
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
        // cout << "Case #" << PTC << ":" << ' ';
        solve();
    }
    // cerr << "Time : " << 1000 * ((double)clock()) / (double)CLOCKS_PER_SEC << "ms\n";
}

ll power(ll x, ll y) {if (y == 0) return 1; ll a = power(x, y / 2); if (y % 2 == 0) return a * a; else return x * a * a;}
ll powermod(ll x, ll ex, ll md) {ll ans = 1ll; while (ex > 0) {if (ex & 1ll) ans = (ans * x) % md; ex >>= 1ll; x = (x * x) % md;} return ans;}
