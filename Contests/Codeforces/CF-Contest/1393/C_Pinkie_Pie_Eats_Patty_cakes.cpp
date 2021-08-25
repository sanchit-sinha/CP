#include "bits/stdc++.h"
using namespace std; 

#define IOS {ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);}
#define ll long long 

int main(){
    IOS;
    ll T;
    cin>>T;
    while(T--){
        ll n;
        cin>>n;ll a[n];
        map<ll,ll> ct;
        multiset<pair<ll,ll>> s;
        for(ll i=0;i<n;i++){
            cin>>a[i];
            ct[a[i]]++;
        }

        for(auto it=ct.begin() ;it !=ct.end() ;++it) s.insert(make_pair(-(it->second),it->first));


        ll l=0,r=n-2,mid=0,ans=0;
        while(l<=r){
            mid=(l+(r-l)/2);

            bool vis[n]={0};
            bool ok=1;

            set<ll> index;
            for(ll i=0;i<n;i++) index.insert(i);

            multiset<pair<ll,ll> >s1=s;
            for(auto it=s1.begin();it!=s1.end();it++){
                ll cnt=-(it->first);
                ll x=it->second;
                // cout << x <<" " << cnt<<"\n";

                if((int)index.size()==0){
                    ok=0;
                    break;
                }

                ll pos=*index.begin();
                vis[pos]=1;
                ll prev=pos;
                index.erase(index.find(pos));

                for(ll j=1;j<cnt;j++){
                    ll pos=prev+mid+1;
                    
                    if(pos<n) {
                        auto it=index.lower_bound(pos);
                        if(it != index.end()) {
                            vis[*it]=1;
                            prev=*it;
                        }
                        else{
                            ok=0;
                            break;
                        }
                    }
                    else{
                        ok=0;
                        break;
                    }

                }

                if(!ok) break;
            }

            // cout << l <<" " << mid <<" " << r<<"\n";
            if(ok) l=mid+1,ans=mid;
            else r=mid-1;
        }
        cout<<ans<<"\n";
    }    

}