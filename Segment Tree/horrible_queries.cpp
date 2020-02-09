#include<bits/stdc++.h>
using namespace std;
#define ll long long
ll lazy[400004], tree[400004], a[100001];
void build(ll start, ll end, ll node){
    if(start==end){
        tree[start]=0;
        return;
    }
    ll mid = (start+end)/2;
    build(start, mid, 2*node);
    build(mid+1, end, 2*node+1);
    tree[node] = tree[2*node] + tree[2*node+1];
}
void update(ll l, ll r, ll start, ll end, ll node, ll val){
    if(lazy[node]!=0){
        tree[node] += (end-start+1)*lazy[node];
        if(start!=end){
            lazy[2*node] += lazy[node];
            lazy[2*node+1] += lazy[node];
        }
        lazy[node] = 0;
    }
    if(start>r || end<l) return;
    if(l<=start && end<=r){
        tree[node] += (end-start+1)*val;
        if(start!=end){
            lazy[2*node] += val;
            lazy[2*node+1] += val;
        }
        return;
    }
    ll mid = (start+end)/2;
    update(l, r, start, mid, 2*node, val);
    update(l, r, mid+1, end, 2*node+1, val);
    tree[node] = tree[2*node] + tree[2*node+1];
    return;
}

ll query(ll l, ll r, ll start, ll end, ll node){
    if(lazy[node]!=0){
        tree[node] += (end-start+1)*lazy[node];
        if(start!=end){
            lazy[2*node] += lazy[node];
            lazy[2*node+1] += lazy[node];
        }
        lazy[node] = 0;
    }
    if(start>r || end<l) return 0;
    if(l<=start && end<=r) return tree[node];
    ll mid = (start+end)/2;
    return query(l, r, start, mid, 2*node) + query(l, r, mid+1, end, 2*node+1);
}

int main() {
    ll t; cin>>t;
    while(t--){
        memset(tree,0,sizeof(tree));
        memset(lazy,0,sizeof(lazy));
        ll n, q; cin>>n>>q;
        build(0, n-1, 1);
        while(q--){
            ll type; cin>>type;
            if(type==0){
                ll l, r, val; cin>>l>>r>>val;
                update(l-1, r-1, 0, n-1, 1, val);
            }
            else{
                ll l, r; cin>>l>>r;
                //cout<<"harsh";
                cout<<query(l-1, r-1, 0, n-1, 1)<<endl;
            }
        }
    }
}
