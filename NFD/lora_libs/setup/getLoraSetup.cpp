// reading a text file
#include <iostream>
#include <fstream>
#include <string>
#include <sstream>
using namespace std;

int main () {
	cout <<"\n";
	string getV;
	int i=0;
	int gv = 0; //which line are we on
	ifstream myfile ("/home/pi/NDN_over_LoRa/NFD/lora_libs/setup/lora_config.txt");
  	if (myfile.is_open())
  	{
		cout<<"\n******************************************************************************\n";
		cout<<"\n				LORA Settings\n";
		cout<<"\n******************************************************************************\n";
		//get debug value
        while (getline(myfile, getV))
		{
			stringstream val1(getV);//change string to int
			val1 >> i; //change string to int
			switch (gv){
				case 0: //Does lora need to update
					cout << "Does the LoRa need to update? "; 
					
					switch (i)
					{
						case 0: cout << "No" << endl; break;
						case 1: cout << "Yes" << endl; break;
					}
				break;

				case 1: //display messages setting
					cout << "The message setting is: ";
					switch (i)
					{
						case 0: cout << "None" << endl; break;
						case 1: cout << "Low" << endl; break;
						case 2: cout << "High" << endl; break;
					}
				break;

				case 2: cout << "The Coding Rate setting is: CR_" << getV << endl; break;
				case 3: cout << "The Bandwidth setting is: BW_" << getV << endl; break;
				case 4: cout << "The Spreading Factor setting is: SF_" << getV << endl; break;

				case 5: //output the frequency
					cout << "The channel and frequency settings are: "; 
					switch (i)
					{
						case 1: cout<<"CH_10_868 (865.20MHz)\n"; break;
						case 2: cout<<"CH_11_868 (865.50MHz)\n"; break;
						case 3: cout<<"CH_12_868 (865.80MHz)\n"; break;
						case 4: cout<<"CH_13_868 (866.10MHz)\n"; break;
						case 5: cout<<"CH_14_868 (866.40MHz)\n"; break;
						case 6: cout<<"CH_15_868 (866.70MHz)\n"; break;
						case 7: cout<<"CH_16_868 (867.00MHz)\n"; break;
						case 8: cout<<"CH_17_868 (868.00MHz)\n"; break;
						case 9: cout<<"CH_00_900 (903.08MHz)\n"; break;
						case 10: cout<<"CH_01_900 (905.24MHz)\n"; break;
						case 11: cout<<"CH_02_900 (907.40MHz)\n"; break;
						case 12: cout<<"CH_03_900 (909.56MHz)\n"; break;
						case 13: cout<<"CH_04_900 (911.72MHz)\n"; break;
						case 14: cout<<"CH_05_900 (913.88MHz)\n"; break;
						case 15: cout<<"CH_06_900 (916.04MHz)\n"; break;
						case 16: cout<<"CH_07_900 (918.20MHz)\n"; break;
						case 17: cout<<"CH_08_900 (920.36MHz)\n"; break;
						case 18: cout<<"CH_09_900 (922.52MHz)\n"; break;
						case 19: cout<<"CH_10_900 (924.68MHz)\n"; break;
						case 20: cout<<"CH_11_900 (926.84MHz)\n"; break;
						case 21: cout<<"CH_12_900 (915.00MHz)\n"; break;
					}
				break;

				case 6: 
					cout << "The Power setting is: ";
					switch (i)
					{
						case 1: cout << "'Low'" << endl; break;
						case 2: cout << "'High'" << endl; break;
						case 3: cout << "'Max'" << endl; break;
						case 4: cout<<"Low Pa_boost \n"; break;
						case 5: cout<<"High Pa_boost \n"; break;
					}
				break;
				case 7: cout << "The Node Address is: " << getV << endl; break;
			}
			gv++;
			
		}
	myfile.close();
	}
	else cout << "Error: Unable to open file. Stop the program!";
  

  return 0;
}