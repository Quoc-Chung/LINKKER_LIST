#include <stdio.h>
#include <math.h>
// tạo struct của one node (data và point)
struct Node{
	int data;//  giá trị của node ==>lưu giá trị các số nguyên
	struct Node *next;// point linkedd node
	// create linked node  
};
//typedef struct Node NODE// define struct Node lúc này là NODE
// declared struct in linked list 
// tạo một nút trong danh sách liên kết 
struct Node *create_node(int x){// have "*name_function"==>return point 
	struct Node *p = (struct Node *) malloc (sizeof(struct Node ));// cấp phát bộ nhớ động cho một nút trong danh sách 
	if(p==NULL){
		printf("\nKhong cap phat duoc bo nho cho 1 node");
		exit(1);
	}
	// khởi tạo các giá trị cho một node 
	p->data=x;// khởi tạo giá trị của node là x
	p->next=NULL;// thiết lập con trỏ của một node == NULL; tức là nó chưa trỏ đến đâu, đảm bảo không truy cập đến vùng nhớ không xác định 
    return p;// trả về node vừa khởi tạo 
}
// hàm  khởi tạo danh sách liên kết đơn với nhiều số nguyên 
struct Node *linked_list(int start,int n){// truyền tham chiếu để lưu sự thay đổi của các nodde trong hàm khởi tạo 
	// cho hai node trỏ đến null vì danh sách liên kết đơn chưa có phần tử nào liên kết
	struct Node *pHead=NULL;
	struct Node *pTail=NULL;
    // tạo node đầu tiên và gán cho con trỏ head 
    pHead=create_node(start);
    
    pTail=pHead;
    //tạo các nút liên kết giữa chúng 
    for (int i=start+1;i<=n;i++){
    	struct Node *p = create_node(i);// tạo nút mới  i và trỏ con trỏ p đến nút này 
    	pTail->next=p;//cho con trỏ đang trỏ đến địa chỉ ở vị trí cuối  trỏ đến biến thành con trỏ liên kết
//		 và cũng như biến con trỏ này thành con trỏ ở nút đầu tiên 
    	pTail=p;// con trỏ cuối lúc này biến thành con trỏ mới tạo và thực hiện lặp lại ...
	}
	return pHead;// trả về địa chỉ đầu tiên của con trỏ để tí in ra danh sách sẽ lấy địa chỉ này làm mốc 
// in ra các giá trị trong danh sách liên kết đơn 
}
void printf_list(struct Node *pHead){// truyền vào địa chỉ của list vừa tạo 
	struct Node *pTail =pHead;//làm lại việc cho con trỏ cuối của danh sách thành con trỏ đầu của danh sách 
	while (pTail!=NULL){
		printf("%d ",pTail->data);
		pTail=pTail->next;
	}  
}
void printf_list1(struct Node *pHead){// truyền vào địa chỉ của list vừa tạo 
	struct Node *p_list = pHead;//làm lại việc cho con trỏ cuối của danh sách thành con trỏ đầu của danh sách 
	while (p_list!=NULL){// con trỏ không trỏ đến đâu 
		printf("%d ",p_list->data);
		p_list=p_list->next;
	}  
}
int main (){
	struct Node *pHead=linked_list(1,10);
	// in ra danh sách liên kết đơn 
	printf_list1(pHead);
	return 0;
}