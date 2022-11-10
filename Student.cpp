#include<iostream>
#include<fstream>
#include<stdlib.h>
using namespace std;
class student {
	int rollno;
	char name[50];
	int marks;
	char grade;
public:
    void set_student(){
    	cout<<"enter roll number: ";
    	cin>>rollno;
    	cout<<"Student name: ";
    	cin>>name;
    	cout<<"Enter marks: ";
    	cin>>marks;
    	cout<<"Enter grade: ";
    	cin>>grade;	
    }	
    void get_student(){
    	cout<<"Roll no.: "<<rollno<<endl;
    	cout<<"Name: "<<name<<endl;
    	cout<<"Marks: "<<marks<<endl;
    	cout<<"grade: "<<grade<<endl;
    	
    }
    int get_rollnumber(){
    	return rollno;
    }

};
int main(){
  student s;
  int roll;
  fstream f1;
  char fname[] ="student";
  int ch;
  int find;
  while(1){
  
    cout<<"===========Menu============="<<endl;
    cout<<"1. Add Student"<<endl<<"2. Display Student"<<"3. Delete 	Student"<<endl<<"4. Update Student"<<endl<<"5. Exit"<<endl<<"Enter choice: ";
    cin>>ch;
    switch(ch){
      case 1: 
               f1.open(fname, ios::app|ios::binary|ios::ate);
               if (f1.fail()){
                 cout<<"\nnew file is creating...."<<endl;
                 f1.open(fname,ios::out|ios::binary);
               }
               s.set_student();
               f1.write((char*)&s, sizeof(s));
               f1.close();
               break;
      case 2:  cout<<endl<<"Enter roll number to find: ";
      	       cin>> roll;
      	       f1.open(fname,ios::in|ios::binary);
      	       find=0;
      	       while(!find){
      	         if(f1.eof()){
      	          cout<<"\nRecord not found";
      	          find=1;
      	          break;
      	         }
      	         f1.read((char*) &s, sizeof(s));
      	         if(roll == s.get_rollnumber()){
      	           s.get_student();
      	           find=1;
      	           break;
      	         }
      	       }
      	       f1.close();
      	       break;
      case 5: exit(0);
      default: cout<<"\nChoice not found";
      	                
    
    }
  }
  return 0;
}