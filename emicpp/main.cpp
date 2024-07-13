//
//  main.cpp
//  emicpp
//
//  Created by emiliano.roberti on 03/06/2024.
//

#include <iostream>
#include "DM_Device_Info.hpp"
using namespace std;

class IDM_Device {
public:
    virtual ~IDM_Device() = default;
    virtual void parse() = 0;
protected:
    DM_Device_config deviceConfig;
    IDM_Device(const DM_Device_config& config) : deviceConfig(config) {}
};

class IDM_Milesight : public IDM_Device {
public:
    IDM_Milesight(const DM_Device_config& config) : IDM_Device(config) {
        std::cout << "Milesight device created with IP: " << config.ip << " and Name: " << config.name << std::endl;
    }

    void parse() override {
        std::cout << "Parsing Milesight device configuration..." << std::endl;
    }
};

class Panasonic : public IDM_Device {
public:
    Panasonic(const DM_Device_config& config) : IDM_Device(config) {
        std::cout << "Panasonic device created with IP: " << config.ip << " and Name: " << config.name << std::endl;
    }

    void parse() override {
        std::cout << "Parsing Panasonic device configuration..." << std::endl;
    }
};

class DeviceFactory {
public:
    static IDM_Device* createDevice(const DM_Device_config& config) {
        switch (config.mode) {
            case 1:
                return new IDM_Milesight(config);
            case 2:
                return new Panasonic(config);
            default:
                return nullptr;
        }
    }
};


//EMULATED WHAT MILESIGHT SEE
int main(int argc, const char * argv[]) {
    DM_Device_config dInfo("192.188.1.12", "emi", 2);
    IDM_Device* device = DeviceFactory::createDevice(dInfo);
    
    if (device) {
        device->parse();
        delete device;
    } else {
        std::cerr << "Unsupported device mode: " << dInfo.mode << std::endl;
    }

    return 0;
}
