#include <iostream>
#include <string>
#include <string.h>
#include <istream>
#include <fstream>
using namespace std;

void layIDDaDungTuFile(string tenFile, int &RegisterID){
	string line;
	char* kyTu;
	fstream layIDDaDung;
	layIDDaDung.open(tenFile);
	layIDDaDung.seekg(-1, ios::end);
	getline(layIDDaDung, line);
	kyTu[1] = line[0];
	RegisterID = atoi(&kyTu[1]);
    // cout << "RegisterID: " << RegisterID;
	layIDDaDung.close();
}

void ghiIDDaDungVaoFile(string tenFile, int &RegisterID){
	fstream ghiIDDaDung;
	ghiIDDaDung.open(tenFile);
	ghiIDDaDung << RegisterID;
	ghiIDDaDung.close();
}
int main(){
    int employeeID;
   	layIDDaDungTuFile("IDNV_DaDung.txt", employeeID); // lấy id
    // cout << employeeID;
        cout << "RegisterID1: " << employeeID;
    for(int i=0; i<3; i++){
        employeeID++;
        cout << "RegisterID2: " << employeeID;

        ghiIDDaDungVaoFile("IDNV_DaDung.txt", employeeID);
    };
}