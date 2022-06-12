#include <stdio.h>
#include <memory>
#include "module.h"

int main(int argc, char** argv)
{
    library::Module module_x("module_x", "1.0.0");
    module_x.printModuleInfo();
    
    library::Module module_y(std::move(module_x));
    module_x.printModuleInfo();

    module_y.setModuleName("module_y");
    module_y.printModuleInfo();

    std::shared_ptr<library::Module> module_z(new library::Module("module_z", "1.0.0"));
    module_z->printModuleInfo();
    return 0;
}