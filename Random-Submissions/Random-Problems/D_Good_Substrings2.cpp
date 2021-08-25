#include "bits/stdc++.h"
using namespace std; 

#define IOS {ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);}
#define ll long long 
bool good[2];
ll bad,ans;
string s,t;
const int ALPHABET_SIZE = 26; 
// trie node 
struct TrieNode{ 
        struct TrieNode* children[ALPHABET_SIZE]; 
        // isEndOfWord is true if the node represents 
        // end of a word 
        bool isEndOfWord; 
}; 
// struct TrieNode* root = getNode()

// Returns new trie node (initialized to NULLs) 
struct TrieNode* getNode(void){ 
        struct TrieNode* pNode = new TrieNode; 
        pNode->isEndOfWord = false; 
        for (int i = 0; i < ALPHABET_SIZE; i++) 
                pNode->children[i] = NULL; 
        return pNode; 
} 
//struct TrieNode* root = getNode(); 
  
// If not present, inserts key into trie 
// If the key is prefix of trie node, just 
// marks leaf node 
void insert(struct TrieNode* root, string key){ 
        struct TrieNode* pCrawl = root; 
        for (int i=0; i<(int)key.size(); i++) { 
                int index = key[i] - 'a'; 
                if (!pCrawl->children[index]) pCrawl->children[index] = getNode(); 
                pCrawl = pCrawl->children[index]; 
        } 
        // mark last node as leaf 
        pCrawl->isEndOfWord = true; 
} 
// insert(root, keys); 

// Returns true if key presents in trie, else 
// false 
bool search(struct TrieNode* root, string key) { 
        struct TrieNode* pCrawl = root; 
        for (int i=0; i<(int)key.size(); i++) { 
                int index=(key[i]-'a'); 
                if (!pCrawl->children[index]) return false; 
                pCrawl = pCrawl->children[index]; 
        } 
    return (pCrawl != NULL && pCrawl->isEndOfWord); 
} 
// search(root, key)

// Returns true if root has no children, else false 
bool isEmpty(TrieNode* root) { 
        for (int i=0; i<ALPHABET_SIZE; i++) if (root->children[i]) return false; 
        return true; 
} 
  
// Recursive function to delete a key from given Trie 
TrieNode* remove(TrieNode* root, string key, int depth = 0){ 
        // If tree is empty 
        if (!root) return NULL; 
        // If last character of key is being processed 
        if (depth==(int)key.size()){ 
                // This node is no more end of word after 
                // removal of given key 
                if (root->isEndOfWord) root->isEndOfWord = false; 
        
                // If given is not prefix of any other word 
                if (isEmpty(root)) { 
                        delete (root); 
                        root = NULL; 
                } 
                return root; 
        } 
        
        // If not last character, recur for the child 
        // obtained using ASCII value 
        int index = key[depth] - 'a'; 
        root->children[index] = remove(root->children[index], key, depth + 1); 
        
        // If root does not have any child (its only child got  
        // deleted), and it is not end of another word. 
        if (isEmpty(root) && root->isEndOfWord == false) { 
                delete (root); 
                root = NULL; 
        } 
        
        return root; 
} 
// remove(root, key)
void solve(struct TrieNode* root,ll ct){
        for(ll i=0;i<ALPHABET_SIZE;i++){
                if(root->children[i]){
                        if(!good[i]){
                                if(ct+1<=bad){
                                        ans++;
                                        solve(root->children[i],ct+1);
                                }
                        }
                        else{
                                ans++;
                                solve(root->children[i],ct);
                        }
                }
        }
}

int main(){
        IOS;
        cin>>s>>t>>bad;
        for(ll i=0;i<ALPHABET_SIZE;i++) good[i]=t[i]-'0';
        ll n=(int)s.size();
        struct TrieNode* root = getNode(); 
        for(ll i=0;i<n;i++){
                ll len=n-i+1;
                string check=s.substr(i,len+1);
                insert(root,check);
        }
        solve(root,0);
        cout<<ans<<"\n";        
}
