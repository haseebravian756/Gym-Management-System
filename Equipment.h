#pragma once

#include <iostream>
#include <fstream>
#include <string>

using namespace std;

class Equipment
{
private:
	int size;
	int* Equip_ID;
	string** equipment;

public:
	//constructors
	Equipment()
	{
		size = 0;
		equipment = nullptr;
		Equip_ID = nullptr;
	}

	~Equipment()
	{
		if (Equip_ID != nullptr)
		{
			delete[] Equip_ID;
			Equip_ID = nullptr;
		}

		if (equipment != nullptr)
		{
			for (int i = 0; i < this->size; i++)
			{
				delete equipment[i];
			}
			delete[] equipment;
		}
	}

	//Size Increasing Functions

	void increaseSizeOftheEquipmentArray()
	{
		size++;
		int* newID = new int[size];
		string** newEquipmentarray = new string * [size];

		for (int i = 0; i < size - 1; i++)
		{
			newID[i] = Equip_ID[i];
			newEquipmentarray[i] = new string(this->equipment[i][0]);
			delete this->equipment[i];
		}
		delete[] this->equipment;
		delete[] this->Equip_ID;

		Equip_ID = newID;
		newID = nullptr;

		this->equipment = newEquipmentarray;
		newEquipmentarray = nullptr;
	}
	void DecreaseSizeOftheEquipmentArray(int I)
	{
		size--;
		int* newID = new int[size];
		string** newTrainerarray = new string * [size];
		for (int i = 0, j = 0; i < size + 1; i++)
		{
			if (i != I)
			{
				newID[j] = Equip_ID[i];
				newTrainerarray[j] = new string(this->equipment[i][0]);
				delete this->equipment[i];
				j++;
			}
			else
			{
				delete this->equipment[i];
			}
		}
		delete[] this->equipment;
		delete[] this->Equip_ID;

		Equip_ID = newID;
		newID = nullptr;

		this->equipment = newTrainerarray;
		newTrainerarray = nullptr;
	}

	//member functions

	bool EquipmentAvailable(int EquipmentID)
	{
		for (int i = 0; i < this->size; i++)
		{
			if (this->Equip_ID[i] == EquipmentID) { return true; }

		}
		return false;
	}

	bool EquipmentAvailable(const string NameOfTheEquipment)
	{
		for (int i = 0; i < this->size; i++)
		{
			if (this->equipment[i][0] == NameOfTheEquipment) { return true; }

		}
		return false;
	}

	//*****************************Setters*****************************//

	void InsertEquipment(const string NameOfTheEquipment)
	{
		for (int i = 0; i < this->size; i++)
		{
			if (this->equipment[i][0] == NameOfTheEquipment)
			{
				cout << "\nEquipment Not Inserted: Equipment Already Exists\n\n";
				return;
			}
		}
		increaseSizeOftheEquipmentArray();
		this->Equip_ID[size - 1] = size;
		this->equipment[size - 1] = new string(NameOfTheEquipment);
	}

	void UpdateEquipment(const string NameOftheOldEquipment, const string NameOftheNewEquipment)
	{
		bool check = true;

		for (int i = 0; i < this->size; i++)
		{
			if (this->equipment[i][0] == NameOftheOldEquipment)
			{
				equipment[i][0] = NameOftheNewEquipment;
				check = false;
			}
		}

		if (check)
		{
			cout << "\nEquipment Not Updated: Equipment does not exist\n\n";
		}
	}

	//*****************************Getter*****************************//

	string** getEquipmentNames() { return equipment; }

	int* getEquipmentID() { return Equip_ID; }

	int getSize() { return size; }

	int getEquipmentId_Index_ByEquipmentName(const string E_NAME)
	{

		for (int i = 0; i < this->size; i++)
		{
			if (E_NAME == this->equipment[i][0])
			{
				return i + 1;
			}
		}
		cout << "\nEquipment Not Found: -1 returned\n\n";
		return -1;
	}
	
	//*****************************Remover*****************************//

	void RemoveEquipment(const string NameOfTheTrainer)
	{
		bool check = true;

		for (int i = 0; i < this->size; i++)
		{
			if (this->equipment[i][0] == NameOfTheTrainer)
			{
				DecreaseSizeOftheEquipmentArray(i);
				check = false;
			}
		}

		if (check)
		{
			cout << "Equipment does exist in this Gym..!" << endl;
		}
	}

	//------------------------------File Handling Functions------------------------------//

	void print()
	{
		for (int i = 0; i < this->size; i++)
		{
			cout << this->Equip_ID[i] << " " << this->equipment[i][0] << endl;
		}
	}

	void FileInput()
	{
		ifstream fin;
		fin.open("Equipment.txt");
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
				InsertEquipment(name);
			}
		}
		else
		{
			cout << "Unable to open File Equipment.txt.";
		}
		fin.close();
	}

	void FileOutput()
	{
		ofstream fout;
		fout.open("Equipment.txt");
		fout << "EquipmentID	Name\n";
		for (int i = 0; i < this->size; i++)
		{
			if (i == size - 1)
			{
				fout << this->Equip_ID[i] << "		" << this->equipment[i][0];
			}
			else
				fout << this->Equip_ID[i] << "		" << this->equipment[i][0] << "\n";
		}
		fout.close();
	}
};
