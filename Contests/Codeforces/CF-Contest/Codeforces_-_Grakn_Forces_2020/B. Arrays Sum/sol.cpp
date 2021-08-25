/**
 *    Author:  Sanchit Sinha
 *    Created: 30.09.2020 21:57:52       
**/
#include "bits/stdc++.h"
using namespace std; 

#define ll long long 
inline ll gcd(ll a,ll b) {if(b==0)return a;a%=b;return gcd(b,a);}
inline ll max(ll a,ll b) {return((a>b)?a:b);}
inline ll min(ll a,ll b) {return((a>b)?b:a);}
ll powermod(ll x,ll ex,ll md){ll ans=1ll;while(ex>0){if(ex&1ll) ans=(ans*x)%md; ex>>=1ll;x=(x*x)%md;}return ans;}

int main(){
        ios::sync_with_stdio(false);
        cin.tie(0);
        ll T;
        cin>>T;
        while(T--){
                ll n,k;
                cin>>n>>k;
                map<ll,ll>m;
                for(ll i=0;i<n;i++){
                        ll x;
                        cin>>x;
                        m[x]++;
                }

                if(k==1){
                        if((int)m.size() == 1) cout<<1<<"\n";
                        else cout<<"-1\n";
                        continue;
                }
                ll ans=1;
                while(true){
                        ll different = (int)m.size();
                        if(different <= k) break;

                        ll index=1;
                        vector<ll> v;
                        for(auto it=m.rbegin() ; it!=m.rend() ; it++){
                                ll x=it->first;
                                if(index == k) v.push_back(x);
                                else{
                                        index++;
                                }
                        }
                        m.clear();
                        for(ll i=0;i<(int)v.size();i++) m[v[i]]++;
                        cout <<"\n\n";
                        ans++;
                }
                cout<<ans<<"\n";                                                                                                
        }    
        return 0;
}