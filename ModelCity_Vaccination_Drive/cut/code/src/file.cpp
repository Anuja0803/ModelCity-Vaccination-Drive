/**********************************************************************************
  *  FILENAME     : file.c
  *  
  *  DESCRIPTION : The file.cpp contains all list to file and file to list
  *                  function and perform all designated tasks.
  *
  *  REVISION HISTORY
  *
  *  DATE             NAME          REASON
  *
  * -----------------------------------------------------
  *
  *  22/09/22         Group-5       Perform Operations
  *
  * ********************************************************************************/
#include "header.hpp" // Required header file
using namespace std;

int user :: reg_list_to_file()	//For registering records in registered file from list	
{
	fl.open("Registered_file",ios::out);	//opening the file in binary mode
	for (list<user> :: iterator t = l1.begin();t!=l1.end();t++)
	{
		strcpy(us.aadhar_no,t->aadhar_no);
		strcpy(us.name,t->name);
		strcpy(us.gender,t->gender);
		us.age=t->age;
		us.shots=t->shots;
		strcpy(us.centre,t->centre);
		us.token=t->token;
                us.time_s=t->time_s;
		strcpy(us.registration_id,t->registration_id);
		
		fl.write((char *) &us, sizeof(user1));	//Writing in file
	}
	fl.close();	//closing the file
	return 0;
}
int user :: reg_file_to_list()	//Inserting records from file to list
{
	user u2;
	fl2.open("Registered_file",ios::in);	//opening file in binary mode
	if(!fl2)
	{
		cout<<"File can't open"<<endl;
		return EXIT_FAILURE;
	}
	else
	{
		int temp = sizeof(user1);
		fl2.read((char *) &us, temp);	//reading from file
		while(!fl2.eof())
		{
			strcpy(u2.aadhar_no,us.aadhar_no);
			strcpy(u2.name,us.name);
			strcpy(u2.gender,us.gender);
			u2.age=us.age;
			u2.shots=us.shots;
			strcpy(u2.centre,us.centre);
			u2.token=us.token;
			u2.time_s=us.time_s;
			strcpy(u2.registration_id,us.registration_id);
			l1.push_back(u2);	//after reading data from file, inserting into list
			fl2.read((char *) &us, temp);	//reading from file
		}
		fl2.close();	//closing the file
	}
	return EXIT_SUCCESS;
}
int admin :: vaccine_list_to_file()	//For inserting records in Vaccine file
{
	fl.open("Vaccine_file",ios::out);	//open file in binary mode
	for (list<admin> :: iterator t = l2.begin();t!=l2.end();t++)
	{
		strcpy(as.centre1,t->centre1);
		strcpy(as.centre2,t->centre2);
		strcpy(as.centre3,t->centre3);
		as.vcount1=t->vcount1;
		as.vcount2=t->vcount2;
		as.vcount3=t->vcount3;
		fl.write((char *) &t, sizeof(as));	//Writing in file
	}
	fl.close();	//closing the file
	return 0;
}
int admin :: vaccine_file_to_list()	//Inserting records from file to list
{
	//admin ad;	
	fl2.open("Vaccine_file",ios::in);	//opening file in binary mode
	if(!fl2)
	{
		cout<<"File can't open"<<endl;
		return EXIT_FAILURE;
	}
	else
	{
		int temp = sizeof(ad);
		fl2.read((char *) &ad, temp);	//reading from file
		while(!fl2.eof())
		{
			strcpy(ad.centre1,as.centre1);
			strcpy(ad.centre2,as.centre2);
			strcpy(ad.centre3,as.centre3);
			ad.vcount1=as.vcount1;
			ad.vcount2=as.vcount2;
			ad.vcount3=as.vcount3;
			l2.push_back(ad);	//after reading data from file, inserting into the list
			fl2.read((char *) &as, temp);	//reading from the file
		}
		fl2.close();	//closing the file
	}
	return EXIT_SUCCESS;
}
