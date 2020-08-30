#include "bits/stdc++.h"
using namespace std; 

#define IOS {ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);}
#define ll long long 
const ll N=1e3+11;
ll n,m,xx1,yy1,xx2,yy2;
set< pair< pair<ll,ll> , ll > >v[N][N];
string s[N];
ll dx[4]={1,-1,0,0};
ll dy[4]={0,0,1,-1};
ll dis[N][N];
void bfs(ll node_x,ll node_y){
        for(ll i=0;i<n;i++){
                for(ll j=0;j<m;j++) dis[i][j]=LLONG_MAX;
        }
        dis[node_x][node_y]=0;
        deque<pair<ll,ll>> d;
        d.push_back(make_pair(node_x,node_y));
        while(!d.empty()){
                pair<ll,ll> from = d.front();
                d.pop_front();
                for(auto child:v[from.first][from.second]){
                        pair<ll,ll> to=child.first;
                        ll len=child.second;
                        if(dis[from.first][from.second] + len < dis[to.first][to.second]){
                                dis[to.first][to.second] = dis[from.first][from.second]+len;
                                if(len==0) d.push_front(make_pair(to.first , to.second));
                                else d.push_back(make_pair(to.first , to.second));
                        }
                }
        }
}
int main(){
        IOS;
        cin>>n>>m>>xx1>>yy1>>xx2>>yy2;
        xx1--,yy1--,xx2--,yy2--;
        for(ll i=0;i<n;i++) cin>>s[i];        
        for(ll i=0;i<n;i++){
                for(ll j=0;j<m;j++){
                        if(s[i][j]=='.'){
                                for(ll k=0;k<4;k++){
                                        ll x=i+dx[k] , y=j+dy[k];
                                        if(x>=0 && x<n && y>=0 && y<m && s[x][y]=='.'){
                                                pair<pair<ll,ll> ,ll > p1= make_pair(make_pair(i,j) , 1);
                                                pair<pair<ll,ll> ,ll > p2= make_pair(make_pair(x,y) , 1);
                                                auto it=v[x][y].find(p1);
                                                if(it!=v[x][y].end()) {
                                                        v[x][y].erase(it);
                                                        v[i][j].erase(v[i][j].find(p2));
                                                }
                                                v[i][j].insert(make_pair(make_pair(x,y) , 0));
                                                v[x][y].insert(make_pair(make_pair(i,j) , 0));
                                        }
                                }
                                for(ll k1=-2;k1<=2;k1++){
                                        for(ll k2=-2;k2<=2;k2++){
                                                ll x=i+k1 , y=j+k2;
                                                if(x>=0 && x<n && y>=0 && y<m && s[x][y]=='.'){
                                                        pair<pair<ll,ll> ,ll > p= make_pair(make_pair(i,j) , 0);
                                                        auto it=v[x][y].find(p);
                                                        if(it==v[x][y].end()){
                                                                v[i][j].insert(make_pair(make_pair(x,y) , 1));
                                                                v[x][y].insert(make_pair(make_pair(i,j) , 1));
                                                        }
                                                }
                                        }
                                }
                        }
                }
        }
        bfs(xx1,yy1);

        if(dis[xx2][yy2]==LLONG_MAX) cout<<"-1\n";
        else cout<<dis[xx2][yy2]<<"\n";
}
