#ifndef PENDAPP_H
#define PENDAPP_H

#include "PendingChoose.h"
#include "PendingOneCourse.h"

class PendingApps
{
  public:
    PendingApps();
    ~PendingApps();

    void initPendApps();

  private:
    int update();
    
    int index;
    int nBreaker;

    PendingChoose* choosePage;
    PendingOneCourse* onePage;

};
#endif
