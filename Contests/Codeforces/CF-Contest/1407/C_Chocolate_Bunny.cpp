#include "bits/stdc++.h"
using namespace std; 

#define IOS {ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);}
#define ll long long 

ll powermod(ll x,ll ex,ll md){ll ans=1ll;while(ex>0){if(ex&1ll) ans=(ans*x)%md; ex>>=1ll;x=(x*x)%md;}return ans;}
inline ll gcd(ll a,ll b) {if(b==0)return a;a%=b;return gcd(b,a);}
inline ll max(ll a,ll b) {return((a>b)?a:b);}
inline ll min(ll a,ll b) {return((a>b)?b:a);}

ll ask(ll x,ll y){
        cout<<"? "<<x<<" "<<y<<"\n";
        cout.flush();
        ll rem;
        cin>>rem;
        return rem;
}
int main(){
        IOS;
        ll n;
        cin>>n;
        ll ans[n+4]={0};
        ll index1=0,index2=n-1;
        set<ll> s;
        for(ll i=1;i<=n;i++) s.insert(i);
        while(1){
                ll len=(int)s.size();
                if(len<=1) break;
                else{
                        ll x=ask(index1+1,index2+1);
                        ll y=ask(index2+1,index1+1);
                        if(x>y){
                                ans[index1]=x;
                                index1++;
                                auto it=s.find(x);
                                if(it != s.end()) s.erase(it);
                        }
                        else if(y>x){
                                ans[index2]=y;
                                index2--;
                                auto it=s.find(y);
                                if(it != s.end()) s.erase(it);
                        }
                        else break;
                }

        }
        ll element=*s.begin();
        for(ll i=0;i<n;i++) if(ans[i]==0) ans[i]=element;
        cout<<"! ";
        for(ll i=0;i<n;i++){
                cout<<ans[i]<<" ";
        }
        cout<<"\n";
        cout.flush();
}
