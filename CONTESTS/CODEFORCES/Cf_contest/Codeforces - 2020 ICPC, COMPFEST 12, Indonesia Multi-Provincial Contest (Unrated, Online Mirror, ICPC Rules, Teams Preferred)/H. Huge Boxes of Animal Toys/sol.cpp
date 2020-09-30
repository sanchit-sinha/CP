/**
 *    author:  Sanchit Sinha
 *    created: 27.09.2020 13:58:52       
**/
#include "bits/stdc++.h"
using namespace std; 

#define ll long long 
inline ll gcd(ll a,ll b) {if(b==0)return a;a%=b;return gcd(b,a);}
inline ll max(ll a,ll b) {return((a>b)?a:b);}
inline ll min(ll a,ll b) {return((a>b)?b:a);}
ll powermod(ll x,ll ex,ll md){ll ans=1ll;while(ex>0){if(ex&1ll) ans=(ans*x)%md; ex>>=1ll;x=(x*x)%md;}return ans;}

int main(){
        ios::sync_with_stdio(false);
        cin.tie(0);
        ll T;
        cin>>T;
        while(T--){
                ll a[4];
                ll ct=0;
                for(ll i=0;i<4;i++){
                        cin>>a[i];
                }
                if(a[0] && a[0]%2==0){
                        a[0]=0;
                        a[3]=1;
                }
                if(a[1] && a[1]%2==0){
                        a[2]=1;
                        a[1]=0;
                }
                if(a[3]) a[3]=1;
                if(a[2]) a[2]=1;

                for(ll i=0;i<4;i++) if(a[i]) ct++;

                if(ct==0){
                        for(ll i=0;i<4;i++) cout<<"Tidak ";
                        cout<<"\n";
                }
                else if(ct==1){
                        for(ll i=0;i<4;i++){
                                if(a[i])  cout<<"Ya ";
                                else cout<<"Tidak ";
                        }
                        cout<<"\n";
                }
                else if(ct==2){
                        if(a[1] && a[2]){
                                // both small
                                for(ll i=0;i<4;i++){
                                        if(i==1) cout<<"Ya ";
                                        else cout<<"Tidak ";
                                }
                                cout<<"\n";
                        }
                        else if(a[0] && a[3]){
                                // both big
                                for(ll i=0;i<4;i++){
                                        if(i==0) cout<<"Ya ";
                                        else cout<<"Tidak ";
                                }
                                cout<<"\n";
                        }
                        else{
                                ll pos=0,neg=0;
                                if(a[0]) neg++;
                                if(a[1]) neg++;

                                if(a[2]) pos++;
                                if(a[3]) pos++;

                                if(pos==2 || neg==2){
                                        for(ll i=0;i<4;i++) {
                                                if(i==3 || i==2) cout<<"Ya ";
                                                else cout<<"Tidak ";
                                        }
                                        cout<<"\n";
                                }
                                else{
                                        for(ll i=0;i<4;i++){
                                                if(i==0 || i==1) cout<<"Ya ";
                                                else cout <<"Tidak ";
                                        }
                                        cout<<"\n";
                                }
                        }
                }
                else{
                        for(ll i=0;i<4;i++){
                                if(i==0 || i==1) cout<<"Ya ";
                                else cout <<"Tidak ";
                        }
                        cout<<"\n";
                }
        }
        return 0;
}