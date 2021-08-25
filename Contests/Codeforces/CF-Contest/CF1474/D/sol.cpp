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

bool find(ll a[] , ll n){

}
void solve(){
    ll n;
    cin >> n;
    ll a[n];

    ll temp[n];

    rep(i , n) cin >> a[i];
    rep(i , n) temp[i] = a[i];

    ll l = 0 , r = n -1 ;

    ll ct = 0;
    while(l <= r){
        ll nextl = l + 1;
        ll prevr = r - 1;

        if(nextl <= r){
            if(a[l] <= a[nextl]){
                a[nextl] -= a[l];
                a[l] = 0;
                l++;
            }
            else{
                ct++;
                swap(a[l] , a[nextl]);
                a[nextl] -= a[l];
                a[l] = 0;
                l++;
            }
            if(a[nextl] == 0) l++;
        }
        else break;

        if(prevr >= l){
            if(a[r] <= a[prevr]){
                a[prevr] -= a[r];
                a[r] = 0;
                r--;
            }
            else{
                ct++;
                swap(a[r] , a[prevr]);
                a[prevr] -= a[r];
                a[r] = 0;
                r--;
            }
            if(a[prevr] == 0) r--;
        }
        else break;
    }     

    bool ok = 1;
    rep(i , n) if(a[i]) ok = 0;

    if(ok) cout <<"YES\n";
    else {
        ll nzero = 0;
        ll index = -1;
        rep(i , n){
            if(a[i]){
                nzero++;
                index = i;
            }
        }
        if(nzero > 1) cout <<"NO\n";
        else{
            bool got = 0;
            if(index > 0){
                rep(i , n) a[i] = temp[i];

                swap(a[index] , a[index - 1]);          
                ll l = 0 , r = n -1 ;

                ll ct = 0;
                while(l <= r){
        ll nextl = l + 1;
        ll prevr = r - 1;

        if(nextl <= r){
            if(a[l] <= a[nextl]){
                a[nextl] -= a[l];
                a[l] = 0;
                l++;
            }
            else{
                ct++;
                swap(a[l] , a[nextl]);
                a[nextl] -= a[l];
                a[l] = 0;
                l++;
            }
            if(a[nextl] == 0) l++;
        }
        else break;

        if(prevr >= l){
            if(a[r] <= a[prevr]){
                a[prevr] -= a[r];
                a[r] = 0;
                r--;
            }
            else{
                ct++;
                swap(a[r] , a[prevr]);
                a[prevr] -= a[r];
                a[r] = 0;
                r--;
            }
            if(a[prevr] == 0) r--;
        }
        else break;
    }       

                bool ok = 1;
                rep(i , n) if(a[i]) ok = 0;

                if(ok) got = 1;
            } 

            if(index < n - 1){
                rep(i , n) a[i] = temp[i];

                swap(a[index] , a[index + 1]); 

                ll l = 0 , r = n -1 ;

                ll ct = 0;
                while(l <= r){
        ll nextl = l + 1;
        ll prevr = r - 1;

        if(nextl <= r){
            if(a[l] <= a[nextl]){
                a[nextl] -= a[l];
                a[l] = 0;
                l++;
            }
            else{
                ct++;
                swap(a[l] , a[nextl]);
                a[nextl] -= a[l];
                a[l] = 0;
                l++;
            }
            if(a[nextl] == 0) l++;
        }
        else break;

        if(prevr >= l){
            if(a[r] <= a[prevr]){
                a[prevr] -= a[r];
                a[r] = 0;
                r--;
            }
            else{
                ct++;
                swap(a[r] , a[prevr]);
                a[prevr] -= a[r];
                a[r] = 0;
                r--;
            }
            if(a[prevr] == 0) r--;
        }
        else break;
    }          

                bool ok = 1;
                rep(i , n) if(a[i]) ok = 0;

                if(ok) got = 1;
            }

            if(got) cout <<"YES\n";
            else cout <<"NO\n";

        }

    }
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

