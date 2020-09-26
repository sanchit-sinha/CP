/**
 *    author:  Sanchit Sinha
 *    created: 26.09.2020 12:56:19       
**/
#include "bits/stdc++.h"
using namespace std; 

#define ll long long
inline ll gcd(ll a,ll b) {if(b==0)return a;a%=b;return gcd(b,a);}
inline ll max(ll a,ll b) {return((a>b)?a:b);}
inline ll min(ll a,ll b) {return((a>b)?b:a);}
ll powermod(ll x,ll ex,ll md){ll ans=1ll;while(ex>0){if(ex&1ll) ans=(ans*x)%md; ex>>=1ll;x=(x*x)%md;}return ans;}

const ll N=3e5+11;
pair<pair<ll,ll> , pair<ll,ll> > tree[4*N];
ll a[N],n,q;
// node of tree contains : +,+  +,- ; -,+  , -,-
pair< pair<ll,ll> , pair<ll,ll>> pull(pair<pair<ll,ll> , pair<ll,ll> >l ,pair<pair<ll,ll> , pair<ll,ll> >r){
        pair< pair<ll,ll> , pair<ll,ll>> p;
        p.first.first   = max (l.first.second + r.first.first , l.first.first + r.second.first);
        p.first.second  = max (l.first.second + r.first.second , l.first.first + r.second.second);
        p.second.first  = max (l.second.second + r.first.first , l.second.first + r.second.first);
        p.second.second = max (l.second.second + r.first.second , l.second.first + r.second.second);

        return p;
}
void build(ll node,ll l,ll r){
        if(l==r){
                tree[node].first.first  = a[l]; //+ +
                tree[node].first.second = 0;  // + -
                tree[node].second.first = 0;  // -  +
                tree[node].second.second = -a[l]; // - - 
        }
        else{
                ll mid=l+(r-l)/2;
                build(2*node,l,mid);
                build(2*node+1,mid+1,r);
                tree[node] = pull(tree[node*2] , tree[node*2 + 1]);
        }
}
void update(ll node,ll l,ll r,ll index,ll val){
        if(index>r || index<l) return ;
        if(l==r) {
                tree[node].first.first = val; //+ +
                tree[node].first.second = 0;  // + -
                tree[node].second.first = 0;  // -  +
                tree[node].second.second = -val; // - - 
        }
        else{
                ll mid=l+(r-l)/2;
                update(node*2,l,mid,index,val);
                update(node*2+1,mid+1,r,index,val);
                tree[node] = pull(tree[node*2] , tree[node*2 + 1]);;
        }
}
pair<pair<ll,ll> , pair<ll,ll> > query(ll node,ll l,ll r,ll start,ll end){
        if(end<l || start>r){
                return make_pair(make_pair(0,0) , make_pair(0,0));
        }
        else if(start<=l && end>=r){
                return tree[node];
        }
        else{
                ll mid=l+(r-l)/2;
                pair<pair<ll,ll>,pair<ll,ll>> p1=query(2*node,l,mid,start,end);
                pair<pair<ll,ll>,pair<ll,ll>> p2=query(2*node+1,mid+1,r,start,end);

                return pull(p1,p2);
        }
}
//build(1,0,n-1) .... query(1,0,n-1,l,r) .... update(1,0,n-1,x,a[x])
int main(){
        ios::sync_with_stdio(false);
        cin.tie(0);
        ll T;
        cin>>T;
        while(T--){
                //clear
                for(ll i=0;i<n;i++) a[i]=0;

                cin>>n>>q;
                for(ll i=0;i<n;i++) cin>>a[i];       
                build(1,0,n-1);
                pair<pair<ll,ll> , pair<ll,ll>> ans = query(1,0,n-1,0,n-1);
                cout << max(ans.first.first , ans.first.second)<<"\n";
                while(q--){
                        ll l,r;
                        cin>>l>>r;
                        l--,r--;
                        update(1,0,n-1,l,a[r]);
                        update(1,0,n-1,r,a[l]);
                        swap(a[l],a[r]);

                        pair<pair<ll,ll> , pair<ll,ll>> ans = query(1,0,n-1,0,n-1);
                        cout << max(ans.first.first , ans.first.second)<<"\n";
                }
        }    
        return 0;
}