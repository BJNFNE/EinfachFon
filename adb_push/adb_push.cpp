#include <iostream>
#include <stdio.h>

void androidStorageFolder() {
    std::cout << "/data - Internal Save directory (Cannot be used at the moment)." << std::endl;
    std::cout << "/sdcard - Save directory for your Files." << std::endl;
    return;
}

void uploadFiles() {
    std::string sourceDirectory, targetDirectory;

    std::cout << "Enter the local directory or file path to upload: ";
    std::cin >> sourceDirectory;

    std::cout << "Enter the target directory path on the device: ";
    std::cin >> targetDirectory;

    std::string command = "adb push \"" + sourceDirectory + "\" \"" + targetDirectory + "\"";

    int cmdInt = std::system(command.c_str());

    if (cmdInt == 0) {
        std::cout << "File(s) uploaded successfully!" << std::endl;
    } else {
        std::cerr << "Failed to upload the file(s)." << std::endl;
    }
}

void checkForDevices() {
    system("adb devices");
    return;

}

void openShell() {
    system("adb shell");
    return;
}

void printUsage() {
    printf("Choose your option!\n");
    std::cout << "1. Checks for your Android device" << std::endl;
    std::cout << "2. List the directory where you can upload Files to." << std::endl;
    std::cout << "3. Upload the Files " << std::endl;
    std::cout << "4. Open ADB Shell" << std::endl;
    printf("\b");
    return;
}

int main(int argc, char **argv) {

    std::string versionNumber = "v1.0";
    std::cout << "adb_push" << " " << versionNumber << std::endl;
    printf("\n");
    printUsage();
    printf("\n");

    int choice;
    std::cin >> choice;

    switch (choice)
    {
    case 1:
        checkForDevices();
        break;
    case 2:
        androidStorageFolder();
        break;
    case 3:
        uploadFiles();
        break;
    case 4:
        openShell();
        break;
    default:
        std::cout << "Unknown Answer!\n" << std::endl;
        break;
    }

    return 0;
}
