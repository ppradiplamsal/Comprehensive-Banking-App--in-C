banksystem: main.o customer.o administrator.o
	gcc -o banksystem main.o customer.o administrator.o

main.o: Main.c Administrator.h Customer.h Struct.h
	gcc -c main.c

customer.o: Customer.c Customer.h Struct.h
	gcc -c Customer.c

administrator.o: Administrator.c Administrator.h Struct.h
	gcc -c Administrator.c

clean:
	rm *.o banksystem
