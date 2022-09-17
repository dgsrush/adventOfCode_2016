OBJS=\
	main.o

CFLGS=-c -mconsole -O2

LIBS=

day6.exe : $(OBJS) $(INCS)
	g++ -o day6.exe -mconsole $(OBJS) $(LIBS)

main.o : main.cpp $(INCS)
	g++ $(CFLGS) main.cpp

clean :
	rm *.o
