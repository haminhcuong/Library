#include "ListUser.h"



ListUser::ListUser()
{
}

ListUser::~ListUser()
{
}

void ListUser::AddUser()
{
	User user;
	user.CreatAccount(vectoruser);
}

void ListUser::AddListUser(string path)
{
	ifstream f;
	f.open(path, ios::in);
	while (!f.eof())
	{
		string username, ten, matkhau;
		int tuoi;
		getline(f, username, '\t');
		f >> matkhau;
		f.ignore();
		f >> tuoi;
		f.ignore();
		getline(f, ten, '\n');
		User a;
		a.SetUsername(username);
		a.Setage(tuoi);
		a.SetName(ten);
		a.SetPass(matkhau);
		vectoruser.push_back(a);
	}
	f.close();
}

void ListUser::XoaUser(string a)
{
	vector <User> ::iterator it;
	for (it = vectoruser.begin(); it != vectoruser.end(); it++)
	{
		if (a == it->GetUsername())
		{
			vectoruser.erase(it);
			return;
		}		
	}
	cout << "Khong Co User Nay" << endl;
}

void UpdateUserToFile(ListUser& a)
{
	fstream f;
	f.open("User.txt", ios::out);
	vector <User> ::iterator it;
	for (it = a.vectoruser.begin(); it != a.vectoruser.end(); it++)
	{
		f << it->GetUsername() << "\t" << it->GetPass() << "\t" << it->age << "\t" << it->GetName() << "\n";
	}
	f.close();
}