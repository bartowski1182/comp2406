OBJECTS = main.o Mainmenu.o Form.o Cutaes.o CutaesStudentMenu.o CutaesAdminMenu.o USGenInfo.o RCourses.o TCourses.o RWExp.o CourseRelated.o CourseRelatedQueue.o Course.o Application.o ApplicationQueue.o ApplicationIO.o WorkExp.o WorkExpQueue.o TaCourse.o TaCourseQueue.o Student.o UndergradStudent.o CourseLoader.o

cutaes:			$(OBJECTS)
			g++ -o cutaes $(OBJECTS) -lncurses

main.o:			main.cpp Mainmenu.h
			g++ -c main.cpp

Cutaes.o:		Cutaes.cpp Cutaes.h CutaesStudentMenu.h CutaesAdminMenu.h
			g++ -c Cutaes.cpp

Mainmenu.o:		Mainmenu.cpp Mainmenu.h CutaesStudentMenu.h CutaesAdminMenu.h
			g++ -c Mainmenu.cpp

CutaesStudentMenu.o:	CutaesStudentMenu.cpp CutaesStudentMenu.h ApplicationQueue.h Form.h
			g++ -c CutaesStudentMenu.cpp
	
CutaesAdminMenu.o:	CutaesAdminMenu.cpp CutaesAdminMenu.h ApplicationQueue.h
			g++ -c CutaesAdminMenu.cpp

Form.o:			Form.cpp Form.h GenInfo.h RCourses.h TCourses.h RWExp.h Student.h CourseRelatedQueue.h TaCourseQueue.h WorkExpQueue.h
			g++ -c Form.cpp

USGenInfo.o:		USGenInfo.cpp USGenInfo.h Student.h CourseLoader.h UndergradStudent.h
			g++ -c USGenInfo.cpp

RCourses.o:		RCourses.cpp RCourses.h
			g++ -c RCourses.cpp

TCourses.o:		TCourses.cpp TCourses.h
			g++ -c TCourses.cpp

RWExp.o:		RWExp.cpp RWExp.h
			g++ -c RWExp.cpp

ApplicationIO.o:	ApplicationIO.cpp ApplicationIO.h ApplicationQueue.h Application.h
			g++ -c ApplicationIO.cpp

Application.o:		Application.cpp Application.h Student.h ApplicationQueue.h CourseRelatedQueue.h Course.h
			g++ -c Application.cpp

ApplicationQueue.o:	ApplicationQueue.cpp ApplicationQueue.h Application.h
			g++ -c ApplicationQueue.cpp

CourseRelated.o:	CourseRelated.cpp CourseRelated.h
			g++ -c CourseRelated.cpp

CourseRelatedQueue.o:	CourseRelatedQueue.cpp CourseRelatedQueue.h CourseRelated.h
			g++ -c CourseRelatedQueue.cpp

TaCourse.o:		TaCourse.cpp TaCourse.h
			g++ -c TaCourse.cpp

TaCourseQueue.o:	TaCourseQueue.cpp TaCourseQueue.h TaCourse.h
			g++ -c TaCourseQueue.cpp

WorkExp.o:		WorkExp.cpp WorkExp.h
			g++ -c WorkExp.cpp

WorkExpQueue.o:		WorkExpQueue.cpp WorkExpQueue.h
			g++ -c WorkExpQueue.cpp

Course.o:		Course.cpp Course.h
			g++ -c Course.cpp

Student.o:		Student.cpp Student.h
			g++ -c Student.cpp

UndergradStudent.o:	UndergradStudent.cpp UndergradStudent.h Student.h
			g++ -c UndergradStudent.cpp

CourseLoader.o:		CourseLoader.cpp CourseLoader.h
			g++ -c CourseLoader.cpp

package: 
			tar -cvf assignment2.tar *.c *.h Makefile

clean: 		
			rm -f *.o cutaes
