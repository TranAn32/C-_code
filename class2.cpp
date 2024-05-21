#include <bits/stdc++.h>

using namespace std;

class Animal{
    public:
    const int id;
    const string sex;
    string name;
    double cao,nang;
    int age;
    Animal(); 
    void display();
    double getBMI();
    Animal(const Animal& a);
    Animal& operator =(const Animal& b);

   
    
};
void Animal :: display(){
        cout << "Ten" <<name <<endl << "sex" << sex<< endl << "cao" << cao << endl << "nang" <<nang <<endl;
    }
double Animal :: getBMI(){
    double BMI = nang/(cao*cao);
    return BMI;
}
Animal::Animal(const Animal& a):id(a.id),sex(sex){
    name=a.name;
    cao=a.cao;
    age=a.age;
    nang=a.nang;
    cout<<"A copy of " <<id <<" has been created" << endl;
}
Animal& Animal ::operator =(const Animal& b){
    name =b.name;
    cao = b.cao;
    age = b.age;
    nang = b.nang;
    return *this;
}

int main(){

}

