#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>
#include "strumienie.hpp"
using namespace std;
using namespace strumienie;

bool My_cmp(pair<int, string> p1, pair <int,string> p2){
    return (p1.second < p2.second);
}

int main(int argc, char* argv[])
{
    int actual_nr = 1;
    fstream File;
    string line;
    vector <pair<int, string> > stringi;

    if(argc<=1){
        cout<< "dupa blada";
        return 0;
    }

    File.open(argv[1], ios::in);
    if(File.good()){
        while (!File.eof()){
            getline(File, line);
            stringi.push_back(make_pair(actual_nr, line));
            actual_nr++;
        }
    File.close();
    }
    sort(stringi.begin(), stringi.end(), My_cmp);
    for (pair<int, string>& p : stringi)
        cout << Index(2, p.first) << comma << p.second << endl;

    return 0;
}
