MY_INCLUDE=$$HOME/pacs/pacs-examples/Examples/include
OTHER_INCLUDE1=$$HOME/pacs-examples/Examples/lib
LIB_PATH=$$HOME/pacs/pacs-examples/Examples/lib

TARGET := main
SRCS := $(wildcard *.cpp)
OBJS := $(patsubst %.cpp,%.o,$(SRCS))


.PHONY:	all
all:	$(TARGET)

$(TARGET): $(OBJS)
	@g++ -Wl,-rpath=. -Wl,-rpath=$(LIB_PATH) -g   $< -L$(LIB_PATH)  -lmuparser -o main
			
$(OBJS): $(SRCS)
		        @g++ -fconcepts -c $< -I$(MY_INCLUDE) -I$(OTHER_INCLUDE1) -o $@
		        
.PHONY:	clear		      
clear:	
	@rm -f *.dat
	@rm -f *.o
	@rm -f main
	

