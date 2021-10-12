#pragma once
#include <iostream>
#include <fstream>
#include "Date.h"
#include "Trainer.h"
#include "Equipment.h"
#include "Exercise_plan.h"
#include "Customer.h"


using namespace std;

class subscription
{
private:

	int* subscriptionID;
	int subscriptionID_size;

	Date* S_time;
	int S_time_size;

	int* PlanID;
	int planID_size;

	ExercisePlan* planID;

	int* S_customerID;
	int S_customerID_size = 0;

public:

	//------------------------------Default Constructors------------------------------//

	//Needs constructor for Exercise Plan ID (Pointer) member
	subscription(ExercisePlan& planID)
	{
		subscriptionID = nullptr;
		subscriptionID_size = 0;

		S_time = nullptr;
		S_time_size = 0;

		S_customerID = nullptr;
		S_customerID_size = 0;

		PlanID = nullptr;
		planID_size = 0;

		this->planID = &planID;
	}

	//Needs destructor for Exercise Plan ID (Pointer) member
	~subscription()
	{
		if (subscriptionID != nullptr)
		{
			delete[] subscriptionID;
			subscriptionID = nullptr;
		}
		if (S_time != nullptr)
		{
			delete[] S_time;
			S_time = nullptr;
		}
		if (S_customerID != nullptr)
		{
			delete[] S_customerID;
			S_customerID = nullptr;
		}
	}

	//------------------------------Setters------------------------------//

	//Needs setter for Exercise Plan ID (Pointer) member
	void setPlanID(int iD)
	{
		planID_size++;
		int* newPlanID = new int[planID_size];
		
		for (int i = 0; i < planID_size - 1; i++)
		{
			newPlanID[i] = PlanID[i];
 		}

		delete[] PlanID;
		PlanID = newPlanID;
		newPlanID = nullptr;

		PlanID[planID_size - 1] = iD;
	}

	bool setsubscriptionID(int temp)
	{
		bool check2 = true;
		bool check3 = false;

		//---------------------------------------------//

		int iD = 0;
		cout << "Enter PlanID : ";
		cin >> iD;
		
		cout << endl;

		if (planID->PlanIdAvailable(iD))
		{
			check3 = true;
		}
		else
		{
			cout << "\nInsertion Failed: Plan ID " << iD << " does not exist \n\n";
			check3 = false;
			return false;
		}

		//---------------------------------------------//

		int S_id = 0;
		cout << "\nInput Subscription ID: ";
		cin >> S_id;

		for (int i = 0; i < subscriptionID_size; i++)
		{
			if (subscriptionID[i] == S_id)
			{
				cout << "\nInsertion Failed: Subscription ID " << S_id << " already exists \n\n";
				check2 = false;
				return false;
			}
		}
		
		//---------------------------------------------//

		if (check2)
		{
			if (S_customerID_size == 0)
			{
				S_customerID = new int[1];
				S_customerID[0] = temp;
				S_customerID_size++;
			}
			else
			{
				int* temp2 = new int[S_customerID_size + 1];

				for (int i = 0; i < S_customerID_size; i++)
				{
					temp2[i] = S_customerID[i];
				}
				temp2[S_customerID_size] = temp;
				S_customerID_size++;

				delete[] S_customerID;

				S_customerID = temp2;
				temp2 = nullptr;
			}

			if (subscriptionID_size == 0)
			{
				subscriptionID = new int[subscriptionID_size + 1];
				subscriptionID[0] = S_id;
				subscriptionID_size++;
			}
			else
			{
				int* temp3 = new int[subscriptionID_size + 1];

				for (int i = 0; i < subscriptionID_size; i++)
				{
					temp3[i] = subscriptionID[i];
				}
				temp3[subscriptionID_size] = S_id;
				subscriptionID_size++;

				delete[] subscriptionID;

				subscriptionID = temp3;
				temp3 = nullptr;
			}

			//setting plan iD;
			setPlanID(iD);
		}

		return true;
	}
	void S_setTime()
	{
		int dum[3] = { -1 };

		cout << "\nInput Day: ";
		cin >> dum[0];

		cout << "\nInput Month: ";
		cin >> dum[1];

		cout << "\nInput Year: ";
		cin >> dum[2];

		if (S_time_size == 0)
		{
			S_time = new Date[1];
			S_time[0].setDay(dum[0]).setMonth(dum[1]).setYear(dum[2]);
			S_time_size++;
		}
		else
		{
			Date* temp = new Date[S_time_size + 1];

			for (int i = 0; i < S_time_size; i++)
			{
				temp[i].setDay(S_time[i].getDay()).setMonth(S_time[i].getMonth()).setYear(S_time[i].getYear());
			}
			temp[S_time_size].setDay(dum[0]).setMonth(dum[1]).setYear(dum[2]);
			S_time_size++;

			delete[] S_time;

			S_time = temp;
			temp = nullptr;
		}
	}

	//------------------------------Setter Fucntion------------------------------//

	void setSubscription(int CustomerID)
	{
		bool check = setsubscriptionID(CustomerID);

		if (check)
		{
			S_setTime();

			this->SubscriptionSort();
		}
		cout << endl;
	}

	//------------------------------Subscription Class Sorter------------------------------//

	void SubscriptionSort() //Sorts based on Customer ID
	{
		int tempI = 0;
		Date tempD;

		for (int i = 0; i < subscriptionID_size - 1; i++)
		{
			for (int j = 0; j < subscriptionID_size - i - 1; j++)
			{
				if (subscriptionID[j] > subscriptionID[j + 1]) //Ascending Order Sort
				{
					//Subscription ID Swap
					tempI = subscriptionID[j];
					subscriptionID[j] = subscriptionID[j + 1];
					subscriptionID[j + 1] = tempI;
					tempI = -1; //Data in tempI set to -1 for error checking in Customer ID Swap

					//Date Swap
					tempD.setDay(S_time[j].getDay()).setMonth(S_time[j].getMonth()).setYear(S_time[j].getYear());
					S_time[j].setDay(S_time[j + 1].getDay()).setMonth(S_time[j + 1].getMonth()).setYear(S_time[j + 1].getYear());
					S_time[j + 1].setDay(tempD.getDay()).setMonth(tempD.getMonth()).setYear(tempD.getYear());

					//Customer ID Swap(ID ptr array of subscription class)
					tempI = S_customerID[j];
					S_customerID[j] = S_customerID[j + 1];
					S_customerID[j + 1] = tempI;
					tempI = -1; //Data in tempI set to -1 for error checking in Subscription ID Swap

					//planID swap
					tempI = this->PlanID[j];
					this->PlanID[j] = this->PlanID[j + 1];
					this->PlanID[j + 1] = tempI;
				}
			}
		}
	}

	//------------------------------Remover------------------------------//

	void RemoveSubscription()
	{
		int S_ID = 0;
		cout << "\nInput Subscription ID to remove: ";
		cin >> S_ID;

		bool check = false;

		for (int i = 0; i < subscriptionID_size; i++)
		{
			if (subscriptionID[i] == S_ID)
			{
				check = true;
				break;
			}
		}

		if (check)
		{
			int* tempI = new int[subscriptionID_size - 1];
			Date* tempD = new Date[S_time_size - 1];
			int* tempC = new int[S_customerID_size - 1];
			int* tempP = new int[S_customerID_size - 1];

			for (int j = 0, j2 = 0; j < subscriptionID_size; j++)
			{
				if (subscriptionID[j] != S_ID)
				{
					tempI[j2] = subscriptionID[j];

					tempD[j2].setDay(S_time[j].getDay()).setMonth(S_time[j].getMonth()).setYear(S_time[j].getYear());

					tempC[j2] = S_customerID[j];

					tempP[j2] = this->PlanID[j];

					j2++;
				}
			}

			delete[] subscriptionID;
			delete[] S_time;
			delete[] S_customerID;
			delete[] PlanID;

			subscriptionID = tempI;
			subscriptionID_size--;
			tempI = nullptr;

			S_time = tempD;
			S_time_size--;
			tempD = nullptr;

			S_customerID = tempC;
			S_customerID_size--;
			tempC = nullptr;

			PlanID = tempP;
			planID_size--;
			tempP = nullptr;

			this->SubscriptionSort();
		}
		else
		{
			cout << "\nRemoval Failed: Subscription with ID " << S_ID << " does not exist\n";
		}
	}

	//------------------------------Updater------------------------------//

	void UpdateSubscription()
	{
		int SubscriptionID = 0;
		cout << "\nInput Subscription ID to Update: ";
		cin >> SubscriptionID;

		if (subscriptionID_size > 0)
		{
			bool check = false;

			int index = 0;
			for (int i = 0; i < subscriptionID_size; i++)
			{
				if (subscriptionID[i] == SubscriptionID)
				{
					check = true;
					index = i;
					break;
				}
			}

			int temp = 0;

			if (check)
			{
				cout << "Input New Customer ID: ";
				cin >> temp;
				S_customerID[index] = temp;

				cout << "Input Updated Equipment ID : ";
				cin >> temp;
				PlanID[index] = temp;

				cout << "Input New Day: ";
				cin >> temp;
				S_time[index].setDay(temp);
				cout << "Input New Month: ";
				cin >> temp;
				S_time[index].setMonth(temp);
				cout << "Input New Year: ";
				cin >> temp;
				S_time[index].setYear(temp);
			}
			else
			{
				cout << "\nInsertion Failed: Subscription ID " << SubscriptionID << " does not exist \n\n";
			}
		}
	}

	//------------------------------Print Fucntion------------------------------//

	void printSubscription()
	{
		if (subscriptionID_size == 0)
		{
			cout << "\nThere is not DATA for Subscriptions Information\n\n";
		}
		else
		{
			cout << endl << "Subscriptions Information:\n";
			for (int i = 0; i < subscriptionID_size; i++)
			{
				cout << subscriptionID[i] << '\t'
					<< S_time[i].getDay() << '/' << S_time[i].getMonth() << '/' << S_time[i].getYear() << '\t'
					<< S_customerID[i] << '\t'
					<< PlanID[i] << endl;
			}
			cout << endl;
		}
	}
	void printSpecificCustomer(int CustomerID)
	{ 
		if (subscriptionID_size > 0)
		{
			bool check = false;
			for (int i = 0; i < subscriptionID_size; i++)
			{
				if (S_customerID[i] == CustomerID)
				{
					check = true;
					cout << subscriptionID[i] << '\t'
						<< S_time[i].getDay() << '/' << S_time[i].getMonth() << '/' << S_time[i].getYear() << '\t'
						<< S_customerID[i] << '\t'
						<< PlanID[i] << endl;
				}
			}
			if (!check)
			{
				cout << "No subscriptions for the this customer are avaiable." << endl;
			}
		}
		else if (subscriptionID_size <= 0)
		{
			cout << "No subscriptions Available..!" << endl;
		}

		cout << endl;
	}

	//------------------------------File Handling Functions------------------------------//

	void subscriptionInput()
	{
		ifstream fin;

		fin.open("Subscription.txt");
		if (!fin)
		{
			cout << "Error: Unable to Open file " << '"' << "Subscription.txt" << '"' << endl;
		}
		else
		{
			int SubscriptionFile_size;
			fin >> SubscriptionFile_size;

			//Deleting any existing Data in subscription class members
			//And assigning memory of indexes SubscriptionFile_size to
			//each member
			{
				if (subscriptionID != nullptr)
				{
					delete[] subscriptionID;
					subscriptionID = nullptr;
				}
				if (S_time != nullptr)
				{
					delete[] S_time;
					S_time = nullptr;
				}
				if (S_customerID != nullptr)
				{
					delete[] S_customerID;
					S_customerID = nullptr;
				}
				if (PlanID != nullptr)
				{
					delete[] PlanID;
					PlanID = nullptr;
				}

				subscriptionID = new int[SubscriptionFile_size];
				subscriptionID_size = SubscriptionFile_size;

				S_time = new Date[SubscriptionFile_size];
				S_time_size = SubscriptionFile_size;

				S_customerID = new int[SubscriptionFile_size];
				S_customerID_size = SubscriptionFile_size;
				
				PlanID = new int[SubscriptionFile_size];
				planID_size = SubscriptionFile_size;
			}

			int temp = 0;

			for (int i = 0; i < SubscriptionFile_size; i++)
			{
				fin >> subscriptionID[i];

				fin >> temp;
				S_time[i].setDay(temp);
				fin.ignore('/');
				fin >> temp;
				S_time[i].setMonth(temp);
				fin.ignore('/');
				fin >> temp;
				S_time[i].setYear(temp);
		
				fin.ignore();
				fin >> S_customerID[i];
				
				fin.ignore();
				fin >> PlanID[i];
			}
		}
		fin.close();
	}
	void subscriptionOutput()
	{
		ofstream fout;

		fout.open("Subscription.txt");
		if (!fout)
		{
			cout << "Error: Unable to Open file " << '"' << "Subscription.txt" << '"' << endl;
		}
		else
		{
			fout << subscriptionID_size << endl;

			for (int i = 0; i < subscriptionID_size; i++)
			{
				fout << subscriptionID[i] << '\t';

				fout << S_time[i].getDay() << '/';
				fout << S_time[i].getMonth() << '/';
				fout << S_time[i].getYear() << '\t';
				
				fout << S_customerID[i] << "\t" << PlanID[i];
			}
		}
		fout.close();
	}
};