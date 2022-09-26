/**********************************************************************************
  *  FILENAME     : functions.cpp
  *  
  *  DESCRIPTION : This file contains all the functions and perform all
  *                designated task.
  *  REVISION HISTORY
  *
  *  DATE             NAME          REASON
  *
  * -----------------------------------------------------
  *
  *  22/09/22         Group-5      Perform Operations
  *
  * ********************************************************************************/
#ifndef FUNC1
#define FUNC1

#include "validation.cpp"	// Include required header files
#include "header.hpp"
#include "file.cpp"
#include <unistd.h>

using namespace std;
string temp,input;
mutex accum_mutex;


int user :: create_account()	//Function to create account of beneficiary
{
	string n2,a4;
	while(1)
	{
		cout<<endl<<"Enter Aadhar Number : ";
		cin>>input;	//Take aadhar number as input
		if(aadhar_len(input)==false)	//Check aadhar number validation
			continue;

		int flag = 0;

		for(list<user>::iterator it=l1.begin();it!=l1.end();it++)	//Traverse through list
		{
			if(it->aadhar_no == input)
			{
				flag=1;
				break;
			}
		}
		if(flag == 1)
		{
			cout<<"Account with this already exists"<<endl<<"Registration not completed"<<endl;
			return 0;
		}
		else
		{
			u1.aadhar_no=input;
			break;
		}
	}

	while(1)
	{
		cout<<endl<<"Enter your Age : ";
		cin>>input;	//Accept age from user
		if(age_validation(input)==false)	//Check age validation
			return 0;
		else
		{
			u1.age=stoi(input);
			break; //should terminate the program.
		}

	}
	while(1)
	{
		cout<<endl<<"Enter your name : ";
		cin>>input;	//Take name as input
		if(name_validation(input)==false)	//Check name validations
			continue;
		else
		{
			u1.name=input;	//Store in class variable
			break; 
		}
	}
	n2=u1.name.substr(0,2);	//Extract first two letters from name
	a4=u1.aadhar_no.substr(0,4);	//Extract first 4 digits from aadhar number
	u1.registration_id=n2+a4;	//Generate registration id
	cout<<endl<<"Your Registeration ID is : "<<u1.registration_id<<endl;
	while(1)
	{
		cout<<endl<<"Enter Gender (F/M/O) : ";
		cin>>input;	//Take gender as input
		if(gender_validation(input)==false)	//Check gender validation
			continue;
		else
		{
			u1.gender=input;	//store in class variable
			break;
		}
	}
	l1.push_back(u1);	//push user object into l1 list

	system("clear");
	return 0;
}


int user :: view_user()	//Function to view beneficiary details
{
	cout<<aadhar_no<<"\t"<<name<<"\t"<<age<<"\t"<<gender<<"\t"<<shots<<endl;
	return EXIT_SUCCESS;
}


int user :: view_registered_user()	//Function to display registered user details
{
	cout<<aadhar_no<<"\t"<<name<<"\t"<<age<<"\t"<<gender<<"\t"<<centre<<"\t\t"<<time_s<<"\t\t"<<shots<<endl;
	return EXIT_SUCCESS;
}


int user :: view_details()	//Function to view beneficiary details
{
	string m_aadhar_no;
	if(l1.empty())	//Check if list is empty
	{
		cout<<"Empty File "<<endl;
		return EXIT_FAILURE;
	}
	cout<<"Enter your Aadhar number to view your details: ";
	cin>>m_aadhar_no;	//Take aadhar number as input
	cout<<endl<<"----------------View Details-----------------"<<endl;
	cout<<endl<<"Aadhar\tName\tAge\tGender\tShots"<<endl;
	int flag=0;
	for(list<user>::iterator it=l1.begin();it!=l1.end();it++)	//Traverse through list
	{
		if(it->get_aadhar()==m_aadhar_no)
		{
			it->view_user();	//Function call to view_user function
			break;
		}
		else
		{
                       flag=1;
		}
	}
	if(flag==1)
	{
		cout<<"Aadhar number not found"<<endl;
	}
	system("read a");
	system("clear");
	return EXIT_SUCCESS;
}


int user :: select_centre()	//Function to allow beneficiary to select centre
{

	string m_aadhar_no=" ";
	cout<<"Enter your aadhar number: ";
	cin>>m_aadhar_no;	//Take aadhar number as input from beneficiary
	cout<<endl<<endl;
	vector<string> v;	//Vector declaration
	int choice=0;
	v.push_back("1. Hawkins");	//push centres in vector
	v.push_back("2. Riverdale");
	v.push_back("3. Central Perk");
	for(string it:v)	//display content of vector
	{
		cout<<it<<endl;
	}
	int flag=0;
	list<user> :: iterator it;	
	for(it=l1.begin();it!=l1.end();it++)	//Traverse through list
	{

		if(it->get_aadhar()==m_aadhar_no)
		{
			flag=1;
			break;
		}
	}
	if(flag==1)
	{
		cout<<endl<<"Select one centre"<<endl;
		cin>>temp;	//Accept choice from user
		try
		{
			choice=stoi(temp);
		}
		catch(exception& ex)
		{
			cout<<endl<<"Exception Occured...Enter only digits"<<endl;
			return 0;
		}

		if(choice==1)
		{
			it->centre = "Hawkins";
			cout<<endl<<"Your centre for vaccination drive is succesfully selected"<<endl;
			cout<<endl<<"__________________________________________________________"<<endl;
		}
		else if(choice==2)
		{
			it->centre = "Riverdale";
			cout<<endl<<"Your centre for vaccination drive is succesfully selected"<<endl;
			cout<<endl<<"__________________________________________________________"<<endl;
		}
		else if(choice==3)
		{
			it->centre = "Central Perk";
			cout<<endl<<"Your centre for vaccination drive is succesfully selected"<<endl;
			cout<<endl<<"__________________________________________________________"<<endl;
		}
		else
		{
			cout<<endl<<"Invalid Choice";
		}
	}
	else
	{
		cout<<endl<<"Aadhar number not found"<<endl;
	}

	lc.push_back(u1);	//push object in copy list
	list<user>l1 (lc);	//copy list into original list
	
	system("read a");
	system("clear");
	return 0;
}


int user :: book_slot()	//Function to allow user to book slot
{
	string m_aadhar_no;
	int auto_token;
	time_t t1;
	cout<<"Enter your aadhar number: ";
	cin>>m_aadhar_no;	//accept input from beneficiary
	cout<<endl<<endl;
	int choice;

	vector<string> v;
	list<user>::iterator it;
	for(it=l1.begin();it!=l1.end();it++)	//Traverse through list
	{
		if(it->get_centre()=="NA")	//If centre is not selected
		{
			cout<<endl<<"Please select your centre first to book the slot"<<endl;
			return 0;
		}
		else
		{
			cout<<endl<<endl<<"**************Book your slot**************"<<endl<<endl;
			v.push_back("1. Morning");
			v.push_back("2. Afternoon");
			for(string it:v)	//Display contents of vector
			{
				cout<<it<<endl;
			}
			cout<<endl<<endl<<"*****************************************"<<endl<<endl;
			if(it->get_aadhar()==m_aadhar_no)	//If aadhar number is present in list
			{
				cout<<endl<<"Select one slot: "<<endl;
				cin>>temp;	//accept input from beneficiary
				try
				{
					choice=stoi(temp);
				}
				catch(exception& ex)
				{
					cout<<endl<<"Exception Occured...Enter only digits"<<endl;
					return EXIT_FAILURE;
				}
				if(choice<=0 || choice>=3)
				{
						cout<<endl<<"Entered slot is wrong....Please enter correct time slot"<<endl;
						return EXIT_FAILURE;
				}
				srand((unsigned) time(&t1)); //generates random unique token no
				auto_token=rand() % 50;
				accum_mutex.lock();; //lock mutex object
				cout<<endl<<"YOUR TOKEN FOR BOOKING IS: **"<<auto_token<<"**"<<endl;
				accum_mutex.unlock();; //release mutex object
				cout<<endl<<"PLEASE CONFIRM YOUR TOKEN"<<endl;
				cin>>temp;	//accept token from beneficiary
				try
				{
					it->token=stoi(temp);
				}
				catch(exception& ex)
				{
					cout<<endl<<"Exception Occured...Enter only digits"<<endl;
					return 0;
				}
				if(it->token==auto_token) //checks the token number
				{
					if(choice==1)	//If beneficiary selects morning slot
					{
						while(1)
						{
							
							cout<<"Confirm your time between 10 to 12"<<endl;
							cin>>temp;
							try
							{
								it->time_s=stoi(temp);
							}
							catch(exception& ex)
							{
								cout<<endl<<"Exception Occured...Enter only digits"<<endl;
								return 0;
							}
							if(it->time_s<10 || it->time_s>12)	//checks for valid time slot
							{
								cout<<endl<<"Please enter valid time slot"<<endl;
								continue;
							}
							else
							{
								break;
							}
						}
					}
					if(choice==2)	//If choice is afternoon slot
					{
						while(1)
						{
							cout<<"Confirm your time between 1 to 4"<<endl;
							cin>>temp;
							try
							{
								it->time_s=stoi(temp);
							}
							catch(exception& ex)
							{
								cout<<endl<<"Exception Occured...Enter only digits"<<endl;
								return 0;
							}
							
							if(it->time_s<1 || it->time_s>4)	//checks for valid time slot
							{
								cout<<endl<<"Please enter valid time slot"<<endl;
								continue;
							}
							else
							{
								break;
							}
						}
					}

				}

				else
				{
					cout<<endl<<"Entered token is wrong. Please recheck your entered token"<<endl;
					return 0;
				}
			}
			else
			{
				cout<<endl<<"Aadhar number not found"<<endl;
				return 0;
			}
			break;
		}
	}
	lc.push_back(u1);	//push object into list
	list<user>l1 (lc);
	cout<<endl<<"Your Vaccination slot is selected successfully"<<endl;
	cout<<endl<<"__________________________________"<<endl;
	if(it->centre=="Hawkins")
	{
		--ad.vcount1;	//decrease vaccine units in vaccine file
	}
	if(it->centre=="Riverdale")
	{
		--ad.vcount2;
	}
	if(it->centre=="Central Perk")
	{
		--ad.vcount3;
	}
	lc2.push_back(ad);
	l2.clear();
	for(list<admin> :: iterator it=lc2.begin();it!=lc2.end();it++)
	{
		l2.push_back(*it);	//push contents in admin list
	}
	
	system("read a");
	system("clear");
	return 0;
}


int user :: register_details()	//Function to display details of register user
{
	string m_aadhar_no;
	if(l1.empty())	//checks if list is empty
	{
		cout<<"Empty File "<<endl;
		return EXIT_FAILURE;
	}
	cout<<"Enter your Aadhar number to view your details: ";
	cin>>m_aadhar_no;	//Accepts input from user
	cout<<endl<<"----------------View Details-----------------"<<endl<<endl;
	cout<<endl<<"Aadhar\tName\tAge\tGender\tCentre\t\tTime slot\tShots"<<endl;
	int flag=0;
	for(list<user>::iterator it=l1.begin();it!=l1.end();it++)	//Traverse through the list
	{
		if(it->get_aadhar()==m_aadhar_no)	//checks for aadhar number in list
		{
			it->view_registered_user();	//Function call to view registered_user function
			flag=1;
			break;
		}
	}
	if(flag==0)
	{
		cout<<endl<<"No Records Available"<<endl;
	}
	system("read a");
	system("clear");
	return EXIT_SUCCESS;
}


int user :: get_vaccinated()	//Function to allow user to complete vaccination
{
	string m_aadhar_no;
	int m_token;
	if(l1.empty())	//checks if list is empty
	{
		cout<<"Empty File "<<endl;
		return EXIT_FAILURE;
	}
	cout<<"Enter your Aadhar number: ";
	cin>>m_aadhar_no;	//Takes input from user
	for(list<user>::iterator it=l1.begin();it!=l1.end();it++)	//Traverse through list
	{
		if(it->get_time()==0 || it->get_centre()=="NA")	//checks if centre and time slot are selected
		{
			cout<<endl<<"Please select a centre and time slot first to get vaccinated"<<endl;
			break;
		}
		else
		{
			if(it->get_aadhar()==m_aadhar_no)
			{
				if(it->get_shots()>=3)	//If beneficiary has completed all three doses
				{
					cout<<endl<<"You have already completed your 3 doses"<<endl;
					return 0;
				}
				else
				{
					cout<<endl<<"PLEASE CONFIRM YOUR TOKEN"<<endl;
					cin>>temp;
					try
					{
						m_token=stoi(temp);
					}
					catch(exception& ex)
					{
						cout<<endl<<"Exception Occured...Enter only digits"<<endl;
						return 0;
					}
					if(it->token==m_token) //checks the token number
					{
						++it->shots;	//increase shot count
						cout<<endl<<"***********Congratulations on getting vaccinated**********"<<endl;
						cout<<endl<<"You have completed "<<it->shots<<" doses"<<endl;
						break;
					}
					else
					{
						cout<<endl<<"Entered token is wrong"<<endl;
						return 0;
					}
				}
			}
		}
	}
	lc.push_back(u1);	//push contents in list
	list<user>l1 (lc);

	return 0;
}


string user :: get_aadhar()	//function to get aadhar number
{
	return this->aadhar_no;
}
string user :: get_centre()	//function to get centre
{
	return this->centre;
}
string user :: get_name()	//function to get name
{
	return this->name;
}
int user :: get_token()	//function to get token
{
	cout<<"Token: "<<token;
	return this->token;
}
int user :: get_shots()	//function to get shots
{
	return this->shots;
}
int user :: get_time()	//function to get_time
{
	return this->time_s;
}
int user :: get_age()	//function to get_age
{
	return this->age;
}


int admin :: show_bene_data()	//Function to show beneficiary details
{
	if(l1.empty())	//checks if list is empty
	{
		cout<<"Empty File "<<endl;
		return EXIT_FAILURE;
	}
	cout<<endl;
	cout<<endl<<"Aadhar\tName\tAge\tGender\tCentre\t\tTime slot\tShots"<<endl<<endl;
	for(list<user>::iterator it=l1.begin();it!=l1.end();it++)	//Traverse through list
	{
		it->view_registered_user();	//Function call to view_registered_user function
	}
	system("read a");
	system("clear");
	return 0;
}


int admin :: add_vaccine_stock()	// This function is used to  add vaccine stock 
{
	int choice,add=0;
	vector<string> v1;
	v1.push_back("1. Hawkins");
	v1.push_back("2. Riverdale");
	v1.push_back("3. Central Perk");
	for(string it:v1)	//Display contents of vector
	{
		cout<<it<<endl;
	}
	cout<<endl<<"Select the slot in which you want to add vaccine stock: "<<endl;
	cin>>temp;	//Take input from user
	try
	{
		choice=stoi(temp);
	}
	catch(exception& ex)
	{
		cout<<endl<<"Exception Occured...Enter only digits"<<endl;
		return 0;
	}
	for(list<admin> :: iterator it=l2.begin();it!=l2.end();it++) //Traverse through list
	{

		if(choice==1)	//if choice is Hawkins
		{
			cout<<"\n\t\t-->>For Center 1<<--"<<endl; 
			cout<<endl<<"Vaccine in Center *"<<ad.centre1<<"* are: "<<it->vcount1<<endl; 

			cout<<"\n\tEnter Number of vaccines you want to add: "; 
			cin>>temp;	//takes input from user 
			try
			{
				add=stoi(temp);
			}
			catch(exception& ex)
			{
				cout<<endl<<"Exception Occured...Enter only digits"<<endl;
				return 0;
			}

			accum_mutex.lock();
			it->vcount1=it->vcount1+add;
			accum_mutex.unlock(); 
			cout<<endl<<"......Adding........"<<endl;
			sleep(2);
			cout<<endl<<endl<<"Vaccines added to the center"<<endl;
		}
		if(choice==2)	//if choice is riverdale
		{
			cout<<"\n\t\t-->>For Center 2<<--"<<endl; 
			cout<<endl<<"Vaccine in Center *"<<ad.centre2<<"* are: "<<it->vcount2<<endl; 
			cout<<"\n\tEnter Number of vaccines you want to add: "; 
			cin>>temp;	//takes input from user 
			try
			{
				add=stoi(temp);
			}
			catch(exception& ex)
			{
				cout<<endl<<"Exception Occured...Enter only digits"<<endl;
				return 0;
			}
			it->vcount2=it->vcount2+add;	//increase vaccine count 
			cout<<endl<<"......Adding........"<<endl;
			sleep(2);
			cout<<endl<<"Vaccines added to the center"<<endl;
		}
		if(choice==3)	//If centre is Central Perk
		{
			cout<<"\n\t\t-->>For Center 3<<--"<<endl; 
			cout<<endl<<"Vaccine in Center *"<<ad.centre3<<"* are: "<<it->vcount3<<endl; 
			cout<<"\n\tEnter Number of vaccines you want to add: "; 
			cin>>temp; //Accept input from user
			try
			{
				add=stoi(temp);
			}
			catch(exception& ex)
			{
				cout<<endl<<"Exception Occured...Enter only digits"<<endl;
				return 0;
			}
			it->vcount3=it->vcount3+add;	//increase vaccine count 
			cout<<endl<<"......Adding........"<<endl;
			sleep(2);
			cout<<endl<<"Vaccines added to the center"<<endl;
			system("read");
		}
	}
	system("clear");
	return 0;
}



int admin :: get_vaccine_stock()	// This function fetches the available vaccines in all 3 centres
{
	cout<<centre1<<"\t\t\t"<<vcount1<<endl;
	cout<<centre2<<"\t\t"<<vcount2<<endl;
	cout<<centre3<<"\t\t"<<vcount3<<endl;
	return EXIT_SUCCESS;
}


int admin :: display_vaccine_stock()	// This function displays the available vaccines in all the location
{
	if(l2.empty())	//checks if list is empty
	{
		cout<<"Empty File "<<endl;
		return 0;
	}
	cout<<endl<<endl<<"_____________________________"<<endl<<endl;
	cout<<endl<<endl<<"Centre"<<"\t\t"<<"Vaccine Count"<<endl;
	for(list<admin>::iterator it=l2.begin();it!=l2.end();it++)
	{
		it->get_vaccine_stock();	//Function call to get_vaccinated_stock
	}
	cout<<endl<<"_____________________________"<<endl<<endl;
	system("read a");
	system("clear");
	return EXIT_SUCCESS;

}


int admin :: delete_fully_vaccinated()	// This function is used to remove the details of specified beneficiaries 
{
	int flag=0;
	if(l1.empty())	//Checks if list is empty
	{
		printf("\nEmpty Records\n");
		return 0;
	}
	string  m_aadhar_no;
	cout<<endl<<"Enter the Aadhar number whose record you want to delete:";
	cin>>m_aadhar_no;	//Take input from user
	for(list<user>::iterator it=l1.begin();it!=l1.end();it++)	//Traverse through list
	{	
		if(it->get_aadhar()==m_aadhar_no)
		{
			if(it->get_shots()==3)	//if beneficiary is fully vaccinated
			{

				it=l1.erase(it);	//delete the record
				flag=1;
				break;
			}
			else
			{
				cout<<"This beneficiary has not completed his all doses."<<endl<<"----You cannot delete this record.----"<<endl;
				return 0;
			}
		}
	}
	if(flag==1)
	{
		cout<<"The record of aadhar number deleted succesfully"<<endl;
	}
	else
	{
		cout<<endl<<"Beneficiary with aadhar number "<<m_aadhar_no<<" does not exit"<<endl;
	}
	system("read a");
	return EXIT_SUCCESS;
}


int admin :: non_vaccinated()	// This function is used to show not vaccinated beneficiaries
{
	if(l1.empty())
	{
		cout<<endl<<"Empty Records"<<endl;
		return 0;
	}
	cout<<endl<<"Aadhar\tName\tAge\tGender\tCentre\t\tTime slot\tShots"<<endl<<endl;
	int flag=0;
	list<user> :: iterator it;
	for(it=l1.begin();it!=l1.end();it++)	//Traverse through list
	{
		if(it->get_shots()==0)	//checks if number of shots are zero
		{
			it->view_registered_user(); //calls function to display details of beneficiary
			flag=1;	
		}
	}
	if(flag==0)
	{
		cout<<endl<<"No Records found"<<endl;
	}
	system("read a");
	system("clear");
	return EXIT_SUCCESS;
}


int admin :: fully_vaccinated()	// This function shows fully vaccinated beneficiaries
{
	if(l1.empty())	//checks if list is empty
	{
		cout<<endl<<"Empty Records"<<endl;
		return 0;
	}
	cout<<endl<<"Aadhar\tName\tAge\tGender\tCentre\t\tTime slot\tShots"<<endl<<endl;
	int flag=0;
	list<user> :: iterator it;
	for(it=l1.begin();it!=l1.end();it++)	//Traverse through list
	{
		if(it->get_shots()==3)
		{
			it->view_registered_user();	//calls function to display details of beneficiary
			flag=1;
		}
	}
	if(flag==0)
	{
		cout<<endl<<"No Records found"<<endl;
	}
	
	system("read a");
	system("clear");
	return EXIT_SUCCESS;
}


int admin :: today_vaccinated()	// This function displays beneficiaries who are vaccinated today
{
	if(l1.empty())
	{
		cout<<"Empty File "<<endl;
		return 0;
	}
	cout<<endl;
	cout<<endl<<"Aadhar\tName\tAge\tGender\tCentre\t\tTime slot\tShots"<<endl<<endl;
	int flag=0;
	list<user> :: iterator it;
	for(it=l1.begin();it!=l1.end();it++)	//Traverse through list
	{
		if(it->get_shots()>0)
		{
			it->view_registered_user();	//calls function to display details of beneficiary
			flag=1;
		}
		
	}
	if(flag==0)
	{
		cout<<endl<<"No Records found"<<endl;
	}
	
	system("read a");
	system("clear");
	return EXIT_SUCCESS;
}

#endif
