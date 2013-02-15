#ifndef WORKEXP_H
#define WORKEXP_H
using namespace std;
#include <string>
class WorkExp
{

  public:
    WorkExp(string = "", int = 0, string = "", string = "");
    ~WorkExp();
    
    string getResponsibilities();
    string getStartDate();
    string getEndDate();
    int getMonths();
    bool canSetResponsibilities(string);
    bool canSetMonths(string);
    string print();

  private:
    string responsibilities;
    string startDate;
    string endDate;
    int months;

};

#endif











