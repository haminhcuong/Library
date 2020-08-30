#pragma once
#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <string>
#include "Sach.h"
#include <vector>
#include "ListSach.h"
#include "Guest.h"
using namespace std;

class TacGia:public Guest
{
protected:
	string Ten;
	string Pass;
	ListSach list;
public:
	vector <TacGia> vectorTacGia;
	TacGia();
	~TacGia();
	void CreatAccount(vector <TacGia>&);
	void CreatAccount2(vector<TacGia>& a);
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
};

