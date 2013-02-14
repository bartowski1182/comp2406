OBJECTS = main.o Form.o CourseRelatedQueue.o Student.o Cutaes.o CourseRelated.o

cutaes:			$(OBJECTS)
			g++ -o cutaes $(OBJECTS) -lncurses

main.o:			main.cpp Form.h Cutaes.h
			g++ -c main.cpp -lncurses

Cutaes.o:		Cutaes.cpp Cutaes.h
			g++ -c Cutaes.cpp -lncurses
	
Form.o:			Form.cpp Form.h
			g++ -c Form.cpp -lncurses

CourseRelatedQueue.o:	CourseRelatedQueue.cpp CourseRelatedQueue.h CourseRelated.h
			g++ -c CourseRelatedQueue.cpp

CourseRelated.o:	CourseRelated.cpp CourseRelated.h
			g++ -c CourseRelated.cpp

Student.o:		Student.cpp Student.h
			g++ -c Student.cpp


clean: 		
			rm -f *.o cutaes	
