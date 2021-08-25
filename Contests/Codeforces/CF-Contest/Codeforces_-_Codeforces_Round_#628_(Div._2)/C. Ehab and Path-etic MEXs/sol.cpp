/**
 *    Author:  Sanchit Sinha
 *    Created: 26.10.2020 01:31:20       
**/
#include "bits/stdc++.h"
using namespace std; 

#define ll long long 
ll powermod(ll x,ll ex,ll md){ll ans=1ll;while(ex>0){if(ex&1ll) ans=(ans*x)%md; ex>>=1ll;x=(x*x)%md;}return ans;}
inline ll gcd(ll a,ll b) {if(b==0)return a;a%=b;return gcd(b,a);}
inline ll max(ll a,ll b) {return((a>b)?a:b);}
inline ll min(ll a,ll b) {return((a>b)?b:a);}

const ll N=1e5+11;
vector<ll> v[N],ans(N,-1);
ll n,x[N],y[N],parent[N];

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin>>n;
    for(ll i=0;i<n-1;i++){
        cin>>x[i]>>y[i];
        v[x[i]].push_back(y[i]);
        v[y[i]].push_back(x[i]);
    }
    // for(ll i=1;i<=n;i++){
    //     ll len=(int)v[i].size();
    //     if(len){
    //         cout << i << ": ";
    //         for(ll j=0;j<len;j++) cout<<v[i][j]<<" ";
    //         cout<<"\n";
    //     }
    // }
    set<ll> s;
    for(ll i=0;i<n-1;i++) s.insert(i);
    if(n==2) cout<<"0\n";
    else if(n==3) cout<<"0\n1\n";
    else{
        set<pair<ll,ll>> got;
        for(ll i=1;i<=n;i++){
            ll len=(int)v[i].size();
            if(len>=3){
                for(ll j=0;j<3;j++){
                    ll child = v[i][j];
                    got.insert({i,child});
                }
                break;
            }   
        }
        // cout << (int)(got).size()<<"\n\n";
        ll index=0;
        if((int)(got.size())){
            for(ll i=0;i<n-1;i++){
                ll xx=x[i],yy=y[i];
                auto it1=got.find(make_pair(xx,yy));
                auto it2=got.find(make_pair(yy,xx));
                if(it1!=got.end() || it2!=got.end()){
                    ans[i]=index;
                    s.erase(s.find(index));
                    index++;
                }
            }
        }
        for(ll i=0;i<n-1;i++){
            if(ans[i]==-1){
                ans[i]=*s.begin();
                cout<<ans[i]<<"\n";
                s.erase(s.begin());
            }
            else cout<<ans[i]<<"\n";
        }
    }
    return 0;
}
