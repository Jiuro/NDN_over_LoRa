// reading a text file
#include <iostream>
#include <fstream>
#include <string>
#include <sstream>
using namespace std;

int main () {
	cout <<"\n";
	string getV;
	int gv = 0; //which line are we on
	ifstream myfile ("/home/pi/NDN_over_LoRa/NFD/lora_libs/setup/lora_config.txt");
  	if (myfile.is_open())
  	{
		  //get debug value
        while (getline(myfile, getV))
		{
			switch (gv){
				case 0: cout << "The debug setting is: " << getV << endl; break;
				case 1: cout << "The Coding Rate setting is: " << getV << endl; break;
				case 2: cout << "The Bandwidth setting is: " << getV << endl; break;
				case 3: cout << "The Spreading Factor setting is: " << getV << endl; break;
				case 4: cout << "The channel and frequency settings are: " << getV << endl; break;
				case 5: cout << "The Power setting is: " << getV << endl; break;
				case 6: cout << "The Node Address is: " << getV << endl; break;
			}
			gv++;
			
		}

	}

  else cout << "Error: Unable to open file. Stop the program!";
  myfile.close();

  return 0;
}