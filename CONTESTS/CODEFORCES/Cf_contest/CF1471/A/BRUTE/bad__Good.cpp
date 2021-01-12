#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define pi pair<int,int>
#define pll pair<ll,ll>
#define ld  long double
 
const int INF = 1e9 + 7;

void solve(){
	int N; cin >> N; 
	ll x; cin >> x;
	ll mn = 0 , mx = 0;
	for(int i = 0; i < N; i++){
	   ll t; cin >> t;
	   mn += (t + x - 1) / x;
	   mx += t;	
	} 
	mx = (mx + x - 1) / x;
	cout << mx << " " << mn << endl;
}
 
int main(){
    ios :: sync_with_stdio(false); 
    cin.tie(nullptr); 
    cout.tie(nullptr);
    int tt = 1;
    cin >> tt;
    for(int tc = 1; tc <= tt; tc++){
        // cout << "Case #" << tc << ": ";
        solve();
    }
}