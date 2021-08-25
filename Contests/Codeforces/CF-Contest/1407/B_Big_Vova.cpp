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
                multiset<ll> s;
                for(ll i=0;i<n;i++) cin>>a[i],s.insert(a[i]);
                vector<ll> ans;
                auto it=s.end();
                it--;
                ans.push_back(*it);
                s.erase(it);                
                ll g=ans[0];
                while(!s.empty()){
                        ll len=(int)s.size();
                        if(len==n){
                                ll ct=0;
                                for(ll j=0;j<n;j++){
                                        if(a[j]%g==0) ct++;
                                }
                                if(ct>1){
                                        for(ll i=0;i<n;i++){
                                                if(a[i]%g==0){
                                                        ans.push_back(a[i]);
                                                        s.erase(s.find(a[i]));
                                                }
                                        }
                                }
                                else g--;
                        }
                        else{
                                map<ll , vector<ll > > m;
                                for(auto it=s.begin() ; it != s.end() ; it++){
                                        ll x=*it;
                                        ll y=gcd(x , g);
                                        m[y].push_back(x);
                                }
                                for(auto it=m.rbegin() ; it != m.rend() ; it++){
                                        ll x=it->first;
                                        ll len=(it->second).size();
                                        sort((it->second).begin() , (it->second).end() , greater<ll>());
                                        if(len){
                                                for(ll i=0;i<len;i++){
                                                        ans.push_back((it->second)[i]);
                                                        s.erase(s.find((it->second)[i]));
                                                }
                                                g=it->first;
                                                break;
                                        }
                                }
                        }
                }
                for(ll i=0;i<n;i++) cout<<ans[i]<<" ";
                cout<<"\n";
        }    
}       