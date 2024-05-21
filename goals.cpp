#include <bits/stdc++.h>

using namespace std;

struct math{
    string name_home_team;
    string name_away_team;
    int tiso_home_team;
    int tiso_away_team;
    string result;
    string season;

};
bool xapxep(const pair<string, int>& a, const pair<string, int>& b) {
    return a.second > b.second;
}

int main(int argc, char *argv[]){
    if(argc != 5){
        cout<<"input sai" << endl;
        exit(0);
    }

    bool timthayP= false ,timthayN = false;


    string path;
    int n;
    for(int i= 0; i < argc ;++i){
        if(string(argv[i])== "-p"){
            path= argv[i+1];
            timthayP= true;
        }else if(string(argv[i])=="-n"){
            n=stoi(argv[i+1]);
            timthayN= true;
        }
    }
    if(!timthayN || !timthayP){
        cout<< "INPUT thieu" <<endl;
        exit(0);
    }

    ifstream infile;
    infile.open(path);

    if(!infile.is_open()){
        cout<<"ERROR";
        exit(0);
    }else cout<<"file loaded.." << endl;

    vector<math> danhsach;
    math a1;
    string line;
    getline(infile, line);
    while(getline(infile,line)){
        istringstream iss(line);
        string token;
        getline(iss,token,',');
        a1.name_away_team=token;
        getline(iss,token,',');
        a1.name_home_team=token;
        getline(iss,token,',');
        a1.tiso_away_team=stoi(token);
        getline(iss,token,',');
        a1.result=token;
        getline(iss,token,',');
        a1.season=token;

        danhsach.push_back(a1);
    }
    map<string,int> point;
    int point_home_team;
    int point_away_team;
    for(int i = 0;  i < danhsach.size(); ++i){
        if(danhsach[i].tiso_away_team > danhsach[i].tiso_home_team){
            point_away_team +=3;
        }else if(danhsach[i].tiso_away_team < danhsach[i].tiso_home_team){
            point_home_team +=3;
        }else{
            point_away_team +=1;
            point_home_team +=1;
        }
        point[danhsach[i].name_home_team]=point_home_team;
        point[danhsach[i].name_away_team]=point_away_team;
        
    }
    // chuyển từ một map -> vector
    vector<pair<string, int>> topTeams;
    for (const auto& c : point) {
        topTeams.push_back(c); 
    }
    
    sort(topTeams.begin(),topTeams.end(),xapxep);

    for (int i =0; i< n ; ++i) {
        cout << topTeams[i].first << ": " << topTeams[i].second << " point" << std::endl;
    }
    



    infile.close();
}