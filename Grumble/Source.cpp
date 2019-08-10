#include <iostream>
#include <string>

using namespace std;

void menuCtrl();
void menuView();
void addCompView();

#define logln(x) cout << x << endl;
#define log(x) cout << x;

int main() {

	menuCtrl();

}

void menuCtrl() {

	//DISPLAY MAIN MENU
	menuView();


	//GET RESPONSE
	log("\n\t\t\t	Enter your choice: ");
	char in;
	cin >> in;

	while (!(in == '1' || in == '2'|| in == '3'|| in == '4' || in == '5')) {
		system("cls");
		menuView();
		log("\n\t\t\t	Enter a valid choice: ");
		cin >> in;
	}


	//HANDLE RESPONSE
	switch (in) {
	case '1':
		//add complaint
		system("cls");
		addCompView();
		break;
	case '2':
		//remove complaint
		break;
	case '3':
		//update complaint
		break;
	case '4':
		//view all complaints
		break;
	case '5':
		//exit
		break;
	}
	

}

void menuView() {

	logln("\n\t\t\t===========================================");
	logln("\n\t\t\t    I-CALL COMPLAINT MANANGEMENT SYSTEM    ");
	logln("\n\t\t\t===========================================");
	logln("\n\t\t\t    INPUT  (1)	 TO ADD A COMPLAINT");
	logln("\t\t\t-------------------------------------------");
	logln("\t\t\t    INPUT  (2)	 TO REMOVE A COMPLAINT");
	logln("\t\t\t-------------------------------------------");
	logln("\t\t\t    INPUT  (3)	 TO UPDATE A COMPLAINT");
	logln("\t\t\t-------------------------------------------");
	logln("\t\t\t    INPUT  (4)	 TO VIEW ALL COMPLAINTS");
	logln("\t\t\t-------------------------------------------");
	logln("\t\t\t    INPUT  (5)	 TO EXIT");
	logln("\t\t\t-------------------------------------------");
}

void addCompView() {

	logln("\n\t\t\t===========================================");
	logln("\n\t\t\t              ADD A COMPLAINT              ");
	logln("\n\t\t\t===========================================");
}