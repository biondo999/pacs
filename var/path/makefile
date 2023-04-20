MY_INCLUDE=$$HOME/pacs/pacs-examples/Examples/include
OTHER_INCLUDE1=$$HOME/pacs-examples/Examples/include/muparserx
OTHER_INCLUDE2=$$HOME/Work/pacs/PACSCourse/Material/Examples/include

.PHONY:	all
all:	main

main:	main.o
	@g++ -o $@ $^
			
%.o: %.cpp
		        @g++ -c $< -I$(MY_INCLUDE) -I$(OTHER_INCLUDE1) -I$(OTHER_INCLUDE2) -o $@
		        
.PHONY:	clear		      
clear:	
	@rm -f *.dat
	@rm -f *.o
	@rm -f main
		

