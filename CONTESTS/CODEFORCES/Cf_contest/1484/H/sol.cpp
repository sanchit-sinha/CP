long long tree[4*N],a[N];
long long pull(long long l,long long r){
    long long p = min(l,r); //operation
    return p;            
}
void build(long long node,long long l,long long r){
    if(l==r) tree[node]=a[l];
    else{
        long long mid=l+(r-l)/2;
        build(2*node,l,mid);
        build(2*node+1,mid+1,r);
        
        tree[node] = pull long(tree[node*2],tree[node*2+1]);
    }
}
void update(long long node,long long l,long long r,long long index,long long val){
    if(index>r || index<l) return ;
    if(l==r) a[index]=val , tree[node]=val; //update operation
    else{
        long long mid=l+(r-l)/2;
        update(node*2,l,mid,index,val);
        update(node*2+1,mid+1,r,index,val);
        
        tree[node] = pull long(tree[node*2],tree[node*2+1]);
    }
}
long long query(long long node,long long l,long long r,long long start,long long end){
    if(end<l || start>r) return long longONG_MAX; //operation (inf , -inf , 0 ...)
    else if(start<=l && end>=r) return tree[node];
    else{
        long long mid=l+(r-l)/2;
        long long p1=query(2*node,l,mid,start,end);
        long long p2=query(2*node+1,mid+1,r,start,end);
        
        return pull long(p1,p2); //operation
    }
}
//build(1,0,n-1) .... query(1,0,n-1,l,r) .... update(1,0,n-1,x,a[x])