MAKEFLAGS=-S

SOURCES			:=	$(wildcard *.cpp)
HEADERS			:=	$(wildcard *.h)
OBJECTS			=	$(SOURCES:.cpp=.o)
TARGET			=	$(shell basename $(CURDIR))

IPSERVERNAME 	= 	server
IPSERVER		=	server.cpp
IPSERVEROBJ		=	$(IPSERVER:.cpp=.o)

IPCLIENTNAME	=   client
IPCLIENT		=	client.cpp 
IPCLIENTOBJ		=	$(IPCLIENT:.cpp=.o)

TMS_BASE		?=	/usr/local
TMS_VERSION		?=	tms6

INSTALL_ROOT	?=  ./

RM				=	/bin/rm
RMFLAGS			=	-fR

STRIP			= 	/usr/bin/strip -s
INSTALL			=	/usr/bin/install
INSTALL_FLAGS	=	-m 0775 -D -s

CC		=	g++

ADD_USAGE =	/usr/local/bin/add_usage
ADD_TAG = /usr/local/bin/add_tag
ADD_VER = /usr/local/bin/add_version

INCDIRS	=	-I /usr/local/include \
            -I /usr/include 

LIBDIRS	=	-L /usr/local/lib		\
            -L /usr/lib   

LIBS	=	-lrt -lm -lz -lc 

CFLAGS	=	-DDEBUG -O0 -g -DCT_V7 -pipe -D__LINUX__	\
			-D__CPLUSPLUS__ -DPANEWFD -DPFPROTO -DPANSI	\
			-w -Wunused -Wformat
.PHONY : clean 

all: $(IPCLIENTNAME) $(IPSERVERNAME) 

$(IPCLIENTNAME): $(HEADERS) $(IPCLIENT) $(IPCLIENTOBJ)
	$(CC) -o client client.cpp soapcalcProxy.cpp soapC.cpp -lgsoap++

$(IPSERVERNAME): $(HEADERS) $(IPCLIENT) $(IPCLIENTOBJ)
	$(CC) -o server server.cpp soapcalcService.cpp soapC.cpp -lgsoap++

clean:
	$(RM) $(RMFLAGS) $(OBJECTS) $(IPCLIENTNAME) $(IPSERVERNAME)
