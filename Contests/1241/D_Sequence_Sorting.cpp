#include "bits/stdc++.h"
using namespace std; 

#define IOS {ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);}
#define ll long long 

inline ll gcd(ll a,ll b) {if(b==0)return a;a%=b;return gcd(b,a);}
inline ll max(ll a,ll b) {return((a>b)?a:b);}
inline ll min(ll a,ll b) {return((a>b)?b:a);}
ll powermod(ll x,ll ex,ll md){ll ans=1ll;while(ex>0){if(ex&1ll) ans=(ans*x)%md; ex>>=1ll;x=(x*x)%md;}return ans;}


int main(){
       IOS;
       ll T;
       cin>>T;
       while(T--){
               ll n;
               cin>>n;
               ll a[n];
               /*
               final  array-> part moved left + part unchanged + part moved right
                        we need to maximize the unchanged part 
                                                   */
               vector<ll> lower_index(n,LLONG_MAX) , upper_index(n,LLONG_MIN);                                   
               set<ll> elements;
               for(ll i=0;i<n;i++){
                       cin>>a[i];
                       a[i]--;
                       lower_index[a[i]]=min(lower_index[a[i]] , i);
                       upper_index[a[i]]=max(upper_index[a[i]] , i);
                       elements.insert(a[i]);
               }
                ll mx_unchanged_part=0;
                ll present_unchanged_part=0;
                ll previous_index=-1;
                for(auto &x:elements){
                        if(lower_index[x]>previous_index) present_unchanged_part++;
                        else present_unchanged_part=1;
                        previous_index=upper_index[x];
                        mx_unchanged_part=max(mx_unchanged_part , present_unchanged_part);
                }
                cout<<(int)elements.size() - mx_unchanged_part<<"\n";
       }        
}