#include "bits/stdc++.h"
using namespace std; 

#define IOS {ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);}
#define ll long long 

inline ll gcd(ll a,ll b) {if(b==0)return a;a%=b;return gcd(b,a);}
inline ll max(ll a,ll b) {return((a>b)?a:b);}
inline ll min(ll a,ll b) {return((a>b)?b:a);}
ll powermod(ll x,ll ex,ll md){ll ans=1ll;while(ex>0){if(ex&1ll) ans=(ans*x)%md; ex>>=1ll;x=(x*x)%md;}return ans;}


int main(){
       IOS;
       ll T;
       cin>>T;
       while(T--){
               ll n;
               cin>>n;
               ll h[n];
                for(ll i=0;i<n;i++) cin>>h[i];
                if(n==1){
                        cout<<"1 0\nMotu\n";
                        continue;
                }
                ll time_taken_left=0,time_taken_right=0;
                ll l=0,r=n-1;
                while(l<=r){
                        if(time_taken_left <= time_taken_right*2){
                                time_taken_left += h[l];
                                l++;
                        }
                        else{
                                time_taken_right+=h[r];
                                r--;
                        }
                }
                ll motu=l , patlu=n-r-1;
                if(l==0) motu=1,patlu--;
                cout<<motu<<" " << patlu<<"\n";
                if(motu==patlu) cout<<"Tie\n";
                else if(motu>patlu) cout<<"Motu"<<"\n";
                else cout<<"Patlu\n";
       }    
}