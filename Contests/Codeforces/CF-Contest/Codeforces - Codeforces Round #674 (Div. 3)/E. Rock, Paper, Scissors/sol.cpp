/**
 *    Author:  Sanchit Sinha
 *    Created: 28.09.2020 15:11:29       
**/
#include "bits/stdc++.h"
using namespace std; 

#define ll long long 
ll powermod(ll x,ll ex,ll md){ll ans=1ll;while(ex>0){if(ex&1ll) ans=(ans*x)%md; ex>>=1ll;x=(x*x)%md;}return ans;}
inline ll gcd(ll a,ll b) {if(b==0)return a;a%=b;return gcd(b,a);}
inline ll max(ll a,ll b) {return((a>b)?a:b);}
inline ll min(ll a,ll b) {return((a>b)?b:a);}

pair<ll,ll> win(ll a[],ll b[],ll n){
        // A to win
        
        // rock -> scissor
        // Scissor -> paper
        // paper -> rock


        ll rock1=a[0] , scissor1=a[1] , paper1=a[2];
        ll rock2=b[0] , scissor2=b[1] , paper2=b[2];
        ll matches_won=0;

        /*
        cout << rock1 <<" " << paper1 << " " << scissor1<<"\n";
        cout << rock2 <<" " << paper2 << " " << scissor2<<"\n"; */


        // clear win
        ll mn1 = min(rock1 , scissor2);
        matches_won += mn1;
        rock1 -= mn1;
        scissor2 -= mn1;

        ll mn2 = min(scissor1 , paper2);
        matches_won += mn2;
        scissor1 -= mn2;
        paper2 -= mn2;
        
        ll mn3 = min(paper1 , rock2);
        matches_won += mn3;
        paper1 -= mn3;
        rock2 -= mn3;


        ll matches_draw=0;
        // attempt to draw
        if(rock1){
                if(rock2){
                        ll mn = min(rock1 , rock2);
                        rock1 -= mn;
                        rock2 -= mn;
                        matches_draw += mn;
                }
        }

        if(paper1){
                if(paper2){
                        ll mn = min(paper1 , paper2);
                        paper1 -= mn;
                        paper2 -= mn;
                        matches_draw += mn;
                }
        }

        if(scissor1){
                if(scissor2){
                        ll mn = min(scissor1 , scissor2);
                        scissor1 -= mn;
                        scissor2 -= mn;
                        matches_draw += mn;
                }
        }


        // lose
        // cout <<"--------\n";
        // cout << matches_won<<"\n";
        // cout << rock1 <<" " << paper1 <<" " << scissor1<<"\n\n";
        // matches_won -= (rock1 + paper1 + scissor1);

        return make_pair(matches_won , matches_draw);


}

pair<ll,ll> draw(ll a[],ll b[],ll n){
        // A to win
        
        // rock -> scissor
        // Scissor -> paper
        // paper -> rock


        ll rock1=a[0] , scissor1=a[1] , paper1=a[2];
        ll rock2=b[0] , scissor2=b[1] , paper2=b[2];
        ll matches_won=0;

        /*
        cout << rock1 <<" " << paper1 << " " << scissor1<<"\n";
        cout << rock2 <<" " << paper2 << " " << scissor2<<"\n"; */


        // clear win
       


        ll matches_draw=0;
        // attempt to draw
        if(rock1){
                if(rock2){
                        ll mn = min(rock1 , rock2);
                        rock1 -= mn;
                        rock2 -= mn;
                        matches_draw += mn;
                }
        }

        if(paper1){
                if(paper2){
                        ll mn = min(paper1 , paper2);
                        paper1 -= mn;
                        paper2 -= mn;
                        matches_draw += mn;
                }
        }

        if(scissor1){
                if(scissor2){
                        ll mn = min(scissor1 , scissor2);
                        scissor1 -= mn;
                        scissor2 -= mn;
                        matches_draw += mn;
                }
        }


        ll mn1 = min(rock1 , scissor2);
        matches_won += mn1;
        rock1 -= mn1;
        scissor2 -= mn1;

        ll mn2 = min(scissor1 , paper2);
        matches_won += mn2;
        scissor1 -= mn2;
        paper2 -= mn2;
        
        ll mn3 = min(paper1 , rock2);
        matches_won += mn3;
        paper1 -= mn3;
        rock2 -= mn3;

        // lose
        // cout <<"--------\n";
        // cout << matches_won<<"\n";
        // cout << rock1 <<" " << paper1 <<" " << scissor1<<"\n\n";
        // matches_won -= (rock1 + paper1 + scissor1);

        return make_pair(matches_won , matches_draw);


}
int main(){
        ios::sync_with_stdio(false);
        cin.tie(0);
        ll x;
        cin>>x;
        ll n=3;
        ll a[n],b[n];
        for(ll i=0;i<n;i++) cin>>a[i];
        for(ll i=0;i<n;i++) cin>>b[i];

        pair<ll,ll> wonb = win(b,a,n);
        pair<ll,ll> wonb2 = draw(b,a,n);
        pair<ll,ll> wona = win(a,b,n);

        ll mx_won_a  = wona.first;
        ll mn_won_a = min((x - wonb.first - wonb.second) , x - wonb2.first - wonb2.second);

        cout << mn_won_a <<" " << mx_won_a<<"\n";

        return 0;
}
