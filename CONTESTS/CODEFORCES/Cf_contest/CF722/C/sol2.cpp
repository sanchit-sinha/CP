/*=====================This is jd_299=====================*/
#include<bits/stdc++.h>
using namespace std;
#define endl "\n" 
#define pb push_back
#define f first
#define s second
#define mp make_pair
#define fast ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0)
#define mod 1000000007
#define pi acos(-1)
#define debug(x) cout<< "[" << #x << " = " << x <<"]\n";
typedef long long int ll;
typedef long double ld;
typedef vector<ld> vld;
typedef vector<ll> vll;
typedef pair<ll,ll> pll;

ll pow(ll a,ll b)
{
    ll res=1;
    while(b>0)
    {
        if(b%2==1) res=(res*a)%mod;
        a=(a*a)%mod;
        b/=2;
    }
    return res;
}

bool isPrime(ll n)
{
    ll flag=0;
    for(ll i=2;i<=sqrt(n);i++)
    {
        if(n%i==0) 
        {
            flag=1;
            break;
        }
    }
    if(flag==1) return false;
    else return true;
}


ll lrs[2][2000005];
vll adj_list[2000005];
ll dp[2][2000005];

void dfs(ll v,ll p)
{
    dp[0][v] = dp[1][v] = 0;
    for(auto u:adj_list[v])
    {
        if(u==p) continue;

        dfs(u,v);
        
        dp[0][v]+=max(dp[0][u]+abs(lrs[0][v]-lrs[0][u]), dp[1][u]+abs(lrs[0][v]-lrs[1][u]));
        dp[1][v]+=max(dp[0][u]+abs(lrs[1][v]-lrs[0][u]), dp[1][u]+abs(lrs[1][v]-lrs[1][u]));
    }
}

ll n;
void solve()    //check t
{
    cin>>n;
    
    for(ll i=1;i<=n;i++)
    {
        cin>>lrs[0][i]>>lrs[1][i];
    }
    for(ll i=0;i<n-1;i++)
    {
        ll u,v;
        cin>>u>>v;
        adj_list[u].pb(v);
        adj_list[v].pb(u);
    }
    dfs(1 , -1);
    cout<<max(dp[1][1],dp[0][1])<<endl;
}

int main()
{
    fast;
    ll t=1;
    cin>>t;
    while(t--)
    {
        solve();
    }
}