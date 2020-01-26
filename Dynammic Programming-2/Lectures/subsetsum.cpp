#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n; cin>>n;
    int a[n]; for(int i=0;i<n;i++) cin>>a[i];
    int w; cin>>w;
    int x[w+1], y[w+1];
    for(int i=1;i<=w;i++) x[i]=0;
    x[0]=1;
    
    for(int i=1;i<=n;i++){
        for(int j=1;j<=w;j++){
            if(i%2!=0){
            y[j]=x[j];
            if(a[i-1]<=j) y[j] = x[j] || x[j-a[i-1]];
            }
            else{
                x[j]=y[j];
                if(a[i-1]<=j) x[j] = y[j] || y[j-a[i-1]];
            }
        }
    }
    if(n%2!=0) if(y[w])cout<<"Yes"; else cout<<"No";
    else if(x[w]) cout<<"Yes"; else cout<<"No";
    // if(dp[n][w]) cout<<"Yes";
    // else cout<<"No";
    return 0;
}
