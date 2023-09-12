#include <iostream>
#include <string>
#include <fstream>
using namespace std;

string removewhitespace(string line){
    
}
int main()
{
    ifstream file("cars.txt");
    // while(file){
    //     string line;
    //     getline(file,line);
    //     cout<<line<<endl;
    // }

    while (file)
    {
        string tag, Maker, Condition;
        int Top_speed;
        getline(file, tag, ',');
        getline(file, Maker, ',');
        getline(file, Condition, ',');
        file >> Top_speed;
        cout << tag << endl;
        cout << Maker << endl;
        cout << Condition << endl;
        cout << Top_speed << endl;
    }
    return 0;
}