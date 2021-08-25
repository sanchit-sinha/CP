#include "bits/stdc++.h"
using namespace std; 

#define IOS {ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);}
#define ll long long 
// finding shortest prime factor//SPF -- Nlog(n)
const ll mX = 1e7+2;
ll spf[mX];
void sieve (){
        spf[1]=1;
        for(ll i=2;i<mX;i++){
                if(spf[i]==0){
                        spf[i]=i;
                        for (ll j=1ll*i*i;j<mX;j+=i){
                                if(spf[j]==0) spf[j]=i;
                        }
                }
        }
}
int main(){
        IOS;
        map<ll,ll> m,match;
        sieve();
        ll n;
        cin>>n;
        for(ll i=0;i<n;i++){
                ll x;
                cin>>x;
                while(x>1){
                        ll div=spf[x];
                        if(div>1){
                                m[div]++;
                                while(x%div==0)x/=div;
                        }
                        else break;
                }
        }
        ll len=(int)m.size();
        ll id[len]={0};
        ll index=0;
        for(auto it=m.begin();it!=m.end();it++){
                id[index]=it->first;
                match[it->first]=index;
                index++;
        }
        vector<ll> pfx(len,0);
        for(ll i=0;i<len;i++){
                if(i==0) pfx[i]=m[id[i]];
                else pfx[i]=pfx[i-1]+m[id[i]];
        }
        ll q;
        cin>>q;
        while(q--){
                ll l,r;
                cin>>l>>r;
                ll lower=-1,upper=-1;
                auto it=m.upper_bound(r);
                if(it!=m.begin()){
                        it--;
                        upper=match[it->first];
                } 

                auto it1=m.lower_bound(l);
                if(it1!=m.end()){
                        lower=match[it1->first];
                }
                if(upper==-1 || lower==-1) cout<<0<<"\n";
                else{
                        if(lower) cout<<pfx[upper]-pfx[lower-1]<<"\n";
                        else cout<<pfx[upper]<<"\n";
                }

        }
}
