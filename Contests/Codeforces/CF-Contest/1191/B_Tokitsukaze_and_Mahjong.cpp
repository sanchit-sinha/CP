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
        string a,b,c;
        cin>>a>>b>>c;
        ll m=0,p=0,s=0;
        
        if(a[1]=='p') p++;
        else if(a[1]=='s') s++;
        else if(a[1]=='m') m++;

        if(b[1]=='p') p++;
        else if(b[1]=='s') s++;
        else if(b[1]=='m') m++;
        
        if(c[1]=='p') p++;
        else if(c[1]=='s') s++;
        else if(c[1]=='m') m++;

        vector<ll> x;
        x.push_back(a[0]-'0');
        x.push_back(b[0]-'0');
        x.push_back(c[0]-'0');
        sort(x.begin() , x.end());

        vector<ll> pp,mm,ss;
        if(a[1]=='p') pp.push_back(a[0]-'0');
        else if(a[1]=='s') ss.push_back(a[0]-'0');
        else if(a[1]=='m') mm.push_back(a[0]-'0');

        if(b[1]=='p') pp.push_back(b[0]-'0');
        else if(b[1]=='s') ss.push_back(b[0]-'0');
        else if(b[1]=='m') mm.push_back(b[0]-'0');
        
        if(c[1]=='p') pp.push_back(c[0]-'0');
        else if(c[1]=='s') ss.push_back(c[0]-'0');
        else if(c[1]=='m') mm.push_back(c[0]-'0');

        if(p==3 || m==3 || s==3){
                if(x[0]==x[1] && x[1]==x[2]) cout<<"0\n";
                else if(x[0]==x[1]) cout<<"1\n";
                else if(x[1]==x[2]) cout<<"1\n";
                else{
                       ll d1=x[1]-x[0] , d2=x[2]-x[1];
                       if(x[1]==x[0]+1 && x[2]==x[1]+1) cout<<"0\n";
                       else{
                               bool one=0;
                               if(d1==2 || d2==2 || d1==0 || d2==0) one=1;
                               if(d1==1){
                                        if(x[1]+d1<=9) one=1;
                                        if(x[0]-d1>0) one=1;
                               }
                                if(d2==1){      
                                        if(x[2]+d2<=9) one=1;
                                        if(x[1]-d2>0) one=1;
                                }

                                if(one) cout<<"1\n";
                                else cout<<"2\n";
                       }
                }
        }
        else if(p==2 ){
                sort(pp.begin() , pp.end());
                ll d1=pp[1]-pp[0];
                bool one=0;
                if(d1==2 || d1==0) one=1;
                if(d1==1){
                        if(pp[1]+d1<=9) one=1;
                        if(pp[0]-d1>0) one=1;
                }
                if(one) cout<<"1\n";
                else cout<<"2\n";
        }
        else if(m==2){
                sort(mm.begin() , mm.end());
                ll d1=mm[1]-mm[0];
                bool one=0;
                if(d1==2 || d1==0) one=1;
                if(d1==1){
                        if(mm[1]+d1<=9) one=1;
                        if(mm[0]-d1>0) one=1;
                }

                if(one) cout<<"1\n";
                else cout<<"2\n";

        }
        else if(s==2 ){
                sort(ss.begin() , ss.end());
                ll d1=ss[1]-ss[0];
                bool one=0;
                if(d1==2 || d1==0) one=1;
                if(d1==1){
                        if(ss[1]+d1<=9) one=1;
                        if(ss[0]-d1>0) one=1;
                }

                if(one) cout<<"1\n";
                else cout<<"2\n";
        }
        else cout<<"2\n";
}       