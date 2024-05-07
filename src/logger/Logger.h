#include <string>
#include <fstream>
#include <mutex>

// Class
class Logger
{
public:
    Logger(const std::string &filename);
    ~Logger();
    void log(const std::string &message);

private:
    std::ofstream fileStream;
    std::mutex mtx;
};
