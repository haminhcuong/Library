#ifndef SACH_H
#define SACH_H

#include <iostream>
#include <string>
#include <vector>

using namespace std;

struct Hiden
{
	string className;
	string userName;
};

class Sach
{
private:
	string maSach;
	string tenSach;
	int gia;
	int soLuotMua;
public:
	
	string tacGia;
	string NXB;
	vector <Hiden> vectorHiden;
	Sach();
	~Sach();
	void SetSo(int);
	int GetSo();
	void SetMaSach(string);
	string GetMaSach();
	void SetTenSach(string);
	string GetTenSach();
	void SetGia(int);
	int GetGia();
	void NhapSach();
	void XuatSach();
	void AddHiden();
};


#endif

