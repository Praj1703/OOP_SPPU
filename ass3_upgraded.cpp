#include <iostream>
#include <string>
#include <exception>

using namespace std;

class Publication {
protected:
    string title;
    float price;
public:
    Publication(string t = "No title", float p = 0.0) : title(t), price(p) {}
};

class Books : public Publication {
protected:
    int pages;
public:
    Books(string t = "No title", float p = 0.0) : Publication(t, p), pages(0) {}

    void getb();
    void displayb();
};

class Tape : public Publication {
    float min;
public:
    Tape(string t = "No title", float p = 0.0) : Publication(t, p), min(0.0) {}

    void gett();
    void displayt();
};

void Books::getb() {
    cout << "Enter the details of the book:" << endl;
    cout << "Enter the title of the book: " << flush;
    cin.ignore(1, '\n');
    getline(cin, title);
    cout << "Enter the price of the book: " << flush;
    cin >> price;

    // Added exception handling for price
    try {
        if (price <= 0.0) throw price; // Invalid price
        cout << "Enter the pages of the book: " << endl;
        cin >> pages;

        if (pages <= 0) throw pages; // Invalid pages

        if (pages > 500 && pages < 1500) {
            if (price > 100 && price < 2000) {
                displayb();
            } else throw price; // Invalid price range
        } else throw pages; // Invalid pages range
    } catch (float p) {
        cout << "Caught an exception in function of book: Invalid price" << endl;
        title = "0";
        price = 0.0;
        pages = 0;
        displayb();
    } catch (int p) {
        cout << "Caught an exception in function of book: Invalid page count" << endl;
        title = "0";
        price = 0.0;
        pages = 0;
        displayb();
    } catch (...) {
        cout << "Caught an unknown exception in function of book" << endl;
    }
}

void Books::displayb() {
    cout << "The Book you Entered is:" << endl;
    cout << "The Entered Title is: " << title << endl;
    cout << "The Entered price is: " << price << endl;
    cout << "The Entered pages are: " << pages << endl;
}

void Tape::gett() {
    cout << "Enter the details of the tape:" << endl;
    cout << "Enter the title of the tape: " << flush;
    cin.ignore(1, '\n');
    getline(cin, title);
    cout << "Enter the price of the tape: " << flush;
    cin >> price;

    // Added exception handling for price
    try {
        if (price <= 0.0) throw price; // Invalid price
        cout << "Enter the playing time in minutes: " << endl;
        cin >> min;

        if (min <= 0) throw min; // Invalid playing time

        if (min > 30.00 && min < 90.00) {
            if (price > 500 && price < 1000) {
                displayt();
            } else throw price; // Invalid price range
        } else throw min; // Invalid playing time range
    } catch (float p) {
        cout << "Caught an exception in function of tape: Invalid price" << endl;
        title = "0";
        price = 0.0;
        min = 0.0;
        displayt();
    } catch (float m) {
        cout << "Caught an exception in function of tape: Invalid playing time" << endl;
        title = "0";
        price = 0.0;
        min = 0.0;
        displayt();
    } catch (...) {
        cout << "Caught an unknown exception in function of tape" << endl;
    }
}

void Tape::displayt() {
    cout << "The Tape you Entered is:" << endl;
    cout << "The Entered Title is: " << title << endl;
    cout << "The Entered price is: " << price << endl;
    cout << "The Entered play_time is: " << min << endl;
}

int main() {
    Books b;
    Tape t;
    int choice;
    cout << "Do you want to buy a book (enter 1) or a tape (enter 2): " << flush;
    cin >> choice;

    switch (choice) {
        case 1:
            try {
                b.getb();
            } catch (int i) {
                cout << "Caught the exception in int main()" << endl;
            }
            break;

        case 2:
            try {
                t.gett();
            } catch (float f) {
                cout << "Caught the exception in int main()" << endl;
            }
            break;

        default:
            cout << "Entered bad choice! Try Again" << endl;
    }
    return 0;
}

