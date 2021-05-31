//
// Created by AntonLvov on 24.05.2021.
//

#ifndef UNTITLED9_MENU_H
#define UNTITLED9_MENU_H

#endif //UNTITLED9_MENU_H
#include "BinarySearchTree.h"


using namespace std;

template <class T>
void printBinarySearchTree(TreeElement<T> * root, int space = 0) {
    if (!root)
        return;
    enum { COUNT = 2 };
    space += COUNT;
    printBinarySearchTree(root->rightChild, space);
    for (int i = COUNT; i < space; ++i)
        std::cout << "  ";
    cout << root->data << endl;
    printBinarySearchTree(root->leftChild, space);
}


int GetInt(){
    int a;
    cin>>a;
    if (a<1){
        cout<<"Number is out of range. Try again:";
        GetInt();
    }
    return a;
}

int GetInt(int lower, int upper){
    int a;
    cout<<"Input number: ";
    cin>>a;
    if(a>upper||a<lower){
        cout<<"Number is out of range, try again"<<endl;
        GetInt(lower, upper);
    }
    return a;
}

int getNumber(int a){
    int b;
    cin>>b;
    return b;
}

float getNumber(float a){
    float b;
    cin>>b;
    return b;
}

int randomInt() {
    return rand()%1000;
}

float randomFloat() {
    return static_cast <float> (rand()) / (static_cast <float> (RAND_MAX/100));
}

template <class T>
BinaryHeap<T> *creatBinaryHeapNotRandom(){
    cout<<"Input 1 number: "<<endl;
    T *a = new T[1];
    cin>>a[0];
    BinaryHeap<T> *binaryHeap = new BinaryHeap<T>(a, 1);
    T b;
    while (1) {
        cout << "Do you want to add number?." << endl;
        cout << "1. Yes." << endl;
        cout << "2. No." << endl;
        int point = GetInt(1, 2);
        if (point == 2)
            break;
        cout << "Input number: " << endl;
        cin >> b;
        binaryHeap->AddElement(b);
    }
    for (int i = binaryHeap->GetHeapSize() / 2; i >= 0; i--)
        binaryHeap->heapify(i);
    return binaryHeap;
}

template<class T>
BinaryHeap<T> *creatBinaryHeapRandom(T func()){
    cout<<"How many numbers do you want?"<<endl;
    int point = GetInt();
    T *a = new T[1];
    a[0] = func();
    BinaryHeap<T> *binaryHeap = new BinaryHeap<T>(a, 1);
    T b;
    for (int i = 0; i < point-1; ++i) {
        b = func();
        binaryHeap->AddElement(b);
    }
    for (int i = binaryHeap->GetHeapSize() / 2; i >= 0; i--)
        binaryHeap->heapify(i);
    return binaryHeap;
}

template <class T>
void creatBinaryHeap(ArraySequence<BinaryHeap<T>*> *arraySequence, T func()){
    cout<<"Do you want to fill binary heap yourself?"<<endl;
    cout<<"1. Yes."<<endl;
    cout<<"2. No."<<endl;
    int point = GetInt(1, 2);
    BinaryHeap<T> *binaryHeap;
    switch (point) {
        case 1:
            binaryHeap = creatBinaryHeapNotRandom<T>();
            break;
        case 2:
            binaryHeap = creatBinaryHeapRandom(func);
            break;
        default: break;
    }
    arraySequence->Append(binaryHeap);
}

void chooseBinaryHeapType(ArraySequence<BinaryHeap<int> *> *binaryHeapIntArray, ArraySequence<BinaryHeap<float> *> *binaryHeapFloatArray){
    cout<<"What type  do you want?"<<endl;
    cout<<"1. Int."<<endl;
    cout<<"2. Float."<<endl;
    int b = GetInt(1,2);
    switch (b) {
        case 1:
            creatBinaryHeap(binaryHeapIntArray, randomInt);
            break;
        case 2:
            creatBinaryHeap(binaryHeapFloatArray, randomFloat);
            break;
        default: break;
    }
}

template <class T>
BinarySearchTree<T> *creatBinaryTreeRandom(T func()){
    cout<<"How many numbers do you want?"<<endl;
    int point = GetInt();
    T a = func();
    BinarySearchTree<T> *binarySearchTree = new BinarySearchTree<T>(a);
    T b;
    for (int i = 0; i < point-1; ++i) {
        b = func();
        binarySearchTree->Add(b);
    }
    return binarySearchTree;
}

template <class T>
BinarySearchTree<T> *creatBinaryTreeNotRandom(){
    cout<<"Input 1 number: "<<endl;
    T *a = new T[1];
    cin>>a[0];
    BinarySearchTree<T> *binarySearchTree = new BinarySearchTree<T>(a[0]);
    T b;
    while (1) {
        cout << "Do you want to add number?." << endl;
        cout << "1. Yes." << endl;
        cout << "2. No." << endl;
        int point = GetInt(1, 2);
        if (point == 2)
            break;
        cout << "Input number: " << endl;
        cin >> b;
        binarySearchTree->Add(b);
    }
    return binarySearchTree;
}

template <class T>
void creatBinaryTree(ArraySequence<BinarySearchTree<T>*> *arraySequence, T func()){
    cout<<"Do you want to fill binary search tree yourself?"<<endl;
    cout<<"1. Yes."<<endl;
    cout<<"2. No."<<endl;
    int point = GetInt(1, 2);
    BinarySearchTree<T> *binarySearchTree;
    switch (point) {
        case 1:
            binarySearchTree = creatBinaryTreeNotRandom<T>();
            break;
        case 2:
            binarySearchTree = creatBinaryTreeRandom<T>(func);
            break;
        default: break;
    }
    arraySequence->Append(binarySearchTree);
}

void chooseBinarySearchTreeType(ArraySequence<BinarySearchTree<float> *> *binarySearchFloatArray, ArraySequence<BinarySearchTree<int> *> *binarySearchIntArray) {
    cout << "What type do you want?" << endl;
    cout << "1. Int." << endl;
    cout << "2. Float." << endl;
    int b = GetInt(1, 2);
    switch (b) {
        case 1:
            creatBinaryTree(binarySearchIntArray, randomInt);
            break;
        case 2:
            creatBinaryTree(binarySearchFloatArray, randomFloat);
            break;
        default:
            break;
    }
}

template <class T>
void printBinaryHeapFromMemory(ArraySequence<BinaryHeap<T> *> *arraySequence){
    for (int i = 0; i < arraySequence->GetLength(); ++i) {
        cout<<*arraySequence->Get(i);
    }
}

void showAvailableBinaryHeaps(ArraySequence<BinaryHeap<int> *> *binaryHeapIntArray, ArraySequence<BinaryHeap<float> *> *binaryHeapFloatArray){
    cout << "What type do you want?" << endl;
    cout << "1. Int." << endl;
    cout << "2. Float." << endl;
    int b = GetInt(1, 2);
    switch (b) {
        case 1:
            printBinaryHeapFromMemory(binaryHeapIntArray);
            break;
        case 2:
            printBinaryHeapFromMemory(binaryHeapFloatArray);
            break;
        default:
            break;
    }
}

template <class T>
void printBinaryTreesFromMemory(ArraySequence<BinarySearchTree<T> *> *arraySequence){
    for (int i = 0; i < arraySequence->GetLength(); ++i) {
        printBinarySearchTree(arraySequence->Get(i)->GetRoot());
    }
    cout<<endl<<endl;
}

void showAvailableBinaryTrees(ArraySequence<BinarySearchTree<float> *> *binarySearchFloatArray, ArraySequence<BinarySearchTree<int> *> *binarySearchIntArray){
    cout << "What type do you want?" << endl;
    cout << "1. Int." << endl;
    cout << "2. Float." << endl;
    int b = GetInt(1, 2);
    switch (b) {
        case 1:
            printBinaryTreesFromMemory(binarySearchIntArray);
            break;
        case 2:
            printBinaryTreesFromMemory(binarySearchFloatArray);
            break;
        default:
            break;
    }
}

void operateWithBinaryHeaps(){
    cout<<"What do you want to do?"<<endl;
    cout<<"1. Add element."<<endl;
    cout<<"2. Delete element."<<endl;
    cout<<"3. Find element."<<endl;
    cout<<"4. Map binary heap."<<endl;
    cout<<"5. Do where binary heap."<<endl;
    cout<<"6. Allocate subtree."<<endl;
    cout<<"7. Find subtree."<<endl;
    int point = GetInt(1, 7);
}

void mainMenu(){
    ArraySequence<BinaryHeap<int> *> binaryHeapIntArray;
    ArraySequence<BinaryHeap<float> *> binaryHeapFloatArray;
    ArraySequence<BinarySearchTree<float> *> binarySearchFloatArray;
    ArraySequence<BinarySearchTree<int> *> binarySearchIntArray;

    while (1) {
        cout<<"Menu: "<<endl;
        cout<<"1. Create binary heap."<<endl;
        cout<<"2. Create binary search tree."<<endl;
        cout<<"3. Show available binary heaps."<<endl;
        cout<<"4. Show available binary search trees."<<endl;
        cout<<"5. Operate with binary heaps."<<endl;
        cout<<"6. Operate with binary search tree."<<endl;
        cout<<"7. Launch binary heap's test."<<endl;
        cout<<"8. Launch binary search tree's test."<<endl;
        cout<<"9. Exit."<<endl;

        int point = GetInt(1, 9);

        if (point == 9)
            break;
        switch (point) {
            case 1:
                chooseBinaryHeapType(&binaryHeapIntArray, &binaryHeapFloatArray);
                break;
            case 2:
                chooseBinarySearchTreeType(&binarySearchFloatArray, &binarySearchIntArray);
                break;
            case 3:
                showAvailableBinaryHeaps(&binaryHeapIntArray, &binaryHeapFloatArray);
                break;
            case 4:
                showAvailableBinaryTrees(&binarySearchFloatArray, &binarySearchIntArray);
                break;
            case 5:
                break;
            case 6:
                break;
            case 7:
                break;
            case 8:
                break;
            default:
                break;
        }
    }
}