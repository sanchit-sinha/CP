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
ll value(string &new_s , ll cj , ll jc){
    ll len = sz(new_s);
    ll ans = 0;
    FOR(i , 0 , len - 2){
        if(new_s[i + 1] == 'C' && new_s[i] == 'J') {
            // cout << "JC " << new_s[i] << " " << new_s[i + 1] << "\n";
            ans += jc;
        }
        if(new_s[i + 1] == 'J' && new_s[i] == 'C') {
            // cout << "CJ " << new_s[i] << " " << new_s[i + 1] << "\n";
            ans += cj;
        }
    }
    return ans;
}
void fill(string &s , ll cj , ll jc){
    ll n = sz(s);
    FOR(i , 1 , n - 2){
        char before = s[i - 1];
        if(s[i] == '?'){
            if(cj + jc < 0){
                if(before == 'C') s[i] = 'J';
                if(before == 'J') s[i] = 'C';
            }
            else{
                if(before == 'C') s[i] = 'C';
                if(before == 'J') s[i] = 'J';
            }
        }   
    }
}

void solve(){
    ll x , y;
    cin >> x >> y;
    string s;
    cin >> s;

    ll cj = x;
    ll jc = y;

    ll n = sz(s);
    string new_s;
    rep(i , n){
        if(s[i] != '?') new_s.pb(s[i]);
    }

    ll ans = value(new_s , cj , jc);

    if(x >= 0 && y >= 0) cout << ans << "\n";
    else{
        new_s.clear();
        n = sz(s);
        ll ans = inf;
        
        string s1 = s;
        string s2 = s;
        string s3 = s;
        string s4 = s;
        if(s[0] == '?'){
            s1[0] = 'C';
            s2[0] = 'C';
            s3[0] = 'J';
            s4[0] = 'J';
        }

        if(s[n - 1] == '?'){
            s1[n - 1] = 'C';
            s2[n - 1] = 'C';
            s3[n - 1] = 'J';
            s4[n - 1] = 'J';
        }   

        fill(s1 , cj , jc);
        fill(s2 , cj , jc);
        fill(s3 , cj , jc);
        fill(s4 , cj , jc);

        ans = min(ans , value(s1 , cj , jc));
        ans = min(ans , value(s2 , cj , jc));
        ans = min(ans , value(s3 , cj , jc));
        ans = min(ans , value(s4 , cj , jc));


        cout << ans << "\n";
    }
}

int main(){
    IOS;
    cout<<fixed<<setprecision(20);
    #ifdef SIEVE
        sieve();
    #endif
    #ifdef NCR
        factorial();
    #endif
    ll NTC=1;
    cin>>NTC;
    ll PTC=0;
    while((PTC++)<NTC){
        cout<<"Case #"<<PTC<<":"<<' ';
        solve();
        //cout<<"\n";
    }
    //cerr<<"Time : "<<1000*((double)clock())/(double)CLOCKS_PER_SEC<<"ms\n";
}

ll power(ll x,ll y){if(y==0) return 1;ll a=power(x,y/2);if(y%2==0) return a*a;else return x*a*a;}
ll powermod(ll x,ll ex,ll md){ll ans=1ll;while(ex>0){if(ex&1ll) ans=(ans*x)%md; ex>>=1ll;x=(x*x)%md;}return ans;}
