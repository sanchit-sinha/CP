#include "bits/stdc++.h"
using namespace std; 
 
#define IOS {ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);}
#define ll long long 
 
const ll N=2e5+11;
ll n,k,a[N];
 
int main(){
    IOS;
    cin>>n>>k;
    vector<pair<ll,ll>> movies;
    for(ll i=0;i<n;i++){
        ll x,y;cin>>x>>y;
        movies.push_back({y,x});
    }
    sort(movies.begin(),movies.end());
    
    ll movies_watched=0;
    multiset<ll> time;
    for(ll i=0;i<n;i++){
        ll l=movies[i].second,r=movies[i].first;
        if(i==0){
            movies_watched++;
            time.insert(r);
        }
        else{
            auto it=time.upper_bound(l);
            if(it==time.begin()){
                ll len=(int)(time.size());
                if(len<k) time.insert(r),movies_watched++;
            }
            else{   
                it--;
                time.erase(it);
                time.insert(r);
                movies_watched++;
            }
        }
    }

    cout<<movies_watched<<"\n";
}
