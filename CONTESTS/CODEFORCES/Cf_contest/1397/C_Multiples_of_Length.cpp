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
        ll n;
        cin>>n;
        ll a[n];
        for(ll i=0;i<n;i++) cin>>a[i];
        if(n==1){
                cout<<"1 1\n";
                cout<<-a[0]<<"\n";
                cout<<"1 1\n";
                cout<<"0\n";
                cout<<"1 1\n";
                cout<<"0\n";
        }
        else if(n==2){
                cout<<"1 1\n";
                cout<<-a[0]<<"\n";
                cout<<"2 2\n";
                cout<<-a[1]<<"\n";
                cout<<"1 1\n";
                cout<<"0\n";
        }
        else{
                ll lcm=(n*(n-1))/gcd(n,n-1);
                cout<<"1 "<<n-1<<"\n";
                for(ll i=0;i<n-1;i++){
                        ll rem=a[i]%n;
                        ll first_factor=rem;
                        ll req_div=(a[i]/lcm);
                        ll add=(req_div)*lcm + (first_factor)*(n-1);
                        cout<<add<<" ";
                        a[i]+=add;
                }        
                cout<<"\n";
                cout<<n<<" "<<n<<"\n";
                ll x=(a[n-1]/n);
                ll final_num=(x+1)*n;
                cout<< final_num-a[n-1]<<" \n";
                a[n-1]=final_num;
                cout<<1<<" "<<n<<"\n";
                for(ll i=0;i<n;i++){
                        cout<<-(a[i])<<" ";
                }
                cout<<"\n";
        }
}
