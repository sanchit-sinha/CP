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

mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
ll range(ll l ,ll r){
    ll n = uniform_int_distribution<int> (l , r)(rng);
    return n;
}


void solve(){
    int n;
    cin >> n;

    map<pair<int , pair<int , int>> , int> cache;

    auto ask = [&](int i , int j , int k){
        vector<int> v;
        v.push_back(i);
        v.push_back(j);
        v.push_back(k);
        sort(v.begin(), v.end());

        if(cache.count(make_pair(v[0] , make_pair(v[1] , v[2])))){
            return cache[make_pair(v[0] , make_pair(v[1] , v[2]))];
        }
        cout << "? " << v[0] << " " << v[1] << " " << v[2] << endl;
        cout.flush();
        int ret;
        cin >> ret;
        cache[make_pair(v[0] , make_pair(v[1] , v[2]))] = ret;
        return ret;
    };

    auto answer = [&](int i , int j){
        cout << "! " << i << " " << j << endl;
        cout.flush();
    };

    vector<pair<int , int>> vals;

    set<int> values;

    int i1 = -1; 
    int i2 = -1;

    vector<pair<int , int>> checks(5);
    checks[0] = {ask(1 , 2 , 3), 4};
    checks[1] = {ask(1 , 2 , 4), 3};
    checks[2] = {ask(1 , 3 , 4), 2};
    checks[3] = {ask(2 , 3 , 4), 1};

    sort(checks.begin(), checks.end());
    i1 = checks[3].second;
    i2 = checks[2].second;


    for(int i = 1 ; i <= n; i++){
        if(i == i1 || i == i2) continue;
        int val = ask(i1 , i2 , i);
        vals.push_back(make_pair(val , i));
        values.insert(val);
    }


    // n - 2 queries done

    sort(vals.begin(), vals.end());
    int mxid = vals.back().second;

    int p = i1;
    vals.clear();
    for(int i = 1; i <= n; i++){
        if(i == p || i == mxid) continue;
        int v = ask(p , i , mxid);
        vals.push_back(make_pair(v , i));
    }

    sort(vals.begin() , vals.end());

    int test = ask(1 , 2 , 3);

    int zid = vals.back().second;

    answer(mxid , zid);

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
