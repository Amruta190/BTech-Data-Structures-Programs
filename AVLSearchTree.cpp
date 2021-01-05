#include<iostream>
using namespace std;
class Node
{
    public:
    int key;
    Node *left,*right;
    int ht;
};
class AVLSearchTree
{
    public:
    Node *root=NULL;
    Node* insertnode(Node*, Node*);
    int height(Node*);
    int bf(Node*);
    Node* rightrotate(Node*);
    Node* leftrotate(Node*);
    Node* LL(Node*);
    Node* RR(Node*);
    Node* LR(Node*);
    Node* RL(Node*);
    Node* deletenode(Node*,int);
    void inorder(Node*);
    void preorder(Node*);
    void postorder(Node*);
};
int AVLSearchTree :: height(Node *tmp)
{
    int hl,hr;
    if(tmp->left==NULL)
        hl=0;
    else
        hl=1+tmp->left->ht;
    if(tmp->right==NULL)
        hr=0;
    else
        hr=1+tmp->right->ht;
    if(hl>hr)
        return hl;
    else
        return hr;
}
int AVLSearchTree :: bf(Node *tmp)
{
    int hl,hr;
    if(tmp->left==NULL)
        hl=0;
    else
        hl=1+tmp->left->ht;
    if(tmp->right==NULL)
        hr=0;
    else
        hr=1+tmp->right->ht;
    return (hl-hr);
}
Node* AVLSearchTree :: insertnode(Node *root, Node *tmp)
{
    if(root==NULL)
        root=tmp;
    else if(root->key>tmp->key)
    {
        root->left=insertnode(root->left,tmp);
        if(bf(root)==2)
        {
            if(root->left->key>tmp->key)
                root=LL(root);
            else
                root=LR(root);
        }
    }
    else if(root->key<tmp->key)
    {
        root->right=insertnode(root->right,tmp);
        if(bf(root)==-2)
        {
            if(root->right->key<tmp->key)
                root=RR(root);
            else
                root=RL(root);
        }
    }
    root->ht=height(root);
    return root;
}
Node* AVLSearchTree :: rightrotate(Node *tmp)
{
    Node *a=tmp->left;
    tmp->left=a->right;
    a->right=tmp;
    tmp->ht=height(tmp);
    a->ht=height(a);
    return a;
}
Node* AVLSearchTree :: leftrotate(Node *tmp)
{
    Node *a=tmp->right;
    tmp->right=a->left;
    a->left=tmp;
    tmp->ht=height(tmp);
    a->ht=height(a);
    return a;
}
Node* AVLSearchTree :: LL(Node *tmp)
{
    tmp=rightrotate(tmp);
    return tmp;
}
Node* AVLSearchTree :: RR(Node *tmp)
{
    tmp=leftrotate(tmp);
    return tmp;
}
Node* AVLSearchTree :: LR(Node *tmp)
{
    tmp->left=leftrotate(tmp->left);
    tmp=rightrotate(tmp);
    return tmp;
}
Node* AVLSearchTree :: RL(Node *tmp)
{
    tmp->right=rightrotate(tmp->right);
    tmp=leftrotate(tmp);
    return tmp;
}
Node* AVLSearchTree :: deletenode(Node* root, int k)
{
    Node *p=NULL;
    if(root==NULL)
        return NULL;
    else if(root->key>k)
    {
        root->left=deletenode(root->left,k);
        if(bf(root)==-2)
        {
            if(bf(root->right)<=0)
                root=RR(p);
            else 
                root=RL(p);
        }
    }
    else if(root->key<k)
    {
        root->right=deletenode(root->right,k);
        if(bf(root)==2)
        {
            if(bf(root->left)>=0)
                root=LL(root);
            else 
                root=LR(root);
        }
    }
    else
    {
        if(root->left!=NULL)
        {
            p=root->left;
            while(p->right!=NULL)
                p=p->right;
            root->key=p->key;
            root->left=deletenode(root->left,p->key);
            if(bf(root)==-2)
            {
                if(bf(root->right)<=0)
                    root=RR(p);
                else 
                    root=RL(p);
            }
        }
        else
        {
            return root->right;
        }
    }
    root->ht=height(root);
    return root;
}
void AVLSearchTree :: inorder(Node* root)
{
    if(root!=NULL)
    {
        inorder(root->left);
        cout<<root->key<<" ";
        inorder(root->right);
    }
}
void AVLSearchTree :: preorder(Node* root)
{
    if(root!=NULL)
    {
        cout<<root->key<<" ";
        preorder(root->left);
        preorder(root->right);
    }
}
void AVLSearchTree :: postorder(Node* root)
{
    if(root!=NULL)
    {
        postorder(root->left);
        postorder(root->right);
        cout<<root->key<<" ";
    }
}
int main()
{
    int n,n1,deletekey;
    Node *tmp=NULL;
    AVLSearchTree AVL;
    while(true)
    {
        cout<<"\nSelect an option :\n1. Insert\n2. Delete\n3. Print\n4. Exit\n";
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
                AVL.root=AVL.insertnode(AVL.root,tmp);
                break;
            }
            case 2:
            {
                cout<<"Enter the key value to be deleted : ";
                cin>>deletekey;
                AVL.root=AVL.deletenode(AVL.root,deletekey);
                break;
            }
            case 3:
            {
                cout<<"Select the option to print in :\n1. Inorder\t2. Preorder\t3. Postorder\n";
                cin>>n1;
                switch(n1)
                {
                    case 1:AVL.inorder(AVL.root);
                            break;
                    case 2:AVL.preorder(AVL.root);
                            break;
                    case 3:AVL.postorder(AVL.root);
                            break;
                    default : cout<<"Invalid Option\n";
                }
                break;
            }
            case 4:exit(0);
        }
    }
}