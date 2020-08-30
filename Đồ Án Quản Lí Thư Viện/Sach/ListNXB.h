#pragma once
#include "NXB.h"

class ListNXB
{
public:
	vector <NXB> vectornxb;
	ListNXB();
	~ListNXB();
	void AddNXB();
	void AddListNXB(string);
	void XoaNXB(string a);
};

void UpdateNXBToFile(ListNXB& a);