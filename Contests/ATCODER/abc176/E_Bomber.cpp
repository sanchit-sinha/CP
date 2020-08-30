#include "bits/stdc++.h"
using namespace std; 

#define IOS {ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);}
#define ll long long 
multiset<ll> visisted;
// row * 1e6 + col 
const ll x=1e6;
int main(){
        IOS;
        ll n,m,x;
        cin>>n>>m>>x;
        map<ll ,ll > row;
        map<ll ,ll >col;
        for(ll i=0;i<x;i++){
                ll a,b;
                cin>>a>>b;
                ll p=a*(x) + b;
                visisted.insert(p);
                row[a]++;
                col[b]++;
        }
        
        ll mx1=0,mx2=0;
        for(auto it=row.begin() ; it!=row.end() ; it++) mx1=max(mx1,it->second);
        for(auto it=col.begin() ; it!=col.end() ; it++) mx2=max(mx2,it->second);

        set<ll> r1, c1;

        for(auto it=row.begin() ; it!=row.end() ; it++){
                if(it->second == mx1){
                        r1.insert(it->first);
                }
        }


        for(auto it=col.begin() ; it!=col.end() ; it++){
                if(it->second == mx2){ 
                        c1.insert(it->first);         
                }
        }

        bool ok=0;
        for(auto it1=r1.begin() ; it1 != r1.end() ; it1++){
                for(auto it2=c1.begin() ; it2 != c1.end() ; it2++){
                        ll xx = *it1 , yy =*it2;
                        ll num=(xx)*x + yy;
                        auto it=visisted.find(num);
                        if(it == visisted.end()){
                                ok=1;
                                break;
                        }
                }
                if(ok) break;
        }

        if(ok)cout << mx1 + mx2 <<"\n";
        else cout<<mx1 + mx2 -1<<"\n";
}
