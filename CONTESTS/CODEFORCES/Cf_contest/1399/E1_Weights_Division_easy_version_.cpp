#include "bits/stdc++.h"
using namespace std; 

#define IOS {ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);}
#define ll long long 
const ll N=1e5+11;

ll n,s,times_used[N],weight[N],initial_weight[N];
vector<pair<ll,ll>> v[N];
vector<ll> leaf;
bool vis[N];
multiset<pair<ll,pair<ll,ll>>> value_subtracted;// VALUE , wt,times_appeard

void dfs(ll node){
    vis[node]=1;
    bool enter=0;
    for(auto child:v[node]){
        ll wt=child.second;
        ll chld=child.first;
        if(!vis[chld]){
            // cout << node <<" " << chld <<" " << wt <<"\n";
            weight[chld]=weight[node]+wt;
            initial_weight[chld]=wt;
            
            enter=1;
            dfs(chld);
            times_used[node]+=times_used[chld];
        }
    }
    if(!enter) leaf.push_back(node),times_used[node]=1;

}
int main(){
    IOS;
    ll T;
    cin>>T;
    while(T--){
        // clear
        for(ll i=0;i<=n;i++) times_used[i]=weight[i]=vis[i]=initial_weight[i]=0,v[i].clear();
        value_subtracted.clear(),leaf.clear();

        cin>>n>>s;
        ll ans=0;
        for(ll i=0;i<n-1;++i){
            ll x,y,w;
            cin>>x>>y>>w;
            while(w>s){
                w/=2;
                ans++;
            }
            // cout << x << " " << y <<" " << w <<'\n'; 
            v[x].push_back(make_pair(y,w));
            v[y].push_back(make_pair(x,w));
        }      
        dfs(1);

        //DEBUG
        // for(ll i=1;i<=n;i++) cout <<i <<" : " <<weight[i] <<" "<<times_used[i]<<" \n";
        // cout<<"\n\n";

        ll sum=0;

        for(ll i=0;i<(int)(leaf.size());++i) sum += weight[leaf[i]];

        for(ll i=1;i<=n;i++){
            ll x= initial_weight[i];
            value_subtracted.insert(make_pair((x-(x/2))*times_used[i] , make_pair(x,times_used[i])));
        }
        
        // cout << sum <<" " <<ans <<  " \n";
        // for(auto it=value_subtracted.begin() ; it != value_subtracted.end() ; it++){
        //         ll sub=it->first;
        //         ll wt=(it->second).first;
        //         ll times=(it->second).second;

        //         cout << sub <<" " << wt <<" " << times<<"\n";
        // }
        // return 0;
        // cout <<"\n\n";
        ll ct=0;
        while(sum>s){
            if(int(value_subtracted.size())){
                
                // cout<<"---------------\n";
                // for(auto it=value_subtracted.begin() ; it != value_subtracted.end() ; it++){
                //     ll sub=it->first;
                //     ll wt=(it->second).first;
                //     ll times=(it->second).second;

                //     cout << sub <<" " << wt <<" " << times<<"\n";
                // }
                // cout<<"-------------------\n\n";

                auto last=value_subtracted.rbegin();
                ll sub=last->first;
                ll wt=(last->second).first;
                ll times=(last->second).second;

                // cout << sub <<" " << wt <<" " << times<<"\n";
                // cout << sum<<" "<< ans<<"\n\n";
                // if(ct==100){
                
                //     return 0;
                // }

                auto it=(value_subtracted.find(make_pair(sub,make_pair(wt,times))));
                if(it != value_subtracted.end()) value_subtracted.erase(it);

                sum-=sub;
                ans++;

                wt/=2;
                sub=(wt-(wt/2))*times;

                    ct++;
                value_subtracted.insert(make_pair(sub,make_pair(wt,times)));
            }
        }

        cout << ans<<"\n";

    }    
}