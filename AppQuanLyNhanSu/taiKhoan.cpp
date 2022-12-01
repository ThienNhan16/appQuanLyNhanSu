#include "taiKhoan.h"

taiKhoan::taiKhoan(){
    this->tenDangNhap = "";
    this->matKhau = "";
}

taiKhoan::taiKhoan(string tenDangNhap, string matKhau, string ID){
    this->tenDangNhap = tenDangNhap;
    this->matKhau = matKhau;
    this->ID = ID;
}

taiKhoan::~taiKhoan(){
    
}