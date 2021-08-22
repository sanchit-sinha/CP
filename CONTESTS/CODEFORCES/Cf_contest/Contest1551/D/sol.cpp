#include"bits/stdc++.h"
using namespace std;

int main() {
	int t;
	cin >> t;
	while (t--) {
		int n;
		cin >> n;

		int ans = 0;
		vector<string> s(n);
		for (int i = 0 ; i < n; i++) {
			cin >> s[i];
		}

		int mx = 0;
		for (int k = 0; k < 5; k++) {
			vector<pair<pair<int, int>, int>> t;

			int sum = 0, other = 0;
			int ans = 0;
			for (int i = 0; i < n; i++) {
				vector<int> ct(5, 0);
				for (auto &x : s[i]) ct[x - 'a']++;

				int add = 0;
				for (int j = 0; j < 5; j++) add += ct[j];
				if (ct[k] <= add - ct[k]) {
					pair<pair<int, int>, int> p;
					p = make_pair(make_pair(ct[k] - (add - ct[k]), 0), i);
					t.push_back(p);
				}
				else {
					ans++;
					sum += ct[k];
					other += (add - ct[k]);
				}
			}

			mx = max(mx, ans);
			int len = (int)t.size();

			sort(t.begin(), t.end());
			reverse(t.begin(), t.end());

			// cout << k << " " << sum << " " << other << " : ";
			for (int i = 0; i < len; i++) {
				int index = t[i].second;
				// cout << s[index] << " ";

				vector<int> ct(5, 0);
				for (auto &x : s[index]) ct[x - 'a']++;

				sum += ct[k];

				int add = 0;
				for (int j = 0 ; j < 5; j++) add += ct[j];

				other += (add - ct[k]);

				if (sum > other) {
					mx = max(mx, ans + i + 1);
				}
			}

			// cout << "\n";
		}

		cout << mx << "\n";
	}
}