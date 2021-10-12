#pragma once

#include <iostream>
#include <fstream>
#include <string>
#include "Customer.h"
#include "Equipment.h"
#include "Trainer.h"

class Gym
{
private:
	Trainer* trainer;

	customer* Customer;

	Equipment* equipment;

public:
	Gym()
	{
		trainer = nullptr;
		//trainer_size = 0;

		Customer = nullptr;
		//customer_size = 0;

		equipment = nullptr;
	}
	Gym(Trainer& tri, customer& cust)
	{
		trainer = &tri;
		Customer = &cust;
		equipment = new Equipment;
	}
	~Gym()
	{
		this->Customer = nullptr;
		this->trainer = nullptr;
		delete equipment;
	}

	//*************************Functions of Trainer*************************//

	void InsertTrainer()
	{
		string name;
		cout << "Enter the name of the trainer :-";
		getline(cin, name);
		this->trainer->InsertTrainer(name);
	}

	void UpdateTrainer()
	{
		string name, newname;
		cout << "Enter the name of the old trainer :-";
		getline(cin, name);
		cout << "Enter the name of the new trainer :-";
		getline(cin, newname);

		this->trainer->UpdateTrainer(name, newname);
	}

	void RemoveTrainer()
	{
		string name;
		cout << "Enter the name of the trainer that you want to remove:-";
		getline(cin, name);

		this->trainer->RemoveTrainer(name);
	}

	void UpdateTimeWorkedByTheTrainer()
	{
		string name;
		cout << "Enter the name of the trainer :-";
		getline(cin, name);

		int t = 0;
		cout << "Enter New Time : ";
		cin >> t;

		this->trainer->UpdateTimeWorkedByTheTrainer(name, t);
	}

	void Print_Trainer_Info()
	{
		string name;
		cout << "Enter the name of the trainer :-";
		getline(cin, name);

		this->trainer->Print_Trainer_Info(name);
	}

	void Trainer_FileInput()
	{
		this->trainer->FileInput();
	}

	void Trainer_FileOutput()
	{
		this->trainer->FileOutput();
	}

	//Exercise_plan functions

	void setExerCisePlan()
	{
		this->trainer->setExerCisePlan();
	}

	void UpdateExercisePlan()
	{
		this->trainer->UpdateExercisePlan();
	}

	void RemoveExercisePlan()
	{
		this->trainer->RemoveExercisePlan();
	}

	void ExercisePlan_FileInput()
	{
		this->trainer->ExercisePlan_FileInput();
	}

	void ExercisePlan_FileOutput()
	{
		this->trainer->ExercisePlan_FileOutput();
	}
	//*************************Functions of Customer*************************//

	void setCustomer()
	{
		this->Customer->setCustomer();
	}

	void UpdateCustomer()
	{
		int iD;
		cout << "Enter the ID of the Customer that you want to Update:-";
		cin >> iD;

		this->Customer->UpdateCustomer(iD);
	}

	void RemoveCustomer()
	{
		int iD;
		cout << "Enter the ID of the Customer that you want to remove:-";
		cin >> iD;

		this->Customer->RemoveCustomer(iD);
	}

	void Customer_FileInput()
	{
		this->Customer->customerInput();
	}

	void Customer_FileOutput()
	{
		this->Customer->customerOutput();
	}

	//Subscription Functions

	void SubscriptionClass_Setter()
	{
		this->Customer->SubscriptionClass_Setter();
	}

	void SubscriptionClass_Remover()
	{
		this->Customer->SubscriptionClass_Remover();
	}

	void SubscriptionClass_Updator()
	{
		this->Customer->SubscriptionClass_Updator();
	}

	void SubscriptionClass_Printer()
	{
		this->Customer->SubscriptionClass_Printer();
	}

	void SubscriptionClass_FileInput()
	{
		this->Customer->SubscriptionClass_FileInput();
	}

	void SubscriptionClass_FileOutput()
	{
		this->Customer->SubscriptionClass_FileOutput();
	}

	void Print_Subscription_Info()
	{
		this->Customer->Print_Subscription_Info();
	}

	//-------------------------------Equipment Class Functions-------------------------------//

	void InsertEquipment()
	{
		string name;
		cout << "Enter the name of the Equipment :-";
		getline(cin, name);

		this->equipment->InsertEquipment(name);
	}

	void UpdateEquipment()
	{
		string name, newname;
		cout << "Enter the name of the old Eqiuipment :-";
		getline(cin, name);
		cout << "Enter the name of the new Eqiuipment :-";
		getline(cin, newname);

		this->equipment->UpdateEquipment(name, newname);
	}

	void RemoveEquipment()
	{
		string name;
		cout << "Enter the name of the Eqiuipment that you want to remove:-";
		getline(cin, name);

		this->equipment->RemoveEquipment(name);
	}

	void Equipment_FileInput()
	{
		this->equipment->FileInput();
	}

	void Equipment_FileOutput()
	{
		this->equipment->FileOutput();
	}


	
};
