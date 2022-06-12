#include "module.h"
#include <utility>

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

    inline void setModuleName(const std::string& name)
    {
        name_ = name;
    }

    inline void setModuleVersion(const std::string& version)
    {
        version_ = version;
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

Module::Module::Module(Module&& rhs)
{
    impl_ = std::move(rhs.impl_);
}

Module& Module::operator=(Module&& rhs)
{
    impl_ = std::move(rhs.impl_);
    return *this;
}

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

void Module::setModuleName(const std::string& name)
{
    if (impl_)
    {
        impl_->setModuleName(name);
    }
}

void Module::setModuleVersion(const std::string& version)
{
    if (impl_)
    {
        impl_->setModuleVersion(version);
    }
}

void Module::printModuleInfo() const
{
    if (impl_)
    {
        impl_->printModuleInfo();
    }
}

} // !namespace library
