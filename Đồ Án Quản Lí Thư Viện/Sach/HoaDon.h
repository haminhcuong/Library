#ifndef  HOADON_H_
#define HOADON_H_
#include "ListSach.h"


class HoaDon
{
public:
	
	Sach sach;
	int tien;
	int soLuong;
	int tongTien;
	string duLieu;
	HoaDon();
	~HoaDon();
	static Sach TimSach(ListSach&);
	int Add(Sach&);
	friend ostream& operator<< (ostream&, HoaDon);
	void CapNhatTien();
	void xuat();
};


#endif

