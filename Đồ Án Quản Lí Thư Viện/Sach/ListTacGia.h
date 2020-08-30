#pragma once
#include "TacGia.h"

class ListTacGia
{
public:
	vector <TacGia> vectortacgia;
	ListTacGia();
	~ListTacGia();
	void AddTacGia();
	void AddListTacGia(string);
	void XoaTacGia(string a);
};

void UpdateTacGiaToFile(ListTacGia& a);