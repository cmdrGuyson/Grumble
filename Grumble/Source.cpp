#include <iostream>
#include <string>

#define logln(x) cout << x << endl;
#define log(x) cout << x;

using namespace std;

struct ComplaintInfo
{
	int complaintNum;
	string complaintID;
	string customerName;
	string customerAddress;
	string complaint;
	string contactNumber;
	string date;
	struct ComplaintInfo* nextPtr;
};

typedef ComplaintInfo* ComplaintInfoPtr;

void menuCtrl();
void menuView();
void addCompView();
void addCompCtrl(ComplaintInfoPtr* startPtr);
void viewAllComplaints(ComplaintInfoPtr startPtr);

int main() {

	menuCtrl();

}

void menuCtrl() {

	ComplaintInfoPtr startPtr = NULL;

	/* Display Main Menu */
	menuView();


	/* Get User Response */
	log("\n\t\t\t	Enter your choice: ");
	char in;
	cin >> in;

	while (!(in == '1' || in == '2'|| in == '3'|| in == '4' || in == '5')) {
		system("cls");
		menuView();
		log("\n\t\t\t	Enter a valid choice: ");
		cin >> in;
	}


	/* Handle User Response */
	while (in != '5') {
		switch (in) {
		case '1':
			//add complaint
			system("cls");
			addCompView();
			addCompCtrl(&startPtr);
			break;
		case '2':
			//remove complaint
			break;
		case '3':
			//update complaint
			break;
		case '4':
			//view all complaints
			system("cls");
			viewAllComplaints(startPtr);
			break;
		}
		system("cls");
		menuView();
		log("\n\t\t\t	Enter your choice: ");
		cin >> in;
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

void addCompCtrl(ComplaintInfoPtr* startPtr) {

	int complaintNum;
	string complaintID, customerName, customerAddress, complaint, contactNumber, date;

	/* Ask for user input */
	log("\tEnter Complaint Number: C");
	cin >> complaintID;
	cin.ignore(100, '\n');
	complaintNum = stoi(complaintID);

	log("\tEnter Customer Name: ");
	getline(cin, customerName);

	log("\tEnter Customer Address: ");
	getline(cin, customerAddress);

	log("\tEnter Complaint Description: ");
	getline(cin, complaint);

	log("\tEnter Contact Number: ");
	cin >> contactNumber;

	log("\tEnter Date: ");
	cin >> date;

	complaintID = "C" + complaintID;

	/* Add to data Structure*/

	ComplaintInfoPtr newPtr = NULL;
	ComplaintInfoPtr previousPtr = NULL;
	ComplaintInfoPtr currentPtr = NULL;

	newPtr = new ComplaintInfo;


	if (newPtr != NULL) {

		newPtr->complaintNum = complaintNum;
		newPtr->complaintID = complaintID;
		newPtr->customerName = customerName;
		newPtr->customerAddress = customerAddress;
		newPtr->complaint = complaint;
		newPtr->contactNumber = contactNumber;
		newPtr->date = date;
		newPtr->nextPtr = NULL;

		previousPtr = NULL;
		currentPtr = *startPtr;

		while (currentPtr != NULL && complaintNum > currentPtr->complaintNum) {
			previousPtr = currentPtr;
			currentPtr = currentPtr->nextPtr;
		}

		if (previousPtr == NULL) {
			newPtr->nextPtr = *startPtr;
			*startPtr = newPtr;
		}
		else {
			previousPtr->nextPtr = newPtr;
			newPtr->nextPtr = currentPtr;
		}
	}
	else {
		logln("Entry not added! No memory available.");
	}

}

void viewAllComplaints(ComplaintInfoPtr startPtr) {

	logln("\n\t\t\t===========================================");
	logln("\n\t\t\t           VIEW ALL COMPLAINTS             ");
	logln("\n\t\t\t===========================================\n");\

	if (startPtr == NULL) {
		logln("/n There are no complaints!");
	}
	else {
		while (startPtr != NULL) {
			logln("---------------------------------------------");
			logln("\n\tComplaint ID: " << startPtr->complaintID);
			logln("\n\tCustomer Name: " << startPtr->customerName);
			logln("\n\tCustomer Address: " << startPtr->customerAddress);
			logln("\n\tContact Number: " << startPtr->contactNumber);
			logln("\n\tComplaint Description: " << startPtr->complaint);
			startPtr = startPtr->nextPtr;
		}
	}

	logln("---------------------------------------------");
	logln("\n\n");
	system("pause");

}