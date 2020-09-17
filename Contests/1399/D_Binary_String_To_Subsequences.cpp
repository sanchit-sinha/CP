#include "bits/stdc++.h"
using namespace std; 

#define IOS {ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);}
#define ll long long 

int main(){
    IOS;
    ll T;
    cin>>T;
    while(T--){
        ll n;cin>>n;
        string s;
        cin>>s;
        map<ll,vector<pair<ll,ll>>> m;

        ll b[n];
        ll ans=0;
        for(ll i=0;i<n;i++){
            ll x=s[i]-'0';
            // find complementary
            auto it=m.find(x^1);
            if(it==m.end()){
                m[x].push_back(make_pair(i,ans));
                b[i]=ans;
                ans++;
            }
            else{
                auto last=m[x^1].rbegin();

                ll index=last->first;
                ll val=last->second;

                m[x^1].pop_back();
                ll size=(int)(m[x^1].size());
                if(size==0) m.erase(m.find(x^1));

                m[x].push_back(make_pair(i,val));
                b[i]=val;
            }
        }

        cout << ans<<"\n";
        for(ll i=0;i<n;i++) cout<<b[i]+1<<" ";
        cout<<"\n";
    }    
}