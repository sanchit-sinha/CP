#include "bits/stdc++.h"
using namespace std; 

#define IOS {ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);}
#define ll long long 

const ll N=1e5+11;
ll n,m,a[N],b[N],indexx[N];

int main(){
        IOS;
        ll T;
        cin>>T;
        while(T--){
                for(ll i=0;i<n;i++) a[i]=b[i]=indexx[i]=0;

                cin>>n>>m;
                for(ll i=0;i<n;i++) cin>>a[i],indexx[a[i]]=i+1;
                for(ll i=0;i<m;i++) cin>>b[i];
                ll r=LLONG_MIN;
                ll del=0,ans=0;
                for(ll i=0;i<m;i++){
                        if(i==0){
                                ll x=indexx[b[i]];
                                r=max(r,indexx[b[i]]);
                                del++;
                                ans=(2*(x-1))+1;
                        }
                        else{
                                ll x=indexx[b[i]];
                                if(x<=r) ans++,del++;
                                else{
                                        r=max(r,x);
                                        del++;
                                        ans+=(2*(x-del))+1;
                                }
                        }
                }
                cout<<ans<<"\n";
        }    
}