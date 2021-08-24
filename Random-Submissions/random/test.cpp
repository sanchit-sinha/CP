#include "bits/stdc++.h"
using namespace std; 

#define IOS {ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);}
#define ll long long 
 
const int NMAX = 1010;
 
int N, K, V[10][NMAX], Pos[10][NMAX], Best[NMAX], Ans;
vector<int> G[NMAX];
bool Used[NMAX];
 
void DFS(int Node)
{
    Used[Node] = 1;
    cout<<"---------\n";
        cout << Node<<"\n";
    for(int i = 0; i < G[Node].size(); ++ i)
    {
        if(!Used[G[Node][i]])
            DFS(G[Node][i]);
        Best[Node] = max(Best[Node], Best[ G[Node][i] ] + 1);
    }
    Best[Node] = max(Best[Node], 1);
    Ans = max(Ans, Best[Node]);
}
 
int main()
{
   // freopen("d.in", "r", stdin);
   // freopen("d.out", "w", stdout);
 
    scanf("%i %i", &N, &K);
    for(int i = 1; i <= K; ++ i)
        for(int j = 1; j <= N; ++ j)
        {
            scanf("%i", &V[i][j]);
            Pos[i][ V[i][j] ] = j;
        }
 
    for(int i = 1; i <= N; ++ i)
        for(int j = 1; j <= N; ++ j)
        {
            if(i == j) continue;
            bool OK = 1;
            for(int k = 1; k <= K; ++ k)
                if(Pos[k][i] >= Pos[k][j])
                    OK = 0;
            if(OK) G[i].push_back(j);
        }

        for(int i=1;i<=N;i++){
                 int len=(int)G[i].size();
                 if(len) cout<<i<<" : ";
                 for(int j=0;j<len;j++) cout<<G[i][j]<<" ";
                 cout<<"\n";
        }
    for(int i = 1; i <= N; ++ i)        
        if(!Used[i])
            DFS(i);
 
        for(ll i=1;i<=N;i++) cout<<Best[i]<<" ";
        cout<<"\n\n";
    printf("%i\n", Ans);
}