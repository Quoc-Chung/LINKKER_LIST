#include<stdio.h>
#include<math.h>
#include<string.h>
#include<stdlib.h>
//Khai bao NODE + LIST
struct Node {
 int data;
 struct Node *pNext;
}; typedef struct Node NODE;

struct List {
    NODE *pHead;
    NODE *pTail;
}; typedef struct List LIST;

// Khoi Tao LIST rỗng
void KhoiTaoList(LIST &l){
    l.pHead=NULL;
    l.pTail=NULL;
}
NODE* KhoiTaoMotNode(int x){
    NODE *p=(NODE *) malloc (sizeof(NODE));
    if(p==NULL){
        printf("\nKHong the  mo duuoc file .");
        exit (0);
    }
    p->data=x;
    p->pNext=NULL;
    return p;
}
void DocFile(int **a, int &n, char *tentep) {
    FILE *f = fopen(tentep, "r");
    if (f == NULL) {
        printf("\nKhong the mo duoc file.");
        exit(0);
    }
    fscanf(f, "%d", &n); // Đọc giá trị đầu tiên trong file để lấy số lượng phần tử
    (*a) = (int *)malloc(n * sizeof(int));
    for (int i = 0; i < n; i++) {
        fscanf(f, "%d", &(*a)[i]);
    }
    fclose(f);
}


void Them_Vao_Dau(LIST &l,NODE *p){
    //Kiem tra LIST rỗng
    if(l.pHead ==NULL){
        l.pHead =l.pTail = p;
    }
    p->pNext=l.pHead;
    l.pHead=p;
}

void Them_Vao_Cuoi (LIST &l,NODE *p){
    //Kiem tra LIST rỗng
    if(l.pHead ==NULL){
        l.pHead =l.pTail =p;
    }
    l.pTail->pNext =p;
    l.pTail=p;
}

bool NguyenTo(int n) {
    if (n < 2) {
        return false;
    } else {
        for (int i = 2; i <= sqrt(n); i++) {
            if (n % i == 0) {
                return false;
            }
        }
    }
    return true;
}
void NhapNode (LIST &l,int *a,int n){
    KhoiTaoList(l);
    for (int i=0;i<n;i++){
        // x duoc doc ra tu tep
        NODE *p=KhoiTaoMotNode(a[i]);
        if(NguyenTo (p->data)){
            Them_Vao_Cuoi(l,p);
        }
    }
    // printf("\nThong tin NODE  la  :\n");
    // for ( NODE  *i=l.pHead;i!=NULL ;i=i->pNext){
    //     printf("%d ",i->data);
    // }
}
void ThongTinNode(LIST l){
    
    for(NODE *i=l.pHead ;i!=NULL ;i=i->pNext){
        printf("%d ",i->data);
    }
}
void TachNode(LIST l, LIST &l1, LIST &l2) {

    for (NODE *i = l.pHead; i != NULL; i = i->pNext) {
        if (i->data % 2 == 0) {
            NODE *p = KhoiTaoMotNode(i->data);
            Them_Vao_Cuoi(l1, p);
        } else if( i->data %2 != 0){
            NODE *p = KhoiTaoMotNode(i->data);
            Them_Vao_Cuoi(l2, p);
        }
    }
}
int main(){
    int n;
  
    char tentep[50]="MangTron.txt";
    int *a;
    LIST l1,l2,l;
    DocFile(&a,n,tentep);

    NhapNode (l,a,n);
    
    printf("\nThong tin cua NODE la :\n");
    ThongTinNode(l);

    TachNode(l,l1,l2);
    printf("\nNode Chua toan So Nguyen To Le:\n");
    for(NODE *i=l2.pHead ;i!=NULL ;i=i->pNext){
        printf("%d ",i->data);
    }

    printf("\nNode Chua toan So Nguyen To Chan:\n");
    for(NODE *i=l1.pHead ;i!=NULL ;i=i->pNext){
        printf("%d ",i->data);
    }
    return 0;
}
