template <typename T>
class segmentTree{
    public:
     vector<T> tree;
     vector<T> v;
     vector<T> lazy;
     segmentTree(vector<T> &vec){
            v = vec;
            tree.resize(4 * v.size());
            lazy.resize(4 * v.size());
            fill(lazy.begin() , lazy.end() , 0);
            buildUtil(0 , 0 , v.size() - 1);
     }
     void buildUtil(int x , int start , int end){  // O(N)
         if(start == end){
             tree[x] = v[start];
             return;
         }
         int mid = ((start + end) >> 1);
         buildUtil(x + x + 1, start , mid); 
         buildUtil(x + x + 2, mid + 1, end);
         tree[x] = max(tree[x + x + 1] , tree[x + x + 2]); // oper
     } 
     
     void lazyUpdate(int x , int start , int end , int l , int r, T val){ // O(logN)
      // time complexity analysis is similar to function query.
            if(lazy[x] != 0){
                tree[x] += lazy[x]; // Update current node by lazy value and push
                if(start != end){
                lazy[x + x + 1] += lazy[x]; 
                lazy[x + x + 2] += lazy[x]; 
                }
                lazy[x] = 0;
            }
            if(start > end || l > end || r < start) return;
 
            if(start >= l && end <= r){ // node completely within
                lazy[x] = val;
                return; 
            }
            int mid = ((start + end) >> 1);
            lazyUpdate(x + x + 1,   start, mid , l , r , val);
            lazyUpdate(x + x + 2, mid + 1, end , l , r , val);
            T left  = tree[x + x + 1] + lazy[x + x + 1];
            T right = tree[x + x + 2] + lazy[x + x + 2];
            tree[x] = max(left , right);
      }
      T lazyQuery(int x , int start , int end , int qs , int qe){
            if(start > end || qe < start || qs > end) return -inf;
            if(lazy[x] != 0){
                tree[x] += lazy[x];
                if(start != end){
                    lazy[x + x + 1] += lazy[x];
                    lazy[x + x + 2] += lazy[x];
                }
                lazy[x] = 0;
            }
            if(start >= qs && end <= qe) return tree[x];
            int mid = ((start + end) >> 1);
            T lef = lazyQuery(x + x + 1 , start  , mid , qs , qe);
            T rt  = lazyQuery(x + x + 2 , mid + 1, end , qs , qe);
            return max(lef , rt); // combine nodes
      }
};