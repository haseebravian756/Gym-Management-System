#include <iostream>
#include <string>
#include <fstream>
#include "GYM.h"
#include "Trainer.h"
#include "Date.h"
#include"Equipment.h"
#include "Exercise_plan.h"
#include "Subscription.h"

using namespace std;

int main()
{
	//object created to be passed to Gym class object and fileInput is called so that there exists some data
	Trainer trainer;
	trainer.FileInput();

	//object created to be passed to customer class object and fileInput is called so that there exists some data
	ExercisePlan exercisePlan;
	exercisePlan.FileInput();

	//object created to be passed to Gym class object and fileInput is called so that there exists some data
	customer Customer(exercisePlan);
	Customer.customerInput();

	//object created to run the functions of gym
	Gym gym(trainer, Customer);
	
	//--------------------------Inputting data from file--------------------------//

	gym.Equipment_FileInput();
	gym.ExercisePlan_FileInput();
	gym.SubscriptionClass_FileInput();
	

	cout << "//********************************WELCOME TO THE MY GYM********************************//\n\n\n";

	int check = 0;
	cout << "You are :-\n1.Manager\n2.Trainer\n";
	
	cin >> check;
	int newcheck = check;

	while (check != 5)
	{
		switch (check)
		{

		//If manager is using the program
		case 1:
		{
			cout << "You are here to :\n1.Add something\n2.Update something\n3.Remove Something.\n4.Enquire About Something\n5.Exit Program\nEnter your choice from the above points : ";
			cin >> check;

			switch (check)
			{
			
			//To add something
			case 1:
			{
				cout << "\nWhat do you want to add :-\n1.Trainer\n2.Customer\n3.Equipment\n4.New Customer Subscription\n";
				cin >> check;
				
				switch (check)
				{
				
				//Adding trainer
				case 1:
				{
					cin.ignore();
					gym.InsertTrainer();
					break;
				}
				
				//Adding Trainer
				case 2:
				{
					gym.setCustomer();
					break;
				}
				
				//Adding Equipment
				case 3:
				{
					gym.InsertEquipment();
					break;
				}

				//Adding new Subscription
				case 4:
				{
					gym.SubscriptionClass_Setter();
					break;
				}
				}
				break;
			}
			
			//To update Something
			case 2:
			{
				cout << "\nWhat do you want to update :-\n1.Trainer\n2.Customer\n3.Equipment\n4.Customer Subscription\n5.Time worked By the Trainer\n";
				cin >> check;

				switch (check)
				{

					//Updating trainer
				case 1:
				{
					cin.ignore();
					gym.UpdateTrainer();
					break;
				}

				//Adding Trainer
				case 2:
				{
					gym.UpdateCustomer();
					break;
				}

				//Adding Equipment
				case 3:
				{
					gym.UpdateEquipment();
					break;
				}

				//Adding new Subscription
				case 4:
				{
					gym.SubscriptionClass_Updator();
					break;
				}

				//trainer time updating
				case 5:
				{
					gym.UpdateTimeWorkedByTheTrainer();
					break;
				}
				}
				break;
			}

			//To Delete Something
			case 3:
			{
				cout << "\nWhat do you want to Remove :-\n1.Trainer\n2.Customer\n3.Equipment\n4.Customer Subscription\n5.Remove Exercise Plan\n";
				cin >> check;

				switch (check)
				{
				//removing trainer
				case 1:
				{
					cin.ignore();
					gym.RemoveTrainer();
					break;
				}

				//removing customer
				case 2:
				{
					gym.RemoveCustomer();
					break;
				}

				//removing equipment
				case 3:
				{
					gym.RemoveEquipment();
					break;
				}

				//removing Customer Subscription
				case 4:
				{
					gym.SubscriptionClass_Remover();
					break;
				}

				//removing Exercise Plan
				case 5:
				{
					gym.RemoveExercisePlan();
					break;
				}
				}
			break;
			}
			
			//Enquiry
			case 4:
			{
				cout << "\nWhat do you want to Enquire about :-\n1.Trainer\n2.Customer Subscription\n";
				cin >> check;

				switch (check)
				{

				//printing Trainer Info
				case 1:
				{
					gym.Print_Trainer_Info();
					break;
				}

				//priting Customer Subscription Info
				case 2:
				{
					gym.Print_Subscription_Info();
					break;
				}
				}
				break;
			}

			//To exit the program
			case 5:
			{
				gym.Trainer_FileOutput();
				gym.Customer_FileOutput();
				gym.Equipment_FileOutput();
				gym.ExercisePlan_FileOutput();
				gym.SubscriptionClass_FileOutput();

				return 0;
				break;
			}

			//default case
			default:
			{
				cout << "wrong choice..!";
				break;
			}

			}
			break;
		}

		//If trainer is using the program
		case 2:
		{
			cout << "You are here to :\n1.Add Exercise Plan\n2.Enquire About Customer Subscription\n3.Enquire About Trainer info\n5.Exit Program\nEnter your choice from the above points : ";
			cin >> check;

			switch (check)
			{
			//Adding Exercise Plan
			case 1:
			{
				gym.setExerCisePlan();
				break;
			}

			//Enquire about customer subscription
			case 2:
			{
				gym.Print_Subscription_Info();
				break;
			}

			//Enquire about Trainer Info
			case 3:
			{
				cin.ignore();
				gym.Print_Trainer_Info();
				break;
			}

			case 5:
			{
				gym.ExercisePlan_FileOutput();
				break;
			}

			default:
			{
				cout << "Wrong Choice..!";
				break;
			}
			}
			break;
		}
		}
		if(check != 5)
			check = newcheck;
	}
	
	
	

	return 0;
}