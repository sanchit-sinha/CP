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
        ll x[n],y[n];
        vector<pair<ll,ll>>sum(n) ,dif(n);
        for(ll i=0;i<n;i++){
                cin>>x[i]>>y[i];
                sum[i]=make_pair((x[i]+y[i]) , i);
                dif[i]=make_pair((x[i]-y[i]) , i);
        }
        sort(sum.begin() , sum.end());
        sort(dif.begin() , dif.end());

        ll ans=LLONG_MIN;

        ll index=sum[0].second;
        ll startx = x[index];
        ll starty = y[index];
        for(ll i=0;i<n;i++){
                ll index=sum[i].second;
                ll xx=x[index];
                ll yy=y[index];
                if(xx>=startx){
                        if(yy >= starty) ans=max(ans , abs(sum[i].first - sum[0].first));
                }
                else{
                        if(starty >= xx) ans=max(ans ,abs(sum[0].first - sum[i].first));
                }
        }

        index=sum[n-1].second;
        startx = x[index] , starty = y[index];
        for(ll i=0;i<n;i++){
                ll index=sum[i].second;
                ll xx=x[index];
                ll yy=y[index];
                if(xx>=startx){
                        if(yy >= starty) ans=max(ans , abs(sum[i].first - sum[n-1].first) );
                }
                else{
                        if(starty >= xx) ans=max(ans , abs(sum[n-1].first - sum[i].first) );
                }
        }

        index=dif[0].second;
        startx = x[index] , starty = y[index];
        for(ll i=0;i<n;i++){
                ll index=dif[i].second;
                ll xx=x[index];
                ll yy=y[index];
                if(xx>=startx){
                        if(yy < starty) ans=max(ans , abs(dif[i].first - dif[0].first));
                }
                else{
                        if(starty < xx) ans=max(ans , abs(dif[0].first - dif[i].first));
                }
        }

        index=dif[n-1].second;
        startx = x[index] , starty = y[index];
        for(ll i=0;i<n;i++){
                ll index=dif[i].second;
                ll xx=x[index];
                ll yy=y[index];
                if(xx>=startx){
                        if(yy < starty) ans=max(ans ,abs(dif[i].first - dif[n-1].first));
                }
                else{
                        if(starty < xx) ans=max(ans , abs(dif[n-1].first - dif[i].first));
                }
        }

        cout<<ans<<"\n";
}
