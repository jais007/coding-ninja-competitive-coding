#include <bits/stdc++.h>
using namespace std;

int main()
{
    int t; cin>>t;
    while(t--){
        cin>>a>>b;
        int k; cin>>k;
        int l1 = a.size();
        int l2 = b.size();
        for(int i=0;i<101;i++) for(int j=0;j<101;j++) for(int k=0;k<101;k++) dp[i][j][k]=-1;
        cout<<max(0, Fun(0, 0, l1, l2, k))<<endl;
    }
    return 0;
}
