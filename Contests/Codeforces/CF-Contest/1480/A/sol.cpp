#include <bits/stdc++.h>
#include<array>
using namespace std;
int main()
{
    int t;
    cin>>t;
    while(t--){
        string s1,s2;
        cin>>s1>>s2;
        // cout << s1 << "\n";
        s1.erase(2,1);
        // cout << s1 << "\n";
        // cout << s2 << "\n";
        int n;
        cin>>n;
        string s3,s4,s5,s6,s7,s8;
        for(int i=0;i<n;i++){
               cin>>s3>>s4>>s5>>s6;
               s3.erase(2,1);
               s5.erase(2,1);
               // cout <<" in "<<  i << " : " << s3 << " " << s4 << " : " << s5 << " " << s6 << "\n";
               s7[0]=s3[0];  
               s7[1]=s3[1];
               s8[0]=s5[0];
               s8[1]=s5[1];
           if((s2=="AM" && s4=="AM" && s6=="AM") || (s2=="AM" && s4=="AM" && s6=="PM") || (s2=="PM" && s4=="PM" && s6=="AM") || (s2=="PM" && s4=="PM" && s6=="PM")){
                int c=0,count=0;
                for(int i=0;i<4;i++){
                  if(s1[0]=='0' && s1[3]!='0'){
                    if(count==3){
                          c=1;
                          cout<<"1";
        }
                    if(i==3)break;
                    if(s1[i+1]>=s3[i+1])count=count+1;
        }
                 if(s1[0]=='0' && s1[3]=='0'){
                     if(count==2){
                             c=1;
                             cout<<"1";
            }
                     if(i==2)break;
                     if(s1[i+1]>=s3[i+1])count=count+1;

        }
                if(s1[0]!='0'){
                    if(s1[i]>=s3[i])count=count+1;
                    if(count==4){
                          c=1;
                          cout<<"1";
           }
        }
    }
         if(c!=1)cout<<"0";
          }
      if((s2=="AM" && s4=="PM" && s6=="PM") || (s2=="PM" && s4=="AM" && s6=="AM"))cout<<"0";
      if((s2=="AM" && s4=="PM" && s6=="AM")){
              int no1=s3[0]*1000+s3[1]*100+s3[2]*10+s3[3]*1;
              int no2=s5[0]*1000+s5[1]*100+s5[2]*10+s5[3]*1;
              if(s3[0]==0){
                     if(no1<=no2)cout<<"1";
                     else cout<<"0";
    }
              if(s3[0]!=0){
                    if(no2<=no1)cout<<"1";
                     else cout<<"0";
    }
}

      if((s2=="PM" && s4=="AM" && s6=="PM")){
               int no1=s7[0]*10+s7[1]*1;
               int no2=s8[0]*10+s8[1]*1;
               if(no1>=no2)cout<<"1";
               else cout<<"0";
}

      }
      cout<<endl;
    }
}