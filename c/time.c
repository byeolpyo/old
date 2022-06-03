/* parse datetime from a server; json file that is received from the server is parsed using just string manipulation */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <curl/curl.h>

size_t data(char *buffer, size_t itemsize, size_t nitems, void* ignorethis) {
    size_t bytes = itemsize * nitems;
    char* start;
    if ((start = strstr(buffer, "datetime")) != NULL) {
    	start += strlen("datetime\":\"");
	    int i;
    	char date[20];
    	strncpy(date, start, 19);
    	date[10] = ' ';
    	printf("%s", date);
    }
    
    return bytes;
}

int main(void) {    
    CURL *curl = curl_easy_init();

    if(!curl) {
	    fprintf(stderr, "Failed to initialize curl\n");
    	return 1;
    }

    curl_easy_setopt(curl, CURLOPT_URL, "http://worldtimeapi.org/api/ip");
    curl_easy_setopt(curl, CURLOPT_WRITEFUNCTION, data);
    CURLcode res = curl_easy_perform(curl);
    if(res != CURLE_OK) {
	    fprintf(stderr, "Failed to download file: problem %s\n", curl_easy_strerror(res));
    }
    curl_easy_cleanup(curl);
    putchar('\n');
    return 0;
    
}
