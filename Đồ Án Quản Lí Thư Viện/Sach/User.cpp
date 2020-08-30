#include "User.h"
#include <time.h>
#include "Sach.h"

User::User()
{
	userName = "";
	name = "";
	pass = "";	
	age = 0;
}


User::~User()
{
	userName = "";
	name = "";
	pass = "";
	age = 0;
}


string User::GetUsername()
{
	return userName;
}

void User::SetUsername(string& username)
{
	this->userName = username;
}

string User::GetPass()
{
	return pass;
}

void User::SetPass(string& pass)
{
	this->pass = pass;
}

string User::GetName()
{
	return name;
}

void User::SetName(string& name)
{
	this->name = name;
}

int User::Getage()
{
	return age;
}

void User::Setage(int& age)
{
	this->age = age;
}

void User::Buy(ListSach& listsach)
{

	this->listHoaDon.Buy(listsach);

}

void User::BuyBook(ListSach& listsach, Sach& sach)
{
	HoaDon hoadon;
	int a = hoadon.Add(sach);
	if (a == 0)
	{
		string b = sach.GetMaSach();
		this->listHoaDon.Add(hoadon);
		vector <Sach> ::iterator it;
		it = TimMaSach(listsach, b);
		int n = it->GetSo();
		n = n + hoadon.soLuong;
		it->SetSo(n);
	}
	cout << endl;
	int lenh;
	cout << "1. Mua Tiep" << endl;
	cout << "2. Quay Lai" << endl;
	cout << "Moi Ban Chon: ";
	cin >> lenh;
	cin.ignore();
	if (lenh == 1)
		this->Buy(listsach);
}

string User::GetClassName()
{
	return "User";
}

void User::CapNhatDonHang()
{
	string mas;
	cout << "Nhap Ma Sach Cap Nhat: ";
	cin >> mas;
	HoaDon hd;
	bool True = false;
	vector<HoaDon>::iterator it;
	for (it = listHoaDon.vectorHoaDon.begin(); it != listHoaDon.vectorHoaDon.end(); it++)
	{
		if (it->sach.GetMaSach() == mas)
		{
			hd = *it;
			True = true;
		}
	}
	if (!True)
	{
		cout << "Khong Co Sach Nay" << endl;
		return;
	}
	int n;
	cout << "1. Cap Nhat So Luong" << endl;
	cout << "2. Xoa Hoa Don" << endl;
	cout << "Moi Ban Chon: ";
	cin >> n;
	cin.ignore();
	switch (n)
	{
	case 1:
		int sl;
		cout << "Nhap So Luong: ";
		cin >> sl;
		listHoaDon.CapNhatSoLuong(hd, sl);
		break;
	case 2:
		listHoaDon.XoaHoaDon(hd);
		break;
	default:
		break;
	}
}

void User::InDonHang()
{
	string b = userName + ".hoadon.txt";
	listHoaDon.InHoaDon(b);
}

void User::CreatAccount(vector <User> &a)
{
	fstream f;
	f.open("User.txt", ios::out | ios::app);
	cout << "Nhap Username: ";
	vector<User>::iterator it;
	string c = "";
	int dem = 0;
	do 
	{
		cin >> c;
		for (it = a.begin(); it != a.end(); it++)
		{
			if (c == it->GetUsername())
			{
				cout << "Username da ton tai, moi nhap lai username : ";
				dem = 1;
				break;
			}
			else dem = 0;
		}
	} while (dem == 1);
	this->userName = c;
	cout << "Nhap Mat Khau: ";
	cin >> this->pass;
	cin.ignore();
	cout << "Nhap Ten: ";
	getline(cin, this->name);
	cout << "Nhap Tuoi: ";
	cin >> this->age;
	cin.ignore();
	f << this->GetUsername() << "\t" << this->GetPass() << "\t" << age << "\t" << this->GetName() << "\n";
	f.close();
}

void User::CreatAccount2(vector <User>& a)
{
	fstream f;
	f.open("User.txt", ios::out | ios::app);
	cout << "Nhap Username: ";
	vector<User>::iterator it;
	string c = "";
	cin.ignore();
	int dem = 0;
	do
	{
		cin >> c;
		for (it = a.begin(); it != a.end(); it++)
		{
			if (c == it->GetUsername())
			{
				cout << "Username da ton tai, moi nhap lai username : ";
				dem = 1;
				break;
			}
			else dem = 0;
		}
	} while (dem == 1);
	this->userName = c;
	cout << "Nhap Mat Khau: ";
	cin >> this->pass;
	cin.ignore();
	cout << "Nhap Ten: ";
	getline(cin, this->name);
	cout << "Nhap Tuoi: ";
	cin >> this->age;
	cin.ignore();
	f << this->GetUsername() << "\t" << this->GetPass() << "\t" << age << "\t" << this->GetName() << "\n";
	f.close();
}

const std::string currentDateTimE()
{
	time_t     now = time(0);
	struct tm  tstruct;
	char       buf[80];
	tstruct = *localtime(&now);
	strftime(buf, sizeof(buf), "%Y-%m-%d.%X", &tstruct);

	return buf;
}

void User::SendMessage()
{
	fstream f;
	string m;
	string n = currentDateTimE();
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
			f << p << "      :: send by User: " << userName << " in " << n << endl;
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
			f << p << "      :: send by User: " << userName << " in " << n << endl;
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
			f << p << "      :: send by User: " << userName << " in " << n << endl;
		}
		else if (lenh == 4)
		{
			f.open("admin.mess.txt", ios::out | ios::app);
			string p;
			cout << "NHAP MESSAGE: " << endl;
			getline(cin, p);
			f << p << "      :: send by User: " << userName << " in " << n << endl;
		}
		else if (lenh == 0)
			break;
	} while (lenh != 0);
	f.close();
}



void DocThongBao()
{
	fstream f;
	f.open("Thongbao.txt", ios::in);
	string a;
	while (!f.eof())
	{
		getline(f, a);
		cout << a << endl;
	}
}

void User::DocThu()
{
	fstream f;
	string b;
	b = userName + ".user.mess.txt";
	f.open(b, ios::in);
	string a;
	while (!f.eof())
	{
		getline(f, a);
		cout << a << endl;
	}
}

void User::Xuat()
{
	string a;
	a = this->GetPass();
	int n = a.length();
	char *b = new char;
	for (int i = 0; i < n; i++)
	{
		b[i] = '*';
	}
	b[n] = '\0';
	cout << this->GetUsername() << "\t" << b << "\t" << age << "\t" << this->GetName() << "\n";
}
