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

inline ll gcd(ll a, ll b) {if (b == 0) return a; a %= b; return gcd(b , a);}
inline ll max(ll a, ll b) {return ((a > b) ? a : b);}
inline ll min(ll a, ll b) {return ((a > b) ? b : a);}
ll power(ll x, ll ex);
ll powermod(ll x, ll ex, ll md);

const ll inf = 1e18 + 9;
const ll mod = 1e9 + 7;
const ld PI = acos(-1);
const ld eps = 1e-9;

const int MX = 26;
// Insert and search costs O(key_length)
// memory requirements of Trie is O(MX * key_length * N)
struct TrieNode {
	struct TrieNode* children[MX];
	bool endofWord;

	TrieNode() {
		endofWord = false;
		for (int i = 0; i < MX; i++) children[i] = NULL;
	}
};
void insert(TrieNode* root, string &key) {
	TrieNode* temp = root;
	for (int i = 0; i < key.size(); i++) {
		int index = key[i] - 'a';
		if (temp->children[index] == NULL) {
			temp->children[index] = new TrieNode();
		}
		temp = temp->children[index];
	}
	temp->endofWord = true;
	return;
}
bool search(TrieNode* root, string &key) {
	TrieNode* temp = root;
	for (int i = 0; i < key.size(); i++) {
		int index = key[i] - 'a';
		if (temp->children[index] == NULL) return 0;
		temp = temp->children[index];
	}
	if (temp->endofWord == false) return 0;
	return 1;
}
bool isempty(TrieNode* root) {
	for (int i = 0; i < MX; i++) if (root->children[i]) return 0;
	return 1;
}
TrieNode* erase(TrieNode* root, string &key, int depth = 0) {
	if (!root) return NULL;
	if (depth == key.size()) {
		if (root->endofWord) root->endofWord = false;
		if (isempty(root))delete root, root = NULL;
		return root;
	}

	int index = key[depth] - 'a';
	root->children[index] = erase(root->children[index], key, depth + 1);
	if (isempty(root) && root->endofWord == false) delete root, root = NULL;
	return root;
}

void solve() {
	vector<string> keys = {"the", "a", "there", "answer", "any", "by", "bye", "their"};
	int n = keys.size();

	TrieNode* root = new TrieNode();
	for (int i = 0; i < n; i++) insert(root, keys[i]);

	string look = "the";
	cout << (search(root, look) ? ("found\n") : ("notfound\n"));

	look = "dog";
	cout << (search(root, look) ? ("found\n") : ("notfound\n"));

	look = "answ";
	cout << (search(root, look) ? ("found\n") : ("notfound\n"));

	look = "answer";
	cout << (search(root, look) ? ("found\n") : ("notfound\n"));
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
