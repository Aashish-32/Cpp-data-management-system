#include<iostream>
#include<fstream>
#include<iomanip>
#include<string>
using namespace std;


class student{
	private:
int	roll_no;
char name[30];
double avg;
char grade;
int cs, math, english, science, nepali;
public:
	void getdata();
	void showdata();
	void calculate();
	int return_roll();
	
};
	void student::calculate() {
		avg=(cs+math+english+science+nepali)/5;
		if(avg>=90)
		grade='A';
	    else if(avg>=70)
	    grade='B';
	    else if(avg>=50)
	    grade='C';
	    else
	    grade='F';
	}
	int student::return_roll()
	{ return roll_no;
	}
	    
	    void student::getdata(){
	    	cout<<"\nEnter student's roll number: ";
	    	cin>>roll_no;
	    	cin.ignore();
	    	cout<<"\n Enter student's name: ";
	    	cin.getline(name,50);
	    	cout<<"\nEnter marks in Computer Science: ";
	    	cin>>cs;
	    	cout<<"\nEnter marks in Science: ";
	    	cin>>science;
	    	cout<<"\nEnter marks in Math: ";
	    	cin>>math;
	    	cout<<"\nEnter marks in English: ";
	    	cin>>english;
	    	cout<<"\nEnter marks in Nepali: ";
	    	cin>>nepali;
	    }
	    	
	    	void student::showdata(){
	    		
	    		cout<<"\nRoll no: "<<roll_no;
	    		cout<<"\nName: "<<name;
	    			cout<<"\nMarks in Computer Science: "<<cs;
	    			cout<<"\nMarks in Math: "<<math;
	    			cout<<"\nMarks in Science: "<<science;
	    			cout<<"\nMarks in Nepali: "<<nepali;
	    			cout<<"\nMarks in English: "<<english;
	    			cout<<"\nThe average marks is: "<<avg;
	    			cout<<"\nGrade: "<<grade;
	    				
	    		
			}
	    	
	    	
	    	
	    	void create();
	    	void display_search(int);
	    	void display_all();
	    	void delete_(int);
	    	void modify(int);
	    	
	    	//Starting Main
	    	

int main(){
	int rl;
	int choice;

	do{
		system("cls");
		cout<<"\n\n\tMenu\n";
		cout<<"\n\n\t1.Create student record";
		
		cout<<"\n\n\n\t2.Search student record";
		cout<<"\n\n\n\t3.Display all student record";
		cout<<"\n\n\n\t4.Delete student record";
		cout<<"\n\n\n\t5.Modify student record";
		cout<<"\n\n\n\t6.EXIT";
		cout<<"\n\n\n\tEnter a function choice(1/2/3/4/5/6): ";
		cin>>choice;
		system("cls");
		
		switch(choice){
			case 1:create();
			break;
			
			
			 case 2:
			 		cout<<"\nEnter roll no: ";
			 		cin>>rl;
			 	display_search(rl);
			 	break;
			 	
			case 3:
				display_all();
				break;
				
				case 4:
					cout<<"Enter roll no you want to delete: ";
			        cin>>rl;
			        delete_(rl);
			        break;
			        
			    case 5:
			    	cout<<"Enter roll no you want to modify: ";
			        cin>>rl;
			        modify(rl);
			        break;
			        
			    case 6:
			    	cout<<"Thank you for using our service.Exiting....."; 
			    	exit(0);
			    	
}
			 	
			
		} while (choice!=6);
		return 0;
		
		
} //main closed

void create(){
	student s;
	fstream newfile;
	newfile.open("project.dat",ios::binary|ios::app);
	s.getdata();
	newfile.write(reinterpret_cast<char *> (&s),sizeof(student));
	newfile.close();
		
}


void display_all()
{

	student s;
	ifstream newwfile;
	newwfile.open("project.dat",ios::binary);
	if(!newwfile)	
{
	cout<<"file doesnt exist";
	cin.ignore();
	cin.get();
	return ;
	}
	
	cout<<"\n\nDisplaying data\n\n";
	while(newwfile.read(reinterpret_cast<char *> (&s), sizeof(student))) {
		s.showdata();
	}
	newwfile.close();
	cin.ignore();
     cin.get();
     
}
	
	void display_search(int n)
{
	student s;
	ifstream newwfile;
	newwfile.open("project.data",ios::binary);
	if(!newwfile){
		cout<<"\nfile does not exist";
	}
	cin.get();
	cin.ignore();
	return;
	bool flag=false;
	while(newwfile.read((char*) &s,sizeof(student)))
{
	if(s.return_roll()==n){
		s.showdata();
		flag=true;
	
	}
}
newwfile.close();
	
	if (flag==false)
	cout<<"\ndata does not exist";
		cin.get();
		cin.ignore();
	}	
	
	//modify record based on roll no..
	
	void modify(int a)
	{
		student s;
		bool found=false;
		fstream file;
		file.open("project.dat",ios::binary|ios::in|ios::out);
		if (!file)
		{
		cout<<"cannot open file";
		cin.ignore();
		cin.get();
		return;
			}
	
	while(!file.eof() && found==false){
		file.read((char*) &s, sizeof(student)); //since read expects char * so we cast it.
		if (s.return_roll()==a)
		{
			s.showdata();
			cout<<"Enter new information: ";
			s.getdata();
		
			int pos=(-1)*static_cast<int>(sizeof(s)); //  to turns the unsigned result of the sizeof operator into a signed number, and multiply it by -1
			
			file.seekp(pos,ios::cur); 
			file.write((char *) &s,sizeof(student)); //file.write(reinterpret_cast<char*> (&s),sizeof(student));
			cout<<"Record updated";
			found=true;
				
		}
		}
		file.close();
		if (found==false)
		cout<<"Record does not exist";
		cin.ignore();
		cin.get();
	}
		

	
	
	void delete_(int n){
		student s;
		ifstream newfile;
		newfile.open("project.dat",ios::binary);
		if(!newfile) {
		
		cout<<"File not found.. press any key to exit";
		cin.ignore();
        cin.get();
        return;
   }
	
	
	fstream file2;
	file2.open("data.dat",ios::out);
newfile.seekg(0,ios::beg);
	
	while(newfile.read(reinterpret_cast<char *> (&s),sizeof(student)))
	{
		if (s.return_roll()!=n)
		{
		
		
	     file2.write(reinterpret_cast<char *> (&s),sizeof(student));
		
}
}

file2.close();
	newfile.close();
	remove("project.dat");
rename("data.dat","project.dat");
cout<<"\n\n\tRecord Deleted ..";

cin.ignore();
cin.get();	
}
	
	
	

	
	
	











