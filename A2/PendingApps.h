#ifndef PENDAPP_H
#define PENDAPP_H

#include "PendingChoose.h"
#include "PendingOneCourse.h"
#include "ApplicationQueue.h"

class PendingApps
{
  public:
    PendingApps(ApplicationQueue **);
    ~PendingApps();

    void initPendApps();

  private:
    int update();
    
    int index;
    int nBreaker;

    PendingChoose* choosePage;
    PendingOneCourse* onePage;
    ApplicationQueue **applications;

};
#endif
