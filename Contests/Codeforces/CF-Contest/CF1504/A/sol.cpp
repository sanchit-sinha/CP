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

bool check(string &s){
    ll n = sz(s);
    rep( i, n) if(s[i] != s[n - 1 - i]) return 0;

    return 1;
}
void solve(){
    string s;
    cin >> s;

    ll n = sz(s);
    ll ct =0 ;
    rep( i, n) if(s[i] == 'a') ct++;

    if(ct == n) cout << "No\n";
    else{
        ll index = n;
        rep(i , n){
            if(s[i] != 'a'){
                index = i;
                break;
            }
        }
        ll opp = n - 1 - index;
        string s1 , s2 , s3 , s4 , s5 , s6;

        // first
        s1.pb('a');
        s1 += s;

        // last
        s2 = s;
        s2.pb('a');

        // pos - 1 
        FOR(i , 0 , index - 1) s3.pb(s[i]);
        s3.pb('a');
        FOR(i , index , n - 1) s3.pb(s[i]);

        // pos + 1
        FOR(i , 0 , index) s3.pb(s[i]);
        s3.pb('a');
        FOR(i , index + 1 , n - 1) s3.pb(s[i]);


        // opp - 1
        FOR(i , 0 , opp - 1) s3.pb(s[i]);
        s3.pb('a');
        FOR(i , opp , n - 1) s3.pb(s[i]);

        // opp + 1
        FOR(i , 0 , opp) s3.pb(s[i]);
        s3.pb('a');
        FOR(i , opp + 1 , n - 1) s3.pb(s[i]);
    
        if(!check(s1)){
            cout << "Yes\n";
            cout << s1 << "\n";
            return ;
        }

        if(!check(s2)){
            cout << "Yes\n";
            cout << s2 << "\n";
            return ;
        }

        if(!check(s3)){
            cout << "Yes\n";
            cout << s3 << "\n";
            return ;
        }

        if(!check(s4)){
            cout << "Yes\n";
            cout << s4 << "\n";
            return ;
        }

        if(!check(s5)){
            cout << "Yes\n";
            cout << s5 << "\n";
            return ;
        }

        if(!check(s6)){
            cout << "Yes\n";
            cout << s6 << "\n";
            return ;
        }

        cout << "No\n";
        return;
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
        // cout<<"Case #"<<PTC<<":"<<' ';
        solve();
        //cout<<"\n";
    }
    //cerr<<"Time : "<<1000*((double)clock())/(double)CLOCKS_PER_SEC<<"ms\n";
}

ll power(ll x,ll y){if(y==0) return 1;ll a=power(x,y/2);if(y%2==0) return a*a;else return x*a*a;}
ll powermod(ll x,ll ex,ll md){ll ans=1ll;while(ex>0){if(ex&1ll) ans=(ans*x)%md; ex>>=1ll;x=(x*x)%md;}return ans;}
