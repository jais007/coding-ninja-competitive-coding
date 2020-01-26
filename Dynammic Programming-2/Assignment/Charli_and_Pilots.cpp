#include <bits/stdc++.h>
using namespace std;

static int dp[10001][10001];

int fun(int a[], int c[], int n, int d){
    if(n==0) return 0;
    if(d==0){
        return a[0] + fun(a+1, c+1, n-1, 1);
    }
    else if(d>=n) return c[0] + fun(a+1, c+1, n-1, d-1);
    else{
        if(dp[n][d]!=-1) return dp[n][d];
        int opt1 = a[0] + fun(a+1, c+1, n-1, d+1);
        int opt2 = c[0] + fun(a+1, c+1, n-1, d-1);
        dp[n][d]=min(opt1, opt2);
        return dp[n][d];
    }
}

int main(){
    int n; cin>>n;
    int a[n], c[n];
    for(int i=0;i<5000;i++) for(int j=0;j<5000;j++) dp[i][j]=-1;
    for(int i=0;i<n;i++) cin>>c[i]>>a[i];
    cout<<fun(a, c, n, 0);
    return 0;
}
