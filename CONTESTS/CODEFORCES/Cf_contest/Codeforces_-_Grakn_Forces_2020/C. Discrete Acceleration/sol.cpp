/**
 *    Author:  Sanchit Sinha
 *    Created: 30.09.2020 21:28:18       
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
               cout << fixed << setprecision(15);
               
                ll n,len;
                cin>>n>>len;
                ll a[n+11];
                for(ll i=0;i<n;i++) cin>>a[i+1];
                a[0]=0;
                a[n+1] = 1e18;
                ll l=0,r=n+1;

                long double time_of_collision , t1 , t2;
                long double x=0,y=len;

                ll speed1 = 1 , speed2 = 1;
                
                t1 =  (long double)(a[l+1] - x)/speed1;               
                t2 = (long double)(y - a[r-1])/speed2;
                time_of_collision = (long double)(y - x)/(speed1 + speed2);

                long double ans = 0.0;

                if(t1 >= time_of_collision && t2 >= time_of_collision){
                        ans += time_of_collision;
                }
                else if(t1 < t2){
                        // first reaches early;
                        l++;

                        x=a[l];
                        speed1++;
                        y -= speed2 * t1;
                        ans += t1;

                }
                else if(t2 < t1){
                        // second reached early;
                        r--;

                        y=a[r];
                        speed2++;
                        x += speed1 * t2;
                        ans += t2;
                }
                else if(t1 == t2){
                        l++;
                        r--;

                        x=a[l];
                        y=a[r];
                        speed1++;
                        speed2++;
                        ans += t1;
                }

                // cout << t1 <<" " << t2 <<"\n" << x <<" " << y <<"\n\n";
                while(true){
                        if(l>=r) break;
                        else{
                                t1 =  (long double)(min(a[l+1] , y) - x)/speed1;               
                                t2 = (long double)(y - max(a[r-1] , x))/speed2;
                                time_of_collision = (long double)(y - x)/(speed1 + speed2);

                                if(t1 >= time_of_collision && t2 >= time_of_collision){
                                        ans += time_of_collision;
                                        break;
                                }
                                else if(t1 < t2){
                                        // first reaches early;
                                        l++;

                                        x=a[l];
                                        speed1++;
                                        y -= speed2 * t1;
                                        ans += t1;

                                }
                                else if(t2 < t1){
                                        // second reached early;
                                        r--;

                                        y=a[r];
                                        speed2++;
                                        x += speed1 * t2;
                                        ans += t2;
                                }
                                else if(t1 == t2){
                                        l++;
                                        r--;

                                        x=a[l];
                                        y=a[r];
                                        speed1++;
                                        speed2++;
                                        ans += t1;
                                }
                        }
                // cout << t1 <<" " << t2 <<"\n" << x <<" " << y <<"\n\n";

                }
                cout << ans<<"\n";
                // cout<<"-----------------\n\n";
        }    
        return 0;
}