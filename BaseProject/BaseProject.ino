/*******************************************************************
    An example ESP32 Project with the following features

    - Wifi manager for configuring
    - Double reset detector for entering config mode
    - Saving and loading config
    - NTP and Timezones

    If you find what I do useful and would like to support me,
    please consider becoming a sponsor on Github
    https://github.com/sponsors/witnessmenow/

    Written by Brian Lough
    YouTube: https://www.youtube.com/brianlough
    Twitter: https://twitter.com/witnessmenow
 *******************************************************************/

#include "genericBaseProject.h"

void setup()
{
    Serial.begin(115200);

    baseProjectSetup();
    // You will be fully connected by the time you are here
}

bool first = true;

void loop()
{
    baseProjectLoop();

    if (first || minuteChanged())
    {
        Serial.print(projectConfig.timeZone);
        Serial.print(F(":     "));
        Serial.println(myTZ.dateTime());
        Serial.println("-------------------------");
        first = false;
    }
}