#include <iostream>
#include <string>
#include <fstream>

using namespace std;

void menu();
void manage_doctor_details();
void manage_appointment_details();
void view_doctor_details();
void update_doctor_existing_details();
void view_appointment_details();
void view_company_details();
void login();
void logout();


int main()
{
    m:
    system("cls");
    int choice;

    cout <<"\n\n";
    cout <<"\t\t      Spire Health Care Hospital \n";
    cout <<"\t\t  ===================================\n";
    cout <<"\n\n 1- User Login ";
    cout <<"\n\n 2- View Company Details";
    cout <<"\n\n 3- Exit ";
    cout <<"\n\n\n Enter your choice : ";
    cin >>choice;


    switch(choice)
    {
    case 1:
        login();

    case 2:
        view_company_details();

    case 3:
        exit(0);

    default:
        cout <<"\n\n\t\t\t Wrong Choice \n\n\n";
        system("pause");
    }
    goto m;

}

void login()
{
    m:
    system("cls");

    cout <<"\n\n";
    cout <<"\t\t      Spire Health Care Hospital \n";
    cout <<"\t\t  ===================================\n";
    cout <<"\n\n";
    cout <<"\t      Please Login \n";
    cout <<"\t ------------------------\n\n";

    string user;
    cout <<" User Name : ";
    cin >>user;
    string password;
    cout <<"\n Password : ";
    cin >>password;




            if((user == "icbt" || user=="ICBT") && password=="1234")
        {
            menu();
        }
        else if((user == "icbt" || user=="ICBT") && password!="1234")
        {
            cout <<"\n\n\t\t Password is Wrong \n\n\n";
            system("pause");
            main();
        }
        else if((user != "icbt" || user!="ICBT") && password=="1234")
        {
            cout <<"\n\n\t\t User Name is Wrong \n\n\n";
            system("pause");
            main();
        }
        else
        {
            cout <<"\n\n\t\t User Name And password is Wrong \n\n\n";
            system("pause");
            main();
        }


    
    goto m;

}

void view_company_details()
{
    system("cls");

    cout <<"\n\n";
    cout <<"\t\t      Spire Health Care Hospital \n";
    cout <<"\t\t  ===================================\n";
    cout <<"\n\n";
    cout <<"    Company Details   \n";
    cout <<" --------------------\n\n\n";

    cout<<"  - Company Details -";

    cout<<"\n\nSpire Health Care Hospital (PVT) LTD\n";
    cout<<"\n\nContact Number:- 081 223 344 55\n";
    cout<<"\n\n24/7 Service\n";
    cout<<"\n\nLocation:- Kandy and Colombo\n";
    
    cout<<"n\n\n";
    system("pause");
    main();
}

void menu()
{
    m:
    system("cls");

    cout <<"\n\n";
    cout <<"\t\t      Spire Health Care Hospital \n";
    cout <<"\t\t  ===================================\n";
    cout <<"\n\n 1- Manage Doctor Details";
    cout <<"\n\n 2- Manage Appointment Details";
    cout <<"\n\n 3- View Doctor Details";
    cout <<"\n\n 4- View Appointment Details";
    cout <<"\n\n 5- Update Doctor Existing Details";
    cout <<"\n\n 6- Logout";
    int choice;
    cout <<"\n\n\n\t Enter Your Choice : ";
    cin >>choice;

    switch(choice)
    {
    case 1:
        manage_doctor_details();

    case 2:
        manage_appointment_details();

    case 3:
        view_doctor_details();

    case 4:
        view_appointment_details();

    case 5:
        update_doctor_existing_details();

    case 6:
        logout();

    default:
        cout <<"\n\n\t\t\t Wrong Choice \n\n\n";
    }

    system("pause");
    goto m;

}

void manage_doctor_details()
{
    system("cls");
    fstream file;
    string id,name,spec;
    string id1,name1,spec1;
    int token=0;

    cout <<"\n\n";
    cout <<"\t\t      Spire Health Care Hospital \n";
    cout <<"\t\t  ===================================\n";
    cout <<"\n\n";
    cout <<"    Add Doctor Details   \n";
    cout <<" ------------------------\n\n";

    cout <<"\n Enter Doctor ID : ";
    cin >>id;

    cout <<"\n\n Enter Doctor Name : ";
    cin >>name;

    cout <<"\n\n Enter Doctor Speciality : ";
    cin >>spec;



    file.open("DoctorData.txt",ios::in);

    if(!file)
    {
        file.open("DoctorData.txt",ios::app|ios::out);
        file <<" "<<id<<"\t\t"<<name<<"\t\t"<<spec<<"\n";
        file.close();
    }
    else
    {
        file>>id1>>name1>>spec1;
        while(!file.eof())
        {
            if(id1==id)
            {
                token++;
            }
            file>>id1>>name1>>spec1;
        }
        file.close();


        if(token==1)
        {
            cout<<"\n\n\t\t\t >> This ID allrady inserted << \n\n\n\n\n";
            system("pause");
            menu();
        }
        else
        {
            file.open("DoctorData.txt",ios::app|ios::out);
            file <<" "<<id<<"\t\t"<<name<<"\t\t"<<spec<<"\n";
            file.close();
        }
    }
    cout <<"\n\t\t\t       Record inserter ";
    cout <<"\n\n\n";
    system("pause");
    menu();

}


void manage_appointment_details()
{
    system("cls");
    fstream file;
    string pID,pName,dName,date,time;
    string pID1,pName1,dName1,date1,time1;
    int token=0;

    cout <<"\n\n";
    cout <<"\t\t      Spire Health Care Hospital \n";
    cout <<"\t\t  ===================================\n";
    cout <<"\n\n";
    cout <<"   Add Appointment Details   \n";
    cout <<" ---------------------------\n\n";

    cout <<"\n Enter Patient ID : ";
    cin>>pID;

    cout <<"\n\n Enter Patient Name : ";
    cin>>pName;

    cout <<"\n\n Enter Doctor Name : ";
    cin>>dName;

    cout <<"\n\n Enter Visiting Date : ";
    cin>>date;

    cout <<"\n\n Enter Visiting Time : ";
    cin>>time;


    file.open("AppointmentData.txt",ios::in);

    if(!file)
    {
        file.open("AppointmentData.txt",ios::app|ios::out);
        file <<" "<<pID<<"\t\t"<<pName<<"\t\t"<<dName<<"\t\t"<<date<<"\t\t"<<time<<"\n";
        file.close();
    }
    else
    {
        file>>pID1>>pName1>>dName1>>date1>>time1;
        while(!file.eof())
        {
            if(pID1==pID)
            {
                token++;
            }
            file>>pID1>>pName1>>dName1>>date1>>time1;
        }
        file.close();


        if(token==1)
        {
            cout<<"\n\n\t\t\t >> This Appointment Already Inserted << \n\n\n\n\n";
            system("pause");
            menu();
        }
        else
        {
            file.open("AppointmentData.txt",ios::app|ios::out);
            file <<" "<<pID<<"\t\t"<<pName<<"\t\t"<<dName<<"\t\t"<<date<<"\t\t"<<time<<"\n";
            file.close();
        }
    }
    cout <<"\n\t Record inserter ";
    cout <<"\n\n\n";
    system("pause");
    menu();

}

void view_doctor_details()
{
    system("cls");
    fstream file;
    string code,name,price;

    cout <<"\n\n";
    cout <<"\t\t      Spire Health Care Hospital \n";
    cout <<"\t\t  ===================================\n";
    cout <<"\n\n";
    cout <<"    Doctor Details   \n";
    cout <<" --------------------\n\n";

    file.open("DoctorData.txt",ios::in);

    if(!file)
    {
        cout <<"\n\n File Does Not Exist \n\n\n\n\n";
    }
    else
    {
        cout <<" "<<"D-ID"<<"\t\t"<<"D-NAME"<<"\t\t"<<"D-SPECIALIY"<<"\n\n";

        while(!file.eof())
        {
            cout <<"  "<<code<<"\t\t  "<<name<<"\t\t   "<<price<<"\n";
            file>>code>>name>>price;
        }
    }
    file.close();
    cout<<"\n\n\n\n";
    system("pause");
    menu();
}

void update_doctor_existing_details()
{

    system("cls");
    int coun=0;
    fstream file,file1;
    string di,id,name,spec;
    string id1,name1,spec1;



    cout <<"\n\n";
    cout <<"\t\t      Spire Health Care Hospital \n";
    cout <<"\t\t  ===================================\n";
    cout <<"\n\n";
    cout <<"    Doctor Existing Details  \n";
    cout <<" -----------------------------\n\n";

    file.open("DoctorData.txt",ios::in);

    if(!file)
    {
        cout <<"\n\n File Does Not Exist \n\n\n\n\n";
    }
    else
    {
        cout <<"\n Enter Doctor Update ID : ";
        cin >>di;

        file1.open("DoctorData1.txt",ios::app|ios::out);
        file>>id>>name>>spec;

        while(!file.eof())
        {
            if(di==id)
            {
                cout <<"\n\n New Product  \n";

                cout <<"\n Enter Doctor ID : ";
                cin >>id1;

                cout <<"\n\n Enter Doctor Name : ";
                cin >>name1;

                cout <<"\n\n Enter Doctor Speciality : ";
                cin >>spec1;

                file1<<" "<<id1<<"\t"<<name1<<"\t"<<spec1<<"\n";
                cout <<"\n\n\t\t\t\t Recode Updating \n\n\n";
                coun++;
            }
            else
            {
                file1<<" "<<id<<"\t"<<name<<"\t"<<spec<<"\n";
            }
            file>>id>>name>>spec;

        }
        file.close();
        file1.close();

        remove("DoctorData.txt");
        rename("DoctorData1.txt","DoctorData.txt");


        if(coun==0)
        {
            cout <<"\n\n\t\t\t   Record Not Found \n\n\n\n\n";
        }

    }

    system("pause");
    menu();

}

void view_appointment_details()
{
    system("cls");
    fstream file;
    string pID,pName,dName,date,time;

    cout <<"\n\n";
    cout <<"\t\t      Spire Health Care Hospital \n";
    cout <<"\t\t  ===================================\n";
    cout <<"\n\n";
    cout <<"   Appointment Details   \n";
    cout <<" ------------------------\n\n";

    file.open("AppointmentData.txt",ios::in);

    if(!file)
    {
        cout <<"\n File Does Not Exist \n\n\n\n\n";
    }
    else
    {
        cout <<" "<<"P-ID"<<"\t\t"<<"P-NAME"<<"\t\t"<<"D-NAME"<<"\t\t"<<"VISITING DATE"<<"\t\t"<<"VISITING TIME"<<"\n";

        while(!file.eof())
        {
            cout <<" "<<pID<<"\t\t"<<pName<<"\t\t"<<dName<<"\t\t"<<date<<"\t\t\t"<<time<<"\n";
            file>>pID>>pName>>dName>>date>>time;
        }
    }
    file.close();
    cout<<"\n\n\n\n";
    system("pause");
    menu();
}

void logout()
{
    main();
}


