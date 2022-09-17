OBJS=\
	main.o

CFLGS=-c -mconsole -O2

LIBS=libcryptopp.a

day5.exe : $(OBJS) $(INCS)
	g++ -o day5.exe -mconsole $(OBJS) $(LIBS)

main.o : main.cpp $(INCS)
	g++ $(CFLGS) main.cpp

clean :
	rm *.o
