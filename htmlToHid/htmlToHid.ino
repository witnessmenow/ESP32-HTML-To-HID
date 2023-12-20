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

#include <WiFi.h>
#include <WiFiClient.h>
#include <WebServer.h>
#include <ESPmDNS.h>

#define MDNS_NAME "fire"

// #ifndef ARDUINO_USB_MODE
// #error This ESP32 SoC has no Native USB interface
// #elif ARDUINO_USB_MODE == 1
// #warning This sketch should be used when USB is in OTG mode
// void setup(){}
// void loop(){}
// #else

#include "USB.h"
#include "USBHIDKeyboard.h"
USBHIDKeyboard Keyboard;

const char *webpage =
#include "webPage.h"
    ;

WebServer server(80);

const int led = 13;

void handleRoot()
{
    server.send(200, "text/html", webpage);
}

void handleNotFound()
{
    digitalWrite(led, 1);
    String message = "File Not Found\n\n";
    message += "URI: ";
    message += server.uri();
    message += "\nMethod: ";
    message += (server.method() == HTTP_GET) ? "GET" : "POST";
    message += "\nArguments: ";
    message += server.args();
    message += "\n";
    for (uint8_t i = 0; i < server.args(); i++)
    {
        message += " " + server.argName(i) + ": " + server.arg(i) + "\n";
    }
    server.send(404, "text/plain", message);
    digitalWrite(led, 0);
}

void handleCommand()
{
    String command = "";
    int commandNum = 0;
    uint8_t key = 0;
    for (uint8_t i = 0; i < server.args(); i++)
    {
        if (server.argName(i) == "press")
        {
            command = server.arg(i);
            commandNum = command.toInt();
            switch (commandNum)
            {
            case 1:
                key = KEY_UP_ARROW;
                break;
            case 2:
                key = KEY_LEFT_ARROW;
                break;
            case 3:
                key = KEY_RIGHT_ARROW;
                break;
            case 4:
                key = KEY_DOWN_ARROW;
                break;
            case 5:
                key = KEY_ESC;
                break;
            case 6:
                key = KEY_RETURN;
                break;
            case 7:
                key = KEY_F12;
                break;
            }
        }
    }
    if (key > 0)
    {
        Keyboard.press(key);
        delay(50);
        Keyboard.release(key);
        delay(50);
        server.send(200, "text/plain", "got it");
    }
    else
    {
        server.send(404, "text/plain", "not a real key");
    }
}

void handleText()
{
    String text = "";
    for (uint8_t i = 0; i < server.args(); i++)
    {
        if (server.argName(i) == "text")
        {
            text = server.arg(i);
        }
    }
    if (text != "")
    {
        Keyboard.print(text);
    }
    server.send(200, "text/plain", "got it");
}

void setup()
{
    Serial.begin(115200);

    baseProjectSetup();
    // You will be fully connected by the time you are here

    Keyboard.begin();
    USB.begin();

    if (MDNS.begin(MDNS_NAME))
    {
        Serial.println("MDNS Responder Started");
    }

    server.on("/", handleRoot);
    server.on("/command", handleCommand);
    server.on("/text", handleText);
    server.onNotFound(handleNotFound);

    server.begin();
}

bool first = true;

void loop()
{
    baseProjectLoop();

    server.handleClient();
}