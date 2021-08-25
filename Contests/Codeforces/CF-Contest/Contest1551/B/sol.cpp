#include"bits/stdc++.h"
using namespace std;

int main() {
	int t;
	cin >> t;

	while (t--) {
		string s;
		cin >> s;

		int n = (int)s.size();
		vector<int> v(26, 0);
		for (int i = 0; i < n; i++) {
			v[s[i] - 'a']++;
		}

		int ct = 0, one = 0;
		for (int i = 0; i < 26; i++) {
			if (v[i] > 1) ct++;
			else if (v[i] == 1) one++;
		}

		cout << ct + (one / 2) << "\n";
	}
}