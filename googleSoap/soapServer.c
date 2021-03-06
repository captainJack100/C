/* soapServer.c
   Generated by gSOAP 2.8.16 from googleapi.h

Copyright(C) 2000-2013, Robert van Engelen, Genivia Inc. All Rights Reserved.
The generated code is released under one of the following licenses:
GPL or Genivia's license for commercial use.
This program is released under the GPL with the additional exemption that
compiling, linking, and/or using OpenSSL is allowed.
*/

#if defined(__BORLANDC__)
#pragma option push -w-8060
#pragma option push -w-8004
#endif
#include "soapH.h"
#ifdef __cplusplus
extern "C" {
#endif

SOAP_SOURCE_STAMP("@(#) soapServer.c ver 2.8.16 2015-06-14 03:52:52 GMT")


SOAP_FMAC5 int SOAP_FMAC6 soap_serve(struct soap *soap)
{
#ifndef WITH_FASTCGI
	unsigned int k = soap->max_keep_alive;
#endif
	do
	{
#ifndef WITH_FASTCGI
		if (soap->max_keep_alive > 0 && !--k)
			soap->keep_alive = 0;
#endif
		if (soap_begin_serve(soap))
		{	if (soap->error >= SOAP_STOP)
				continue;
			return soap->error;
		}
		if (soap_serve_request(soap) || (soap->fserveloop && soap->fserveloop(soap)))
		{
#ifdef WITH_FASTCGI
			soap_send_fault(soap);
#else
			return soap_send_fault(soap);
#endif
		}

#ifdef WITH_FASTCGI
		soap_destroy(soap);
		soap_end(soap);
	} while (1);
#else
	} while (soap->keep_alive);
#endif
	return SOAP_OK;
}

#ifndef WITH_NOSERVEREQUEST
SOAP_FMAC5 int SOAP_FMAC6 soap_serve_request(struct soap *soap)
{
	soap_peek_element(soap);
	if (!soap_match_tag(soap, soap->tag, "api:doGoogleSearch"))
		return soap_serve_api__doGoogleSearch(soap);
	if (!soap_match_tag(soap, soap->tag, "api:doGetCachedPage"))
		return soap_serve_api__doGetCachedPage(soap);
	if (!soap_match_tag(soap, soap->tag, "api:doSpellingSuggestion"))
		return soap_serve_api__doSpellingSuggestion(soap);
	return soap->error = SOAP_NO_METHOD;
}
#endif

SOAP_FMAC5 int SOAP_FMAC6 soap_serve_api__doGoogleSearch(struct soap *soap)
{	struct api__doGoogleSearch soap_tmp_api__doGoogleSearch;
	struct api__doGoogleSearchResponse response;
	soap_default_api__doGoogleSearchResponse(soap, &response);
	soap_default_api__doGoogleSearch(soap, &soap_tmp_api__doGoogleSearch);
	if (!soap_get_api__doGoogleSearch(soap, &soap_tmp_api__doGoogleSearch, "api:doGoogleSearch", NULL))
		return soap->error;
	if (soap_body_end_in(soap)
	 || soap_envelope_end_in(soap)
	 || soap_end_recv(soap))
		return soap->error;
	soap->error = api__doGoogleSearch(soap, soap_tmp_api__doGoogleSearch.key, soap_tmp_api__doGoogleSearch.q, soap_tmp_api__doGoogleSearch.start, soap_tmp_api__doGoogleSearch.maxResults, soap_tmp_api__doGoogleSearch.filter, soap_tmp_api__doGoogleSearch.restrict_, soap_tmp_api__doGoogleSearch.safeSearch, soap_tmp_api__doGoogleSearch.lr, soap_tmp_api__doGoogleSearch.ie, soap_tmp_api__doGoogleSearch.oe, &response);
	if (soap->error)
		return soap->error;
	soap->encodingStyle = "";
	soap_serializeheader(soap);
	soap_serialize_api__doGoogleSearchResponse(soap, &response);
	if (soap_begin_count(soap))
		return soap->error;
	if (soap->mode & SOAP_IO_LENGTH)
	{	if (soap_envelope_begin_out(soap)
		 || soap_putheader(soap)
		 || soap_body_begin_out(soap)
		 || soap_put_api__doGoogleSearchResponse(soap, &response, "api:doGoogleSearchResponse", NULL)
		 || soap_body_end_out(soap)
		 || soap_envelope_end_out(soap))
			 return soap->error;
	};
	if (soap_end_count(soap)
	 || soap_response(soap, SOAP_OK)
	 || soap_envelope_begin_out(soap)
	 || soap_putheader(soap)
	 || soap_body_begin_out(soap)
	 || soap_put_api__doGoogleSearchResponse(soap, &response, "api:doGoogleSearchResponse", NULL)
	 || soap_body_end_out(soap)
	 || soap_envelope_end_out(soap)
	 || soap_end_send(soap))
		return soap->error;
	return soap_closesock(soap);
}

SOAP_FMAC5 int SOAP_FMAC6 soap_serve_api__doGetCachedPage(struct soap *soap)
{	struct api__doGetCachedPage soap_tmp_api__doGetCachedPage;
	struct api__doGetCachedPageResponse soap_tmp_api__doGetCachedPageResponse;
	struct xsd__base64Binary soap_tmp_xsd__base64Binary;
	soap_default_api__doGetCachedPageResponse(soap, &soap_tmp_api__doGetCachedPageResponse);
	soap_default_xsd__base64Binary(soap, &soap_tmp_xsd__base64Binary);
	soap_tmp_api__doGetCachedPageResponse._return = &soap_tmp_xsd__base64Binary;
	soap_default_api__doGetCachedPage(soap, &soap_tmp_api__doGetCachedPage);
	if (!soap_get_api__doGetCachedPage(soap, &soap_tmp_api__doGetCachedPage, "api:doGetCachedPage", NULL))
		return soap->error;
	if (soap_body_end_in(soap)
	 || soap_envelope_end_in(soap)
	 || soap_end_recv(soap))
		return soap->error;
	soap->error = api__doGetCachedPage(soap, soap_tmp_api__doGetCachedPage.key, soap_tmp_api__doGetCachedPage.url, soap_tmp_api__doGetCachedPageResponse._return);
	if (soap->error)
		return soap->error;
	soap->encodingStyle = "";
	soap_serializeheader(soap);
	soap_serialize_api__doGetCachedPageResponse(soap, &soap_tmp_api__doGetCachedPageResponse);
	if (soap_begin_count(soap))
		return soap->error;
	if (soap->mode & SOAP_IO_LENGTH)
	{	if (soap_envelope_begin_out(soap)
		 || soap_putheader(soap)
		 || soap_body_begin_out(soap)
		 || soap_put_api__doGetCachedPageResponse(soap, &soap_tmp_api__doGetCachedPageResponse, "api:doGetCachedPageResponse", NULL)
		 || soap_body_end_out(soap)
		 || soap_envelope_end_out(soap))
			 return soap->error;
	};
	if (soap_end_count(soap)
	 || soap_response(soap, SOAP_OK)
	 || soap_envelope_begin_out(soap)
	 || soap_putheader(soap)
	 || soap_body_begin_out(soap)
	 || soap_put_api__doGetCachedPageResponse(soap, &soap_tmp_api__doGetCachedPageResponse, "api:doGetCachedPageResponse", NULL)
	 || soap_body_end_out(soap)
	 || soap_envelope_end_out(soap)
	 || soap_end_send(soap))
		return soap->error;
	return soap_closesock(soap);
}

SOAP_FMAC5 int SOAP_FMAC6 soap_serve_api__doSpellingSuggestion(struct soap *soap)
{	struct api__doSpellingSuggestion soap_tmp_api__doSpellingSuggestion;
	struct api__doSpellingSuggestionResponse soap_tmp_api__doSpellingSuggestionResponse;
	char * soap_tmp_xsd__string;
	soap_default_api__doSpellingSuggestionResponse(soap, &soap_tmp_api__doSpellingSuggestionResponse);
	soap_tmp_xsd__string = NULL;
	soap_tmp_api__doSpellingSuggestionResponse._return = &soap_tmp_xsd__string;
	soap_default_api__doSpellingSuggestion(soap, &soap_tmp_api__doSpellingSuggestion);
	if (!soap_get_api__doSpellingSuggestion(soap, &soap_tmp_api__doSpellingSuggestion, "api:doSpellingSuggestion", NULL))
		return soap->error;
	if (soap_body_end_in(soap)
	 || soap_envelope_end_in(soap)
	 || soap_end_recv(soap))
		return soap->error;
	soap->error = api__doSpellingSuggestion(soap, soap_tmp_api__doSpellingSuggestion.key, soap_tmp_api__doSpellingSuggestion.phrase, soap_tmp_api__doSpellingSuggestionResponse._return);
	if (soap->error)
		return soap->error;
	soap->encodingStyle = "";
	soap_serializeheader(soap);
	soap_serialize_api__doSpellingSuggestionResponse(soap, &soap_tmp_api__doSpellingSuggestionResponse);
	if (soap_begin_count(soap))
		return soap->error;
	if (soap->mode & SOAP_IO_LENGTH)
	{	if (soap_envelope_begin_out(soap)
		 || soap_putheader(soap)
		 || soap_body_begin_out(soap)
		 || soap_put_api__doSpellingSuggestionResponse(soap, &soap_tmp_api__doSpellingSuggestionResponse, "api:doSpellingSuggestionResponse", NULL)
		 || soap_body_end_out(soap)
		 || soap_envelope_end_out(soap))
			 return soap->error;
	};
	if (soap_end_count(soap)
	 || soap_response(soap, SOAP_OK)
	 || soap_envelope_begin_out(soap)
	 || soap_putheader(soap)
	 || soap_body_begin_out(soap)
	 || soap_put_api__doSpellingSuggestionResponse(soap, &soap_tmp_api__doSpellingSuggestionResponse, "api:doSpellingSuggestionResponse", NULL)
	 || soap_body_end_out(soap)
	 || soap_envelope_end_out(soap)
	 || soap_end_send(soap))
		return soap->error;
	return soap_closesock(soap);
}

#ifdef __cplusplus
}
#endif

#if defined(__BORLANDC__)
#pragma option pop
#pragma option pop
#endif

/* End of soapServer.c */
