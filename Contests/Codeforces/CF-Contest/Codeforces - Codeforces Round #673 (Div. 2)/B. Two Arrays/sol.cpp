/**
 *    Author:  Sanchit Sinha
 *    Created: 27.09.2020 20:50:04       
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
                ll n,t;
                cin>>n>>t;
                ll a[n];
                map<ll,ll> m,col;
                for(ll i=0;i<n;i++) cin>>a[i] , m[a[i]]++;
                bool half=0;
                for(auto it=m.begin() ; it!=m.end() ; it++){
                        ll x=it->first;
                        if((t%2==0) && (x==t/2)){
                                half=1;
                                continue;
                        }
                        // cout <<" before " << x <<" " << t<<"\n";
                        if(col[x]==0){
                                if(x<=t){
                                        auto it1=m.find(t-x);
                                        if(it1 == m.end()) col[x]=1;
                                        else{
                                                // cout <<" 1 " <<  x << " " << it1->first <<'\n';
                                                col[x]=1;
                                                col[it1->first]=2;
                                        }
                                }
                        }
                }         

                ll ans[n] = {0};
                for(ll i=0;i<n;i++){
                        if(col[a[i]] != 0) ans[i] = col[a[i]] - 1;
                }
                if(half){
                        ll index=0;
                        ll req = m[t/2]/2;
                        for(ll i=0;i<n;i++){
                                if(a[i]==t/2){
                                        if(index<req){
                                                ans[i]=1;
                                                index++;
                                        }
                                        else ans[i]=0;
                                }
                                else continue;
                        }
                }

                for(ll i=0;i<n;i++) cout<<ans[i] <<" " ;
                cout<<"\n";
        }    
        return 0;
}