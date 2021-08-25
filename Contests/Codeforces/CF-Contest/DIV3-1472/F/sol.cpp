#include "bits/stdc++.h"
using namespace std;
#define IOS {ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);}
#define pb push_back
#define ll long long
#define ld long double
#define all(c) (c).begin(),(c).end()
#define sz(c) (int)(c.size())
#define mp make_pair
#define mt make_tuple
#define get(x,c) get<x>(c)
#define trav(a,x) for(auto a=x.begin();a!=x.end();a++)
#define rep(i,n) for(int i=0;i<n;i++)
#define FOR(i,a,b) for(int i=a;i<=b;i++)
#define FORR(i,b,a) for(int i=b;i>=a;i--)
#define lb lower_bound
#define ub upper_bound
#define pll pair<ll,ll>
#define vll vector<ll>
#define vpll vector<pll>
#define f first
#define s second

inline ll gcd(ll a,ll b) {if(b==0)return a;a%=b;return gcd(b,a);}
inline ll max(ll a,ll b) {return((a>b)?a:b);}
inline ll min(ll a,ll b) {return((a>b)?b:a);}
ll power(ll x,ll ex);
ll powermod(ll x,ll ex,ll md);

const ll inf = 1e18 + 9;
const ll mod = 1e9 + 7;
const ld PI = acos(-1);
const ld eps = 1e-9;

const ll N = 1e5+11;


void solve(){
    ll n;
    cin >> n;
    ll h[n] , w[n];
    rep(i , n) cin >> h[i] >> w[i];

    vpll sorted_h;
    vpll sorted_w;
    rep(i , n){
        sorted_h.pb(mp(h[i] , i));
        sorted_w.pb(mp(w[i] , i));
    }
    sort(all(sorted_w));
    sort(all(sorted_h));

    ll pfxmn_for_w_on_sorted_h[n + 1];
    // ll pfxmn_for_h_on_sorted_w[n + 1];

    ll index_of_w_in_pfxmn_for_w_on_sorted_h[n + 1];
    // ll index_of_h_in_pfxmn_for_h_on_sorted_w[n + 1];

    rep(i , n){
        // pfxmn_for_h_on_sorted_w[i] = LLONG_MAX;
        pfxmn_for_w_on_sorted_h[i] = LLONG_MAX;

        index_of_w_in_pfxmn_for_w_on_sorted_h[i] = LLONG_MAX;
        // index_of_h_in_pfxmn_for_h_on_sorted_w[i] = LLONG_MAX;
    }
    rep(i , n) {
        ll indexh = sorted_h[i].s;
        ll eleh = sorted_h[i].f ;

        ll indexw = sorted_w[i].s;
        ll elew = sorted_w[i].f;

        if(i == 0){
            pfxmn_for_w_on_sorted_h[indexh] = min(pfxmn_for_w_on_sorted_h[indexh] , w[indexh]);
            index_of_w_in_pfxmn_for_w_on_sorted_h[indexh] = indexh;

            pfxmn_for_h_on_sorted_w[indexw] = min(pfxmn_for_h_on_sorted_w[indexw] , h[indexw]);
            index_of_h_in_pfxmn_for_h_on_sorted_w[indexw] = indexw;
        }
        else {
            ll previndexh = sorted_h[i - 1].s;
            ll previndexw = sorted_w[i - 1].s;
            
            if(eleh < pfxmn_for_w_on_sorted_h[previndexh]){
                index_of_w_in_pfxmn_for_w_on_sorted_h[indexh] = indexh;
            }
            else if(eleh < pfxmn_for_w_on_sorted_h[previndexh]){
                index_of_w_in_pfxmn_for_w_on_sorted_h[indexh] = index_of_w_in_pfxmn_for_w_on_sorted_h[previndexh];
            }
            else{
                if(w[indexh] <= w[index_of_w_in_pfxmn_for_w_on_sorted_h[previndexh]])
                    index_of_w_in_pfxmn_for_w_on_sorted_h[indexh] = indexh ;
                else{
                    index_of_w_in_pfxmn_for_w_on_sorted_h[indexh] = index_of_w_in_pfxmn_for_w_on_sorted_h[previndexh];
                }
            }
            pfxmn_for_w_on_sorted_h[indexh] = min(w[indexh] , pfxmn_for_w_on_sorted_h[previndexh]);
            
            if(elew < pfxmn_for_w_on_sorted_h[previndexw]){
                index_of_h_in_pfxmn_for_h_on_sorted_w[indexw] = indexw;
            }
            else if(eleh < pfxmn_for_w_on_sorted_h[previndexw]){
                index_of_h_in_pfxmn_for_h_on_sorted_w[indexw] = index_of_h_in_pfxmn_for_h_on_sorted_w[previndexw];
            }
            else{
                index_of_h_in_pfxmn_for_h_on_sorted_w[indexw] = min(indexw , index_of_h_in_pfxmn_for_h_on_sorted_w[previndexw]);
            }
            pfxmn_for_h_on_sorted_w[indexw] = min(h[indexw] , pfxmn_for_h_on_sorted_w[previndexw]);
        }
    }

    // cout << "--------------SORTED - H----------\n";
    // rep(i , n){
    //     cout << sorted_h[i].f << " " << sorted_h[i].s << "\n";
    // }
    // cout <<"\n";
    // cout << "-----PFXMN - FOR -W - IN - SORTED - H----------\n";
    // rep(i , n){
    //     cout << pfxmn_for_w_on_sorted_h[i] << " ";
    // }
    // cout <<"\n";
    // rep(i , n){
    //     cout << index_of_w_in_pfxmn_for_w_on_sorted_h[i] << " ";
    // }
    // cout<<"\n";
    // cout << "--------------SORTED - W----------\n";
    // rep(i , n){
    //     cout << sorted_w[i].f << " " << sorted_w[i].s << "\n";
    // }
    // cout << "\n";
    // cout << "-----PFXMN - FOR -H - IN - SORTED - W----------\n";
    // rep(i , n){
    //     cout << pfxmn_for_h_on_sorted_w[i] << " ";
    // }
    // cout <<"\n";
    // rep(i , n){
    //     cout << index_of_h_in_pfxmn_for_h_on_sorted_w[i] << " ";
    // }
    // cout<<"\n";

    ll ans[n + 1] = {0};
    rep(i , n) ans[i] = -2;

    FOR(i , 0 , n - 1){
        //case 1 
        // hj < hi , wj < wi 
        auto it = ub(sorted_h.begin() , sorted_h.end() , mp(h[i],LLONG_MIN));
        if(it != sorted_h.begin()){
            it--;
            ll wmin = pfxmn_for_w_on_sorted_h[it->s];
            // cout << " in "<< i << " : " << it->s<<"-"<<wmin << " ";
            if(wmin < w[i]){
                // change
                ll index = index_of_w_in_pfxmn_for_w_on_sorted_h[it->s];
                ans[i] = index;
            }
        }

    }

    // cout <<"\n***************************\n";
    // rep(i , n) cout << ans[i] + 1<<" ";
    // cout <<"\n";
    FOR(i ,0 , n- 1){
        // hj < wi  wj < hi ,  
        auto it1 = ub(sorted_h.begin() , sorted_h.end() , mp(w[i],LLONG_MIN));
        if(it1 != sorted_h.begin()){
            it1--;
            //got hmin
            ll wmin = pfxmn_for_w_on_sorted_h[it1->s];
            if(wmin < h[i]){
                // change
                ll index = index_of_w_in_pfxmn_for_w_on_sorted_h[it1->s];
                ans[i] = index;
            }
        }
    }
    // cout <<"***************************\n";
    rep(i , n) cout << ans[i] + 1<<" ";
    cout <<"\n";
}

int main(){
    IOS;
    cout<<fixed<<setprecision(20);
    ll NTC=1;
    cin>>NTC;
    ll PTC=0;
    while((PTC++)<NTC){
        // cout<<"Case #"<<PTC<<":"<<' ';
        solve();
        //cout<<"\n";
    }
    //cerr<<"Time : "<<1000*((double)clock())/(double)CLOCKS_PER_SEC<<"ms\n";
}

ll power(ll x,ll y){if(y==0) return 1;ll a=power(x,y/2);if(y%2==0) return a*a;else return x*a*a;}
ll powermod(ll x,ll ex,ll md){ll ans=1ll;while(ex>0){if(ex&1ll) ans=(ans*x)%md; ex>>=1ll;x=(x*x)%md;}return ans;}

