#include"bits/stdc++.h"
using namespace std;

#define ll long long
const int N = 1e5 + 11;

ll tree[N], len;
ll A[N], n;

// 0 - indexed
bool f(ll rootValue, ll childValue) {
	return rootValue > childValue;
}

// works in log(n) and assumes that both the left and right child are heaps themselves
void Heapify(int node) {
	int largest = node;
	int left = 2 * node, right = 2 * node + 1;

	if (left < len && tree[largest] < tree[left]) largest = left;
	if (right < len && tree[largest] < tree[right]) largest = right;

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
		if (tree[parent] >= tree[node]) node = parent;
		else break;
	}
	Heapify(node / 2); // calling heapify from node ensures that its child are already heap

}

void deleteNode(int node) {
	swap(tree[node], tree[len - 1]);
	tree[len - 1] = 0;
	len--;

	while (node) {
		int parent = node / 2;
		if (tree[parent] >= tree[node]) node = parent;
		else break;
	}
	Heapify(node / 2); // calling heapify from node ensures that its child are already heap
}

// moves in bottom-up manner as this guarantees that whenever we apply heapify, the left and right child are heaps
void buildHeap() {
	len = n + 1;
	for (int i = 0; i < n; i++) tree[i + 1] = A[i];
	for (int i = n / 2; i >= 1; i--) {
		Heapify(i);
	}
}

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


int main() {
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
	// 9 4 5 1 3 2 7
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
}