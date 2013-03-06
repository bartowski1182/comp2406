#include "WorkExp.h"
#include <sstream>
using namespace std;
WorkExp::WorkExp(std::string res, string m, std::string sd, std::string ed) : responsibilities(res), months(m), 
	startDate(sd), endDate(ed)
{

}

WorkExp::~WorkExp(){

}

string WorkExp::getResponsibilities()
{
  return responsibilities;
}

string WorkExp::getStartDate()
{
  return startDate;
}

string WorkExp::getEndDate()
{
  return endDate;
}

string WorkExp::print()
{
  std::stringstream out;
  out << months;
  return responsibilities + "#" + out.str() + "#" + startDate + "#" + endDate;
}

string WorkExp::getMonths()
{
  return months;
}

bool WorkExp::canSetResponsibilities(string res)
{
  if (res.size() == 0)
    return false;

  return true;
}

bool WorkExp::canSetMonths(string m)
{

  if(m.size() == 0)
    return false;

  string numbers = "1234567890";

  if(m.find_first_not_of(numbers) != string::npos)
    return false;

  return true;

}













