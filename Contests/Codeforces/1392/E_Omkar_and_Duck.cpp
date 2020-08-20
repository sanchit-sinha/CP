#include "bits/stdc++.h"
using namespace std; 

#define IOS {ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);}
#define ll long long 

const ll N=27;
ll a[N][N],n;

int main(){
        IOS;
        cin >> n;
        for(ll i=1;i<=n;i++){
                for(ll j=1;j<=n;j++){
                        if(i&1) a[i][j]=(1ll<<(i+j));
                        cout<<a[i][j]<<" ";
                        cout.flush();
                }
                cout<<"\n";
                cout.flush();
        }                

        ll q;
        cin>>q;
        while(q--){
                ll ans;
                cin>>ans;
                cout<<"1 1\n";
                cout.flush();
                ll x=1,y=1;
                for(ll i=2;i<=n+n-1;i++){
                        /*
                        x,y    x,y+1    x,y+2  .. . .
                        x+1,y  x+1,y+1  x+1,y+2 .. . . 
                        .
                        .
                        .
                        
                        checking if (x,y+1)th bit is set or not
                        if it is set, tghen go right
                        else go down 
                        */
                        if(x&1){
                                if((1ll<<(x+y+1))&ans) y++;
                                else x++;
                        }
                        else{
                                if((1ll<<(x+y+1))&ans) x++;
                                else y++;  
                        }
                        cout<<x <<" " << y <<"\n";
                        cout.flush();
                }
        }
}
