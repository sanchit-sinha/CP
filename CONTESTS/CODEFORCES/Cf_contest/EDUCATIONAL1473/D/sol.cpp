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


void solve(){
    ll n , m;
    cin >> n >> m;

    string s , reverse_s;
    cin >> s;
    ll mn[n] , mx[n] , reversemn[n] , reversemx[n];

    rep(i , n){
        if(s[i] == '-') reverse_s.pb('+');
        else reverse_s.pb('-');
    }

    rep(i , n){
        mn[i] = reversemn[i] = 0;
        mx[i] = reversemx[i] = 0;
    }   

    ll pfx[n] = {0};
    rep(i , n){
        if(i == 0){
            if(s[i] == '-') pfx[i] = -1;
            else pfx[i] = 1;
        }
        else{
            if(s[i] == '-') pfx[i] = pfx[i - 1] - 1;
            else pfx[i] = pfx[i - 1] + 1;   
        }
    }
    ll sum = pfx[n - 1];
    rep(i , n){
        if(s[i] == '-') sum -= 1;
        else sum += 1;

        if(i == 0){
            mn[i] = min(0 , sum);
            mx[i] = max(0 , sum);
        }
        else{
            mn[i] = min(mn[i - 1] , sum);
            mx[i] = max(mx[i - 1] , sum);
        }
    }

    // last = 0;
    sum = 0;
    FORR(i , n - 1  ,0){
        if(s[i] == '-') sum -= 1;
        else sum += 1;
    
        if(i == n - 1){
            reversemn[i] = min(0 , sum);
            reversemx[i] = max(0 , sum);
        }
        else{
            reversemn[i] = min(reversemn[i - 1] , sum);
            reversemx[i] = max(reversemx[i - 1] , sum);
        }
    }

    cout <<"PFX---\n";
    FOR( i, 0 , n -1 ) cout << pfx[i] <<" ";
    cout << "\n";
    cout <<"MN------\n";
    FOR(i , 0 , n -1 )  cout << mn[i] << " ";
    cout <<"\n";

    while(m--){
        ll l , r;
        cin >> l >> r;
        l-- , r--;


        l--;
        r++;
        // x ahead , y behind
        ll ans = 0;

        ll pfxtot   = pfx[n - 1];
        ll subs = 0;
        if(l >= 0) subs = pfx[l];
        pfxtot -= subs;

        ll mnx , mxx ;
        if(l == -1) mnx = mxx = 0;
        else{
            mnx = mn[l];
            mxx = mx[l];
        }

        ans = mxx - mnx + 1;


        ll mny , mxy;
        if(r == n){
            mny = pfxtot;
            mxy = pfxtot;
        }
        else{
            mny = reversemn[r] + pfxtot;
            mxy = reversemx[r] + pfxtot;
        }

        ans += mxy - mny + 1;

        ll mnm , mxm ;
        mnm = min({mnx , mxx , mny , mxy});
        mxm = max({mnx , mxx , mny , mxy});

        cout << "---------\n";
        cout <<" l " << l << " r " << r <<"\n"; 
        cout << pfxtot <<"\n";
        cout << mnx <<" " << mxx <<"\n";
        cout << mny <<" " << mxy <<"\n\n";

        cout << mxm - mnm + 1 <<"\n";

    }         




    cerr << "#####################################3\n";
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

