#include<stdio.h>
#include<math.h>
#include<string.h>
#include<stdlib.h>
struct QuyenSach {
  char TenSach[50];
  char TacGia[30];
  int Nam;
};
void  DocFile(QuyenSach **q,int &n,char *tentep){
  FILE *f=fopen(tentep,"r");
  if(f==NULL){
    printf("\nKHong the mo duoc file.");
    exit(0);
  }
  fscanf(f,"%d",&n);
  (*q)=(QuyenSach*) malloc (n*sizeof(QuyenSach));
  for(int i=0;i<n;i++){
    fscanf(f," %[^\n]",(*q)[i].TenSach);
    fscanf(f," %[^\n]",(*q)[i].TacGia);
    fscanf(f,"%d",&(*q)[i].Nam);
  }
  fclose(f);
}
struct Node{
    QuyenSach data;
    struct Node *pNext;
}; typedef struct Node NODE;

struct List {
    NODE *pHead;
    NODE *pTail;
}; typedef struct List LIST;

void KhoiTaoList(LIST &l){
    l.pHead =NULL;
    l.pTail =NULL;
}
// Khoi tao mot NODE
NODE* KhoiTaoNode(QuyenSach q){
    NODE *p =(NODE *) malloc(sizeof(NODE));
    if(p ==NULL ){
        printf("\nKhong the mo duoc file.");
        exit(0);
    }
    p->data=q;
    p->pNext=NULL;
    return p;
}
void Them_Vao_Dau(LIST &l,NODE *p){
  // Kiem tra xem LIST co rong khong
  if(l.pHead == NULL){
    l.pHead = l.pTail =p;
  }
  p->pNext =l.pHead;
  l.pHead=p;
}
void ThemVaoCuoi (LIST &l ,NODE *p){
    // Kiem tra xem LIST co rong khong
    if(l.pHead == NULL ){
        l.pHead =l.pTail =p;
    }
    l.pTail->pNext=p;
    l.pTail=p;
}
void NhapSachVaoList(LIST &l ,int n,QuyenSach *q){
    KhoiTaoList(l);
    for(int i=0;i<n;i++){
        NODE *p =KhoiTaoNode(q[i]);
        ThemVaoCuoi(l,p);
    }
}
void XuatList (LIST l){
    printf("\nThong tin cua cac QUYEN SACH :\n");
    for (NODE *i=l.pHead ;i!=NULL ; i=i->pNext){
      printf("\n%s -- %s -- %d", i->data.TenSach , i->data.TacGia,i->data.Nam);
    }    
}
void QuyenSachCuNhat(LIST l){
    NODE *q;
    int min=INT_MAX;
    for (NODE *i=l.pHead ;i != NULL ;i=i->pNext){
       if(min   > i->data.Nam){
        min=i->data.Nam;
        q=i;
       }
    }
    printf("\nThong tin quyen sach cu nhat la :\n");
    printf("%s --- %s --- %d ",q->data.TenSach,q->data.TacGia ,q->data.Nam);
}
int count[1000006]={0};
void NamNhieuSachNhat(LIST l,int n){
    int *nam =(int *) malloc (n*sizeof(int));
    int k=0;
    for (NODE *i =l.pHead; i!=NULL ;i=i->pNext){
        nam[k++] =i->data.Nam;
    }
    int max =0;
    int nxb_max=0;
    for (int i=0;i<k;i++){
        count[nam[i]]++;
        if(max < count[nam[i]]){
            max =count[nam[i]];
            nxb_max=nam[i];
        }
    }
    printf("\nNam co nhieu sach xuat ban nhat la :%d ", nxb_max);
    for(NODE *i =l.pHead ;i!= NULL ;i=i->pNext){
        if( nxb_max== i->data.Nam){
            printf("\n%s -- %s -- %d", i->data.TenSach , i->data.TacGia,i->data.Nam);
        }
    }
    
}
int main(){
   int n;
   LIST l;
   QuyenSach *q;
   char tentep[50]="QuyenSach.txt";
   DocFile(&q,n,tentep);
   NhapSachVaoList(l,n,q);
   XuatList(l);
   QuyenSachCuNhat(l);
   NamNhieuSachNhat(l,n);
   return 0;
}