#pragma once

#include "Sach.h"
#include <vector>
#include <fstream>

class ListSach
{
public:
	vector <Sach> vectorSach;
	ListSach();
	~ListSach();
	void AddListSach(string path);
	void XuatListSach();
	void ThemSach();
	void XoaSach(string& masach, Hiden& An);
	void SuaSach(string& masach, Hiden& An);
};

void TimTenSach(ListSach&);
vector<Sach>::iterator TimMaSach(ListSach& listsach,string& ma);
void UpdateBookToFile(ListSach&);
