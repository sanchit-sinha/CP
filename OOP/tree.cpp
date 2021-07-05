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
struct TreeNode {
	int data;
	TreeNode* left;
	TreeNode* right;

	TreeNode(int x) {
		data = x;
		left = NULL, right = NULL;
	}
};

// inorder traversal of binary tree
void inorderTraversal(TreeNode* root) {
	if (root == NULL) return;
	inorderTraversal(root->left);
	cout << root->data << " ";
	inorderTraversal(root->right);
	return;
}

// preorder traversal of binary tree
void preorderTraversal(TreeNode* root) {
	if (root == NULL) return;
	cout << root->data << " ";
	preorderTraversal(root->left);
	preorderTraversal(root->right);
	return;
}

// postorder traversal of binary tree
void postorderTraversal(TreeNode* root) {
	if (root == NULL) return;
	postorderTraversal(root->left);
	postorderTraversal(root->right);
	cout << root->data << " ";
	return;
}

// level order traversal of binary tree
void levelorderTraversal(TreeNode* root) {
	queue<TreeNode*> q;
	q.push(root);

	while (!q.empty()) {
		TreeNode* cur = q.front();
		cout << cur->data << " ";
		q.pop();

		if (cur->left) q.push(cur->left);
		if (cur->right) q.push(cur->right);
	}
}

// LCA of binary tree
TreeNode* LCA(TreeNode* root, int n1, int n2) {
	if (root == NULL) return root;
	if (root->data == n1 || root->data == n2) return root;

	TreeNode* leftLCA = LCA(root->left, n1, n2);
	TreeNode* rightLCA = LCA(root->right, n1, n2);

	if (leftLCA && rightLCA) return root;

	return (leftLCA == NULL) ? (rightLCA) : (leftLCA);
}

// Height of binary tree
int Height(TreeNode* root, int &ans) {
	if (root == NULL) return 0;

	int lheight = Height(root->left, ans);
	int rheight = Height(root->right, ans);

	ans = max(ans, 1 + lheight + rheight);
	return max(lheight, rheight) + 1;
}
// Diamater of binary Tree
int Diameter(TreeNode* root) {
	int ans = 0;
	int ht = Height(root, ans);
	return ans;
}

// Left view of binary tree
void leftView(TreeNode* root) {
	// do level order traversal to store distances
	map<int, vector<TreeNode*>> SAME_LEVEL;
	unordered_map<TreeNode*, int> DIS;

	queue<TreeNode*> q;
	q.push(root);
	DIS[root] = 0;

	while (!q.empty()) {
		TreeNode* cur = q.front();
		int level = DIS[cur];
		SAME_LEVEL[level].push_back(cur);
		q.pop();

		if (cur->left) {
			DIS[cur->left] = level + 1;
			q.push(cur->left);
		}
		if (cur->right) {
			DIS[cur->right] = level + 1;
			q.push(cur->right);
		}
	}

	for (auto nodes : SAME_LEVEL) {
		cout << nodes.second[0]->data << " ";
	}
	cout << "\n";
}

// right view of binary tree
void rightView(TreeNode* root) {
	// do level order traversal to store distances
	map<int, vector<TreeNode*>> SAME_LEVEL;
	unordered_map<TreeNode*, int> DIS;

	queue<TreeNode*> q;
	q.push(root);
	DIS[root] = 0;

	while (!q.empty()) {
		TreeNode* cur = q.front();
		int level = DIS[cur];
		SAME_LEVEL[level].push_back(cur);
		q.pop();

		if (cur->left) {
			DIS[cur->left] = level + 1;
			q.push(cur->left);
		}
		if (cur->right) {
			DIS[cur->right] = level + 1;
			q.push(cur->right);
		}
	}

	for (auto nodes : SAME_LEVEL) {
		int len = nodes.second.size();
		cout << nodes.second[len - 1]->data << " ";
	}
	cout << "\n";
}

// Top view of binary tree
void topView(TreeNode* root) {
	// do level order traversal to store horizontal distances
	map<int, vector<TreeNode*>> SAME_VERTICAL_LINE;
	unordered_map<TreeNode*, int> HORZ_DIS;

	queue<TreeNode*> q;
	q.push(root);
	HORZ_DIS[root] = 0;

	while (!q.empty()) {
		TreeNode* cur = q.front();
		int level = HORZ_DIS[cur];
		SAME_VERTICAL_LINE[level].push_back(cur);
		q.pop();

		if (cur->left) {
			HORZ_DIS[cur->left] = level - 1;
			q.push(cur->left);
		}
		if (cur->right) {
			HORZ_DIS[cur->right] = level + 1;
			q.push(cur->right);
		}
	}

	for (auto nodes : SAME_VERTICAL_LINE) {
		cout << nodes.second[0]->data << " ";
	}
	cout << "\n";
}

// Bottom view of binary tree
void bottomView(TreeNode* root) {
	// do level order traversal to store horizontal distances
	map<int, vector<TreeNode*>> SAME_VERTICAL_LINE;
	unordered_map<TreeNode*, int> HORZ_DIS;

	queue<TreeNode*> q;
	q.push(root);
	HORZ_DIS[root] = 0;

	while (!q.empty()) {
		TreeNode* cur = q.front();
		int level = HORZ_DIS[cur];
		SAME_VERTICAL_LINE[level].push_back(cur);
		q.pop();

		if (cur->left) {
			HORZ_DIS[cur->left] = level - 1;
			q.push(cur->left);
		}
		if (cur->right) {
			HORZ_DIS[cur->right] = level + 1;
			q.push(cur->right);
		}
	}

	for (auto nodes : SAME_VERTICAL_LINE) {
		int len = nodes.second.size();
		cout << nodes.second[len - 1]->data << " ";
	}
	cout << "\n";
}
TreeNode* mirrorTree(TreeNode* root) {
	if (root == NULL) return root;

	TreeNode* lroot = mirrorTree(root->left);
	TreeNode* rroot = mirrorTree(root->right);

	root->left = rroot;
	root->right = lroot;
	return root;
}

void solve() {
	TreeNode* root = new TreeNode(0);

	TreeNode* newnode1 = new TreeNode(1);
	root -> left = newnode1;

	TreeNode* newnode2 = new TreeNode(2);
	root -> right = newnode2;

	TreeNode* newnode3 = new TreeNode(5);
	newnode1 -> left =  newnode3;

	TreeNode* newnode4 = new TreeNode(6);
	newnode3 -> left = newnode4;

	TreeNode* newnode5 = new TreeNode(7);
	newnode3 -> right = newnode5;
	/*
					0
				   / \
				  1   2
				 /
				5
			   / \
			  6   7
							*/
	cout << "Pre-order Traversal : "; preorderTraversal(root); cout << "\n";
	cout << "Inorder Traversal : "; inorderTraversal(root); cout << "\n";
	cout << "Post-order Traversal : "; postorderTraversal(root); cout << "\n";
	cout << "Level order Traversal : "; levelorderTraversal(root); cout << "\n\n";

	cout << "LCA of 6 ans 2 is " << LCA(root, 6, 2)->data << "\n";
	cout << "LCA of 1 ans 7 is " << LCA(root, 7, 1)->data << "\n";

	int dmtr = 0;
	cout << "Height of binary tree is " << Height(root, dmtr) << "\n";
	cout << "Diameter of binary tree is " << dmtr << "\n\n";

	cout << "Left View of tree is : "; leftView(root);
	cout << "Right View of tree is : "; rightView(root);
	cout << "Top View of tree is : "; topView(root);
	cout << "Bottom View of tree is : "; bottomView(root); cout << "\n";

	TreeNode* mirrorRoot = mirrorTree(root);
	cout << "Level order Traversal of mirror tree: "; levelorderTraversal(mirrorRoot); cout << "\n\n";

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
		cerr << "Testcase # " << PTC << "\n";
		// cout << "Case #" << PTC << ":" << ' ';
		solve();
		cerr << "*************************\n";
	}
	// cerr << "Time : " << 1000 * ((double)clock()) / (double)CLOCKS_PER_SEC << "ms\n";
}

ll power(ll x, ll y) {if (y == 0) return 1; ll a = power(x, y / 2); if (y % 2 == 0) return a * a; else return x * a * a;}
ll powermod(ll x, ll ex, ll md) {ll ans = 1ll; while (ex > 0) {if (ex & 1ll) ans = (ans * x) % md; ex >>= 1ll; x = (x * x) % md;} return ans;}
