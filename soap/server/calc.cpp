#include "soapH.h" /* get the gSOAP-generated definitions */
#include "calc.nsmap" /* get the gSOAP-generated namespace bindings */
#include <math.h>  
int main()  
{ 

int standalone = 1;

if (standalone) {

struct soap soap;
   int m, s; // master and slave sockets
   soap_init(&soap);
   m = soap_bind(&soap, NULL, 18083, 100);
   if (m < 0)
      soap_print_fault(&soap, stderr);
   else
   {
      fprintf(stderr, "Socket connection successful: master socket = %d\n", m);
      for (int i = 1; ; i++)
      {
         s = soap_accept(&soap);
         if (s < 0)
         {
            soap_print_fault(&soap, stderr);
            break;
         }
         fprintf(stderr, "%d: accepted connection from IP=%d.%d.%d.%d socket=%d", i,
            (soap.ip >> 24)&0xFF, (soap.ip >> 16)&0xFF, (soap.ip >> 8)&0xFF, soap.ip&0xFF, s);
         if (soap_serve(&soap) != SOAP_OK) // process RPC request
            soap_print_fault(&soap, stderr); // print error
         fprintf(stderr, "request served\n");
         soap_destroy(&soap); // clean up class instances
         soap_end(&soap); // clean up everything and close socket
      }
   }
   soap_done(&soap); // close master socket and detach context 

} else {


	return soap_serve(soap_new()); /* call the request dispatcher */  

}
}  
int ns__add(struct soap *soap, double a, double b, double *result)  
{ *result = a + b;  
  return SOAP_OK;  
}  
int ns__sub(struct soap *soap, double a, double b, double *result)  
{ *result = a - b;  
  return SOAP_OK;  
}  
int ns__sqrt(struct soap *soap, double a, double *result)  
{ if (a >= 0)  
  { *result = sqrt(a);  
    return SOAP_OK;  
  }  
  else 
    return soap_sender_fault(soap, "Square root of negative value", "I can only take the square root of non-negative values");    
}


