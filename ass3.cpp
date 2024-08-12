#include<iostream>
#include<cstring>
#include<exception>

using namespace std;

class publication{
	protected:
		string title;
		float price;
	public:
		publication(string t ="No title", float p = 0.0){}
};

class books:public publication{
	protected:
	int pages;
	public:
		books(string t ="No title ", float p = 0.0){}
		
		void getb();
		void displayb();
	
};

class tape:public publication{
	float min;
	public:
		tape(string t ="No title ", float p = 0.0){}		
		void gett();
		void displayt();
	
};

void books::getb(){
	cout<<"Enter the details of the book :"<<endl;
	cout<<"Enter the title of the book: "<<flush;
	cin.ignore(1,'\n');
	getline(cin,title);
	cout<<"Enter the price of the book: "<<flush;
	cin>>price;
	cout<<"Enter the pages of the book: "<<endl;
	cin>>pages;
	
	try{
		if(pages>500 && pages<1500){
			if(price>100 && price<2000){
				displayb();
			}
		}
		else throw(pages),throw(price);
	}
	catch (int i){
	cout<<"Cought the exception in function of book :"<<endl;
	cout<<"You entered an invalid data"<<endl;
	title = "0";
	price = 0.0;
	pages = 0;
	displayb();
	throw;
	
	}
}

void books::displayb(){
	cout<<"The Book you Entered is: "<<endl;
	cout<<"The Entered Title is: "<<title<<endl;
	cout<<"The Entered price is: "<<price<<endl;
	cout<<"The Entered pages are: "<<pages<<endl;
}


void tape :: gett(){
	cout<<"Enter the details of the tape :"<<endl;
	cout<<"Enter the title of the tape: "<<flush;
	cin.ignore(1,'\n');
	getline(cin,title);
	cout<<"Enter the price of the tape: "<<flush;
	cin>>price;
	cout<<"Enter the playing time in minutes: "<<endl;
	cin>>min;
	
	try{
		if(min>30.00 && min<90.00){
			if(price>500 && price<1000){
				displayt();
			}
		}
		else throw(min),throw(price);
	}
	catch (float f){
	cout<<"Cought the exception in function of tape :"<<endl;
	cout<<"You entered an invalid data"<<endl;
	title = "0";
	price = 0.0;
	min = 0.0;
	displayt();
	throw;
	
	}
}

void tape::displayt(){
	cout<<"The Book you Entered is: "<<endl;
	cout<<"The Entered Title is: "<<title<<endl;
	cout<<"The Entered price is: "<<price<<endl;
	cout<<"The Entered play_time is: "<<min<<endl;
}

int main(){
	books b;
	tape t;
	int choice;
	cout<<"Do you want to buy a book (enter 1) or a tape (enter 2): "<<flush;
	cin>>choice;
	
	switch(choice){
		case 1:
		try {
			b.getb();
		}
		catch(int i){
			cout<<"Cought the exception in int main()"<<endl;
		}
		break;
		
		case 2:
		try {
			t.gett();
		}
		catch(float f){
			cout<<"Cought the exception in int main()"<<endl;
		}
		break;
		default:
		
		cout<<"Entered bad choice! Try Again"<<endl;
		
	}
return 0;
}
