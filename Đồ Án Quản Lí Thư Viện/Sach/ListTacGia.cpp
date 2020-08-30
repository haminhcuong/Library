#include "ListTacGia.h"

ListTacGia::ListTacGia()
{
}

ListTacGia::~ListTacGia()
{
}

void ListTacGia::AddTacGia()
{

	TacGia TacGia;
	TacGia.CreatAccount(vectortacgia);
}

void ListTacGia::AddListTacGia(string path)
{
	ifstream f;
	f.open(path, ios::in);
	while (!f.eof())
	{
		string ten, matkhau;
		getline(f, ten, '\t');
		getline(f, matkhau, '\n');
		TacGia a;
		a.SetName(ten);
		a.SetPass(matkhau);
		vectortacgia.push_back(a);
	}
	f.close();
}

void ListTacGia::XoaTacGia(string name)
{
	vector<TacGia>::iterator it;
	for (it = vectortacgia.begin(); it != vectortacgia.end(); it++)
	{
		if (it->GetName() == name)
		{
			vectortacgia.erase(it);
			return;
		}
	}
	cout << "Khong Co Tac Gia Nay" << endl;
}

void UpdateTacGiaToFile(ListTacGia& a)
{
	fstream f;
	f.open("TacGia.txt", ios::out);
	vector <TacGia> ::iterator it;
	for (it = a.vectortacgia.begin(); it != a.vectortacgia.end(); it++)
	{
		f << it->GetName() << "\t" << it->GetPass() << "\n";
	}
	f.close();
}