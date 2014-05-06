CC= arm-none-linux-gnueabi-gcc

cgi-bin/iwlist.cgi: iwlist.cgi.o
	$(CC) $^ -o $@

cgi-bin/hello.cgi: hello.cgi.o
	$(CC) $^ -o $@


install: cgi-bin/iwlist.cgi cgi-bin/iwlist index.html sta.html 
	cp $^ /var/lib/tftpboot/
	cp $^ ~/www/
	


