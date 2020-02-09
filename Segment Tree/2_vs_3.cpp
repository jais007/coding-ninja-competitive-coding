#include<bits/stdc++.h>
using namespace std;
int tree[400004];
int power[100002];
void build(string &s, int start, int end, int node){
    if(start==end){
        tree[node] = (s[start]=='1') ? 1 : 0;
        return;
    }
    int mid = (start+end)/2;
    build(s, start, mid, 2*node);
    build(s, mid+1, end, 2*node+1);
    tree[node] = ((tree[2*node] * power[end-mid])+(tree[2*node+1]))%3;
    return;
}
void update(string &s, int start, int end, int node, int ind){
    if(start==end){
        tree[node] = 1;
        s[start] = '1';
        return;
    }
    int mid = (start+end)/2;
    if(ind<=mid) update(s, start, mid, 2*node, ind);
    else update(s, mid+1, end, 2*node+1, ind);
    tree[node] = (tree[2*node] * power[end-mid] +tree[2*node+1])%3;
    return;
}
int query(int l, int r, int start, int end, int node){
    if(start>r || end<l) return 0;

    if(l<=start && end<=r) return (tree[node]*power[r-end])%3; //right bits
    int mid = (start+end)/2;
    int opt1 = query(l, r, start, mid, 2*node);
    int opt2 = query(l, r, mid+1, end, 2*node+1);
    return ((opt1)+(opt2))%3;
}
int main() {
   
    ios_base::sync_with_stdio(false);
    int n; cin>>n;
    string s; cin>>s;
    power[0]=1;
    for(int i=1;i<=100000;i++){
        power[i] = (power[i-1]==1) ? 2:1;
    }
    build(s, 0, n-1, 1);
    int q; cin>>q;
    while(q--){
        int opt; cin>>opt;
        if(opt==0){
            int l, r; cin>>l>>r;
            if(l==r) cout<<s[l]<<endl;
            else cout<<query(l, r, 0, n-1, 1)<<endl;
        }
        else{
            int ind; cin>>ind;
            if(s[ind]=='0'){
                update(s, 0, n-1, 1, ind);
            }
        }
    }
    return 0;
}
