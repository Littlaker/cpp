#ifndef MODULE_H
#define MODULE_H

#include <string>
#include <memory>
#include "api.h"

namespace library {

class MODULE_LOCAL Module 
{
public:
    Module(std::string name, std::string version);
    ~Module();

    Module(const Module&) = delete;
    Module& operator=(const Module&) = delete; 

    Module(Module&&) = delete;
    Module& operator=(Module&&) = delete;

    std::string getModuleName() const;
    std::string getModuleVersion() const;

    void printModuleInfo() const;
private:    
    class ModuleImpl;
    std::unique_ptr<ModuleImpl> impl_;
};

} // !namespace library

#endif // !MODULE_H