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
        std::ofstream fileStream;

    private:
        std::mutex mtx;
};
