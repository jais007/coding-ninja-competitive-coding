#include <bits/stdc++.h>
using namespace std;
int dp[32][11][2];
int fun(int *a, int k, int n, int flag){
    if(k<=0 || n<=0) return 0;
    if(dp[n][k][flag]!=-1) return dp[n][k][flag];
    int opt1=fun(a+1, k, n-1, flag);
    int opt2;
    if(flag){
        opt2 = fun(a+1, k-1, n-1, 0) + a[0];
    }
    else{
        if(k<=0) return 0;
        else opt2 = fun(a+1, k, n-1, 1) - a[0];
    }
    dp[n][k][flag]=max(opt1, opt2);
    return dp[n][k][flag];
}

int main()    
{
    int t; cin>>t;
    while(t--){ 
        int k, n; cin>>k>>n;
        int *a = new int[n];
        for(int i=0;i<n;i++) cin>>a[i];
        //for(int i=0;i<n;i++) cout<<i[a]<<" ";
        for(int i=0;i<32;i++) for(int j=0;j<11;j++) for(int k=0;k<2;k++) dp[i][j][k]=-1;
        cout<<fun(a, k, n, 0)<<endl;
        }
    return 0;
}
