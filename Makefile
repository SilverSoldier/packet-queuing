CC=g++
OBJ = main.o args.o simulation.o
LDFLAGS = -g -Wall

%.o: %.cpp %.h
	$(CC) $(LDFLAGS) -c -o $@ $< 

main: $(OBJ)
	$(CC) $(LDFLAGS) -o $@ $^

clean:
	rm main *.o
