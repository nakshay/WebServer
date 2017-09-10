#include <stdio.h>
#include <stdlib.h>
#include "libuv/include/uv.h"

static uv_tcp_t server;



void on_connection (uv_stream_t* server, int status) {


}

int main() {

	uv_loop_t *loop= uv_default_loop();
	uv_tcp_init(loop,&server);

  	struct sockaddr_in addr;

  	uv_ip4_addr("0.0.0.0", 0, &addr);

    uv_tcp_bind(&server, (const struct sockaddr*)&addr, 0);

	printf("Hello world !\n");

	int r = uv_listen((uv_stream_t*) &server, 8000, on_connection);
    if (r) {
        fprintf(stderr, "Listen error %s\n", uv_strerror(r));
        return -1;
    } 
    return uv_run(loop, UV_RUN_DEFAULT);
}
