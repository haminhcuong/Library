#pragma once

#include <iostream>
#include <string>
#include "Sach.h"
#include "ListSach.h"
#include "Guest.h"
#include <vector>

class NXB:public Guest
{
protected:
	string Ten;
	string Pass;
	ListSach list;
	
public:
	NXB();
	~NXB();
	int Tong;
	vector <NXB> vectorNXB;
	void CreatAccount(vector <NXB>&);
	void CreatAccount2(vector<NXB>& a);
	string GetName();
	void SetName(string& name);
	string GetPass();
	void SetPass(string& pass);
	void UpdateListSach(ListSach& list);
	void XoaSach(Hiden& An);
	void ThemSach();
	void SuaSach(Hiden& An);
	string GetClassName();
	void SendMessage();
	void DocThu();
	void xuatSach(ListSach& list);
	void Xuat();
	void TimSachKhongBan(ListSach list);
	void TinhTienBanDuoc(ListSach list);
};



