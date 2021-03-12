# Wireless Named Data Networking Over LoRa
This repository contains the project and work done to add a LoRa networking face to the Named Data Networking protocol based fowarading software [NFD](https://github.com/named-data/NFD).

## Installation & Usage
### Hardware and Libraries
This code was modified for and tested on the following hardware and software:
- Raspberry Pi 3B+
- LoRa Module (Either will work, just need 1 per Raspberry Pi)
  - Libelium SX1272 LoRa Shield https://www.cooking-hacks.com/sx1272-lora-shield-for-raspberry-pi-900-mhz.html
  - Modtronix SX1276 inAir9B

The libraries used are as follows:
- [ndn-cxx](https://github.com/named-data/ndn-cxx) - C++ Library that implements NDN programming functions. Used by NFD.
- [ArduPi](https://www.cooking-hacks.com/documentation/tutorials/extreme-range-lora-sx1272-module-shield-arduino-raspberry-pi-intel-galileo/index.html#step4) SX1272 Library for Raspberry Pi

Software:
- Raspbian 10 Buster
- Clang 9
- [NFD](https://github.com/named-data/NFD) - NDN forwarding software.
- [NDN-Tools](https://github.com/named-data/ndn-tools) - Simple command-line tools for testing NFD and NDN applications.

### Software Setup
Prior knowledge of Linux, the command line, C++, Python, compilation, and installation is assumed. This setup is based off of [Dr. Ashiqur Rahman's Guide](https://gist.github.com/ashiqopu/547f357345db396fdf3e36e6ed462cbe). See his guide for a more in depth instructions.

Raspbian and Rasbian Lite were both tested working for this project. Raspbian Lite is recommended for the lighter memory usage.

After installing Raspbian Lite on the Raspberry Pi, Clang 9 must be installed. [Here](https://solarianprogrammer.com/2018/04/22/raspberry-pi-raspbian-install-clang-compile-cpp-17-programs/) is an article about installing Clang 8 on the Pi. Newer versions have not been tested with this project (but will likely work).


### Compiling & Installation
#### First Time Compilation

These build and installation instructions are based off of [this tutorial](https://named-data.net/doc/NFD/current/INSTALL.html) from Named-Data.net. See the tutorial for more in depth instructions.

Install the dependencies first:
```
sudo apt-get install build-essential pkg-config libboost-all-dev \
                     libsqlite3-dev libssl-dev libpcap-dev
```

Download the git files:
```
git clone --recursive https://github.com/Jiuro/NDN_over_LoRa.git
```

Navigate to the NDN_over_loRa folder.
Compile and install the modified library in the `ndn-cxx` folder first from the command line:
```
cd ndn-cxx
sudo chmod u+x ./waf
CXX=clang++ ./waf configure
./waf -j2
sudo ./waf install
sudo ldconfig
```


Next, compile and install the modified library in the `NFD` folder:
```
cd NFD
sudo chmod u+x ./waf
CXX=clang++ ./waf configure
./waf -j2
sudo ./waf install
```
Copy the modified NFD configuration file from the root directory to the correct location:
```
sudo cp nfd.conf /usr/local/etc/ndn/nfd.conf
```

Compile and install ndn-tools. The version provided in the `ndn-tools` folder has not been modified so a new version may be installed from [https://github.com/named-data/ndn-tools](https://github.com/named-data/ndn-tools) by following the instructions posted there. However the `ndn-tools` folder contains a tested working version and can be compiled and installed as follows:
```
cd ndn-tools
sudo chmod u+x ./waf
CXX=clang++ ./waf configure
./waf -j2
sudo ./waf install
```

`CXX=clang++` is used to siginify to [waf](https://waf.io/) (a build system) to use the clang++ compiler.

The -j2 flag is used to limit the number of simultaneous compilations to 2 jobs. This is done to reduce memory usage. Successful compilation has been achieved with 3 jobs, but has also needed to be limited to 1 job depending on what other software is running on the Pi at the time of compilation.

#### LoRa Configuration
The following commands are to compile the lora configuration commands. The LoRa takes its setting values from a text file, and these commands will alter the text file or read it.
```
cd NFD/lora_libs/setup/
clang++ getLoraSetup.cpp -o getlora
clang++ setuplora.cpp -o setlora
sudo cp -r getlora /usr/local/bin
sudo cp -r setlora /usr/local/bin
```
You can now run the commands from anywhere via the command console.
```
getlora
setlora
```
#### Testing GPIO (Optional)
The following compiles the test GPIO. DO NOT have anything wired to the Pi while this is being done!
```
cd test
clang++ -pthread *.cpp -o testGPIO
```
You can move it to the bin directory if you want to be able to run the command from anywhere:
```
sudo cp -r testGPIO /usr/local/bin
```
Run the command with either of the following: (the first one requires you to be in the test folder and the second requires the executable to be in the /bin folder.
```
sudo ./testGPIO
testGPIO
```

#### Susbsequent Compilations
Once everything has been compiled for the first time and tested working, if any changes are made the compilation and installation will go much faster and requires fewer steps.

If ndn-cxx is modified:
```
cd ndn-cxx
./waf -j2
sudo ./waf install
sudo ldconfig
```

If NFD is modified:
```
cd NFD
./waf -j2
sudo ./waf install
```


### Running and testing the software
Make sure the SX1272/SX1276 module is connected to the Raspberry Pi. Make sure the Pi is off while connecting the module.

Test out NFD locally or with a face other than LoRa first.
Creating a face and connecting to other NFD daemons can be found at [Getting Started with NFD](https://named-data.net/doc/NFD/current/INSTALL.html) & [NDN-tools testing](https://github.com/named-data/ndn-tools).

#### Starting and Stopping NFD
```
sudo NFD -start

sudo NFD -stop
```
#### Creating a LoRa Face
2 or more Raspberry Pis with LoRa modules will need to be set up for this test.

Create a LoRa face on each Pi:

*When creating a face, the format follows the format of: current_node_id-connected_node_id.
The node_id can be any unique number.
Ex. connect node 1 to node 2 with '... lora://1-2' or do a broadcast with '...lora://1'. This can be set to any number / numbers.

```
nfdc face create lora://1
```
Look for the face id
```
nfdc route add /ndn <faceid>
```
The route added (/ndn) can be any route name

Add another face if you want to make a connection to another node.

Follow the same instructions for the next node with the appropriate ids.

#### Testing
Using ndn-tools:

On one Pi, produce a packet: (the /ndn is the name of the packet and can be changed to '/___')
```
echo "test" | ndnpoke -x 10000 /ndn
```
-x specifies the freshness of the packet

/ndn is the name to produce the packet on

On the second Pi,
```
ndnpeek -pf -l 10000 /ndn
```
The -l flag specifies the timeout period.

### Configuration
The LoRa module hardware is setup in NFD/daemon/face/lora-factory.cpp in the `setup()` function.

## Files & Modifications
Modified/Added files:
- ndn-cxx/ndn-cxx/net/face-uri.cpp
- ndn-cxx/ndn-cxx/net/face-uri.hpp
- NFD/daemon/face/lora-transport.cpp
- NFD/daemon/face/lora-transport.hpp
- NFD/daemon/face/lora-channel.cpp
- NFD/daemon/face/lora-channel.hpp
- NFD/daemon/face/lora-factory.cpp
- NFD/daemon/face/lora-factory.hpp
- NFD/lora_libs/libraries/arduPiLoRa/arduPiLoRa.cpp
- NFD/lora_libs/libraries/arduPiLoRa/arduPiLoRa.hpp
- NFD/lora_libs/arduPi/arduPi.cpp
- NFD/lora_libs/arduPi/arduPi.h
- ndnScripts/*
- nfd.conf

## Authors, Contributors, & Resources
[Named Data software and libraries](https://github.com/named-data) were modified by:
-Camden Ewell
-Kevin Chau
-Ye Zhou
-Jack Fahey
- Sean Hammond
- Jake Maschoff
- Bryan Hatasaka
- Katlynne Bills
- Garrick Clegg
- Jason Stauffer
- Thomas Van Hook

Advisors, Mentors, Support, Thanks
- Stephen Dudley
- Mingyue Ji
- Jon Davies
- L3Harris Technologies
- University of Utah Electrical and Computer Engineering department

Resources:
- https://named-data.net/
- https://gist.github.com/ashiqopu/547f357345db396fdf3e36e6ed462cbe
- https://www.cooking-hacks.com/documentation/tutorials/extreme-range-lora-sx1272-module-shield-arduino-raspberry-pi-intel-galileo/index.html
- https://www.raspberrypi.org/
- https://github.com/named-data/NFD
- https://github.com/named-data/ndn-cxx
- https://github.com/named-data/ndn-tools


Big thanks goes to all contributers of the [Named Data Netwoking Project](https://named-data.net/)!
