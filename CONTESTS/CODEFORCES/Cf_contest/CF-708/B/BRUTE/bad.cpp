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
    ll n , mod;
    cin >> n >> mod;
    ll a[n];
    rep(i , n) cin >> a[i];

    rep(i , n) a[i] %= mod;

    map<ll , ll > m;
    ll ans = 0 ;
    rep(i , n) m[a[i]]++;
    while(!m.empty()){
        ll ele = m.begin()->f;
        if(ele == 0){
            cout << "in1 \n";
            ans++;
            m.erase(m.find(ele));
        }
        else if(mod%2 == 0 && ele == mod/2){
            cout << "in2 \n";
            ans++;
            m.erase(m.find(ele));
        }
        else{
            ll ct = m[ele];
            ll rem = mod - ele;

            auto it = m.find(rem);
            if(it != m.end()){
                ll mn = (m[ele] , m[rem]);
                m[ele] -= mn;
                m[rem] -= mn;

                cout << ele << " " << rem << "\n";
                cout << m[ele] << " " << m[rem] << "\n"; 
                ans++;
                if(m[ele]) m[ele]--;
                else if(m[rem]) m[rem]--;

                if(m[ele]) ans += m[ele];
                else if(m[rem]) ans += m[rem];

                m.erase(m.find(ele));
                m.erase(m.find(rem));
            }
            else{
                ans += m[ele];
                m.erase(m.find(ele));
            }
        }
    }

    cout << ans << "\n";
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