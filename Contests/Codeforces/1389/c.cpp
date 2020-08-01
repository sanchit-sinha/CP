#include "bits/stdc++.h"
using namespace std; 
#define IOS {ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);}
#define ll long long 
inline ll min(ll a,ll b) {return((a>b)?b:a);}
int main(){
    IOS;
    ll t;
    cin>>t;
    while(t--){
        string s;
        cin >> s;
        ll n=(int)(s.size());
        ll ans=n-2;
        for(ll i=0;i<=9;i++){
            for(ll j=0;j<=9;j++){
                string v;
                if(i==j){
                    for(ll k=0;k<n;k++) if(s[k]-'0'==i) v.push_back(s[k]);
                }
                else{
                    for(ll k=0;k<n;k++){
                        if(s[k]-'0'==i){
                            if((int)(v.size())){
                                char c=v.back();
                                if(s[k]!=c) v.push_back(s[k]);
                            }
                            else v.push_back(s[k]);
                        }
                        if(s[k]-'0'==j){
                            if((int)(v.size())){
                                char c=v.back();
                                if(s[k]!=c) v.push_back(s[k]);
                            }
                            else v.push_back(s[k]);
                        }
                    }
                }
                ll len=(int)(v.size());
                if((len&1) && i!=j) len--;
                ans=min(ans,n-len);
            }
        }

        cout<<ans<<"\n";
    }    
}
