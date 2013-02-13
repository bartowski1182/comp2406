

RelatedCourse::RelatedCourse(string cc, string tm, int yr, int fg) 
	: courseCode(cc), term(tm), year(yr), finalGrade(fg)
{

	cout<<"RelatedCourse constructor" << endl;

}

RelatedCourse::~RelatedCourse()
{

	cout<<"RelatedCourse deconstructor" << endl;

}

string RelatedCourse::getCourseCode()
{

	return courseCode;

}

string RelatedCourse::print()
{

	return courseCode;

}