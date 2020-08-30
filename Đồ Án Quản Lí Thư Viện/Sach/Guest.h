#ifndef GUEST_H_
#define GUEST_H_
#include "ListHoaDon.h"
#include <fstream>
#include <vector>



class Guest
{
public:
	Guest();
	virtual ~Guest();
	virtual string GetUsername();
	virtual void SetUsername(string& username);
	virtual string GetPass();
	virtual void SetPass(string& pass);
	virtual string GetName();
	virtual void SetName(string& name);
	virtual int GetTuoi();
	virtual void SetTuoi(int& tuoi);
	Sach TimSach(ListSach& listsach);
	virtual string GetClassName();
	virtual void InDonHang();
	virtual void Buy(ListSach& listsach);
	virtual void BuyBook(ListSach& listsach, Sach& sach);
	virtual void CapNhatDonHang();
	virtual void UpdateListSach(ListSach& l);
	virtual void ThemNXB();
	virtual void XoaNXB(string& name);
	virtual void ThemTacGia();
	virtual void XoaTacGia(string& name);
	virtual void ThemUser();
	virtual void XoaUser(string& username);
	virtual void XoaSach(Hiden& An);
	virtual void ThemSach();
	virtual void SuaSach(Hiden& An);
	virtual void XuatListSach();
	virtual void AddHiden(ListSach& listSach);
	virtual void CreatAccount();
	virtual void CreatAccount2();
	virtual void SendMessage();
	void LogIn();
	virtual void DocThu();
	virtual void xuatSach(ListSach& list);
	virtual void Xuat();
	virtual void TimSachKhongBan(ListSach list);
};
#endif




