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

/*REMOVED COMPLAINT DATA STRUCTURE*/
struct RemovedComplaintInfo
{
	int complaintNum;
	string customerName;
	string customerAddress;
	string complaint;
	string contactNumber;
	string date;
	string status;
	struct RemovedComplaintInfo* nextPtr;
};

/*ADDRESSED COMPLAINTS QUEUE*/
struct AddressedComplaintInfo
{
	int complaintNum;
	string customerName;
	string complaint;
	string action;
	string status;
	struct AddressedComplaintInfo* nextPtr;
};

/*TYPE DEFENITIONS*/
typedef ComplaintInfo* ComplaintInfoPtr;
typedef RemovedComplaintInfo* RemovedComplaintInfoPtr;
typedef AddressedComplaintInfo* AddressedComplaintInfoPtr;

/*PROTOTYPES*/
void menuCtrl();
void menuView();
void addCompView();
void addCompCtrl(ComplaintInfoPtr* startPtr);
void viewAllComplaints(ComplaintInfoPtr startPtr);
void viewAllRemovedComplaints(RemovedComplaintInfoPtr startRemPtr);
void viewSingleComplaintCtrl(ComplaintInfoPtr startPtr);
bool viewSingleComplaint(ComplaintInfoPtr startPtr, int searchKey);
bool verifyCompNum(ComplaintInfoPtr startPtr, int searchKey);
void editComplaintCtrl(ComplaintInfoPtr startPtr);
bool editComplaint(ComplaintInfoPtr startPtr, int searchKey);
void removeComplaintCtrl(ComplaintInfoPtr* startPtr, RemovedComplaintInfoPtr* startRemPtr);
bool removeComplaint(ComplaintInfoPtr* startPtr, int searchKey, RemovedComplaintInfoPtr* startRemPtr);
void addressComplaintCtrl(AddressedComplaintInfoPtr* headPtr, AddressedComplaintInfoPtr* tailPtr, ComplaintInfoPtr* startPtr);
bool addressComplaint(AddressedComplaintInfoPtr* headPtr, AddressedComplaintInfoPtr* tailPtr, ComplaintInfoPtr* startPtr, int searchKey);
void viewAllAddressedComplaints(AddressedComplaintInfoPtr headPtr);
void viewAllClosedComplaints(AddressedComplaintInfoPtr headPtr);
bool verifyClosed(ComplaintInfoPtr startPtr, int searchKey);



/*MAIN*/
int main() {

	menuCtrl();

	return 0;

}



/*MAIN MENU CONTROLER*/
void menuCtrl() {

	ComplaintInfoPtr startPtr = NULL;
	RemovedComplaintInfoPtr startRemPtr = NULL;
	AddressedComplaintInfoPtr headPtr = NULL;
	AddressedComplaintInfoPtr tailPtr = NULL;

	/* Display Main Menu */
	menuView();


	/* Get User Response */

	int in;
	bool fail;

	do {
		log("\n\t\t\t	Enter your choice: ");
		cin >> in;
		fail = cin.fail();
		cin.clear();
		cin.ignore(100, '\n');
	} while (fail);



	/* Handle User Response */
	do {

		switch (in) {
		case 1:
			//add complaint
			system("cls");
			addCompView();
			addCompCtrl(&startPtr);
			break;
		case 2:
			//remove complaint
			system("cls");
			removeComplaintCtrl(&startPtr, &startRemPtr);
			break;
		case 3:
			//update complaint
			system("cls");
			editComplaintCtrl(startPtr);
			break;
		case 4:
			//view all complaints
			system("cls");
			viewAllComplaints(startPtr);
			break;
		case 5:
			//view single complaint
			system("cls");
			viewSingleComplaintCtrl(startPtr);
			break;
		case 6:
			//address a complaint
			system("cls");
			addressComplaintCtrl(&headPtr, &tailPtr, &startPtr);
			break;
		case 7:
			//view all addressed complaints
			system("cls");
			viewAllAddressedComplaints(headPtr);
			break;
		case 8:
			//view all closed complaints
			system("cls");
			viewAllClosedComplaints(headPtr);
			break;
		case 9:
			//view all removed complaints
			system("cls");
			viewAllRemovedComplaints(startRemPtr);
			break;
		}
		system("cls");
		menuView();
		log("\n\t\t\t	Enter your choice: ");
		cin >> in;
		fail = cin.fail();
		cin.clear();
		cin.ignore(100, '\n');
	} while (in != 0 || fail);

	system("cls");
	system("color c");
	logln("\t\t\t\t   ______                           ");
	logln("\t\t\t\t  / ____/_  ____  ___________  ____ ");
	logln("\t\t\t\t / / __/ / / / / / / ___/ __ \\/ __ \\");
	logln("\t\t\t\t/ /_/ / /_/ / /_/ (__  ) /_/ / / / /");
	logln("\t\t\t\t\\____/\\__,_/\\__, /____/\\____/_/ /_/ ");
	logln("\t\t\t\t           /____/                    ");

	logln("\n\t\t\t===================================================");
	logln("\n\t\t\t        I-CALL COMPLAINT MANANGEMENT SYSTEM        ");
	logln("\n\t\t\t===================================================");
	logln("\n\t\t\t       Created by Gayanga Chathushan Kuruppu");
	logln("\t\t\t---------------------------------------------------\n\n");
	system("pause");


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
	logln("\t\t\t    INPUT  (5)	 TO VIEW A SINGLE COMPLAINT");
	logln("\t\t\t---------------------------------------------------");
	logln("\t\t\t    INPUT  (6)	 TO ADDRESS COMPLAINT");
	logln("\t\t\t---------------------------------------------------");
	logln("\t\t\t    INPUT  (7)	 TO VIEW ALL ADDRESSED COMPLAINTS");
	logln("\t\t\t---------------------------------------------------");
	logln("\t\t\t    INPUT  (8)	 TO VIEW ALL CLOSED COMPLAINTS");
	logln("\t\t\t---------------------------------------------------");
	logln("\t\t\t    INPUT  (9)	 TO VIEW ALL REMOVED COMPLAINTS");
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
	bool fail, failV;
	regex dateReg("\\d{2}[-]\\d{2}[-]\\d{4}"), contactReg("\\d{10}");

	string complaintID, customerName, customerAddress, complaint, contactNumber, date;

	/* Ask for user input */
	do {
		do {
			log("\tEnter Complaint Number: C");
			cin >> complaintNum;
			fail = cin.fail();
			if (fail == true) {
				logln("\tPlease enter a valid number.");
			}
			failV = verifyCompNum(*startPtr, complaintNum);
			cin.clear();
			cin.ignore(100, '\n');
		} while (fail || failV);


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
		cin.ignore(100, '\n');

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
	logln("\n\t\t\t===========================================\n");

	if (startPtr == NULL) {
		logln("\n There are no complaints!\n");
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

	if (startPtr == NULL) {
		logln("\nThere are no complaints!\n");
		system("pause");
	}
	else {
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
			logln("Complaint not found!\n");
			system("pause");
		}
	}

}

bool viewSingleComplaint(ComplaintInfoPtr startPtr, int searchKey) {
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


/* COMPLAINT NUMBER VERIFICATION */
bool verifyCompNum(ComplaintInfoPtr startPtr, int searchKey) {
	if (startPtr == NULL) {
		return false;
	}
	else {

		while (startPtr->complaintNum != searchKey) {
			startPtr = startPtr->nextPtr;
			if (startPtr == NULL) {
				return false;
			}
		}

		if (startPtr->complaintNum == searchKey) {
			logln("\tThis complaint number already exits!");
			return true;
		}

		return false;
	}
}

/* EDIT A COMPLAINT */
void editComplaintCtrl(ComplaintInfoPtr startPtr) {

	logln("\n\t\t\t===========================================");
	logln("\n\t\t\t              EDIT A COMPLAINT             ");
	logln("\n\t\t\t===========================================\n");

	int searchKey;
	bool fail;

	if (startPtr == NULL) {
		logln("\nThere are no complaints!\n");
		system("pause");
	}
	else {
		do {
			log("\tEnter Complaint Number: C");
			cin >> searchKey;
			fail = cin.fail();
			cin.clear();
			cin.ignore(100, '\n');
		} while (fail == true);

		if (editComplaint(startPtr, searchKey) == true) {
			system("pause");
		}
		else {
			logln("Complaint not found!");
			system("pause");
		}
	}
}

bool editComplaint(ComplaintInfoPtr startPtr, int searchKey) {
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

	char confirm;
	regex contactReg("\\d{10}");

	string customerAddress, contactNumber;

	/* Ask for user input */
	do {

		log("\tEnter Customer Address: ");
		getline(cin, customerAddress);

		do {
			log("\tEnter Contact Number (valid 10 digit number): ");
			cin >> contactNumber;
			cin.clear();
			cin.ignore(100, '\n');
		} while (!regex_match(contactNumber, contactReg));

		log("\nIs this information correct? (y/n): ");
		cin >> confirm;
		cin.ignore(100, '\n');

	} while (confirm != 'y');

	startPtr->customerAddress = customerAddress;
	startPtr->contactNumber = contactNumber;

	return true;

}

/* REMOVE A COMPLAINT */

void removeComplaintCtrl(ComplaintInfoPtr* startPtr, RemovedComplaintInfoPtr* startRemPtr) {

	logln("\n\t\t\t===========================================");
	logln("\n\t\t\t             REMOVE A COMPLAINT            ");
	logln("\n\t\t\t===========================================\n");

	int searchKey;
	char confirm;
	bool fail;

	if (*startPtr == NULL) {
		logln("\nThere are no complaints!\n");
		system("pause");
	}
	else {
		do {
			log("\tEnter Complaint Number: C");
			cin >> searchKey;
			fail = cin.fail();
			cin.clear();
			cin.ignore(100, '\n');
		} while (fail == true);

		if (viewSingleComplaint(*startPtr, searchKey)) {
			log("Do you wish to remove this complaint? (y/n): ");
			cin >> confirm;
			cin.ignore(100, '\n');
			if (confirm == 'y') {
				removeComplaint(startPtr, searchKey, startRemPtr);
				system("pause");
			}
		}
		else {
			logln("Complaint not found!");
			system("pause");
		}
	}
}

bool removeComplaint(ComplaintInfoPtr* startPtr, int searchKey, RemovedComplaintInfoPtr* startRemPtr) {

	ComplaintInfoPtr previousPtr = NULL;
	ComplaintInfoPtr currentPtr = NULL;
	ComplaintInfoPtr tempPtr = NULL;

	RemovedComplaintInfoPtr newPtr = NULL;
	RemovedComplaintInfoPtr previousRemPtr = NULL;
	RemovedComplaintInfoPtr currentRemPtr = NULL;

	newPtr = new RemovedComplaintInfo;


	if (searchKey == (*startPtr)->complaintNum) {
		tempPtr = *startPtr;

		/*Add removed data to secondary structure*/
		newPtr->complaintNum = tempPtr->complaintNum;
		newPtr->customerName = tempPtr->customerName;
		newPtr->customerAddress = tempPtr->customerAddress;
		newPtr->complaint = tempPtr->complaint;
		newPtr->contactNumber = tempPtr->contactNumber;
		newPtr->date = tempPtr->date;
		newPtr->status = "removed";
		newPtr->nextPtr = NULL;

		if (newPtr != NULL) {

			previousRemPtr = NULL;
			currentRemPtr = *startRemPtr;

			while (currentRemPtr != NULL && tempPtr->complaintNum > currentRemPtr->complaintNum) {
				previousRemPtr = currentRemPtr;
				currentRemPtr = currentRemPtr->nextPtr;
			}

			if (previousRemPtr == NULL) {
				newPtr->nextPtr = *startRemPtr;
				*startRemPtr = newPtr;
			}
			else {
				previousRemPtr->nextPtr = newPtr;
				newPtr->nextPtr = currentRemPtr;
			}
		}
		else {
			logln("Entry not added to removed complaints! No memory available.");
		}
		*startPtr = (*startPtr)->nextPtr;
		delete(tempPtr);
		logln("Entry Successfully Deleted\n");
		return true;
	}
	else {
		previousPtr = *startPtr;
		currentPtr = (*startPtr)->nextPtr;

		while (currentPtr != NULL && currentPtr->complaintNum != searchKey) {
			previousPtr = currentPtr;
			currentPtr = currentPtr->nextPtr;
		}

		if (currentPtr != NULL) {
			tempPtr = currentPtr;

			/*Add removed data to secondary structure*/
			newPtr->complaintNum = tempPtr->complaintNum;
			newPtr->customerName = tempPtr->customerName;
			newPtr->customerAddress = tempPtr->customerAddress;
			newPtr->complaint = tempPtr->complaint;
			newPtr->contactNumber = tempPtr->contactNumber;
			newPtr->date = tempPtr->date;
			newPtr->status = "removed";
			newPtr->nextPtr = NULL;

			if (newPtr != NULL) {

				previousRemPtr = NULL;
				currentRemPtr = *startRemPtr;

				while (currentRemPtr != NULL && tempPtr->complaintNum > currentRemPtr->complaintNum) {
					previousRemPtr = currentRemPtr;
					currentRemPtr = currentRemPtr->nextPtr;
				}

				if (previousRemPtr == NULL) {
					newPtr->nextPtr = *startRemPtr;
					*startRemPtr = newPtr;
				}
				else {
					previousRemPtr->nextPtr = newPtr;
					newPtr->nextPtr = currentRemPtr;
				}
			}
			else {
				logln("Entry not added to removed complaints! No memory available.");
			}
			previousPtr->nextPtr = currentPtr->nextPtr;
			delete(tempPtr);
			logln("Entry Successfully Deleted\n");
			return true;
		}
	}

	return false;
}

/*VIEW ALL REMOVED COMPLAINTS*/
void viewAllRemovedComplaints(RemovedComplaintInfoPtr startRemPtr) {

	logln("\n\t\t\t===========================================");
	logln("\n\t\t\t        VIEW ALL REMOVED COMPLAINTS        ");
	logln("\n\t\t\t===========================================\n");

	if (startRemPtr == NULL) {
		logln("\n There are no complaints!\n");
	}
	else {
		while (startRemPtr != NULL) {
			logln("---------------------------------------------");
			logln("\tComplaint ID: C" << startRemPtr->complaintNum);
			logln("\tCustomer Name: " << startRemPtr->customerName);
			logln("\tCustomer Address: " << startRemPtr->customerAddress);
			logln("\tContact Number: " << startRemPtr->contactNumber);
			logln("\tComplaint Description: " << startRemPtr->complaint);
			logln("\tDate: " << startRemPtr->date);
			logln("\tStatus: " << startRemPtr->status);

			startRemPtr = startRemPtr->nextPtr;
		}
	}

	logln("---------------------------------------------");
	logln("\n\n");
	system("pause");

}

/* ADDRESS A COMPLAINT */
void addressComplaintCtrl(AddressedComplaintInfoPtr* headPtr, AddressedComplaintInfoPtr* tailPtr, ComplaintInfoPtr* startPtr) {

	logln("\n\t\t\t===========================================");
	logln("\n\t\t\t             ADDRESS A COMPLAINT           ");
	logln("\n\t\t\t===========================================\n");

	int searchKey;
	char confirm;
	bool fail;

	if (*startPtr == NULL) {
		logln("\nThere are no complaints!\n");
		system("pause");
	}
	else {
		do {
			log("\tEnter Complaint Number: C");
			cin >> searchKey;
			fail = cin.fail();
			cin.clear();
			cin.ignore(100, '\n');
		} while (fail == true);

		if (verifyClosed(*startPtr, searchKey)) {
			if (viewSingleComplaint(*startPtr, searchKey)) {
				log("Do you wish to address this complaint? (y/n): ");
				cin >> confirm;
				cin.ignore(100, '\n');
				if (confirm == 'y') {
					addressComplaint(headPtr, tailPtr, startPtr, searchKey);
					system("pause");
				}
			}
			else {
				logln("Complaint not found!");
				system("pause");
			}
		}

	}

}

bool addressComplaint(AddressedComplaintInfoPtr* headPtr, AddressedComplaintInfoPtr* tailPtr, ComplaintInfoPtr* startPtr, int searchKey) {

	string action, status;
	int input;
	bool fail, failN = false;

	ComplaintInfoPtr previousPtr = NULL;
	ComplaintInfoPtr currentPtr = NULL;
	ComplaintInfoPtr tempPtr = NULL;

	AddressedComplaintInfoPtr newPtr;
	newPtr = new AddressedComplaintInfo;

	log("\nEnter Action taken: ");
	getline(cin, action);

	do {
		log("Enter status (1/2/3) (1. Closed / 2. Open  / 3. Cannot Address): ");
		cin >> input;
		fail = cin.fail();
		if (input != 1 && input != 2 && input !=3) {
			failN = true;
			logln("\tPlease enter a valid status (1, 2 or 3.");
		}
		else {
			failN = true;
		}
		if (fail == true) {
			logln("\tPlease enter a valid status.");
		}
		cin.clear();
		cin.ignore(100, '\n');
	} while (fail || failN);

	switch (input) {
	case 1:
		status = "closed";
		break;
	case 2:
		status = "open";
		break;
	case 3:
		status = "cannot-address";
		break;
	}

	if (searchKey == (*startPtr)->complaintNum) {
		tempPtr = *startPtr;

		if (newPtr != NULL) {
			/*Add data to addressed complaint structure*/
			newPtr->complaintNum = tempPtr->complaintNum;
			newPtr->customerName = tempPtr->customerName;
			newPtr->complaint = tempPtr->complaint;
			newPtr->action = action;
			newPtr->status = status;
			tempPtr->status = status;
			newPtr->nextPtr = NULL;

			if (*headPtr == NULL) {
				*headPtr = newPtr;
			}
			else {
				(*tailPtr)->nextPtr = newPtr;
			}
			logln("Entry Successfully added to addressed complaints!");
			*tailPtr = newPtr;
		}
		else {
			logln("Addressed complaint not added! No memory available.");
		}
		return true;
	}
	else {
		previousPtr = *startPtr;
		currentPtr = (*startPtr)->nextPtr;

		while (currentPtr != NULL && currentPtr->complaintNum != searchKey) {
			previousPtr = currentPtr;
			currentPtr = currentPtr->nextPtr;
		}

		if (currentPtr != NULL) {
			tempPtr = currentPtr;
			/*Add data to addressed complaint structure*/
			newPtr->complaintNum = tempPtr->complaintNum;
			newPtr->customerName = tempPtr->customerName;
			newPtr->complaint = tempPtr->complaint;
			newPtr->action = action;
			newPtr->status = status;
			tempPtr->status = status;
			newPtr->nextPtr = NULL;

			if (*headPtr == NULL) {
				*headPtr = newPtr;
			}
			else {
				(*tailPtr)->nextPtr = newPtr;
			}
			logln("Entry Successfully added to addressed complaints!");
			*tailPtr = newPtr;
		}
		else {
			logln("Addressed complaint not added! No memory available.");
		}
		return true;
	}
	return false;
}

/*VIEW ALL ADDRESSED COMPLAINTS*/
void viewAllAddressedComplaints(AddressedComplaintInfoPtr headPtr) {

	logln("\n\t\t\t===========================================");
	logln("\n\t\t\t       VIEW ALL ADDRESSED COMPLAINTS       ");
	logln("\n\t\t\t===========================================\n");

	if (headPtr == NULL) {
		logln("\n There are no addressed complaints!\n");
	}
	else {
		while (headPtr != NULL) {
			logln("---------------------------------------------");
			logln("\tComplaint ID: C" << headPtr->complaintNum);
			logln("\tCustomer Name: " << headPtr->customerName);
			logln("\tComplaint Description: " << headPtr->complaint);
			logln("\tAction Taken: " << headPtr->action);
			logln("\tStatus: " << headPtr->status);

			headPtr = headPtr->nextPtr;
		}
	}

	logln("---------------------------------------------");
	logln("\n\n");
	system("pause");

}

/*VIEW ALL CLOSED COMPLAINTS*/
void viewAllClosedComplaints(AddressedComplaintInfoPtr headPtr) {

	logln("\n\t\t\t===========================================");
	logln("\n\t\t\t         VIEW ALL CLOSED COMPLAINTS        ");
	logln("\n\t\t\t===========================================\n");

	if (headPtr == NULL) {
		logln("\n There are no addressed complaints!\n");
	}
	else {
		while (headPtr != NULL) {
			if (headPtr->status == "closed") {
				logln("---------------------------------------------");
				logln("\tComplaint ID: C" << headPtr->complaintNum);
				logln("\tCustomer Name: " << headPtr->customerName);
				logln("\tComplaint Description: " << headPtr->complaint);
				logln("\tAction Taken: " << headPtr->action);
				logln("\tStatus: " << headPtr->status);
			}

			headPtr = headPtr->nextPtr;
		}
	}

	logln("---------------------------------------------");
	logln("\n\n");
	system("pause");

}

bool verifyClosed(ComplaintInfoPtr startPtr, int searchKey) {
	while (startPtr->complaintNum != searchKey) {
		startPtr = startPtr->nextPtr;
		if (startPtr == NULL) {
			return true;
			//return false;
		}
	}

	if (startPtr->status == "closed") {
		logln("This complaint is closed");
		system("pause");
		return false;
	}

	if (startPtr->status == "cannot-address") {
		logln("This complaint cannot be addressed");
		system("pause");
		return false;
	}

	return true;
}