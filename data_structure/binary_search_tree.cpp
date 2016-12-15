// Binart Search Tree
// Read a txt file from"input.txt",
// and show the result in the cmd
//
// Input:
// 10 5 6 13 4 9 7 1 /*txt*/
// 5 /*command line*/
// Output:
// Preorder: 10 5 4 1 6 9 7 13
// Inorder:  1 4 5 6 7 9 10 13
// Postorder:1 4 7 9 6 5 13 10

// /*after input 5*/
// Preorder: 10 4 1 6 9 7 13
// Inorder:  1 4 6 7 9 10 13
// Postorder:1 7 9 6 4 13 10

// or
// Preorder: 10 6 4 1 9 7 13
// Inorder:  1 4 6 7 9 10 13
// Postorder:1 4 7 9 6 13 10
#include <iostream>
#include <fstream>

using namespace std;

typedef struct Node *tree_pointer;
typedef struct Node
{
    Node* left;
    Node* right;
    int data;
}Node;

void print_preorder(Node *node){
    //走訪順序：中左右
    if(!node){
        return;
    }
    cout << node->data << " ";
    print_preorder(node->left);
    print_preorder(node->right);
}

void print_inorder(Node *node){
    //走訪順序：左中右
    if(!node){
        return;
    }
    print_inorder(node->left);
    cout << node->data << " ";
    print_inorder(node->right);
}

void print_postorder(Node *node){
    //走訪順序左右中
    if(!node){
        return;
    }
    print_postorder(node->left);
    print_postorder(node->right);
    cout<<node->data<<" ";
}



Node* Insert(Node *node, int num){
    if(!node){
        Node *temp;
        temp = (Node *)malloc(sizeof(Node));
        temp->data = num;
        temp->left = temp->right = NULL;
        return temp;
    }
    if(num > (node->data)){
        node->right = Insert(node->right, num);
    }
    else if(num < (node->data)){
        node->left = Insert(node->left, num);
    }
    //if there is empty, then return node directly
    return node;
}
Node* FindMin(Node *node){
    //iterative
    if(!node)
        return NULL;
    if(node->left)
        return FindMin(node->left);
    else return node;
}
Node* Delete(Node *node, int num){
    Node *temp;
    if(!node){
        cout<<"There is no this node"<<endl;
    }
    else if(num < (node->data))
        node->left = Delete(node->left, num);
    else if(num > (node->data))
        node->right = Delete(node->right, num);
    else{
        if(node->right && node->left){
            temp = FindMin(node->right);
            node->data = temp->data;
            node->right = Delete(node->right, temp->data);
        }
        else{
            temp = node;
            if(node->left == NULL)
                node = node->right;
            else if(node->right == NULL)
                node = node->left;
            free(temp);
        }
    }
    return node;
}
int main(int argc, const char * argv[]) {
    ifstream in("input.txt");
    int num=0;
    int delete_data=0;
    Node *root = NULL;
    while(in>>num){
        root = Insert(root, num);
    }
    in.close();

    cout<<"Preorder: "; print_preorder(root);
    cout<<endl<<"Inorder: "; print_inorder(root);
    cout<<endl<<"Postorder: "; print_postorder(root);
    cout<<endl<<"Input the node you want to delete:"<<endl;
    cin>>delete_data;
    root = Delete(root, delete_data);

    cout<<endl<<"Preorder: "; print_preorder(root);
    cout<<endl<<"Inorder: "; print_inorder(root);
    cout<<endl<<"Postorder: "; print_postorder(root);

    return 0;
}
