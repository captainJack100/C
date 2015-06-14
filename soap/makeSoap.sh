# does the initial soap stuff

wsdl2h -s -o calc.h calc.wsdl
soapcpp2 -i calc.h
