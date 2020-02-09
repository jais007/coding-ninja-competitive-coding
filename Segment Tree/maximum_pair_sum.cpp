#include<bits/stdc++.h>
using namespace std;
struct Node{
    int mx;
    int smx;
};
void buildTree(int *arr,Node *tree,int start,int end,int tNode){
    if(start==end){
        tree[tNode].mx=arr[start];
        tree[tNode].smx=-1;
        return;
    }
    int mid=(start+end)/2;
    buildTree(arr,tree,start,mid,2*tNode);
    buildTree(arr,tree,mid+1,end,2*tNode+1);
    Node left=tree[2*tNode];
    Node right=tree[2*tNode+1];
    tree[tNode].mx=max(left.mx,right.mx);
    tree[tNode].smx=min(max(left.mx,right.smx),max(left.smx,right.mx));
    return;
}
int query(Node *tree,int start,int end,int tNode,int left,int right){
    
}
int main(){
    int n;
    cin>>n;
    int *arr=new int[n];
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }
    Node *tree=new Node[3*n];
    buildTree(arr,tree,0,n-1,1);
    int k;
    cin>>k;
    while(k--){
        char type;
        cin>>type;
        if(type=='Q'){
            int l,r;
            cin>>l>>r;
            query(tree,0,n-1,1,l-1,r-1);
        }
        else{
            int ind,val;
            cin>>ind>>val;
            update(arr,tree,0,n-1,1,ind,val);
        }
    }
    for(int i=0;i<3*n;i++){  
	cout<<tree[i].mx<<" , "<<tree[i].smx<<endl;
   }
}
