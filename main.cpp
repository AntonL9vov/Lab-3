#include <iostream>
#include "BinaryHeap.h"

using namespace std;


int randomInt() {
    return rand()%1000;
}

int multTwice(int a){
    return a*2;
}

bool isEven(int a){
    if(a%2 == 0)
        return true;
    return false;
}

int main() {
    int *a = new int[3];
    for (int i = 0; i < 3; ++i) {
        a[i] = randomInt();
        cout<<a[i]<<" ";
    }
    cout<<endl;
    BinaryHeap<int> binaryHeap = BinaryHeap<int>(a, 3);
    cout<<binaryHeap;
    binaryHeap.AddElement(100);
    binaryHeap.AddElement(randomInt());
    binaryHeap.AddElement(randomInt());
    binaryHeap.AddElement(randomInt());
    binaryHeap.AddElement(randomInt());
    binaryHeap.AddElement(800);
    binaryHeap.AddElement(randomInt());
    binaryHeap.AddElement(randomInt());
    binaryHeap.AddElement(randomInt());
    binaryHeap.AddElement(randomInt());
    cout<<binaryHeap;
    BinaryHeap<int> *binaryHeap1 = binaryHeap.subBinaryHeap(800);
    cout<<*binaryHeap1;
    bool flag = binaryHeap.findSubBinaryHeap(binaryHeap1);
    cout<<flag;
    return 0;
}
