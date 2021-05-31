//
// Created by AntonLvov on 26.05.2021.
//

#ifndef UNTITLED9_BINARYSEARCHTREE_H
#define UNTITLED9_BINARYSEARCHTREE_H

#endif //UNTITLED9_BINARYSEARCHTREE_H
#include "BinaryHeap.h"

template <class T>
class TreeElement{
public:
    T data;
    TreeElement *leftChild;
    TreeElement *rightChild;
    unsigned char height;
    TreeElement(T val){
        leftChild = nullptr;
        rightChild = nullptr;
        data = val;
        height = 1;
    }
};

template <class T>
class BinarySearchTree{
private:
    TreeElement<T> *root;
    size_t size;
   // void delete_tree(TreeElement<T> * current){
   //     if(current){
   //         delete_tree(current->rightChild);
   //         delete_tree(current->leftChild);
   //         delete current;
   //     }
   // }
public:
    BinarySearchTree(T a){
        root = new TreeElement<T>(a);
        size = 1;
    }

    BinarySearchTree(TreeElement<T> *r){
        root = r;
    }

   // ~BinarySearchTree(){
   //     delete_tree(root);
   // }

    bool Find(T key){
        TreeElement<T> *current = root;
        while (current && current->data != key){
            if (current->data > key)
                current = current->leftChild;
            else
                current = current->rightChild;
        }
        return current != nullptr;
    }

    void Add(T key){
        TreeElement<T> *current = root;
        while (current && current->data != key){
            if (current->data > key && current->leftChild == nullptr){
                current->leftChild  = new TreeElement<T>(key);
                ++size;
                return;
            }
            if (current->data < key && current->rightChild == nullptr){
                current->rightChild = new TreeElement<T>(key);
                ++size;
                return;
            }
            if (current->data > key)
                current = current->leftChild;
            else
                current = current->rightChild;
        }
    }

    void Erase(T key){
        TreeElement<T> * current = root;
        TreeElement<T> * parent = nullptr;
        while (current && current->data != key){
            parent = current;
            if (current->data > key)
                current = current->leftChild;
            else
                current = current->rightChild;
        }
        if (!current)
            return;
        if (current->leftChild == nullptr){
            if (parent && parent->leftChild == current)
                parent->leftChild = current->rightChild;
            if (parent && parent->rightChild == current)
                parent->rightChild = current->rightChild;
            --size;
            delete current;
            return;
        }
        if (current->rightChild == nullptr){
            if (parent && parent->leftChild == current)
                parent->leftChild = current->leftChild;
            if (parent && parent->rightChild == current)
                parent->rightChild = current->leftChild;
            --size;
            delete current;
            return;
        }
        TreeElement<T> * replace = current->rightChild;
        while (replace->leftChild)
            replace = replace->leftChild;
        T replace_value = replace->data;
        Erase(replace_value);
        current->data = replace_value;
    }

    size_t GetSize(){
        return size;
    }

    unsigned char height(TreeElement<T> * p){
        return p?p->height:0;
    }

    int balanceFactor(TreeElement<T>* p){
        return height(p->rightChild)-height(p->leftChild);
    }

    void fixHeight(TreeElement<T>* p){
        unsigned char hl = height(p->leftChild);
        unsigned char hr = height(p->rightChild);
        p->height = (hl>hr?hl:hr)+1;
    }

    TreeElement<T>* rotateRight(TreeElement<T>* p){
        TreeElement<T>* q = p->leftChild;
        p->leftChild = q->rightChild;
        q->rightChild = p;
        fixHeight(p);
        fixHeight(q);
        return q;
    }

    void balanceTree(TreeElement<T> *root1){
        if (root1!= nullptr)
            return;
        balance(root1);
        balanceTree(root1->leftChild);
        balanceTree(root1->rightChild);
    }

    TreeElement<T> *copyElements(TreeElement<T> *treeElement, T func(T)){
        if(treeElement == nullptr)
            return nullptr;
        T a = treeElement->data;
        TreeElement<T> *newNode = new TreeElement<T>(func(a));
        newNode->leftChild = copyElements(treeElement->leftChild, func);
        newNode->rightChild = copyElements(treeElement->rightChild, func);
        return newNode;
    }

    BinarySearchTree<T> map(T func(T)){
        TreeElement<T> *newNode = copyElements(root, func);
        BinarySearchTree<T> binarySearchTree = BinarySearchTree<T>(newNode);
        return binarySearchTree;
    }

    TreeElement<T> *copyElements(TreeElement<T> *treeElement){
        if(treeElement == nullptr)
            return nullptr;
        T a = treeElement->data;
        TreeElement<T> *newNode = new TreeElement<T>(a);
        newNode->leftChild = copyElements(treeElement->leftChild);
        newNode->rightChild = copyElements(treeElement->rightChild);
        return newNode;
    }

    void BypassTree(bool func(T), TreeElement<T> *treeElement){
        if(treeElement == nullptr)
            return;
        BypassTree(func, treeElement->leftChild);
        BypassTree(func, treeElement->rightChild);
        T a = treeElement->data;
        if (func(a))
            Erase(a);
    }

    BinarySearchTree<T> where(bool func(T)){
        TreeElement<T> *newNode = copyElements(root);
        BinarySearchTree<T> binarySearchTree = BinarySearchTree<T>(newNode);
        binarySearchTree.BypassTree(func, binarySearchTree.GetRoot());
        return binarySearchTree;
    }

    TreeElement<T> *GetRoot(){
        return root;
    }
};