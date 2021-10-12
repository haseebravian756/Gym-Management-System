#pragma once

#include <iostream>
#include <fstream>
#include <string>
#include "Date.h"
#include "Exercise_plan.h"


using namespace std;

class Trainer
{
private:
	int size;

	int* ID;

	Date* TimeWorkedByTrainer;
	ExercisePlan plan;
	string** trainer;

public:
	//constructors
	Trainer()
	{
		size = 0;

		ID = nullptr;

		TimeWorkedByTrainer = nullptr;

		trainer = nullptr;
	}

	//Destructor

	~Trainer()
	{
		if (ID != nullptr)
		{
			delete[] ID;
		}
		
		if (trainer != nullptr)
		{
			for (int i = 0; i < this->size; i++)
			{
				delete trainer[i];
			}
			delete[] trainer;
		}
	}

	//Size Increasing Functions

	void increaseSizeOftheTrainerArray()
	{
		size++;
		int* newID = new int[size];
		string** newTrainerarray = new string * [size];
		for (int i = 0; i < size - 1; i++)
		{
			newID[i] = ID[i];
			newTrainerarray[i] = new string(this->trainer[i][0]);
			delete trainer[i];
		}
		delete[] trainer;
		delete[] ID;

		ID = newID;
		newID = nullptr;

		trainer = newTrainerarray;
		newTrainerarray = nullptr;
	}
	void DecreaseSizeOftheTrainerArray(int I)
	{
		size--;
		int* newID = new int[size];
		string** newTrainerarray = new string * [size];
		for (int i = 0, j = 0; i < size + 1; i++)
		{
			if (i != I)
			{
				newID[j] = ID[i];
				newTrainerarray[j] = new string(this->trainer[i][0]);
				delete this->trainer[i];
				j++;
			}
			else
			{
				delete trainer[i];
			}
		}
		delete[] trainer;
		delete[] ID;

		ID = newID;
		newID = nullptr;

		this->trainer = newTrainerarray;
		newTrainerarray = nullptr;
	}

	//member functions

	bool TrainerAvailable(int TrainerID)
	{
		for (int i = 0; i < this->size; i++)
		{
			if (this->ID[i] == TrainerID) { return true; }
		}

		return false;
	}

	bool TrainerAvailable(const string NameOfTheTrainer)
	{
		for (int i = 0; i < this->size; i++)
		{
			if (this->trainer[i][0] == NameOfTheTrainer) { return true; }
		}

		return false;
	}

	//------------------------------File Handling Functions------------------------------//

	void FileInput()
	{
		ifstream fin;
		fin.open("trainers.txt");
		int id = 0;
		string name = "0";
		fin >> name;
		fin.ignore();
		fin >> name;
		if (fin.is_open())
		{
			while (!fin.eof())
			{
				fin >> id;
				fin.ignore();
				fin.ignore();
				getline(fin, name);
				InsertTrainer(name);
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
		fout.open("trainers.txt");
		fout << "TrainerID	Name\n";
		for (int i = 0; i < this->size; i++)
		{
			fout << this->ID[i] << "		" << this->trainer[i][0] << "\n";
		}
		fout.close();
	}

	void print()
	{
		for (int i = 0; i < this->size; i++)
		{
			cout << this->ID[i] << " " << this->trainer[i][0] << endl;
		}
	}

	void Print_Trainer_Info(string NameOfTheTrainer)
	{
		if (TimeWorkedByTrainer != nullptr)
		{
			for (int i = 0; i < this->size; i++)
			{
				if (this->trainer[i][0] == NameOfTheTrainer)
					cout << "TrainerID : " << this->ID[i] << "\nTrainer Name : " << this->trainer[i][0] << "\nTime Worked By the Trainer : " << TimeWorkedByTrainer[i].getTime() << endl;
			}
		}
		else
		{
			for (int i = 0; i < this->size; i++)
			{
				if (this->trainer[i][0] == NameOfTheTrainer)
					cout << "TrainerID : " << this->ID[i] << "\nTrainer Name : " << this->trainer[i][0] << "\nTime Worked By the Trainer : No data for Time." << endl;
			}
		}
	}

	/*void setExercisePlan()
	{
		int trainerID = 0;
		cout << "Enter Trainer ID : ";
		cin >> trainerID;
		string eq_Name = "0";
		cout << "\nEnter Equipment Name : ";
		cin >> eq_Name;
		int plan_id = 0;
		cout << "\nEnter Plan ID : ";
		cin >> plan_id;

		if (this->TrainerAvailable(trainerID) && this->plan.eQuipment->EquipmentAvailable(eq_Name) && this->CanPlanIdBeInserted(plan_id))
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
			if (!this->Trainers->TrainerAvailable(trainerID))
				cout << "Exercise plan not added. Trainer does not Exists in this Gym.";
			else if (!this->eQuipment->EquipmentAvailable(eq_Name))
				cout << "Exercise plan not added. Equipment does not Exists in this Gym.";
			else if (this->CanPlanIdBeInserted(plan_id))
				cout << "Exercise plan not added. Plan ID already exists(it should be unique).";
		}
	}*/

	void ExercisePlan_FileInput()
	{
		this->plan.FileInput();
	}

	void ExercisePlan_FileOutput()
	{
		this->plan.FileOutput();
	}

	//*****************************Setters*****************************//

	/*void InsertTrainer(int iD)
	{
		for (int i = 0; i < this->size; i++)
		{
			if (this->ID[i] == iD)
			{
				cout << "\nTrainer Not Inserted: Trainer ID already Exists\n\n";
				return;
			}
		}

		increaseSizeOftheTrainerArray();

		this->ID[size - 1] = iD;
	}*/

	void InsertTrainer(const string NameOfTheTrainer)
	{
		for (int i = 0; i < this->size; i++)
		{
			if (this->trainer[i][0] == NameOfTheTrainer)
				return;
		}

		increaseSizeOftheTrainerArray();

		this->ID[size - 1] = size;
		this->trainer[size - 1] = new string(NameOfTheTrainer);
	}

	/*void InsertTrainer(int iD, const string NameOfTheTrainer)
	{
		for (int i = 0; i < this->size; i++)
		{
			if (this->trainer[i][0] == NameOfTheTrainer)
				return;
		}

		increaseSizeOftheTrainerArray();

		this->ID[size - 1] = iD;
		this->trainer[size - 1] = new string(NameOfTheTrainer);
	}*/

	void UpdateTimeWorkedByTheTrainer(string NameOfTheTrainer, int newTime)
	{
		bool check = true;
		bool check2 = false;

		if ((newTime <= 8) && (newTime > 0))
		{
			check = true;
		}

		if (check)
		{
			if (this->TimeWorkedByTrainer == nullptr)
			{
				this->TimeWorkedByTrainer = new Date[this->size];
			}

			for (int i = 0; i < this->size; i++)
			{
				if (this->TrainerAvailable(NameOfTheTrainer))
				{
					this->TimeWorkedByTrainer[i].setTime(newTime);
					check2 = false;
				}
			}

			if (check2)
			{
				cout << "\nTrainer Time Not Inserted: Trainer is not available\n\n";
			}
		}
		else
		{
			cout << "\nTrainer Time Not Inserted: Trainer cannot work more than 8 hours daily\n\n";
		}
	}

	void UpdateTrainer(const string NameOftheOldTrainer, const string NameOftheNewTrainer)
	{
		bool check = true;

		for (int i = 0; i < this->size; i++)
		{
			if (this->trainer[i][0] == NameOftheOldTrainer)
			{
				trainer[i][0] = NameOftheNewTrainer;
				check = false;
			}
		}

		if (check)
		{
			cout << "\nTrainer Not Updated: Trainer name does not exist\n\n";
		}
	}

	//*****************************Remover*****************************//

	void RemoveTrainer(const string NameOfTheTrainer)
	{
		bool check = true;

		for (int i = 0; i < this->size; i++)
		{
			if (this->trainer[i][0] == NameOfTheTrainer)
			{
				DecreaseSizeOftheTrainerArray(i);
				check = false;
			}
		}

		if (check)
		{
			cout << "\nTrainer Not Removed: Trainer does exist in this Gym..!\n\n";
		}
	}

	void setExerCisePlan()
	{
		int trainerID = 0;
		cout << "Enter Trainer ID : ";
		cin >> trainerID;
		if (this->TrainerAvailable(trainerID))
		{
			this->plan.setExercisePlan(trainerID);
		}
		else if (!this->TrainerAvailable(trainerID))
			cout << "Exercise plan not added. Trainer does not Exists in this Gym.";
	}

	void UpdateExercisePlan()
	{
		this->plan.UpdateExercisePlan();
	}

	void RemoveExercisePlan()
	{
		int plan_id = 0;
		cout << "\nEnter Plan ID of the Exercise plan you want to Remove : ";
		cin >> plan_id;

		this->plan.RemoveExercisePlan(plan_id);
	}

	friend void ExercisePlan::setTrainerID(int iD);
};