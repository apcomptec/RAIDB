#ifndef LOGS_H
#define LOGS_H

#include <fstream>
using namespace std;
#define STRINGIFY(x) #x
#define TOSTRING(x) STRINGIFY(x)
#define AT __FILE__ ":" TOSTRING(__LINE__)

class Logs
{
public:
    Logs();
    void logs(const char *location, const char *msg);
};

#endif // LOGS_H
