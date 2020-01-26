#include<bits/stdc++.h>
int dp[10001][10001];
int fun(char *s1, int m, char *s2, int n)
{
    if(m==0) return 10000;
    if(n<=0) return 1;
    int i;
    
    for(i=0;i<n;i++)
        if(s1[0]==s2[i]) break; 
    
    if(i==n) return 1;
    if(dp[m][n]!=-1) return dp[m][n];
    int opt1 = 1+fun(s1+1, m-1, s2+i+1, n-i-1);
    
    int opt2 = fun(s1+1, m-1, s2, n);
    
    dp[m][n] = min(opt1, opt2);

    return dp[m][n] ;
}

int solve(string S,string V)
{
    int m=S.size(), n=V.size();
    char *s1 = new char[m];
    char *s2 = new char[n];
    for(int i=0;i<m;i++) s1[i]=S[i];
    for(int i=0;i<n;i++) s2[i]=V[i];
    for(int i=0;i<m+1;i++) for(int j=0;j<=n;j++) dp[i][j]=-1;
    return fun(s1, S.length(), s2, V.length());
}
