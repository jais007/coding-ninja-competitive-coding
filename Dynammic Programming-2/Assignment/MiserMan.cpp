#include <bits/stdc++.h>
using namespace std;

int fun(int **a, int ind1, int ind2, int n, int m, int **dp){
    //cout<<ind1<<" "<<ind2<<endl;
    if(ind1>=n) return 0;
    if(ind2>=m || ind2<0) return INT_MAX;
    //cout<<ind1<<" "<<ind2<<endl;
    if(dp[ind1][ind2]!=-1) return dp[ind1][ind2];
    int opt1 = a[ind1][ind2]+min(fun(a, ind1+1, ind2+1, n, m, dp),
                                 min(fun(a, ind1+1, ind2, n, m, dp), fun(a, ind1+1, ind2-1, n, m, dp)));
    //cout<<opt1<<endl;
    dp[ind1][ind2]=opt1;
    return opt1;                         
}

int main()
{
    int n, m; cin>>n>>m;
    int **a = new int*[n];
    for(int i=0;i<n;i++) a[i]=new int[m];
    int **dp = new int*[n];
    for(int i=0;i<n;i++){
        dp[i]=new int[m];
        for(int j=0;j<m;j++) dp[i][j]=-1;
    }
    for(int i=0;i<n;i++) for(int j=0;j<m;j++) cin>>a[i][j];
    int mn=INT_MAX;
    for(int i=0;i<m;i++){
        int x=fun(a, 0, i, n, m, dp);
        //cout<<x<<endl;
        if(x<mn) mn = x; 
    }
    cout<<mn;
    return 0;
}
