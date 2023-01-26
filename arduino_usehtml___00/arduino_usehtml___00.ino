#include <WiFi.h>
#include <WiFiClient.h>
#include <WiFiServer.h>
#include <WiFiUdp.h>

#include <WiFi.h> 


// Uncomment one of the lines below for whatever DHT sensor type you're using!
const char* ssid = "JAWAD"; 
const char* password = "595*266*581@";

WiFiServer server(80);

String header;

const char index_html[] PROGMEM ={"<!DOCTYPE html PUBLIC \"-//W3C//DTD HTML 4.01//EN\">\n"
"<html>\n"
"<head>\n"
"  <title>Moonbucks</title>\n"
"<style>\n"
".home-container {\n"
"  width: 100%;\n"
"  display: flex;\n"
"  overflow: auto;\n"
"  min-height: 100vh;\n"
"  align-items: center;\n"
"  flex-direction: column;\n"
"  justify-content: flex-start;\n"
"}\n"
".home-text {\n"
"  color: rgb(69, 105, 49);\n"
"  font-size: 40px;\n"
"  font-style: normal;\n"
"  font-family: Georgia;\n"
"  font-weight: 700;\n"
"  padding-top: 100px;\n"
"}\n"
".home-container1 {\n"
"  width: 100%;\n"
"  height: 363px;\n"
"  display: flex;\n"
"  margin-top: 300px;\n"
"  align-items: flex-start;\n"
"  flex-direction: row;\n"
"  justify-content: center;\n"
"}\n"
".home-container2 {\n"
"  width: 304px;\n"
"  height: 286px;\n"
"  display: flex;\n"
"  align-items: center;\n"
"  flex-direction: column;\n"
"  justify-content: flex-end;\n"
"}\n"
".home-text1 {\n"
"  font-size: 20px;\n"
"  font-style: normal;\n"
"  font-weight: 600;\n"
"}\n"
".home-image {\n"
"  width: 205px;\n"
"  height: 202px;\n"
"  margin-top: 10px;\n"
"  object-fit: cover;\n"
"  margin-left: 20px;\n"
"  margin-right: 20px;\n"
"  padding-left: 0px;\n"
"  margin-bottom: 20px;\n"
"  padding-right: 0px;\n"
"}\n"
".home-button {\n"
"  color: #ffffff;\n"
"  border-color: #ffffff;\n"
"  background-color: #73a943;\n"
"}\n"
".home-container3 {\n"
"  width: 304px;\n"
"  height: 286px;\n"
"  display: flex;\n"
"  align-items: center;\n"
"  flex-direction: column;\n"
"  justify-content: flex-end;\n"
"}\n"
".home-text2 {\n"
"  font-size: 20px;\n"
"  font-style: normal;\n"
"  font-weight: 600;\n"
"}\n"
".home-image1 {\n"
"  width: 205px;\n"
"  height: 202px;\n"
"  margin-top: 10px;\n"
"  object-fit: cover;\n"
"  margin-left: 20px;\n"
"  margin-right: 20px;\n"
"  padding-left: 0px;\n"
"  margin-bottom: 20px;\n"
"  padding-right: 0px;\n"
"}\n"
".home-button1 {\n"
"  color: #ffffff;\n"
"  border-color: #ffffff;\n"
"  background-color: #73a943;\n"
"}\n"
".home-container4 {\n"
"  width: 304px;\n"
"  height: 286px;\n"
"  display: flex;\n"
"  align-items: center;\n"
"  flex-direction: column;\n"
"  justify-content: flex-end;\n"
"}\n"
".home-text3 {\n"
"  font-size: 20px;\n"
"  font-style: normal;\n"
"  font-weight: 600;\n"
"}\n"
".home-image2 {\n"
"  width: 205px;\n"
"  height: 202px;\n"
"  margin-top: 10px;\n"
"  object-fit: cover;\n"
"  margin-left: 20px;\n"
"  margin-right: 20px;\n"
"  padding-left: 0px;\n"
"  margin-bottom: 20px;\n"
"  padding-right: 0px;\n"
"}\n"
".home-button2 {\n"
"  color: #ffffff;\n"
"  border-color: #ffffff;\n"
"  background-color: #73a943;\n"
"}\n"
".home-container5 {\n"
"  width: 304px;\n"
"  height: 286px;\n"
"  display: flex;\n"
"  align-items: center;\n"
"  flex-direction: column;\n"
"  justify-content: flex-end;\n"
"}\n"
".home-text4 {\n"
"  font-size: 20px;\n"
"  font-style: normal;\n"
"  font-weight: 600;\n"
"}\n"
".home-image3 {\n"
"  width: 205px;\n"
"  height: 202px;\n"
"  margin-top: 10px;\n"
"  object-fit: cover;\n"
"  margin-left: 20px;\n"
"  margin-right: 20px;\n"
"  padding-left: 0px;\n"
"  margin-bottom: 20px;\n"
"  padding-right: 0px;\n"
"}\n"
".home-button3 {\n"
"  color: #ffffff;\n"
"  border-color: #ffffff;\n"
"  background-color: #73a943;\n"
"}\n"
".home-image4 {\n"
"  top: 0px;\n"
"  right: 0px;\n"
"  width: 300px;\n"
"  height: 300px;\n"
"  position: absolute;\n"
"  margin-top: 0px;\n"
"  object-fit: cover;\n"
"  margin-right: 0px;\n"
"}\n"
"\n"
"</style>\n"
"</head>\n"
"\n"
"<body>\n"
"<div>\n"
"  <link href=\"./home.css\" rel=\"stylesheet\" />\n"
"  <div class=\"home-container\">\n"
"    <span class=\"home-text\">Moonbucks Machine</span>\n"
"    <div class=\"home-container1\">\n"
"      <div class=\"home-container2\">\n"
"        <h1 class=\"home-text1\">Normal</h1>\n"
"        <img\n"
"          alt=\"image\"\n"
"          src=\"https://encrypted-tbn0.gstatic.com/images?q=tbn:ANd9GcQwTm4_gJ7nxnXUw71Vodmyew6fMC7dVfqPbA&amp;usqp=CAU\"\n"
"          class=\"home-image\"\n"
"        />\n"
"        <button id=\"normalButton\" class=\"home-button button\">\n"
"          order a cup\n"
"        </button>\n"
"      </div>\n"
"      <div class=\"home-container3\">\n"
"        <h1 class=\"home-text2\">Dark</h1>\n"
"        <img\n"
"          alt=\"image\"\n"
"          src=\"https://www.nescafe.com/mena/sites/default/files/BR%20english%20without%20capture-1.jpg\"\n"
"          class=\"home-image1\"\n"
"        />\n"
"        <button id=\"darkButton\" class=\"home-button1 button\">order a cup</button>\n"
"      </div>\n"
"      <div class=\"home-container4\">\n"
"        <h1 class=\"home-text3\">Sugar plus plus</h1>\n"
"        <img\n"
"          id=\"sugarPlusButton\"\n"
"          alt=\"image\"\n"
"          src=\"https://www.shutterstock.com/image-photo/july-2016-lahore-promotional-red-260nw-461187979.jpg\"\n"
"          class=\"home-image2\"\n"
"        />\n"
"        <button id=\"sugarPlusButton\" class=\"home-button2 button\">\n"
"          order a cup\n"
"        </button>\n"
"      </div>\n"
"      <div class=\"home-container5\">\n"
"        <h1 class=\"home-text4\">No sugar</h1>\n"
"        <img\n"
"          alt=\"image\"\n"
"          src=\"https://cdnprod.mafretailproxy.com/sys-master-root/h08/h20/14966005760030/1747962_1.jpg_480Wx480H\"\n"
"          class=\"home-image3\"\n"
"        />\n"
"        <button id=\"noSugarButton\" class=\"home-button3 button\">\n"
"          order a cup\n"
"        </button>\n"
"      </div>\n"
"    </div>\n"
"    <img\n"
"      alt=\"image\"\n"
"      src=\"https://images-wixmp-ed30a86b8c4ca887773594c2.wixmp.com/f/aca2d73f-de95-438a-b84f-d0fcaeedd6d9/d9tkwi1-8af7eb5e-1568-49e8-a77e-93d8649aed18.png/v1/fill/w_600,h_600,strp/moonbucks_coffee_by_rtry_d9tkwi1-fullview.png?token=eyJ0eXAiOiJKV1QiLCJhbGciOiJIUzI1NiJ9.eyJzdWIiOiJ1cm46YXBwOjdlMGQxODg5ODIyNjQzNzNhNWYwZDQxNWVhMGQyNmUwIiwiaXNzIjoidXJuOmFwcDo3ZTBkMTg4OTgyMjY0MzczYTVmMGQ0MTVlYTBkMjZlMCIsIm9iaiI6W1t7InBhdGgiOiJcL2ZcL2FjYTJkNzNmLWRlOTUtNDM4YS1iODRmLWQwZmNhZWVkZDZkOVwvZDl0a3dpMS04YWY3ZWI1ZS0xNTY4LTQ5ZTgtYTc3ZS05M2Q4NjQ5YWVkMTgucG5nIiwiaGVpZ2h0IjoiPD02MDAiLCJ3aWR0aCI6Ijw9NjAwIn1dXSwiYXVkIjpbInVybjpzZXJ2aWNlOmltYWdlLndhdGVybWFyayJdLCJ3bWsiOnsicGF0aCI6Ilwvd21cL2FjYTJkNzNmLWRlOTUtNDM4YS1iODRmLWQwZmNhZWVkZDZkOVwvcnRyeS00LnBuZyIsIm9wYWNpdHkiOjk1LCJwcm9wb3J0aW9ucyI6MC40NSwiZ3Jhdml0eSI6ImNlbnRlciJ9fQ.tan5hfUccrNKlGDlTLHKPAFr6Z5FraiScPdzAXHFuUU\"\n"
"      class=\"home-image4\"\n"
"    />\n"
"  </div>\n"
"</div>\n"
"\n"
"\n"
"</body>\n"
"</html>"};

void setup() {
Serial.begin(115200);



Serial.print("Connecting to Wifi Network");
Serial.println(ssid);
WiFi.begin(ssid, password);
while (WiFi.status() != WL_CONNECTED) {
delay(500);
Serial.print(".");
}
Serial.println("");
Serial.println("Successfully connected to WiFi.");
Serial.println("IP address of ESP32 is : ");
Serial.println(WiFi.localIP());
server.begin();
Serial.println("Server started");

}

void loop()
{

WiFiClient client = server.available();

if (client) 
{ 
Serial.println("Web Client connected ");
String request = client.readStringUntil('\r'); 
client.println("HTTP/1.1 200 OK");
client.println("Content-type:text/html");
client.println("Connection: close");
client.println();
////////////

client.println(index_html);



client.stop();
client.println();
Serial.println("Client disconnected.");
client.println(" ");


}
}
