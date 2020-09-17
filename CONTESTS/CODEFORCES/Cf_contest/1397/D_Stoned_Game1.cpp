#include "bits/stdc++.h"
using namespace std; 

#define IOS {ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);}
#define ll long long 

inline ll gcd(ll a,ll b) {if(b==0)return a;a%=b;return gcd(b,a);}
inline ll max(ll a,ll b) {return((a>b)?a:b);}
inline ll min(ll a,ll b) {return((a>b)?b:a);}
ll powermod(ll x,ll ex,ll md){ll ans=1ll;while(ex>0){if(ex&1ll) ans=(ans*x)%md; ex>>=1ll;x=(x*x)%md;}return ans;}

// every player tries to choose pile with max stones
int main(){
        IOS;
        ll T;
        cin>>T;
        while(T--){
                ll n;
                cin>>n;
                ll a[n];
                for(ll i=0;i<n;i++) cin>>a[i];
                multiset< pair<ll,ll> > s;
                for(ll i=0;i<n;i++) s.insert(make_pair(a[i],i));
                bool turn1=1;
                // 1->T , 2->HL
                ll previous_index=-1;
                while(1){
                        ll choosen_index=-1;
                        ll val =-1;
                        bool got=0;
                        for(auto it=s.rbegin() ;it!= s.rend();it++){
                                ll index=it->second;
                                if(index != previous_index){
                                        got=1;
                                        choosen_index=index;
                                        val=it->first;
                                        break;
                                }
                        }
                        if(!got){
                                if(!turn1) cout<<"T\n";
                                else cout<<"HL\n";
                                break;
                        }
                        else{
                                s.erase(s.find(make_pair(val,choosen_index)));
                                val--;
                                if(val) s.insert(make_pair(val,choosen_index));
                                previous_index=choosen_index;
                                turn1=!turn1;
                        }
                }
        }    
}