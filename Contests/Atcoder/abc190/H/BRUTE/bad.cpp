#include <bits/stdc++.h>
using namespace std;
int main()
{
    int t;
    cin>>t;
    while(t--){
        int n,m;
        cin>>n>>m;
        int u[m];
        int v[m];
        for(int i=0;i<m;i++){
            cin>>u[i];
            cin>>v[i];
        }
        int arr[m];
        arr[0]=m-1;
        int k=1;
        for(int i=0;i<m-1;i++){
            if(u[i]!=u[m-1] && v[i]!=u[m-1] && u[i]!=v[m-1] && v[i]!=v[m-1]){
                    arr[k]=i;
                    k++;
        }
        }
        sort(arr,arr+k);
        for(int i=0;i<k;i++)cout<<arr[i]<<" ";
        cout<<endl;
    }
}