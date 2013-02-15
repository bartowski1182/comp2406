#include "WorkExp.h"

class WorkExp
{

  public:
    WorkExp(std::string == "", int = 0; std::string = "", std::string = "");
    ~WorkExp();
    
    string getResponsibilities();
    string getStartDate();
    string getEndDate();
    int getMonths();
    bool canSetResponsibilities(string);
    bool canSetMonths(string);

  private:
    string responsibilities;
    string startDate;
    string endDate;
    int months

};













