.PHONY: install uninstall

install:
	cp ./vantage-cli /usr/bin/vantage-cli
	chmod a+rx /usr/bin/vantage-cli

uninstall:
	rm -f /usr/bin/vantage-cli