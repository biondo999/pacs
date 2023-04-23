MY_INCLUDE=$$HOME/pacs/pacs-examples/Examples/include
OTHER_INCLUDE1=$$HOME/pacs-examples/Examples/include
OTHER_INCLUDE2=$$HOME/Work/pacs/PACSCourse/Material/Examples/include

LIB_PATH=$$HOME/pacs/pacs-examples/Examples/lib
LIB_PATH1=$$HOME/pacs-examples/Examples/lib
LIB_PATH2=$$HOME/Work/pacs/PACSCourse/Material/Examples/include



TARGET := main
SRCS := $(wildcard *.cpp)
OBJS := $(patsubst %.cpp,%.o,$(SRCS))


.PHONY:	all
all:	$(TARGET)

$(TARGET):	$(OBJS)
	@g++ -o $@ $^ -Wl,-rpath=. -Wl,-rpath=$(LIB_PATH) -g -L$(LIB_PATH)  -lmuparser
			
%.o:	%.cpp
	@g++ -fconcepts -c $< -I$(MY_INCLUDE) -I$(OTHER_INCLUDE1) -I$(OTHER_INCLUDE2) -o $@
		        
.PHONY:	clear		      
clear:	
	@rm -f *.dat
	@rm -f *.o
	@rm -f main
