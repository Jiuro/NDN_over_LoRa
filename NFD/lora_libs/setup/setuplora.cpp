// reading a text file
#include <iostream>
#include <fstream>
#include <string>
#include <sstream>
using namespace std;

int main () 
{
  string line;
  int x=0;

	  int e =0;
	  bool error=false;
	  int choice;
	  int menu_choice;
	  bool menu = false;
    while(menu==false)
    {
		
		cout<<"________________________________\n";
		cout<<"1 - Default Setup\n";
		cout<<"2 - Enter Values\n";
		cout<<"Enter your choice for the LoRa setup: ";
		cin>> choice;
		cin.clear();

		switch (choice){
			case 1:
				fstream newfile;
   				newfile.open("/home/pi/NDN_over_LoRa/NFD/lora_libs/setup/lora_config.txt",ios::out);  // open a file to perform write operation using file object
   				if(newfile.is_open())     //checking whether the file is open
   				{
      				newfile<<"1\n"; //inserting text
        			newfile<<"1\n";
        			newfile<<"7\n";
					newfile<<"500\n";
					newfile<<"10\n";
					newfile<<"21\n";
					newfile<<"2\n";
					newfile<<"3\n";
      				newfile.close(); //close the file object

					cout << "Set the default settings: \n"
					cout<<"________________________________\n";
					cout << "The message setting is: low" endl; break;
					cout << "The Coding Rate setting is: CR_7" << endl; break;
					cout << "The Bandwidth setting is: BW_500" << endl; break;
					cout << "The Spreading Factor setting is: SF_10" << endl; break;
					cout << "The channel and frequency settings are: CH_12_900 (915 MHz)"  << endl; break;
					cout << "The Power setting is: 'H'" << endl; break;
					cout << "The Node Address is: 3" << endl; break;
   				}
   				else {cout<<"Unable to open file!\n";}

				menu = true;

			break;

			case 2://Enter values for LoRa
				cout<<"Debug Messages: \n";
				cout<<"0 - OFF \n";
				cout<<"1 - Light \n";
				cout<<"2 - Medium \n";
				cout<<"Please pick a value: ";
				cin>> menu_choice;
				cin.clear();
				switch (menu_choice)
				{

				}

				cout<<"Set Coding Rate: \n";
				cout<<"5 - CR_5 \n";
				cout<<"6 - CR_6 \n";
				cout<<"7 - CR_7 \n";
				cout<<"8 - CR_8 \n";
				cout<<"Please pick a value: ";
				cin>> menu_choice;
				cin.clear();
				switch (menu_choice)
				{

				}

  

  				// Set header


  				// Select frequency channel


  				// Set CRC


  				// Select output power (Max, High or Low)


  				// Set the node address

				menu = true;
			break;
			case 3:
				menu = true;
			break;
			default:
				cout << "Invalid choice! Choose again."
				menu = false;
			break;
			
		}


	  }

  return 0;
}