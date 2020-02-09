#include<bits/stdc++.h>
using namespace std;
struct tree{
    int sum, pre, suf, res;
};

tree t[400004];

tree make_data(int val){
    tree temp;
    temp.sum = val;
    temp.pre = temp.suf = temp.res = val;
    return temp;
}

tree combine(tree l, tree r){
    tree temp;
    temp.sum = l.sum+r.sum;
    temp.pre = max(l.pre, l.sum+r.pre);
    temp.suf = max(r.suf, l.suf+r.sum);
    temp.res = max(max(l.res, r.res), l.suf+r.pre);
    return temp;
}

void build(int* a, int l, int r, int node){
    if(l==r) {
        t[node] = make_data(a[l]);
        return;
    }
    int mid = (l+r)/2;
    build(a, l, mid, 2*node);
    build(a, mid+1, r, 2*node+1);
    t[node] = combine(t[2*node], t[2*node+1]);
    return;
}

tree query(int l, int r, int start, int end, int node){
    if(start>r || end<l) return make_data(-10000);
    if(start>=l && end<=r) return t[node];
    int mid = (start+end)/2;
    tree opt1 = query(l, r, start, mid, 2*node);
    tree opt2 = query(l, r, mid+1, end, 2*node+1);
    return combine(opt1, opt2);
}

int main() {
    int n; cin>>n;
    int a[n]; 
    for(int i=0;i<n;i++) cin>>a[i];
    build(a, 0, n-1, 1);
    //for(int i=1;i<20;i++) cout<<t[i].sum<<" "<<t[i].pre<<" "<<t[i].suf<<" "<<t[i].res<<endl;
    int q; cin>>q;
    while(q--){
        int l, r; cin>>l>>r;
        tree temp;
        temp=query(l-1, r-1, 0, n-1, 1);
        cout<<temp.res<<endl;
    }
}
