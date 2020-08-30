#pragma once
#define _CRT_SECURE_NO_WARNINGS

#include <iostream>
#include <string>
#include "Sach.h"
#include "TacGia.h"
#include "User.h"
#include "NXB.h"
#include "Guest.h"
#include "ListUser.h"
#include "ListHoaDon.h"

using namespace std;

class Admin:public Guest
{
public:
	string Ten;
	string Pass;
	vector <NXB> vectorNXB;
	vector <TacGia> vectorTacGia;
	vector <User> vectorUser;

	Admin();
	~Admin();
	string GetTen();
	void SetTen(string& ten);
	string GetPass();
	void SetPass(string& pass);
	string GetClassName();
	void AddHiden(ListSach& list);
	void SendMessage();
	void DocThu();
};


void GuiThongBao();
void XuatDanhSachTaiKhoan(vector <User> a, vector <NXB> b, vector <TacGia> c);
void XuatDanhSachHoaDon(vector <User> a);
void XuatHoaDonNhieu(vector <NXB> a, ListSach);