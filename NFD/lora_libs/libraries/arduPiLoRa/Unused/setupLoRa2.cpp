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
        pinMode(4,OUTPUT);
        digitalWrite(4,HIGH);
        delay(100);

        cout<<"Pin 4 is High\n";
        cout<<"Should it be turned off?\n";
        int x = 0;
        while (x!=3){
                cin>> x;
                cin.clear();
                switch (x){
                        case 1:
                        digitalWrite(4,HIGH);
                        delay(100);
                        cout<<"Pin 4 is High\n";
                        break;
                        case 2:
                        digitalWrite(4,LOW);
                        delay(100);
                        cout<<"Pin 4 is Low\n";
                        break;
                }
        }

        return 0;
}