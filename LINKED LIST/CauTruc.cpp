#include<bits/stdc++.h>
using namespace std;
struct SinhVien{
 string Name;  // char name[100];
 string Lop;   // char Lop[50];
 double gpa;
};
struct Node {
 SinhVien data;
 struct Node *pNext;
};typedef struct Node  NODE;

// Tạo mói một node 
NODE* KhoiTaoMotNode(SinhVien hs){
    NODE *p=(NODE *)malloc(sizeof(NODE));
    if(p==NULL){
        printf("\nKhong the khoi tao duoc node.");
        exit(0);
    }
    p->data=hs;
    p->pNext=NULL;//Vì ban dau chi co mot node nen pNext =NULL
 return p;
}


int main (){
    int a[100];
    return  0;
}