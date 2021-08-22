#include"bits/stdc++.h"
using namespace std;
int main() {
	int t;
	cin >> t;
	while (t--) {
		int n;
		cin >> n;

		int div = n / 3;
		if (n % 3 == 0) cout << div << " " << div << "\n";
		else if (n % 3 == 1) {
			cout << div + 1 << " " << div << "\n";
		}
		else {
			cout << div  << " " << div + 1 << "\n";
		}
	}
}