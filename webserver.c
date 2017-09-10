#include <stdio.h>
#include <stdlib.h>
#include "libuv/include/uv.h"

static uv_tcp_t server;

int main() {

	uv_loop_t *loop= uv_default_loop();
	uv_tcp_init(loop,&server);
	printf("Hello world !\n");
}
