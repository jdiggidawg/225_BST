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
        node* left;
        node* right;
        node(){};
        node (Type value): data(value), left(NULL), right(NULL) {};
    };
    
    node* root;
    bool insertPrivate(Type newThing,node* ptr);
    void traverse(node* root, vector<Type> *list);
    void balance();
    
public:
    
    BST();
    BST(vector<Type> list);
    
    bool insert (Type);
    Type* search (Type *target);
    vector<Type> flattenedTree();
};

//PRIVATE METHODS IMPLEMENTATION--------------------------------------------------------------------------------
template <class Type>
void BST<Type>:: traverse(node* current, vector<Type> *list){
    if(current != NULL) {
        traverse(current->left, list);
        
        list->push_back(current->data);
        traverse(current->right, list);
        
    }
}

template <class Type>
void BST<Type>:: balance(){
    //TODO:
}

//TODO:
template <class Type>
bool BST<Type>::insertPrivate(Type newThing,node *ptr) {
    node newNode = new node(newThing);
    if(root == NULL) {
        root = &newNode;
    } else if (newNode.data < ptr->data) {
        if (ptr->left != NULL) {
            insertPrivate(snewNode.data, ptr->left);
        } else {
            ptr->left = &newNode;
        }
        
    } else if (newNode.data < ptr->data) {
        if (ptr->right != NULL) {
            insertPrivate(newNode.data, ptr->right);
        } else {
            ptr->right = &newNode;
        }
    }
    return true;
}



//PUBLIC METHODS IMPLEMENTATION---------------------------------------------------------------------------------

//Contructors
template <class Type>
BST<Type>:: BST(){
    root = NULL;
}


template <class Type>
BST<Type>:: BST(vector<Type>) {
    root = NULL;
}

//Insertion
template <class Type>
bool BST<Type>::insert(Type newThing) {
    insertPrivate(newThing, root);
    return true;
}


//Search
template <class Type>
Type* BST<Type>::search (Type *target) {
    //TODO:
    return NULL;
}

//Convert to vector
template <class Type>
vector<Type> BST<Type>::flattenedTree(){
    vector<Type> *flatTree = new vector<Type>();
    traverse(root, flatTree);
    //TODO: traverse...
    return *flatTree;
}
        

#endif /* BST_hpp */
