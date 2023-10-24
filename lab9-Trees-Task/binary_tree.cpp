#include<iostream>
#include<string>

using namespace std;

struct Trunk
{
    Trunk *prev;
    string str;

    Trunk(Trunk *prev, string str)
    {
        this->prev = prev;
        this->str = str;
    }
};

// Helper function to print branches of the binary tree
void showTrunks(Trunk *p)
{
    if (p == NULL)
        return;

    showTrunks(p->prev);

    cout << p->str;
}

class node
{
    public:
        int info;
        node *left;
        node *right;
        
    node(int val)
    {
        info = val;
        left = NULL;
        right = NULL;
    }
};

node* parent(node* curr, node* p, node* par)
{
    if(curr == NULL)
        return NULL;

    if (curr == p)
    {
        return par;
    }
    else
    {
        node *t = NULL;
        t = parent(curr->left, p, curr);
        if(t!= NULL)
            return t;
        else
        {
            t = parent(curr->right, p, curr);
            return t;
        }

    }
}

node* sibling(node* root, node* p)
{
    node* par = parent(root, p, root);

    if (par->left == p)
        return par->right;
    else 
        return par->left;
}

void deleteTree(node* leaf)
{
    if (leaf != NULL)
    {
        deleteTree(leaf->left);
        deleteTree(leaf->right);
        delete leaf;
    }
}
//14, 15, 4, 9, 7, 18, 3, 5, 16, 4, 20, 17, 9, 14, 5
void checkDuplicates(node** n, int val)
{
    if(*n == NULL)
    {
        *n = new node(val);
        return;
    }
    

    if(val > (*n)->info)
    {
        if ((*n)->right != NULL)
            checkDuplicates(&(*n)->right, val);
        else
        {
            (*n)->right = new node(val);
            return;
        }
        
    }
    else if(val < (*n)->info)
    {
        if((*n)->left != NULL)
            checkDuplicates(&(*n)->left, val);
        else
        {
            (*n)->left = new node(val);
            return;
        }
    }
    else if(val == (*n)->info)
        cout<<val<<" is repeated..."<<endl;
}
// int checklevel(node *ptr,node* val,int level)
int checklevel(node *ptr, node* n,int level) 
{
    if (ptr == NULL)
        return 0;
    if (ptr == n)
        return level;

    int l = checklevel(ptr->left, n, level+1); 
    int r = checklevel(ptr->right, n, level+1);

    if(l == 0)
        return r;
    else if(r == 0)
        return l;
    else
        return 0;
    // return l | r;
    // return getLevel(ptr->left, val, level+1) | 
            // checklevel(ptr->right, val, level+1);
}

int maxDepth(node* n)  
{  
    if (n == NULL)  
        return -1;  
    else
    {  
        /* compute the depth of each subtree */
        int lDepth = maxDepth(n->left);  
        int rDepth = maxDepth(n->right);  
      
        /* use the larger one */
        if (lDepth > rDepth)  
            return(lDepth + 1);  
        else return(rDepth + 1);  
    }  
}

void preOrder(node *n)
{
    if(n == NULL)
        return;
    
    cout<<n->info<<"\t";
    preOrder(n->left);
    preOrder(n->right);
}

void inOrder(node *n)
{
    if(n == NULL)
        return;

    inOrder(n->left);
    cout<<n->info<<"\t";
    inOrder(n->right);
}

void postOrder(node *n)
{
    if(n == NULL)
        return;
    
    postOrder(n->left);
    postOrder(n->right);
    cout<<n->info<<"\t";
}

// Recursive function to print binary tree
// It uses inorder traversal
void printTree(node *root, Trunk *prev, bool isRight)
{
    if (root == NULL)
        return;
    
    string prev_str = "    ";
    Trunk *trunk = new Trunk(prev, prev_str);

    printTree(root->right, trunk, true);

    if (!prev)
        trunk->str = "---";
    else if (isRight)
    {
        trunk->str = ".---";
        prev_str = "   |";
    }
    else
    {
        trunk->str = "`---";
        prev->str = prev_str;
    }

    showTrunks(trunk);
    cout << root->info << endl;

    if (prev)
        prev->str = prev_str;
    trunk->str = "   |";

    printTree(root->left, trunk, false);
}

int main(int argc, const char** argv) {
    node *root = new node(5);
    root->left = new node(2);
    root->right = new node(7);
    root->right->left = new node(3);
    root->right->right = new node(9);
    root->left->left = new node(6);
    root->left->left->right = new node(1);

    printTree(root, NULL, false);
    
    // Find Parent
    node *n = parent(root, root->right, root);
    cout<<"Parent is: "<<n->info<<endl;

    // Find sibling
    node *sib = sibling(root, root->right->left); //sibling of 3 (which is 9)
    cout<<"Sibling of 3 is: "<<sib->info<<endl;

    // Level of a node
    cout<<"Level of 1: "<<checklevel(root, root->left->left->right, 0)<<endl;

    // Depth of the tree
    cout<<"Depth of the tree: "<<maxDepth(root)<<endl;
    deleteTree(root);

    // Find Duplicates [Start]
    node *r = NULL;
    int arr[] = {14, 15, 4, 9, 7, 18, 3, 5, 16, 4, 20, 17, 9, 14, 5};
    int sz = sizeof(arr)/sizeof(int);
    
    for (int i = 0; i < sz; i++)
        checkDuplicates(&r, arr[i]);
    
    deleteTree(r);
    // Find Duplicates [End]

    // Tree Traversals (PreOrder, InOrder, PostOrder) [Start]
    node *order = NULL;
    order = new node(1);
    order->left = new node(2);
    order->right = new node(3);
    order->left->left = new node(4);
    //printTree(root, NULL, false);
    preOrder(order);
    cout<<endl;
    inOrder(order);
    cout<<endl;
    postOrder(order);
    // Tree Traversals (PreOrder, InOrder, PostOrder) [End]
    return 0;
}