#include "Logs.h"

Logs::Logs()
{
}
inline std::ofstream& logfile()
{
      static std::ofstream log("Logfile.log");
      return log;
}

void Logs::logs(const char *location, const char *msg)
{
    logfile()<<"Run Proyect"<<location<<":"<<msg<<"\n";
}
