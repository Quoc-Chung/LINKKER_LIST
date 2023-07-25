#include<bits/stdc++.h>
using namespace std;
/*
Nhập danh sách stack chưa các số nguên ,sau đó xuất ra  màn 
hình các giá trị số nguyên đó.
*/
// Khai báo cấu trúc NODE
struct Node{
    int data;
    struct Node *pNext;
}; typedef struct Node NODE;

//Khai báo cấu trúc stack 
struct Stack{
    NODE *pTop;// dùng con trỏ đầu quản lí stack
}; typedef struct Stack STACK;

// Khởi tạo strack
void KhoiTaoStack(STACK &s){
    s.pTop =NULL;
}

//======= KIỂM TRA STACK CÓ RỖNG HAY KHÔNG =======
bool IsEmpty(STACK s){
    //Nếu danh sách rỗng 
    if(s.pTop ==NULL){
        return true;
    }
    return false; //Danh sách có  phần tử 
}

// =====  THÊM ĐỐI TƯỢNG VÀO ĐẦU STACK .LIFO============
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
bool ThemNodeVaoStack(STACK &s,NODE *p){
    // p Khởi tạo không thành công 
    if(p==NULL){
        return false;
    }
    if(IsEmpty(s)==true){
        s.pTop=p;//NODE p chính là Node đầu Stack
    }
    // Danh Sách  đã có phần tử (THÊM VÀO ĐẦU )
    else{
      p->pNext=s.pTop;
      s.pTop=p;  
    }
    return true;
}
//=======LẤY RA PHẦN TỬ ĐẦU STACK VÀ HỦY NÓ ĐI=======
bool POP(STACK &s,int &x){
  //Nếu danh sach rỗng 
  if(IsEmpty(s)){
    return false;
  }
  else{
    //XÓA ĐẦU DANH SÁCH
    NODE *p=s.pTop;// Lấy phần tử đầu
    x=p->data;// Gán giá trị top vào biến x
    s.pTop=s.pTop->pNext;
    delete p;
  }
  return true;
}
//====XEM THONG TIN ĐẦU STACK MÀ KHÔNG  HỦY NÓ ĐI=======
bool TOP(STACK &s,int &x){
    if(IsEmpty(s)){
        return false;
    }
    x=s.pTop->data; //Gán giá trị của phần tử đầu stack vào x
    return true;// lấy ra thành công 
}

// Hàm xuất danh sách stack
void XuatStack(STACK s){
    // Danh sách còn phần tử 
    while (IsEmpty(s)==false){
       int x;
       POP(s,x);
       cout  <<x<<" ";
    } 
}
//Hàm nhập danh sách cách số nguyên 
void NhapStack(STACK &s){
    int luachon;
    while(true){
        cout <<"\n\n=============MENU==========";
        cout <<"\nT1. Them Phan Tu Vao Stack";
        cout <<"\nT2.Xuat Danh Sach Stack Ra Man Hinh.";
        cout <<"\nT3.Xem Phan Tu Vao Stack.";
        cout <<"\nT4.Ket Thuc.";
        cout <<"\n=============END=============";
        cout <<"\nNhap lua chon:";
        cin>> luachon;
        if(luachon==1){
            int x;
            cout<<"\nNhap phan tu can them:";
            cin>>x;
            NODE*p=KhoiTaoNode(x);
            ThemNodeVaoStack(s,p);
        }
        else if(luachon==2){
            XuatStack(s);
        }
        else if(luachon==3){
          int x;
          TOP(s,x);
          cout <<"\nPhan Tu Dau Stack"<<x<<" ";
        }
        else{
            break;
        }

    }
}
int main (){
  STACK s;
  KhoiTaoStack(s);
  NhapStack(s);
  cout <<endl;
  system("pause");

}