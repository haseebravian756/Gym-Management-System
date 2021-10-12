#pragma once

#include <iostream>
#include <string>
#include <fstream>
#include "Trainer.h"
#include"Equipment.h"
#include "Date.h"

using namespace std;

class ExercisePlan
{
private:
	
	int* Plan_IDs;
	int plans_size;

	int* TrainerID;
	int* EquipmentID;
	
	int* Time;

	Equipment* eQuipment;
	bool check;
public:

	//constructors
	ExercisePlan()
	{
		Plan_IDs = nullptr;
		plans_size = 0;
		
		TrainerID = nullptr;
		EquipmentID = nullptr;

		Time = nullptr;
		eQuipment = new Equipment;
		check = true;
		eQuipment->FileInput();
	}

	ExercisePlan(Equipment& equip)
	{
		Plan_IDs = nullptr;
		plans_size = 0;

		TrainerID = nullptr;
		EquipmentID = nullptr;

		Time = nullptr;
		check = false;
		eQuipment = &equip;
	}

	~ExercisePlan()
	{
		delete[] this->Plan_IDs;
		delete[] TrainerID;
		delete[] EquipmentID;
		eQuipment = nullptr;
		delete[] this->Time;
	}

	//Size Increasing Functions

	void increaseSizeOfthePlanIDArray()
	{
		this->plans_size++;
		int* newID = new int[plans_size];
		int* newDate = new int[plans_size];
		int* newEquip = new int[plans_size];
		int* newTrainer = new int[plans_size];

		for (int i = 0; i < plans_size - 1; i++)
		{
			newID[i] = Plan_IDs[i];

			newDate[i] = Time[i];

			newTrainer[i] = TrainerID[i];

			newEquip[i] = EquipmentID[i];

		}
		delete[] this->Plan_IDs;
		delete[] this->EquipmentID;
		delete[] this->Time;
		delete[] this->TrainerID;

		Plan_IDs = newID;
		EquipmentID = newEquip;
		Time = newDate;
		TrainerID = newTrainer;

		newID = nullptr;
		newDate = nullptr;
		newEquip = nullptr;
		newTrainer = nullptr;

	}
	void DecreaseSizeOfthePlanIDArray(int I)
	{
		plans_size--;
		int* newID = new int[plans_size];
		int* newDate = new int[plans_size];
		int* newEquip = new int[plans_size];
		int* newTrainer = new int[plans_size];

		for (int i = 0, j = 0; i < plans_size + 1; i++)
		{
			if (i != I)
			{
				newID[j] = Plan_IDs[i];

				newDate[j]= Time[i];

				newTrainer[j] = TrainerID[i];

				newEquip[j] = EquipmentID[i];

				j++;
			}
		}
		delete[] this->Plan_IDs;
		delete[] this->EquipmentID;
		delete[] this->Time;
		delete[] this->TrainerID;

		Plan_IDs = newID;
		EquipmentID = newEquip;
		Time = newDate;
		TrainerID = newTrainer;

		newID = nullptr;
		newDate = nullptr;
		newEquip = nullptr;
		newTrainer = nullptr;
	}

	//Member Functions

	bool PlanIdAvailable(int planID)
	{
		for (int i = 0; i < this->plans_size; i++)
		{
			if (this->Plan_IDs[i] == planID) { return true; }

		}
		return false;
	}

	int PlanIdAvailable_intReturnType(int planID)
	{
		for (int i = 0; i < this->plans_size; i++)
		{
			if (this->Plan_IDs[i] == planID) { return i; }

		}
		return -1;
	}

	bool CanPlanIdBeInserted(int planID)
	{
		for (int i = 0; i < this->plans_size; i++)
		{
			if (this->Plan_IDs[i] == planID) { return false; }

		}
		return true;
	}

	void setPlanID(int plan)
	{
		increaseSizeOfthePlanIDArray();
		Plan_IDs[this->plans_size - 1] = plan;
	}

	void SetExerciseDuration(int DurationInMinutes)
	{
		Time[this->plans_size - 1] = DurationInMinutes;
	}

	void SetExerciseEquipment(string EquipmentName)
	{
		bool check = false;
		int Index = eQuipment->getEquipmentId_Index_ByEquipmentName(EquipmentName);

		if (Index != -1)
		{
			check = true;
		}

		if (check)
		{
			EquipmentID[this->plans_size - 1] = Index;
		}
	}

	void setTrainerID(int iD)
	{
		this->TrainerID[this->plans_size - 1] = iD;
	}

	void setExercisePlan(int trainerID)
	{
		string eq_Name = "0";
		cout << "\nEnter Equipment Name : ";
		cin >> eq_Name;
		int plan_id = 0;
		cout << "\nEnter Plan ID : ";
		cin >> plan_id;

		if (this->eQuipment->EquipmentAvailable(eq_Name) && this->CanPlanIdBeInserted(plan_id))
		{
			this->setPlanID(plan_id);
			SetExerciseEquipment(eq_Name);
			setTrainerID(trainerID);

			cout << "\nEnter Exercise Duration : ";
			int dura = 0;
			cin >> dura;
			SetExerciseDuration(dura);
		}
		else
		{
			if (!this->eQuipment->EquipmentAvailable(eq_Name))
				cout << "Exercise plan not added. Equipment does not Exists in this Gym.";
			else if (!this->CanPlanIdBeInserted(plan_id))
				cout << "Exercise plan not added. Plan ID already exists(it should be unique).";
		}
	}

	void UpdateExercisePlan()
	{
		int plan_id = 0;
		cout << "\nEnter Plan ID of the Exercise plan you want to update : ";
		cin >> plan_id;

		if (this->PlanIdAvailable(plan_id))
		{
			int index = this->PlanIdAvailable_intReturnType(plan_id);

			int eq_ID = 0;
			cout << "\nEnter Updated Equipment ID : ";
			cin >> eq_ID;
			this->EquipmentID[index] = eq_ID;

			int trainerID = 0;
			cout << "Enter Updated Trainer ID : ";
			cin >> trainerID;
			this->TrainerID[index] = trainerID;

			cout << "\nEnter Updated Exercise Duration : ";
			int dura = 0;
			cin >> dura;
			this->Time[index] = dura;
		}
		else
		{
			if (!this->PlanIdAvailable(plan_id))
				cout << "Exercise plan not Found. Plan ID does not exists.";
		}
	}

	void RemoveExercisePlan(int planID)
	{
		if (this->PlanIdAvailable(planID))
		{
			DecreaseSizeOfthePlanIDArray( PlanIdAvailable_intReturnType(planID) );
		}
		else if(PlanIdAvailable_intReturnType(planID) == -1)
		{
			cout << "Plan ID not available.";
		}
	}

	void print()
	{
		cout << "Size of array : " << this->plans_size << endl;
		cout << "PlanID	TrainerID	EquipmentID	Duration\n";
		for (int i = 0; i < this->plans_size; i++)
		{
			cout << this->Plan_IDs[i] << "	" << this->TrainerID[i] << "	" << this->EquipmentID[i] << "	" << this->Time[i] << endl;
		}
	}

	void operator=(ExercisePlan _plan)
	{
		Plan_IDs = _plan.Plan_IDs;
		plans_size = _plan.plans_size;

		TrainerID = _plan.TrainerID;
		EquipmentID = _plan.EquipmentID;

		Time = _plan.Time;
		eQuipment = _plan.eQuipment;
	}

	//***************************************File Handling***************************************//

	void FileInput()
	{
		ifstream fin;
		fin.open("excercisePlans.txt");

		int dum = 0;
		char Dum = '\0';
		if (fin.is_open())
		{
			while (!fin.eof())
			{
				fin >> dum;
				this->setPlanID(dum);
				fin.ignore();

				fin >> dum;
				this->setTrainerID(dum);
				fin.ignore();

				fin >> this->EquipmentID[plans_size-1];
				fin.ignore();

				fin >> dum;
				this->SetExerciseDuration(dum);
			}
		}
		else
		{
			cout << "Unable to open File.";
		}
		fin.close();
	}

	void FileOutput()
	{
		ofstream fout;
		fout.open("excercisePlans.txt");
		for (int i = 0; i < this->plans_size; i++)
		{
			if (i == this->plans_size - 1)
				fout << this->Plan_IDs[i] << "	" << this->TrainerID[i] << "	" << this->EquipmentID[i] << "	" << this->Time[i];
			else
				fout << this->Plan_IDs[i] << "	" << this->TrainerID[i] << "	" << this->EquipmentID[i] << "	" << this->Time[i] << endl;
		}
		fout.close();
	}
};