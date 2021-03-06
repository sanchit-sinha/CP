#include "bits/stdc++.h"
using namespace std; 

#define IOS {ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);}
#define ll long long 

ll powermod(ll x,ll ex,ll md){ll ans=1ll;while(ex>0){if(ex&1ll) ans=(ans*x)%md; ex>>=1ll;x=(x*x)%md;}return ans;}
inline ll gcd(ll a,ll b) {if(b==0)return a;a%=b;return gcd(b,a);}
inline ll max(ll a,ll b) {return((a>b)?a:b);}
inline ll min(ll a,ll b) {return((a>b)?b:a);}

string ask(ll x,ll y){
        string t;
        cout<<"? "<<x<<" "<<y<<"\n";
        cout.flush();
        cin>>t;
        return t;
}
void print(ll ans){
        cout<<"! "<<ans<<"\n";
        cout.flush();
}
int main(){
        IOS;
        while(1){
                string s;
                cin>>s;
                if(s=="start"){
                        ll x=0,y=1;
                        while(true){
                                if(ask(x,y)=="x"){
                                        break;
                                }
                                else{
                                        x=y;
                                        y*=2;
                                }
                        }
                        ll l=x, r=y, mid=0,ans=r;
                        while(r>l+1){
                                mid=(l+(r-l)/2);
                                if(ask(mid,r)=="y")ans=mid, r=mid;
                                else l=mid;
                        }       
                        print(ans);
                }
                else break;
        }
}
