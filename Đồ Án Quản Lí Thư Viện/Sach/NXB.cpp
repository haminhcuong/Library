
#define _CRT_SECURE_NO_WARNINGS
#include "NXB.h"
#include <time.h>


NXB::NXB()
{
	Tong = 0;
}


NXB::~NXB()
{
}

void NXB::CreatAccount(vector <NXB> &a)
{
	fstream f;
	f.open("NXB.txt", ios::out | ios::app);
	cout << "Nhap Ten Nha Xuat Ban: ";
	vector<NXB>::iterator it;
	string c = "";
	int dem = 0;
	do
	{
		getline(cin, c);
		for (it = a.begin(); it != a.end(); it++)
		{
			if (c == it->GetName())
			{
				cout << "Nha Xuat Ban da ton tai, moi nhap lai Nha Xuat Ban (Viet lien khong dau) : ";
				dem = 1;
				break;
			}
			else
			{
				dem = 0;
			}	
		}
	} while (dem == 1);

	this->Ten = c;
	cout << "Nhap Mat Khau: ";
	cin >> Pass;
	f << Ten << "\t" << Pass << "\t" << "\n";
	f.close();
}

void NXB::CreatAccount2(vector <NXB>& a)
{
	fstream f;
	f.open("NXB.txt", ios::out | ios::app);
	cout << "Nhap Ten Nha Xuat Ban: ";
	vector<NXB>::iterator it;
	string c = "";
	cin.ignore();
	int dem = 0;
	do
	{
		getline(cin, c);
		for (it = a.begin(); it != a.end(); it++)
		{
			if (c == it->GetName())
			{
				cout << "Nha Xuat Ban da ton tai, moi nhap lai Nha Xuat Ban (Viet lien khong dau) : ";
				dem = 1;
				break;
			}
			else
			{
				dem = 0;
			}
		}
	} while (dem == 1);

	this->Ten = c;
	cout << "Nhap Mat Khau: ";
	cin >> Pass;
	f << Ten << "\t" << Pass << "\t" << "\n";
	f.close();
}

string NXB::GetName()
{
	return Ten;
}

void NXB::SetName(string& name)
{
	Ten = name;
}

string NXB::GetPass()
{
	return Pass;
}

void NXB::SetPass(string& pass)
{
	Pass = pass;
}

void NXB::UpdateListSach(ListSach& l)
{
	vector<Sach>::iterator it;
	for (it = l.vectorSach.begin(); it != l.vectorSach.end(); it++)
	{
		if (it->NXB == Ten)
		{
			list.vectorSach.push_back(*it);
		}
	}
}

void NXB::XoaSach(Hiden& An)
{
	string ma;
	cout << "Nhap Ma Sach: ";
	cin >> ma;
	list.XoaSach(ma, An);
}

void NXB::ThemSach()
{
	list.ThemSach();
}

void NXB::SuaSach(Hiden& An)
{
	string ma;
	cout << "Nhap Ma Sach: ";
	cin >> ma;
	cin.ignore();
	list.SuaSach(ma, An);
}

string NXB::GetClassName()
{
	return "NXB";
}

const std::string currentDateTiME()
{
	time_t     now = time(0);
	struct tm  tstruct;
	char       buf[80];
	tstruct = *localtime(&now);
	strftime(buf, sizeof(buf), "%Y-%m-%d.%X", &tstruct);

	return buf;
}

void NXB::SendMessage()
{
	fstream f;
	string m;
	string n = currentDateTiME();
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
		cout << "| Press 4: Gui Cho Admin                |" << endl;
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
			f << p << "      :: send by NXB: " << Ten << " in " << n << endl;
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
			f << p << "      :: send by NXB: " << Ten << " in " << n << endl;
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
			f << p << "      :: send by NXB: " << Ten << " in " << n << endl;
		}
		else if (lenh == 4)
		{
			f.open("admin.mess.txt", ios::out | ios::app);
			string p;
			cout << "NHAP MESSAGE: " << endl;
			getline(cin, p);
			f << p << "      :: send by NXB: " << Ten << " in " << n << endl;
		}
		else if (lenh == 0)
			break;
	} while (lenh != 0);
	f.close();
}

void NXB::DocThu()
{
	fstream f;
	string b;
	b = Ten + ".nxb.mess.txt";
	f.open(b, ios::in);
	string a;
	while (!f.eof())
	{
		getline(f, a);
		cout << a << endl;
	}
}

void NXB::xuatSach(ListSach& list)
{
	vector <Sach>::iterator it;
	for (it = list.vectorSach.begin(); it != list.vectorSach.end(); it++)
	{
		if (this->GetName() == it->NXB)
		{
			it->XuatSach();
		}
	}
}

void NXB::Xuat()
{
	string a;
	a = this->GetPass();
	int n = a.length();
	char* b = new char;
	for (int i = 0; i < n; i++)
	{
		b[i] = '*';
	}
	b[n] = '\0';
	cout << Ten << "\t" << b << "\t" << "\n";
}

void NXB::TimSachKhongBan(ListSach list)
{
	vector <Sach> ::iterator it;
	for (it = list.vectorSach.begin(); it != list.vectorSach.end(); it++)
	{
		if (it->GetSo() == 0 && Ten == it->NXB)
		{
			it->XuatSach();
		}
	}
}

void NXB::TinhTienBanDuoc(ListSach list)
{
	vector <Sach> ::iterator it;
	for (it = list.vectorSach.begin(); it != list.vectorSach.end(); it++)
	{
		if (Ten == it->NXB)
		{
			Tong += it->GetSo() * it->GetGia();
		}	
	}
}