#include<bits/stdc++.h>
using namespace std;
/*
Nhập danh sách Queue chưa các số nguên ,sau đó xuất ra  màn 
hình các giá trị số nguyên đó.
*/
// Khai báo cấu trúc NODE
struct Node{
    int data;
    struct Node *pNext;
}; typedef struct Node NODE;

//Khai báo cấu trúc queue
struct Queue{
    // dùng con trỏ đầu và cuối  quản lí Queue
    NODE *pHead;
    NODE *pTail;
}; typedef struct Queue QUEUE;

// Khởi tạo strack
void KhoiTaoQueue(Queue &q){
    q.pHead=NULL;
    q.pTail=NULL;
}

//======= KIỂM TRA QUEUE CÓ RỖNG HAY KHÔNG =======
bool IsEmpty(Queue q){
    //Nếu danh sách rỗng 
    if(q.pHead ==NULL){
        return true;
    }
    return false; //Danh sách có  phần tử 
}

// =====  THÊM ĐỐI TƯỢNG VÀO ĐẦU QUEUE .FIFO============
NODE* KhoiTaoNode(int x){
    NODE *p=(NODE *) malloc(sizeof(NODE));
    if(p==NULL){
        printf("\nKhong khoi tao duoc NODE.");
        exit(0);
    }
    p->data=x;
    p->pNext=NULL;
    return p;
}

bool ThemNodeVaoQueue(QUEUE &q,NODE *p){
    // p Khởi tạo không thành công 
    if(p==NULL){
        return false;
    }
    if(IsEmpty(q)==true){
    // p chính là NODE đầu và là NODE cuối 
      q.pHead=q.pTail=p;
    }
    // Danh Sách  đã có phần tử (THÊM VÀO CUỐI  )
    else{
     q.pTail->pNext=p;
     q.pTail=p;
    }
    return true;
}
//=======LẤY RA PHẦN TỬ ĐẦU QUEUE VÀ HỦY NÓ ĐI=======
bool POP(QUEUE &q,int &x){
  //Nếu danh sach rỗng 
  if(IsEmpty(q)){
    return false;
  }
  else{
    //XÓA ĐẦU DANH SÁCH
    NODE *p=q.pHead;// Lấy phần tử đầu
    x=p->data;// Gán giá trị top vào biến x
    q.pHead=q.pHead->pNext;
    delete p;
  }
  return true;
}
//====XEM THONG TIN ĐẦU QUEUE MÀ KHÔNG  HỦY NÓ ĐI=======
bool TOP(QUEUE &q,int &x){
    if(IsEmpty(q)==true){
        return false;
    }
    x=q.pHead->data; //Gán giá trị của phần tử đầu QUEUE vào x
    return true;// lấy ra thành công 
}

// Hàm xuất danh sách stack
void XuatStack(QUEUE q){
    // Danh sách còn phần tử 
    while (IsEmpty(q)==false){
       int x;
       POP(q,x);
       cout <<x<<" ";
    } 
}
//Hàm nhập danh sách cách số nguyên 
void NhapQueue(QUEUE &q){
    int luachon;
    while(true){
        cout <<"\n\n=============MENU==========";
        cout <<"\nT1. Them Phan Tu Vao QUEUE";
        cout <<"\nT2.Xuat Danh Sach QUEUE Ra Man Hinh.";
        cout <<"\nT3.Xem Phan Tu Vao QUEUE.";
        cout <<"\nT4.Ket Thuc.";
        cout <<"\n=============END=============";
        cout <<"\nNhap lua chon:";
        cin>> luachon;
        if(luachon==1){
            int x;
            cout<<"\nNhap phan tu can them:";
            cin>>x;
            NODE*p=KhoiTaoNode(x);
            ThemNodeVaoQueue(q,p);
        }
        else if(luachon==2){
            XuatStack(q);
        }
        else if(luachon==3){
          int x;
          TOP(q,x);
          cout <<"\nPhan Tu Dau Stack"<<x<<" ";
        }
        else{
            break;
        }

    }
}
int main (){
  QUEUE q;
  KhoiTaoQueue(q);
  NhapQueue(q);
  cout <<endl;
  system("pause");

}