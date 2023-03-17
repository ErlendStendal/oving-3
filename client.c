#include <mosquitto.h>
#include <stdio.h>
#include <string.h>

void on_message(struct mosquitto *mosq, void *obj, const struct mosquitto_message *msg)
{
    
    printf("Received message on topic '%s': %s\n", msg->topic, (char *) msg->payload);
}

int main(){
    mosquitto_lib_init();
    struct mosquitto * client = mosquitto_new(NULL, true, NULL);
    mosquitto_message_callback_set(client, on_message);
    mosquitto_connect(client,"localhost", 1883, 360);
    mosquitto_subscribe(client, NULL, "Testing", 0);
    mosquitto_loop_start(client);
    getchar();
    mosquitto_disconnect(client);
    mosquitto_destroy(client);
    mosquitto_lib_cleanup();
    return 0;
}