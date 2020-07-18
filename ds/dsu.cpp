int sz[N];
int parent[N];
void make_set(int node){
    parent[node] = node;
    sz[node] = 1;
}
int find_set(int a){
    if(a == parent[a]) return a;
    return parent[a]=find_set(parent[a]);
}
void union_set(int a,int b){
    int p1=find_set(a);
    int p2=find_set(b);
    if(p1!=p2){
    	if(sz[p2]>sz[p1]) swap(p1,p2);
	parent[p2]=p1;
	sz[p1]+=sz[p2];
    }
}
