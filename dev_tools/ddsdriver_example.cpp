#include "firmware/due/DDSDriver.h"

int main() {
    DDSDriver dds;
    dds.begin();
    dds.setFrequency(1000000);
    dds.setWaveform(0);
    return 0;
}
