#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define pi pair<int,int>
#define pll pair<ll,ll>
#define vi vector<int>
#define vll  vector<ll>
const int inf = 1e9 + 7;
const int MOD = 1e9 + 7;

void solve(){
  int n;
  cin >> n;
  string s; cin >> s;
  int good = 0, adj = 0 , bad = 0;
  for (int i = 0; i < n; i++){
    if (s[i] == '>' && s[((i - 1) + n) % n] == '>'){
      adj++;
    }
    if (s[i] == '<' && s[((i - 1) + n) % n] == '<'){
       adj++;
    }
    if (s[i] == '-' || s[((i - 1) + n) % n] == '-'){
       good++;
    }
    if (s[i] == '<' && s[((i - 1) + n) % n] == '>'){
       bad++;
    }
    if (s[i] == '>' && s[((i - 1) + n) % n] == '<'){
       bad++;
    }
  }
  // cout << "good : " << good << " bad : " << bad << " adkj : " << adj << endl;
  if (bad >= 1) cout << good << endl;
  else cout << (good + adj) << endl;
}

int main(){
    ios :: sync_with_stdio(false); 
    cin.tie(nullptr); 
    cout.tie(nullptr);
    int tt = 1;
    for(int tc = 1; tc <= tt; tc++){
        // cout << "Case #" << tc << ": ";
        solve();
    }
}
