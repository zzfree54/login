CC= arm-none-linux-gnueabi-gcc

cgi-bin/iwlist.cgi: iwlist.cgi.o
	$(CC) $^ -o $@

cgi-bin/hello.cgi: hello.cgi.o
	$(CC) $^ -o $@


install: cgi-bin/iwlist.cgi
	cp $^ /var/lib/tftpboot/
	


