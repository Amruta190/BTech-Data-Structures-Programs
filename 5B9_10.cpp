//Binary Search Tree
#include<iostream>
using namespace std;
class Node
{
    public:
    int key;
    Node *left,*right;
};
class BinarySearchTree
{
    public:
    Node *root=NULL;
    Node* insert(Node*, Node*);
    void inorder(Node*);
    void preorder(Node*);
    void postorder(Node*);
    Node* deletenode(Node*,int);
    Node* deletekey(Node*);
    int maxval(Node*);
    int minval(Node*);
    void searchnode(Node*,int);
};
Node* BinarySearchTree :: insert(Node *root, Node *tmp)
{
    if(root==NULL)
        root=tmp;
    else
    {
        if(root->key>tmp->key)
            root->left=insert(root->left,tmp);
        if(root->key<tmp->key)
            root->right=insert(root->right,tmp);
    }
    return root;
}
void BinarySearchTree :: inorder(Node* root)
{
    if(root!=NULL)
    {
        inorder(root->left);
        cout<<root->key<<" ";
        inorder(root->right);
    }
}
void BinarySearchTree :: preorder(Node* root)
{
    if(root!=NULL)
    {
        cout<<root->key<<" ";
        preorder(root->left);
        preorder(root->right);
    }
}
void BinarySearchTree :: postorder(Node* root)
{
    if(root!=NULL)
    {
        postorder(root->left);
        postorder(root->right);
        cout<<root->key<<" ";
    }
}
Node* BinarySearchTree :: deletenode(Node *root,int k)
{
    if(root->key>k)
        root->left=deletenode(root->left,k);
    else if(root->key<k)
        root->right=deletenode(root->right,k);
    else
        root=deletekey(root);
    return root;
}
Node* BinarySearchTree :: deletekey(Node *tmp)
{
    if(tmp->left==NULL&&tmp->right==NULL)
        return NULL;
    else if(tmp->left==NULL||tmp->right==NULL)
    {
        if(tmp->left==NULL)
            return tmp->right;
        else
            return tmp->left;
    }
    else
    {
        int k1=maxval(tmp->left);
        // int k1=minval(tmp->right);
        tmp->key=k1;
        tmp->left=deletenode(tmp->left,k1);
    }
}
int BinarySearchTree :: maxval(Node *tmp)
{
    while(tmp->right!=NULL)
        tmp=tmp->right;
    return tmp->key;
}
int BinarySearchTree :: minval(Node *tmp)
{
    while(tmp->left!=NULL)
        tmp=tmp->left;
    return tmp->key;
}
void BinarySearchTree :: searchnode(Node *root,int k)
{
    Node *tmp=root;
    while(tmp!=NULL)
    {
        if(tmp->key==k)
        {
            cout<<"\nElement "<<k<<" found\n";
            return;
        }
        else if(tmp->key<k)
            tmp=tmp->right;
        else if(tmp->key>k) 
            tmp=tmp->left;
    }
    cout<<"\nElement not found\n";
    return;
}
int main()
{
    int n,n1,deletekey,searchkey;
    Node *tmp=NULL;
    BinarySearchTree bst;
    while(true)
    {
        cout<<"\nSelect an option :\n1. Insert\n2. Delete\n3. Search\n4. Print\n5. Exit\n";
        cin>>n;
        switch(n)
        {
            case 1:
            {       
                cout<<"Enter the key value : ";
                tmp=new Node();
                tmp->left=NULL;
                tmp->right=NULL;
                cin>>tmp->key;
                bst.root=bst.insert(bst.root,tmp);
                break;
            }
            case 2:
            {
                cout<<"Enter the key value to be deleted : ";
                cin>>deletekey;
                bst.root=bst.deletenode(bst.root,deletekey);
                break;
            }
            case 3:
            {
                cout<<"Enter the key value to be searched : ";
                cin>>searchkey;
                bst.searchnode(bst.root,searchkey);
                break;
            }
            case 4:
            {
                cout<<"Select the option to print in :\n1. Inorder\t2. Preorder\t3. Postorder\n";
                cin>>n1;
                switch(n1)
                {
                    case 1:bst.inorder(bst.root);
                            break;
                    case 2:bst.preorder(bst.root);
                            break;
                    case 3:bst.postorder(bst.root);
                            break;
                    default : cout<<"Invalid Option\n";
                }
                break;
            }
            case 5:exit(0);
        }
    }
}