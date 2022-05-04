#include <Arduino.h>
#include <ESP8266WiFi.h>
#include <ESP8266HTTPClient.h>
#include <WiFiClient.h>
class Comunicacao
{
public:
    struct WIFI
    {
        const char *ssid = "rede";
        const char *password = "rede";
        String localhost = "111.1.1.1";
    };
    struct WIFI WIFI;
    struct user
    {
        String email = "";
        String senha = "";
        String token = "";
    };
    struct user user;
    struct TempUmiDados
    {
        float temperatura;
        float umidade;
    };
    struct TempUmiPinos
    {
    };

    void
    connectWIFI()
    {
        WiFi.begin(WIFI.ssid, WIFI.password);
        Serial.println("Connecting");
        while (WiFi.status() != WL_CONNECTED)
            delay(500);
        Serial.print("Connected to WiFi network with IP Address: ");
        Serial.println(WiFi.localIP());

        // Serial.println("Timer set to 5 seconds (timerDelay variable), it will take 5 seconds before publishing the first reading.");
    }

    String postLogin()
    {

        return user.token;
    }
    void postHistory(bool temperatura)
    {
        String token = postLogin();
        String viragem = "null";

        if (temperatura)
        {
        }
        else
        {
            viragem = "moment";
        }
    }
    TempUmiDados getProcess()
    {
        String token = postLogin();
        struct TempUmiDados padrao;
        if (WiFi.status() == WL_CONNECTED)
        {
            WiFiClient client;
            HTTPClient http;
            String serverPath = WIFI.localhost + "/process";
            // Your Domain name with URL path or IP address with path
            http.begin(client, serverPath.c_str());

            // Send HTTP GET request
            int httpResponseCode = http.GET();
            if (httpResponseCode > 0)
            {
                Serial.println("HTTP Response code: " + httpResponseCode);
                String payload = http.getString();
                Serial.println(payload);
            }
            else
                Serial.println("Error code: " + httpResponseCode);
            http.end();
        }
        else
            Serial.println("WiFi Disconnected");
        return padrao;
    }
    void getUltimaViragem()
    {
    }
    void getHorario()
    {
    }
    TempUmiDados CI()
    {
        struct TempUmiDados chocadeira;
        chocadeira.temperatura = digitalRead(10);
        chocadeira.umidade = digitalRead(10);
        return chocadeira;
    }
};