#include <stdio.h>
#include <string.h>
#include <curl/curl.h>

int main(){
	
	CURL *curl;
	CURLcode res;

	static const char *postthis="api_key=P7UOC5M1K1JP5LOH&field1=90&field2=90";	
	curl = curl_easy_init();	
	struct curl_slist *chunk = NULL;
	chunk = curl_slist_append(chunk,"Content-type:application/x-www-form-urlencoded");
	 res = curl_easy_setopt(curl, CURLOPT_HTTPHEADER, chunk);
	 curl_easy_setopt(curl, CURLOPT_URL, "http://api.thingspeak.com/update.json");
	 
	 curl_easy_setopt(curl, CURLOPT_POSTFIELDS, postthis);
	 curl_easy_setopt(curl, CURLOPT_POSTFIELDSIZE, (long)strlen(postthis));
	 
	 res = curl_easy_perform(curl);
	 
	 if(res != CURLE_OK)
      fprintf(stderr, "curl_easy_perform() failed: %s\n", curl_easy_strerror(res));
              
     curl_easy_cleanup(curl);
     return 0;
}
