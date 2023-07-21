#include<bits/stdc++.h>

// 1: Khai báo cấu trúc dữ liệu danh sách liên kết đơn các số nguyên
struct Node {
  int data;
  struct Node *pNext;
};  typedef struct Node NODE;

struct List {
    NODE *pHead;
    NODE *pTail;
};  typedef struct List LIST;

// 2. Khởi tạo danh sách liên kết đơn
void KhoiTaoList(LIST &l){
    l.pHead=NULL;
    l.pTail=NULL;
}

// 3. Tạo Node trong danh sách
NODE* TaoNode(int x){ // x là dữ  liệu được đưa vào data
   NODE *p=(NODE *) malloc (sizeof(NODE));
   if(p==NULL){
    printf("\nKhong du bo nho de khoi tao NODE");
    exit(0);
   }
   p->data=x; // (*p).data=x
   p->pNext=NULL;
   return p;
}

// 4. Thêm Node (thêm đầu hoặc cuối)

void Them_Vao_Dau(LIST &l,NODE *p){
  //Kiem tra LIST rong khong
  if(l.pHead ==NULL ){
    l.pHead =l.pTail = p;//=NULL
  }
  else{
    p->pNext=l.pHead;  // p quăng dây để tham gia vào danh sách
    l.pHead=p ; // p chính thức đã đứng dầu danh sách
  } 
}

void Them_Vao_Cuoi(LIST &l ,NODE *p){
 //Kiem tra LIST rong khong 
 if(l.pHead ==NULL){
    l.pHead =l.pTail = p;
 }
 else{
    l.pTail->pNext=p; //l.pTail quăng dây nối với p
    l.pTail=p;  // p chính  thức  đứng cuối  danh  sách 
 }
}

// 5. Nhập dữ liệu cho danh sách
void NhapList(LIST &l,int x,int n){
 // Khởi tao list cho danh sach 
    KhoiTaoList (l);

    for(int i=0;i<n;i++){
        printf("\nNhap data NODE %d :",i+1);
        scanf("%d",&x);

        NODE *p=TaoNode(x);  // Đưa data vào Node p, tạo ra node p
        Them_Vao_Cuoi(l,p); // Them NODE p vào  cuối danh sách 
    }

}

// 6.In ra thông tin cua toan bo NODE

void ThongTin(LIST l){
    printf("\nThong tin cua toan bo NODE :\n");
    // for (  int i=0       ;    i<n    ;   i++)
       for (NODE *i=l.pHead ;   i!=NULL ; i=i->pNext){
        printf("%d ",(*i).data);
       }
} 


// 7.Tim max cua NODE
 
void Max_Node(LIST l){
    /*
	int max=INT_MIN;
	for(int i = 0; i < n; i++)
	{
		if(max <a[i])
		{
			max = a[i];
		}
	}
	*/
    int max=INT_MIN;
    for (NODE *i=l.pHead ;i !=NULL ;i=i->pNext){
        if(max < i->data){
            max=(*i).data;
        }
    }
    printf("\nMax lon nhat trong NODE :%d",max);
}

// 8. Sap Xep tang dan

void HoanVi(int &a, int &b)
{
	int Temp = a;
	a = b;
	b = Temp;
}

void Sap_Xep(LIST &l)
{
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
	for(NODE *p = l.pHead; p != l.pTail; p = p ->pNext)
	{
		for(NODE *q = p ->pNext; q != NULL; q = q ->pNext)
		{
			if(p->data > q->data)
			{
				HoanVi(p->data, q->data);
			}
		}
	}

}

int TinhSum(LIST l)
{
	int sum = 0;
	for(NODE *p = l.pHead; p != NULL; p = p ->pNext)
	{
		sum += p ->data;
	}
	return sum;
}

// 9.Them mot NODE p vao sau mot NODE q

void Them_P_Sau_Q (LIST &l, NODE *p, NODE *q){
//Dyuyet tu dau den cuoi  de  tim  NODE 
    for  (NODE  *i=l.pHead ; i!=NULL ; i=i->pNext){
        if (i->data == q->data){//Tim  thay node q
          NODE *g = i ->pNext;//  Dich chuyen NODE  i sang  mot NODE
		     	i ->pNext = p;     // Gan node i thanh node p
	    		p ->pNext = g;    // cho con tro pNext cua node  p sau NODE g voi g 
		    	return; // Kết thúc
        }  
    }

}

// 10.Xóa đầu danh  sách
void  XoaDauDanhSach (List &l){
  // Kiem  tra  NODE rỗng
  if(l.pHead==NULL){
    return;
  }
  NODE *p=l.pHead;
  l.pHead=l.pHead->pNext;//Đầu trốn  sang bên  cạnh 
  free(p);
}

// 11.Xoa cuoi  danh  sach 
void XoaCuoiDanhSach(LIST &l){
  //Kiem tra NODE rỗng 
  if(l.pHead ==NULL){
    return;
  }
  // Tim kiem NODE ở trước  NODE cuối (l.pTail)
  for (NODE *i=l.pHead ;i!=NULL ;i=i->pNext){
    if(i->pNext == l.pTail){
      free(l.pTail);
      i->pNext=NULL;
      l.pTail=i;
    }
  }
}

// 11.Xoa mot NODE sau NODE q
void XoaSau(LIST &l,NODE *q){
  // Kiem tra NODE rỗng  không  
  for (NODE *i=l.pHead ;i!=NULL ;i=i->pNext){
    // Tim thay  NODE q
    if(i->data == q->data){
         NODE *g=i->pNext;  //NODE  g ở  đây là  NODE  nam  sau NODE  i (Nằm sau  NODE  q) 
         //Cần  xóa  NODE  g
         i->pNext=g->pNext;
         free(g);
         return ;
    }
  }
}

// 12.Xoa NODE bat ki 
void  XoaNodeBatKi (LIST &l ,int data){
  //Nếu  danh  sách  rỗng thì không còn gì để  xóa  
  if(l.pHead ==NULL){
    return ;
  }
  if(l.pHead ->data ==data ){
    XoaDauDanhSach(l);
    return ;
  }
 else if(l.pTail->data ==data){
    XoaCuoiDanhSach(l);
  }
  else{
   NODE *q;
	// Nếu Node cần xóa không phải đầu hoặc cuối
	// Tìm ra Node nằm trước Node có khóa cần xóa => gọi hàm xóa Node sau cái Node vừa tìm thấy
	for(NODE *g = l.pHead; g != NULL; g = g ->pNext)
	{
    // Điều kiện này kiểm tra xem dữ liệu của nút hiện tại g có bằng data 
    // (giả sử data là giá trị cần xóa) hay không.
		if(g ->data == data)
		{
			XoaSau(l, q);
			return;
		}
		q = g;
	}
	
  }
}
void  TimKiemMotNode (LIST  &l ,int data){
  bool check=false;// ban  dầu  không tìm thấy 
  int dem=0; 
  for  (NODE *i=l.pHead ;i!=NULL ;i=i->pNext){
    if(i->data == data){
      check=true;// Tìm thay
      dem++;
      printf("\nTim Thay NODE o vi tri thu %d. ",dem);
      break;
    }
  }
  if(check=false){
    printf("\nKhong tim  thay.");
  }
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
void XoaNodeNguyenTo(LIST &l){
  for (NODE *i =l.pHead ;i!=NULL ;i=i->pNext){
    if(NguyenTo(i->data)){
      XoaNodeBatKi(l,i->data);
    }
  }
}
int main (){
  int n,x;
  printf("\nNhap so NODE :");
  scanf("%d",&n);
  LIST l;
  NhapList(l,x,n);
  ThongTin(l);
  XoaCuoiDanhSach(l);
  ThongTin(l);

  XoaNodeNguyenTo(l);
  ThongTin(l);
}




