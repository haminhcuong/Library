#define _CRT_SECURE_NO_WARNINGS
#include "ListHoaDon.h"
#include <time.h>


ListHoaDon::ListHoaDon()
{
	result = 0;
}


ListHoaDon::~ListHoaDon()
{
}

void ListHoaDon::Add(HoaDon& hoadon)
{
	vectorHoaDon.push_back(hoadon);
}

void ListHoaDon::CapNhatTien()
{
	result = 0;
	vector<HoaDon> ::iterator it;
	for (it = vectorHoaDon.begin(); it != vectorHoaDon.end(); it++)
	{
		result += (*it).tien;
	}
}

const std::string currentDatETimE()
{
	time_t     now = time(0);
	struct tm  tstruct;
	char       buf[80];
	tstruct = *localtime(&now);
	strftime(buf, sizeof(buf), "%Y-%m-%d.%X", &tstruct);

	return buf;
}

void ListHoaDon::InHoaDon(string path)
{
	fstream f;
	f.open(path, ios::out | ios::app);
	cout << endl;
	cout << ">>>>>>>>>> XUAT HOA DON <<<<<<<<<<" << endl;
	vector<HoaDon> ::iterator it;
	for (it = vectorHoaDon.begin(); it != vectorHoaDon.end(); it++)
	{
		cout << *it;
	}
	CapNhatTien();
	cout << "Tong Tien: " << result << endl;
	string time = currentDatETimE();
	for (it = vectorHoaDon.begin(); it != vectorHoaDon.end(); it++)
	{
		f << *it;
		
	}
	f << ",";
	f << result << "\t##########\n";
	f.close();
}

void ListHoaDon::AddListHoaDon(string username)
{
	ifstream f;
	string path;
	path = username + ".hoadon.txt";
	f.open(path, ios::in);
	while (!f.eof())
	{
		string dulieu;
		int tongtien;
		string tap;
		getline(f, dulieu, ',');
		f >> tongtien;
		getline(f, tap, '\n');
		HoaDon hoadon;
		hoadon.duLieu = dulieu;
		hoadon.tongTien = tongtien;
		vectorHoaDon.push_back(hoadon);
	}
	f.close();
}



void ListHoaDon::Buy(ListSach& lishsach)
{
	int n;
	do
	{
		Sach sach = HoaDon::TimSach(lishsach);
		HoaDon hoadon;
		int a = hoadon.Add(sach);
		if (a == 0)
		{
			this->Add(hoadon);
		}
		cout << endl;
		cout << "1. Mua Tiep" << endl;
		cout << "2. Quay Lai" << endl;
		cout << "Moi Ban Chon: ";
		cin >> n;
		cin.ignore();
	} while (n == 1);
}

void ListHoaDon::XoaHoaDon(HoaDon& hd)
{
	vector<HoaDon>::iterator it;
	for (it = vectorHoaDon.begin(); it != vectorHoaDon.end(); it++)
	{
		if (it->sach.GetMaSach() == hd.sach.GetMaSach())
		{
			vectorHoaDon.erase(it);
			return;
		}
	}
}

void ListHoaDon::CapNhatSoLuong(HoaDon& hd, int& soLuong)
{
	vector<HoaDon>::iterator it;
	for (it = vectorHoaDon.begin(); it != vectorHoaDon.end(); it++)
	{
		if (it->sach.GetMaSach() == hd.sach.GetMaSach())
		{
			it->soLuong = soLuong;
			it->CapNhatTien();
		}
	}
}
