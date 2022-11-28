#pragma once
#include <iostream>
using namespace std;

//include class
#include "Date.h"

//include lib
#include <string>

class Employee:public Date
{
public:
	string maNhanVien, hoTen, maChucVu, gioiTinh, diaChi, hocVan;
	Date ngaySinh, ngayVaoLam;
	int soDienThoai, soCMND;
	
public:
	Employee();
	Employee(string maNhanVien, string hoTen, string maChucVu, string gioiTinh, string diaChi, string hocVan, Date ngaySinh, Date ngayVaoLam, int soDienThoai, int soCMND);
	~Employee(void);

	string getMaNhanVien();
	string getHoTen();
	string getMaChucVu();
	string getGioiTinh();
	string getDiaChi();
	string getHocVan();
	Date getNgaySinh();
	Date getNgayVaoLam();
	int getSoDienThoai();
	int getSoCMND();

	void setMaNhanVien(string s);
	void setHoTen(string s);
	void setMaChucVu(string s);
	void setGioiTinh(string s);
	void setDiaChi(string s);
	void setHocVan(string s);
	void setNgaySinh(Date d);
	void setNgayVaoLam(Date d);
	void setSoDienThoai(int n);
	void setSoCMND(int n);

	Employee nhap();

	void xuat();
};