#include<bits/stdc++.h>
using namespace std;
//khởi tạo node 
struct Node {
    int data;
    struct Node *pNext;
};  typedef struct Node NODE;
// khai bao cau  truc list
struct List {
    NODE *pHead;
    NODE *pTail;
};  typedef struct List LIST;
// khoi  tao list 
void KhoiTaoList(LIST &l){
    l.pHead=NULL;
    l.pTail=NULL;
}
// Viết hàm  khởi tạo một NODE
NODE* KhoiTaoNode(int x){
    NODE *p=(NODE *) malloc (sizeof(NODE));
    if(p==NULL){
        printf("\nKhong the khoi tao duoc node.");
        exit(0);
    }
    p->data=x;
    p->pNext=NULL;
    return p;
}
void ThemVaoDau(LIST &l,NODE *p){
    // kiểm ta xem DSLK có trống không 
    if(l.pHead==NULL){
        l.pHead=l.pTail=p;// tất cả đều = NULL
    }
    else{
        p->pNext=l.pHead;//Head đứng sau p  
        l.pHead=p;
    }
}
void ThemVaoCuoi (LIST &l,NODE *p){
    if(l.pHead==NULL){
        l.pHead=l.pTail=p;
    }
    else{
        l.pTail->pNext=p;
        l.pTail=p;
    }
}
// Viết  hàm nhâp một NODE 
void NhapMotNode(LIST &l,int x,int n){
    for (int i=0;i<n;i++){
        printf("\nNhap NODE thu %d:",i+1);
        scanf("%d",&x);
        NODE *p=KhoiTaoNode(x);
        ThemVaoCuoi(l,p);
    }
}
// Viết hàm in thông tin NODE 
void ThongTinNode(LIST l){
    printf("\nThong tin cua cac NODE la :\n");
    // i=i->pNext <=> i++
    for (NODE *i=l.pHead ;i!=NULL;i=i->pNext){
        printf("%d  ",i->data);
    }
}


int main(){
    int n,x;
   printf("\nNhap so luong node:");
   scanf("%d",&n);
   LIST l;
   KhoiTaoList(l);
   NhapMotNode(l,x,n);
   ThongTinNode(l);
   return 0;
}