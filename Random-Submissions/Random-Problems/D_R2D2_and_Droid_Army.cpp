#include "bits/stdc++.h"
using namespace std; 

#define IOS {ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);}
#define ll int

ll powermod(ll x,ll ex,ll md){ll ans=1ll;while(ex>0){if(ex&1ll) ans=(ans*x)%md; ex>>=1ll;x=(x*x)%md;}return ans;}
inline ll gcd(ll a,ll b) {if(b==0)return a;a%=b;return gcd(b,a);}
inline ll max(ll a,ll b) {return((a>b)?a:b);}
inline ll min(ll a,ll b) {return((a>b)?b:a);}

const ll N=1e5+1;
ll a[N][5],n,m,k;
ll tree[4*N][5];
void pull(ll node,ll l,ll r){
        for(ll j=0;j<m;j++){
                tree[node][j]=max(tree[l][j] , tree[r][j]);
        }
}
void build(ll node,ll l,ll r){
        if(l==r){
                for(ll j=0;j<m;j++){
                        tree[node][j]=a[l][j];
                }
        }
        else{
                ll mid=l+(r-l)/2;
                
                build(2*node,l,mid);
                build(2*node+1,mid+1,r);
                
                pull(node,node*2,node*2+1);
        }
}
ll query(ll node,ll l,ll r,ll start,ll end, ll index){
        if(end<l || start>r) return LLONG_MIN; //operation (inf , -inf , 0 ...)
        else if(start<=l && end>=r) return tree[node][index];
        else{
                ll mid=l+(r-l)/2;
                
                ll p1=query(2*node,l,mid,start,end,index);
                ll p2=query(2*node+1,mid+1,r,start,end,index);
                
                return max(p1,p2); //operation
        }
}
//build(1,0,n-1) .... query(1,0,n-1,l,r) .... update(1,0,n-1,x,a[x])
bool check(ll start , ll end){
        ll sum=0;
        for(ll j=0;j<m;j++){
                sum+=query(1,0,n-1,start,end,j);
        }
        if(sum<=k) return true;
        else return false;
}
int main(){
        IOS;
        cin>>n>>m>>k;
        for(ll i=0;i<n;i++){
                for(ll j=0;j<m;j++) cin>>a[i][j];
        }
        build(1,0,n-1);
        ll start=n,end=0,mx=LLONG_MIN;
        for(ll i=0;i<n;i++){
                ll l=i,r=n-1,mid=0,ans=-1;
                while(l<=r){
                        mid=l+(r-l)/2;
                        if(check(i,mid)) l=mid+1,ans=mid;
                        else r=mid-1;
                }
               if(ans!=-1){
                       ll len=ans-i+1;
                       mx=max(mx,len);
                       if(mx==len) start=i,end=ans;
                }
        }
        if(mx==LLONG_MIN){
                for(ll j=0;j<m;j++) cout<<0<<" ";
        }
        else{
                for(ll j=0;j<m;j++){
                        cout<<query(1,0,n-1,start,end,j)<<" ";
                }
        }
        cout<<"\n";
}
