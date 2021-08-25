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

string inc(string s){
    // increase string by 1
    ll n = sz(s);
    reverse(all(s));
    rep(i , n){
        if(s[i] != '9'){
            s[i]++;
            reverse(all(s));
            return s;
        }
        else s[i] = '0';
    }

    if(s[0] == '0') s.pb('1');
    reverse(all(s));
    return s;

}
bool onlyappend(string old , string neww){
    ll len = min(sz(old) , sz(neww));
    rep(i , len){
        if(old[i] != neww[i]) return 0;
    }
    return 1;
}

string gr(string s , string t){
    ll n = sz(s);
    ll m = sz(t);

    if(n > m) return s;
    if(n < m) return t;

    rep(i , n){
        if(s[i] > t[i]) return s;
        else if(s[i] < t[i]) return t;
    }

    return "-1";
}
void solve(){
    ll n;   
    cin >> n;

    string a[n];
    rep(i , n) cin >> a[i];

    ll ans = 0;
    FOR(i , 1 , n - 1){
        string pres = a[i];
        string prev = a[i - 1];

        string big = gr(pres , prev);
        if(big != pres){
            // pres <= prev 
            // make pres > prev
        
            // cout << i << ": " << prev << " " << pres <<"\n";
            if(big == "-1"){
                // pres == prev

                // cout << "nobuig " << prev << " " << pres << "\n";
                pres += '0';
                a[i] = pres;
                ans++;
            }
            else{
                // pres < prev
                string newprev = inc(prev);
                if(onlyappend(pres , newprev)){
                    // cout << " only append "  << newprev << " " << pres <<"\n";
                    a[i] = newprev;
                    ans += (sz(newprev) - sz(pres));
                }
                else{
                    while(sz(pres) != sz(prev))  pres = pres + '0';
                    
                    string bigg = gr(pres ,  prev);
                    if(bigg != pres) pres += '0';
                    ans += (sz(pres) - sz(a[i]));
                    a[i] = pres;
                }
            }
        }

    }


    cout << ans << "\n";
    // rep(i , n) cout << a[i] << "\n";


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
