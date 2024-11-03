.PHONY: install uninstall

install:
	gcc -o vantage-cli vantage-cli.c
	cp ./vantage-cli /usr/bin/vantage-cli
	chmod a+rx /usr/bin/vantage-cli

uninstall:
	rm -f /usr/bin/vantage-cli