#include <iostream>
#include <fstream>
#include <string>

using namespace std;

ifstream& open_file(ifstream& in, const string &file){
    in.close();
    in.clear();
    in.open(file.c_str());
    return in;
}

istream& get(istream& in){
    string  ival;
    while(in >> ival, !in.eof()){
        if(in.bad())
            throw runtime_error("IO stream corrupted");
        if(in.fail()){
            cerr << "bad data, try again";
            in.clear();
            in.ignore(1, ' ');
            continue;
        }
        cout << ival << " ";
    }
    in.clear();
    return in;

}


int main(){
    string fileName, s;
    cout << "Enter filename:" << endl;
    cin >> fileName;

    ifstream inFile;
    if(!open_file(inFile, fileName.c_str())){
        cerr << "error: can not open file:"
             << fileName << endl;
        return -1;
    }
    get(inFile);
    inFile.close();
    return 0;
}
