#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define pi pair<int,int>
#define pll pair<ll,ll>
#define vi vector<int>
#define vll  vector<ll>
#define vvi vector<vi>
#define vvll vector<vll>
#define vpll vector<pll>
#define vpi vector<pi>
#define vvpll vector<vpll>
#define vvpi vector<vpi>
#define vs vector<string>
#define pb push_back
#define eb emplace_back
#define fi first
#define se second
#define ld  long double
#define MP make_pair
#define mapii map<int,int>
#define umapii unordered_map<int,int>
#define mapll map<ll,ll>
#define umapll unordered_map<ll,ll>
#define FOR(i,a,b) for(int i = a; i <= b; i++)
#define FORI(i,a,b) for(int i = a; i >= b; i--)
#define all(v) (v).begin(),(v).end()
#define rall(v) (v).rbegin(),(v).rend()
template<typename T>
inline void read(vector<T> &v , int n){ for(int i = 0; i < n; i++) cin >> v[i]; }
template<typename T>
inline void read(T &n){ cin >> n; }
inline void read(string &s){ cin >> s; }
template<typename T>
inline void dbgc(const char* txt , T &c){ cout << txt << ": "; for (auto it = c.begin(); it != c.end(); it++) cout << *it << " "; cout << endl;}
template<typename T>
inline void dbgx(const char *txt , T x) { cout << txt << ": "; cout << x << endl;}
const int mod = 1e9 + 7;
const int inf = 1e9 + 7;

/*
      . Think dp before greedy
      . Base case
      . Integer overflow
      . while using map don't write mp[x] multiple times
      . mp[x] creates extra entry 
      . Don't compare your progress with others(just keep practicing)
*/
void solve(){
  int n , c0 , c1 , h;
  cin >> n >> c0 >> c1 >> h;
  string s;
  cin >> s;
  int z = 0, o = 0;
  for(auto x : s) 
  {
    if(x == '0') z++;
    else o++;
  }
  int ans = inf;
  for(int fo = 0; fo <= n; fo++)
  {
    int cost = 0;
    if(fo >= o){
      cost = (fo - o) * h + fo * c1 + (n - fo) * c0;  
    } else cost = (o - fo) * h + fo * c1 + (n - fo) * c0;
    ans = min(ans , cost);
  }
  cout << ans << endl;
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
