#include <bits/stdc++.h>
#define ll long long
#define mod 1000000007
using namespace std;

ll fun(string s, int n){
    ll dp[n+1];
    ll freq[26];
    memset(freq, -1, sizeof(freq));
    dp[0]=1;
    for(ll i=1;i<=n;i++){
        dp[i] = (2 * dp[i-1]%mod)%mod;
        if(freq[s[i-1]-'A']!=-1)
            dp[i] = (dp[i]%mod - dp[freq[s[i-1]-'A']]%mod + mod); 
        freq[s[i-1]-'A'] = i-1;
    }
    return dp[n]%mod;
}

int main()
{
    int t; cin>>t;
    while(t--){
        ll l;
        string str; cin>>str;
        l=str.size();
        cout<<fun(str, l)<<endl;
    }
    return 0;
}
