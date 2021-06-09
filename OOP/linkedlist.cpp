#include "bits/stdc++.h"
using namespace std;
#define f                   first
#define s                   second
#define pb                  push_back
#define ll                  long long
#define ld                  long double
#define lb                  lower_bound
#define ub                  upper_bound
#define mp                  make_pair
#define mt                  make_tuple
#define pll                 pair<ll , ll>
#define vll                 vector<ll>
#define vvll                vector<vll>
#define vpll                vector<pll>
#define all(c)              (c).begin(),(c).end()
#define sz(c)               (int)(c.size())
#define get(x,c)            get<x>(c)
#define trav(a,x)           for(auto a = x.begin() ; a != x.end() ; a++)
#define rep(i, n)           for(int i = 0; i < (n) ; i++)
#define FOR(i, a, b)        for(int i = (a); i <= (b); i++)
#define FORR(i, b, a)       for(int i = (b); i >= (a); i--)

string to_string(string s) {return '"' + s + '"';} string to_string(const char* s) {return to_string((string) s);} string to_string(bool b) {return (b ? "true" : "false");} template <typename A, typename B>string to_string(pair<A, B> p) {return "(" + to_string(p.first) + ", " + to_string(p.second) + ")";} template <typename A>string to_string(A v) {bool first = true; string res = "{"; for (const auto &x : v) {if (!first) {res += ", ";} first = false; res += to_string(x);} res += "}"; return res;} void debug_out() { cerr << "\n"; } template <typename Head, typename... Tail>void debug_out(Head H, Tail... T) {cerr << " " << to_string(H) << "\n"; debug_out(T...);}
#ifdef LOCAL
#define debug(...) cerr << "[" << #__VA_ARGS__ << "]:", debug_out(__VA_ARGS__)
#else
#define debug(...) 42
#endif

inline ll gcd(ll a, ll b) {if (b == 0) return a; a %= b; return gcd(b , a);}
inline ll max(ll a, ll b) {return ((a > b) ? a : b);}
inline ll min(ll a, ll b) {return ((a > b) ? b : a);}
ll power(ll x, ll ex);
ll powermod(ll x, ll ex, ll md);

const ll inf = 1e18 + 9;
const ll mod = 1e9 + 7;
const ld PI = acos(-1);
const ld eps = 1e-9;

/* Linked List */
struct node {
    ll data; //data
    struct node *next;// pointer to the next node
};

void display(struct node* head) { // linkedlist traversal
    while (head != NULL) {
        cout << head -> data << " ";
        head = head -> next;
    }

    cout << "\n";
    return;
}

void push_front(struct node* &head , ll new_data) { // push node at the front
    node* new_node = new node;
    new_node -> data = new_data;

    new_node -> next = head;
    head  = new_node;
}

void insert_after(struct node* &prev , ll new_data) { // adding node after a given node
    node* new_node = new node;
    new_node -> data = new_data;

    new_node -> next = prev -> next;
    prev -> next = new_node;

    return;
}

void append(struct node* head , ll new_data) { // adding node at the end
    node* temp_node = new node;
    temp_node = head;

    while (temp_node -> next != NULL) temp_node = temp_node -> next;

    node* new_node = new node;
    new_node -> data = new_data;

    temp_node -> next = new_node;
    new_node -> next = NULL;
}

void deletenode(struct node* &head , ll key) { // deletes first occurrence of node
    struct node* temp = head;
    struct node* prev = NULL;

    if (head == NULL) return;
    if (temp != NULL && temp -> data == key) {
        head = temp -> next;
        free(temp);
        return;
    }

    while (temp != NULL && temp -> data != key) prev = temp , temp = temp -> next;
    prev -> next = temp -> next;
    free(temp);

    return;
}

void deletenode_at_position(struct node* &head, int position) {
    if (head == NULL) return;

    node* temp = new node;
    temp = head;

    node* prev = NULL;

    if (position == 0) {
        head = temp -> next;
        free(temp);
        return;
    }

    while (temp != NULL && position > 0) {
        prev = temp;
        temp = temp -> next;
        position--;
    }

    if (position || temp == NULL) return;

    prev -> next = temp -> next;
    free(temp);

    return;
}

void delete_node_at_given_pointer(struct node* ptr) {
    node* to_delete = ptr -> next;
    ptr -> data = to_delete -> data;
    ptr -> next = to_delete -> next;

    free(to_delete);
    return;
}
void solve() {
    // creating list with 3 nodes
    node* head = NULL;
    node* second = NULL;
    node* third = NULL;

    head = new node;
    second = new node;
    third = new node;

    head -> data = 1;
    head -> next = second;
    second -> data = 2;
    second -> next = third;
    third -> data = 3;
    third -> next = NULL;

    // traversing thorug linkedlist
    display(head);

    // adding values from front
    push_front(head , 0);
    display(head);

    // adding after a given node
    insert_after(head -> next , 9);
    display(head);

    //adding node at the end
    append(head , 10);
    display(head);

    // delete first occurrence of a node with a give data
    deletenode(head , 2);
    display(head);

    // delete node at the given position
    deletenode_at_position(head , 5);
    display(head);

    // delete node with given pointer
    delete_node_at_given_pointer(head);
    display(head);


}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    cout << fixed << setprecision(20);

    ll NTC = 1;
    // cin >> NTC;

#ifdef SIEVE
    sieve();
#endif
#ifdef NCR
    factorial();
#endif
#ifdef PREPROCESS
    preprocess();
#endif

    ll PTC = 0;
    while ((PTC++) < NTC) {
        // cout << "Case #" << PTC << ":" << ' ';
        solve();
        // cout << "\n";
    }
    // cerr << "Time : " << 1000 * ((double)clock()) / (double)CLOCKS_PER_SEC << "ms\n";
}

ll power(ll x, ll y) {if (y == 0) return 1; ll a = power(x, y / 2); if (y % 2 == 0) return a * a; else return x * a * a;}
ll powermod(ll x, ll ex, ll md) {ll ans = 1ll; while (ex > 0) {if (ex & 1ll) ans = (ans * x) % md; ex >>= 1ll; x = (x * x) % md;} return ans;}
