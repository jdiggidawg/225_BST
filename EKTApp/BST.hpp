//
//  BST.hpp
//  EKTApp
//
//  Created by Jessie Tran on 2016-07-10.
//  Copyright © 2016 jdiggidawg. All rights reserved.
//

#ifndef BST_hpp
#define BST_hpp

#include "Word.hpp"
#include <stdio.h>
#include <iostream>
using namespace std;


template <class Type>
class BST
{

private:
    
    
public:
    BST();
    
    bool insert (const Word&);
    
    Word* search (const Word& target);
    
    
};

bool BST::BST() {
    
}



#endif /* BST_hpp */
