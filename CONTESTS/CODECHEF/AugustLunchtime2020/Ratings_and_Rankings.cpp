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
                ll n,m;
                cin>>n>>m;

                ll rating[n];
                for(ll i=0;i<n;i++) cin>>rating[i];

                vector< vector<ll> >present_rating(n , vector<ll>(m ,0));
                vector< vector<ll> >rating_change(n , vector<ll>(m ,0));
                vector< vector<ll> >rank(n , vector<ll>(m ,0));

                for(ll i=0;i<n;i++){
                        for(ll j=0;j<m;j++) cin>>rating_change[i][j];
                }

                for(ll i=0;i<n;i++){
                        for(ll j=0;j<m;j++){
                                if(j==0) present_rating[i][j]=rating_change[i][j]+rating[i];
                                else{
                                        present_rating[i][j]=present_rating[i][j-1]+rating_change[i][j];
                                }
                        }
                }

                ll mx_rating[n]={0};
                vector<ll> mn_rank(n,LLONG_MAX);
                for(ll i=0;i<n;i++){
                        for(ll j=0;j<m;j++) mx_rating[i]=max(mx_rating[i] , present_rating[i][j]);
                }

                for(ll j=0;j<m;j++){
                        vector<ll> v;
                        for(ll i=0;i<n;i++) v.push_back(present_rating[i][j]);
                        sort(v.begin() , v.end() , greater<ll>());
                        ll index=1;
                        map<ll,ll> id;
                        for(ll i=0;i<n;i++){
                                ll x=v[i];
                                ll ct=0;
                                while(i<n && v[i]==x) ct++,i++;
                                i--;
                                id[v[i]]=index;
                                index+=ct;
                        }
                        for(ll i=0;i<n;i++) rank[i][j]=id[present_rating[i][j]];
                }

                for(ll i=0;i<n;i++){
                        for(ll j=0;j<m;j++) mn_rank[i]=min(mn_rank[i] , rank[i][j]);
                }

                // for(ll i=0;i<n;i++){
                //         cout<<mx_rating[i]<<"\n\n";
                //         cout<<i << " : ";
                //         for(ll j=0;j<m;j++) cout<<rank[i][j]<<" ";
                //         cout<<"\n";
                // }
                // cout<<"\n\n";
                
                ll ans=0;
                for(ll i=0;i<n;i++){
                        ll mn1=LLONG_MAX,mn2=LLONG_MAX;
                        for(ll j=0;j<m;j++){
                                if(rank[i][j]==mn_rank[i]) mn2=min(mn2,j);
                                if(present_rating[i][j]==mx_rating[i]) mn1=min(mn1,j);
                        }
                        if(mn2==LLONG_MAX || mn1==LLONG_MAX) ans++;
                        else if(mn2 != mn1) ans++;
                }
                cout<<ans<<"\n";
        }    
}