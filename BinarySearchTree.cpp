#include<iostream>
#include<map>
#include<vector>
using namespace std;
struct Node{
    int data;
    Node* right, *left;
    Node(int val){
        data = val;
        left=NULL;
        right=NULL;
    }
};

Node* insertBST(Node* root,int val){
    if(root==NULL){
        return new Node(val);
    }
    if(val<root->data){
        root->left = insertBST(root->left,val);
    }else{
        root->right = insertBST(root->right,val);
    }
    return root;
}
void inOrder(Node* root){
    if(root==NULL) return;
    inOrder(root->left);
    cout<<root->data<<" ";
    inOrder(root->right);
}
bool searchBST(Node* root, int key){
    if(root==NULL) return -1;
    if(root->data ==key) return true;
    if(key<root->data){
        searchBST(root->left,key);
    }else{
        searchBST(root->right,key);
    }

    return -1;
}

Node* inOrderSucc(Node* root){
    Node* curr = root;
    while (curr && curr->left != NULL)
    {
        curr = curr->left;
    }return curr;
    
}

////////vertical order

Node* deleteBST(Node* root, int key){
    
    if(key<root->data){
        root->left = deleteBST(root->left,key);
    }
    else if(key>root->data){
        root->right = deleteBST(root->right,key);
    }else{
        if(root->left == NULL){
            Node* temp = root->right;
            free(root);
            return temp;
        }
        if(root->right == NULL){
            Node* temp = root->left;
            free(root);
            return temp;
        }

        Node* temp = inOrderSucc(root->right);
        root->data = temp->data;
        root->right = deleteBST(root->right,temp->data); 
    }return root;
}


bool isBST(Node* root,Node* min=NULL,Node* max=NULL){
    if(root==NULL) return true;
    if(min!=NULL && root->data <= min->data) return false;
    if(max!=NULL && root->data >= max->data) return false;
    
    bool leftValid= isBST(root->left,min,root);
    bool rightValid= isBST(root->right,root,max);
    return leftValid && rightValid;
}

///////////////////////////Balanced BST from Sorted Array
Node* buildBalancedBST(int arr[],int start,int end){
    if(start>end) return NULL;
    int mid = (start+end)/2;
    Node* root=new Node(arr[mid]);
    root->left = buildBalancedBST(arr, start,mid-1);
    root->right = buildBalancedBST(arr, mid+1, end);
    return root;

}

////////////Identical BST???
bool isIdenticalBST(Node* root1,Node* root2){
    if((root1==NULL)&&(root2==NULL)) return true;
    else if(root2==NULL || root1==NULL) return false;
    else{
        bool cond1=root1->data==root2->data;
        bool cond2=isIdenticalBST(root1->left,root2->left);
        bool cond3=isIdenticalBST(root1->right,root2->right);

        if(cond1 && cond2 && cond3) return true;
        else return false;
    }
}

////////vertical order
void getVerticalOrder(Node* root,int hd, map<int, vector<int>> &m){
    if(root==NULL) return;
    m[hd].push_back(root->data);
    getVerticalOrder(root->left,hd-1,m);
    getVerticalOrder(root->right,hd+1,m);
}
void verticalOrder(Node* root){
    map<int, vector<int>> m;
    int hd=0;
    getVerticalOrder(root,hd,m);
    map<int, vector<int>> :: iterator it;
    for(it=m.begin(); it!=m.end(); ++it){
        for(int i=0; i<it->second.size(); ++i){
            cout<<it->second[i]<<" ";
        }cout<<endl;
    }

   
}

int main(){
    Node* root=NULL;
    root = insertBST(root,5);
    insertBST(root,1);
    insertBST(root,3);
    insertBST(root,4);
    insertBST(root,2);
    insertBST(root,7);

    
    //if(isBST(root,NULL,NULL)) cout<<" Trre"<<" ";
    
    // int arr[]={10,20,30,40,50,60};
    // Node* root1=buildBalancedBST(arr,0,5);

    // root = deleteBST(root,4);
    //inOrder(root1);
    // cout<<"\n"<<searchBST(root,8)<<endl;
    //Vertical order
    verticalOrder(root);
    return 0; 
}