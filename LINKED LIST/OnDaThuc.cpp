#include<bits/stdc++.h>
using namespace std;
struct Node {
    int data;
    struct Node *pNext;
}; typedef struct Node NODE;

struct List {
    NODE *pHead;
    NODE *pTail;
}; typedef struct List LIST;

void KhoiTao(LIST &l) {
    l.pHead = NULL;
    l.pTail = NULL;
}
void ThemVaoDau(LIST &l, NODE *p) {
    if (l.pHead == NULL) {
        l.pHead = l.pTail = p;
    } else {
        p->pNext = l.pHead;
        l.pHead = p;
    }
}

void ThemVaoCuoi(LIST &l, NODE *p) {
    if (l.pHead == NULL) {
        l.pHead = l.pTail = p;
    } else {
        l.pTail->pNext = p;
        l.pTail = p;
    }
}

NODE* KhoiTaoNode(int x) {
    NODE *p = (NODE*)malloc(sizeof(NODE));
    if (p == NULL) {
        cout << "\n Khong the khoi tao duoc NODE ";
        exit(0);
    }
    p->data = x;
    p->pNext = NULL;
    return p;
}
void ThemVaoList(LIST &l, int n) {
    KhoiTao(l);
    for (int i = 0; i < n; i++) {
        int x;
        cout << "\nNhap NODE thu" << i+1 <<" : ";
        cin >> x;
        NODE *p = KhoiTaoNode(x);
        ThemVaoCuoi(l, p);
    }
}

void InDanhSach(LIST l) {
    cout << "\nDanh sach list la  :" << endl;
    for (NODE *p = l.pHead; p != NULL; p = p->pNext) {
        cout << p->data << " ";
    }
}
int main() {
    int n;
    cout << "\n Nhap n :";
    cin >> n;
    LIST l;
    ThemVaoList(l, n);
    InDanhSach(l);
    return 0;
}
