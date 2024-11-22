CFlAGS = -Wall -g
SRCS = $(wildcard *.c)
OBJS = $(SRCS:.c=.o)
TARGET = $(patsubst homework_%,%,$(notdir $(CURDIR)))
all: $(TARGET)
test:
	echo $(TARGET)
$(TARGET):$(OBJS)
	cc $(CFLAGS) $^ -o $@
%.o: %.c
	cc $(CFLAGS) -c $< -o $@
clean:
	rm -f $(OBJS) $(TARGET)
auto:
	rm -f $(OBJS) $(TARGET)
	cc $(FLAGS) $(SRCS) -o $(TARGET)
test2:
	echo $(SRCS)
	echo $(OBJS)
