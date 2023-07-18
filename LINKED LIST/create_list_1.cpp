#include <stdio.h>
#include <math.h>
// tao cấu trúc một nút  
struct Node {
	int data;
	struct Node *next;// địa chỉ dùng để liên kết csc nút
};
typedef struct Node NODE;// minh co the dung o bat cu dau trrog chương trình 
// khai bao cau tuc mot líst 
struct list {
	NODE *Head;
	NODE *Tail;
};
// khoi tao mot list chua trỏ đến đâu 
void khoi_tao_list (list &l){
	// hai gia tri con tro hua lien ket den phan tu nao 
	l.Head=NULL;
	l.Tail=NULL;
}
NODE* khoi_tao_1_node(int x){
	// cap phat bo nho cho con trô lien ket node 
	NODE*p=(NODE *) malloc (sizeof(NODE));
	if(p==NULL){
		printf("\nKhong the cap phat vung no cho 1 node .");
		exit(1);
	}
	p->data=x;
	
	p->next=NULL;// chua có node nào nên point của node đó =NULL
	return p;// trả vè con tro dang tro den node chua gia tri x
}
// thêm một node vào dau danh sach 
void them_vao_dau(list &l,NODE *p){// con trỏ trỏ đến node đầu
// kiem tra danh sach dang rong,cac con tro chua tro den dau
	if(l.Head==NULL){
		l.Head=l.Tail=p;	//=NULL
	}
	else {
		p->next=l.Head;// cập nhật giá trị địa chỉ của node tiếp theo trong danh sách là 
		//gt địa chỉ của node tiếp theo của node đầu trong danh sách 
		// cap nhat node dau là node vua them vô 
		l.Head=p;
	}
}
// thêm vào cuối danh sach 
void them_vao_cuoi(list &l ,NODE *p){// con tro tro den node cuoi
	// kiem tra danh sach dang rong,cac con tro chua tro den dau
	if(l.Head==NULL){
		l.Head=l.Tail=p;	//=NULL
	}
	else {
		// l.Tail-> next chính là mối liên kết của node cuối 
	   l.Tail->next=p;// cho mối liên kết(con trỏ pTail) của node cuối bây giờ là mối liên kết 
	   // của node vừa thêm
	   // cập nhật node cuối bây giờ là node vừa thêm
	   //(con trỏ node cuối bây giờ chính là con trỏ của node vừa thêm  
	   l.Tail=p;
	}
}
void nhap_node(list &l,int &x,int n){
	for (int i=1;i<=n;i++){
		printf("\nGia tri cua node thu %d:",i);
		scanf("%d",&x);
	   	// p là con tro đại diện cho node đang muốn thêm vào 
	   NODE *p=khoi_tao_1_node(x);
		them_vao_cuoi(l,p);// thêm node vừa tạo vào đầu 
	 }
}
// in thì gia tri khong can thay doi nua ne khong can truyen tham chieu 
void printf_list(list l){
	for (NODE *i=l.Head;i!= NULL;i=i->next){// duyệt qua tung moi noi,bat dau tu moi noi dau tien ,vôi k la con tro)
	// k la con tro tro den tung phan tu trong node 
		printf("%d ",i->data);
	}
}
void max_list (list l){
	// ta luôn cho giá trị max bằng giá trị của list đầu tiên trong mảng  
	int max=l.Head->data;// 
 // i là con trỏ chạy từ mối liên kết thứ hai(vì ta đặt max ở mối liên kết đầu rồi) đến mối liên kết cuối cùng  
	for (NODE *i=l.Head->next;i!=NULL;i=i->next){
		if(max<i->data){
			max=i->data;
		}
	}
	printf("\nGia tri max cua node la:%d.",max);
}
int main (){
	int n, x;
    printf("Nhap so luong node: ");
    scanf("%d", &n);
    list l;
    khoi_tao_list(l);
    nhap_node(l, x, n);
    printf_list(l);
    max_list(l);
    return 0;
}
	
	

