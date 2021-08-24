#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
// above one shoud be above using namespace std

template<typename T>
#define o_set(T) tree<T, null_type,less<T>, rb_tree_tag,tree_order_statistics_node_update>
// o_set(ll) name ; -- defining ordered set
//member functions :
//1. order_of_key(k) : number of elements strictly lesser than k
//2. find_by_order(k) : counting from zero it returns the k-th largest or smallest element in the set - returns iterator