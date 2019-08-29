#include <iostream>
#include <string>
#include <regex>

#define logln(x) cout << x << endl;
#define log(x) cout << x;

using namespace std;

/*MAIN DATA STRUCTURE*/
struct ComplaintInfo
{
	int complaintNum;
	string customerName;
	string customerAddress;
	string complaint;
	string contactNumber;
	string date;
	string status;
	struct ComplaintInfo* nextPtr;
};


typedef ComplaintInfo* ComplaintInfoPtr;

/*PROTOTYPES*/
void menuCtrl();
void menuView();
void addCompView();
void addCompCtrl(ComplaintInfoPtr* startPtr);
void viewAllComplaints(ComplaintInfoPtr startPtr);
void viewSingleComplaintCtrl(ComplaintInfoPtr startPtr);
bool viewSingleComplaint(ComplaintInfoPtr startPtr, int searchKey);
bool verifyCompNum(ComplaintInfoPtr startPtr, int searchKey);



/*MAIN*/
int main() {

	menuCtrl();

}



/*MAIN MENU CONTROLER*/
void menuCtrl() {

	ComplaintInfoPtr startPtr = NULL;

	/* Display Main Menu */
	menuView();


	/* Get User Response */
	log("\n\t\t\t	Enter your choice: ");
	char in;
	cin >> in;

	while (!(in == '1' || in == '2' || in == '3' || in == '4' || in == '5' || in == '6' || in == '7' || in == '0')) {
		system("cls");
		menuView();
		log("\n\t\t\t	Enter a valid choice: ");
		cin >> in;
	}


	/* Handle User Response */
	while (in != '0') {
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
		case '5':
			//view single complaint
			system("cls");
			viewSingleComplaintCtrl(startPtr);
			break;
		case '6':
			//view all addressed complaints
			break;
		case '7':
			//view all removed complaints
			break;
		}
		system("cls");
		menuView();
		log("\n\t\t\t	Enter your choice: ");
		cin >> in;
	}



}

/*MAIN MENU DISPLAY*/
void menuView() {

	logln("\n\t\t\t===================================================");
	logln("\n\t\t\t        I-CALL COMPLAINT MANANGEMENT SYSTEM        ");
	logln("\n\t\t\t===================================================");
	logln("\n\t\t\t    INPUT  (1)	 TO ADD A COMPLAINT");
	logln("\t\t\t---------------------------------------------------");
	logln("\t\t\t    INPUT  (2)	 TO REMOVE A COMPLAINT");
	logln("\t\t\t---------------------------------------------------");
	logln("\t\t\t    INPUT  (3)	 TO UPDATE A COMPLAINT");
	logln("\t\t\t---------------------------------------------------");
	logln("\t\t\t    INPUT  (4)	 TO VIEW ALL COMPLAINTS");
	logln("\t\t\t---------------------------------------------------");
	logln("\t\t\t    INPUT  (5)	 TO SINGLE COMPLAINT");
	logln("\t\t\t---------------------------------------------------");
	logln("\t\t\t    INPUT  (6)	 TO VIEW ALL ADDRESSED COMPLAINTS");
	logln("\t\t\t---------------------------------------------------");
	logln("\t\t\t    INPUT  (7)	 TO VIEW ALL REMOVED COMPLAINTS");
	logln("\t\t\t---------------------------------------------------");
	logln("\t\t\t    INPUT  (0)	 TO EXIT");
	logln("\t\t\t---------------------------------------------------");
}

void addCompView() {

	logln("\n\t\t\t===========================================");
	logln("\n\t\t\t              ADD A COMPLAINT              ");
	logln("\n\t\t\t===========================================");
}


/*ADD COMPLAINT CONTROLER*/
void addCompCtrl(ComplaintInfoPtr* startPtr) {

	int complaintNum;
	char confirm;
	bool fail;
	regex dateReg("\\d{2}[-]\\d{2}[-]\\d{4}"), contactReg("\\d{10}");

	string complaintID, customerName, customerAddress, complaint, contactNumber, date;

	/* Ask for user input */
	do {
		do {
			log("\tEnter Complaint Number: C");
			cin >> complaintNum;
			fail = cin.fail();
			if (fail == true) {
				logln("\tPlease enter a valid number.")
			}
			fail = verifyCompNum(*startPtr, complaintNum);
			cin.clear();
			cin.ignore(100, '\n');
		} while (fail == true);


		log("\tEnter Customer Name: ");
		getline(cin, customerName);

		log("\tEnter Customer Address: ");
		getline(cin, customerAddress);

		log("\tEnter Complaint Description: ");
		getline(cin, complaint);

		do {
			log("\tEnter Contact Number (valid 10 digit number): ");
			cin >> contactNumber;
			cin.clear();
			cin.ignore(100, '\n');
		} while (!regex_match(contactNumber, contactReg));




		do {
			log("\tEnter Date (dd-mm-yyyy): ");
			cin >> date;
			cin.clear();
			cin.ignore(100, '\n');
		} while (!regex_match(date, dateReg));

		log("\nIs this information correct? (y/n): ");
		cin >> confirm;

	} while (confirm != 'y');




	/* Add to data Structure*/

	ComplaintInfoPtr newPtr = NULL;
	ComplaintInfoPtr previousPtr = NULL;
	ComplaintInfoPtr currentPtr = NULL;

	newPtr = new ComplaintInfo;


	if (newPtr != NULL) {

		newPtr->complaintNum = complaintNum;
		newPtr->customerName = customerName;
		newPtr->customerAddress = customerAddress;
		newPtr->complaint = complaint;
		newPtr->contactNumber = contactNumber;
		newPtr->date = date;
		newPtr->status = "open";
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


/*VIEW ALL COMPLAINTS*/
void viewAllComplaints(ComplaintInfoPtr startPtr) {

	logln("\n\t\t\t===========================================");
	logln("\n\t\t\t           VIEW ALL COMPLAINTS             ");
	logln("\n\t\t\t===========================================\n"); \

		if (startPtr == NULL) {
			logln("/n There are no complaints!");
		}
		else {
			while (startPtr != NULL) {
				logln("---------------------------------------------");
				logln("\tComplaint ID: C" << startPtr->complaintNum);
				logln("\tCustomer Name: " << startPtr->customerName);
				logln("\tCustomer Address: " << startPtr->customerAddress);
				logln("\tContact Number: " << startPtr->contactNumber);
				logln("\tComplaint Description: " << startPtr->complaint);
				logln("\tDate: " << startPtr->date);
				logln("\tStatus: " << startPtr->status);

				startPtr = startPtr->nextPtr;
			}
		}

	logln("---------------------------------------------");
	logln("\n\n");
	system("pause");

}

/* VIEW INFO ON A SINGLE COMPLAINT */
void viewSingleComplaintCtrl(ComplaintInfoPtr startPtr) {

	logln("\n\t\t\t===========================================");
	logln("\n\t\t\t           VIEW SINGLE COMPLAINT           ");
	logln("\n\t\t\t===========================================\n");

	int searchKey;
	bool fail;

	do {
		log("\tEnter Complaint Number: C");
		cin >> searchKey;
		fail = cin.fail();
		cin.clear();
		cin.ignore(100, '\n');
	} while (fail == true);

	if (viewSingleComplaint(startPtr, searchKey) == true) {
		system("pause");
	}
	else {
		logln("Complaint not found!");
		system("pause");
	}

}

bool viewSingleComplaint(ComplaintInfoPtr startPtr, int searchKey) {
	if (startPtr == NULL) {
		logln("\nThere are no complaints!");
		return true;

	}
	else {

		while (startPtr->complaintNum != searchKey) {
			startPtr = startPtr->nextPtr;
			if (startPtr == NULL) {
				return false;
			}
		}

		logln("---------------------------------------------");
		logln("\tComplaint ID: C" << startPtr->complaintNum);
		logln("\tCustomer Name: " << startPtr->customerName);
		logln("\tCustomer Address: " << startPtr->customerAddress);
		logln("\tContact Number: " << startPtr->contactNumber);
		logln("\tComplaint Description: " << startPtr->complaint);
		logln("\tDate: " << startPtr->date);
		logln("\tStatus: " << startPtr->status);
		logln("---------------------------------------------");
		logln("\n\n");

		return true;

	}
}

bool verifyCompNum(ComplaintInfoPtr startPtr, int searchKey) {
	if (startPtr == NULL) {
		return false;
	}
	else {

		while (startPtr->complaintNum != searchKey) {
			startPtr = startPtr->nextPtr;
			if (startPtr == NULL) {
				return true;
			}
		}

		if (startPtr->complaintNum == searchKey) {
			logln("\tThis complaint number already exits!");
			return true;
		}

		return false;
	}
}
