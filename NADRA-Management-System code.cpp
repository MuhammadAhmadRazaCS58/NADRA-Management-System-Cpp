#include<iostream>
#include<cstdlib> // for genrating random numbers
#include<ctime>//used for genrating random time so that different cnic will be genrated
#include<fstream>// for storing record in file and then getting that so that all records are saved
#include <vector> //  using vectors for using dynamic memory allocation
using namespace std;
//make a structure so that all record and be save
struct Person {
    string name;
    int age;
    char gender;
    float height;
    string city;
    string bloodgroup;
    string fathername;
    string mothername;
    char cnic[17];  //1 extra for \0 null terminator  1 for getline as getline reads (size - 1)
    int issueDay, issueMonth, issueYear;
    int expiryDay, expiryMonth, expiryYear;
};
vector<Person> record;
string historyarr[5][2]; //  how 5 records in 2 column 1 for what he call and what he do 
int historycount=0; // so that if it exceeded 5 it will delete the old record and make new space;
void mainpage();//I write it at end but before main here i declare because i need if i want to move on main page if user want
//for getting only int
int getInt()
{
    int x;
    while (true)
    {
        cin >> x;
        if(cin.fail())   // check if input is not integer
        {
            cin.clear();  // clear error flag
            cin.ignore(1000, '\n'); // discard invalid input
            cout << "Invalid input! Enter an integer: ";
        }
        else
        {
            cin.ignore(1000, '\n'); // remove leftover input
            return x;
        }
    }
}

//for getting float


float getFloat()
{
    float x;
    while (true)
    {
        cin >> x;
        if(cin.fail())
        {
            cin.clear();
            cin.ignore(1000, '\n');
            cout << "Invalid input! Enter a number: ";
        }
        else
        {
            cin.ignore(1000, '\n');
            return x;
        }
    }
}
// for getting char

char getChar()
{
    char c;
    while (true)
    {
        cin >> c;
        if(!isalpha(c))   // only letters allowed
        {
            cin.clear();
            cin.ignore(1000, '\n');
            cout << "Invalid input! Enter a character: ";
        }
        else
        {
            cin.ignore(1000, '\n');
            return c;
        }
    }
}
// for user name or input will be greter than 5 digits
string getString()
{
    string username;
    while(true)
    {
        getline(cin, username);  // get full line input
        if(username.length() < 3)   // check minimum length
        {
            cout << "Invalid input! It must be at least 3 characters: ";
        }
        else
        {
            return username;   // valid input
        }
    }
}
string getblood()
{
    string username;
    while(true)
    {
        getline(cin, username);  // get full line input
        if(username != "A+" && username != "A-" && username != "B+" && username != "B-" &&  username != "AB+" && username != "AB-" && username != "O+" && username != "O-")   // check blood group
        {
            cout << "Invalid input! It must be  A+, A-, B+, B-, AB+, AB-, O+, or O- "<<endl;
        }
        else
        {
            return username;   // valid input
        }
    }
}
void printBigNADRA() {
    cout << R"(
  _   _    _    ____  ____    _      ____   ___  ____ _____  _    _     
 | \ | |  / \  |  _ \|  _ \  / \    |  _ \ / _ \|  _ \_   _|/ \  | |    
 |  \| | / _ \ | | | | |_) |/ _ \   | |_) | | | | |_) || | / _ \ | |    
 | |\  |/ ___ \| |_| |  _  / ___ \  |  __/| |_| |  _ < | |/ ___ \| |___ 
 |_| \_/_/   \_\____/|_| \_/_/   \_\ |_|   \___/|_| \_\|_/_/   \_\_____|
                                                                        
       NATIONAL DATABASE & REGISTRATION AUTHORITY - PAKISTAN
)" << endl<<endl;
}
void printAdminPortal() {
    cout << R"(
     _    ____  __  __ ___ _   _     ____   ___  ____ _____  _    _     
    / \  |  _ \|  \/  |_ _| \ | |   |  _ \ / _ \|  _ \_   _|/ \  | |    
   / _ \ | | | | |\/| || ||  \| |   | |_) | | | | |_) || | / _ \ | |    
  / ___ \| |_| | |  | || || |\  |   |  __/| |_| |  _ < | |/ ___ \| |___ 
 /_/   \_\____/|_|  |_|___|_| \_|   |_|    \___/|_| \_\|_/_/   \_\_____|
                                                                        
)" << endl<<endl;
}
void printOperatorPortal() {
    cout << R"(
   ___  ____  _____ ____      _  _____ ___  ____  
  / _ \|  _ \| ____|  _ \    / \|_   _/ _ \|  _ \ 
 | | | | |_) |  _| | |_) |  / _ \ | || | | | |_) |
 | |_| |  __/| |___|  _ <  / ___ \| || |_| |  _ < 
  \___/|_|   |_____|_| \_\/_/   \_\_| \___/|_| \_\
                                                  
       STAFF ACCESS - DATA ENTRY & VERIFICATION
)" << endl<<endl<<endl;
}
void printCitizenPortal() {
    cout << R"(
   ____ ___ _____ ___ _____ _____ _   _     ____   ___  ____ _____  _    _     
  / ___|_ _|_   _|_ _|__  /| ____| \ | |   |  _ \ / _ \|  _ \_   _|/ \  | |    
 | |    | |  | |  | |  / / |  _| |  \| |   | |_) | | | | |_) || | / _ \ | |    
 | |___ | |  | |  | | / /_ | |___| |\  |   |  __/| |_| |  _ < | |/ ___ \| |___ 
  \____|___| |_| |___/____||_____|_| \_|   |_|    \___/|_| \_\|_/_/   \_\_____|
                                                                               
)" << endl<<endl;
}
void printSaved() {
    cout << R"(
  __________________________________________________________
 |  ______________________________________________________  |
 | |                                                      | |
 | |    ____     _    __     _______ ____                 | |
 | |   / ___|   / \   \ \   / / ____|  _ \                | |
 | |   \___ \  / _ \   \ \ / /|  _| | | | |               | |
 | |    ___) |/ ___ \   \ V / | |___| |_| |               | |
 | |   |____//_/   \_\   \_/  |_____|____/                | |
 | |                                                      | |
 | |                DATA STORED SUCCESSFULLY              | |
 | |______________________________________________________| |
 |__________________________________________________________|
    )" << endl<<endl;
}
void printLoad() {
    cout << R"(
      __________
     /         /|
    /  LOAD   / |    ____  _____ ____  _____  _    ____  
   /  FILE   /  |   |  _ \| ____/ ___|| ____|/ \  |  _ \ 
  /_________/   |   | |_) |  _| \___ \|  _| / _ \ | | | |
  |         |   |   |  _ <| |___ ___) | |__/ ___ \| |_| |
  |  NADRA  |  /    |_| \_\_____|____/|_____/_/   \_\____/ 
  |_________| /     
                    
    )" << endl<<endl;
}

void printupdated() {
    cout << R"(
      _   _ ____  ____    _    _____ _____ ____  
     | | | |  _ \|  _ \  / \  |_   _| ____|  _ \ 
     | | | | |_) | | | |/ _ \   | | |  _| | | | |
     | |_| |  __/| |_| / ___ \  | | | |___| |_| |
      \___/|_|   |____/_/   \_\ |_| |_____|____/ 
                                                
    )" << endl<<endl;
}
void printSearching() {
    cout << R"(
      ________
     /        \
    /   SEARCH \      ____  _____    _    ____   ____ _   _ 
   |    RECORD  |    / ___|| ____|  / \  |  _ \ / ___| | | |
    \          /     \___ \|  _|   / _ \ | |_) | |   | |_| |
     \________/       ___) | |___ / ___ \|  _ <| |___|  _  |
          \\         |____/|_____/_/   \_\_| \_\\____|_| |_|
           \\
            \\       
    )" << endl<<endl;
}
void history(string type, string detail) {
    if (historycount < 5) {
        historyarr[historycount][0] = type;   // action Type
        historyarr[historycount][1] = detail; // action Detail
        historycount++;
    } else {
        // If fullso move everything up to make room for the newest action
        for (int i = 0; i < 4; i++) {
            historyarr[i][0] = historyarr[i+1][0];
            historyarr[i][1] = historyarr[i+1][1];
        }
        historyarr[4][0] = type;  // after making space add that history at last place
        historyarr[4][1] = detail;
    }
}

char gendercheck()
{
    char g;
    while (true)
    {
        cin >> g;
        if (g == 'M' || g == 'F')
        {
            return g;
        }
        else
        {
            cout << "Invalid input! Enter M for Male or F for Female: "<<endl;
        }
    }
}

void addrecord()
{
	
	 Person* p = new Person;   // calling person structure inside it with pointer
	    int age;
    float height;
    string name, city, bloodgroup, fathername, mothername;
    char gender;
 
        cout << "Enter the age: "<<endl;
        p->age=getInt();

	bool flag=true; // used so that user can give correct input only m or f not other 
    while(flag)
    {
    cout << "Enter the gender of person (M for male and F for female): "<<endl;
    p->gender=gendercheck(); 
    cin.ignore(1000,'\n');
    cout << "Enter the name of person: "<<endl;
    p->name=getString();  
    cout << "Enter the height: (must me in float  if its integer add .0 at last)"<<endl;
    p->height=getFloat();
    while (true) {
        
        if (p->height <= 0) {
            cout << "Invalid height! Please enter a positive number: "<<endl;
            continue;
        }
        break;
    }
   cout << "Enter the city: "<<endl;
    p->city=getString();
    cout << "Enter blood group: "<<endl;
    p->bloodgroup=getblood();
    cout << "Enter father's name: "<<endl;
    p->fathername=getString();

    cout << "Enter mother's name: "<<endl;
     p->mothername=getString();

    cout << "\nRecord added successfully!"<<endl;
  
// loop to keep trying until unique
    bool duplicate = true;
     while (duplicate) {
        // Generate a random CNIC
        p->cnic[0] = '3';
        for (int i = 1; i < 15; i++) {
        	if(i==5 || i==13)
        	{
        	p->cnic[i]='-';	
			}
			else{
            p->cnic[i] = (rand() % 10 + '0');
        }
        }
        p->cnic[16] = '\0';

        // check if this CNIC is already in your record 
        duplicate = false; // Assume it's unique first
        for (int i = 0; i < record.size(); i++) {
            if (string(p->cnic) == string(record[i].cnic)) {
                duplicate = true; // Oh no, it exists! 
                break;            // Stop checking and loop back to generate a new one
            }
        }
    } 

    //loop ends, we know cnic is unique
    cout << "Congratulations! Your unique CNIC is: " << p->cnic << endl<<endl;
time_t t = time(0);  // time_t is a data type
tm* now = localtime(&t);   // tm* now pointer to a structure tm which stores broken-down time (day, month, year, hour, minute, second).

// Issue date = today
p->issueDay = now->tm_mday;
p->issueMonth = now->tm_mon + 1;     // months start from 0
p->issueYear = now->tm_year + 1900;  // years since 1900

// Expiry = 10 years later
p->expiryDay = p->issueDay;
p->expiryMonth = p->issueMonth;
p->expiryYear = p->issueYear + 10;

cout << "CNIC Issued on: "
     << p->issueDay << "/" << p->issueMonth << "/" << p->issueYear << endl<<endl;

cout << "CNIC Expires on: "
     << p->expiryDay << "/" << p->expiryMonth << "/" << p->expiryYear << endl<<endl;

record.push_back(*p);  // save data 
delete p; // release memory 
    
    cout << "Record added successfully!" << endl<<endl;
    flag = false;

}
}
void deleterecord()
{
	string delc;
	cout<<"enter the cnic = "<<endl;
	bool found=false;
	delc=getString();
	for(int i=0;i<record.size();i++)
	{
		if(delc==record[i].cnic)//compare string delc wtih  all record count shows that how many record are there so it checks its one by one  and then
		{
			record.erase(record.begin() + i);  //remove record  from start increse +1

			 found=true ;
			 break;

		}
		
	}
	if(found==false) cout << "Record not found!" << endl<<endl;

}
void renewCNIC()
{
    string c;
    cout << "Enter CNIC to renew: "<<endl;
    c = getString();

    for (int i = 0; i < record.size(); i++)
    {
        if (c == record[i].cnic)
        {
            time_t t = time(0);
            tm* now = localtime(&t);

            // Renew from today
            record[i].issueDay = now->tm_mday;
            record[i].issueMonth = now->tm_mon + 1;
            record[i].issueYear = now->tm_year + 1900;

            record[i].expiryDay = record[i].issueDay;
            record[i].expiryMonth = record[i].issueMonth;
            record[i].expiryYear = record[i].issueYear + 10;

            cout << "CNIC Renewed Successfully!" << endl;
            cout << "New Expiry Date: "
                 << record[i].expiryDay << "/"
                 << record[i].expiryMonth << "/"
                 << record[i].expiryYear << endl;

            history("RENEW", "CNIC renewed");
            return;
        }
    }
    cout<<"\n";
    cout << "CNIC not found!" << endl<<endl;
}


bool isCNICExpired(Person &p)
{
    time_t t = time(0);
    tm* now = localtime(&t);

    int cDay = now->tm_mday;
    int cMonth = now->tm_mon + 1;
    int cYear = now->tm_year + 1900;
    if (cYear > p.expiryYear) return true;
    if (cYear == p.expiryYear && cMonth > p.expiryMonth) return true;
    if (cYear == p.expiryYear && cMonth == p.expiryMonth && cDay > p.expiryDay) return true;

    return false;
}

void checkrecord()
{
	string check;
	cout<<"enter the cnic = "<<endl;
	check=getString();
	bool found = false; 
	for(int i=0;i<record.size();i++)
	{
		if(check==record[i].cnic)
		{     
		      Person* ptr = &record[i];
			cout << "--- Record Found ---"<<endl;
            cout << "Name: " << ptr->name << endl;
            cout << "Age: " << ptr->age << endl;
            cout << "Gender: " << ptr->gender << endl;
            cout << "Height: " << ptr->height << endl;
            cout << "City: " <<   ptr->city << endl;
            cout << "Blood Group: " << ptr->bloodgroup << endl;
            cout << "Father's Name: " << ptr->fathername << endl;
            cout << "Mother's Name: " << ptr->mothername << endl;
            cout << "CNIC: " << ptr->cnic << endl;
            if (isCNICExpired(*ptr))
    cout << "CNIC Status: EXPIRED" << endl<<endl;
else
    cout << "CNIC Status: VALID" << endl<<endl;

            cout<<endl<<endl;
        found = true;
        break;
            
		}

}

if(!found) {
     cout<<"\n";
    cout << "Record not found!" << endl<<endl;
}

}


void editrecord()
{
	int newage;
	string edit;
	int num; // for storing what number user waht to edit like what record 
	int index;//so that we store i mean for which person the reocrd has been editing 
	cout<<"enter the cnic = "<<endl;
	edit=getString();
	bool found = false;  // checking if cnic matches or not
		for(int i=0;i<record.size();i++)
	
	{  // checking cnic if match then it will be able to edit record
		if(edit==record[i].cnic)
		{
			index=i;// so we further use it for checking what person is this
			cout<<"Match Founded"<<endl;
			cout<<"Enter following number for what you want to edit!"<<endl<<endl;
			cout<<"1.age\n 2.gender \n 3. height \n 4. city \n 5. bloodgroup \n 6. fathername \n 7.mothername"<<endl<<endl;
			num=getInt();
			
			found = true; // show that cnic matches so that it will not check further
			
			bool flag=true;//so that if user enter wrong number it may agian run
			while(flag)
			{
			switch(num)
			{
				case 1:
					cout<<"your current store age is "<<record[index].age<<endl<<endl;
					cout<<"Enter you new current age"<<endl<<endl;
					record[index].age=getInt(); // it overwrites the previous and write new
				    cout<<"Record Updated SuccessFully!"<<endl<<endl;
	                 flag=false;	                 
					break;
				case 2:
					cout<<"your current store gender is "<<record[index].gender<<endl<<endl;
					cout<<"Enter you new current gender "<<endl<<endl;
					record[index].gender=gendercheck(); // it overwrites the previous and write new
					cout<<"Record Updated SuccessFully!"<<endl<<endl;
					flag=false;
					break;
				case 3:
					cout<<"your current store height is "<<record[index].height<<endl<<endl;
					cout<<"Enter you new current height "<<endl<<endl;
					record[index].height=getFloat(); // it overwrites the previous and write new
				    cout<<"Record Updated SuccessFully!"<<endl<<endl;
				    flag=false;
					break;
				case 4:
					cout<<"your current store city is "<<record[index].city<<endl<<endl;
					cout<<"Enter you new current city"<<endl<<endl;
					record[index].city=getString(); // it overwrites the previous and write new
					cout<<"Record Updated SuccessFully!"<<endl<<endl;
					flag=false;
					break;
				case 5:			
							
					cout<<"your current store bloodgroup is "<<record[index].bloodgroup<<endl<<endl;
					cout<<"Enter you new current blood group"<<endl<<endl;
					record[index].bloodgroup=getblood(); // it overwrites the previous and write new
					cout<<"Record Updated SuccessFully!"<<endl<<endl;
					flag=false;
					break;
				case 6:
					cout<<"your current store father name  is "<<record[index].fathername<<endl<<endl;
					cout<<"Enter you new current father name is "<<endl<<endl;
					record[index].fathername=getString(); ; // it overwrites the previous and write new
				    cout<<"Record Updated SuccessFully!"<<endl<<endl;
				    flag=false;
					break;
				case 7:
					cout<<"your current store mother name  is "<<record[index].mothername<<endl<<endl;
					cout<<"Enter you new current mothername"<<endl<<endl;
					record[index].mothername=getString(); ; // it overwrites the previous and write new
					 printupdated();
					 cout<<"Record Updated SuccessFully!"<<endl<<endl;
					 flag=false;
					break;
					default:
					cout<<"Please enter correct number!!"<<endl;								
			}
		}
		
}

}

	if(!found)
    {
    	cout<<"\n";
        cout << "CNIC not found!" << endl<<endl;
    }

			
}





void showallrecord()
{
	
	//for this first make some reocrd then check it 
    if(record.empty())
    {
        cout << "No records found!" << endl;
        return;
    }

    cout << "All Stored Records are below: "<<endl;

    for(int i = 0; i < record.size(); i++)//count tells us that howmany reocrd has been stored
    {
    	Person* ptr = &record[i]; // Create a pointer pointing to the current record
        cout << "----- Record " << i+1 << " -----" << endl;// as i start from 0 so we use i+1
        cout << "Name: " << ptr->name << endl;
        cout << "Age: " << ptr->age << endl;
        cout << "Gender: " << ptr->gender << endl;
        cout << "Height: " << ptr->height << endl;
        cout << "City: " <<  ptr->city << endl;
        cout << "Blood Group: " << ptr->bloodgroup << endl;
        cout << "Father's Name: " << ptr->fathername << endl;
        cout << "Mother's Name: " << ptr->mothername << endl;
        cout << "CNIC: " << ptr->cnic << endl;
        cout << endl;
    }

}

void savetofile()
{
    ofstream file("nadra_records.txt");
	//ofstream is used for creating and writing  data in file and store
	//it opens the file also after creating
//file is object
    if(!file) //if file opening failed then show that
    {
        cout << "Error opening file!" << endl;
        return;
    }

    for(int i = 0; i < record.size(); i++)
    {
    	
    	//as we make file as object so here it writes date in file
    	//for writing data in file named object
        file << record[i].name << endl;
        file << record[i].age << endl;
        file << record[i].gender << endl;
        file << record[i].height << endl;
        file << record[i].city << endl;
        file << record[i].bloodgroup << endl;
        file << record[i].fathername << endl;
        file << record[i].mothername << endl;
        file << record[i].cnic << endl;
        file << record[i].issueDay << endl;
        file << record[i].issueMonth << endl;
        file << record[i].issueYear << endl;
        file << record[i].expiryDay << endl;
        file << record[i].expiryMonth << endl;
        file << record[i].expiryYear << endl;
    }

    file.close();//closing the file
    printSaved(); //big word print
    cout << "All records saved successfully!" << endl<<endl;
}

void loadfromfile() {
    ifstream file("nadra_records.txt");
    if(!file) return;
    record.clear();   //Delete everything already in memory, then load fresh data from file
    Person p;

    while(getline(file, p.name)) {     //because in  file format  the first line of every record is the name.
        if(file.fail()) break;
        // we write file.ignore() because we store data as  file << record[i].age << endl; so  file.ignore() it ignores new line <<Endl(\n) if we not write it as compiler ignore \n sense that it is empty it left all reocrd just read name
        file >> p.age; file.ignore();
        file >> p.gender; file.ignore();
        file >> p.height; file.ignore();
        //getline automatically removes \n from input buffer so no need for using file.ignore()
        getline(file, p.city);
        getline(file, p.bloodgroup);
        getline(file, p.fathername);
        getline(file, p.mothername);
        file.getline(p.cnic, 15);   //1 extra for \0 null terminator  1 for getline as getline reads (size - 1)
        file >> p.issueDay; file.ignore();
        file >> p.issueMonth; file.ignore();
        file >> p.issueYear; file.ignore();
        file >> p.expiryDay; file.ignore();
        file >> p.expiryMonth; file.ignore();
        file >> p.expiryYear; file.ignore();
        record.push_back(p); // Add to vector

    }
    file.close();
    printLoad(); //big word print
    cout << "All records loaded successfully!" << endl<<endl;
}

void young() {
    if(record.empty()) {
        cout << "No records found!" << endl<<endl;
        return;
    }
  int temp = 0;
     //why we donot use sorting because sorting permanently changes the record and arrange it by age or what we do so we just get the index of that and use it
    for(int i = 1; i < record.size(); i++) {  // we start from one because 0 index is already stored
    
            if(record[i].age < record[temp].age) {
                temp = i;
            }
        
    }
     printSearching();
    cout << "The youngest person is: " << record[temp].name<<endl << " with age " << record[temp].age << endl;
}


void old() {
    if(record.empty()) {
        cout << "No records found!" << endl;
        return;
    }
 int temp = 0;
    //why we donot use sorting because sorting permanently changes the record and arrange it by age or what we do so we just get the index of that and use it
    for(int i = 1; i < record.size() ; i++) { // we start from one because 0 index is already stored
                  if(record[i].age > record[temp].age)
				   {
                temp = i; 
        }
   }
      printSearching();
    cout << "The old person is: " << record[temp].name<<endl << " with age " << record[temp].age << endl<<endl;
}

void tall() {
    if(record.empty()) {
        cout << "No records found!" << endl;
        return;
    }
  int temp = 0;
     //why we donot use sorting because sorting permanently changes the record and arrange it by age or what we do so we just get the index of that and use it
    for(int i = 1; i < record.size(); i++) { // we start from one because 0 index is already stored
      
            if(record[i].height > record[temp].height) {
                temp = i;
            }
        
        
    }
printSearching();
    cout << "The tall person is: " << record[temp].name<<endl << " with height " << record[temp].height << endl<<endl;
}


void shortt() {   // short is built in function so we use sortt
    if(record.empty()) {
        cout << "No records found!" << endl;
        return;
    }
  int temp = 0;
     //why we donot use sorting because sorting permanently changes the record and arrange it by age or what we do so we just get the index of that and use it
    for(int i = 1; i < record.size(); i++) { // we start from one because 0 index is already stored
      
            if(record[i].height < record[temp].height) {
                temp = i;
            }
    }
    
printSearching();
    cout << "The short person is: " << record[temp].name<<endl << " with height " << record[temp].height << endl<<endl;
}

void sorting()
{
	int choice;
	while(true)
	{
	cout<<"0.For existing the program"<<endl;
	cout<<"1.Young person by age "<<endl;
	cout<<"2.Old person by age "<<endl;
	cout<<"3.Tallest person by height"<<endl;
	cout<<"4.Smallest person by height "<<endl;

	choice=getInt();
switch(choice)
{
	case 0:
	
    cout << "Exiting..." << endl;
    return; // This "breaks" the loop and exits the mainpage() function use return as it is void function not int
	case 1:
		young();
		history("SORTING","young by age");
		break;
	case 2:
		old();
		history("SORTING","old by age");
		break;
	case 3:
		tall();
		history("SORTING","tall by height");
	   break;
	case 4:
		shortt();
		history("SORTING","short height");
		break;
    default:
         cout << "Invalid choice!\n";
}
}
}
void malecheck()
{
	int malecount=0;
	for(int i=0;i<record.size();i++)
	{
		if(record[i].gender=='M')
		{
			malecount++;
		}
	}
	cout<<"Total Male person = "<<malecount<<endl<<endl;
}
void femalecheck()
{
	int femalecount=0;
	for(int i=0;i<record.size();i++)
	{
		if(record[i].gender=='F')
		{
			femalecount++;
		}
	}
	cout<<"Total Female person = "<<femalecount<<endl<<endl;
}
//we place it below male and female because we call male and female count in this
void totalperson()
{
	cout<<"Total person in the record is = "<<record.size()<<endl;
	//in this we donot use cout<<malecheck(); or femalecheck(); because these are void they retrun nothing
    malecheck();
	femalecheck();
}
void viewHistory()
{
    cout << "--- OPERATOR SESSION HISTORY ---" << endl;
    cout << "TYPE\t\tDESCRIPTION" << endl;
    cout << "-------------------------------\n" << endl;
    for (int i = 0; i < historycount; i++) {
        cout << historyarr[i][0] << "\t\t" << historyarr[i][1] << endl<<endl;
    }
}


void otheroperation()
{
	int choice;
	while(true)
	{
	cout<<"0.For existing the program"<<endl;
	cout<<"1.For total person in save record"<<endl;
	cout<<"2.For total male "<<endl;
	cout<<"3.For total female "<<endl;
	choice=getInt();

switch(choice)
{
	case 0:
    cout << "Exiting..." << endl;
    return; // This "breaks" the loop and exits the mainpage() function use return as it is void function not int
	case 1:
		totalperson();
		history("otheroperation","total person");
		break;
	case 2:
		malecheck();
		history("otheroperation","male check");
		break;
	case 3:
		femalecheck();
     	history("otheroperation","female check");
	   break;
    default:
         cout << "Invalid choice!\n";
}
}
}
void ageheightparallel()
{
    cout << "Age\tHeight"<<endl;
    cout << "----------------"<<endl;

    for(int i = 0; i < record.size(); i++)
    {
        cout << record[i].age << "\t"
             << record[i].height << endl;
    }
}
void loginuserfile() {
    
    ifstream check("login.txt");
    if (check) {
        check.close();
        return; // File already exists, no need to create it again
    }
    // If file doesn't exist, create it and add the default roles
    ofstream file("login.txt");
    if (file) {
        file << "ADMIN admin Admin" << endl;
        file << "OPERATOR operator Operator" << endl;
        file << "CITIZEN citizen User" << endl;
        file.close();
    }
}
struct User {  // for checking user and password from user
    string username;
    string password;
    string role;
};
string usercheck() {
    string u, p;
    cout << "Enter username: ";
    u = getString();
    cout << "Enter password: ";
    p = getString();
    ifstream file("login.txt");
    User temp;  // use User structure
    
    // Read the file line by line to check credentials
    while (file >> temp.username >> temp.password >> temp.role) {
        if (temp.username == u && temp.password == p) {
            file.close();
            return temp.role; // Success! Returns "Admin", "Manager", or "User"
        }
    }
    
    file.close();
    return "FAILED"; // No match found
}






void mainpage()
{
	int choice;
	while(true)
	{
	cout<<"0.For existing the program"<<endl;
	cout<<"1.For add record "<<endl;
	cout<<"2.For delete record "<<endl;
	cout<<"3.For check record "<<endl;
	cout<<"4.For edit record "<<endl;
	cout<<"5.For all record "<<endl;
	cout<<"6.For saving record "<<endl;
	cout<<"7.For loading record "<<endl;
	cout<<"8.For sorting "<<endl;
	cout<<"9.For other operation"<<endl;
	cout<<"10.Age & height parallel"<<endl;
	cout<<"11.For history"<<endl;
	cout << "12. Renew CNIC" << endl;

	choice=getInt();
  
switch(choice)
{
	case 0:
	
    cout << "Exiting..." << endl;
    return; // This "breaks" the loop and exits the mainpage() function use return as it is void function not int
	case 1:
		addrecord();
		history("INSERT", "Added a new citizen record(admin)");
		break;
	case 2:
		deleterecord();
		history("DELETE", "Removed a record from system(admin)");
		break;
	case 3:
		checkrecord();
		history("CHECK", "Check a record by CNIC(admin)");
		break;
	case 4:
		editrecord();
		history("UPDATE", "UPADTE an existing record(admin)");
		break;
	case 5:
		 showallrecord();
		 history("VIEW", "Displayed all stored records(admin)");
		 	break;
	case 6:
		 savetofile();
		 history("SAVE"," Record saved to file(admin)");
		 	break;
	case 7:
		loadfromfile();
		history("LOAD","load from file(admin)");
			break;
	case 8:
		 sorting();
		 history("SORTING","by admin");
		 break;
	case 9:
		  otheroperation();
		  history("otheroperation","by admin");
		  break;
	case 10:
		ageheightparallel();
		break;
	case 11:
		viewHistory();
		break;
	case 12:
    renewCNIC();
    break;

		
    default:
         cout << "Invalid choice!\n";
}
}
}
void Omainpage() {
    int choice;
    while(true) {
        cout << "0. Logout" << endl;
        cout << "1. Add New Record" << endl;
        cout << "2. Search Record by CNIC" << endl;
        cout << "3. Show All Records" << endl;
        cout<<" 4.For sorting "<<endl;
        cout <<"5. View Statistics (Other Operations)" << endl;
        cout<<"6.Age & height parallel"<<endl;
        cout <<"7. Renew CNIC" << endl;

        choice = getInt();
        switch(choice) {
            case 0:
                cout << "Logging out..." << endl;
                return;
            case 1:
                addrecord();
                history("INSERT", "Added a new citizen record(operator)");
                break;
            case 2:
                checkrecord();
                history("CHECK", "Check a record by CNIC(operator)");
                break;
            case 3:
                showallrecord();
                history("VIEW", "Displayed all stored records(operator)");
                break;
            case 4:
		       sorting();
		       history("SORTING","by operator");
		        break;
            case 5:
                otheroperation();
                history("otheroperation","by operator");
                break;
            case 6:
                ageheightparallel();
                break;
            case 7:
                  renewCNIC();
                  break;
            default:
                cout << "Invalid choice!" << endl;
        }
    }
}
void Cmainpage()
{
	int choice;
	while(true)
	{
	cout<<"0.For existing the program"<<endl;
	cout<<"1.Load from file"<<endl;
	cout<<"2.For check record "<<endl;
	
	choice=getInt();
  
switch(choice)
{
	
    case 0:
    cout << "Exiting ...." << endl;
    return ; // This "breaks" the loop and exits the mainpage() function use return as it is void function not int
	case 1:
		loadfromfile();
		history("LOAD","load from file(user)");
		break;
	case 2:
		checkrecord();
		 history("CHECK", "Check a record by CNIC(user)");
	   break;
    default:
         cout << "Invalid choice!\n";

}
}
}
int main()
{
    loginuserfile();  //create file having login data
	printBigNADRA();
	string password;
	string username;
	srand(time(0)); //for genrating the random numbers with respect to time
	cout<<"WELCOME TO National Database and Registration Authority"<<endl;
	cout<<"For  Sign-in in you account Please enter you User name and Password!!"<<endl;
	int attempts = 0;
while(attempts < 3) {
    string role = usercheck(); // Check file for getting that its admin user citizen 
    if(role=="Admin") 
	{
    	printAdminPortal();
        cout << "Welcome Admin!\n" << endl;
        loadfromfile();
        mainpage();
        break;
    } else if(role=="User")
	{
    	printCitizenPortal();
        cout << "Welcome Citizen!\n" << endl;
        loadfromfile();
        Cmainpage();
        break;
    } 
    else if(role=="Operator")
	{
    printOperatorPortal();
    cout << "Welcome Operator!\n" << endl;
    loadfromfile();
    Omainpage();
    break;
}
	else
	{
        cout << "Incorrect username or password!\n" << endl;
        attempts++;
    }
}
if(attempts == 3) 
{
    cout << "Too many failed attempts. Exiting program.\n" << endl;
    cout<<"Exiting program......";
    return 0;
}
return 0;

}