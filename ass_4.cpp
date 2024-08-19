#include <fstream>
#include <iostream>

using namespace std;

int main() {
    char data[100];
    string line;

    ofstream outfile;
    outfile.open("data1.txt");
    
    cout << "..............Writing to the file..........." << endl;

    cout << "Enter Your name:" << endl;
    cin.getline(data, 100);
    
    outfile << data << endl;

    cout << "Enter Your age:" << endl;
    cin >> data;
    cin.ignore();
    
    outfile << data << endl;

    outfile.close();

    ifstream infile;
    infile.open("data1.txt");

    cout << "*************Reading from the file:*****************" << endl;

    /*infile >> data;
    cout << data << endl;
    
    infile >> data;
    cout << data << endl;
    */
    
    while (getline(infile, line)) {
      
        
        cout << line << endl;
    }
    
    infile.close();

    return 0;
}

