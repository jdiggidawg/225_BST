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
    
    struct Node {
        Type data;
        Node* left;
        Node* right;
        Node(){};
        Node (Type value): data(value), left(NULL), right(NULL) {};
    };
    
    Node* root;
    Node* insertPrivate(Node* subTreePtr, Node* newNode);
    void traverse(Node* root, vector<Type> *list);
    
public:
    
    
    BST();
    BST(vector<Type> list);
    
    bool insert (Type newData);
    Node* findNode(Node* subTreePtr. Type target);
    vector<Type> flattenedTree();
};

//PRIVATE METHODS IMPLEMENTATION--------------------------------------------------------------------------------

template <class Type>
void BST<Type>:: traverse(Node* current, vector<Type> *list){
    if(current != NULL) {
        traverse(current->left, list);
        
        list->push_back(current->data);
        traverse(current->right, list);
        
    }
}


//TODO: FIX UNKNOWN RETURN TYPE NAME NODE*
template <class Type>
Node* BST<Type>::insertPrivate(Node* subTreePtr, Node* newNode){
    if(subTreePtr == NULL) {
        return newNode;
    } else if (newNode->data < subTreePtr->data) {
        Node* tempPtr = insertPrivate(subTreePtr->left, newNode);
        subTreePtr->left = tempPtr;
        
    } else if (newNode->data > subTreePtr->data) {
        Node* tempPtr = insertPrivate(subTreePtr->right, newNode);
        subTreePtr->right = tempPtr;
    }
}



//PUBLIC METHODS IMPLEMENTATION--------------------------------------------------------------------------------

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
bool BST<Type>::insert(Type newData) {
    Node* newNode = new Node*(newData);
    root = insertPrivate(root,newNode);
    return true;
}

//TODO: FIX UNKNOWN RETURN TYPE NAME NODE*
//Search
template <class Type>
Node* BST<Type>::findNode(Node* subTreePtr, Type target); {
    if (subTreePtr == NULL) {
        return NULL;
    } else if (subTreePtr->data == target) {
        return subTreePtr;
    } else if (subTreePtr->data > target) {
        return findNode(subTreePtr->left, target);
    } else {
        return findNode(subTreePtr->rigt,target);
    }
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
