#pragma once
#include <iostream>
using namespace std;

class taiKhoan{
private:
    string tenDangNhap, matKhau, ID;
public:
    taiKhoan();
    taiKhoan(string tenDangNhap, string matKhau, string ID);
    ~taiKhoan(void);
    
    string getTenDangNhap(){
        return this->tenDangNhap;
    };

    string getMatKhau(){
        return this->matKhau;
    };

    string getID(){
        return this->ID;
    };

    taiKhoan* setTenDangNhap(string tenDangNhap){
        this->tenDangNhap = tenDangNhap;
    };

    taiKhoan* setMatKhau(string matKhau){
        this->matKhau = matKhau;
    };

    taiKhoan* setID(string ID){
        this->ID = ID;
    };
};

