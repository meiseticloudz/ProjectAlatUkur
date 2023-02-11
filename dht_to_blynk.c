#define BLYNK_PRINT Serial //Pendeklarasian Library
#include &lt;ESP8266WiFi.h&gt;
#include &lt;BlynkSimpleEsp8266.h&gt;
#include &lt;DHT.h&gt;

char auth[] = "XXXX"; // masukkan kode autentikasi disini
char ssid[] = "Indobot"; //nama wifi
char pass[] = "123456789"; //password

#define DHTPIN 2  // Pemilihan Pin D4 dan pendeklarasian variabel
#define DHTTYPE DHT11     
DHT dht(DHTPIN, DHTTYPE);
BlynkTimer timer;

void sendSensor(){ //Pengaturan Variabel Sensor dan Virtual Pin
  float h = dht.readHumidity();
  float t = dht.readTemperature(); 
  if (isnan(h) || isnan(t)) {
    Serial.println("Failed to read from DHT sensor!");
    return;
  }

  Blynk.virtualWrite(V5, h);
  Blynk.virtualWrite(V6, t);
}

void setup(){ //Pengaturan Variabel
  Serial.begin(9600);
  Blynk.begin(auth, ssid, pass);
  dht.begin();
  timer.setInterval(1000L, sendSensor);
}

void loop(){ //Perulangan Program
  Blynk.run();
  timer.run();
}
