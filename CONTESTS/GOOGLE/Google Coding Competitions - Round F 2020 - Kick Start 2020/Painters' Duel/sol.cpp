/**
 *    author:  Sanchit Sinha
 *    created: 27.09.2020 08:03:16       
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
        for(ll PTC=1;PTC<=T;PTC++){
                cout<<"Case #"<<PTC<<":"<<' ';
                ll s,ra,pa,rb,pb,c;
                cin>>s>>ra>>pa>>rb>>pb>>c;
                pair<ll,ll> closed[c+2];
                for(ll i=0;i<c;i++){
                        ll l,r;
                        cin>>l>>r;
                        closed[i] = make_pair(l,r);
                }
                if(ra==2 && pa==2){
                        if(c==2) cout<<"0\n";
                        else cout<<"1\n";
                }
                else{
                        if(rb==2 && pb==2){
                                if(c==2) cout<<"0\n";
                                else cout<<"-1\n";
                        }
                        else{
                                if(c==0) cout<<"2\n";
                                else if(c==1){
                                        if(closed[0].first==2 && closed[0].second == 2) cout<<"0\n";
                                        else cout<<"1\n";
                                }
                                else cout<<"0\n";
                        }
                }
        }    
}
