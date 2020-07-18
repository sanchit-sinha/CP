class lca{
    public:
    int MAX_D;
    int dfs_timer;
    vector<vector<int>> g;
    vector<vector<int>> ancestor;
    vector<bool> visited;
    vector<int> depth;
    vector<int> en;
    vector<int> ex;
    vector<int> par;
    lca(int n){
        g.resize(n + 1);
        visited.resize(n + 1 , 0);
        depth.resize(n + 1 , 0);
        en.resize(n + 1, 0);
        ex.resize(n + 1, 0);
        par.resize(n + 1, -1);
        dfs_timer = 0;
        MAX_D = ceil(log2(n));
        ancestor = vector<vector<int>>(MAX_D + 1, vector<int>(n + 1 , -1));
        build_lca_table();
    }
    void addEdge(int l, int r){
        g[l].push_back(r);
    }
    void do_dfs(int sr){
        visited[sr] = true;
        dfs_timer++;
        en[sr] = dfs_timer;
        for(auto child : g[sr]){
            if(!visited[child]){
                ancestor[0][child] = sr;
                depth[child] = depth[sr] + 1;
                par[child] = sr; 
                do_dfs(child);
            }
        }
        dfs_timer++;
        ex[sr] = dfs_timer;
    }
    void build_lca_table(){
        int n = (int) g.size() - 1;
        this->do_dfs(1);
        for(int d = 1; d <= MAX_D; d++){
            for(int i = 1; i <= n; i++){
                if(ancestor[d - 1][i] != -1){
                    ancestor[d][i] = ancestor[d - 1][ancestor[d - 1][i]];
                }
            }
        }
    }
    int climb(int l , int d){
        int i = l;
        for(int dd = 0; (dd <= MAX_D && i != -1) ;dd++){
            if((1 << dd) & d) i = ancestor[dd][i];
        }
        return i;
    }
    int get_lca(int i , int j){
        if(depth[i] > depth[j]) i = climb(i , depth[i] - depth[j]);
        if(depth[j] > depth[i]) j = climb(j , depth[j] - depth[i]);
        assert(depth[j] == depth[i]);
        if(i == j) return i;
        for(int d = MAX_D; d >= 0; --d){
            if(ancestor[d][i] != ancestor[d][j]){
                i = ancestor[d][i];
                j = ancestor[d][j];
            }
        }
        return ancestor[0][i];
    }
    int isAncestor(int u , int v){
        return (en[u] <= en[v] && ex[v] <= ex[u]);
    }
};
