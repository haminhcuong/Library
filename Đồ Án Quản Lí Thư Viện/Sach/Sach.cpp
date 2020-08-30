#include "Sach.h"



Sach::Sach()
{
	gia = -1;
	tenSach = "";
	maSach = "";
	tacGia = "";
	NXB = "";
	soLuotMua = 0;
}


Sach::~Sach()
{
	gia = -1;
	tenSach = "";
	maSach = "";
	tacGia = "";
	NXB = "";
}

void Sach::SetSo(int so)
{
	soLuotMua = so;
}

int Sach::GetSo()
{
	return soLuotMua;
}

void Sach::SetMaSach(string masach)
{
	this->maSach = masach;
}

string Sach::GetMaSach()
{
	return maSach;
}

void Sach::SetTenSach(string tensach)
{
	this->tenSach = tensach;
}

string Sach::GetTenSach()
{
	return tenSach;
}

void Sach::SetGia(int gia)
{
	this->gia = gia;
}

int Sach::GetGia()
{
	return gia;
}

void Sach::NhapSach()
{
	cout << "Nhap Ten Sach: ";
	getline(cin, tenSach);
	fflush(stdin);
	cout << "Nhap Ma Sach: ";
	fflush(stdin);
	getline(cin, maSach);
	cout << "Nhap Gia: ";
	cin >> gia;
	cin.ignore();
	cout << "Nhap Tac Gia: ";
	getline(cin, tacGia);
	cout << "Nhap Nha Xuat Ban: ";
	getline(cin, NXB);
}

void Sach::XuatSach()
{
	cout << tenSach << "\t" << maSach << "\t" << gia << "\t" << tacGia << "\t" << NXB << endl;
}

void Sach::AddHiden()
{
	Hiden An;
	cout << "1. Hiden NXB" << endl;
	cout << "2. Hiden Tac Gia" << endl;
	cout << "   Moi Ban Chon: ";
	int n;
	cin >> n;
	switch (n)
	{
	case 1:
		An.className = "NXB";
		An.userName = NXB;
		break;
	case 2:
		An.className = "TacGia";
		An.userName = tacGia;
		break;
	default:
		break;
	}

	vectorHiden.push_back(An);
}

