#include <bits/stdc++.h>


using namespace std;

string xoakitu(const string &word) { // hàm xóa các kí tự đặc biệt trong sâu
    string text;
    for (char c : word) {
        c=tolower(c);
        if (c != ',' && c != '.' && c != '(' && c != ')' && c != '?' && c != '!' && c != '-') {
            text += c;
        }
    }
    return text;
}

int check_position(vector<string>& words, string& w ){ // hàm kiểm tra tồn tại một từ đã xuất hiện chưa
    for(int i=0;i<words.size();i++){
        if(words[i]==w){
            return i;
        }
    }return -1;
}
void xapxep(vector<string>& words, vector<int>& counts) { // hàm xắp xếp theo số counts từ lớn đến bé
    int n = words.size();
    for (int i = 0; i < n - 1; ++i) {
        for (int j = i + 1; j < n; ++j) {
            if (counts[i] < counts[j]) {
                int tempCount = counts[i];
                counts[i] = counts[j];
                counts[j] = tempCount;
                
                string tempWord = words[i];
                words[i] = words[j];
                words[j] = tempWord;
            }
        }
    }
}
void xapxeptu(vector<string> &word, vector<int> &count) { //hàm xắp xếp theo bảng chữ cái
    for (int i = 0; i < word.size(); ++i) {
        for (int j = i + 1; j < word.size(); ++j) {
            if (count[i] == count[j] && word[i] < word[j]) {
                string temp2=word[i];
                word[i]= word[j];
                word[j]=temp2;

                int temp1= count[i];
                count[i]=count[j];
                count[j] = temp1;
            }
        }
    }
}

void bien_thuong(string &s){// hàm chuyển thành chữ thường
    for( auto &c : s){
        c=tolower(c);
    }
}


int main(int argc, char *argv[]){
    vector<string> name;

    for(int i= 1;i<argc;++i){
        name.push_back(argv[i]);
    }
    /*string s="Imagine you are taking a walk in a lush green park on an early morning?. The air is fresh and cool, and you hear the songs of various birds. You stroll along the small path by the lake, and you see the first rays of sunlight filtering through the trees. This feeling is truly wonderful and relaxing!";

    istringstream iss(s);

    cách nhập vào từ 1 string cho trước
    */



    vector<string> words;
    vector<int> counts;
    // do các kí tự được lưu lại trong vector name rồi nên dùng for() nếu như sâu chưa được lưu lại thì phải chuyền vào một sring khác while(iss/infile >> token) với token là string, iss/infile tùy bài cho string sẵn hoặc phải nhập từ file
    for(auto c : name){
        c=xoakitu(c);
        int position=check_position(words,c);
        if(position==-1){
            words.push_back(c);
            counts.push_back(1);
        }else counts[position]+=1;
    }
    xapxep(words,counts);
    xapxep(words,counts);
    for(int i = 0; i<words.size() ;++i){
        cout<< words[i] << ": " << counts[i] <<endl;
    }

    int countmax =counts[0];
    string namemax= words[0];

    for(int i=0; i<words.size() ;++i){
        if(countmax == counts[i] && namemax > words[i]){
            namemax = words[i];
        }
    }
    cout<< "Nguoi co so phieu cao nhat la: " << endl;
    cout<< namemax <<": " << countmax <<endl;
    
}