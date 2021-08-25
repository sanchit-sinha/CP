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
ll rtime[] = {0,1,5,-1,-1,2,-1,-1,8,-1};
pll hhmm(string rev){
    ll len = sz(rev);

    ll minutes = 0;
    minutes += (rev[len - 1] - '0');
    minutes += (rev[len - 2] - '0')*10;

    ll hours = 0;
    hours += (rev[1] - '0');
    hours += (rev[0] - '0')*10;

    return mp(hours , minutes);
}
bool check(string s , ll h , ll m){
    ll hr = 0;
    ll mn = 0;

    ll len = sz(s);
    string rev;
    FORR(i , len - 1 , 0){
        if(s[i] == ':') rev.pb(':');
        else{
            ll x = s[i] - '0';
            x = rtime[x];
            if(x == -1) return 0;
            else rev.pb((char)(x + '0'));
        }
    }    

    // cout << rev << "\n";
    pll p = hhmm(rev);
    ll hours = p.f;
    ll minutes = p.s;

    if(hours >= h) return 0;
    if(minutes >= m) return 0;    

    return 1;
}
string gen(ll x ,ll y){
    // 0x:0y or x1x2:y1y2
    bool twox = 1;
    bool twoy = 1;

    if(x/10 == 0) twox = 0;
    if(y/10 == 0) twoy = 0;

    string ans;
    if(twox){
        ll num = x/10;
        char c = num + '0';
        ans.pb(c);
    }
    else ans.pb('0'); 

    ll num = x%10;
    char c = num + '0';
    ans.pb(c);

    ans.pb(':');

    if(twoy){
        ll num2 = y/10;
        char c2 = num2 + '0';
        ans.pb(c2);
    }
    else ans.pb('0');

    ll num1 = y%10;
    char c1 = num1 + '0';
    ans.pb(c1);

    return ans;    

}
void solve(){
    ll h , m;
    cin >> h >> m;

    string s;
    cin >> s;

    // check(s , h , m);
    pll p = hhmm(s);
    ll hr = p.f ;
    ll min = p.s;

    while(1){
        if(min == m){
            min = 0;
            hr++;
        }
        if(hr == h){
            hr = 0;
        }

        string tym = gen(hr , min);
        if(check(tym , h , m)){
            cout << tym << "\n";
            return;
        }

        min++;
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

