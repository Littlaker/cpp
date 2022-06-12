#include "module.h"

namespace library {

class Module::ModuleImpl
{
public:
    ModuleImpl(std::string name, std::string version)
        :name_(name)
        ,version_(version)
    {
    }

    inline std::string getModuleName() const
    {
        return name_;
    }

    inline std::string getModuleVersion() const
    {
        return version_;
    }

    inline void printModuleInfo() const
    {
        printf("name: %s, version: %s\n", name_.c_str(), version_.c_str());
    }
private:
    std::string name_;
    std::string version_;
};

Module::Module(std::string name, std::string version)
    :impl_(new ModuleImpl(name, version))
{
}

Module::~Module() = default;

std::string Module::getModuleName() const
{
    if (impl_)
    {
        return impl_->getModuleName();
    }    
    return "";
}

std::string Module::getModuleVersion() const
{
    if (impl_)
    {
        return impl_->getModuleVersion();
    }
    return "";
}

void Module::printModuleInfo() const
{
    if (impl_)
    {
        impl_->printModuleInfo();
    }
}

} // !namespace library
