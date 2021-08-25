/**
 *    Created: 17.11.2020 21:05:04       
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
void solve(){
    ll n,m;
    cin>>n>>m;
    string s[n];
    ll a[n][m];
    rep(i,n) cin>>s[i];
    rep(i,n){
        rep(j,m){
            a[i][j]=(s[i][j] - '0');
        }
    }

    //FIRST
    vector<tuple<pll,pll,pll>> v;
    for(ll i=0;i<n-2;i++){
        for(ll j=0;j<m;j+=2){
            ll index1=j,index2=j+1;
            if(index2<m){
                if(a[i][index1] && a[i][index2]){
                    a[i][index1]=a[i][index2]=0;
                    a[i+1][index1]=!a[i+1][index1];
                    v.pb(mt(mp(i,index1) , mp(i,index2) , mp(i+1,index1)));
                }
                else{
                    if(a[i][index1]==1 && a[i][index2]==0){
                        a[i][index1]=0;
                        a[i+1][index1]=!a[i+1][index1];
                        a[i+1][index2]=!a[i+1][index2];
                        v.pb(mt(mp(i,index1) , mp(i+1,index1) ,mp(i+1,index2)));
                    }
                    else if(a[i][index2]==1 && a[i][index1]==0){
                        a[i][index2]=0;
                        a[i+1][index1]=!a[i+1][index1];
                        a[i+1][index2]=!a[i+1][index2];
                        v.pb(mt(mp(i,index2) , mp(i+1,index1) , mp(i+1,index2)));
                    }
                }
            }
            else{
                if(a[i][index1]==1){
                    a[i][index1]=0;
                    a[i+1][index1]=!a[i+1][index1];
                    a[i+1][index1-1]=!a[i+1][index1-1];
                    v.pb(mt(mp(i,index1) , mp(i+1,index1) , mp(i+1 , index1-1)));
                }
            }
        }
    }


    // rep(i,n){
    //     rep(j,m) cout<<a[i][j]<<" ";
    //     cout<<"\n";
    // }
    // cout<<"\n";
    // cout<<"-----------------\n";

    // SECOND
    for(ll j=0;j<m-1;j++){
        ll row1=n-2,row2=n-1;
        ll nxtcol=j+1;
        if(nxtcol<m){
            if(a[row1][j]==1 && a[row2][j]==1){
                a[row1][j]=a[row2][j]=0;
                a[row1][nxtcol]=!a[row1][nxtcol];
                v.pb(mt(mp(row1,j) , mp(row2,j) ,mp(row1,nxtcol)));
            }
            else{
                if(a[row1][j]==1 && a[row2][j]==0){
                    a[row1][j]=0;
                    a[row1][nxtcol]=!a[row1][nxtcol];
                    a[row2][nxtcol]=!a[row2][nxtcol];
                    v.pb(mt(mp(row1,j) , mp(row1,nxtcol) ,mp(row2,nxtcol)));
                }
                else if(a[row2][j]==1 && a[row1][j]==0){
                    a[row2][j]=0;
                    a[row1][nxtcol]=!a[row1][nxtcol];
                    a[row2][nxtcol]=!a[row2][nxtcol];
                    v.pb(mt(mp(row2,j) , mp(row1,nxtcol) ,mp(row2,nxtcol)));
                }
            }
        }
    }

    // rep(i,n){
    //     rep(j,m) cout<<a[i][j]<<" ";
    //     cout<<"\n";
    // }
    // cout<<"\n";
    // cout<<"-----------------\n";

    ll row1=n-2,row2=n-1,col=m-1,prevcol=m-2;
    if(a[row1][col] == 1 && a[row2][col] == 1 && a[row1][prevcol]==0 && a[row2][prevcol]==0){
        a[row1][prevcol]=!a[row1][prevcol];
        a[row2][prevcol]=!a[row2][prevcol];
        a[row1][col]=!a[row1][col];
        v.pb(mt(mp(row1,prevcol) ,mp(row2,prevcol) ,mp(row1,col)));
        v.pb(mt(mp(row1,prevcol) , mp(row2,prevcol) ,mp(row2,col)));
        a[row1][prevcol]=!a[row1][prevcol];
        a[row2][prevcol]=!a[row2][prevcol];
        a[row2][col]=!a[row2][col];
    }

    if(a[row1][col]==1 && a[row2][col]==0 && a[row1][prevcol]==0 && a[row2][prevcol]==0){
        a[row1][col]=!a[row1][col];
        a[row1][prevcol]=!a[row1][prevcol];
        a[row2][prevcol]=!a[row2][prevcol];
        v.pb(mt(mp(row1,col) ,mp(row1,prevcol) ,mp(row2,prevcol)));
        a[row1][prevcol]=!a[row1][prevcol];
        a[row1][col]=!a[row1][col];
        a[row2][col]=!a[row2][col];
        v.pb(mt(mp(row1,prevcol) ,mp(row1,col) , mp(row2,col)));
        a[row2][prevcol]=!a[row2][prevcol];
        a[row1][col]=!a[row1][col];
        a[row2][col]=!a[row2][col];
        v.pb(mt(mp(row2,prevcol) ,mp(row1,col) ,mp(row2,col)));
    }

    if(a[row2][col]==1 && a[row1][col]==0 && a[row1][prevcol]==0 && a[row2][prevcol]==0){
        a[row2][col]=!a[row2][col];
        a[row1][prevcol]=!a[row1][prevcol];
        a[row2][prevcol]=!a[row2][prevcol];
        v.pb(mt(mp(row2,col) ,mp(row1,prevcol) ,mp(row2,prevcol)));
        a[row1][prevcol]=!a[row1][prevcol];
        a[row1][col]=!a[row1][col];
        a[row2][col]=!a[row2][col];
        v.pb(mt(mp(row1,prevcol) ,mp(row1,col) , mp(row2,col)));
        a[row2][prevcol]=!a[row2][prevcol];
        a[row1][col]=!a[row1][col];
        a[row2][col]=!a[row2][col];
        v.pb(mt(mp(row2,prevcol) ,mp(row1,col) ,mp(row2,col)));
    }
    
    ll ct=0;
    ct+=(a[row1][col]==1);
    ct+=(a[row2][col]==1);
    ct+=(a[row1][prevcol]==1);
    ct+=(a[row2][prevcol]==1);
    if(ct==3){
        if(a[row1][prevcol]==1 && a[row2][prevcol]==1 && a[row1][col]==1 && a[row2][col]==0) {
            v.pb(mt(mp(row1,prevcol) , mp(row2,prevcol) , mp(row1,col)));
            a[row1][prevcol]=!a[row1][prevcol];
            a[row2][prevcol]=!a[row2][prevcol];
            a[row1][col]=!a[row1][col];
        }
        if(a[row1][prevcol]==1 && a[row2][prevcol]==1 && a[row2][col]==1 && a[row1][col]==0){
            v.pb(mt(mp(row1,prevcol) , mp(row2,prevcol) , mp(row2,col)));
            a[row1][prevcol]=!a[row1][prevcol];
            a[row2][prevcol]=!a[row2][prevcol];
            a[row2][col]=!a[row2][col];
        }
        if(a[row1][col]==1 && a[row2][col]==1 && a[row2][prevcol]==1 && a[row1][prevcol]==0){
            v.pb(mt(mp(row1,col) , mp(row2,col) ,mp(row2,prevcol)));
            a[row1][col]=!a[row1][col];
            a[row2][col]=!a[row2][col];
            a[row2][prevcol]=!a[row2][prevcol];
        }
        if(a[row1][col]==1 && a[row2][col]==1 && a[row1][prevcol]==1 && a[row2][prevcol]==0){
            v.pb(mt(mp(row1,col) , mp(row2,col) ,mp(row1,prevcol)));
            a[row1][col]=!a[row1][col];
            a[row2][col]=!a[row2][col];
            a[row1][prevcol]=!a[row1][prevcol];
        }
    }

    if(ct==4){
        a[row1][prevcol]=!a[row1][prevcol];
        a[row2][prevcol]=!a[row2][prevcol];
        a[row2][col]=!a[row2][col];
        v.pb(mt(mp(row1,prevcol) , mp(row2,prevcol) , mp(row2,col)));
        a[row1][prevcol]=!a[row1][prevcol];
        a[row2][prevcol]=!a[row2][prevcol];
        a[row1][col]=!a[row1][col];
        v.pb(mt(mp(row1,prevcol) , mp(row2,prevcol) , mp(row1,col)));
        a[row1][prevcol]=!a[row1][prevcol];
        a[row1][col]=!a[row1][col];
        a[row2][col]=!a[row2][col];
        v.pb(mt(mp(row1,prevcol) , mp(row1,col) ,mp(row2,col)));
        a[row2][prevcol]=!a[row2][prevcol];
        a[row1][col]=!a[row1][col];
        a[row2][col]=!a[row2][col];
        v.pb(mt(mp(row2,prevcol) , mp(row1,col) , mp(row2,col)));
    }

    // rep(i,n){
    //     rep(j,m) cout<<a[i][j]<<" ";
    //     cout<<"\n";
    // }
    // cout<<"\n";
    // cout<<"-----------------\n";
  
    ll len=sz(v);
    cout<<len<<"\n";
    rep(i,len){
        tuple<pll,pll,pll> t=v[i];
        pll p1=get(0,t);
        pll p2=get(1,t);
        pll p3=get(2,t);
        cout<<p1.f+1 <<" "<< p1.s+1<<" "<<p2.f+1<<" " <<p2.s+1<<" "<<p3.f+1<<" "<<p3.s+1<<"\n";
    }
    // cout<<"---ANS------\n\n";
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
