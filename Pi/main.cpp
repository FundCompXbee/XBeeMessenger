#include "Packet.h"

int main () {
    Packet testPacket;
    testPacket.printPacket();
    cout << testPacket.getJSONstr() << endl;    
    return 0;

}

