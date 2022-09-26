#include <iostream>  //Required headerfiles
#include <iomanip>  
using namespace std;
bool aadhar_len(string a) //Aadhar Number Validation
{
	int len =a.length();
	if(isblank(a[0])) //Checking for blank entry
	{
		cout<<endl<<"Aadhar number cannot be blank"<<endl;
		return false;
	}
	if(len==6) //Length Validation
        {
                int c = 0;
                for(int i=0;i<len;++i)
                {
                        if(!isdigit(a[i])) //Checking for entry is digit only.
                        {
                                c++;
                                break;
                        }
                }
                if(c>0)
                {
                        cout<<"Invalid entry"<<endl<<"Aadhar Number should contain only digits"<<endl;
                        return false;
                }
                return true;
        }
        else
        {
                cout<<"Invalid Length"<<endl;
                return false;
        }
	return EXIT_SUCCESS;
}

bool age_validation(string age)  //Validation for checking restricted age.
{
	int y;
        if(stoi(age) >= 18 && stoi(age) <= 100) //Allowed age should be greater than 18 and less than 100 
        {
                if (stoi(age) >=35 ) //Checking for medical clearance for age above 35
                {
                        cout<<"Clearance from Doctor: "<<endl;
                        cout<<"1.For yes,enter 1"<<endl<<"2.For no,enter 0"<<endl;
                        cin>>y;
                        if(y == 0)
                        {
                                cout<<"Doctor Clearance needed.Registration not completed."<<endl;
                                return 0;
                        }
                }
                return true;
        }
        else
        {
                cout<<"Vaccination allowed only for age between 18 to 100 only. Registration not completed"<<endl;
                return false;
        }	
	return EXIT_SUCCESS;
}
bool name_validation(string n) //Checking for valid name 
{	
	 int len2 = n.length();
	 int space=0;
	 if(isblank(n[0]) || isspace(n[0])) //Space  entry validation
	 {
		 cout<<endl<<"Name cannot contain space"<<endl;
		 return false;
	 }
	 if(len2<0)  //Blank entry validation
	 {
		 cout<<endl<<"Name cannot be blank"<<endl;
		 return false;
	 }
	 if(len2 < 5 && len2 >= 15 )   //Valid name should have length greater than 5 and less than 15
	 {
		 cout<<endl<<"Invalid Length"<<endl;
		 return false;
	 }
	 else
	 {
		 int c = 0;
		 for(int i=0;i<len2;++i)
		 {
			 if(!isalpha(n[i])) //Name should contain only alphabets
			 {
				 c++;
				 break;
			 }
		 }
		 if(c>0)
		 {
			 cout<<"Invalid Name"<<endl<<"Name should contain only alphabets"<<endl;
			 return false;
		 }
		 return true;
	 }
	 return EXIT_SUCCESS;
}
bool gender_validation(string g) //Validation for valid gender entry
{
	if(isblank(g[0])) //Checking for blank user entry
	{
		cout<<endl<<"Gender cannot be blank"<<endl;
		return false;
	}
	if(g =="M" || g=="F" || g=="O") //Gender should be among these three choices only.
	{
		return true;
	}

	else
	{
		cout<<"Invalid gender"<<endl;
		return false;
	}
	return EXIT_SUCCESS;
}

