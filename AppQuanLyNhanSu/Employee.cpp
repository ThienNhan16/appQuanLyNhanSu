#include "Employee.h"

Employee::Employee() 
{
	this->maNhanVien = "";
	this->hoTen = "";
	this->maChucVu = "";
	this->gioiTinh = "";
	this->diaChi = "";
	this->hocVan = "";

	//Qua tai toan tu gan
	Date d;
	this->ngaySinh = d;
	this->ngayVaoLam = d;

	this->soDienThoai = 0;
	this->soCMND = 0;
}

Employee::Employee(string maNhanVien, string hoTen, string maChucVu, string gioiTinh, string diaChi, string hocVan, Date ngaySinh, Date ngayVaoLam, int soDienThoai, int soCMND)
{
	this->maNhanVien = maNhanVien;
	this->hoTen = hoTen;
	this->maChucVu = maChucVu;
	this->gioiTinh = gioiTinh;
	this->diaChi = diaChi;
	this->hocVan = hocVan;

	//Qua tai toan tu gan
	this->ngaySinh = ngaySinh;
	this->ngayVaoLam = ngayVaoLam;

	this->soDienThoai = soDienThoai;
	this->soCMND = soCMND;
}

Employee::~Employee(void) 
{
	
}

void Employee::setMaNhanVien(string s)
{
	maNhanVien = s;
}
void Employee::setHoTen(string s)
{
	hoTen = s;
}
void Employee::setMaChucVu(string s)
{
	maChucVu = s;
}
void Employee::setGioiTinh(string s)
{
	gioiTinh = s;
}
void Employee::setDiaChi(string s)
{
	diaChi = s;
}
void Employee::setHocVan(string s)
{
	hocVan = s;
}
void Employee::setNgaySinh(Date d)
{
	ngaySinh = d;
}
void Employee::setNgayVaoLam(Date d)
{
	ngayVaoLam = d;
}
void Employee::setSoDienThoai(int n)
{
	soDienThoai = n;
}
void Employee::setSoCMND(int n)
{
	soCMND = n;
}

Employee Employee::nhap()
{
	Employee e;

	string maNhanVien1, hoTen1, maChucVu1, gioiTinh1, diaChi1, hocVan1;
	Date ngaySinh1, ngayVaoLam1;
	int soDienThoai1, soCMND1;

	cout << "Nhap maNhanVien = ";
	cin >> maNhanVien1;
	cout << "Nhap hoTen = ";
	cin.ignore();
	getline(cin, hoTen1);
	cout << "Nhap maChucVu = ";
	cin >> maChucVu1;
	cout << "Nhap gioiTinh = ";
	cin.ignore();
	getline(cin, gioiTinh1);
	cout << "Nhap diaChi = ";
	cin.ignore();
	getline(cin, diaChi1);
	cout << "Nhap hocVan = ";
	cin.ignore();
	getline(cin, hocVan1);
	//Qua tai toan tu xuat
	cout << "Nhap ngaySinh = ";
	cin >> ngaySinh1;
	cout << "Nhap ngayVaoLam = ";
	cin >> ngayVaoLam1;

	cout << "Nhap soDienThoai = ";
	cin >> soDienThoai1;
	cout << "Nhap soCMND = ";
	cin >> soCMND1;

	e.setMaNhanVien(maNhanVien1);
	e.setHoTen(hoTen1);
	e.setMaChucVu(maChucVu1);
	e.setGioiTinh(gioiTinh1);
	e.setDiaChi(diaChi1);
	e.setHocVan(hocVan1);
	e.setNgaySinh(ngaySinh1);
	e.setNgayVaoLam(ngayVaoLam1);
	e.setSoDienThoai(soDienThoai1);
	e.setSoCMND(soCMND1);

	return e;
}

void Employee::xuat() 
{
	cout << "maNhanVien = "<< this->maNhanVien <<endl;
	cout << "hoTen = "<< this->hoTen <<endl;
	cout << "maChucVu = "<< this->maChucVu <<endl;
	cout << "gioiTinh = "<< this->gioiTinh <<endl;
	cout << "diaChi = "<< this->diaChi <<endl;
	cout << "hocVan = "<< this->hocVan <<endl;
	//Qua tai toan tu xuat
	cout << "ngaySinh = " << this->ngaySinh;
	cout << "ngayVaoLam = " << this->ngayVaoLam;

	cout << "soDienThoai = "<< this->soDienThoai <<endl;
	cout << "soCMND = "<< this->soCMND <<endl;
}