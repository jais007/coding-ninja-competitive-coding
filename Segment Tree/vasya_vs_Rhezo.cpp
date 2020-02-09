#include<bits/stdc++.h>
using namespace std;
struct tree{
    int a, b, ind;
}t[400004];

void build(int *x, int *y, int start, int end, int node){
    if(start==end){
        t[node].a = x[start];
        t[node].b = y[start];
        t[node].ind = start;
        return;
    }
    int mid = (start+end)/2;
    build(x, y, start, mid, 2*node);
    build(x, y, mid+1, end, 2*node+1);
    if(t[2*node].a > t[2*node+1].a){
        t[node].a = t[2*node].a;
        t[node].b = t[2*node].b;
        t[node].ind = t[2*node].ind;
    }
    else if(t[2*node].a < t[2*node+1].a){
        t[node].a = t[2*node+1].a;
        t[node].b = t[2*node+1].b;
        t[node].ind = t[2*node+1].ind;
    }
    else if(t[2*node].b < t[2*node+1].b){
        t[node].a = t[2*node].a;
        t[node].b = t[2*node].b;
        t[node].ind = t[2*node].ind;
    }
    else if(t[2*node].b > t[2*node+1].b){
        t[node].a = t[2*node+1].a;
        t[node].b = t[2*node+1].b;
        t[node].ind = t[2*node+1].ind;
    }
    else{
        t[node].a = t[2*node].a;
        t[node].b = t[2*node].b;
        t[node].ind = t[2*node].ind;
    }
    return;
}
tree make(int x, int y, int z){
    tree temp;
    temp.a = x;
    temp.b = y;
    temp.ind = z;
    return temp;
}
tree query(int l, int r, int start, int end, int node){
    //No overlap
    if(start>r || end<l) return make(-1, -1, 0);
    //Complete overlap
    if(l<=start && end<=r) return t[node];
    //partial overlap
    int mid = (start+end)/2;
    tree opt1 = query(l, r, start, mid, 2*node);
    tree opt2 = query(l, r, mid+1, end, 2*node+1);
    tree temp;
    if(opt1.a > opt2.a){
        temp.a = opt1.a;
        temp.b = opt1.b;
        temp.ind = opt1.ind;
    }
    else if(opt1.a < opt2.a){
        temp.a = opt2.a;
        temp.b = opt2.b;
        temp.ind = opt2.ind;
    }
    else if(opt1.b < opt2.b){
        temp.a = opt1.a;
        temp.b = opt1.b;
        temp.ind = opt1.ind;
    }
    else if(opt1.b > opt2.b){
        temp.a = opt2.a;
        temp.b = opt2.b;
        temp.ind = opt2.ind;
    }
    else{
        temp.a = opt1.a;
        temp.b = opt1.b;
        temp.ind = opt1.ind;
    }
    return temp;
}
int main() {
    int n; cin>>n;
    int a[n], b[n];
    for(int i=0;i<n;i++) cin>>a[i];
    for(int i=0;i<n;i++) cin>>b[i];
    build(a, b, 0, n-1, 1);
    //for(int i=1;i<=16;i++) cout<<t[i].a<<" "<<t[i].b<<" "<<t[i].ind<<endl;
    int q; cin>>q;
    while(q--){
        int l, r; cin>>l>>r;
        cout<<query(l-1, r-1, 0, n-1, 1).ind+1<<endl;
    }
}
