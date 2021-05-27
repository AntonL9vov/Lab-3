//
// Created by AntonLvov on 26.05.2021.
//

#ifndef UNTITLED9_BINARYSEARCHTREE_H
#define UNTITLED9_BINARYSEARCHTREE_H

#endif //UNTITLED9_BINARYSEARCHTREE_H
#include <string>
#include <iostream>
#include "cstring"
#include "IndexOutOfRangeException.h"

template <class T>
class TreeElement{
public:
    T m_data;
    TreeElement *leftChild;
    TreeElement *rightChild;
    TreeElement(T val){
        leftChild = nullptr;
        rightChild = nullptr;
        m_data = val;
    }
};

template <T>
class BinarySearchTree{
private:
    TreeElement *root;
    size_t size;
    void delete_tree(TreeElement * current){
        if(current){
            delete_tree(current->rightChild);
            delete_tree(current->leftChild);
            delete current;
        }
    }
public:
    BinarySearchTree(int a){
        root = new TreeElement(a);
        size = 1;
    }

    ~BinarySearchTree(){
        delete_tree(root);
    }

    bool find(int){
        tree_elem * curr = m_root;
        while (curr && curr->m_data != key)
        {
            if (curr->m_data > key)
                curr = curr->m_left;
            else
                curr = curr->m_right;
        }
        return curr != NULL;
    }

    void insert(int);
    void erase(int);
    int size();
};