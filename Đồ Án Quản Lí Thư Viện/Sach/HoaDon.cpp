#include "HoaDon.h"

HoaDon::HoaDon()
{
	soLuong = 0;
	tien = 0;
}

HoaDon::~HoaDon()
{
	soLuong = 0;
	tien = 0;
}

Sach HoaDon::TimSach(ListSach& listsach)
{
	int count = 0;
	string ten = "";
	do
	{
		system("cls");
		cout << "Nhap ten sach can tim: ";
		getline(cin, ten);
	} while (ten == "");
	
	Sach sach;
	vector<Sach>::iterator it;
	for (it = listsach.vectorSach.begin(); it != listsach.vectorSach.end(); it++)
	{
		if (it->GetTenSach() == ten)
		{
			count++;
			sach = *it;
		}
	}

	if (count > 1)
	{
		string ma;
		cout << "Co nhieu sach" << endl;
		cout << "Vui long nhap ma sach: ";
		cin >> ma;
		vector<Sach>::iterator it;
		for (it = listsach.vectorSach.begin(); it != listsach.vectorSach.end(); it++)
		{
			if (it->GetMaSach() == ma)
			{
				return *it;
			}
		}
	}

	if (count > 0) return sach;

	cout << "Khong co sach nay!!!" << endl;
	return Sach();
}

int HoaDon::Add(Sach& sach)
{
	if (sach.GetMaSach() == "") return 1;
	this->sach = sach;
	cout << "Nhap so luong: ";
	cin >> this->soLuong;
	cin.ignore();
	tien = this->sach.GetGia() * soLuong;
	return 0;
}

void HoaDon::CapNhatTien()
{
	tien = sach.GetGia() * soLuong;
}

void HoaDon::xuat()
{
	cout << duLieu;
	cout << "Tong tien: " << tongTien << "\n\n";
}

ostream& operator<<(ostream& out, HoaDon hoadon)
{
	out << hoadon.sach.GetMaSach() << "\t" << hoadon.sach.GetTenSach() << "\t" << hoadon.sach.GetGia() << " * " << hoadon.soLuong << " = " << hoadon.tien << endl;
	return out;
}


