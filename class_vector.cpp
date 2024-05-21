#include <bits/stdc++.h>
using namespace std;

class File{
    public:
    int id;
    string name,path;
    double size;
    string type;
    File(int id,string name, string path, double size,string type): id(id),name(name),path(path),size(size),type(type){};
    virtual void display(){
        cout<<"--------------"<<endl;
        cout<<"id: "<<id<<endl<<"file " << name<<endl <<"Duong dan: "<<path<<endl<<"kich thuoc: " <<size <<endl<<"Loai file: "<<type<<endl;
    }
};
class Video:public File{
    public:
    string duration;
    string resolution;
    Video(int id,string name, string path, double size,string duration,string resolution,string type) : File(id,name,path,size,type),duration(duration),resolution(resolution){};
    void display(){
        cout<<"-------------->3"<<endl;
        cout<<"id: "<<id<<endl<<"file " << name<<endl <<"Duong dan: "<<path<<endl<<"kich thuoc: " <<size <<endl<<"Loai file: "<<type<<endl;
    }
    
};
class Document:public File{
    public:
    int numPage;
    string title;
    Document(int id,string name, string path, double size,int numPage,string title,string type) : File(id,name,path,size,type),numPage(numPage),title(title){};
    void display(){
        cout<<"-------------->1"<<endl;
        cout<<"id: "<<id<<endl<<"file " << name<<endl <<"Duong dan: "<<path<<endl<<"kich thuoc: " <<size <<endl<<"Loai file: "<<type<<endl;
    }
};
class Music:public File{
    public:
    string namesong;
    double bitrate;
    Music(int id,string name, string path, double size,string namesong,double bitrate,string type) : File(id,name,path,size,type),namesong(namesong),bitrate(bitrate){};
    void display(){
        cout<<"-------------->2"<<endl;
        cout<<"id: "<<id<<endl<<"file " << name<<endl <<"Duong dan: "<<path<<endl<<"kich thuoc: " <<size <<endl<<"Loai file: "<<type<<endl;
    }
};
int main(int argv, char* argc[]){
    Video file_video(1,"video","C:\\video.mp4",4.2,"3:02 p","Video sinh nhat","mp4");
    file_video.display();
    Document file_Document(2,"taiLieu","C:\\baocao.txt",1.2,32,"Bao cao","text");
    file_Document.display();
    Music file_Music(3,"Music","C:\\Music.mp3",2.2,"Nang",5.3,"mp3");
    file_Music.display();
    vector<File* > folder;
    folder.push_back(&file_Document);
    folder.push_back(&file_Music);
    folder.push_back(&file_video);
    for(auto file : folder){
        file->display();
    }


}