#include<stdio.h>
#include<math.h>
#include<stdlib.h>
#include<string.h>

struct NuocTieuThu{
	char TenChuHo[50];
	char DiaChi[50];
	int  MaSo;
	int SoNuoc;
};
//Khai bao  cau  truc  NODE  vs LIST 
struct  Node {
	NuocTieuThu data;
	struct  Node *pNext;
};   typedef struct Node NODE;

struct List {
   NODE *pHead;
   NODE *pTail;
};  typedef struct List LIST;

// Khoi  tao LIST rỗng 
void KhoiTaoList(LIST &l){
	l.pHead =NULL;
	l.pTail =NULL;
}
void  DocFile(NuocTieuThu **d,int &n, char *tentep){
	FILE *f=fopen(tentep,"r");
	if(f==NULL){
		printf("\nKhong the  mo duoc file");
		exit(0);
	}
	fscanf(f,"%d",&n);
	(*d)=(NuocTieuThu *) malloc  (n*sizeof(NuocTieuThu));
	for (int i=0;i<n;i++){
		fscanf(f," %[^\n]",(*d)[i].TenChuHo);
		fscanf(f," %[^\n]",(*d)[i].DiaChi);
		fscanf(f,"%d",&(*d)[i].MaSo);
		fscanf(f,"%d",&(*d)[i].SoNuoc);
	}
   printf("\nThong  tin  Ho Gia Dinh:\n");
   for(int i=0;i<n;i++){
   	 printf("\nTen Chu Ho :%s -- Dia Chi :%s -Ma So :%d --So Nuoc: %d",(*d)[i].TenChuHo,(*d)[i].DiaChi,(*d)[i].MaSo,(*d)[i].SoNuoc);
   }
}
NODE* KhoiTaoMotNode(NuocTieuThu d){
	NODE *p =(NODE *) malloc (sizeof(NODE));
	if(p==NULL){
		printf("\nKhong the mo duoc file.");
		exit (0);
	}
	p->data=d;
	p->pNext =NULL;
   return p;
}
void Them_Vap_Dau (LIST &l ,NODE *p){
	// Kiểm tra list có bị  rỗng khum 
	if(l.pHead ==NULL){
		l.pHead =l.pTail=p;
	}
	p->pNext=l.pHead;
	l.pHead=p;
}
void Them_Vao_Cuoi(LIST &l,NODE *p){
    // Kiểm tra xem list có bị rỗng khum
	if(l.pHead ==NULL ){
		l.pHead=l.pTail =p;

	} 
	l.pTail->pNext=p;
	l.pTail=p;

}
void NhapThongTinList(LIST &l,NuocTieuThu *d,int n){
   for (int i=0;i<n;i++){
	NODE *p=KhoiTaoMotNode(d[i]);
	Them_Vao_Cuoi(l,p);
   }
}
void ThongTinNuocTieu(LIST l) {
    printf("\nThong tin nuoc tieu la:\n");
    for (NODE *i = l.pHead; i != NULL; i = i->pNext) {
        printf("Ten Chu Ho: %s - Dia Chi: %s - Ma So: %d - So Nuoc: %d\n", i->data.TenChuHo, i->data.DiaChi, i->data.MaSo, i->data.SoNuoc);
    }
}

int TienNuoc(int SoNuoc) {
	if (SoNuoc <= 10) {
		return 5000 * SoNuoc;
	}
	else if (SoNuoc > 10 && SoNuoc <= 20) {
		return 10 * 5000 + (SoNuoc - 10) * 6200;
	}
	else if (SoNuoc > 20 && SoNuoc <= 30) {
		return 10 * 5000 + 10 * 6200 + (SoNuoc - 20) * 9000;
	}
	else {
		return 10 * 5000 + 10 * 6200 + 10 * 9000 + (SoNuoc - 30) * 16000;
	}
}
void TienNuocTrungBinh(NuocTieuThu *d, int n) {
	int tong = 0;
	float tien = 0;
	for (int i = 0;i < n; i++) {
		tong +=TienNuoc(d[i].SoNuoc);
	}
	int x=n;
	tien=(float)tong / x;
	printf("\nTien Nuoc Trung Binh La: %.2f", tien);
}
void TimThongTin(NuocTieuThu *d, int n) {
	int maso;
	bool  check =false;
	printf("\nNhap ma so tim kiem:");
	scanf("%d",&maso);
	for (int i = 0;i < n;i++) {
		if (maso == d[i].MaSo) {
			printf("\nTien Nuoc Phai Dong: %d", TienNuoc(d[i].SoNuoc));
			check = true;
			break;
		}
	}
	if (check == false) {
		printf("\nKhong tim thay");
	}
}
int  main (){
	int n;
	NuocTieuThu *d;
	char tentep[50]="NuocTieuThu.txt";
	DocFile(&d,n,tentep);
	TienNuocTrungBinh(d,n);
   
	LIST l;
	NhapThongTinList(l,d,n);
	ThongTinNuocTieu(l);

	TimThongTin(d,n);
	return 0;
}