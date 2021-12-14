#include "client.h"

int main(int n, char **args)
{
    send_binary(65, ft_atoi(args[1]));
}
