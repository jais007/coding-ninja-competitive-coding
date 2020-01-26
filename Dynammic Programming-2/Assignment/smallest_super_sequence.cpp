

int dp[1001][1001];
int fun(char *s1, int l1, char *s2, int l2){
    if(l1==0) return l2;
    if(l2==0) return l1;
    if(s1[0]==s2[0]){
        if(dp[l1][l2]!=-1) return dp[l1][l2];
        dp[l1][l2] = 1+fun(s1+1, l1-1, s2+1, l2-1);
        return dp[l1][l2];
    }
    else{
        if(dp[l1][l2]!=-1) return dp[l1][l2];
        dp[l1][l2]=1+min(fun(s1+1, l1-1, s2, l2), fun(s1, l1, s2+1, l2-1));
        return dp[l1][l2];
    }
}

int smallestSuperSequence(char str1[], int len1, char str2[], int len2) { 
    for(int i=0;i<1001;i++) for(int j=0;j<1001;j++) dp[i][j]=-1;
    return fun(str1, len1, str2, len2);
}
