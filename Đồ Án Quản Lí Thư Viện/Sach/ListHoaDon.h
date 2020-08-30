#ifndef LISTHOADON_H_
#define LISTHOADON_H_
#include "HoaDon.h"
#include <vector>

class ListHoaDon
{
public:
	vector <HoaDon> vectorHoaDon;
	int result;
	ListHoaDon();
	~ListHoaDon();
	void Add(HoaDon&);
	void CapNhatTien();
	void InHoaDon(string path);
	void AddListHoaDon(string username);
	void Buy(ListSach&);
	void XoaHoaDon(HoaDon&);
	void CapNhatSoLuong(HoaDon&, int&);
};

#endif



