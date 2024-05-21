#include <bits/stdc++.h>

using namespace std;

struct Company {
    string name;
    double profit;
    double value;
};

bool sortByProfit(const Company& a, const Company& b) {
    return a.profit > b.profit;
}

double getNumber(const string& s) {
    int unit =1;
    if(s.back()=='B'){
        unit=1000;
    }
    
    string only_num;
    bool so_am=false;
    for(char c : s){
        if(c == '-'){
            so_am=true;
        }else if(isdigit(c)){
            only_num += c;
        }else if(c == '.'){
            only_num +=c;
        }
    }
    double num = stod(only_num)*unit;
    if(so_am){
        num=-num;
    }
    return num;
}
//Lưu thành từng file
/*
void createCompanyInfoFile(const Company& company) {
    string filename = company.name + ".txt";
    ofstream outfile(filename);
    if (!outfile.is_open()) {
        cout << "ERROR " << endl;
        return;
    }
    outfile << "Name: " << company.name << endl;
    outfile << "Profit: " << company.profit << endl;
    outfile << "Value: " << company.value << endl;
    outfile.close();
    cout << "file  " << company.name << " compl." << endl;
}*/
//Lưu 1 file
void tao_file(const Company& ds, ofstream& file_company ){
    file_company << "Company name: " << ds.name << endl;
    file_company << " Profit: " << ds.profit << endl;
    file_company << "Value: " << ds.value << endl;

}

int main(int argc, char* argv[]) {
    if (argc != 3) {
        cout << "INPUT thieu " << endl;
        return 1;
    }
    string part;
    bool check_part = false;
    for(int i = 0; i< argc; ++i){
        if(string(argv[i]) =="-p"){
            cout << " asda"<< endl;
            check_part =true;
            part=argv[i+1];
        }
    }
    if(!check_part){
        cout <<" Input thieu -p " <<endl;
        exit(0);
    }

    ifstream infile;
    infile.open(part);

    if (!infile.is_open()) {
        cout << "Ko mo duoc file " << endl;
        return 1;
    }

    vector<Company> ds;
    string line;

    getline(infile, line); 

    while (getline(infile, line)) {
        istringstream iss(line);
        string token;

        Company com;
        getline(iss, token, ','); 
        getline(iss, token, ','); 
        getline(iss, com.name, ',');
        getline(iss, token, ',');
        getline(iss, token, ',');
        com.profit = getNumber(token);
        getline(iss, token, ',');
        getline(iss, token, ',');
        getline(iss, token, ',');
        com.value = getNumber(token);
        ds.push_back(com);

    }

    

    sort(ds.begin(), ds.end(), sortByProfit);
    infile.close();

    /*for (const Company& company : ds) {
        createCompanyInfoFile(company);
    }*/
    ofstream file_company;
    file_company.open("file_company.txt");
    for( const Company& com : ds){
        tao_file(com,file_company);
    }
    


    return 0;
}
