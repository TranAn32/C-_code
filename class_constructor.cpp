#include <bits/stdc++.h>

using namespace std;

class Rec{
    public:
    int x,y;
    double dai,rong;
    string mau;
    const int id;
    //constructor
    Rec(int id, int x,int y, double dai, double rong, string mau):id(id),x(x),y(y),dai(dai),rong(rong),mau(mau){
       cout<<"An Empty Rec has been created\n";
    }
    void display(){
        cout<<"chieu dai: "<< dai<<endl<<"chieu rong: " << rong<<endl <<"Mau: " << mau <<endl;
    }
    double chu_vi(){
        return (dai +rong)*2;
    }
    double dien_tich(){
        return dai*rong;
    }
    void doimau(string mau_moi){
        mau=mau_moi;
    }

    //copy constructor
    //copy toàn bộ:
    Rec(const Rec& a):id(a.id){
        x=a.x;
        y=a.y;
        dai=a.dai;
        rong =a.rong;
        mau=a.mau;
        cout<<"A copy of " <<id <<" has been created" << endl;
    }
    //copy 1 phần:
    Rec(const Rec& a,string mau):id(a.id){
        x=a.x;
        y=a.y;
        dai=a.dai;
        rong =a.rong;
        this -> mau=mau;//không copy mầu
        cout<<"A copy of " <<id <<" has been created" << endl;
    }

    //assigment constructor: phép gán
    Rec& operator = (const Rec& b){ //không áp dụng đc với id vì id là một conts
        cout<<"ASSIGN "<< id << " = " <<b.id <<endl;
        x=b.x;
        y=b.y;
        dai=b.dai;
        rong=b.rong;
        mau=b.mau;
        return *this;//Nhớ
    }
    
};
/* đưa ra ngoài class
Rec::Rec(const Rec& a) : id(a.id) {
    x = a.x;
    y = a.y;
    dai = a.dai;
    rong = a.rong;
    mau = a.mau;
    cout << "A copy of " << id << " has been created" << endl;
}

// Copy constructor (copy all attributes except mau)
Rec::Rec(const Rec& a, string mau) : id(a.id) {
    x = a.x;
    y = a.y;
    dai = a.dai;
    rong = a.rong;
    this->mau = mau; // Don't copy mau
    cout << "A copy of " << id << " has been created" << endl;
}
Rec& Rec::operator=(const Rec& b) {
    if (this != &b) { // Check for self-assignment
        x = b.x;
        y = b.y;
        dai = b.dai;
        rong = b.rong;
        mau = b.mau;
        cout << "ASSIGN " << id << " = " << b.id << endl;
    }
    return *this;
}
*/
    

int main(){
    Rec Rec1(122,1,2,2.3,4.2,"xanh");
    //copy constructor
    Rec r_copy1 = Rec1;
    r_copy1.display();
    //copy 1 phần:
    Rec r_copy2(Rec1,"vang");

    cout<<"assigment constructor" << endl;
    //assigment constructor: phép gán
    //Trong trường hợp này, r_copy3 = Rec1; là một phép gán giữa hai đối tượng thuộc cùng kiểu Rec, nên assignment operator sẽ được gọi tự động. Hàm assignment operator đã được định nghĩa trong lớp Rec để sao chép giá trị từ Rec1 sang r_copy3.
    Rec r_copy3(4,1,1,1,1,"vang"); 
    
    r_copy3= Rec1;
    r_copy3.display();

}
