#include "listEmployee.h"

listEmployee::listEmployee()
{
	head = NULL;
	tail = NULL;
	size = 0;
}

int listEmployee::getSize()
{
	return size;
}

void listEmployee::nhapDanhSachNhanVien()
{
	cout << "Nhap so nhan vien ban muon them";

}

//doc du lieu tu file qua dslk
void listEmployee::layDanhSachTuFile(string tenFile)
{
	ifstream f(tenFile);

	if (!f.is_open())
	{
		cout << "Faild open file";
		exit(1);
	}

	while (!f.eof())
	{
		string line;
		Employee e;

		getline(f, line, ';');
		e.setMaNhanVien(line);
		getline(f, line, ';');
		e.setHoTen(line);
		getline(f, line, ';');
		e.setMaChucVu(line);
		getline(f, line, ';');
		e.setGioiTinh(line);
		getline(f, line, ';');
		e.setDiaChi(line);
		getline(f, line, ';');
		e.setHocVan(line);

		char temp;

		int d1, m1, y1;
		f >> d1;
		f >> temp;
		f >> m1;
		f >> temp;
		f >> y1;
		Date day1(d1, m1, y1);
		e.setNgaySinh(day1);

		f >> temp;

		int d, m, y;
		f >> d;
		f >> temp;
		f >> m;
		f >> temp;
		f >> y;
		Date day(d, m, y);
		e.setNgayVaoLam(day);

		int sdt, cmnd;
		f >> temp;
		f >> sdt; 
		f >> temp;
		f >> cmnd;
		f >> temp;

		e.setSoDienThoai(sdt);
		e.setSoCMND(cmnd);

		NodeEmployee nE = new nodeEmployee(e);

		this->themPhanTu(nE);

		++size;
	}

	f.close();
}

void listEmployee::xuatTrenXuong()
{
	while (head != NULL) {
		head->data.xuat();
		head = head->next;
	}
}

void listEmployee::themPhanTu(NodeEmployee x)
{
	if (this->head == NULL) 
	{
		this->head = x;
		this->tail = x;
	}
	else 
	{
		x->prev = this->tail;
		this->tail->next = x;
		this->tail = x;
	}
}

void listEmployee::sapXepTheoMaNhanVien()
{

}

void listEmployee::sapXepTheoTen()
{

}

void listEmployee::sapXepTheoMaChucVu()
{

}

//NodeEmployee listEmployee::timPhanTuTheoTen()
//{
//
//}
//
//NodeEmployee listEmployee::timPhanTuTheoMaNhanVien()
//{
//
//}
//
//NodeEmployee listEmployee::timPhanTuTheoMaChucVu()
//{
//
//}
//
//NodeEmployee listEmployee::timPhanTuTheoSoDienThoai()
//{
//
//}
//
//NodeEmployee listEmployee::timPhanTuTheoSoCMND()
//{
//
//}