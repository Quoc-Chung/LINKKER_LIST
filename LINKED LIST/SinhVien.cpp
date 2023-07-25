#include<stdio.h>
#include<math.h>
struct SinhVien{
    int Ma;
    char HoTen[50];
    int NamSinh;
    char GioiTinh[10];
    char QueQuan[50];
};
struct Node {
    SinhVien data;
    struct Node *pNext;
}; typedef struct Node NODE;
struct List {
    NODE *pHeal;
    NODE *pTail;
}; typedef struct List LIST;
void KhoiTaoList(LIST &l){
    l.pHeal=NULL;
    l.pTail=NULL;
}
void  DocFile(SinhVien **sv,int &n,char *tentep){
    FILE *f=fopen(tentep,"r");
    if(f==NULL){
        printf("\nKhong the mo duoc file.");
        exit(0);
    }
    fscanf(f,"%d",&n);
    (*sv)=(SinhVien *)malloc(n*sizeof(SinhVien));
    if(*sv==NULL){
        printf("\nKHong the cap phat dong  ");
        exit(0);
    }
    for (int i=0;i<n;i++){
        fscanf(f,"%d",&(*sv)[i].Ma);
        fscanf(f," %[^\n]",(*sv)[i].HoTen);
        fscanf(f,"%d",&(*sv)[i].NamSinh);
        fscanf(f," %[^\n]",(*sv)[i].GioiTinh);
        fscanf(f," %[^\n]",(*sv)[i].QueQuan);
    }
}
// Khởi tạo NODE
NODE* KhoiTaoNode(SinhVien sv){
    NODE *p=(NODE *)malloc(sizeof(NODE));
    if(p==NULL){
        printf("\nKhong the mo duoc file.");
        exit(0);
    }
    p->data=sv;
    p->pNext=NULL;
    return  p;
}
void Them_Vao_Dau(LIST &l,NODE *p){
    if(l.pHeal ==NULL){
        l.pHeal=l.pHeal=p;
    }
    p->pNext=l.pHeal;
    l.pHeal=p;
}
void Them_Vao_Cuoi(LIST &l,NODE *p){
    if(l.pHeal == NULL ){
        l.pHeal =l.pTail=p;
    }
    l.pTail ->pNext =p;
    l.pTail=p;
}
void ThemNodeVaoList(LIST &l,int n, SinhVien *sv){
    KhoiTaoList(l);
    for(int i=0;i<n;i++){
        NODE *p=KhoiTaoNode(sv[i]);
        Them_Vao_Cuoi(l,p);
    }
}
void  Duyet_List(LIST l){
    printf("\nDanh  sach trong  LIST la :\n");
    for (NODE *i=l.pHeal;i!=NULL;i=i->pNext){
        printf("\n%d -- %s -- %d -- %s -- %s",
               i->data.Ma,i->data.HoTen,i->data.NamSinh,i->data.GioiTinh,i->data.QueQuan);
    }
}
void  GhiRaFile(LIST l,FILE *f=stdout){
    fprintf(f,"\nDanh  sach trong  LIST la :\n");
    for (NODE *i=l.pHeal;i!=NULL;i=i->pNext){
        fprintf(f,"\n%d -- %s -- %d -- %s -- %s",
               i->data.Ma,i->data.HoTen,i->data.NamSinh,i->data.GioiTinh,i->data.QueQuan);
    }
}
void BoXungSinhVien(LIST &l){
    SinhVien sv;
    printf("\nNhap Ma:");       scanf("%d",&sv.Ma);
    printf("\nNhap Ho Ten:");     fflush(stdin) ; gets(sv.HoTen);
    printf("\nNhap Nam Sinh: ");scanf("%d",&sv.NamSinh);
    printf("\nNhap Gioi Tinh :"); fflush(stdin) ; gets(sv.GioiTinh);
    printf("\nNhap Que Quan :");  fflush(stdin) ; gets(sv.QueQuan);
    NODE *p=KhoiTaoNode(sv);
    Them_Vao_Cuoi(l,p);
}
void XoaDau(LIST &l) {
    NODE *p = l.pHeal; // p trỏ vào đầu
    l.pHeal = l.pHeal->pNext; // đầu trốn sang bên cạnh
    free(p); // giải phóng p
}

void XoaCuoi(LIST &l) {
    NODE *p; // p sẽ là Node nằm trước Tail tìm thấy
    for (NODE *k = l.pHeal; k != NULL; k = k->pNext) {
        if (k == l.pTail) {
            l.pTail = p;
            l.pTail->pNext = NULL;
            free(k);
            return;
        }
        p = k;
    }
}

// Xóa Node nằm sau Node q trong danh sách
void XoaSauMotNode(LIST &l, NODE *q) {
    NODE *g; // Node nằm sau q
    for (NODE *k = l.pHeal; k != NULL; k = k->pNext) {
        // tìm q
        if (k == q) { // Fix the condition here, comparing the pointers
            g = k->pNext;
            k->pNext = g->pNext;
            free(g); // Use free instead of delete for consistency with the other functions
            return;
        }
    }
}

void XoaNodeKhoaBatKy(LIST &l, int Ma) {
    if (l.pHeal->data.Ma == Ma) {
        XoaDau(l);
        return;
    }

    if (l.pTail->data.Ma == Ma) {
        XoaCuoi(l);
        return;
    }

    NODE *q;
    // Nếu Node cần xóa không phải đầu hoặc cuối
    // Tìm ra Node nằm trước Node có khóa cần xóa => gọi hàm xóa Node sau cái Node vừa tìm thấy
    for (NODE *g = l.pHeal; g != NULL; g = g->pNext) {
        if (g->data.Ma == Ma) { // Fix the variable name here: data -> data1
            XoaSauMotNode(l, q);
            return;
        }
        q = g;
    }
}
void CapNhatSinhVien(LIST l){
    printf("\nNhap Ma Sinh Vien :");
    int Ma;
    scanf("%d",&Ma);
    bool check=false;
    for (NODE *i=l.pHeal ;i!=NULL;i=i->pNext){
      if(i->data.Ma==Ma){
         printf("\n%d -- %s -- %d -- %s -- %s",
               i->data.Ma,i->data.HoTen,i->data.NamSinh,i->data.GioiTinh,i->data.QueQuan);
               check=true;
      }
    }
    if(check=false){
        printf("\nKhong the cap nhat sinh vien");
    }
}
int main(){
    int n;
    char TenTep[50]="SinhVien.txt";
    SinhVien *sv;
    DocFile(&sv,n,TenTep);
    LIST l;
    ThemNodeVaoList(l,n,sv);
    Duyet_List(l);

    FILE *f=fopen("KetQuaSV.txt","w");
    GhiRaFile(l,f);

    // BoXungSinhVien(l);
    // Duyet_List(l);


    int Ma;
    printf("\nSinh Vien Co Ma Can Xoa :");
    scanf("%d",&Ma);
    XoaNodeKhoaBatKy(l,Ma);
    Duyet_List(l);
    return 0;
}