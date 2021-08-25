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

    ll n , k;
    cin >> n>> k;

    vll v;
    rep( i ,26) v.pb((1ll << i));

    ll ct[26] = {0};

    ll temp = k;
    ct[25] = temp/v[25];
    temp %= v[25];

    while(temp){
        ll index = -1;
        FORR(i , 25 , 0){
            if(v[i] <= temp){
                ct[i] += temp/v[i];
                temp %= v[i];

                break;
            }
        }
    }

    // rep(i , 26) cout << ct[i] <<" ";
    // cout << "\n";

    ll tot = 0;
    rep(i , 26) tot += ct[i];

    if(tot > n || n > k) cout << -1 << "\n";
    else{
        ll rem = n - tot;
        FORR(i , 25 , 1){
            if(rem == 0) break;
            if(ct[i]){
                if(rem > ct[i]){
                    ct[i - 1] += 2*ct[i];
                    rem -= ct[i];
                    ct[i] = 0 ;
                }
                else{
                    ct[i] -= rem;
                    ct[i - 1] += 2*rem;
                    rem = 0;
                }

            }

        }

        if(rem) cout << -1 << "\n";
        else{
            rep(i , 26){
                rep(j , ct[i]){
                    cout << (char)('a' + i);
                }
            }
            cout << "\n";
        }   
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

