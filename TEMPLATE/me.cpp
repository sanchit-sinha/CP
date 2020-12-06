#include "bits/stdc++.h"
/* Properties of modulo:
	(a/b)%m ,where m is prime  = (a%m) * (b^(m-2))%m
*/
    /*ROLLING HASH
    Rabin-Karp algorithm for pattern matching in a string in O(n) time
    Calculating the number of different substrings of a string in O(n2logn)
    Calculating the number of palindromic substrings in a string.
    */
using namespace std;
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
#define IOS { ios :: sync_with_stdio(false); cin.tie(0); cout.tie(0); }
#define ll long long
#define pb push_back
#define nl cout<<"\n"
#define endl "\n"
#define all(c) (c).begin(),(c).end()
#define trav(a,x) for(auto a = x.begin() ; a != x.end() ; a++)
#define lb lower_bound
#define ub upper_bound
#define f first
#define s second
//template<typename T>
//#define o_set(T) tree<T, null_type,less<T>, rb_tree_tag,tree_order_statistics_node_update>
// o_set(ll) name ; -- defining ordered set
//member functions :
//1. order_of_key(k) : number of elements strictly lesser than k
//2. find_by_order(k) : counting from zero it returns the k-th largest or smallest element in the set - returns iterator
bool compare(ll a, ll b){
    return a > b;
}
inline ll max(ll a,ll b)
{return ((a>b)?a:b);}
inline ll min(ll a,ll b)
{return ((a>b)?b:a);}
inline ll gcd(ll a ,ll b)
{if(b==0) return a;a%=b;return gcd(b,a);}
ll power(ll x, ll ex , ll md) {
    ll ans = 1ll;
    while (ex > 0) {
        if (ex & 1ll) ans = (ans * x) % md;
        ex >>= 1ll;
        x = (x * x) % md;
    }
    return ans;
}
void solve(){

}
int main(){
    IOS;
    ll T=1;
    //cin>>T;
    ll t=0;
    while(t++<T){
        //cout<<"Case #"<<t<<":"<<' ';
        solve();
        //cout<<'\n';
    }
    cerr << "Time : " << 1000 * ((double)clock()) / (double)CLOCKS_PER_SEC << "ms\n";
}
