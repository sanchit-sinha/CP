ll sz[N];
ll parent[N];
void make_set(ll node){
	parent[node] = node;
	sz[node] = 1;
}
ll find_set(ll a){
	if(a == parent[a]) return a;
	return parent[a] = find_set(parent[a]);
}
void union_set(ll a , ll b){
	ll p1 = find_set(a);
	ll p2 = find_set(b);
	if(p1 != p2){
		if(sz[p2] > sz[p1]) swap(p1 , p2);
		parent[p2] = p1;
		sz[p1] += sz[p2];
	}
}
