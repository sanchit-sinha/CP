#include "bits/stdc++.h"
using namespace std; 

#define IOS {ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);}
#define ll long long 

const ll N=3e5+11;
ll n,x,a[N];
ll mss_left[N],mss_right[N],pfx[N];
/* 
        mss_left[i] - max sum of subarray ending at i
        mss_right[i]-max sum of subarray starting at i
                                                        */

int main(){
        IOS;
        cin>>n>>x;
        for(ll i=0;i<n;i++) cin>>a[i];
        // pfx
        for(ll i=0;i<n;i++){
                if(i==0) pfx[i]=a[i];
                else pfx[i]=pfx[i-1]+a[i];
        }
        
        // left
        for(ll i=0;i<n;i++){
                if(i==0) mss_left[i]=max(0ll,a[i]);
                else mss_left[i]=max(0ll,mss_left[i-1]+a[i]);
        }

        // right
        for(ll i=n-1;i>=0;--i){
                if(i==n-1) mss_right[i]=max(0ll,a[i]);
                else mss_right[i]=max(0ll,mss_right[i+1]+a[i]);
        }

        /*
                for each r find the best l
                suppose we mul x in subarray [l,r]
                ans -> mss_left[l-1] + x*(pfx[r]-pfx[l-1]) + mss_right[r+1]       
                       mss_left[l-1]-x*pfx[l-1]  +   mss_right[r+1]+x*pfx[r]  
                       <-----best_left_mss---->
                fix r and find the best l for answer
                                                                        */
        ll ans=0,best_left_mss=0;
        for(ll i=0;i<n;i++){
                if(i==0){
                        ans=max({ans,a[i]*x,a[i]});
                        ans=max(ans,mss_right[i+1]+x*pfx[i]);
                }
                else{
                        best_left_mss=max(best_left_mss,mss_left[i-1]-x*pfx[i-1]);

                        /// using one operation
                        if(i!=n-1) ans=max(ans,best_left_mss + mss_right[i+1]+x*pfx[i]);
                        else ans=max(ans,best_left_mss+x*pfx[i]);

                        // not using any operation
                        ans=max(ans,mss_left[i]);
                        ans=max(ans,mss_right[i]);

                }
        }
        cout << ans <<"\n";
}
