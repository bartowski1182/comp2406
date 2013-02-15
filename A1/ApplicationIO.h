#ifndef APPIO_H
#define APPIO_H

#include "Application.h"
#include "ApplicationQueue.h"
#include <iostream>
#include <fstream>
#include <string>

using namespace std;

class ApplicationIO
{



  public:
    ApplicationIO();
    ~ApplicationIO();
    
    void saveApplications(ApplicationQueue*) const;

};

#endif
