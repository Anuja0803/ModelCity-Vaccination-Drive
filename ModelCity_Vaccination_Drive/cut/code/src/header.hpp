#ifndef H_HEADER
#define H_HEADER
#include <iostream>
#include <iomanip>
#include <list>
#include <fstream>
#include <cstdlib>
#include <string>
#include <cctype>
#include <vector>
#include <thread>
#include <mutex>


using namespace std;

class user
{
	protected:
	        char aadhar_no[30];
		char name[30];
		char gender[30];
		char centre[30];
		char registration_id[30];
		int time_s;
		int age;
		int shots;
		int token;
	public:
		// User Corner
		void new_user();
		void registered_user();
		int create_account();
		int view_details();
		int view_user();
		int view_registered_user();
		int select_centre();
		int book_slot();
		int register_details();
		int get_vaccinated();
		char *get_aadhar();
		char *get_centre();
		char *get_name();
		int get_age();
		int get_token();
		int get_shots();
		int get_time();
		int morning_slot(int);
		int afternoon_slot(int);

		user()
		{
			time_s=0;
			age=0;
			shots=0;
			token=0;
		        strcpy(centre,"NA");
		}
};
class admin : public user
{
	protected:
		char centre1[30];
		char centre2[30];
		char centre3[30];
		int vcount1;
		int vcount2;
		int vcount3;
	public:
		//Admin Corner
		int show_bene_data();
		int add_vaccine_stock();
		int display_vaccine_stock();
		int get_vaccine_stock();
		int delete_fully_vaccinated();
		int non_vaccinated();
		int fully_vaccinated();
		int today_vaccinated();
		friend class user;

		admin()
		{
			strcpy(centre1,"Hawkins");
			strcpy(centre2,"Riverdale");
			strcpy(centre3,"Central Perk");
			vcount1=10;
			vcount2=5;
			vcount3=15;
		}
};
void menu();
void user_login();
void admin_login();

int reg_list_to_file();
int reg_file_to_list();
int vaccine_list_to_file();
int vaccine_file_to_list();
user u1;
admin ad;
fstream fl;
fstream fl2;
list<user> l1;
list<user> lc;
list<admin> l2;
list<admin> lc2;
#endif
