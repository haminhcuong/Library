#include "Admin.h"
#include <time.h>
#define _CRT_SECURE_NO_WARNINGS

Admin::Admin()
{
}


Admin::~Admin()
{
}

string Admin::GetTen()
{
	return Ten;
}

void Admin::SetTen(string& ten)
{
	Ten = ten;
}

string Admin::GetPass()
{
	return Pass;
}

void Admin::SetPass(string& pass)
{
	Pass = pass;
}

string Admin::GetClassName()
{
	return "Admin";
}

void Admin::AddHiden(ListSach& list)
{
	string maSach;
	cout << "Nhap ma sach: ";
	cin >> maSach;
	vector<Sach>::iterator it;
	for (it = list.vectorSach.begin(); it != list.vectorSach.end(); it++)
	{
		if (it->GetMaSach() == maSach)
		{
			it->AddHiden();
			return;
		}
	}
	cout << "Khong Co Ma Sach Nay";

}


const std::string currentDateTime()
{
	time_t     now = time(0);
	struct tm  tstruct;
	char       buf[80];
	tstruct = *localtime(&now);
	strftime(buf, sizeof(buf), "%Y-%m-%d.%X", &tstruct);

	return buf;
}

void GuiThongBao()
{
	fstream f;
	f.open("Thongbao.txt", ios::out | ios::app);
	cout << "Nhap Thong Bao: " << endl;
	string a;
	getline(cin, a);
	string b = currentDateTime();
	f << a << "  :: send in " << b << endl;
	f.close();
}

const std::string CUrrentDateTiME()
{
	time_t     now = time(0);
	struct tm  tstruct;
	char       buf[80];
	tstruct = *localtime(&now);
	strftime(buf, sizeof(buf), "%Y-%m-%d.%X", &tstruct);

	return buf;
}

void Admin::SendMessage()
{
	fstream f;
	string m;
	string n = CUrrentDateTiME();
	int lenh;
	do
	{
		system("cls");
		cout << "=========================================\n";
		cout << "||             SendMessage             ||" << endl;
		cout << "=========================================\n";
		cout << "_________________________________________" << endl;
		cout << "|                                       |" << endl;
		cout << "| Press 1: Gui Cho User                 |" << endl;
		cout << "| Press 2: Gui Cho Nha Xuat Ban         |" << endl;
		cout << "| Press 3: Gui Cho Tac Gia              |" << endl;
		cout << "| Press 0: Thoat                        |" << endl;
		cout << "|_______________________________________|" << endl;
		cout << "\n           Moi Ban Chon: ";
		cin >> lenh;
		cin.ignore();
		if (lenh == 1)
		{
			cout << "Nhap Vao Ten User Ban Muon Gui Tin Nhan: ";
			getline(cin, m);
			m = m + ".user.mess.txt";
			cout << "\n";
			f.open(m, ios::out | ios::app);
			string p;
			cout << "NHAP MESSAGE: " << endl;
			getline(cin, p);
			f << p << "      :: send by Admin " << " in " << n << endl;
		}
		else if (lenh == 2)
		{
			cout << "Nhap Vao Ten Nha Xuat Ban Ban Muon Gui Tin Nhan: ";
			getline(cin, m);
			m = m + ".nxb.mess.txt";
			cout << "\n";
			f.open(m, ios::out | ios::app);
			string p;
			cout << "NHAP MESSAGE: " << endl;
			getline(cin, p);
			f << p << "      :: send by Admin " << " in " << n << endl;
		}
		else if (lenh == 3)
		{
			cout << "Nhap Vao Ten Tac Gia Ban Muon Gui Tin Nhan: ";
			getline(cin, m);
			m = m + ".tacgia.mess.txt";
			cout << "\n";
			f.open(m, ios::out | ios::app);
			string p;
			cout << "NHAP MESSAGE: " << endl;
			getline(cin, p);
			f << p << "      :: send by Admin " << " in " << n << endl;
		}
		else if (lenh == 0)
			break;
	} while (lenh != 0);
	f.close();
}

void Admin::DocThu()
{
	fstream f;
	f.open("admin.mess.txt", ios::in);
	string a;
	while (!f.eof())
	{
		getline(f, a);
		cout << a << endl;
	}
}

void XuatDanhSachTaiKhoan(vector <User> a, vector <NXB> b, vector <TacGia> c)
{
	vector <User>::iterator itu;
	vector <NXB>::iterator itn;
	vector <TacGia>::iterator itt;
	cout << "Cac tai khoan User la: \n";
	for (itu = a.begin(); itu != a.end(); itu++)
	{
		itu->Xuat();
	}
	cout << endl;
	cout << "Cac tai khoan Nha Xuat Ban la: \n";
	for (itn = b.begin(); itn != b.end(); itn++)
	{
		itn->Xuat();
	}
	cout << endl;
	cout << "Cac tai khoan Tac Gia la: \n";
	for (itt = c.begin(); itt != c.end(); itt++)
	{
		itt->Xuat();
	}
}

void XuatDanhSachHoaDon(vector <User> a)
{
	vector <User> ::iterator it;
	for (it = a.begin(); it != a.end(); it++)
	{
		ListHoaDon hd;
		string b;
		b = it->GetUsername();
		hd.AddListHoaDon(b);
		hd.vectorHoaDon.pop_back();
		int dem = hd.vectorHoaDon.size();
		if (dem > 0)
		{
			cout << "Cac Hoa Don Cua " << it->GetUsername() << " La: " << endl;
			vector <HoaDon> ::iterator ith;
			for (ith = hd.vectorHoaDon.begin(); ith != hd.vectorHoaDon.end(); ith++)
			{
				ith->xuat();
			}
		}
	}
}

void XuatHoaDonNhieu(vector <NXB> a, ListSach list)
{
	vector <NXB> ::iterator it;
	NXB max = *a.begin();
	for (it = a.begin(); it != a.end(); it++)
	{
		max.TinhTienBanDuoc(list);
		it->TinhTienBanDuoc(list);
		if (max.Tong < it->Tong)
		{
			max = *it;
		}
	}
	cout << "Nha Xuat Ban Co So Tien Thanh Toan Nhieu Nhat La: ";
	cout << max.GetName() << endl;
	cout << "So tien la: " << max.Tong << endl;
}

