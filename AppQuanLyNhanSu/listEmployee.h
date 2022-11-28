#pragma once

//include class
#include "nodeEmployee.h"

//include lib
#include<fstream>

class listEmployee : public nodeEmployee
{
public:
	NodeEmployee head;
	NodeEmployee tail;
	int size;

public:
	listEmployee();

	NodeEmployee getPhanTuTheoIndex(int index);
	int getSize();

	void docFile(ifstream &f, Employee &e);
	void nhapDanhSachNhanVien();
	void layDanhSachTuFile(string);

	void xuatTrenXuong();
	void xuatDuoiLen();

	void themPhanTu(NodeEmployee);

	void sapXepTheoMaNhanVien();
	void sapXepTheoTen();
	void sapXepTheoMaChucVu();

	NodeEmployee timPhanTuTheoTen();
	NodeEmployee timPhanTuTheoMaNhanVien();
	NodeEmployee timPhanTuTheoMaChucVu();
	NodeEmployee timPhanTuTheoSoDienThoai();
	NodeEmployee timPhanTuTheoSoCMND();
};