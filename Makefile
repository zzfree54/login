CC= arm-none-linux-gnueabi-gcc


all: cgi-bin/iwlist.cgi


cgi-bin/iwlist.cgi: iwlist.cgi.o
	$(CC) $^ -o $@

cgi-bin/hello.cgi: hello.cgi.o
	$(CC) $^ -o $@


arminstall: cgi-bin/iwlist.cgi cgi-bin/iwlist refresh.png
	cp $^ $(CGIBIN)
	cp index.html sta.html $(BOA)
	@echo "modify boa conf DocumentRoot/index.html" 

insta11: cgi-bin/iwlist.cgi cgi-bin/iwlist index.html sta.html 
	cp $^ /var/lib/tftpboot/
	cp $^ ~/www/
	


