# Makefile - Smart Home Automation Rule Engine

CC      = gcc
CFLAGS  = -w

TARGET  = smarthome

all: $(TARGET)

# Step 1: Generate y.tab.c and y.tab.h from the Yacc file
y.tab.c y.tab.h: smarthome.y
	bison -d -o y.tab.c smarthome.y

# Step 2: Generate lex.yy.c from the Lex file
lex.yy.c: smarthome.l y.tab.h
	flex -o lex.yy.c smarthome.l

# Step 3: Compile y.tab.c into y.tab.o (object file)
y.tab.o: y.tab.c y.tab.h
	$(CC) $(CFLAGS) -c y.tab.c -o y.tab.o

# Step 4: Compile lex.yy.c into lex.yy.o (object file)
lex.yy.o: lex.yy.c y.tab.h
	$(CC) $(CFLAGS) -c lex.yy.c -o lex.yy.o

# Step 5: Link both object files into the final executable
$(TARGET): y.tab.o lex.yy.o
	$(CC) $(CFLAGS) -o $(TARGET) y.tab.o lex.yy.o -lfl

run: $(TARGET)
	./$(TARGET) < input.txt

output: $(TARGET)
	./$(TARGET) < input.txt > output.txt

clean:
	rm -f $(TARGET) y.tab.c y.tab.h lex.yy.c y.tab.o lex.yy.o

.PHONY: all run output clean
