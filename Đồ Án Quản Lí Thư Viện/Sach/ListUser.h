#pragma once
#include "User.h"

class ListUser
{
public:
	vector <User> vectoruser;
	ListUser();
	~ListUser();
	void AddUser();
	void AddListUser(string);
	void XoaUser(string a);
};



void UpdateUserToFile(ListUser& a);

