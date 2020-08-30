
#define _CRT_SECURE_NO_WARNINGS

#include "Sach.h"
#include "ListSach.h"
#include "HoaDon.h"
#include "ListHoaDon.h"
#include "Guest.h"
#include "User.h"
#include "Admin.h"
#include "NXB.h"
#include "TacGia.h"
#include "ListUser.h"
#include "ListNXB.h"
#include "ListTacGia.h"
#include <time.h>

void Login(Guest* &p, vector<User> a, vector<NXB> b, vector<TacGia> c);

int main()
{
	ListSach List;
	List.AddListSach("Sach.txt");
	List.vectorSach.pop_back();

	ListUser a;
	a.AddListUser("User.txt");

	ListNXB b;
	b.AddListNXB("NXB.txt");


	ListTacGia c;
	c.AddListTacGia("TacGia.txt");
	
	Guest* manage = new Guest;
	Sach sach;
	int lenh;

	do
	{
		UpdateBookToFile(List);
		if (manage->GetClassName() == "Guest")
		{
			system("cls");
			cout << "=========================================\n";
			cout << "||                MENU                 ||" << endl;
			cout << "=========================================\n";
			cout << "_________________________________________" << endl;
			cout << "|                                       |" << endl;
			cout << "| Press 1: Tim Sach                     |" << endl;
			cout << "| Press 2: Dang Nhap                    |" << endl;
			cout << "| Press 3: Dang Ki                      |" << endl;
			cout << "| Press 4: Xuat Danh Sach Sach          |" << endl;
			cout << "| Press 0: Thoat                        |" << endl;
			cout << "|_______________________________________|" << endl;
			cout << "\n           Moi Ban Chon: ";
			cin >> lenh;
			cin.ignore();
			switch (lenh)
			{
			case 1:
			{
				system("cls");
				sach.~Sach();
				sach = manage->TimSach(List);
				if (sach.GetMaSach() == "")
				{
					break;
				}
				cout << "Dang Nhap De Mua Sach!!" << endl;
				system("pause");
			}
			break;
			case 2:
			{
				Login(manage, a.vectoruser, b.vectornxb, c.vectortacgia);
				break;
			}
			case 3:
			{
				int n;
				system("cls");
				cout << "=========================================\n";
				cout << "||               Dang Ki               ||" << endl;
				cout << "=========================================\n";
				cout << "_________________________________________" << endl;
				cout << "|                                       |" << endl;
				cout << "| Press 1: User                         |" << endl;
				cout << "| Press 2: Nha Xuat Ban                 |" << endl;
				cout << "| Press 3: Tac Gia                      |" << endl;
				cout << "| Press 0: Thoat                        |" << endl;
				cout << "|_______________________________________|" << endl;
				cout << "\n           Moi Ban Chon: ";
				cin >> n;
				if (n == 1)
				{
					User* p = new User;
					p->CreatAccount2(a.vectoruser);
					a.AddListUser("User.txt");
				}
				else if (n == 2)
				{
					NXB* p = new NXB;
					p->CreatAccount2(b.vectornxb);
					b.AddListNXB("NXB.txt");
				}
				else if (n == 3)
				{
					TacGia* p = new TacGia;
					p->CreatAccount2(c.vectortacgia);
					c.AddListTacGia("TacGia.txt");
				}
				else if (n == 0)
					break;
			}
			break;
			case 4:
			{
				system("cls");
				List.XuatListSach();
				system("pause");
			}
			break;

			default:
				break;
			}
		}


		if (manage->GetClassName() == "User")
		{
			if (sach.GetMaSach() != "")
			{
				manage->BuyBook(List, sach);
				sach.~Sach();
			}
			int n;
			do
			{
				system("cls");
				cout << "=========================================\n";
				cout << "||                User                 ||" << endl;
				cout << "=========================================\n";
				cout << "_________________________________________" << endl;
				cout << "|                                       |" << endl;
				cout << "| Press 1: Dang Xuat                    |" << endl;
				cout << "| Press 2: Mua Sach                     |" << endl;
				cout << "| Press 3: Cap Nhat Don Hang            |" << endl;
				cout << "| Press 4: Xuat Danh Sach Sach          |" << endl;
				cout << "| Press 5: Gui Tin Nhan                 |" << endl;
				cout << "| Press 6: Doc Thong Bao Tu Admin       |" << endl;
				cout << "| Press 7: Hop Thu                      |" << endl;
				cout << "|_______________________________________|" << endl;
				cout << "\n           Moi Ban Chon: ";
				cin >> n;
				if (n == 1)
				{
					system("cls");
					delete manage;
					manage = new Guest;
				}
				else if (n == 2)
				{
					system("cls");
					manage->Buy(List);
					manage->InDonHang();
					system("pause");
				}
				else if (n == 3)
				{
					system("cls");
					manage->CapNhatDonHang();
					system("pause");
				}
				else if (n == 4)
				{
					system("cls");
					List.XuatListSach();
					system("pause");
				}
				else if (n == 5)
				{
					system("cls");
					manage->SendMessage();
					system("pause");
				}
				else if (n == 6)
				{
					system("cls");
					DocThongBao();
					system("pause");
				}
				else if (n == 7)
				{
					system("cls");
					manage->DocThu();
					system("pause");
				}
			} while (n != 1);
		}


		else if (manage->GetClassName() == "TacGia")
		{
			int n;
			do
			{
				system("cls");
				cout << "=========================================\n";
				cout << "||               Tac Gia               ||" << endl;
				cout << "=========================================\n";
				cout << "_________________________________________" << endl;
				cout << "|                                       |" << endl;
				cout << "| Press 1: Dang Xuat                    |" << endl;
				cout << "| Press 2: Danh Sach Sach               |" << endl;
				cout << "| Press 3: Them Sach                    |" << endl;
				cout << "| Press 4: Sua Sach                     |" << endl;
				cout << "| Press 5: Xoa Sach                     |" << endl;
				cout << "| Press 6: Gui Tin Nhan                 |" << endl;
				cout << "| Press 7: Doc Thong Bao Tu Admin       |" << endl;
				cout << "| Press 8: Hop Thu                      |" << endl;
				cout << "|_______________________________________|" << endl;
				cout << "\n           Moi Ban Chon: ";
				cin >> n;
				Hiden tk;
				tk.className = manage->GetClassName();
				tk.userName = manage->GetUsername();
				string ma;
				string username;
				if (n == 1)
				{
					system("cls");
					delete manage;
					manage = new Guest;
				}
				else if (n == 2)
				{
					system("cls");
					manage->xuatSach(List);
					system("pause");
				}
				else if (n == 3)
				{
					system("cls");
					List.ThemSach();
					UpdateBookToFile(List);
					system("pause");
				}
				else if (n == 4)
				{
					system("cls");
					manage->SuaSach(tk);
					UpdateBookToFile(List);
					system("pause");
				}
				else if (n == 5)
				{
					system("cls");
					cout << "Nhap Ma Sach Can Xoa: ";
					cin >> ma;
					List.XoaSach(ma, tk);
					cout << "Done !!!" << endl;
					UpdateBookToFile(List);
					system("pause");
				}
				else if (n == 6)
				{
					system("cls");
					manage->SendMessage();
					system("pause");
				}
				else if (n == 7)
				{
					system("cls");
					DocThongBao();
					system("pause");
				}
				else if (n == 8)
				{
					system("cls");
					manage->DocThu();
					system("pause");
				}
			} while (n != 1);
		}



		else if (manage->GetClassName() == "NXB")
		{
		int n;
		do
		{
			system("cls");
			cout << "=========================================\n";
			cout << "||             Nha Xuat Ban            ||" << endl;
			cout << "=========================================\n";
			cout << "_________________________________________" << endl;
			cout << "|                                       |" << endl;
			cout << "| Press 1: Dang Xuat                    |" << endl;
			cout << "| Press 2: Danh Sach Sach               |" << endl;
			cout << "| Press 3: Them Sach                    |" << endl;
			cout << "| Press 4: Sua Sach                     |" << endl;
			cout << "| Press 5: Xoa Sach                     |" << endl;
			cout << "| Press 6: Gui Tin Nhan                 |" << endl;
			cout << "| Press 7: Doc Thong Bao Tu Admin       |" << endl;
			cout << "| Press 8: Tim Sach Khong Ban Duoc      |" << endl;
			cout << "| Press 9: Hop Thu                      |" << endl;
			cout << "|_______________________________________|" << endl;
			cout << "\n           Moi Ban Chon: ";
			cin >> n;
			Hiden tk;
			tk.className = manage->GetClassName();
			tk.userName = manage->GetUsername();
			string ma;
			string username;
			if (n == 1)
			{
				system("cls");
				delete manage;
				manage = new Guest;
			}
			else if (n == 2)
			{
				system("cls");
				manage->xuatSach(List);
				system("pause");
			}
			else if (n == 3)
			{
				system("cls");
				List.ThemSach();
				UpdateBookToFile(List);
				system("pause");
			}
			else if (n == 4)
			{
				system("cls");
				manage->SuaSach(tk);
				UpdateBookToFile(List);
				system("pause");
			}
			else if (n == 5)
			{
				system("cls");
				cout << "Nhap Ma Sach Can Xoa: ";
				cin >> ma;
				List.XoaSach(ma, tk);
				cout << "Done !!!" << endl;
				UpdateBookToFile(List);
				system("pause");
			}
			else if (n == 6)
			{
				system("cls");
				manage->SendMessage();
				system("pause");
			}
			else if (n == 7)
			{
				system("cls");
				DocThongBao();
				system("pause");
			}
			else if (n == 8)
			{
				system("cls");
				manage->TimSachKhongBan(List);
				system("pause");
			}
			else if (n == 9)
			{
				system("cls");
				manage->DocThu();
				system("pause");
			}
		} while (n != 1);
		}


		else if (manage->GetClassName() == "Admin")
		{
		int n;
		do
		{
			system("cls");
			cout << "=========================================\n";
			cout << "||                Admin                ||" << endl;
			cout << "=========================================\n";
			cout << "_________________________________________" << endl;
			cout << "|                                       |" << endl;
			cout << "| Press 1 : Dang Xuat                   |" << endl;
			cout << "| Press 2 : Danh Sach Sach              |" << endl;
			cout << "| Press 3 : Them Sach                   |" << endl;
			cout << "| Press 4 : Xoa Sach                    |" << endl;
			cout << "| Press 5 : Them User                   |" << endl;
			cout << "| Press 6 : Xoa User                    |" << endl;
			cout << "| Press 7 : Them Nha Xuat Ban           |" << endl;
			cout << "| Press 8 : Xoa Nha Xuat Ban            |" << endl;
			cout << "| Press 9 : Them Tac Gia                |" << endl;
			cout << "| Press 10: Xoa Tac Gia                 |" << endl;
			cout << "| Press 11: Them An                     |" << endl;
			cout << "| Press 12: Gui Thong Bao               |" << endl;
			cout << "| Press 13: Gui Tin Nhan                |" << endl;
			cout << "| Press 14: Doc tin nhan                |" << endl;
			cout << "| Press 15: Xuat Danh Sach Cac Tai Khoan|" << endl;
			cout << "| Press 16: Xuat Danh Sach Cac Hoa Don  |" << endl;
			cout << "| Press 17: NXB Co Tien Nhieu Nhat      |" << endl;
			cout << "|_______________________________________|" << endl;
			cout << "\n           Moi Ban Chon: ";
			cin >> n;
			cin.ignore();
			Hiden tk;
			tk.className = manage->GetClassName();
			tk.userName = manage->GetUsername();
			string ma;
			string username;
			if (n == 1)
			{
				system("cls");
				delete manage;
				manage = new Guest;
			}
			else if (n == 2)
			{
				system("cls");
				List.XuatListSach();
				system("pause");
			}
			else if (n == 3)
			{
				system("cls");
				List.ThemSach();
				UpdateBookToFile(List);
				system("pause");
			}
			else if (n == 4)
			{
				system("cls");
				cout << "Nhap Ma Sach Can Xoa: ";
				cin >> ma;
				List.XoaSach(ma, tk);
				cout << "Done !!!" << endl;
				UpdateBookToFile(List);
				system("pause");
			}
			else if (n == 5)
			{
				User* p = new User;
				p->CreatAccount(a.vectoruser);
				a.AddListUser("User.txt");
				system("pause");
			}
			else if (n == 6)
			{
				system("cls");
				cout << "Nhap Username Cua User Can Xoa: ";
				cin >> username;
				a.XoaUser(username);
				UpdateUserToFile(a);
				cout << "Done !!!" << endl;
				system("pause");
			}
			else if (n == 7)
			{
				NXB* p = new NXB;
				p->CreatAccount(b.vectornxb);
				b.AddListNXB("NXB.txt");
				system("pause");
			}
			else if (n == 8)
			{
				system("cls");
				cout << "Nhap Ten Nha Xuat Ban Can Xoa: ";
				getline(cin, username);
				b.XoaNXB(username);
				UpdateNXBToFile(b);
				cout << "Done !!!" << endl;
				system("pause");
			}
			else if (n == 9)
			{
				TacGia* p = new TacGia;
				p->CreatAccount(c.vectortacgia);
				c.AddListTacGia("TacGia.txt");
			}
			else if (n == 10)
			{
				system("cls");
				cout << "Nhap Ten Tac Gia Can Xoa: ";
				getline(cin, username);
				c.XoaTacGia(username);
				UpdateTacGiaToFile(c);
				cout << "Done !!!" << endl;
				system("pause");
			}
			else if (n == 11)
			{
				system("cls");
				manage->AddHiden(List);
				system("pause");
			}
			else if (n == 12)
			{
				system("cls");
				GuiThongBao();
				system("pause");
			}
			else if (n == 13)
			{
				system("cls");
				manage->SendMessage();
				system("pause");
			}
			else if (n == 14)
			{
				system("cls");
				manage->DocThu();
				system("pause");
			}
			else if (n == 15)
			{
			system("cls");
			XuatDanhSachTaiKhoan(a.vectoruser, b.vectornxb, c.vectortacgia);
			system("pause");
			}
			else if (n == 16)
			{
			system("cls");
			XuatDanhSachHoaDon(a.vectoruser);
			system("pause");
			}
			else if (n == 17)
			{
			system("cls");
			XuatHoaDonNhieu(b.vectornxb, List);
			system("pause");
			}
		} while (n != 1);
		}
	} while (lenh != 0);



	system("cls");
	cout << "\n\n\n\n SEE YOU AGAIN\n\n\n\n\n" << endl;

	UpdateBookToFile(List);



	system("pause");
	return 0;
}

void Login(Guest*& p, vector<User> a, vector<NXB> b, vector<TacGia> c)
{
	system("cls");
	cout << "=========================================\n";
	cout << "||              Dang Nhap              ||" << endl;
	cout << "=========================================\n";
	cout << "_________________________________________\n" << endl;
	string username, pass;
	cout << "Ten dang nhap: ";
	getline(cin, username);
	cout << "Mat khau: ";
	cin >> pass;
	vector <User>::iterator itu;
	vector <NXB>::iterator itn;
	vector <TacGia>::iterator itt;

	for (itt = c.begin(); itt != c.end(); itt++)
	{
		if (username == itt->GetName() && pass == itt->GetPass())
		{
			p = new TacGia;
			p->SetName(username);
			p->SetPass(pass);
			return;
		}
	}

	for (itu = a.begin(); itu != a.end(); itu++)
	{
		if (username == itu->GetUsername() && pass == itu->GetPass())
		{
			p = new User;
			p->SetUsername(username);
			p->SetPass(pass);
			return;
		}
	}

	for (itn = b.begin(); itn != b.end(); itn++)
	{
		if (username == itn->GetName() && pass == itn->GetPass())
		{
			p = new NXB;
			p->SetName(username);
			p->SetPass(pass);
			return;
		}
	}
	
	if (username == "admin" && pass == "admin")
	{
		p = new Admin;
		p->SetUsername(username);
		p->SetPass(pass);
		return;
	}

}
