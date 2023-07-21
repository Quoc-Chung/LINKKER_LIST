#include<stdio.h>
#include<math.h>
#include<string.h>
#include<stdlib.h>
#include<ctype.h>

struct ThanhPho{ 
 int STT;
 char ThanhPho[50];
 float DienTich;
 int DanSo;
};
//Khoi Tao Cau Truc Cua Node
struct Node{
    ThanhPho data;
    struct Node *pNext;
}; typedef struct Node NODE ;
// Khoi  tao  cau  truc List 
struct List{
    NODE *pHead;
    NODE *pTail;
}; typedef struct List LIST;
//Khoi  tao List 
void KhoiTaoList(LIST &l){
    l.pHead=NULL;
    l.pTail=NULL;
}

//Kho  tao mot NODE
NODE* KhoiTaoMotNode(ThanhPho data){
     NODE *p=(NODE *) malloc(sizeof(NODE));
     if(p==NULL){
        printf("\nKhong khoi tao duoc NODE");
        exit(0);
     }
     p->data=data;
     p->pNext=NULL;
     return p; 
}
void DocFile(ThanhPho **p,int &n, char *tentep){
    FILE *f=fopen(tentep,"r");
    if(f==NULL){
        printf("\nKhong the mo duoc file de doc");
        exit(0);
    }
    fscanf(f,"%d",&n);
    (*p)=(ThanhPho *) malloc(n*sizeof(ThanhPho));
    for(int i=0;i<n+1;i++){
        /*
        fscanf(f,"%d",&(*p)[i].STT);
        fscanf(f, " %[^\t]", (*p)[i].ThanhPho); // Chú ý sử dụng %[^\t] để đọc tên thành phố bao gồm dấu cách
        fscanf(f,"%f",&(*p)[i].DienTich);
        fscanf(f,"%d",&(*p)[i].DanSo);
        */
     fscanf(f, "%d %[^\t] %f %d",&(*p)[i].STT,(*p)[i].ThanhPho,&(*p)[i].DienTich,&(*p)[i].DanSo);
    }
    /*
    printf(("\nTHONG TIN THANH PHO:\n"));
    for (int i=0;i<n;i++){
        printf("\nSo Thu Tu :%d --Thanh Pho :%s --Dien Tich :%.1f -Dan So :%d",
            (*p)[i].STT,(*p)[i].ThanhPho,(*p)[i].DienTich,(*p)[i].DanSo );
    }
    */
}

void Them_Vao_Dau(LIST &l,NODE *p){
    //Kiem tra LIST rỗng không
    if(l.pHead==NULL){
       l.pHead=l.pTail=p;//Tat Ca Deu bâng NULL
    }
    p->pNext=l.pHead;
    l.pHead=p;
}
void Them_Vao_Cuoi(LIST &l,NODE *p){
    // Kiem tra LIST rỗng không 
    if(l.pHead ==NULL){
        l.pHead=l.pTail =p;
    }
    l.pTail->pNext=p;
    l.pTail=p;
}
void DocThongTinNode(LIST &l,ThanhPho *tp,int n){
  KhoiTaoList(l);
  for (int i=0;i<n;i++){
    NODE *p =KhoiTaoMotNode(tp[i]);
     Them_Vao_Cuoi(l,p);
  }
}
void ThongTinToanBoNode(LIST l){
    printf("\nTHONG TIN CUA NODE LA :\n");
    for (NODE *i=l.pHead ;i!=NULL;i=i->pNext){
        printf("\n%d -- %s -- %.1f -- %d",(*i).data.STT,(*i).data.ThanhPho,i->data.DienTich,i->data.DanSo);
    }
}

void ThongTinThanhPho(ThanhPho *p,int n){
 printf(("\nTHONG TIN THANH PHO:\n"));
    for (int i=0;i<n;i++){
        printf("\nSo Thu Tu :%d --Thanh Pho :%s --Dien Tich :%.1f -Dan So :%d",
              p[i].STT,p[i].ThanhPho,p[i].DienTich,p[i].DanSo );
    }
}
void  TongDienTichTInhThanh(LIST l){
    float tong =0;
    for (NODE *i=l.pHead ;i!=NULL ;i=i->pNext){
        tong+= i->data.DienTich;
    }
    printf("\ntong dien tich la :%.1f",tong);
}

void HoanVi(ThanhPho &a, ThanhPho &b)
{
	ThanhPho Temp = a;
	a = b;
	b = Temp;
}
// Sắp xếp node theo  diện tích tăng dần
void SapXepNode(LIST &l){
  /*
	for(int i = 0; i < n - 1; i++)
	{
		for(int j = i + 1; j < n; j++)
		{
			if(a[i] > a[j])
			{
				HoanVi(a[i], a[j]);
			}
		}
	}
	*/
printf("\nDanh  sach thanh pho  sap xep theo dien  tich:\n");
  for (NODE *i =l.pHead ;i!=NULL ;i=i->pNext){

    for (NODE *j= i->pNext ; j!=NULL ;j=j->pNext){
            if(i->data.DienTich > j->data.DienTich){
                HoanVi(i->data,j->data);
            }
    }
  }
}
int main (){
    int n;
    char tentep[50]="ThanhPho.txt";
    ThanhPho *p;
    DocFile(&p,n,tentep);
    LIST l;
 // ThongTinThanhPho(p,n);
    DocThongTinNode(l,p,n);

    ThongTinToanBoNode(l);

    SapXepNode(l);

    ThongTinToanBoNode(l);

    return  0;

    
    
}