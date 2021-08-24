
1) DFS
void dfs(ll node){
	vis[node] =1;
	fo(i , 0 , (int)(v[node].size() - 1)){
		ll child = v[node][i];
		if(vis[child] == 0){
			dfs(child);
		}
	}
}

//o(n)
2) COUNTING COMPONENTS
void dfs(ll node){
	vis[node] = 1;
	fo(i , 0 ,(int)(v[node].size() - 1)){
		ll child = v[node][i];
		if(vis[child] == 0){
			dfs(child);
		}
	}
}
int main(){
	.
	.
	.
	.
	ll ct= 0;
	fo(i , 1 , n){
		if(vis[i] == 0){
			dfs(i);
			ct++;
		}
	}
}


3)SINGLE SOURCE SHORTEST PATH ON TREE USING DFS
bool vis[size] = {0};
vector<ll> v[size];
ll dis[size];
void dfs(ll node , ll d){
	vis[node] = 1;
	dis[node] = d;
	fo(i , 0 , (int)(v[node].size() -1 )){
		ll child = v[node][i];
		if(vis[child] == 0){
			dis[child] = dis[node] + 1;
			dfs(node , dis[node] + 1 );
		}
	}
}
int main(){
	.
	.
	.
	.
	dfs(1 , 0);
}
4)BIPARTITE GRAPH TEST
bool dfs(ll node , ll c){
	vis[node] = 1;
	colour[node] = c;
	fo(i , 0 ,(int)(v[node].size() - 1)){
		ll child = v[node][i];
		if(vis[child] == 0){
			if(dfs(child , c^1) == false) return false;
		}
		else{
			if(colour[child] == colour[node]) return false;
		}
	}
return true;
}
int main(){
	.
	.
	.
	.
	if(dfs(1 , 0) == false) cout<< "NO\n";
	else cout<<"YES\n";
}

5)CYCLE DETECTION USING DFS IN UNDIRECTED GRAPH
bool dfs(ll node , ll parent){
	vis[node] = 1;
	fo(i , 0 , (int)v[node].size() - 1)){
		ll child = v[node][i];
		if(vis[child] == 0) if(dfs(child , node) == true) return true;
		else{
			if(child != parent) return true;
		}
	return false; // there is no cycle
}
int main(){
	.
	.
	.	
	.
	if(dfs(1,1) == true) cout<< " THERE IS A CYCLE" << endl;
	else cout << "THERE IS NO CYCLE" << endl;
}


6)IN/OUT TIME OF A TREE
vector<ll> v[size];
ll vis[size] ;
in[size];
out[size];
ll timer;
void dfs(ll node){
	vis[node] = 1;
	in[node] = timer++;

	fo(i , 0 , (int)(v[node].size() -1 )){
		ll child = v[node][i];
		if(vis[child] == 0) dfs(child);
	}
	out[node] = timer++;
}
int main(){
}



7)FINDING DIAMETER OF A TREE
nsq solution : for each index run dfs to find the largest distance
greedy : apply dfs twice as shown--
bool vis[size] = {0};
vector<ll> v[size];
ll dis[size];
ll d1 = LLONG_MIN;
ll node1;
void dfs(ll node , ll d){
	vis[node] = 1;
	dis[node] = d;
	d1 =  max(d , d1);
	if(d == d1) node1 = node;
	fo(i , 0 , (int)(v[node].size() -1 )){
		ll child = v[node][i];
		if(vis[child] == 0){
			dis[child] = dis[node] + 1;
			dfs(node , dis[node] + 1 );
		}
	}
}
int main(){
	.
	.
	.
	.
	dfs(1 , 0);
	fo(i,0,size){
		vis[i] = 0;
		dis[i] = 0;
	}
	d1 = LLONG_MIN;
	dfs(node1 , 0);
	cout << d1 << endl;
}

8)CALCULATING SUBSIZE IN TREE
ll vis[size] = 0;
vector<ll> v[size];
ll subsize[node] = 0;
// returns size of that node 
int dfs(ll node){
	vis[node] = 1;
	ll curr_size = 1;
	fo(i , 0, (int)(v[node].size() - 1)){
		ll child = v[node][i];
		if(vis[child] == 0){
			curr_size = curr_size + dfs(child);
		}
	}
	subsize[node] = curr_size;
	return curr_size;
}


9)BREADTH FIRST SEARCH
.
.
.
void bfs(ll node){
	deque<ll> q;
	vis[node] = 1;
	dis[node] =0 ;
	q.pb(node);
	while(!q.empty()){
		ll cur= *q.begin();
		q.pop_front();
		fo(i , 0 , (int)v[cur].size() -1)){
			ll child= v[cur][i];
			if(vis[child] == 0){
				vis[child] = 1;
				dis[child] = dis[cur] + 1;
				q.pb(child);
			}
		}
	}
}
				
10) FINDING SHORETEST PATH FOR WEIGHTED(NON - negative weights) GRAPH -- DIJKSTRA'S' THEOREM:
// finding shortest paths to all other vertices from a given node
	
	// v[i] - stores pair of (vertex , weight)
	void dij(ll node){
	set<pll> s;
	rep(i , n) {
		dist[i + 1] = inf;
		if(i != node - 1) s.insert({dist[i + 1] , i + 1});
	}
	dist[node] = 0;
	s.insert({dist[node] , node});
	while(!s.empty()){
		ll from = s.begin()->s;
		s.erase(s.begin());
		for(auto child : v[from]){
			ll len = child.s;
			ll to = child.f;
			if(dist[from] + len < dist[to]){
				s.erase(make_pair(dist[to] , to));
				dist[to] = dist[from] + len;
				s.insert({dist[to] , to});
			}
		}
	}
}


                }
            }
        }
    }

// Calcualting dfs in a subtree of a tree if parent is known
    void dfs (int a , int p){
	par[a] = p;
 
	for (auto x : g[a]){
		if (x != p){
			dis[x] = dis[a] + 1;
			dfs(x , a);
		}
	}
}

// Floyd-Warshall Algorithm - FINDING SHORTEST PATH BETWEEN ALL PAIRS OF VERTICES
// finding shortest path between all pair of vertices
for (int k = 0; k < n; ++k) {
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            d[i][j] = min(d[i][j], d[i][k] + d[k][j]); 
        }
        
        
    }
}

11) checking whether a graph is directed and acyclic or not
void dfs(ll node){
	vis[node] = 1;
	for(auto child:v[node]){
		if(!vis[child]) dfs(child);
	}
	dep[node]++;
}
bool checkdag(){
	for(ll i = 0 ; i < n ; i++){
		ll t1 = dep[i];
		for(auto child:v[i]){
			ll t2 = dep[child];
			if(t2 > t1) return false;
		}
	}
	return true;
}


12)multisource bfs
//insert all initial vertices in queuew
// multisource bfs -- nodes are assigned min distance at one go
void bfs(vpll vrtx){
	deque<pll> d;
	//important part
	for(ll i = 0 ; i < k; i++){
		d.pb({vrtx[i].f , vrtx[i].s});
		vis[vrtx[i].f][vrtx[i].s] = 1;
	}
	while(!d.empty()){
		auto it = d.begin();
		ll x = it->f;
		ll y = it->s;
		d.pop_front();
		if(x + 1 < n){
			if(!vis[x + 1][y]){
				a[x + 1][y] = a[x][y] + 1;
				vis[x + 1][y] = 1;
				d.pb({x + 1 , y});
			}
		}
		if(x - 1 >= 0){
			if(!vis[x - 1][y]){
				a[x - 1][y] =  a[x][y] + 1;
				vis[x - 1][y] = 1;
				d.pb({x - 1 , y});
			}
		}
		if(y + 1 < m){
			if(!vis[x][y + 1]){
				a[x][y + 1] = a[x][y] + 1;
				vis[x][y + 1] = 1;
				d.pb({x , y + 1});
			}
		}
		if(y - 1 >= 0){
			if(!vis[x][y - 1]){
				a[x][y - 1] = a[x][y] + 1;
				vis[x][y - 1] = 1;
				d.pb({x, y - 1});
			}
		}
	}
}













		
