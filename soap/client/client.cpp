#include "soapcalcProxy.h"
#include "calc.nsmap"


int main()
{ calc c; /* calc object */
  

  double n; /* result value */

  if (c.sub(2, 3, &n) == SOAP_OK)
    std::cout << "2 plus 3 is " << n << std::endl;
  else
    soap_print_fault(c.soap, stderr); 


  return 0;
}
