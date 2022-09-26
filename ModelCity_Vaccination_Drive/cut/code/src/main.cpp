/**********************************************************************************
  *  FILENAME     : main.c
  *  
  *  DESCRIPTION : This file is used as Main menu of the vaccination drive which calls 
  *                 user login and admin login options.
  *
  *  REVISION HISTORY
  *
  *  DATE             NAME          REASON
  *
  * -----------------------------------------------------
  *
  *  22/09/22         Group-5       Menu
  *
  * ********************************************************************************/
#include "password.cpp" // Required header file
#include "header.hpp"
#include "functions.cpp"
using namespace std;

void  menu()	//Function to display admin menu
{
	system("clear");
	int choice;
	int admin_pass=0;
	while(choice!=3)
	{
		cout<<endl<<"---------------------------------"<<endl;
		cout<<endl<<"\t MAIN MENU"<<endl;
		cout<<endl<<"\t1. User Login"<<endl;
		cout<<endl<<"\t2. Admin Login"<<endl;
		cout<<endl<<"\t3. Exit"<<endl;
		cout<<endl<<"---------------------------------"<<endl;
		cin>>temp;	//Accepting input
		try
		{
			choice=atoi(temp);	//Convert string to integer and store in variable choice
		}
		catch(exception& ex)
		{
			cout<<endl<<"Exception Occured...Enter only digits"<<endl;
		}
		switch(choice)
		{
			case 1:
				system("clear");
				user_login();	// calling user_login function
				break;
			case 2: system("clear");
				cout<<endl<<"\t\tAdmin Login"<<endl<<endl;
				admin_pass=checkpassword();	// check admin's password
				if(admin_pass==1)	//If password does not match
				{
					printf("\nINVALID PASSWORD!!\n");
					continue;
				}
				else
				{
					admin_login();  // calling admin_login function
				}
				break;
			case 3: 
				system("clear");
				break;
			default:system("clear"); 
				cout<<endl<<"Invalid Choice"<<endl;
		}
	}
	
	system("clear");
}

void user_login()	//Function to display User menu
{
	system("clear");
	user u;
	int choice1;
	while(choice1!=3)
	{
		cout<<endl<<"---------------------------------"<<endl;
		cout<<endl<<"\t User Corner"<<endl;
		cout<<endl<<"\t 1. New User"<<endl;
		cout<<endl<<"\t 2. Registered User"<<endl;
		cout<<endl<<"\t 3. Exit"<<endl;
		cout<<endl<<"---------------------------------"<<endl;
		cout<<endl<<"Enter your choice: "<<endl;
		cin>>temp;	//Accepting input from user
		try
		{
			choice1=atoi(temp);
		}
		catch(exception& ex)
		{
			cout<<endl<<"Exception Occured...Enter only digits"<<endl;
		}
		switch(choice1)
		{
			case 1:
				system("clear");
				u.new_user();	//Function call to new_user function 
				break;
			case 2:
				system("clear");
				u.registered_user();	//function call to registered_user function
				break;
			case 3: 
				system("clear");
				break;
			default:system("clear"); 
				cout<<endl<<"Invalid Choice"<<endl;
		}
	}
}

void admin_login()	//Function to display admin menu
{
	int choice3;
	system("clear");
	admin a;
	while(choice3!=8)
	{
		cout<<endl<<"---------------------------------"<<endl;
		cout<<endl<<"\t Admin Corner"<<endl;
		cout<<endl<<"\t 1. Show Beneficiary Data"<<endl;
		cout<<endl<<"\t 2. Add Vaccine stock"<<endl;
		cout<<endl<<"\t 3. Display Vaccine Stock"<<endl;
		cout<<endl<<"\t 4. Delete Fully Vaccinated Beneficiaries"<<endl;
		cout<<endl<<"\t 5. Display non vaccinated beneficiaries"<<endl;
		cout<<endl<<"\t 6. Display Fully Vaccinated Beneficiaries"<<endl;
		cout<<endl<<"\t 7. Display Today Vaccinated Beneficiaries"<<endl;
		cout<<endl<<"\t 8. Exit"<<endl;
		cout<<endl<<"---------------------------------"<<endl;
		cout<<endl<<"Enter your choice: "<<endl;
		cin>>temp;	//Accepting input from user
		try
		{
			choice3=atoi(temp);
		}
		catch(exception& ex)
		{
			cout<<endl<<"Exception Occured...Enter only digits"<<endl;
		}
		admin *ptr=new admin();
		switch(choice3)
		{
			case 1:
				system("clear");
				a.show_bene_data();	//Function call to show_beneficiary_function
				break;
			case 3:
				system("clear");
				a.display_vaccine_stock();	//Function call to display_vaccine_stock
				break;
			case 4:
				system("clear");
				a.delete_fully_vaccinated();	//Function call to delete_fully_vaccinated function
				break;
			case 5: 
				system("clear");
				a.non_vaccinated();	//Function call to non_vaccinated function
				break;
			case 6: 
				system("clear");
				a.fully_vaccinated();	//Function call to fully_vaccinated function
				break;
			case 7:
				system("clear");
				a.today_vaccinated();	//Function call to today_vaccinated function
				break;
			case 8: 
				system("clear");
				break;
			default:system("clear");
				cout<<endl<<"Invalid Choice"<<endl;
			case 2:
				system("clear");
				thread thread1(&admin::add_vaccine_stock,ptr);	//Create thread
				thread1.join();	//Join the thread
				break;
		}
	}
}
void user :: new_user()
{
	system("clear");
	int choice2;
	while(choice2!=3)
	{
		cout<<endl<<"---------------------------------"<<endl;
		cout<<endl<<"\t New User Corner"<<endl;
		cout<<endl<<"\t 1. Create account"<<endl;
		cout<<endl<<"\t 2. View Details"<<endl;
		cout<<endl<<"\t 3. Exit"<<endl;
		cout<<endl<<"---------------------------------"<<endl;
		cout<<endl<<"Enter your choice: "<<endl;
		cin>>temp;	//Take input from user
		try
		{
			choice2=atoi(temp);
		}
		catch(exception& ex)
		{
			cout<<endl<<"Exception Occured...Enter only digits"<<endl;
		}
		cout<<choice2<<endl;
		switch(choice2)
		{
			case 1:
				system("clear");
				create_account();	//Function call to create_account function
				break;
			case 2:
				system("clear");
				view_details();		//Function call to view_details function
				break;
			case 3: 
				system("clear");

				break;
			default:system("clear");
				cout<<endl<<"Invalid Choice"<<endl;
		}
	}
}

void user :: registered_user()	//This function displays the register corner menu
{
	int choice4;
	system("clear");
	while(choice4!=5)
	{
		cout<<endl<<"---------------------------------"<<endl;
		cout<<endl<<"\t Registered User Corner"<<endl;
		cout<<endl<<"\t 1. Select centre"<<endl;
		cout<<endl<<"\t 2. Book Vaccine Slot"<<endl;
		cout<<endl<<"\t 3. View Details"<<endl;
		cout<<endl<<"\t 4. Get Vaccinated"<<endl;
		cout<<endl<<"\t 5. Exit"<<endl;
		cout<<endl<<"---------------------------------"<<endl;
		cout<<endl<<"Enter your choice: "<<endl;
		cin>>temp;
		try
		{
			choice4=atoi(temp);
		}
		catch(exception& ex)
		{
			cout<<endl<<"Exception Occured...Enter only digits"<<endl;
		}
		user *ptr=new user();
		switch(choice4)
		{
			case 1:
				system("clear");
				select_centre();	//Function call to select_centre function
				break;
			case 3: 
				system("clear");
				register_details();	//Function call to register_details function
				break;
			case 4: 
				system("clear");
				get_vaccinated();	//Function call to get_vaccinated Function
				break;
			case 5: 
				system("clear");
				break;
			default: system("clear"); 
				 cout<<endl<<"Invalid Choice"<<endl;
			case 2:
				system("clear");
				thread thread1(&user::book_slot,ptr);	//Thread creation
				thread1.join();	//Join the thread
				break;
		}
	}
}
int main()	// This is the main function
{	
	u1.reg_file_to_list();	//For inserting records in list from Registered File
	ad.vaccine_file_to_list();	//For inserting records in Registered File from list

	menu();

	u1.reg_list_to_file(); //For inserting records in Registered File from list
	ad.vaccine_list_to_file(); //For inserting records in list from Vaccine File

	return EXIT_SUCCESS;
}
