#include <stdio.h>
#include <math.h>
#include<stdlib.h>
// tajo node 
struct Node{
	int data;
	struct Node *pNext;// con tro lien ket 
};
typedef struct Node NODE;
// tao list
struct List {
	NODE *pHead;// moi lien ket node dau
	NODE *pTail;// Moi lien ket cuoi 
};
// inittial node return P_point
void khoi_tao(List &l){
    l.pHead=NULL;
    l.pTail=NULL;
}

NODE *khoi_tao_1_node(int x){
	NODE *p=(NODE*) malloc (sizeof(NODE));
	if(p==NULL){
		printf("\nKhong cap phat duoc bo nho.");
		exit(1);
	}
	p->data=x;
	p->pNext=NULL;// chua khoi tao moi lien ket vi luc nay ta moi chi nhap mot node 
	return p;
}
// them vào đầu thì con trỏ p sẽ chăng một day để liên kết với moi lien ket dau 
void them_vao_dau (List &l,NODE *p){
	// kiem tra danh sach co dang con trong
	if(l.pHead==NULL){
		l.pHead=l.pTail=p;
	}
	// chăng dây
	p->pNext=l.pHead;
	l.pHead=p->pNext;// cập nhật lại mối liên kết 
	
}
// them vao cuoi thi ta sẽ chăng một dây từ mối liên kết cuối đến p
void them_vao_cuoi (List &l,NODE *p){
	// plaf mối liên kết của node them vào 
		if(l.pHead==NULL){
		l.pHead=l.pTail=p;
	}
	// chăng dây
	l.pTail->pNext=p;
	l.pTail=p;
}
void nhap_mot_node(List &l,int &x,int n){
	khoi_tao(l);
	// nhap vao node 
	for (int i=1;i<=n;i++){
		printf("\nGia tri cua node thu %d:",i);
		scanf("%d",&x);
		NODE *p=khoi_tao_1_node(x);
		them_vao_cuoi(l,p);
	}
}
void printf_node (List &l){
	printf("\nGia tri cua cac node la:\n");
	for (NODE *i=l.pHead;i!=NULL;i=i->pNext){
		printf(" %d ",i->data);
	}
}
void tim_node_max(List l){
	// i là con trỏ cũng là hiện thân của mối nối 
	int max=l.pHead->data;// dat gia tri max là 
	for (NODE *i=l.pHead;i!=NULL;i=i->pNext){
		if(max<i->data){
			max=i->data;
		}
	}
	printf("\nGia tri max cua list la :%d",max);
}
void swap(int *a,int *b){
 	int tam= *a;
	*a=*b;
	*b=tam;
}
// chỉ có thể dùng hàm qsort để sắp xếp mảng 1 chiều 
// sắp xếp chèn selection sort
void arange(List l){
	for (NODE *i=l.pHead;i!=l.pTail;i=i->pNext){
		for (NODE *j=i->pNext;j!=NULL;j=j->pNext){
			if(i->data>j->data){
				swap(&i->data,&j->data);
			}
		}
	}
	printf("\nGia tri node theo chieu tang dan la :\n");
	for (NODE *i=l.pHead;i!=NULL;i=i->pNext){
		printf("%d ",i->data);
	}
}
void tong_list (List l){
	int tong =0;
	for (NODE *i=l.pHead;i!=NULL;i=i->pNext){
		tong+=i->data;
	}
	printf("\nTong  la  :%d",tong);
}
int main (){
	int n;
	int x;
	List l;
	printf("\nNhap so node :");
	scanf("%d",&n);
	nhap_mot_node(l,x,n);
	printf_node(l);
	tim_node_max(l);
	arange(l);
	tong_list(l);
	return 0;
}







