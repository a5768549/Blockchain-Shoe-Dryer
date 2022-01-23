#include <ArduinoJson.h>

bool device1_status = 0;
bool device2_status = 0;
bool device3_status = 0;
bool device4_status = 0;

char server[] = "173.255.242.7"; 
String host   = "173.255.242.7:3000";
String serverPath = "http://173.255.242.7:3000/api/control";

WiFiClient client;

void post_status(String device,String status)
{
  DynamicJsonDocument post_data(2048);
  post_data["id"] = device;
  post_data["status"]  = status;

  String json;
  serializeJson(post_data, json);

  if (client.connect(server, 3000)) 
  {
    Serial.println("connected");
    client.println("PUT /api/control HTTP/1.0");
    client.println("Host: " + host);
    client.println("Accept: */*");
    client.println("Content-Type: application/json");
    client.print  ("Content-Length: ");
    client.println(json.length());
    client.println();
    client.print  (json);
    client.println("Connection: close");
    delay(10);
  }
}

void get_status()
{
  HTTPClient http;
  StaticJsonDocument<200> doc;
  
  // Your Domain name with URL path or IP address with path
  http.begin(serverPath.c_str());
  
  // Send HTTP GET request
  int httpResponseCode = http.GET();
  
  if (httpResponseCode>0) {
    Serial.print("HTTP Response code: ");
    Serial.println(httpResponseCode);
    String payload = http.getString();
    Serial.println(payload);
    deserializeJson(doc, payload);
    device1_status = doc[0]["status"];
    device2_status = doc[1]["status"];
    device3_status = doc[2]["status"];
    device4_status = doc[3]["status"];
  }
  else {
    Serial.print("Error code: ");
    Serial.println(httpResponseCode);
  }
  // Free resources
  
  http.end();
}
