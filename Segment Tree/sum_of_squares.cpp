#include<bits/stdc++.h>
using namespace std;
int tree[400004];
void build(int *a, int start, int end, int node){
    if(start==end){
        tree[node] = a[start]*a[start];
        return;
    }
    int mid = (start+end)/2;
    build(a, start, mid, 2*node);
    build(a, mid+1, end, 2*node+1);
    tree[node] = tree[2*node] + tree[2*node+1];
}

void update1(int *a, int l, int r, int start, int end, int node, int val){
    if(start>end) return;
    
    //No Overlap
    if(start>r || end<l) return;
    //Complete overlap
    if(start==end){
        a[start]+=val;
        tree[node] = a[start]*a[start];
        return;
    }
    //Partial Overlap
    int mid = (start+end)/2;
    update1(a, l, r, start, mid, 2*node, val);
    update1(a, l, r, mid+1, end, 2*node+1, val);
    tree[node] = tree[2*node]+tree[2*node+1];
}

void update0(int *a, int l, int r, int start, int end, int node, int val){
    if(start>end) return;
    
    //No Overlap
    if(start>r || end<l) return;
    //Complete overlap
    if(start==end){
        a[start]=val;
        tree[node] = a[start]*a[start];
        return;
    }
    //Partial Overlap
    int mid = (start+end)/2;
    update0(a, l, r, start, mid, 2*node, val);
    update0(a, l, r, mid+1, end, 2*node+1, val);
    tree[node] = tree[2*node]+tree[2*node+1];
}

int query(int l, int r, int start, int end, int node){
    if(start>r ||end<l) return 0;
    if(start>=l && end<=r){
        return tree[node];
    }
    int mid = (start+end)/2;
    int opt1 = query(l, r, start, mid, 2*node);
    int opt2 = query(l, r, mid+1, end, 2*node+1);
    return opt1+opt2;
}

int main() {
    int te; cin>>te;
    int c=1;
    while(te--){
        cout<<"Case "<<c++<<':'<<endl;
        int n, q; cin>>n>>q;
        int *a = new int[n];
        for(int i=0;i<=400000;i++) tree[i]=0;
        for(int i=0;i<n;i++) cin>>a[i];
        build(a, 0, n-1, 1);
        while(q--){
            int opt; cin>>opt;
            if(opt==2){
                int l, r; cin>>l>>r;
                cout<<query(l-1, r-1, 0, n-1, 1)<<endl;
            }
            else if(opt==1){
                int l, r, val; cin>>l>>r>>val;
                update1(a, l-1, r-1, 0, n-1, 1, val);
            }
            else{

                int l, r, val; cin>>l>>r>>val;
                update0(a, l-1, r-1, 0, n-1, 1, val);
                //for(int i=1;i<=11;i++) cout<<t[i].sq<<" "<<t[i].sum<<endl;
            }
        }
    }
}
