#ifndef MODULE_H
#define MODULE_H

#include <string>
#include <memory>
#include "api.h"

namespace library {

class MODULE_API Module 
{
public:
    Module(std::string name, std::string version);
    ~Module();

    Module(const Module&) = delete;
    Module& operator=(const Module&) = delete; 

    Module(Module&&);
    Module& operator=(Module&&);

    std::string getModuleName() const;
    std::string getModuleVersion() const;

    void setModuleName(const std::string& name);
    void setModuleVersion(const std::string& name);

    void printModuleInfo() const;
private:    
    class ModuleImpl;
    std::unique_ptr<ModuleImpl> impl_;
};

} // !namespace library

#endif // !MODULE_H