#include "clientmultiple.h"

int main()
{
    ClientMultiple* client = new ClientMultiple();
    client->addIPAdrress("192.168.0.105", 9888);
    client->addIPAdrress("192.168.0.105", 9999);
    client->start();

    return 0;
}

