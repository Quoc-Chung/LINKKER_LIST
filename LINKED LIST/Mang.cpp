#include<bits/stdc++.h>
using  namespace std;
//1.Khai báo cấu trúc của một NODE
struct Node {
 int data;
 struct Node *pNext;
};  typedef struct Node NODE;

struct List{
   NODE *pHead;
   NODE *pTail;
}; typedef struct List LIST;

// Khởi tạo một NODE
NODE* KhoiTaoMotNode(int x){
 NODE *p =(NODE*) malloc (sizeof(NODE ));
 if(p==NULL){
    printf("\nKhong the cap phat duoc node.");
    exit(0);
 }
 p->data=x; 
 p->pNext=NULL;// Vì  mới có 1 node nên nó sẽ trỏ đến  node tiếp theo là  NULL
 return p;
}
// khởi  tạo  LIST chưa trỏ đến đâu
void KhoiTaoList(LIST &l){
   l.pHead=NULL;
   l.pTail=NULL;
}
// Hàm duyêt qua Node 
void DuyetNode1(NODE *pHead){
    while (pHead !=NULL){
      printf("%d ",pHead->data);
      pHead=pHead->pNext;//di chuyen NODE hien tai sang NODE tiếp theo
    }
}
//Hàm duyệt qua các  phần tử trong LIST
void DuyetNode2(LIST l){
   printf("\nCac gia tri cua node la  :\n");
   for (NODE *i=l.pHead;i!=NULL;i=i->pNext){
      printf("%d ",i->data);//(*i).data;
   }
}
// Thêm một  phần tử vào đầu danh  sách liên kết
void ThemVaoDauNode(LIST &l,NODE *p){
   //kiểm tra  danh sách liên kết có đàn trống không  
   if(l.pHead ==NULL){
      l.pHead=l.pTail=p;// = NULL
   }
   //Nếu danh  sách không trông
   else{
     p->pNext=l.pHead;// Con trỏ P thêm vào đầu nên pNExt của con trỏ p lúc  này trỏ  tới  địa chỉ của phần tử đầu
     l.pHead=p;// Phân tử đầu lúc này là  P
   }
}
void ThemVaoCuoi(LIST &l,NODE *p){
   // Kiểm tra xem danh sách có đang trống không tức là phần tử đầu  đang trỏ đến NULL
   if(l.pHead==NULL){
     l.pHead =l.pTail=p;
   }
   //Nếu phần tử đang không trống 
   else {
    l.pTail->pNext=p;
    l.pTail=p;
   }
}

void NhapNode(LIST &l,int &x,int n){
	for (int i=1;i<=n;i++){
		printf("\nGia tri cua node thu %d:",i);
		scanf("%d",&x);
	   	// p là con tro đại diện cho node đang muốn thêm vào 
	   NODE *p=KhoiTaoMotNode(x);
		ThemVaoCuoi(l,p);// thêm node vừa tạo vào đầu 
	 }
}

int Count(NODE *pHead){
   int dem=0;
   while (pHead !=NULL){
      dem++;
      pHead=pHead->pNext;
   }
   return  dem;
}

void TimMaxList(LIST l){
   int max=INT_MIN;
   for (NODE *i=l.pHead;i!=NULL; i=i->pNext){
      if(max <i->data){
         max=i->data;
      }
   }
  printf("\nNode co data max la :%d",max);
}
int main(){
   int n,x;
   printf("\nNhap so luong node:");
   scanf("%d",&n);
   LIST l;
   KhoiTaoList(l);
   NhapNode(l,x,n);
   DuyetNode2(l);
   TimMaxList(l);

}
   