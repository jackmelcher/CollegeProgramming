# Makefile:
# 2/13/15 by RD

all: ClockClient ClockServer

clean:
	rm -rf ClockClient ClockServer

test:
	@echo "To run the examples, ....first start the server in one terminal,"
	@echo "then start the client in another."
	@echo
	@echo "For example:"
	@echo "crystalcove# server 10000"
	@echo "crystalcove# client crystalcove 10000"

ClockClient: ClockClient.c
	gcc ClockClient.c -Wall -ansi -g -o ClockClient

ClockServer: ClockServer.c
	gcc ClockServer.c -Wall -ansi -g -o ClockServer

# EOF
