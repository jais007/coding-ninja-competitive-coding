#include<bits/stdc++.h>
using namespace std;
struct tree{
    int odd, even;
}t[400004];

void build(int *a, int start, int end, int node){
    if(start==end){
        if(a[start]%2==0){
            t[node].odd=0;
            t[node].even=1;
        }
        else{
            t[node].odd=1;
            t[node].even=0;
        }
        return;
    }
    int mid = (start+end)/2;
    build(a, start, mid, 2*node);
    build(a, mid+1, end, 2*node+1);
    t[node].even = t[2*node].even + t[2*node+1].even;
    t[node].odd = t[2*node].odd + t[2*node+1].odd; 
}

void update(int *a, int start, int end, int node, int ind, int val){
    if(start>end) return;
    if(start==end){
        a[start] = val;
        if(a[start]%2==0){
            t[node].odd=0;
            t[node].even=1;
        }
        else{
            t[node].odd=1;
            t[node].even=0;
        }
        return;
    }
    int mid = (start+end)/2;
    if(ind<=mid){
        update(a, start, mid, 2*node, ind, val);
    }
    else{
        update(a, mid+1, end, 2*node+1, ind, val);
    }
    t[node].even = t[2*node].even + t[2*node+1].even;
    t[node].odd = t[2*node].odd + t[2*node+1].odd;
}
tree make(int a, int b){
    tree temp;
    temp.even=a; temp.odd=b;
    return temp;
}
tree query(int *a, int l, int r, int start, int end, int node){
    //NO overlap
    if(start>r || end<l) return make(0,0);
    //complete overlap
    if(start>=l && end<=r) return t[node];
    //partial overlap
    int mid = (start+end)/2;
    tree opt1 = query(a, l, r, start, mid, 2*node);
    tree opt2 = query(a, l, r, mid+1, end, 2*node+1);
    // cout<<opt1.even<<" "<<opt1.odd<<endl;
    // cout<<opt2.even<<" "<<opt2.odd<<endl;
    return make(opt1.even+opt2.even, opt1.odd+opt2.odd);
}

int main(){
    int n; cin>>n;
    int a[n]; 
    for(int i=0;i<n;i++) cin>>a[i];
    build(a, 0, n-1, 1);
    //for(int i=1;i<=14;i++) cout<<t[i].even<<" "<<t[i].odd<<endl;
    int q; cin>>q;
    while(q--){
        int opt; cin>>opt;
        if(opt==0){
            int x, y; cin>>x>>y;
            update(a, 0, n-1, 1, x-1, y);
            }
        else{
            int l, r; cin>>l>>r;
            if(opt==1) cout<<query(a, l-1, r-1, 0, n-1, 1).even<<endl;
            if(opt==2) cout<<query(a, l-1, r-1, 0, n-1, 1).odd<<endl;
        }
    }
    
}
