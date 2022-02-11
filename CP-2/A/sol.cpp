#include <iostream>
#include <iomanip>
#include <cstdio>
#include <cstdlib>
#include <algorithm>
#include <cmath>
#include <vector>
#include <set>
#include <map>
#include <unordered_set>
#include <unordered_map>
#include <queue>
#include <ctime>
#include <cassert>
#include <complex>
#include <string>
#include <cstring>
#include <chrono>
#include <random>
#include <bitset>
#define f                   first
#define s                   second
#define pb                  push_back
#define ll                  long long
#define ld                  long double
#define lb                  lower_bound
#define ub                  upper_bound
#define mt                  make_tuple
#define pll                 pair<ll, ll>
#define pi                  pair<int, int> 
#define vi                  vector<int>
#define vvi                 vector<vi>
#define vpi                 vector<pi>
#define vvpi                vector<vpi>
#define vll                 vector<ll>
#define vvll                vector<vll>
#define vpll                vector<pll>
#define vvpll               vector<vpll>
#define vs                  vector<string>
#define all(c)              (c).begin(),(c).end()
#define sz(c)               (int)((c).size())
#define trav(it,x)           for(auto it = (x).begin(); it != (x).end(); it++)
#define rep(i, n)           for(int i = 0; i < (n) ; i++)
#define FOR(i, a, b)        for(int i = (a); i <= (b); i++)
#define FORR(i, b, a)       for(int i = (b); i >= (a); i--)



using namespace std;

void solve(){
    int n , k;
    cin >> n >> k;
    set<string> st;

    string s;
    cin >> s;

    auto rev = [&](string tmp){
        string r = tmp;
        reverse(r.begin(), r.end());
        return r;
    };
    if(k == 0){
        cout << 1 << endl;
        return;
    }
    if(k == 1){
        st.insert(s + rev(s));
        st.insert(rev(s) + s);
        cout << sz(st) << endl;
        return;
    }
    if(k >= 2){
        string f1 = s + rev(s);
        string f2 = rev(s) + s;
        st.insert(f1 + rev(f1));
        st.insert(f2 + rev(f2));
        cout << sz(st) << endl;
    }
}
 
int main(){
    ios :: sync_with_stdio(false); 
    cin.tie(nullptr); 
    cout.tie(nullptr);

    int tt = 1;
    cin >> tt;

    for(int i = 0; i < tt; i++){
        solve();
    }
}
