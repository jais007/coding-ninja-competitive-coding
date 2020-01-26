#include <bits/stdc++.h>
using namespace std;

int n, W;

int fun(int val[], int wt[], int n, int w, int **dp){
    if(n<0 || w<=0) return 0;
    if(dp[n][w]!=-1) return dp[n][w];
    
    if(wt[n]<=w){
        int opt1 = val[n]+fun(val, wt, n-1, w-wt[n], dp);
        int opt2 = fun(val, wt, n-1, w, dp);
        dp[n][w] = max(opt1, opt2);
        return dp[n][w];
    }
    else{
        dp[n][w]=fun(val, wt, n-1, w, dp);
        return dp[n][w];
    }
}

int iter_fun(int val[], int wt[], int n, int w){
    int **dp = new int*[n+1];
        for(int i=0;i<=n;i++){
            dp[i] = new int[w+1];
            for(int j=0;j<=w;j++) dp[i][j]=0;
        }
    for(int i=1;i<=n;i++){
        for(int j=1;j<=w;j++){
            if(wt[i-1]<=j){
                dp[i][j] = max(val[i-1]+dp[i-1][j-wt[i-1]], dp[i-1][j]);
            }
            else dp[i][j]=dp[i-1][j];
        }
    }
    int money = 0;
        for(int i=0;i<=w;i++){
            if(dp[n][i]==dp[n][w]){
                money = i;
                break;
            }
        }
    cout<<money<<" "<<dp[n][w]<<endl;
    // for(int i=0;i<=n;i++){
    //     for(int j=0;j<=w;j++) cout<<dp[i][j]<<" ";
    //     cout<<endl;
    // }
}

int main()
{
    while(1){
    cin>>W>>n;
    if(n==0 && W==0) break;
    else{
        //cout<<W<<" "<<n<<endl;
        int val[n], wt[n];
        for(int i=0;i<n;i++) cin>>wt[i]>>val[i];
        int **dp = new int*[n+1];
        for(int i=0;i<=n;i++){
            dp[i] = new int[W+1];
            for(int j=0;j<=W;j++) dp[i][j]=-1;
        }
//         int res = fun(val, wt, n-1, W, dp);
//         int money = 0;
//         for(int i=0;i<=W;i++){
//             if(dp[n-1][i]==res){
//                 money = i;
//                 break;
//             }
//         }
//         cout<<money<<" "<<res<<endl;
        
//         for(int i=0;i<=n;i++){
//             for(int j=0;j<=W;j++) cout<<dp[i][j]<<" ";
//             cout<<endl;
//         }
        iter_fun(val, wt, n, W);
    }   
    }
}
