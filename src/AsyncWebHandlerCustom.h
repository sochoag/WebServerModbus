#ifndef AsyncWebHandlerCustom
#define AsyncWebHandlerCustom

#include "WiFi.h"
#include "WifiManagerCustom.h"
#include "Arduino_JSON.h"

// Replace with your network credentials
const char* ssid = "sochoagu";
const char* password = "sochoagu";

JSONVar lectura;
String jsonLectura = "";

AsyncEventSource events("/events");

void AWebSetup()
{
  // Route for root / web page
  server.on("/", HTTP_GET, [](AsyncWebServerRequest *request){
    request->send(SPIFFS, "/index.html", String());
  });
  
  // Route to load style.css file
  server.on("/style.css", HTTP_GET, [](AsyncWebServerRequest *request){
    request->send(SPIFFS, "/style.css", "text/css");
  });

  server.addHandler(&events);
  // Start server
  server.begin();
}


void AWebSendData(float v1, float v2, float v3, float c)
{
    lectura["v1"] = v1;
    lectura["v2"] = v2;
    lectura["v3"] = v3;
    lectura["c"] = c;
    
    String mensaje = JSON.stringify(lectura);

    Serial.println(mensaje);

    events.send(mensaje.c_str(), "new_readings", millis());
}
#endif