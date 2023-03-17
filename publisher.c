#include <stdio.h>
#include <mosquitto.h>
#include <string.h>

int main()
{


    mosquitto_lib_init();

    struct mosquitto *publisher = mosquitto_new("publisher", true, NULL);


    mosquitto_connect(publisher, "localhost", 1883, 60);

    const char *payload = "Hello, world!";

    printf("Publishing message: %s\n", payload);
    for(int i = 0; i < 5; i++)
    {
        mosquitto_publish(publisher, NULL, "Testing", strlen(payload), payload, 0, false);
        sleep(1);    
    }
    
    

    mosquitto_destroy(publisher);
    mosquitto_lib_cleanup();
    
    return 0;
}