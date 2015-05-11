//
//  main.c
//  CPractice
//
//  Created by 毕鸣 on 2/4/15.
//  Copyright (c) 2015 BM. All rights reserved.
//

#include <stdio.h>

#define MAXSIZE 5
#define EQ(a,b) ((a) == (b))

typedef int KeyType;
typedef struct {
    KeyType key;
    //InfoType otherType;
}RedType;

typedef struct {
    RedType r[MAXSIZE+1];
    int length;
}SqList;


int main(int argc, const char * argv[]) {
    // insert code here...
    void InsertSort(SqList L);
    RedType red[MAXSIZE + 1] = {0,3,7,2,5,9};
    SqList sqList = {red, 6};
    for (int i = 1; i < MAXSIZE + 1; i++) {
        printf("%d, ", sqList.r[i].key);
    }
    
    InsertSort(sqList);
    
    for (int i = 1; i < MAXSIZE + 1; i++) {
        printf("%d, ", sqList.r[i].key);
    }
    
    return 0;
}

void InsertSort(SqList L) {
    int i, j;
    for (i = 2; i < L.length; i++) {
        if (L.r[i].key < L.r[i - 1].key) {
            L.r[0] = L.r[i];
            L.r[i] = L.r[i - 1];
            for (j = i - 2; L.r[0].key < L.r[j].key; --j ) {
                L.r[j + 1] = L.r[j];
            }
            L.r[j + 1] = L.r[0];
        }
    }
}