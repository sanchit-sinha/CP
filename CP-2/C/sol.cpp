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

    int tot = n * k;

    vector<int> even;
    vector<int> odd;
    for(int i = 1; i <= n * k; i++){
        if(i % 2 == 0) even.push_back(i);
        else odd.push_back(i);
    }

    if(sz(even) % k != 0 || sz(odd) % k != 0){
        cout << "NO" << endl;
        return;
    }
    reverse(even.begin(), even.end());
    reverse(odd.begin(), odd.end());


    cout << "YES" << endl;

    for(int i = 0; i < n; i++){
        if(sz(even) > 0){
            for(int j = 0; j < k; j++){
                cout << even.back() << " ";
                even.pop_back();
            }
            cout << endl;
        } else{
            for(int j = 0; j < k ; j++){
                cout << odd.back() << " ";
                odd.pop_back();
            }
            cout << endl;
        }
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
