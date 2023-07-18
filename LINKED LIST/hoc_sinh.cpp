#include <stdio.h>
#include <math.h>
#include <string.h>
#include <stdlib.h>
struct hocsinh{
   char ten[30];
   char lop[10];
   char SDT[13];
   float diem;
};typedef struct hocsinh HOCSINH;
void nhap_mot_hs(HOCSINH &hs){
    printf("\nNhap ten hoc sinh:");
    fflush(stdin);
    fgets(hs.ten,sizeof(hs.ten),stdin);
}
struct Node{
  HOCSINH data;
  struct Node *pNext;
};typedef struct Node NODE;
struct List {
   NODE *pHead;
   NODE *pTail;
};typedef struct List LIST;
// khởi tạo list 
void khoi_tao_list(LIST &l){
    // danh sách còn trống
    l.pHead=NULL;
    l.pTail=NULL;
}
// khởi tạo node
NODE *khoi_tao_mot_node(HOCSINH &hs){
    NODE *p=(NODE *) malloc (sizeof(NODE));
    if(p==NULL){
        printf("\nKhong cap phat duoc dia chi de tao node.");
        exit(1);
    }
    p->data=hs;
    p->pNext=NULL;// vì mới có một node được tạo 
    return p;
}
// p   l.pHead    l.pTail
void them_vao_dau(LIST &l,NODE *p){
    // kiểm tra danh sách rỗng không 
    if(l.pHead==NULL){
        l.pHead=l.pTail=p;
    }
    else {
        p->pNext=l.pHead;
        l.pHead=p;
    }
}
// l.pHead   l.pTail  p
void them_vao_cuoi(LIST &l,NODE *p){
     if(l.pHead==NULL){
        l.pHead=l.pTail=p;
    }
    else {
        l.pTail->pNext=p;
        l.pTail=p;
    }
}
void nhap_node(LIST &l,int n){
    khoi_tao_list(l);
    for (int i=1;i<=n;i++){
        printf("\nNhap node thu %d :\n",i);
        HOCSINH hs;
        nhap_mot_hs(hs);
        NODE *p=khoi_tao_mot_node(hs);
        them_vao_cuoi(l,p);
    }
}
void delete_newline(char c[]){
    size_t len=strlen(c);
    if(c[len-1]=='\n'){
        c[len-1]='\0';
    }
}
void in_thong_tin(HOCSINH &hs){
	printf("\nTen hoc sinh:%s",hs.ten);
}
void printf_list_nomal(LIST &l){
	for(NODE *i=l.pHead;i!=NULL;i=i->pNext){
		in_thong_tin(i->data);
	}
}
void them_node_bat_ki_tru_dau_cuoi(LIST &l, NODE *p, NODE *q, char ten1[]) {
    int flag = 0;
    NODE *prev = NULL;
    for (NODE *i = l.pHead; i != NULL; i = i->pNext) {
        if (strcmp(i->data.ten, ten1) == 0) {
            if (prev == NULL) { // q is the head of the list
                p->pNext = q->pNext;
                q->pNext = p;
                if (l.pTail == q) {
                    l.pTail = p;
                }
            } else {
                p->pNext = i;
                prev->pNext = p;
            }
            flag = 1;
            break;
        }
        prev = i;
    }
    if (flag == 0) {
        printf("\nKhong tim thay node de them");
    }
}


int main (){
    int n;
    printf("\nNhap so node :");
    scanf("%d",&n);
    LIST l;
    nhap_node(l,n);
    
    printf_list_nomal(l);
    
    
    char ten1[30];
	fflush(stdin);
	printf("\nNhap hs de them hs phia sau:");
	fgets(ten1,sizeof(ten1),stdin);
	
    // Tạo node mới chứa thông tin của học sinh mới
    printf("\nNhap thong tin hoc sinh moi :");
   HOCSINH hs;
   nhap_mot_hs(hs);
   NODE *P=khoi_tao_mot_node(hs);
   
   printf("\nKiem tra lai vi tri hoc sinh them :\n");
   HOCSINH hs1;
   nhap_mot_hs(hs1);
   NODE *Q=khoi_tao_mot_node(hs1);
   them_node_bat_ki_tru_dau_cuoi(l,P,Q,ten1);
//   delete_newline(ten1);
   printf_list_nomal(l);
   
   
}
