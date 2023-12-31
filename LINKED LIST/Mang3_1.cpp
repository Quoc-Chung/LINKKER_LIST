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
void LonNhatDanhSach (LIST l){
    int max=INT_MIN;
    for (NODE *i=l.pHead ;i!=NULL;i=i->pNext){
        if(max <i->data){
            max=(*i).data;
        }
    }
    printf("\nNODE co data max la :%d",max);
}
bool NguyenTo (int n){
    if(n<2){
        return  false;
    }
    else {
        for(int i=2;i<=sqrt(n);i++ ){
            if(n%i==0){
                return false;
            }
        }
    }
    return true;
}
void KiemTraNguyenTo(LIST l){
    int dem=0;
    for (NODE *i=l.pHead ;i!=NULL ;i=i->pNext){
        if(NguyenTo(i->data)){
            dem++;
        }
    }
   printf("\nCo tat ca %d so nguyen to trong  NODE",dem);
}
int main(){
    int n,x;
   printf("\nNhap so luong node:");
   scanf("%d",&n);
   LIST l;
   KhoiTaoList(l);
   NhapMotNode(l,x,n);
   ThongTinNode(l);
   LonNhatDanhSach (l);
   KiemTraNguyenTo(l);
   return 0;
}