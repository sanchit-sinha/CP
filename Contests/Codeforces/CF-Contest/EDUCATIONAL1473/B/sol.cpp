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

string find_smallest_repeating(string x){
    ll n = sz(x);
    string ans ;

    string temp;
    FOR( i, 0 , n - 1){
        temp.pb(x[i]);
        ll len = sz(temp);
        if(n%len == 0){
            bool ok = 1;
            ll index = 0;
            FOR(j , i + 1 , n - 1){
                if(x[j] != temp[index]){
                    ok = 0;
                    break;
                }
                else{
                    index++;
                    if(index == len) index = 0;
                }
            }
            if(ok) return temp;
        }
    }
    ans.pb(-1);
    return ans;
}
void solve(){
    string s , t;
    cin >> s >> t;

    string smallest_s = find_smallest_repeating(s);
    string smallest_t = find_smallest_repeating(t);

    // cout << smallest_s << " " << smallest_t <<"\n";

    if(smallest_s != smallest_t) cout << -1 <<"\n";
    else{
        ll len_s = sz(smallest_s);
        ll len_t = sz(smallest_t);

        ll times_s = sz(s)/len_s;
        ll times_t = sz(t)/len_t;

        ll req_len = (times_s * times_t)/gcd(times_t , times_s);

        rep(i , req_len) cout << smallest_t;
        cout <<"\n";
    }
}

int main(){
    IOS;
    cout<<fixed<<setprecision(20);
    ll NTC=1;
    cin>>NTC;
    ll PTC=0;
    while((PTC++)<NTC){
        // cout<<"Case #"<<PTC<<":"<<' ';
        solve();
        //cout<<"\n";
    }
    //cerr<<"Time : "<<1000*((double)clock())/(double)CLOCKS_PER_SEC<<"ms\n";
}

ll power(ll x,ll y){if(y==0) return 1;ll a=power(x,y/2);if(y%2==0) return a*a;else return x*a*a;}
ll powermod(ll x,ll ex,ll md){ll ans=1ll;while(ex>0){if(ex&1ll) ans=(ans*x)%md; ex>>=1ll;x=(x*x)%md;}return ans;}

