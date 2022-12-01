#include <conio.h>
#include <iostream>
#include <string>
using namespace std;
string inputPassword(string &pass)
{
    size_t length_max;
    // string pass;
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
    cout << endl << endl;
    return pass;
}
 
int main()
{
    string strHello("Hello world !!!");
    cout << strHello << endl;
    string pass;
 
    cout << "Password: ";
    inputPassword(pass); // Nhập chuỗi mật khẩu dài tối đa 20 kí tự
    cout << pass << endl;
    cout << pass << endl;
    cout << pass << endl;

    // cin.get();
    return 0;
}