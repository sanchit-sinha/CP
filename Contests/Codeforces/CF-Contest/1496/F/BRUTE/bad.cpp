#include "bits/stdc++.h"
using namespace std;
#define IOS {ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);}
#define pb push_back
#define ll long long
#define ld long double
#define all(c) (c).begin(),(c).end()
#define sz(c) (int)(c.size())
#define mp make_pair
#define mt make_tuple
#define get(x,c) get<x>(c)
#define trav(a,x) for(auto a=x.begin();a!=x.end();a++)
#define rep(i,n) for(int i=0;i<n;i++)
#define FOR(i,a,b) for(int i=a;i<=b;i++)
#define FORR(i,b,a) for(int i=b;i>=a;i--)
#define lb lower_bound
#define ub upper_bound
#define pll pair<ll,ll>
#define vll vector<ll>
#define vpll vector<pll>
#define f first
#define s second

inline ll gcd(ll a,ll b) {if(b==0)return a;a%=b;return gcd(b,a);}
inline ll max(ll a,ll b) {return((a>b)?a:b);}
inline ll min(ll a,ll b) {return((a>b)?b:a);}
ll power(ll x,ll ex);
ll powermod(ll x,ll ex,ll md);

const ll inf = 1e18 + 9;
const ll mod = 1e9 + 7;
const ld PI = acos(-1);
const ld eps = 1e-9;

const ll N = 1e5+11;

ll powermod(ll base  , ll ex , ll mod){
    if(ex == 0) return 1;
    ll half = powermod(base , ex/2 , mod) % mod;
    ll ans = half * half;
    ans %= mod;

    if(ex&1) ans *= base;    
    ans %= mod;
    return ans;
}
void debug(map<ll,ll> &m){
    cout << "***********************************\n";
    for(auto x : m) cout << x.first << " " << x.second << "\n";
    cout << "***********************************\n";
}
vll solve2(vll &A, vll &B) {
    ll n = A.size();
    ll q = B.size();
    
    vector<ll> left(n , -1);
    vector<ll> right(n , n);
    
    for(ll i = 1 ; i < n ; i++){
        if(A[i] < A[i - 1]) left[i] = i - 1;
        else left[i]  = left[i - 1];
    }
    for(ll i = n - 2 ; i >= 0 ; i--){
        if(A[i + 1] > A[i]) right[i] = i + 1;
        else right[i] = right[i + 1];
    }
    
    ll cnt[n];
    for(ll i = 0 ; i < n ; i++){
        cnt[i] = (right[i] - 1 - (left[i] + 1) + 1);
        cout <<  A[i] << ": " << left[i] << " : " << right[i] << " -> " << cnt[i] << "\n";
    }

    cout << "\n";

    map<ll , ll> divisor;
    for(ll i = 0 ; i < n ; i++){
        ll count = cnt[i] , ele = A[i];
        ll prod = 1ll;
        for(ll j = 1 ; j * j <= ele ; j++){
            if(ele%j == 0){
                ll div1 = j;
                ll div2 = ele/j;
                
                prod *= div1;
                prod %= mod;
                if(div1 != div2){
                    prod *= div2;
                    prod %= mod;
                }
                    
            }
        }
        // cout << ele << " : " << tot_fact << " - " << prod << "\n";
        divisor[prod%mod] += count;
    }
    
    debug(divisor);
    
    map<ll , ll> pfx;
    ll ct = 0;
    for(auto it = divisor.rbegin() ; it != divisor.rend() ; it++){
        ct += it->second;
        pfx[ct] = it->first;
    }
    
    debug(pfx);
    
    vector<ll> ans;
    for(ll i = 0 ; i < q ; i++){
        ll index = B[i];
        auto it = pfx.lower_bound(index);
        if(it != pfx.end()){
            ll ct = it->first;
            ans.push_back(pfx[ct]);
        }
        else ans.push_back(0);
        
    }
    
    return ans;
}
void solve(){
    ll n;
    cin >> n;
    vll A(n , 0);
    rep(i , n) cin >> A[i];

    ll q;
    cin >> q;
    vll B(q , 0);
    rep(i , q) cin >> B[i];

    vector<ll> ans = solve2(A,B);
    rep(i , q) cout << ans[i] << " ";
    cout << "\n";
}

int main(){
    IOS;
    cout<<fixed<<setprecision(20);
    ll NTC=1;
    // cin>>NTC;
    ll PTC=0;
    while((PTC++)<NTC){
        // cout<<"Case #"<<PTC<<":"<<' ';
        solve();
        //cout<<"\n";
    }
    //cerr<<"Time : "<<1000*((double)clock())/(double)CLOCKS_PER_SEC<<"ms\n";
}

ll power(ll x,ll y){if(y==0) return 1;ll a=power(x,y/2);if(y%2==0) return a*a;else return x*a*a;}

