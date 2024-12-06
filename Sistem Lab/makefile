CC = gcc
CFLAGS = -Wall -g
OBJ = main.o login.o lihatList.o return.o lihatpinjam.o pinjamAlat.o tambahdata.o hapusData.o editData.o

all: lab

lab: $(OBJ)
	$(CC) $(CFLAGS) -o lab $(OBJ)

main.o: main.c header.h
	$(CC) $(CFLAGS) -c main.c

login.o: login.c header.h
	$(CC) $(CFLAGS) -c login.c

lihatList.o: lihatList.c header.h
	$(CC) $(CFLAGS) -c lihatList.c

return.o: return.c header.h
	$(CC) $(CFLAGS) -c return.c

lihatpinjam.o: lihatpinjam.c header.h
	$(CC) $(CFLAGS) -c lihatpinjam.c

pinjamAlat.o: pinjamAlat.c header.h
	$(CC) $(CFLAGS) -c pinjamAlat.c

tambahdata.o: tambahdata.c header.h
	$(CC) $(CFLAGS) -c tambahdata.c


hapusData.o: hapusData.c header.h
	$(CC) $(CFLAGS) -c hapusData.c

editData.o: editData.c header.h
	$(CC) $(CFLAGS) -c editData.c

clean:
	rm -f *.o lab