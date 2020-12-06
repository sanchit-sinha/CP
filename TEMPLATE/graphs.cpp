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

5)CYCLE DETECTION USING DFS
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
				
				



















		
