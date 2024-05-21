#include <bits/stdc++.h> 

using namespace std;

struct company{
    string name;
    double propit,value;
};

bool xapxep(const company& a, const company& b){
    return a.propit > b.propit; 
}
double getnumber(const string& s){
    int unit =1;
    if(s.back()=='B'){
        unit = 1000;
    }
    string only_num;
    bool so_am=false;
    for(char c : s){
        if(c=='-'){
            so_am=true;
        }else if(isdigit(c)){
            only_num+=c;
        }else if(c=='.'){
            only_num+=c;
        }
    }
    if(only_num.empty()){
        return 0.0;
    }

    double num= stod(only_num)*unit;
    if(so_am){
        num=-num;
    }
    return num;
}


int main(int argc, char* argv[]){

    if(argc != 3){
        cout<<"input thieu";
        exit(0);
    }

    string part;
    bool check_part =false;
    for(int i = 0; i< argc; ++i){
        if(string(argv[i]) == "-p"){
            part= argv[i+1];
            check_part=true;
        }
    }
    if(!check_part){
        cout<<"input thieu";
        exit(0);
    }

    ifstream infile;
    infile.open(part);

    if(!infile.is_open()){
        cout<<"Ko mo duoc file ";
        exit(0);
    }

    vector<company> ds;
    company com1;
    string line;

    getline(infile,line);

    while(getline(infile,line)){
        istringstream iss(line);
        string token;
        
        getline(iss,token,',');
        getline(iss,token,',');
        com1.name=token;
        getline(iss,token,',');
        getline(iss,token,',');
        getline(iss,token,',');
        com1.propit = getnumber(token);
        getline(iss,token,',');
        getline(iss,token,',');
        getline(iss,token,',');
        getline(iss,token,',');
        com1.value= getnumber(token);
        ds.push_back(com1);
    }
    sort(ds.begin(), ds.end(), xapxep);

    for(int i=0; i< 10; ++i){
        cout<<i+1 <<"."<<ds[i].name <<" "<< ds[i].propit <<" " << ds[i].value <<endl;
    }
    for(int i=0; i< ds.size(); ++i){
        if(ds[i].propit < 0){
             cout<<i+1 <<"."<<ds[i].name <<" "<< ds[i].propit <<" " << ds[i].value <<endl;
        }
       
    }
    infile.close();
    return 0;
}