/**
 *    Author:  Sanchit Sinha
 *    Created: 17.10.2020 00:12:38       
**/
#include "bits/stdc++.h"
using namespace std; 
 
#define ll long long 
ll powermod(ll x,ll ex,ll md){ll ans=1ll;while(ex>0){if(ex&1ll) ans=(ans*x)%md; ex>>=1ll;x=(x*x)%md;}return ans;}
inline ll gcd(ll a,ll b) {if(b==0)return a;a%=b;return gcd(b,a);}
inline ll max(ll a,ll b) {return((a>b)?a:b);}
inline ll min(ll a,ll b) {return((a>b)?b:a);}
 
int main(){
        ios::sync_with_stdio(false);
        cin.tie(0);
        ll n;
        cin>>n;
        ll a[n],sum=0;
        for(ll i=0;i<n;i++) a[i]=i+1,sum+=a[i];
        if(sum&1) cout<<"NO\n";
        else{
                multiset<ll> v1,v2;
                sort(a,a+n);
                ll half_sum=sum/2;
                sum=0;
                for(ll i=n-1;i>=0;i--){
                        sum+=a[i];
                        if(sum<=half_sum) v1.insert(a[i]);
                        else v2.insert(a[i]);
                }
                sum=0;
                for(auto it=v1.begin();it!=v1.end();it++) sum+=(*it);
                ll element=half_sum-sum;
                auto it=v2.find(element);
                if(it!=v2.end()){
                        v2.erase(it);
                        v1.insert(*it);
                }
 
                cout<<"YES\n";
                cout<<(int)v1.size()<<"\n";
                for(auto it=v1.begin();it!=v1.end();it++) cout<<*it<<" ";
                cout<<"\n";
                cout<<(int)v2.size()<<"\n";
                for(auto it=v2.begin();it!=v2.end();it++) cout<<*it<<" ";
                cout<<"\n";
        }
        return 0;
}