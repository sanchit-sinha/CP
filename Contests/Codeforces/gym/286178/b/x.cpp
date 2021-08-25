//Utkarsh.25dec
#include <bits/stdc++.h>
#define ll long long int 
#define ull unsigned long long int
#define pb push_back
#define mp make_pair
#define mod 1000000007
#define rep(i,n) for(ll i=0;i<n;i++)
#define loop(i,a,b) for(ll i=a;i<=b;i++)
#define vi vector <int>
#define vs vector <string>
#define vc vector <char>
#define vl vector <ll>
#define all(c) (c).begin(),(c).end()
#define max3(a,b,c) max(max(a,b),c)
using namespace std;
const int N=500023;
bool vis[N];
vector <int> adj[N];
void solve()
{
    ll n;
    cin>>n;
    ll minx=INT_MAX,maxx=INT_MIN,miny=INT_MAX,maxy=INT_MIN;
    vector <pair<ll,ll>> v;
    v.pb(mp(0,0));
    loop(i,1,(4*n+1))
    {
        ll x,y;
        cin>>x>>y;
        v.pb(mp(x,y));
        if(x<minx)
            minx=x;
        if(x>maxx)
            maxx=x;
        if(y<miny)
            miny=y;
        if(y>maxy)
            maxy=y;
    }
    ll cminx=0,cmaxx=0,cminy=0,cmaxy=0;
    pair <ll,ll> pminx,pmaxx,pminy,pmaxy;
    loop(i,1,(4*n+1))
    {
        ll x,y;
        x=v[i].first;
        y=v[i].second;
        if(x==minx)
        {
            cminx++;
            pminx=mp(x,y);
        }
        if(x==maxx)
        {
            cmaxx++;
            pmaxx=mp(x,y);
        }
        if(y==miny)
        {
            cminy++;
            pminy=mp(x,y);
        }
        if(y==maxy)
        {
            cmaxy++;
            pmaxy=mp(x,y);
        }
    }
    if(cminx==1)
    {
        cout<<pminx.first<<' '<<pminx.second;
        return;
    }
    if(cmaxx==1)
    {
        cout<<pmaxx.first<<' '<<pmaxx.second;
        return;
    }
    if(cminy==1)
    {
        cout<<pminy.first<<' '<<pminy.second;
        return;
    }
    if(cmaxy==1)
    {
        cout<<pmaxy.first<<' '<<pmaxy.second;
        return;
    }
    loop(i,1,(4*n+1))
    {
        ll x,y;
        x=v[i].first;
        y=v[i].second;
        if(x==minx||x==maxx||y==miny||y==maxy)
        {
            continue;
        }
        cout<<x<<' '<<y;
        return;
    }
}
int main()
{
    ios_base::sync_with_stdio(false); 
    cin.tie(NULL);
    int T=1;
    //cin>>T;
    int t=0;
    while(t++<T)
    {
        //cout<<"Case #"<<t<<":"<<' ';
        solve();
        //cout<<'\n';
    }
}