#include "bits/stdc++.h"
using namespace std; 

#define IOS {ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);}
#define ll long long 

int main(){
    IOS;
    ll n,x;
    cin>>x>>n;
    set<ll>s ;
    s.insert(0);
    s.insert(x);
    multiset<ll> ans;
    ans.insert(x);
    for(ll i=0;i<n;i++){
        ll y,big,small;
        cin>>y;
        
        auto it=s.upper_bound(y);
        big=*it;it--;
        small=*it;

        ans.erase(ans.find(big-small));
        ans.insert(big-y);
        ans.insert(y-small);

        s.insert(y);
        cout << *ans.rbegin()<<" ";
    }
}
