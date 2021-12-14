#ifndef CLIENT_H

#define CLIENT_H
#ifndef LAG
#define LAG 500
#endif
#include <unistd.h>
#include <stdlib.h>
#include <signal.h>
#include "../utils/ft_printf/includes/ft_printf.h"
#include "../utils/utils.h"
void send_binary(int c, int pid);

#endif
