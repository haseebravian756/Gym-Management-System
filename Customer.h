#pragma once
#include <iostream>
#include <fstream>
#include "Subscription.h"

using namespace std;

class customer
{
private:

	int* ID;
	int ID_size;

	string** name;
	int name_size;

	string** address;
	int address_size;

	string** phoneNumber;
	int phoneNumber_size;

	string** emailID;
	int emailID_size;
	
	subscription SubObj;

public:

	//------------------------------Default Constructors------------------------------//
	customer(ExercisePlan& planID) :SubObj(planID)
	{
		ID = nullptr;
		ID_size = 0;

		name = nullptr;
		name_size = 0;

		address = nullptr;
		address_size = 0;

		phoneNumber = nullptr;
		phoneNumber_size = 0;

		emailID = nullptr;
		emailID_size = 0;
	}

	~customer()
	{
		if (ID != nullptr)
		{
			delete[] ID;
			ID = nullptr;
		}
		if (name != nullptr)
		{
			for (int i = 0; i < name_size; i++)
			{
				delete name[i];
			}
			delete[] name;
			name = nullptr;
		}
		if (address != nullptr)
		{
			for (int i = 0; i < address_size; i++)
			{
				delete address[i];
			}
			delete[] address;
			address = nullptr;
		}
		if (phoneNumber != nullptr)
		{
			for (int i = 0; i < phoneNumber_size; i++)
			{
				delete phoneNumber[i];
			}
			delete[] phoneNumber;
			phoneNumber = nullptr;
		}
		if (emailID != nullptr)
		{
			for (int i = 0; i < emailID_size; i++)
			{
				delete emailID[i];
			}
			delete[] emailID;
			emailID = nullptr;
		}
	}

	//------------------------------Setters------------------------------//
	bool setID()
	{
		int id = 0;
		cout << "\nInput ID: ";
		cin >> id;

		if (ID_size == 0)
		{
			ID = new int[ID_size + 1];
			ID[0] = id;
			ID_size++;

			return true;
		}
		else
		{
			bool check = true;

			for (int i = 0; i < ID_size; i++)
			{
				if (ID[i] == id)
				{
					cout << "\nInsertion Failed: ID " << id << " already exists \n\n";
					check = false;

					return false;
				}
			}
			
			if (check)
			{
				int* temp = new int[ID_size + 1];

				for (int i = 0; i < ID_size; i++)
				{
					temp[i] = ID[i];
				}
				temp[ID_size] = id;
				ID_size++;

				delete[] ID;

				ID = temp;
				temp = nullptr;

				return true;
			}
		}
		return true;
	}
	void setName()
	{
		string id_name = "\0";
		cout << "\nInput Name: ";
		cin >> id_name;

		if (name_size == 0)
		{
			name_size++;
			name = new string * [name_size];
			name[name_size - 1] = new string(id_name);
		}
		else
		{
			string** temp = new string * [name_size + 1];

			for (int i = 0; i < name_size; i++)
			{
				temp[i] = new string(name[i][0]);
			}
			temp[name_size] = new string(id_name);

			name_size++;

			for (int i = 0; i < name_size - 1; i++)
			{
				delete name[i];
			}
			delete[] name;

			name = temp;
			temp = nullptr;
		}
	}
	void setAddress()
	{
		string Address = "\0";
		cout << "\nInput Address: ";
		cin >> Address;

		if (address_size == 0)
		{
			address_size++;
			address = new string * [address_size];
			address[address_size - 1] = new string(Address);
		}
		else
		{
			string** temp = new string * [address_size + 1];

			for (int i = 0; i < address_size; i++)
			{
				temp[i] = new string(address[i][0]);
			}
			temp[address_size] = new string(Address);

			address_size++;

			for (int i = 0; i < address_size - 1; i++)
			{
				delete address[i];
			}
			delete[] address;

			address = temp;
			temp = nullptr;
		}
	}
	void setPhoneNumber()
	{
		string PhoneNumber = "\0";
		cout << "\nInput Phone Number: ";
		cin >> PhoneNumber;

		if (phoneNumber_size == 0)
		{
			phoneNumber_size++;
			phoneNumber = new string * [phoneNumber_size];
			phoneNumber[phoneNumber_size - 1] = new string(PhoneNumber);
		}
		else
		{
			string** temp = new string * [phoneNumber_size + 1];

			for (int i = 0; i < phoneNumber_size; i++)
			{
				temp[i] = new string(phoneNumber[i][0]);
			}
			temp[phoneNumber_size] = new string(PhoneNumber);

			phoneNumber_size++;

			for (int i = 0; i < phoneNumber_size - 1; i++)
			{
				delete phoneNumber[i];
			}
			delete[] phoneNumber;

			phoneNumber = temp;
			temp = nullptr;
		}

	}
	void setEmailID()
	{
		string EmailID = "\0";
		cout << "\nInput Email ID: ";
		cin >> EmailID;

		if (emailID_size == 0)
		{
			emailID_size++;
			emailID = new string * [emailID_size];
			emailID[emailID_size - 1] = new string(EmailID);
		}
		else
		{
			string** temp = new string * [emailID_size + 1];

			for (int i = 0; i < emailID_size; i++)
			{
				temp[i] = new string(emailID[i][0]);
			}
			temp[emailID_size] = new string(EmailID);

			emailID_size++;

			for (int i = 0; i < emailID_size - 1; i++)
			{
				delete emailID[i];
			}
			delete[] emailID;

			emailID = temp;
			temp = nullptr;
		}

	}

	//------------------------------Getters------------------------------//

	int* ptr_getCustomerID()
	{
		return ID;
	}
	int getCustomerID_index(int customerID)
	{
		for (int i = 0; i < getCustomerID_size(); i++)
		{
			if (this->ID[i] == customerID)
			{
				return i;
			}
		}
	}
	int getCustomerID_size()
	{
		return ID_size;
	}

	//------------------------------Setter Fucntion------------------------------//

	void setCustomer()
	{
		bool check = setID();

		if (check)
		{
			setName();
			setAddress();
			setPhoneNumber();
			setEmailID();

			this->CustomerSort();
		}
	}

	//------------------------------Customer Class Sorter------------------------------//

	void CustomerSort() //Sorts based on Customer ID
	{
		int tempI = 0;
		string tempS = "-1";

		for (int i = 0; i < ID_size - 1; i++)
		{
			for (int j = 0; j < ID_size - i - 1; j++)
			{
				if (ID[j] > ID[j + 1]) //Ascending Order Sort
				{
					//ID Swap
					tempI = ID[j]; 
					ID[j] = ID[j + 1];
					ID[j + 1] = tempI;

					//name Swap
					tempS = name[j][0];
					name[j][0] = name[j + 1][0];
					name[j + 1][0] = tempS;
					tempS = "-1"; //Data in tempS set to -1 for error checking

					//address Swap
					tempS = address[j][0];
					address[j][0] = address[j + 1][0];
					address[j + 1][0] = tempS;
					tempS = "-1"; //Data in tempS set to -1 for error checking

					//phoneNumber Swap
					tempS = phoneNumber[j][0];
					phoneNumber[j][0] = phoneNumber[j + 1][0];
					phoneNumber[j + 1][0] = tempS;
					tempS = "-1"; //Data in tempS set to -1 for error checking

					//emailID Swap
					tempS = emailID[j][0];
					emailID[j][0] = emailID[j + 1][0];
					emailID[j + 1][0] = tempS;
					tempS = "-1"; //Data in tempS set to -1 for error checking
				}
			}
		}
	}

	//------------------------------Remover------------------------------//

	void RemoveCustomer(int id)
	{
		bool check = false;

		for (int i = 0; i < ID_size; i++)
		{
			if (ID[i] == id)
			{
				check = true;
				break;
			}
		}

		if (check)
		{
			int* tempI = new int[ID_size - 1];
			string** tempName = new string * [ID_size - 1];
			string** tempAddress = new string * [ID_size - 1];
			string** tempPhoneNumber = new string * [ID_size - 1];
			string** tempEmailID = new string * [ID_size - 1];

			for (int j = 0, j2 = 0; j < ID_size; j++)
			{
				if (ID[j] != id)
				{
					tempI[j2] = ID[j];

					tempName[j2] = new string(name[j][0]);
					delete name[j];

					tempAddress[j2] = new string(address[j][0]);
					delete address[j];

					tempPhoneNumber[j2] = new string(phoneNumber[j][0]);
					delete phoneNumber[j];

					tempEmailID[j2] = new string(emailID[j][0]);
					delete emailID[j];

					j2++;
				}
			}

			delete[] ID;
			delete[] name;
			delete[] address;
			delete[] phoneNumber;
			delete[] emailID;

			ID = tempI;
			ID_size--;
			tempI = nullptr;

			name = tempName;
			name_size--;
			tempName = nullptr;

			address = tempAddress;
			address_size--;
			tempAddress = nullptr;

			phoneNumber = tempPhoneNumber;
			phoneNumber_size--;
			tempPhoneNumber = nullptr;

			emailID = tempEmailID;
			emailID_size--;
			tempEmailID = nullptr;

			this->CustomerSort();
		}
		else
		{
			cout << "\nRemoval Failed: Customer with ID " << id << " does not exist\n";
		}
	}

	//------------------------------Updater------------------------------//

	void UpdateCustomer(int customerID)
	{
		if (this->getCustomerID_size() > 0)
		{
			bool check = false;
			for (int i = 0; i < getCustomerID_size(); i++)
			{
				if (this->ID[i] == customerID)
				{
					check = true;
					break;
				}
			}
			if (check)
			{
				string str = "\0";
				cout << "Enter updated Customer Name : ";
				cin.ignore();
				getline(cin, str);
				this->name[getCustomerID_index(customerID)][0] = str;

				cout << "\nEnter updated Customer Address : ";
				getline(cin, str);
				this->address[getCustomerID_index(customerID)][0] = str;

				cout << "\nEnter updated Customer Phone.No: ";
				getline(cin, str);
				this->phoneNumber[getCustomerID_index(customerID)][0] = str;

				cout << "\nEnter updated Customer Email-ID : ";
				getline(cin, str);
				this->emailID[getCustomerID_index(customerID)][0] = str;
			}
		}
		else
		{
			cout << "Customer Does not Exists..!";
		}
	}

	//------------------------------Print Function------------------------------//

	void printCustomer() const
	{
		if (ID_size == 0)
		{
			cout << "\nThere is not DATA for Customers Information\n\n";
		}
		else
		{
			cout << endl << "Customers Information:\n";
			for (int i = 0; i < ID_size; i++)
			{
				cout << ID[i] << '\t' << name[i][0] << '\t' << address[i][0] << '\t' << phoneNumber[i][0] << '\t' << emailID[i][0] << endl;
			}
			cout << endl;
		}
	}

	//------------------------------File Handling Functions------------------------------//

	void customerInput()
	{
		ifstream fin;
		
		fin.open("Customers.txt");
		if (!fin)
		{
			cout << "Error: Unable to Open file " << '"' << "Customers.txt" << '"' << endl;
		}
		else
		{
			int CustomerFile_size;
			fin >> CustomerFile_size;

			//Deleting any existing Data in customer class members
			//And assigning memory of indexes CustomerFile_size to
			//each member
			{
				if (ID != nullptr)
				{
					delete[] ID;
					ID = nullptr;
				}
				if (name != nullptr)
				{
					for (int i = 0; i < name_size; i++)
					{
						delete name[i];
					}
					delete[] name;
					name = nullptr;
				}
				if (address != nullptr)
				{
					for (int i = 0; i < address_size; i++)
					{
						delete address[i];
					}
					delete[] address;
					address = nullptr;
				}
				if (phoneNumber != nullptr)
				{
					for (int i = 0; i < phoneNumber_size; i++)
					{
						delete phoneNumber[i];
					}
					delete[] phoneNumber;
					phoneNumber = nullptr;
				}
				if (emailID != nullptr)
				{
					for (int i = 0; i < emailID_size; i++)
					{
						delete emailID[i];
					}
					delete[] emailID;
					emailID = nullptr;
				}

				ID = new int[CustomerFile_size];
				ID_size = CustomerFile_size;

				name = new string * [CustomerFile_size];
				name_size = CustomerFile_size;

				address = new string * [CustomerFile_size];
				address_size = CustomerFile_size;

				phoneNumber = new string * [CustomerFile_size];
				phoneNumber_size = CustomerFile_size;

				emailID = new string * [CustomerFile_size];
				emailID_size = CustomerFile_size;
			}

			string tempS = "\0";

			for (int i = 0; i < CustomerFile_size; i++)
			{
				fin >> ID[i];
				fin.ignore();

				getline(fin, tempS, '\t');
				name[i] = new string(tempS);				

				getline(fin, tempS, '\t');
				address[i] = new string(tempS);

				getline(fin, tempS, '\t');
				phoneNumber[i] = new string(tempS);

				getline(fin, tempS, '\t');
				emailID[i] = new string(tempS);
			}
		}
		fin.close();
	}
	void customerOutput()
	{
		ofstream fout;

		fout.open("Customers.txt");
		if (!fout)
		{
			cout << "Error: Unable to Open file " << '"' << "Customers.txt" << '"' << endl;
		}
		else
		{
			fout << ID_size << endl;

			for (int i = 0; i < ID_size; i++)
			{
				fout << ID[i] << '\t';
				fout << name[i][0] << '\t';
				fout << address[i][0] << '\t';
				fout << phoneNumber[i][0] << '\t';
				fout << emailID[i][0] << endl;
			}
		}
		fout.close();
	}

	//------------------------------Subscription Class Handling------------------------------//
	//---------------------------------------------------------------------------------------//
	//---------------------------------------------------------------------------------------//

	void SubscriptionClass_Setter()
	{
		int temp = 0;

		cout << "Input Customer ID: ";
		cin >> temp;

		bool check = false;

		for (int i = 0; i < ID_size; i++)
		{
			if (ID[i] == temp)
			{
				check = true;
				break;
			}
		}

		if (check)
		{
			SubObj.setSubscription(temp);
		}
		else
		{
			cout << "\nInsertion Failed: Customer ID " << temp << " does not exist \n\n";
		}
	}

	void SubscriptionClass_Remover()
	{
		SubObj.RemoveSubscription();
	}

	void SubscriptionClass_Updator()
	{
		SubObj.UpdateSubscription();
	}

	void SubscriptionClass_Printer()
	{
		SubObj.printSubscription();
	}
	
	void SubscriptionClass_FileInput()
	{
		SubObj.subscriptionInput();
	}

	void SubscriptionClass_FileOutput()
	{
		SubObj.subscriptionOutput();
	}

	void Print_Subscription_Info()
	{
		int temp = 0;

		cout << "Input Customer ID: ";
		cin >> temp;

		bool check = false;

		for (int i = 0; i < ID_size; i++)
		{
			if (ID[i] == temp)
			{
				check = true;
				break;
			}
		}
	
		if (check)
		{
			SubObj.printSpecificCustomer(temp);
		}
		else
		{
			cout << "\nCustomer with ID " << temp << " does not exist \n\n";
		}
	}
};