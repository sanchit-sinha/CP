#include"bits/stdc++.h"
using namespace std;

int main() {
	int t;
	cin >> t;

	while (t--) {
		int n, k;
		cin >> n >> k;

		vector<int> arr(n);
		for (auto &x : arr) cin >> x;

		map<int, vector<int>> m;
		for (int i = 0; i < n; i++)m[arr[i]].push_back(i);

		vector<int> col(n, 0);
		int ct = 0;
		for (auto &x : m) {
			int index = 1;
			int len = (int)((x.second).size());
			if (len >= k) {
				for (int i = 0; i < min(k, len); i++) {
					if (index == k + 1) break;
					col[x.second[i]] = index++;
				}
			}
			else ct += len;
		}

		// cout << "COL\n";
		// for (int i = 0; i < n; i++) cout << col[i] << " ";
		// cout << "\n";
		int extra = (ct / k) * k;
		int index = 1;
		for (auto &x : m) {
			int len = (int)((x.second).size());
			if (len < k) {
				for (int i = 0; i < min(len, k); i++) {
					if (extra == 0) break;
					int color = index;
					if (color == k + 1) index = 1, color = 1;
					extra--;
					col[(x.second)[i]] = index++;
				}
			}
			if (extra == 0) break;
		}

		for (int i = 0; i < n; i++) cout << col[i] << " ";
		cout << "\n";
	}
}