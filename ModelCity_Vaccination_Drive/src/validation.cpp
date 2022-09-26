#include <iostream>  //Required headerfiles
#include <iomanip>  
using namespace std;
bool aadhar_len(char *a) //Aadhar Number Validation
{
	int len =strlen(a);
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

bool age_validation(char *age)  //Validation for checking restricted age.
{
	int y;
	for(int i=0;i<strlen(age);i++)
	{
		if(!isdigit(age[i]))
		{
			y=1;
			break;
		}
	}
	if(y==1)
	{
		cout<<"Age should be numeric"<<endl;
	}
        if(atoi(age) >= 18 && atoi(age) <= 100) //Allowed age should be greater than 18 and less than 100 
        {
                if (atoi(age) >=35 ) //Checking for medical clearance for age above 35
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
bool name_validation(char *n) //Checking for valid name 
{	
	 int len2 = strlen(n);
	 int space=0;
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
			 if(isblank(n[i]))
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
bool gender_validation(char *g) //Validation for valid gender entry
{
	if(isblank(g[0])) //Checking for blank user entry
	{
		cout<<endl<<"Gender cannot be blank"<<endl;
		return false;
	}
	if(strcmp(g,"M")==0 || strcmp(g,"F")==0 || strcmp(g,"O")==0) //Gender should be among these three choices only.
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

