Team Infinite Tears
Yugo Brunet
100853306

Colin Kealty
100855810

Instructions and Comments:
	uses ncurses
	compile with "make"
	navigate through the menu by typing the appropriate keys - Because constrained by time

	Main Menu allows you to select between Student, Administrator or Quit
		Quit quits the program
		Student allows the student user to submit or edit an application
			edit application function not yet implemented

		Administrator allows the admin to select between many options
			only option the admin should be allowed to use is the view pending applications
	
	Student - submit application
		The submit application is split up into 5 parts, at any part, the user can cancel or 			"quit" the submission process in which case they're be redirected to the student menu.
			The first part is the General information submission, fill out all of the fields 			by navigating using the arrow keys and modify the fields by hitting "Enter", inserting 			information into the field and then confirming by hitting "Enter" once more. All of the 		text entry is done in this fashion.
			The second part is the Relevant Courses submission. Fill out the necessary 			fields. The third and fourth pages are very similar to this page in that you can choose 		to "Accept" or "Add". Adding will reset the form but will have added the information to 
		the application. Accept will also add the information to the application but will 			continue on to the next page. We understand that the form looks terrible but we tried to 			fit in as much functionality as we could.
			The last part is where the user is prompted to apply for another course. Should 		they choose yes, then the user will start from part 1 except all of the text fields will 			have been filled out.

	Admin - view pending applications
			The view pending applications will show a list of courses from which the admin 			will be	able to choose the course for which the applications are applying.
		
