#include <iostream>
#include <conio.h>
#include <string>
#include <string.h>
#include <cstdlib>
#include "taiKhoan.h"
#include "taiKhoan.cpp"
#include <fstream>
using namespace std;

bool kiemTraKhoangTrang(string name){
	int x;
	const char* string_to_char = name.c_str();
	x = strlen(string_to_char);
	for (int i = 0; i < x; i++){
		if (string_to_char[i] == ' ' || (name == "")){ 
			system("cls");
			cout << "Ten dang nhap khong duoc chua dau cach." << endl; 
			return false; //false -> ten sai
		}
	}
	return true; // true -> ten dung
}

bool kiemTraNhap(char *kyTu){
	int kyTuSo;
	kyTuSo = atoi(kyTu);
	if(kyTuSo != 1 && kyTuSo != 2 && kyTuSo != 0){
		return false;
	}
	return true;
}

void layTaiKhoanTuFile(string tenFile, taiKhoan* tk, string &tenNhapVao, string &tenCanGan, string &matKhauCanGan){
	ifstream doc(tenFile); 

	if(!doc.is_open()){
		cout << "Khong the mo file";
		exit(1);
	}
	string t, mk, id;
	while(!doc.eof()){

		getline(doc, t, ',');
		tk->setTenDangNhap(t);

		getline(doc, mk, ',');
		tk->setMatKhau(mk);

		getline(doc, id);
		tk->setID(id);

		if(tk->getTenDangNhap() == tenNhapVao){
			tenCanGan = tk->getTenDangNhap();
			matKhauCanGan = tk->getMatKhau();
			break;
		}
	}
	doc.close();
}

void ghiTaiKhoanVaoFile(string tenFile, taiKhoan* tk, string &tenDangNhap, string &matKhau, string &ID){
	ofstream ghi(tenFile, ios::app); 
	if(!ghi.is_open()){
		cout << "Khong the mo file!";
		exit(1);
	}

	tk->setTenDangNhap(tenDangNhap);
	tk->setMatKhau(matKhau);
	tk->setID(ID);

	ghi << tk->getTenDangNhap() << ",";
	ghi << tk->getMatKhau() << ",";
	ghi << tk->getID();
	ghi << endl;
}

void layIDDaDungTuFile(string tenFile, int &RegisterID){
	string line;
	char* kyTu;
	fstream layIDDaDung;
	layIDDaDung.open(tenFile);
	layIDDaDung.seekg(-1, ios::end);
	getline(layIDDaDung, line);
	kyTu[1] = line[0];
	RegisterID = atoi(&kyTu[1]);
	layIDDaDung.close();
}

void ghiIDDaDungVaoFile(string tenFile, int &RegisterID){
	fstream ghiIDDaDung;
	ghiIDDaDung.open(tenFile);
	ghiIDDaDung << RegisterID;
	ghiIDDaDung.close();
}

string inputPassword(string &pass)
{
    // size_t length_max;
    pass = "";
    char ch = 0;
    bool bShow = false;
    do
    {
        ch = getch();
        if((isalpha(ch) || isalnum(ch)))//(pass.size() < length_max) && )) // Chỉ cho phép nhập kí tự và số
        {
            cout << (bShow ? ch : '*');
            pass.push_back(ch);
        }
        else
        {
            if(0x1B == ch) // 0x1B mã ASCII của phím esc.
            {
                bShow = !bShow;
 
                cout << string(pass.size(), '\b');
           
                if(bShow)
                    cout << pass;
                else
                    cout << string(pass.size(), '*');
               
            }
            if('\b' == ch && !pass.empty())
            {
                cout << "\b \b";
                pass.resize(pass.size() - 1);
            }
        }
 
    }while ('\r' != ch);
	cout << endl;
    return pass;
}

int main() {
	string name, name1, pass, pass1, repass, passManage, passManage1, ID;
	char opt[] = "";
	string fileTaiKhoanNhanVien, fileTaiKhoanQuanLy, fileIDNV_DaDung, fileIDQL_DaDung;
	int managerID, employeeID, formManagerID, formEmployeeID;
	int op;
	formManagerID = 1;
	formEmployeeID = 0;
	fileTaiKhoanNhanVien = "IDNhanVien.txt";
	fileTaiKhoanQuanLy = "IDQuanLy.txt"; 
	fileIDNV_DaDung = "IDNV_DaDung.txt"; 
	fileIDQL_DaDung = "IDQL_DaDung.txt";
	/// ID = string(formID + this->ID)
menu:

	system("cls");
	cout << "\t\t QLNV" << endl;
	cout << "Dang ki [1]" << endl;
	cout << "Dang nhap [2]" << endl;
	cout << "------------------------------------" << endl;
	cout << ">>> ";
	cin >> opt;
	/// lệnh này để phòng trường hợp người nhập nhập vào op là kí tự
	while (kiemTraNhap(opt) == false){
		system("cls");
		cout << "Nhap lai!!!" << endl;
		cout << "\t\t QLNV" << endl;
		cout << "Dang ki [1]" << endl;
		cout << "Dang nhap [2]" << endl;
		cout << "------------------------------------" << endl;
		cout << ">>> ";
		// cin.ignore();
		cin >> opt;
	}
	op = atoi(opt); /// chuyển option sang dạng int
	switch (op)
	{
	case 1:
		{
			system("cls");
			cout << "Dang ki cho nhan vien [1]" << endl;
			cout << "Dang ki cho quan ly [2]" << endl;
			cout << "------------------------------------" << endl;
			cout << ">>> ";
			cin >> opt;
			/// lệnh này để phòng trường hợp người nhập nhập vào op là kí tự
			while (kiemTraNhap(opt) == false){
				system("cls");
				cout << "Nhap lai!!!" << endl;
				cout << "Dang ki cho nhan vien [1]" << endl;
				cout << "Dang ki cho quan ly [2]" << endl;
				cout << "------------------------------------" << endl;
				cout << ">>> ";
				cin >> opt;
			}
			op = atoi(opt); /// chuyển option sang dạng int
			switch (op){
				case 1:
					{
						system("cls");
						goto signUpEmployee;
						break;	
					}
				case 2:
					{
						system("cls");
						cout << "Nhap mat khau quan ly de co the tao tai khoan: "; inputPassword(passManage1);

						fstream layPassManage;
						layPassManage.open(".env");
						getline(layPassManage, passManage);
						layPassManage.seekg(-14, ios_base::end);
						layPassManage.close();
						// cout << passManage << endl;
						// cout << passManage1 << endl;

						int luotNhap = 5;
						while((passManage1!=passManage)){
							if(luotNhap>0){
								cout << "Mat khau khong chinh xac!" << endl;
								cout << "Ban con " << luotNhap << " lan" << endl; luotNhap--;
								cout << "Nhap lai [1] hoac den muc Dang ki cho nhan vien [2]: ";
								cin >> opt;
								/// lệnh này để phòng trường hợp người nhập nhập vào op là kí tự
								while (kiemTraNhap(opt) == false){
									system("cls");
									cout << "Nhap lai!!!" << endl;
									cout << "Nhap lai [1] hoac den muc Dang ki cho nhan vien [2]: ";
									cout << ">>> ";
									cin >> opt;
								}
								op = atoi(opt); /// chuyển option sang dạng int
								switch(op){
									case 1:
										{
											system("cls");
											cout << "Nhap mat khau quan ly de co the tao tai khoan: "; inputPassword(passManage1); continue;
										}
									case 2:
										{
											goto signUpEmployee;
											break;
										}
								}
							}
							else {
								system("cls");
								cout << "Ban da het luot nhap! Vui long chuyen den muc Dang ki cho nhan vien!" << endl;
								goto signUpEmployee;
								break;
							}
					}
					system("cls");
					cout << "Mat khau chinh xac!" << endl;
					goto signUpManager;
					break;	
			}
		}
	case 2:
		{
			system("cls");
			cout << "Dang nhap cho nhan vien [1]" << endl;
			cout << "Dang nhap cho quan ly [2]" << endl;
			cout << "------------------------------------" << endl;
			cout << ">>> ";
			cin >> opt;
			/// lệnh này để phòng trường hợp người nhập nhập vào op là kí tự
			while (kiemTraNhap(opt) == false){
				system("cls");
				cout << "Nhap lai!!!" << endl;
				cout << "Dang nhap cho nhan vien [1]" << endl;
				cout << "Dang nhap cho quan ly [2]" << endl;
				cout << "------------------------------------" << endl;
				cout << ">>> ";
				cin >> opt;
			}
			op = atoi(opt); /// chuyển option sang dạng int
			switch (op){
				case 1:
					{
						system("cls");
						goto signInEmployee;
						break;	
					}
				case 2:
					{	
						system("cls");
						goto signInManager;
						break;	
					}
			}
		}
	default:
		{
			cout << "Nhap lai lua chon cua ban" << endl;
			goto menu;
			break;
		}
	}


signUpEmployee:
{
	cin.ignore(); 
	cout << "---------------DANG KI NHAN VIEN-----------------" << endl;
	cout << "Dien nhung thong tin ben duoi" << endl;
	cout << "Ten dang nhap    :"; getline(cin, name); 
	cout << "Mat khau         :"; inputPassword(pass); 
	cout << "Nhap lai mat khau:"; inputPassword(repass); 

	while (!kiemTraKhoangTrang(name)){
		goto signUpEmployee;
	};
	// cout << pass << endl; cout << repass << endl;

	if (repass == pass) {
		system("cls");
		cout << "DANG KI THANH CONG!" << endl;

		taiKhoan* tk = new taiKhoan();
		layIDDaDungTuFile(fileIDNV_DaDung, employeeID); // lấy id
		employeeID++; // id tăng 1 đơn vị
		ID = to_string(formEmployeeID) + to_string(employeeID);
		ghiTaiKhoanVaoFile(fileTaiKhoanNhanVien, tk, name, pass, ID);
		ghiIDDaDungVaoFile(fileIDNV_DaDung, employeeID); // ghi id 
		goto signInEmployee;
	}
	else {
		system("cls");
		cout << "Mat khau khong trung khop! Kiem tra lai mat khau ban da nhap" << endl;
		goto signUpEmployee;
		// break;
		return 1;
	}
}

signInEmployee:
{
	cout << "---------------DANG NHAP NHAN VIEN-----------------" << endl;
	cin.ignore(); 
	cout << "Ten dang nhap  :"; getline(cin, name1); 
	cout << "Mat khau       :"; inputPassword(pass1);
	cout << endl << endl;
	
	ifstream docFile(fileTaiKhoanNhanVien);
	taiKhoan* tk = new taiKhoan();
	
	layTaiKhoanTuFile(fileTaiKhoanNhanVien, tk, name1, name, pass);

	if ((tk->getTenDangNhap().length() == 0) || (tk->getMatKhau().length() == 0) || (tk->getID().length() == 0)){
		system("cls");
		cout << "Khong tim thay tai khoan!" << endl;
		cout << "Nhap (1) de DANG KI" << endl;
		cout << "Nhap (2) de tiep tuc DANG NHAP" << endl;
		cout << ">>> ";
		cin >> opt;
			/// lệnh này để phòng trường hợp người nhập nhập vào op là kí tự
		while (kiemTraNhap(opt) == false){
			system("cls");
			cout << "Nhap lai!!!" << endl;
			cout << "Nhap (1) de DANG KI" << endl;
			cout << "Nhap (2) de tiep tuc DANG NHAP" << endl;
			cout << ">>> ";
			cin >> opt;
		}
		op = atoi(opt); /// chuyển option sang dạng int
		switch (op)
		{
			case 1:
				{
					goto signUpEmployee;
					break;
				}
			case 2:
				{
					goto signInEmployee;
					break;
				}
			default:
				{	
					cout << "Nhap lai lua chon cua ban" << endl;
					break;
				}
		}

	}	
	// cout << name << pass << endl;
	else if (pass1 == pass){ 
		system("cls");
		cout << "DANG NHAP THANH CONG!" << endl;
		goto menuEmployee;
		break;
	}
	else if (pass1!=pass){
		system("cls");
		cout << "TEN DANG NHAP HOAC MAT KHAU KHONG DUNG!" << endl;
		cout << "Kiem tra lai \"Ten dang nhap\" hoac \"Mat khau\" cua ban." << endl;
		cout << "Neu ban chua dang ki, dang ki ngay." << endl;
		cout << "Nhap (1) de DANG KI" << endl;
		cout << "Nhap (2) de tiep tuc DANG NHAP" << endl;
		cout << ">>> ";
		// cin >> op;
		cin >> opt;
			/// lệnh này để phòng trường hợp người nhập nhập vào op là kí tự
		while (kiemTraNhap(opt) == false){
			system("cls");
			cout << "Nhap lai!!!" << endl;
			cout << "Nhap (1) de DANG KI" << endl;
			cout << "Nhap (2) de tiep tuc DANG NHAP" << endl;
			cout << ">>> ";
			cin >> opt;
		}
		op = atoi(opt); /// chuyển option sang dạng int
		switch (op)
		{
			case 1:
				{
					goto signUpEmployee;
					break;
				}
			case 2:
				{
					goto signInEmployee;
					break;
				}
			default:
				{	
					cout << "Nhap lai lua chon cua ban" << endl;
					break;
				}
		}
	}
	else {
		system("cls");
		cout << "DANG NHAP THAT BAI!" << endl;
		goto signInEmployee;
		break;
	}
}

signUpManager:
{
	cin.ignore(); 
	cout << "------------DANG KI QUAN LY-----------------" << endl;
	cout << "Dien nhung thong tin ben duoi" << endl;
	cout << "Ten dang nhap    :"; getline(cin, name); 
	cout << "Mat khau         :"; inputPassword(pass); 
	cout << "Nhap lai mat khau:"; inputPassword(repass); 
	while (!kiemTraKhoangTrang(name)){
		goto signUpManager;
	};
	if (repass == pass) {
		system("cls");
		cout << "DANG KI THANH CONG!" << endl;

		taiKhoan* tk = new taiKhoan();
		layIDDaDungTuFile(fileIDQL_DaDung, managerID);
		managerID = managerID + 1;
		ID = to_string(formManagerID) + to_string(managerID);
		ghiTaiKhoanVaoFile(fileTaiKhoanQuanLy, tk, name, pass, ID);
		ghiIDDaDungVaoFile(fileIDQL_DaDung, managerID);
		
		goto signInManager;
	}
	else {
		system("cls");
		cout << "Mat khau khong trung khop! Kiem tra lai mat khau ban da nhap" << endl;
		goto signUpManager;
		return 1;
	}
}

signInManager:
{	
	cout << "-------------DANG NHAP QUAN LY-----------------" << endl;
	cin.ignore();
	cout << "Ten dang nhap  :"; getline(cin, name1); 
	cout << "Mat khau       :"; inputPassword(pass1);
	cout << endl << endl;
/// lấy dữ liệu để đăng nhập
	ifstream docFile(fileTaiKhoanQuanLy);
	taiKhoan* tk = new taiKhoan();
	
	layTaiKhoanTuFile(fileTaiKhoanQuanLy, tk, name1, name, pass);
	// cout << pass1; cout << name;
	if ((tk->getTenDangNhap().length() == 0) || (tk->getMatKhau().length() == 0) || (tk->getID().length() == 0)){
		system("cls");
		cout << "Khong tim thay tai khoan!" << endl;
		cout << "Nhap (1) de DANG KI" << endl;
		cout << "Nhap (2) de tiep tuc DANG NHAP" << endl;
		cout << ">>> ";
		cin >> opt;
		/// lệnh này để phòng trường hợp người nhập nhập vào op là kí tự
		while (kiemTraNhap(opt) == false){
			system("cls");
			cout << "Nhap lai!!!" << endl;
			cout << "Nhap (1) de DANG KI" << endl;
			cout << "Nhap (2) de tiep tuc DANG NHAP" << endl;
			cout << ">>> ";
			cin >> opt;
		}
		op = atoi(opt); /// chuyển option sang dạng int
		switch (op)
		{
			case 1:
				{
					goto signUpManager;
					break;
				}
			case 2:
				{
					goto signInManager;
					break;
				}
			default:
				{	
					cout << "Nhap lai lua chon cua ban" << endl;
					break;
				}
		}
	}	
/// điều kiện để đăng nhập
	else if (pass1 == pass){
		system("cls");
		cout << "DANG NHAP THANH CONG!" << endl;
		goto menuManager;
		break;
	}
	else if (pass1 != pass){
		system("cls");
		cout << "TEN DANG NHAP HOAC MAT KHAU KHONG DUNG!" << endl;
		cout << "Kiem tra lai \"Ten dang nhap\" hoac \"Mat khau\" cua ban." << endl;
		cout << "Neu ban chua dang ki, dang ki ngay." << endl;
		cout << "Nhap (1) de DANG KI" << endl;
		cout << "Nhap (2) de tiep tuc DANG NHAP" << endl;
		cout << ">>> ";
		cin >> opt;
		/// lệnh này để phòng trường hợp người nhập nhập vào op là kí tự
		while (kiemTraNhap(opt) == false){
			system("cls");
			cout << "Nhap lai!!!" << endl;
			cout << "Nhap (1) de DANG KI" << endl;
			cout << "Nhap (2) de tiep tuc DANG NHAP" << endl;
			cout << ">>> ";
			cin >> opt;
		}
		op = atoi(opt); /// chuyển option sang dạng int
		switch (op)
		{
		case 1:
			{
				goto signUpManager;
				break;
			}
		case 2:
			{
				goto signInManager;
				break;
			}
		default:
			{
				cout << "Nhap lai lua chon cua ban" << endl;
				break;
			}
		}
	}
	else {
		system("cls");
		cout << "DANG NHAP THAT BAI!" << endl;
		goto signInManager;
		break;
	}
}

menuEmployee:
{
	cout << "\t             WELCOME TO MANAGE APP            " << endl << endl;
	cout << "\t *********************************************" << endl;
	cout << "\t|---------------------------------------------|" << endl;
	cout << "\t|---------------------------------------------|" << endl;
	cout << "\t|------------                     ------------|" << endl;
	cout << "\t|------------      Nhan vien      ------------|" << endl;
	cout << "\t|------------                     ------------|" << endl;
	cout << "\t|---------------------------------------------|" << endl;
	cout << "\t|---------------------------------------------|" << endl;
	cout << "\t *********************************************" << endl;
	cout << endl << endl;
	cout <<"Thoat [0]";
	cin >> opt;
	/// lệnh này để phòng trường hợp người nhập nhập vào op là kí tự
	while (kiemTraNhap(opt) == false){
		system("cls");
		cout << "Nhap lai!!!" << endl;
		cout <<"Thoat [0]";
		cout << ">>> ";
		cin >> opt;
	}
	op = atoi(opt); /// chuyển option sang dạng int
	switch (op) {
		case 0:
			goto menu;
			break;
	}
	return 0;
}

menuManager:
{
	cout << "\t             WELCOME TO MANAGE APP            " << endl << endl;
	cout << "\t *********************************************" << endl;
	cout << "\t|---------------------------------------------|" << endl;
	cout << "\t|---------------------------------------------|" << endl;
	cout << "\t|------------                     ------------|" << endl;
	cout << "\t|------------       Quan ly       ------------|" << endl;
	cout << "\t|------------                     ------------|" << endl;
	cout << "\t|---------------------------------------------|" << endl;
	cout << "\t|---------------------------------------------|" << endl;
	cout << "\t *********************************************" << endl;
	cout << endl << endl;
	cout <<"Thoat [0]";
	cin >> opt;
	/// lệnh này để phòng trường hợp người nhập nhập vào op là kí tự
	while (kiemTraNhap(opt) == false){
		system("cls");
		cout << "Nhap lai!!!" << endl;
		cout <<"Thoat [0]";
		cout << ">>> ";
		cin >> opt;
	}
	op = atoi(opt); /// chuyển option sang dạng int
	switch (op) {
		case 0:
			goto menu;
			break;
	}
	return 0;
}
}
}


