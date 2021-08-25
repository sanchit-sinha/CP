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
    vll a(n);
    rep(i , n) cin >> a[i];

    
    vll left(n , 0) , right(n , 0);
    map<ll , ll> l , r;
    map<ll , ll> index1 , index2;

    left[0] = right[0] = 1;
    FOR(i , 1 , n - 1){
        if(a[i] > a[i - 1]) {
            left[i] = left[i - 1] + 1;
            right[i] = 1;
        }
        else{
            left[i] = 1;
            right[i] = right[i - 1] + 1;
        }
    }


    FOR(i , 0 , n - 1){
        ll lft = left[i];
        ll rght = right[i];

        l[left[i]]++;
        r[right[i]]++;

        index1[left[i]] = i;
        index2[right[i]] = i - right[i] + 1;
    }

    // trav(it , l){
    //     cout << it->f << " : " << index1[it->f] << " - " << it->s << "\n"; 
    // }
    // cout << "**********\n";

    // trav(it , r){
    //     cout << it->f << " : " << index2[it->f] << " - " << it->s << "\n"; 
    // }
    // cout << "**********\n";
    ll mxl = (l.rbegin())->f;
    ll mxr = (r.rbegin())->f;

    if(mxr > mxl){
        if(r[mxr] > 1) cout << 0 << "\n";
        else{
            ll index = index2[mxr];
            if(index == 0 || index == n - 1){
                cout << 0 << "\n";
                return ;
            }
            ll counterpart = left[index];

            if(mxr > counterpart) cout << 0 << "\n";
            else{
                if(mxr&1) cout << 1 << "\n";
                else cout << 0 << "\n";
            }
        }
    }
    else if(mxl > mxr){
        if(l[mxl] > 1) cout << 0 << "\n";
        else{
            ll index = index1[mxl];
            if(index == 0 || index == n - 1){
                cout << 0 << "\n";
                return ;
            }
            ll counterpart = right[index];

            if(mxl > counterpart) cout << 0 << "\n";
            else{
                if(mxl&1) cout << 1 << "\n";
                else cout << "0\n";
            }
        }
    }
    else{
        ll index = index1[mxl];
        if(index == 0 || index == n - 1){
            cout << 0 << "\n";
            return ;
        }
        if(l[mxl] == 1 && r[mxr] == 1){
            if(mxl&1) cout << 1 << "\n";
            else cout << 0 << "\n";
        }
        else cout << "0\n";
    }
}

int main(){
    IOS;
    cout<<fixed<<setprecision(20);
    #ifdef SIEVE
        sieve();
    #endif
    #ifdef NCR
        factorial();
    #endif
    ll NTC=1;
    // cin>>NTC;
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


// A : [ 39, 99, 70, 24, 49, 13, 86, 43, 88, 74, 45, 92, 72, 71, 90, 32, 19, 76, 84, 46, 63, 15, 87, 1, 39, 58, 17, 65, 99, 43, 83, 29, 64, 67, 100, 14, 17, 100, 81, 26, 45, 40, 95, 94, 86, 2, 89, 57, 52, 91, 45 ]
// B : [ 1221, 360, 459, 651, 958, 584, 345, 181, 536, 116, 1310, 403, 669, 1044, 1281, 711, 222, 280, 1255, 257, 811, 409, 698, 74, 838 ]
// 7569 1000000000 1000000000 440996283 778688 1000000000 1000000000 1000000000 1000000000 1000000000 83 1000000000 440996283 778688 3364 59969536 1000000000 1000000000 7569 1000000000 970299 1000000000 59969536 1000000000 970299 

Your Input: 5 1 2 3 4 5 15 1 2 3 4 5 6 7 8 9 10 11 12 13 14 15
Expected output is 8 8 8 8 5 5 5 5 5 3 3 3 2 2 1
