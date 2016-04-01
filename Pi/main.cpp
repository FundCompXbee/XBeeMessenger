#include "Packet.h"
#include "Message.h"
#include <iostream>

using namespace std;

int main () {
    Packet testPacket;
    testPacket.printPacket();
    cout << testPacket.getJSONstr() << endl;    


    Message testMessage;
    testMessage.setMessage("Hi Aaron, I hope this works!");
    testMessage.printPacket();
    cout << testMessage.getJSONstr() << endl;

    return 0;

}

