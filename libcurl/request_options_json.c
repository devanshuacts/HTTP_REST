#include <stdio.h>
#include <string.h>
#include <curl/curl.h>
#include <json/json.h>

int main(){
	char *jptr;
	json_object *job1 = json_object_new_object();
	json_object *jvalue = json_object_new_string("P7UOC5M1K1JP5LOH");
	json_object_object_add(job1, "api_key", jvalue);
	 
	json_object *jvalue1 = json_object_new_int(37);
	json_object *jvalue2 = json_object_new_int(36);
	json_object_object_add(job1, "field1", jvalue1);
	json_object_object_add(job1, "field2", jvalue2);
	
	jptr = json_object_to_json_string(job1);
	
	printf("%s\n", jptr);
	
	CURL *curl;
	CURLcode res;
	
	curl = curl_easy_init();	
	struct curl_slist *chunk = NULL;
	chunk = curl_slist_append(chunk,"Content-type:application/json");
	 res = curl_easy_setopt(curl, CURLOPT_HTTPHEADER, chunk);
	 curl_easy_setopt(curl, CURLOPT_URL, "http://api.thingspeak.com/update.json");
	 
	 curl_easy_setopt(curl, CURLOPT_POSTFIELDS, jptr);
	 curl_easy_setopt(curl, CURLOPT_POSTFIELDSIZE, (long)strlen(jptr));
	 
	 res = curl_easy_perform(curl);
	 
	 if(res != CURLE_OK)
      fprintf(stderr, "curl_easy_perform() failed: %s\n", curl_easy_strerror(res));
              
     curl_easy_cleanup(curl);
     return 0;
}
