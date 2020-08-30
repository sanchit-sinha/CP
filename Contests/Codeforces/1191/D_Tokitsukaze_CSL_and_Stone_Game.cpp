#include "bits/stdc++.h"
using namespace std; 

#define IOS {ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);}
#define ll long long 

ll powermod(ll x,ll ex,ll md){ll ans=1ll;while(ex>0){if(ex&1ll) ans=(ans*x)%md; ex>>=1ll;x=(x*x)%md;}return ans;}
inline ll gcd(ll a,ll b) {if(b==0)return a;a%=b;return gcd(b,a);}
inline ll max(ll a,ll b) {return((a>b)?a:b);}
inline ll min(ll a,ll b) {return((a>b)?b:a);}


int main(){
        IOS;
        ll n;
        cin>>n;
        ll a[n];
        map<ll,ll> m;
        for(ll i=0;i<n;i++){
                cin>>a[i];
                m[a[i]]++;
        }
        sort(a,a+n);
        ll ans=0;
        ll bad_element=-1;
        ll ct_bad_element=0;
        for(auto it=m.begin() ; it!=m.end(); it++){
                if(it->second > 1){
                        ct_bad_element+=(it->second-1);
                        bad_element=it->first;
                }
        }
        // 1->sjfnb , 2 -> cslnb
        if(ct_bad_element>1){
                cout<<"cslnb\n";
                return 0;
        }
        else if(ct_bad_element==1){
                if(bad_element==0){
                        cout<<"cslnb\n";
                        return 0;
                }
                auto it=m.find(bad_element-1);
                if(it != m.end()){
                        cout<<"cslnb\n";
                        return 0;
                }
                else{
                        m[bad_element]--;
                        m[bad_element-1]++;
                }
                bool done=0;
                for(ll i=0;i<n;i++){
                        if(a[i]==bad_element && !done){
                                a[i]--;
                                done=1;
                        }
                }
                ans++;
                sort(a,a+n);
        }
        // 1->sjfnb , 2 -> cslnb
        for(ll i=0;i<n;i++) ans+=(a[i]-i);
        // s c s c s c 
        if(ans&1) cout<<"sjfnb\n";
        else cout<<"cslnb\n";
}
