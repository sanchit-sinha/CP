#include"bits/stdc++.h"
using namespace std;

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, m, k;
        cin >> n >> m >> k;

        int tot = (n * m) / 2;
        int rem = tot - k;

        if (k == 0) {
            if (n % 2 == 0) cout << "YES\n";
            else cout << "NO\n";
        }
        else if (rem == 0) {
            if (m % 2 == 0 ) cout << "YES\n";
            else cout << "NO\n";
        }
        else if (n % 2 == 0 && m % 2 == 0) {
            if (tot & 1 || rem & 1) cout << "NO\n";
            else cout << "YES\n";
        }
        else if (n & 1) {
            bool ok = 0;
            for (int i = 1; i * i <= k; i++) {
                if (k % i == 0) {
                    int div1 = i, div2 = k / i;
                    if (div1 & 1 && (k * 2) / div1 <= m) {
                        ok = 1;
                        cout << "YES\n";
                        break;
                    }
                    if (div2 & 1 && (k * 2) / div2 <= m) {
                        ok = 1;
                        cout << "YES\n";
                        break;
                    }

                }
            }
            if (!ok) cout << "NO\n";
        }
        else if (m & 1) {
            bool ok = 0;
            for (int i = 1; i * i <= k; i++) {
                if (k % i == 0) {
                    int div1 = i, div2 = k / i;
                    if (div1 % 2 == 0 && (k * 2) / div1 <= m) {
                        ok = 1;
                        cout << "YES\n";
                        break;
                    }
                    if (div2 % 2 == 0 && (k * 2) / div2 <= m) {
                        ok = 1;
                        cout << "YES\n";
                        break;
                    }

                }

            }
            if (!ok) cout << "NO\n";

        }
    }
}