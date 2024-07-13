//
//  DM_Device_Info.hpp
//  emicpp
//
//  Created by emiliano.roberti on 12/07/2024.
//

#ifndef DM_Device_Info_hpp
#define DM_Device_Info_hpp

#include <stdio.h>
#include <string>

class DM_Device_config {
public:
    std::string ip;
    std::string name;
    int mode;
    
    DM_Device_config(std::string ip, std::string name, int mode);
};


#endif /* DM_Device_Info_hpp */
