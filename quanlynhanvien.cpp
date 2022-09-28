#include <iostream>
#include <string.h>
#include <stdio.h>
using namespace std;
struct Date
{
	int ngay;
	int thang;
	int nam;
};
struct NV
{
    int id;
	char ten[30];
	Date ngaysinh;
	float luong;
	char gt[4];
	char diachi[100];
};

void inputDate(Date date);
void printDate(Date date);
struct Node
{
    NV *data;
    Node *pNext;
};
struct SingleList
{
    Node *pHead;
    Node *pTail;
};
void Initialize(SingleList *&list)
{
    list=new SingleList;
    list->pHead=NULL;
    list->pTail=NULL;
}
bool laNamNhuan(int nYear)
{
	if ((nYear % 4 == 0 && nYear % 100 != 0) || nYear % 400 == 0)
	{
		return true;
	}
	return false;
}
int DayOfMonth(int nMonth, int nYear)
{
	int nNumOfDays;

	switch (nMonth)
	{
	case 1:
	case 3:
	case 5:
	case 7:
	case 8:
	case 10:
	case 12: 
		nNumOfDays = 31;
		break;
	case 4:
	case 6:
	case 9:
	case 11: 
		nNumOfDays = 30;
		break;
	case 2:
		if (laNamNhuan(nYear))
		{
			nNumOfDays = 29;
		}
		else
		{
			nNumOfDays = 28;
		}
		break;
	}

	return nNumOfDays;
}
bool DayHL(int nDay, int nMonth, int nYear)
{
	if (nYear < 0)
	{
		return false; 
	}
	if (nMonth < 1 || nMonth > 12)
	{
		return false; 
	}
	if (nDay < 1 || nDay > DayOfMonth(nMonth, nYear))
	{
		return false; 
	}
	return true; 
}
void inputDate(Date date)
{
	cout<<"Nhap ngay/thang/nam:";
	cin>>date.ngay>>date.thang>>date.nam;
	if (DayHL(date.ngay,date.thang,date.nam)!=true)
	{
		cout<<"Loi! Moi nhap lai ngay/thang/nam:";
		cin>>date.ngay>>date.thang>>date.nam;
	}
}
void printDate(Date date)
{
	cout<<date.ngay <<"/"<<date.thang<<"/"<<date.nam<<"\t";
}
NV *NhapNV()
{
    
    NV *nv=new NV;
    cout<<"Nhap MSNV: ";
    cin>>nv->id;	
    cin.ignore();
    cout<<"Nhap ho va ten: ";
    gets(nv->ten);
    inputDate(nv->ngaysinh);
	cout<<"Nhap gioi tinh(Nam/Nu): ";
    cin>>nv->gt;
  	cout<<"Luong nhan vien: ";
  	cin>>nv->luong;
    cin.ignore();
    cout<<"Nhap dia chi nhan vien: ";
    gets(nv->diachi);
    return nv;
}
Node *CreateNode(NV *nv)
{
    Node *pNode=new Node;
    if(pNode!=NULL)
    {
        pNode->data=nv;
        pNode->pNext=NULL;
    }
    else
    {
        cout<<"Cap phat bo nho that bai!!!"<<endl;
    }
    return pNode;
}
void InsertLast(SingleList *&list,NV *nv)
{
    Node *pNode=CreateNode(nv);
    if(list->pHead==NULL)
    {
        list->pHead=pNode;
    }
    else
    {
        Node *pTmp=list->pHead;
         
        while(pTmp->pNext!=NULL)
        {
            pTmp=pTmp->pNext;
        }
        pTmp->pNext=pNode;
    }
}
void PrintList(SingleList *list)
{
    Node *pTmp=list->pHead;
    cout<<"MANV"<<"\t"<<"HO VA TEN"<<"\t"<<"NGAY SINH"<<"\t"<<"GIOI TINH"<<"\t"<<"LUONG"<<"\t\t"<<"DIACHI"<<"\n";
    if(pTmp==NULL)
    {
		cout<<"Danh sach rong !!";
        return;
    }
    while(pTmp!=NULL)
    {	
        NV *nv=pTmp->data;
        cout<<nv->id<<"\t";
		cout<<nv->ten<<"\t";
		printDate(nv->ngaysinh);cout<<"t";
		cout<<nv->gt<<"\t\t";
		cout<<nv->luong<<"\t\t";
		cout<<nv->diachi<<"\n";
        pTmp=pTmp->pNext;
    }
}
void SortListID(SingleList *&list)
{
    for(Node *pTmp=list->pHead;pTmp!=NULL;pTmp=pTmp->pNext)
    {
        for(Node *pTmp2=pTmp->pNext;pTmp2!=NULL;pTmp2=pTmp2->pNext)
        {   
            if(pTmp->data->id>pTmp2->data->id)
            {
               swap(pTmp->data,pTmp2->data);              
            }
        }
    }
}
void SortListName(SingleList *&list)
{
   	Node* p, * q, * min;
	p = list->pHead;
	while (p != list->pTail)
	{
		min = p;
		q = p->pNext;
		while (q != NULL)
		{
			if(strcmp(strupr(q->data->ten), strupr(p->data->ten)) < 0)
				min = q;
			q = q->pNext;
		}
		swap(min->data, p->data);
		p = p->pNext;
	}
}
void SelectionSort(SingleList *& l)
{
	Node* p, * q, * min;
	p = l->pHead;
	while (p != l->pTail)
	{
		min = p;
		q = p->pNext;
		while (q != NULL)
		{
			if (q->data->luong < p->data->luong)
				min = p;
			q = q->pNext;
		}
		swap(min->data,p->data);
		p = p->pNext;
	}
}
void find(SingleList *&list,int ma)
{
    Node *p;
    int dem=0;
    p=list->pHead;
    cout<<"MANV"<<"\t"<<"HO VA TEN"<<"\t"<<"NGAY SINH"<<"\t"<<"GIOI TINH"<<"\t"<<"LUONG"<<"\t\t"<<"DIACHI"<<"\n";
    while (p!=NULL)
    {
        if(ma==p->data->id)
		{      
        	cout<<p->data->id<<"\t";
			cout<<p->data->ten<<"\t";
			printDate(p->data->ngaysinh);
			cout<<p->data->gt<<"\t\t";
			cout<<p->data->luong<<"\t\t";
			cout<<p->data->diachi<<"\n";
 			dem++;
	}
        p=p->pNext;
    }
    if (dem==0) cout<<"Khong tim thay nhan vien nao !!"<<endl;
}
void RemoveNode(SingleList *&list,int id)
{
    Node *pDel=list->pHead;
    if(pDel==NULL)
    {
        cout<<"Danh sach rong!"<<endl;
    }
    else
    {
        Node *pPre=NULL;
        while(pDel!=NULL)
        {
            NV *nv=pDel->data;
            if(nv->id==id)
                break;
            pPre=pDel;
            pDel=pDel->pNext;
        }
        if(pDel==NULL)
        {
            cout<<"khong tim thay MSNV: "<<id;
        }
        else
        {
            if(pDel==list->pHead)
            {
                list->pHead=list->pHead->pNext;
                pDel->pNext=NULL;
                delete pDel;
                pDel=NULL;
            }
            else
            {
                pPre->pNext=pDel->pNext;
                pDel->pNext=NULL;
                delete pDel;
                pDel=NULL;
            }
        }
    }
}
void DestroyList(SingleList *&l)
{
	Node* p = l->pHead;
	while (l->pHead != NULL)
	{
		l->pHead = p->pNext;
		delete p;
		p = l->pHead;
	}
}
int main() {
    SingleList *list;
    Initialize(list);
    int n;
    cout << "======Danh Sach Chuc Nang=========\n";
    cout << "1 => Nhap nhan vien moi \n";
    cout << "2 => In danh sach nhan vien \n";
    cout << "3 => Sap xep theo ID \n";
    cout << "4 => Sap xep danh sach theo ten \n";
    cout << "5 => Sap xep danh sach theo luong \n";
    cout << "6 => Tim kiem nhan vien theo ID \n";
    cout << "7 => Xoa nhan vien theo ID .\n";
    cout << "8 => Xoa danh sach \n";
    cout<<	"0 ==> Thoat chuong trinh \n";
    cout<<	"===================================\n";
    while(1)
    {
    	cout << "\nNhap chuc nang ban chon: ";
		cin >> n;
		if(cin.fail() || n<0 ||n>8)
	{
		cout<<"Loi!! Moi nhap lai: "<<endl;
		cin.clear();
		cin.ignore();
	}
	else
	{
		if (n == 1) {
			int sl;
			cout<<"Nhap so luong nhan vien can nhap:";
			cin>>sl;
			while (sl>0)
			{
				cout << "Moi Ban nhap thong tin nhan vien : \n";
				NV *teo=NhapNV();
    			InsertLast(list,teo);
    			sl--;
    		}
    	}
    	if (n == 2)
    	{
    		cout << "\nIn danh sach nhan vien.\n ";
    		PrintList(list);
		}
		if (n == 3) {
			SortListID(list);
			cout<<"\nDanh sach nhan vien duoc sap xep theo ID: \n";
			 PrintList(list);
		}
    	if (n==6)
		{
			int ma;
			cout<<"\nNhap ma nhan vien can tim kiem: ";
			cin>>ma;
			cout<<"Tim kiem sinh vien theo ma so.\n";
			find(list,ma);
		}	
		if (n==7)
		{
			int ma1;
			cout<<"Nhap ma so nhan vien can xoa:";
			cin>>ma1;
			cout<<"\nXoa nhan vien theo ID: ";
			RemoveNode(list,ma1);
			cout<<"\nSau khi xoa:\n";
    		PrintList(list);
		}
		if (n==4)
		{
			cout<<"\nSap xep theo ten"<<endl;
			SortListName(list);
			PrintList(list);
		}
		if (n==5)
		{
			cout<<"\nSap xep theo luong"<<endl;
			SelectionSort(list);
			PrintList(list);
		}
		if (n==8)
		{
			cout<<"\nXoa danh sach\n"<<endl;
			DestroyList(list);
		}
		if(n==0)
		{
			cout<<"\nThoat chuong trinh. Cam on ban da su dung. Chuc ban mot ngay vui!!\n";
			break;
		}
}
}
}
