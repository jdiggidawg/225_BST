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
public:
    
    BST();
    BST(vector<Type> list);
    
    bool insert (Type);
    Type* search (Type* target);
    vector<Type> flattenedTree();
};

template <class Type>
BST<Type>:: BST(){
    root = NULL;
}

template <class Type>
BST<Type>:: BST(vector<Type>) {
    root = NULL;
}

template <class Type>
bool BST<Type>::insert (Type newThing) {
    Node *newNode = new Node(newThing);
    Node *parent = root;
    Node *current = NULL;

    
    if (root == NULL){
        //there's no node.
        root = newNode;
    } else {
        //go down the tree until a space is available
        current = root;
        while (current != NULL){
            parent = current;
            if (newThing < current->data){
                current = current->left;
            } else if (newThing > current->data){
                current = current->right;
            }
        }
        current = newNode;
        if (current->data < parent->data) {
            parent->left = current;
        } else if (current->data > parent->data) {
            parent->right = current;
        }
    }
    
    return true;
}

template <class Type>
Type* BST<Type>::search (Type* target) {
    Node *current = root;
    
    while (current != NULL)
    {
        if (current->data == *target) {
            return &current->data;
        } else if (*target < current->data) {
            current = current->left;
        } else {
            current = current->right;
        }
    }
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
