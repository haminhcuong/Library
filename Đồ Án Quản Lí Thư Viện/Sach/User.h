#ifndef USER_H_
#define USER_H_
#define _CRT_SECURE_NO_WARNINGS
#include "Guest.h"
#include "TacGia.h"
#include "NXB.h"


class User :public Guest
{
private:
	string userName, pass;
	string name;
	
	ListHoaDon listHoaDon;
public:
	int age;
	User();
	~User();
	string GetUsername();
	void SetUsername(string& username);
	string GetPass();
	void SetPass(string& pass);
	string GetName();
	void SetName(string& name);
	int Getage();
	void Setage(int& age);
	void Buy(ListSach& listsach);
	void BuyBook(ListSach& listsach, Sach& sach);
	string GetClassName();
	void CapNhatDonHang();
	void InDonHang();
	void CreatAccount(vector <User> &a);
	void CreatAccount2(vector<User>& a);
	void SendMessage();
	void DocThu();
	void Xuat();
};

void DocThongBao();


#endif // !USER_H_




