/*

stop_einfachfon version 1.0
PID: 14435
User: u0_a226
Package: de.einfachfon.kids.launcher (German version)

*/

#include <iostream>
#include <stdio.h>

void checkDevices() {
    system("adb devices");
    return;
}

void enableEinfachFonLauncher() {
    system("adb shell pm enable de.einfachfon.kids.launcher");
    std::cout << "EinfachFon Launcher is now enabled" << std::endl;
    std::cout << "Start EinfachFon Kids App manually and go through the setup process" << std::endl;
    return;
}

void disableEinfachFonLauncher() {
    system("adb shell pm disable-user --user 0 de.einfachfon.kids.launcher");
    std::cout << "EinfachFon Launcher is now disabled" << std::endl;
    return;
}

void printUsage() {
    std::cout << "1. Check for devices" << std::endl;
    std::cout << "2. Disable EinfachFon Launcher" << std::endl;
    std::cout << "3. Enable EinfachFon Launcher" << std::endl;
    return;
}

int main(int argc, char **argv) {
    std::string versionNumber = "1.0";

    printUsage();
    int choice;
    std::cin >> choice;

    switch (choice)
    {
    case 1:
        checkDevices();
        break;
    case 2:
        disableEinfachFonLauncher();
        break;
    case 3:
        enableEinfachFonLauncher();
        break;
    
    default:
        printf("Unknown Answer\n");
        break;
    }

    return 0;
}