/**
 *    Author:  Sanchit Sinha
 *    Created: 28.10.2020 12:13:27       
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
ll find(string &s){
    ll n=sz(s),ans=0;
    rep(i,n){
        if(i==0){
            if(s[i]=='W') ans++;
        }
        else{
            if(s[i]=='W'){
                if(s[i-1]=='W') ans+=2;
                else ans++;
            }
        }
    }
    return ans;
}
void solve(){
    ll n,k;
    string s;
    cin>>n>>k>>s;
    vll win;
    ll loses=0; 
    rep(i,n){
        if(s[i]=='L') loses++;
        else win.pb(i);
    }
    ll len=sz(win);
    if(sz(win)==0){
        rep(i,min(k,n)) s[i]='W';
        cout<<find(s)<<"\n";
        return;
    }
    ll in_between=loses-win[0]-(n-1-win[len-1]);
    
    if(in_between<=k){
        rep(i,n){
            if(i>=win[0] && i<=win[len-1]) s[i]='W';
        }
        ll rem=k-in_between;
        for(ll i=win[0]-1;i>=0;i--){
            if(rem==0) break;
            else s[i]='W',rem--;
        }
        for(ll i=win[len-1]+1;i<n;i++){
            if(rem==0) break;
            else s[i]='W',rem--;
        }
    }
    else{
        // cout <<" in1 \n";
        vector<pair<ll,pll>> gaps;
        rep(i,sz(win)){
            if(i==0) continue;
            else{   
                ll x=win[i]-win[i-1]-1;
                if(x) gaps.pb(mp(x,mp(win[i-1],win[i])));
            }
        }   
        sort(all(gaps));
        rep(i,sz(gaps)){
            ll length_of_gap=gaps[i].first;
            ll index1=gaps[i].second.first;
            ll index2=gaps[i].second.second;
            if(length_of_gap<=k){
                k-=length_of_gap;
                FOR(j,index1+1,index2-1) s[j]='W';
            }
            else{
                FOR(j,index1+1,index2-1){
                    if(k==0) break;
                    else{
                        k--;
                        s[j]='W';
                    }
                }
            }

            if(in_between==0) break;
        }
    }
    cout<<find(s)<<"\n";
    return ;
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
    cerr<<"Time : "<<1000*((double)clock())/(double)CLOCKS_PER_SEC<<"ms\n";
}

ll power(ll x,ll y){if(y==0) return 1;ll a=power(x,y/2);if(y%2==0) return a*a;else return x*a*a;}
ll powermod(ll x,ll ex,ll md){ll ans=1ll;while(ex>0){if(ex&1ll) ans=(ans*x)%md; ex>>=1ll;x=(x*x)%md;}return ans;}
