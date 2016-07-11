//
//  BST.hpp
//  EKTApp
//
//  Created by Jessie Tran on 2016-07-10.
//  Copyright © 2016 jdiggidawg. All rights reserved.
//

#ifndef BST_hpp
#define BST_hpp


#include <stdio.h>
#include <iostream>
#include <vector>

using namespace std;

template <class Type>
class BST{

private:
    
    struct node {
        Type data;
        node *left;
        node *right;
        node(){};
        node (Type value): data(value), left(NULL), right(NULL) {};
    };
    
    node root;
    void traverse(node* root);
    void balance();
    
public:
    
    BST();
    BST(vector<Type> list);
    
    bool insert (Type);
    Type* search (Type *target);
    vector<Type> flattenedTree();
};

template <class Type>
BST<Type>:: BST(){
    root = node(Type());
}

template <class Type>
void BST<Type>:: balance(){
    //TODO:
}

template <class Type>
BST<Type>:: BST(vector<Type>) {
    root = NULL;
}

template <class Type>
bool BST<Type>::insert (Type newThing) {
    node newNode = node(newThing);
    //TODO:
    newNode->left = NULL;
    newNode->right = NULL;
    if(root == NULL) {
        root = newNode;
    }
    balance();
    return true;
}

template <class Type>
Type* BST<Type>::search (Type *target) {
    //TODO:
    return NULL;
}

template <class Type>
vector<Type> flattenedTree(){
    vector<Type> flatTree;
    //TODO: traverse...
    return flatTree;
}
                  
template <class Type>
void BST<Type>:: traverse(node* root){
    if(root != NULL) {
        Inorder(root->Left());
        cout << root->Key() << endl;
        Inorder(root->Right());
        
    }
}

#endif /* BST_hpp */
