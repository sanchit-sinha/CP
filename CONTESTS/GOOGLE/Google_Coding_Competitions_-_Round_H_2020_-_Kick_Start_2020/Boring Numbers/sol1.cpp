/**
 *    Author:  Sanchit Sinha
 *    Created: 15.11.2020 08:43:59       
**/
#include "bits/stdc++.h"
using namespace std;
#define IOS {ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);}
#define pb push_back
#define nl cout<<"\n"
#define endl "\n"
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
ll power(ll x,ll y);
ll powermod(ll x,ll ex,ll md);

const ll inf = 1e18 + 9;
const ll mod = 1e9 + 7;
const ld PI = acos(-1);
const ld eps = 1e-9;

const ll N = 1e5 + 11;
bool check(ll x){
    bool turn=1;
    ll ct=0;
    ll temp=x;
    while(temp){
        ct++;
        temp/=10;
    }
    temp=x;
    if(ct%2 == 0){
        // even 
        while(x){
            ll rem=x%10;
            if(turn){
                if(rem%2 == 1) return false;
            }
            else{
                if(rem%2 == 0) return false;
            }
            turn=!turn;
            x/=10;
        }
    }
    else{
        while(x){
            ll rem=x%10;
            if(turn){
                if(rem%2 == 0) return false;
            }
            else{
                if(rem%2==1) return false;
            }
            turn=!turn;
            x/=10;
        }
    }
    return true;
}
void solve(){
    ll l,r;
    cin>>l>>r;
    if(r<=1000){
         ll ans=0;
        FOR(i,l,r){
            if(check(i)) ans++;
        }
        cout<<ans<<"\n";
    }
    else{
        ll mn=(l/100)*100 + 100;
        ll mx=(r/100)*100;
        ll dif=0;
        ll ans=((dif)/100)*25;
        // cout<<mx <<" " << mn<<" "<<ans<<"\n";
        FOR(i,l,mn-1){
            if(check(i)) ans++;
        }
        // cout<<ans<<"\n";
        FOR(i,mx+1,r){
            if(check(i)) ans++;
        }
        cout<<ans<<"\n";
    }
}
int main(){
    IOS;
    cout<<fixed<<setprecision(20);
    ll NTC=1;
    cin>>NTC;
    ll PTC=0;
    while((PTC++)<NTC){
        cout<<"Case #"<<PTC<<":"<<' ';
        solve();
        //cout<<"\n";
    }
    cerr<<"Time : "<<1000*((double)clock())/(double)CLOCKS_PER_SEC<<"ms\n";
}

ll power(ll x,ll y){if(y==0) return 1;ll a=power(x,y/2);if(y%2==0) return a*a;else return x*a*a;}
ll powermod(ll x,ll ex,ll md){ll ans=1ll;while(ex>0){if(ex&1ll) ans=(ans*x)%md; ex>>=1ll;x=(x*x)%md;}return ans;}
