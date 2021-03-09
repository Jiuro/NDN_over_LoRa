#include "arduPiLoRa.h"
//#include "arduPiLoRa.cpp"
#include <iostream>

using std::cout;
using std::cin;
int main() {

        // //sx1272.setupLora();
        // cout<<"pin"<<"  "<<"R-pin"<<"  "<<"Value"<<"\n";
        // for (int a=1;a<20;a++){
        //         pinMode(a,OUTPUT);
        //         digitalWrite(a,LOW);
        //         cout<<a<<", "<<raspberryPinNumber(a)<<", "<<digitalRead(a)<<"\n";

        // }

        // cout<<"\n";
        // for (int a=1;a<20;a++){
        //         try{
        //         digitalWrite(a,HIGH);
        //         cout<<a<<", "<<raspberryPinNumber(a)<<", "<<digitalRead(a)<<"\n";
        //         }

        // }
        // cout<<"\n";
        cout<<"Pin #"<<"  "<<"GPIO Pin"<<"  "<<"Value (1 is High, 0 is Low)"<<"\n";
        cout<<"_______________________________________________________________";
        for (int a=1;a<14;a++){
                pinMode(a,OUTPUT);
                digitalWrite(a,LOW);
                cout<<a<<",  "<<raspberryPinNumber(a)<<",  "<<digitalRead(a)<<"\n";

        }
        cout<<"What gpio pin do you want to test?";
        int pin = 1;
        cin>>pin;
        pinMode(pin,OUTPUT);
        digitalWrite(pin,HIGH);
        delay(100);

        cout<<"Pin "<<pin<<" is High\n";
        
        int x = 0;
        while (x!=3){
            cout<<"How should it be controlled?\n";
            cout<<"1 - High\n";
            cout<<"2 - Low\n";
            cout<<"3 - Quit Program\n";
                cin>> x;
                cin.clear();
                switch (x){
                        case 1:
                        digitalWrite(pin,HIGH);
                        delay(100);
                        cout<<"Pin "<<pin<<" is High\n";
                        break;
                        case 2:
                        digitalWrite(pin,LOW);
                        delay(100);
                        cout<<"Pin "<<pin<<" is Low\n";
                        break;
                }
        }

        return 0;
}