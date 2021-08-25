#include "bits/stdc++.h"
using namespace std; 

#define IOS {ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);}
#define ll long long 

int main(){
        IOS;
        ll T;
        cin>>T;
        for(ll PTC=1;PTC<=T;PTC++){
                cout<<"Case #"<<PTC<<":"<<' ';
                ll n;
                cin>>n;
                ll e[n],r[n];
                for(ll i=0;i<n;i++) cin>>e[i]>>r[i];
                if(n==1){
                        cout<<0<<" "<<e[0]<<"\n";
                        continue;
                }
                map<ll,ll> removal;
                ll mx=LLONG_MIN;
                for(ll i=1;i<(1ll<<n);i++){
                        vector<ll> bit(n,0);
                        ll temp=i,index=0,unset=0,ans=0,sum=0;
                        while(temp){
                                bit[index++]=temp%2;                                
                                temp/=2;
                        }
                        for(ll j=0;j<n;j++) if(!bit[j]) unset++;
                        if(unset==n-1){
                                for(ll j=0;j<n;j++) if(bit[j]) ans=e[j];
                                auto it=removal.find(ans);
                                if(it==removal.end()) removal[ans]=unset;
                                else removal[ans]=min(removal[ans] , unset);
                                mx=max(mx,ans);
                                continue;
                        }
                        for(ll j=0;j<n;j++) if(bit[j]) sum+=e[j];
                        ans=sum;
                        bool end=0;
                        for(ll j=0;j<n;j++){
                                if(bit[j]){
                                        if(sum<r[j]+e[j]){
                                                end=1;
                                                break;
                                        }
                                        else ans+=e[j];
                                }
                        }
                        if(!end) ans=LLONG_MAX;
                        mx=max(mx,ans);
                        auto it=removal.find(ans);
                        if(it==removal.end()) removal[ans]=unset;
                        else removal[ans]=min(removal[ans] , unset);
                }
                if(mx==LLONG_MAX) cout<<removal[mx]<<" "<<"INDEFINITELY\n";
                else cout<<removal[mx] <<" " << mx<<"\n";
        }    
}