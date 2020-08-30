#include "ListSach.h"



ListSach::ListSach()
{
}


ListSach::~ListSach()
{
}

void ListSach::AddListSach(string path)
{
	ifstream f;
	f.open(path, ios::in);
	while (!f.eof())
	{
		string ten, ma, tacgia, nxb;
		int gias,so;
		f >> so;
		f.ignore();
		getline(f, ten, '\t');
		f >> ma;
		f.ignore();
		f >> gias;
		f.ignore();
		getline(f, tacgia, '\t');
		getline(f, nxb, '\n');
		Sach a;
		a.SetSo(so);
		a.SetGia(gias);
		a.SetMaSach(ma);
		a.SetTenSach(ten);
		a.tacGia = tacgia;
		a.NXB = nxb;
		vectorSach.push_back(a);
	}
	f.close();
}

void ListSach::XuatListSach()
{

	cout << endl;
	cout << "       >>>>>>>>>> XUAT SACH <<<<<<<<<<" << endl;
	vector<Sach>::iterator it;
	for (it = vectorSach.begin(); it != vectorSach.end(); it++)
	{
		it->XuatSach();
	}
}

void ListSach::ThemSach()
{
	Sach sach;
	sach.NhapSach();
	vectorSach.push_back(sach);
}

void ListSach::XoaSach(string& masach, Hiden& An)
{

	vector<Sach>::iterator it;
	it = TimMaSach(*this, masach);
	vector<Hiden>::iterator itH;
	for (itH = it->vectorHiden.begin(); itH != it->vectorHiden.end(); itH++)
	{
		if (itH->className == An.className && itH->userName == An.userName)
		{
			cout << "Ban Khong Co Quyen Xoa" << endl;
			return;
		}
	}
	vectorSach.erase(it);
}

void ListSach::SuaSach(string& masach, Hiden& An)
{
	vector<Sach>::iterator it;
	it = TimMaSach(*this, masach);
	vector<Hiden>::iterator itH;
	for (itH = it->vectorHiden.begin(); itH != it->vectorHiden.end(); itH++)
	{
		if (itH->className == An.className && itH->userName == An.userName)
		{
			cout << "Ban Khong Co Quyen Sua" << endl;
			return;
		}
	}
	cout << "1. Ten" << endl;
	cout << "2. Gia" << endl;
	cout << "Moi Ban Chon: ";
	int n;
	cin >> n;
	cin.ignore();
	string ten;
	int gia;
	switch (n)
	{
	case 1:
		cout << "Nhap Ten Moi: ";
		getline(cin, ten);
		it->SetTenSach(ten);
		break;
	case 2:
		cout << "Nhap Gia Moi: ";
		cin >> gia;
		it->SetGia(gia);
		break;
	default:
		break;
	}
}



void TimTenSach(ListSach& listsach)
{
	int count = 0;
	string ten = "";
	do
	{
		system("cls");
		cout << "Nhap ten sach can tim: ";
		getline(cin, ten);
	} while (ten == "");
	vector<Sach>::iterator pos;
	vector<Sach>::iterator it;
	for (it = listsach.vectorSach.begin(); it != listsach.vectorSach.end(); it++)
	{
		if (it->GetTenSach() == ten)
		{
			count++;
			pos = it;
		}
	}
	if (count == 0)
	{
		cout << "Khong Co Sach Nay" << endl;
		return;

	}
	if (count > 1)
	{
		string ma;
		cout << "Co Nhieu Hon Mot Cuon Sach Giong Vay" << endl;
		cout << "Vui Long Nhap Ma Sach: ";
		cin >> ma;
		pos = TimMaSach(listsach, ma);
	}

	int lenh;
	cout << "1. Xoa Sach" << endl;
	cout << "2. Cap Nhat Gia" << endl;
	cin >> lenh;
	if (lenh == 1)
	{
		listsach.vectorSach.erase(pos);
		return;
	}
	if (lenh == 2)
	{
		int gia;
		cout << "Gia Moi: ";
		cin >> gia;
		pos->SetGia(gia);
		return;
	}
	return;
}

vector<Sach>::iterator TimMaSach(ListSach& listsach, string& ma)
{
	vector<Sach>::iterator it;
	for (it = listsach.vectorSach.begin(); it != listsach.vectorSach.end(); it++)
	{
		if (it->GetMaSach() == ma)
		{
			return it;
		}
	}
}

void UpdateBookToFile(ListSach& listsach)
{
	fstream f;
	f.open("Sach.txt", ios::out);
	vector<Sach>::iterator it;
	for (it = listsach.vectorSach.begin(); it != listsach.vectorSach.end(); it++)
	{
		f << it->GetSo() << "\t" << it->GetTenSach() << "\t" << it->GetMaSach() << "\t" << it->GetGia() << "\t" << it->tacGia << "\t" << it->NXB << "\n";
	}
	f.close();
}
