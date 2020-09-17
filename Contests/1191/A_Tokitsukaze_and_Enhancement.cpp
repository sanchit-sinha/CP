#include "bits/stdc++.h"
using namespace std; 

#define IOS {ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);}
#define ll long long 

ll powermod(ll x,ll ex,ll md){ll ans=1ll;while(ex>0){if(ex&1ll) ans=(ans*x)%md; ex>>=1ll;x=(x*x)%md;}return ans;}
inline ll gcd(ll a,ll b) {if(b==0)return a;a%=b;return gcd(b,a);}
inline ll max(ll a,ll b) {return((a>b)?a:b);}
inline ll min(ll a,ll b) {return((a>b)?b:a);}


int main(){
        IOS;
        ll x;
        cin>>x;
        ll rem=x%4;
        bool got[6]={0};
        for(ll i=0;i<3;i++){
                ll y=x+i;
               got[y%4]=1;
        }
        if(got[1]){
                for(ll i=0;i<3;i++){
                        ll y=x+i;
                        if(y%4==1){
                                cout<<i<<" "<<"A\n";
                                return 0;
                        }
                }
        }
        else if(got[3]){
                for(ll i=0;i<3;i++){
                        ll y=x+i;
                        if(y%4==3){
                                cout<<i<<" "<<"B\n";
                                return 0;
                        }
                }

        }
        else if(got[2]){
                for(ll i=0;i<3;i++){
                        ll y=x+i;
                        if(y%4==2){
                                cout<<i<<" "<<"C\n";
                                return 0;
                        }
                }
        }
        else if(got[0]){
                for(ll i=0;i<3;i++){
                        ll y=x+i;
                        if(y%4==0){
                                cout<<i<<" "<<"D\n";
                                return 0;
                        }
                }
        }
}
