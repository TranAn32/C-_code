#include <iostream>
#include <fstream>
#include <vector>

using namespace std;

bool checktontai(vector<string> v, string word){
    for(auto a : v){
        if(a==word) return true;
    }
    return false;
}

int main(int argc, char *argv[]){
    ifstream file;

    file.open(argv[1]);// nhập vào đường dẫn file ở cmt line là phần tử số 1 của argv

    if(!file.is_open()){
        cout<<"ERROR";
        exit(0);
    }else cout<<"file loaded.." << endl;

    int x,sum=0;
    int dem=0;
    string word;
    vector<string> v;
    
    // chuyền từng từ để xét, đây là trường hợp chuyền từ ở file để lấy từng từ nếu như muốn lấy từng từ ở string cho trước thì phải dùng hàm istringstream iss(sau) và dùng while( iss >> word) để lấy từng từ trong string đó
    while(file >> word){
        cout<< word << " ";
        if(!checktontai(v,word)){
            v.push_back(word);
        } 
    }

    cout << endl;

    for(auto s : v){
        cout << s << " ";
    }
    
    file.close();


}