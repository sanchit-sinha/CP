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
    set<ll> s;
    ll a[n + 1];
    rep(i , n){
    	cin >> a[i + 1];
    	s.insert(a[i + 1]);
    } 

    ll len = sz(s);
    bool start = 0 , end = 0;
    if(len == n && *s.rbegin() == n) {
    	start = 1;
    }
    if(*s.begin() == 1) end = 1;
    if(a[1] == a[n]){
    	rep(i,n-1) cout << 0;
    	cout <<end << "\n";
    	return ;
    }
    ll k = 0;
    ll left[n + 1] = {0};
    ll right[n + 1] = {0};
    vpll v;
    v.pb(mp(a[1] , 1));
    left[1] = -1;
    FOR(i , 2, n){
    	ll prev , index;
    	if(sz(v)){
	    	prev = v.back().f;
	    	index = v.back().s;
	    }
	    else{
	    	prev = -1;
	    	index = -1;
	    }

    	if(a[i] >= prev){
    		v.pb(mp(a[i] , i));
    	}
    	else{
    		ll ele = prev;
    		ll indexx = index;
    		while(ele > a[i]){
    			v.pop_back();
				if(sz(v)){
	    			ele = v.back().f;
	    			indexx = v.back().s;
	    		}
	    		else{
	    			ele = LLONG_MIN;
	    			indexx = -1;
	    			break;
	    		}
    		}

    		index = indexx;
    		prev = ele;
    		v.pb(mp(a[i] , i));
    	}

    	left[i] = index;

    }

    // FOR(i , 1 , n) cout << left[i] <<" ";
    // cout << "\n";


    v.clear();
    v.pb(mp(a[n] , n));
    right[n] = -1;

    FORR(i , n - 1 , 1){
    	ll next , index;
    	if(sz(v)){
    		next = v.back().f;
    		index = v.back().s;
    	}
    	else{
    		next = -1;
    		index = -1;
    	}

    	if(a[i] >= next){
    		v.pb(mp(a[i] , i));
    	}
    	else{
    		ll ele = next;
    		ll indexx = index;

    		while(ele > a[i]){
    			v.pop_back();

    			if(sz(v)){
    				ele = v.back().f;
    				indexx = v.back().s;
    			}
    			else{
    				ele = -1;
    				indexx = -1;
    				break;
    			}
    		}

    		next = ele;
    		index = indexx;
    	}


    	right[i] = index;
    }


    // FOR(i , 1 , n){
    // 	cout << left[i] <<" ";
    // }
    // cout << "\n";

    // FOR(i , 1 , n){
    // 	cout << right[i] << " ";
    // }
    // cout << "\n";


    k = 2;
	FOR( i, 2, n - 1){
		ll ans = 0;
		if(a[i] <= a[ i - 1] && a[i] <= a[i + 1]){
			if(left[i] == -1 && right[i] == -1) k = n - 1;
			else{

				ll x = i - left[i] + 1;
				ll y = right[i] - i + 1;
				ll val = min(i - left[i] + 1, right[i] - i + 1);
				ans = max(ans , val);

				if(x == y){
					ll x = min(a[left[i]] , a[right[i]]);
					ans = max(ans , x);
				}
				else{

					if(val == i - left[i] + 1) ans = max(ans , a[left[i]]);
					else ans = max(ans , a[right[i]]);
				}
				
			}

		}
		k = max(k , ans);
    }


    cout << start;

    FOR(i,2,k - 1) cout << 0;
    FOR(i,k,n - 1) cout << 1;

    cout << end;

    cout << "\n";
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
		