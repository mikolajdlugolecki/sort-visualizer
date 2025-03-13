#include "App.h"

int main(void)
{
    Application *Instance = new Application;
    Instance->run();
    delete Instance;
    return EXIT_SUCCESS;
}
