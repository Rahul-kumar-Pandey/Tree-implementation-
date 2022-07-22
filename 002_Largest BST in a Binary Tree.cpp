class info{
  public:
    int maxi;
    int mini;
    bool isBST;
    int size;
};
info solve(TreeNode<int>*root,int &ans){
    //base case
    if(root==NULL) return {INT_MIN,INT_MAX,true,0};
    
    info left=solve(root->left,ans);
    info right=solve(root->right,ans);
    
    info currNode;
    currNode.maxi=max(root->data,right.maxi);
    currNode.mini=min(root->data,left.mini);
    currNode.size=left.size + right.size + 1;
    if(left.isBST and right.isBST and (left.maxi < root->data and root->data < right.mini)){
        currNode.isBST=true;
    }
    else currNode.isBST=false;
    //update answer
    if(currNode.isBST) ans=max(ans,currNode.size);
    
    return currNode;
}
int largestBST(TreeNode<int>* root) 
{
    // Write your code here.
    int maxsize=0;
    info temp=solve(root,maxsize);
    return maxsize;
}
