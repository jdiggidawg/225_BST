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
        Node *left;
        Node *right;
        Node(){};
        Node (Type value): data(value), left(NULL), right(NULL) {};
    };
    
    Node *root;
    void traverse(Node* current, vector<Type> *list);
    void insertPrivate(Node* subTreePtr, Node* newNode);
    
public:
    
    BST();
    BST(vector<Type> list);
    
    bool insert (Type);
    Type* search (Type *target);
    vector<Type> flattenedTree();
};

template <class Type>
BST<Type>:: BST(){
    root = new Node(Type());
}

template <class Type>
BST<Type>:: BST(vector<Type>) {
    root = NULL;
}

template <class Type>
bool BST<Type>::insert (Type newThing) {
    Node *newNode = new Node(newThing);
    //TODO:
    insertPrivate(root, newNode);
    
    return true;
}

template <class Type>
void BST<Type>::insertPrivate(Node* subTreePtr, Node* newNode) {
    Node *current = subTreePtr;
    while (current != NULL) {
        //
    }
    
    /*if(subTreePtr == NULL) {
        return;
    } else if (newNode->data < subTreePtr->data) {
        Node* tempPtr = insertPrivate(subTreePtr->left, newNode);
        subTreePtr->left = tempPtr;
        
    } else if (newNode->data > subTreePtr->data) {
        Node* tempPtr = insertPrivate(subTreePtr->right, newNode);
        subTreePtr->right = tempPtr;
    }*/
}

template <class Type>
Type* BST<Type>::search (Type *target) {
    //TODO:
    return NULL;
}

template <class Type>
vector<Type> BST<Type>::flattenedTree(){
    vector<Type> flatTree = *new vector<Type>;
    traverse(root, &flatTree);
    return flatTree;
}
                  
template <class Type>
void BST<Type>:: traverse(Node* current, vector<Type> *list){
    if(current != NULL) {
        traverse(current->left, list);
        list->push_back(current->data);
        traverse(current->right, list);
    }
}

#endif /* BST_hpp */
