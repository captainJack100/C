#include <iostream>
#include <curl/curl.h>
#include <string>
#include <cstdlib>
#include <cstdio>

#define URL "PUT URL HERE"

using namespace std;

size_t write_data(void *ptr, size_t size, size_t nmeb, FILE *stream)
{
	return fwrite(ptr,size,nmeb,stream);
}

size_t read_data(void *ptr, size_t size, size_t nmeb, FILE *stream)
{
	return fread(ptr,size,nmeb,stream);
}

int sendRequest(char *infile, char *outfile)
{
	FILE *rfp = fopen(infile, "r");
	if (!rfp)
	{
		perror("Read file open");
		exit(0);
	}

	FILE *wfp = fopen(outfile, "w+");
	if (!wfp)
	{
		perror("Write File Open:");
		exit(0);
	}
	
	CURL *curl;
	CURLcode res;
	curl = curl_easy_init();

	if(curl)
	{
		struct curl_slist *header = NULL;
		header = curl_slist_append(header, "Content-Type:application/soap+xml;charset=utf-8");

		curl_easy_setopt(curl, CURLOPT_READFUNCTION, fread);
		curl_easy_setopt(curl, CURLOPT_READDATA, rfp);
		curl_easy_setopt(curl, CURLOPT_WRITEFUNCTION, fwrite);
		curl_easy_setopt(curl, CURLOPT_WRITEDATA, wfp);
	
		fseek(rfp, 0, SEEK_END);
		int size = ftell(rfp);
		fseek(rfp, 0, SEEK_SET);
		cout << "SIZE: " << size << endl;

		curl_easy_setopt(curl, CURLOPT_VERBOSE,1L);
		curl_easy_setopt(curl, CURLOPT_HTTPHEADER, header);
		curl_easy_setopt(curl, CURLOPT_POST, 1L);
		curl_easy_setopt(curl, CURLOPT_POSTFIELDSIZE, size);
		curl_easy_setopt(curl, CURLOPT_URL, URL);

		res = curl_easy_perform(curl);
		curl_easy_cleanup(curl);
		curl_slist_free_all(header);
	}

	return 0;
}

int main(void)
{

	sendRequest("request.xml", "out");	
	
	return 0;
}
