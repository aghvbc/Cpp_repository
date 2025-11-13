#include <iostream>
#include <string>
#include <cmath>
#include <vector>
#include <fstream>

class FileLogger{
public:
    FileLogger(std::string filename){
        file_stream = new std::ofstream(filename);
    };
private:
    std::ofstream* file_stream;
public:
    ~FileLogger(){
        if (file_stream){
            file_stream->close();
            delete file_stream;
        };
    };

    void log(const std::string& message){
        if (file_stream){
            *file_stream << message << std::endl;
        }
    };
};

int main(){
    FileLogger logger("test.log");
    logger.log("Start program");
    {FileLogger logger2("test2.log"); logger2.log("inside block");};
    logger.log("End program");
};