#include "Guest.h"

Guest::Guest()
{
}

Guest::~Guest()
{
}

string Guest::GetUsername()
{
	return string();
}

void Guest::SetUsername(string& username)
{
}

string Guest::GetPass()
{
	return string();
}

void Guest::SetPass(string& pass)
{
}

string Guest::GetName()
{
	return string();
}

void Guest::SetName(string& name)
{
}

int Guest::GetTuoi()
{
	return 0;
}

void Guest::SetTuoi(int& tuoi)
{
}

Sach Guest::TimSach(ListSach& listsach)
{
	int count = 0;
	string ten = "";
	cout << "Nhap Ten Sach Ban Muon Tim: ";
	getline(cin, ten);
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
		cout << "Co Nhieu Hon Mot Cuon Sach Giong Vay" << endl;
		cout << "Vui Long Nhap Ma Sach: ";
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

	cout << "Khong Co Sach Nay !!!" << endl;
	return Sach();
}

string Guest::GetClassName()
{
	return "Guest";
}

void Guest::InDonHang()
{
}

void Guest::Buy(ListSach& listsach)
{
}

void Guest::BuyBook(ListSach& listsach, Sach& sach)
{
}

void Guest::CapNhatDonHang()
{
}

void Guest::UpdateListSach(ListSach& l)
{
}

void Guest::ThemNXB()
{
}

void Guest::XoaNXB(string& name)
{
}

void Guest::ThemTacGia()
{
}

void Guest::XoaTacGia(string& name)
{
}

void Guest::ThemUser()
{
}

void Guest::XoaUser(string& username)
{
}

void Guest::XoaSach(Hiden& tkAn)
{
}

void Guest::ThemSach()
{
}

void Guest::SuaSach(Hiden& tkAn)
{
}

void Guest::XuatListSach()
{
}

void Guest::AddHiden(ListSach& listSach)
{
}

void Guest::CreatAccount()
{
}

void Guest::CreatAccount2()
{
}

void Guest::SendMessage()
{
}

void Guest::LogIn()
{
}

void Guest::DocThu()
{
}

void Guest::xuatSach(ListSach& list)
{
}

void Guest::Xuat()
{
}

void Guest::TimSachKhongBan(ListSach list)
{
}


