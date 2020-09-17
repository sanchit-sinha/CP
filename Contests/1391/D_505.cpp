#include "bits/stdc++.h"
using namespace std; 

#define IOS {ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);}
#define ll long long 

const ll N=1e6+11;
ll dp[9][N],n,m;// min moves req. to place mask in the jth col
string s[N];
bool check(ll x,ll y){
    bool ok=1;
    for(ll i=0;i<n-1;i++){
        ll x1=0,x2=0,y1=0,y2=0;
        if((1ll<<i)&x) x1=1; 
        if((1ll<<i)&y) y1=1; 

        if((1ll<<(i+1))&x) x2=1; 
        if((1ll<<(i+1))&y) y2=1;

        if((x1+x2+y1+y2)%2==0) ok=0;
    }
    return ok;
}
int main(){
    IOS;
    cin>>n>>m;
    for(ll i=0;i<n;i++) cin>>s[i];
    //n<=m
    if(n>=4 && m>=4) cout<<-1<<"\n";
    else if(n==1) cout<<0<<"\n";
    else{
        for(ll i=0;i<m;i++){
            for(ll j=0;j<9;j++) dp[j][i]=LLONG_MAX;
        }

        ll mx_mask=1ll<<n;
        for(ll j=0;j<=mx_mask;j++){
            dp[j][0]=0;
            for(ll i=0;i<n;i++){
                ll is_set=1;
                if((1ll<<i)&j) is_set=1;
                else is_set=0;

                dp[j][0]+=(is_set==(s[i][0]-'0'));
            }
        }

        for(ll i=1;i<m;i++){
            for(ll x=0;x<mx_mask+1;x++){
                for(ll y=0;y<mx_mask+1;y++){
                    if(check(x,y)){
                        ll moves=0;

                        for(ll row=0;row<n;row++){
                            ll is_set=0;
                            if((1ll<<row)&y) is_set=1;

                            moves+=((s[row][i]-'0')!=is_set);
                        }
                        dp[y][i]=min(dp[y][i],dp[x][i-1]+moves);
                    }
                }
            }
        } 
        ll ans=LLONG_MAX;
        for(ll i=0;i<mx_mask+1;i++) ans=min(ans,dp[i][m-1]);
        cout<<ans<<"\n";
    
    }
}
