/*

Lab Assignment 12

Department maintains a student information. 
The file contains roll number, name, division and address.
Allow user to add, delete information of student. 
Display information of particular employee. 
If record of student does not exist an appropriate message is displayed. 
If it is, then the system displays the student details. Use sequential file to main the data.

*/

#include<iostream>
#include<fstream>
#include<cstring>
using namespace std;
class Student
{
    public:
        int rollNo,roll1;
        char name[10];
        char div;
        char address[20];

        void accept()
        {
            cout<<"--------------------------------";
            cout<<"\nEnter Roll Number :: ";
            cin>>rollNo;
            cout<<"Enter the Name :: ";
            cin>>name;
            cout<<"Enter the Division :: ";
            cin>>div;
            cout<<"Enter the Address :: ";
            cin>>address;
        }

        int getRollNo()
        {
         return rollNo;
        }

        void show()
        {
            cout<<"\n\t"<<rollNo<<"\t\t"<<name<<"\t\t"<<div<<"\t\t"<<address;
        }

        void show1()
        {
            cout<<"\nRoll no :: "<<rollNo
                <<"\nName :: "<<name
                <<"\nDivision :: "<<div
                <<"\nAddress :: "<<address;
        }
};

int main()
{
    int ch,rec,count,y,loop=1;
    char c,name[20];
    Student s;
    count=0;
    fstream g,f;
    while(loop==1)
    {
        cout<<"\n\n------------MENU---------------";
        cout<<"\n1.Insert new record"
            <<"\n2.Display all records"
            <<"\n3.Search by number"
            <<"\n4.Search by name"
            <<"\n5.Delete a Student Record"
            <<"\n6.Exit"
            <<"\nEnter the Choice :: ";
        cin>>ch;
        switch(ch)
        {
            
            case 1:
            cout<<"\nDo you want to append it to previous data? (y/n) \nEnter :: ";
            cin>>c;
            if(c=='y'||c=='Y')
                f.open("StuRecord.txt",ios::app);
            else
                f.open("StuRecord.txt",ios::out);
            x:s.accept();
            f.write((char*) &s,(sizeof(s)));
            cout<<"\nDo you want to enter more records?(y/n)\nEnter :: ";
            cin>>c;
                if(c=='y' || c=='Y')
                    goto x;
                else
                {
                    f.close();
                    break;
                }
        //----------------------------------------------------------------
            
            case 2:
            f.open("StuRecord.txt",ios::in);
            f.read((char*) &s,(sizeof(s)));
            cout<<"\n\tRoll No.\tName\t\tDivision\tAddress";
            cout<<"\n----------------------------------------------------------------------";
            while(f)
            {
                s.show();
                f.read((char*) &s,(sizeof(s)));
            }
            f.close();
            break;
        //-----------------------------------------------------------------

            case 3:
            count=0;
                cout<<"\nEnter the roll number you want to find :: ";
                cin>>rec;
                f.open("StuRecord.txt",ios::in|ios::out);
                f.read((char*)&s,(sizeof(s)));
                while(f)
                {
                    if(rec==s.rollNo)
                    {
                        cout<<"\nRecord found";
                        cout<<"\n-------------------------";
                        s.show1();
                        f.close();
                        count=1;
                        break;
                    }
                    f.read((char*)&s,(sizeof(s)));
                }
                if(count==0)
                    cout<<"\nRecord not found";
                f.close();
            break;
        //---------------------------------------------------------------------
            
            case 4:
                count=0;
                cout<<"\nEnter the name you want to find ::";
                cin>>name;
                f.open("StuRecord.txt",ios::in|ios::out);
                f.read((char*)&s,(sizeof(s)));
                while(f)
                {
                    y=(strcmp(name,s.name));
                    if(y==0)
                    {
                        cout<<"\nRecord found";
                        cout<<"\n-------------------------";
                        count=1;
                        s.show1();
                        break;
                    }
                    f.read((char*)&s,(sizeof(s)));
                }
                if(count==0)
                    cout<<"\nRecord not found";
                f.close();
            break;
        //--------------------------------------------------------------------
                    
            case 5:
                count=1;
                int roll;
                cout<<"Please Enter the Roll No. of Student whose information you want to delete :: ";
                cin>>roll;
                f.open("StuRecord.txt",ios::in);
                g.open("temp.txt",ios::out);
                f.read((char *)&s,sizeof(s));
                    while(!f.eof())
                    {
                        if (s.getRollNo() != roll)
                            g.write((char *)&s,sizeof(s));
                            f.read((char *)&s,sizeof(s));
                        if(s.getRollNo()==roll)
                            count=0;
                    
                    }
                if(count==0){
                    cout << "\nThe record with the roll no. " << roll << " has been deleted " << endl;
                }
                else{
                    cout << "\nRecord not found" << endl;
                }
                g.close();
                f.close();
                remove("StuRecord.txt");
                rename("temp.txt","StuRecord.txt");
            break;
        //-------------------------------------------------------------------
            
            case 6:
                loop=0;
                cout<<"Thank you!!";
            break;
        }
    }
}
