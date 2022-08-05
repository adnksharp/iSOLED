#include <Wire.h>
#include <Adafruit_GFX.h>
#include <Adafruit_SSD1306.h>

Adafruit_SSD1306 display(128, 64, &Wire, -1);

void setup()
{
    Serial.begin(115200);
    display.begin(SSD1306_SWITCHCAPVCC, 0x3C);
    display.clearDisplay();
    display.setCursor(0, 0);
    display.setTextColor(WHITE);
    display.print("Sistema funcionando");
    display.display();
}

void loop()
{
    if (Serial.available() > 0)
    {
        display.clearDisplay();
        display.setCursor(0, 0);
        display.setTextColor(WHITE);
        display.println(Serial.readString());
        display.display();
    }
}