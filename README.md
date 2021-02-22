# CoursePlanner

In this project, we implemented an automatic course planner for a curriculum semester of a department. In the curriculum, there are several courses for each year of the curriculum. Our program assigns a classroom and a time slot for each course in the curriculum. Courses in the same year don't intersect with each other (i.e., see CENG Spring curriculum). There is some intersection between courses of different years. There are 2 different types of classroom; big and small. Mandatory courses in the curriculum assigned to a big classroom. Elective courses are assigned to a big or small classroom according to the availability of them. There is a limited number of dedicated classrooms for the department. The number of each type of classroom is read from a file. 

In the department curriculum, some service courses are given by another department at the university. The time slot of these courses is fixed and predefined. Therefore, students can not assign different time slots for those courses other than the requested time slot. Furthermore, some instructors do not available for some time slots. Thus, our program respects these busy time slots for the respective courses. All of these constraints are taken from a file.

In the end, our program produces a file that contains a course schedule for the department. In this schedule, there is not any intersection between courses for a year of the curriculum and respect to all constraints. If our program can not find any possible schedule it will print a message “There is no way to make a perfect schedule for the department.” 

Finally, we implemented a GUI system that can take inputs directly from the user instead of reading them from a file. 

