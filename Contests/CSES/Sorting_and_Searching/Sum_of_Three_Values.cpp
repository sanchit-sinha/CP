#include "bits/stdc++.h"
using namespace std; 

#define IOS {ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);}
#define ll long long 

ll n,target,a[5001];
map<ll,multiset<ll>>m;

int main(){
    IOS;
    cin>>n>>target;
    for(ll i=0;i<n;i++){
        cin>>a[i];
        m[a[i]].insert(i);
    }

    bool found=0;
    for(ll i=0;i<n;i++){
        for(ll j=i+1;j<n;j++){
            ll sum=a[i]+a[j];
            auto it=m.find(target-sum);
            if(it!=m.end()){
                for(auto k:m[target-sum]){
                    if(k!=i && k!=j){
                        cout<<i+1<<" "<<j+1<<" "<<k+1<<"\n";
                        found=1;
                        break;
                    }
                }
                if(found) break; 
            }
            if(found) break;
        }
        if(found) break;
    }
    
    if(!found) cout<<"IMPOSSIBLE\n";
}
