#include"bits/stdc++.h"
using namespace std;

#define ll long long
const int N = 1e5 + 11; // Max Size of heap

ll tree[N], len = 1; // tree : heap
ll A[N], n;
void levelorder(int node) {
	queue<pair<ll, ll>> q;
	q.push({node, tree[node]});

	while (!q.empty()) {
		auto p = q.front();
		ll cur = p.first;
		cout << p.second << " ";
		q.pop();

		ll left = 2 * cur, right = 2 * cur + 1;
		if (left < len) q.push({left, tree[left]});
		if (right < len) q.push({right, tree[right]});
	}
	return;
}
// 0 - indexed : (>= max heap)
bool func(ll rootValue, ll childValue) {
	return rootValue >= childValue;
}

// works in log(n) and assumes that both the left and right child are heaps themselves
void Heapify(int node) {
	int largest = max(node, 1);
	int left = 2 * node, right = 2 * node + 1;

	if (left < len && func(tree[left] , tree[largest])) largest = left;
	if (right < len && func(tree[right] , tree[largest])) largest = right;

	if (largest != node) {
		swap(tree[largest], tree[node]);
		Heapify(largest);
	}
	return;
}

void insert(ll val) {
	tree[len] = val;
	int node = len;
	len++;

	while (node) {
		int parent = node / 2;
		if (parent && func(tree[node], tree[parent])) { // bigger node is pushed upward
			swap(tree[node], tree[parent]);
			node = parent;
		}
		else break;
	}

	Heapify(max(node , 1)); // calling heapify from node ensures that its child are already heap
}
void deleteNode(int node) {
	swap(tree[node], tree[len - 1]);
	tree[len - 1] = 0;
	len--;

	while (node) {
		int parent = node / 2;
		if (parent && func(tree[node], tree[parent])) { // bigger node is pushed upward
			swap(tree[node], tree[parent]);
			node = parent;
		}
		else break;
	}

	Heapify(max(node , 1)); // calling heapify from node ensures that its child are already heap
}

// moves in bottom-up manner as this guarantees that whenever we apply heapify, the left and right child are heaps
void buildHeap() {
	len = n + 1;
	for (int i = 0; i < n; i++) tree[i + 1] = A[i];
	for (int i = n / 2; i >= 1; i--) {
		Heapify(i);
	}
}


void HeapSort(int node = 1) {
	while (len > 1) {
		int root = 1;
		swap(tree[root], tree[len - 1]);
		len--;

		Heapify(root);
	}
}


ll peek() {
	if (len <= 1) return -1;

	return tree[1];
}

ll extract() {
	if (len <= 1) return -1;

	ll temp = tree[1];
	deleteNode(1);
	return temp;
}

bool validateHeap(int node = 1) {
	if (node * 2 < len && !func(tree[node] , tree[node * 2])) return 0;
	if (node * 2 + 1 < len && !func(tree[node] , tree[node * 2 + 1])) return 0;

	bool ok = 1;
	if (node * 2 < len && !validateHeap(node * 2)) ok = 0;
	if (node * 2 + 1 < len && !validateHeap(node * 2 + 1)) ok = 0;
	return ok;
}

bool isempty() {
	return (len <= 1);
}


mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
ll range(ll l , ll r) {
	ll n = uniform_int_distribution<int> (l , r)(rng);
	return n;
}

int main() {
	/*
	n = 6;
	A[0] = 3;
	A[1] = 9;
	A[2] = 2;
	A[3] = 1;
	A[4] = 4;
	A[5] = 5;

	cout << "ARRAY\n";
	for (int i = 0; i < n; i++) cout << A[i] << " ";
	cout << "\n";

	buildHeap();

	cout << "leftOrder: ";
	levelorder(1);
	// 9 4 5 1 3 2
	cout << "\n";

	cout << "Inserted node value " << 7 << "\n";
	insert(7);

	cout << "leftOrder: ";
	levelorder(1);
	// 9 4 7 1 3 2 5
	cout << "\n";

	cout << "Tree\n";
	for (int i = 1; i < len; i++) cout << tree[i] << " ";
	cout << "\n";

	int index = 5;
	cout << "Deleted node at " << index << " " << tree[index] << "\n";
	deleteNode(index);

	cout << "leftOrder: ";
	levelorder(1);
	// 9 5 7 1 4 2
	cout << "\n";


	cout << peek() << "\n";
	cout << extract() << "\n";
	cout << peek() << "\n";

	cout << "leftOrder: ";
	levelorder(1);
	// 7 5 2 1 4
	cout << "\n";

	*/

	int iters = 20;
	while (iters--) {
		int x = range(0, 1);
		int n = range(1, 50);

		if (x == 0) insert(n);
		else extract();

		if (validateHeap()) {
			// cout << x << " " << n << " : " << len << "levelorder: ";
			// levelorder(1);
			// cout << "\n\n";
		}
		else {
			cout << "false\nlevelorder: ";
			levelorder(1);
			exit(1);
		}
		assert(validateHeap());
	}

	cout << " levelorder: " ; levelorder(1); cout << "\n";
	int sz = len;
	HeapSort();
	cout << sz - 1 << "\n";
	for (int i = 1; i < sz; i++) cout << tree[i] << " ";
	cout << "\n";
}