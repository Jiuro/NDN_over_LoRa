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

	string val;
	string DB;
	string CR;
	string BW;
	string SF;
	string F;
	string P;
	string NA;


	int e =0;
	int i=0;
	bool error=false;
	int choice;
	int menu_choice;
	bool menu = false;

	ifstream myfile ("/home/pi/NDN_over_LoRa/NFD/lora_libs/setup/lora_config.txt");
  	if (myfile.is_open())
  	{
		  //get debug value
        while (getline(myfile, line))
		{
			switch (i){
				case 0: val = line; break;
				case 1: DB = line; break;
				case 2: CR = line; break;
				case 3: BW = line; break;
				case 4: SF = line; break;
				case 5: F = line; break;
				case 6: P = line; break;
				case 7: NA = line; break;
			}
			i++;
			
		}
		myfile.close();
	}
  	else {
		  cout << "Error: Unable to open file. Stop the program!";
		  return 0;
	}

	fstream newfile;
   	newfile.open("/home/pi/NDN_over_LoRa/NFD/lora_libs/setup/lora_config.txt",ios::out);  // open a file to perform write operation using file object
   	if(newfile.is_open())     //checking whether the file is open
   	{

    	while(menu==false)
    	{
		
		cout<<"________________________________\n";
		cout<<"1 - Default Setup.\n";
		cout<<"2 - Enter Values.\n";
		cout<<"3 - Exit without changes.\n";
		cout<<"Enter your choice for the LoRa setup: ";
		cin>> choice;
		cin.clear();


			switch (choice){
				case 1:
				
      				newfile<<"1\n"; //inserting text
        			newfile<<"1\n";
        			newfile<<"7\n";
					newfile<<"500\n";
					newfile<<"10\n";
					newfile<<"21\n";
					newfile<<"2\n";
					newfile<<"3\n";
      				newfile.close(); //close the file object

					cout << "Set the default settings: \n";
					cout<<"________________________________\n";
					cout << "The message setting is: low"<< endl; 
					cout << "The Coding Rate setting is: CR_7" << endl;
					cout << "The Bandwidth setting is: BW_500" << endl;
					cout << "The Spreading Factor setting is: SF_10" << endl;
					cout << "The channel and frequency settings are: CH_12_900 (915 MHz)"  << endl;
					cout << "The Power setting is: 'H'" << endl;
					cout << "The Node Address is: 3" << endl;

				menu = true;

				break;

			case 2://Enter values for LoRa
				menu = true;
				cout<<"\n***************************************************************************************\n";
				cout<<"\n		NDN over LoRa Configuration\n";
				cout<<"\n***************************************************************************************\n";
				cout<<"\n";
				cout<<"	***Giving any value not listed in the menu will result in default settings.***\n";
				//newfile<<"1\n"; // Tell the program that the LoRa is ready for change.

				cout<<"\nDebug Messages: \n";
				cout<<"	0 - OFF \n";
				cout<<"	1 - Light (Default)\n";
				cout<<"	2 - Medium \n";
				cout<<"Please pick a value: ";
				cin>> menu_choice;
				cin.clear();
				switch (menu_choice)
				{
					case 0: DB = "0"; break; //newfile<<"0\n"; break;
					case 1: DB = "1"; break; //newfile<<"1\n"; break;
					case 2: DB = "2"; break; //newfile<<"2\n"; break;
					default: cout<<"Defaulted\n"; DB = "1"; break; //newfile<<"1\n"; break;
				}

				cout<<"\nSet Coding Rate: \n";
				cout<<"	5 - CR_5 \n";
				cout<<"	6 - CR_6 \n";
				cout<<"	7 - CR_7 (Default)\n";
				cout<<"	8 - CR_8 \n";
				cout<<"Please pick a value: ";
				cin>> menu_choice;
				cin.clear();
				switch (menu_choice)
				{
					case 5: CR = "5"; break; //newfile<<"5\n"; break;
					case 6: CR = "6"; break; //newfile<<"6\n"; break;
					case 7: CR = "7"; break; //newfile<<"7\n"; break;
					case 8: CR = "8"; break; //newfile<<"8\n"; break;
					default: cout<<"***Defaulted***\n"; CR = "7"; break; //newfile<<"7\n"; break;
				}

				cout<<"\nSet Bandwidth: \n";
				cout<<"	125 - BW_125 \n";
				cout<<"	250 - BW_250 \n";
				cout<<"	500 - BW_500 (Default)\n";
				cout<<"Please pick a value: ";
				cin>> menu_choice;
				cin.clear();
				switch (menu_choice)
				{
					case 125: BW = "125"; break; //newfile<<"125\n"; break;
					case 250: BW = "250"; break; //newfile<<"250\n"; break;
					case 500: BW = "500"; break; //newfile<<"500\n"; break;
					default: cout<<"***Defaulted***\n"; BW = "500"; break; //newfile<<"500\n"; break;
				}

				cout<<"\nSet Spreading Factor: \n";
				cout<<"	6 - SF_6 \n";
				cout<<"	7 - SF_7 \n";
				cout<<"	8 - SF_8 \n";
				cout<<"	9 - SF_9 \n";
				cout<<"	10 - SF_10 (Default)\n";
				cout<<"	11 - SF_11 \n";
				cout<<"	12 - SF_12 \n";
				cout<<"Please pick a value: ";
				cin>> menu_choice;
				cin.clear();
				switch (menu_choice)
				{
					case 6: SF = "6"; break; //newfile<<"6\n"; break;
					case 7: SF = "7"; break; //newfile<<"7\n"; break;
					case 8: SF = "8"; break; //newfile<<"8\n"; break;
					case 9: SF = "9"; break; //newfile<<"9\n"; break;
					case 10: SF = "10"; break; //newfile<<"10\n"; break;
					case 11: SF = "11"; break; //newfile<<"11\n"; break;
					case 12: SF = "12"; break; //newfile<<"12\n"; break;
					default: cout<<"***Defaulted***\n"; SF = "10"; break; //newfile<<"10\n"; break;
				}

  				// Select frequency channel
				cout<<"\nSet Channel and Frequency: \n";
				cout<<"	1 - CH_10_868 (865.20MHz)\n";
				cout<<"	2 - CH_11_868 (865.50MHz)\n";
				cout<<"	3 - CH_12_868 (865.80MHz)\n";
				cout<<"	4 - CH_13_868 (866.10MHz)\n";
				cout<<"	5 - CH_14_868 (866.40MHz)\n";
				cout<<"	6 - CH_15_868 (866.70MHz)\n";
				cout<<"	7 - CH_16_868 (867.00MHz)\n";
				cout<<"	8 - CH_17_868 (868.00MHz)\n";
				cout<<"	9 - CH_00_900 (903.08MHz)\n";
				cout<<"	10 - CH_01_900 (905.24MHz)\n";
				cout<<"	11 - CH_02_900 (907.40MHz)\n";
				cout<<"	12 - CH_03_900 (909.56MHz)\n";
				cout<<"	13 - CH_04_900 (911.72MHz)\n";
				cout<<"	14 - CH_05_900 (913.88MHz)\n";
				cout<<"	15 - CH_06_900 (916.04MHz)\n";
				cout<<"	16 - CH_07_900 (918.20MHz)\n";
				cout<<"	17 - CH_08_900 (920.36MHz)\n";
				cout<<"	18 - CH_09_900 (922.52MHz)\n";
				cout<<"	19 - CH_10_900 (924.68MHz)\n";
				cout<<"	20 - CH_11_900 (926.84MHz)\n";
				cout<<"	21 - CH_12_900 (915.00MHz) (Default)\n";
				cout<<"Please pick a value: ";
				cin>> menu_choice;
				cin.clear();
				switch (menu_choice)
				{
					case 1: F = "1"; break; //newfile<<"1\n"; break;
					case 2: F = "2"; break; //newfile<<"2\n"; break;
					case 3: F = "3"; break; //newfile<<"3\n"; break;
					case 4: F = "4"; break; //newfile<<"4\n"; break;
					case 5: F = "5"; break; //newfile<<"5\n"; break;
					case 6: F = "6"; break; //newfile<<"6\n"; break;
					case 7: F = "7"; break; //newfile<<"7\n"; break;
					case 8: F = "8"; break; //newfile<<"8\n"; break;
					case 9: F = "9"; break; //newfile<<"9\n"; break;
					case 10: F = "10"; break; //newfile<<"10\n"; break;
					case 11: F = "11"; break; //newfile<<"11\n"; break;
					case 12: F = "12"; break; //newfile<<"12\n"; break;
					case 13: F = "13"; break; //newfile<<"13\n"; break;
					case 14: F = "14"; break; //newfile<<"14\n"; break;
					case 15: F = "15"; break; //newfile<<"15\n"; break;
					case 16: F = "16"; break; //newfile<<"16\n"; break;
					case 17: F = "17"; break; //newfile<<"17\n"; break;
					case 18: F = "18"; break; //newfile<<"18\n"; break;
					case 19: F = "19"; break; //newfile<<"19\n"; break;
					case 20: F = "20"; break; //newfile<<"20\n"; break;
					case 21: F = "21"; break; //newfile<<"21\n"; break;
					default: cout<<"***Defaulted***\n"; F = "21"; break; //newfile<<"21\n"; break;
				}

  				// Select output power (Max, High or Low)
				cout<<"\nSet Power \n";
				cout<<"	1 - 'Low' \n";
				cout<<"	2 - 'High' (Default) \n";
				cout<<"	3 - 'Max'\n";
				cout<<"	4 - Low Pa_boost \n";
				cout<<"	5 - High Pa_boost \n";
				cout<<"Please pick a value: ";
				cin>> menu_choice;
				cin.clear();
				switch (menu_choice)
				{
					case 1: P = "1"; break; //newfile<<"1\n"; break;
					case 2: P = "2"; break; //newfile<<"2\n"; break;
					case 3: P = "3"; break; //newfile<<"3\n"; break;
					case 4: P = "4"; break; //newfile<<"4\n"; break;
					case 5: P = "5"; break; //newfile<<"5\n"; break;
					default: cout<<"***Defaulted***\n"; P = "2"; break; //newfile<<"2\n"; break;
				}


  				// Set the node address
				cout<<"Set Node Address \n";
				cout<<"Please pick a value: (Recommended: 3)";
				cin>> menu_choice;
				cin.clear();
				switch (menu_choice)
				{
					case 1: NA = "1"; break; //newfile<<"1\n"; break;
					case 2: NA = "2"; break; //newfile<<"2\n"; break;
					case 3: NA = "3"; break; //newfile<<"3\n"; break;
					case 4: NA = "4"; break; //newfile<<"4\n"; break;
					case 5: NA = "5"; break; //newfile<<"5\n"; break;
					default: cout<<"***Defaulted***\n"; NA = "3"; break; //newfile<<"3\n"; break;
				}
				// newfile<<menu_choice; break;

				
			break;
			case 3:
				// newfile<<val<<"\n";
				// newfile<<DB<<"\n";
				// newfile<<CR<<"\n";
				// newfile<<BW<<"\n";
				// newfile<<SF<<"\n";
				// newfile<<F<<"\n";
				// newfile<<P<<"\n";
				// newfile<<NA<<"\n";
				menu = true;
			break;
			default:
				cout << "Invalid choice! Choose again.";
				menu = false;
			break;
			
		}
		
		}
		newfile<<"1\n";
		newfile<<DB<<"\n";
		newfile<<CR<<"\n";
		newfile<<BW<<"\n";
		newfile<<SF<<"\n";
		newfile<<F<<"\n";
		newfile<<P<<"\n";
		newfile<<NA<<"\n";
		newfile.close();		
	  }
	  else {cout<<"Unable to open file!\n";}

  return 0;
}