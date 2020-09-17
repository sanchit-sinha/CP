        //     vector<bool>vis(n , 0);
        //     vector<ll> dis(n , 0),cost(n,LLONG_MAX);
        //     set<pair<ll,ll>> s;
        //     dis[0]=0;
        //     for(ll i=1;i<n;i++){
        //         ll x=LLONG_MAX;
        //         s.insert(make_pair(x , i));
        //         dis[i]=x;
        //     }
        //     s.insert({0,0});
        //     vis[0]=1;
        //     cost[0]=0;
        // // 0 --------x ---------- y
        //     while(!s.empty()){
        //         ll from = s.begin()->second;
        //         s.erase(s.begin());
        //         vis[from]=1;
        //         for(ll j=0;j<n;j++){
        //             if(j!=from && j!=0){
        //                 ll len=abs(a[j][0] - a[from][0]) + abs(a[j][1] - a[from][1]);
        //                 ll to = j;
        //                 if(dis[from] + len <= dis[to]){
        //                         cost[to]=min(cost[to] , len);
        //                     cout << from <<" " << len <<" " << to <<"\n";
        //                         s.erase(make_pair(dis[to],to));
        //                         dis[to]=dis[from]+len;
        //                         s.insert({dis[to] , to});
        //                 }
        //             }
        //         }
        //     }
        //     ll ans=0;
        // for(ll i=0;i<n;i++) cout<< dis[i] <<" ";
        // cout<<"\n";
        //     for(ll i=0;i<n;i++) cout<< cost[i] <<" ";
        // cout<<"\n";
        //     for(ll i=0;i<n;i++) ans+=cost[i];
        //     return ans;