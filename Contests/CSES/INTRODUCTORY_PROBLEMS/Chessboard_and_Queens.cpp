#include "bits/stdc++.h"
using namespace std; 
#define ll long long 
#define IOS {ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);}
const ll n=8;
ll blocked[n][n];
void block(ll r,ll queens){
    for(ll i=0;i<n;i++){
        blocked[i][queens-1]++;
        blocked[r][i]++;
    }
    ll x=r,y=queens-1;
    for(ll i=0;i<n;i++){
        if(x>=0 && x<n && y>=0 && y<n) blocked[x][y]++;
        x++,y++;
    }
    x=r,y=queens-1;
    for(ll i=0;i<n;i++){
        if(x>=0 && x<n && y>=0 && y<n) blocked[x][y]++;
        x--,y++;
    }
    x=r,y=queens-1;
    for(ll i=0;i<n;i++){
        if(x>=0 && x<n && y>=0 && y<n) blocked[x][y]++;
        x++,y--;
    }
    x=r,y=queens-1;
    for(ll i=0;i<n;i++){
        if(x>=0 && x<n && y>=0 && y<n) blocked[x][y]++;
        x--,y--;
    }
}
void revert(ll r,ll queens){
    for(ll i=0;i<n;i++){
        blocked[i][queens-1]--;
        blocked[r][i]--;
    }
    ll x=r,y=queens-1;
    for(ll i=0;i<n;i++){
        if(x>=0 && x<n && y>=0 && y<n) blocked[x][y]--;
        x++,y++;
    }
    x=r,y=queens-1;
    for(ll i=0;i<n;i++){
        if(x>=0 && x<n && y>=0 && y<n) blocked[x][y]--;
        x--,y++;
    }
    x=r,y=queens-1;
    for(ll i=0;i<n;i++){
        if(x>=0 && x<n && y>=0 && y<n) blocked[x][y]--;
        x++,y--;
    }
    x=r,y=queens-1;
    for(ll i=0;i<n;i++){
        if(x>=0 && x<n && y>=0 && y<n) blocked[x][y]--;
        x--,y--;
    }
}
void solve(ll queens,ll &ways){
    if(queens==0){
        ways++;
        return;
    }
    for(ll r=0;r<n;r++){
        if(blocked[r][queens-1]==0){
            block(r,queens);
            solve(queens-1,ways);
            revert(r,queens);
        }
    }
    return;
}
int main(){
    IOS;
    ll queens=n;
    string s[n];
    for(ll i=0;i<n;i++) cin>>s[i];
    for(ll i=0;i<n;i++){
        for(ll j=0;j<n;j++) if(s[i][j]=='*') blocked[i][j]=20;
    }
    ll ways=0;
    solve(queens,ways);
    cout<<ways<<"\n";
}
