#define ll long long


int fun(int *weights, int *values, int n, int w, int **dp){
    
    if(n<0 || w==0) return 0;
    if(dp[n][w]!=-1) return dp[n][w];
    if(weights[n]<=w){
        int opt1=values[n]+fun(weights, values, n-1, w-weights[n], dp);
        int opt2=fun(weights, values, n-1, w, dp);
        dp[n][w]=max(opt1, opt2);
        return dp[n][w];
    }
    else{
        dp[n][w]=fun(weights, values, n-1, w, dp);
        return dp[n][w];
    }
}

int iter_fun(int *wt, int *val, int n, int w){
    
    int x[w+1], y[w+1];
    for(int i=0;i<=w;i++) x[i]=0;
    for(ll i=1;i<=n;i++){
        for(ll j=1;j<=w;j++){
            if(i%2!=0){
            y[j]=x[j];
            if(wt[i-1]<=j)
            y[j] = max(val[ i-1]+x[j-wt[i-1]], x[j]);
            }
            else{
            x[j]=y[j];
            if(wt[i-1]<=j)
            x[j] = max(val[ i-1]+y[j-wt[i-1]], y[j]);
            }
        }
    }
    if(n%2==0) return x[w];
    else
    return y[w];   
}

int fun2(int *wt, int *val, int n, int w){
    int **dp=new int*[n+1];
    for(int i=0;i<=n;i++){
        dp[i]=new int[w+1];
    }
    for(int i=0;i<=n;i++) dp[i][0]=0;
    for(int i=0;i<=w;i++) dp[0][i]=0;
    
    for(int i=1;i<=n;i++){
        for(int j=1;j<=w;j++){
            dp[i][j] = dp[i-1][j];
            if(wt[i-1]<=j) dp[i][j] = max(val[i-1]+dp[i-1][j-wt[i-1]], dp[i-1][j]);
        }
    }
    return dp[n][w];
}

int knapsack(int* weights, int* values, int n, int W){
    //cout<<fun(weights, values, n-1, W)<<endl;
    // ll **dp=new ll*[n+1];
    // for(ll i=0;i<=n;i++){
    //     dp[i]=new ll[W+1];
    //     for(ll j=0;j<=W;j++) dp[i][j]=0;
    // }
    // return fun2(weights, values, n, W);
    return iter_fun(weights, values, n, W);
}
