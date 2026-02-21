/**
 * @file DoxygenExample.ino
 * 
 * @mainpage Doxygen Example Project_May_04
 * 
 * 
 */
/*****************************************************************
  Header files section
****************************************************************/
// Libraries
#include <ESP8266WiFi.h>
#include <DNSServer.h>
#include <ESP8266WebServer.h>
#include <WiFiManager.h>
#include <WiFiClient.h>
#include <EEPROM.h>
#include <PubSubClient.h>
#include <Ticker.h>  //Ticker Library
#include <SimpleTimer.h>

/****************************************************************
    Macro declaration section
 ****************************************************************/
 //Defines
#define CWONOFF        5
#define WWHITE         13
#define RED            4
#define GREEN          12
#define BLUE           14
#define DEVICEINFO     16
#define CONFIGTIME     5
#define ENABLE_DEBUG   1

#if ENABLE_DEBUG
// Debug Define Messages
#define WIFIDBUG       1
#define WIFICTRL       1
#define WIFIUDP        1
#define WIFIMQTT       1
#define WIFICONFIG     1
#endif


#define IDLETIME   ((1.5)*60)

/***************************************************************
   Global Variables declartion
 ***************************************************************/
// Const global variables
// MQTT Broker
//const char *mqtt_broker = "13.234.207.135";
const char *mqtt_username = "emqx";
const char *mqtt_password = "public";
//const int mqtt_port = wifi_cred.credport.toInt();
const char *STATE_TOPIC = "LED/BRT/state";  // Topic to publish the light state to

// Global variables
/** The eeprom structure type. */
struct eeprom {
  int config_flag;  ///< The config_flag of the eeprom.
  int prev_state_led;   ///< The led_prev_state of the eeprom.
  int prev_state_brt;   
  int prev_state_temp;
  int control_flag;
  int bootup_flag;
  int configtopic;
  int power_on_sequence_flag;
  int device_type;
  int grp_flag;
  int empty;
  byte index_grp;
};

/** The mqtt structure type. */
struct mqtt {
  String Home;
  String room;
  String light;
  String devres;
  String redString;
  String greenString;
  String blueString;
  String brtString;
  String onoffString;
  String grp_cnt;
};

/** The cred structure type. **/
struct cred {
  String creds;
  String credp;
  String credurl;
  String credport;
};

/** The crntstate type. **/
struct crntstate {
  short red;
  short green;
  short blue;
  short warm;
  short cool;
  short brt;
  short temp;
  short dlonoff;
};

struct eeprom prev_data;
struct cred wifi_cred;
struct mqtt mqtt_data;
struct crntstate crntval;


int addr = 0;
int Rval = 0, Gval = 0, Bval = 0, Wval = 0, val = 0, Cval = 0;
int preRval = 0, preGval = 0, preBval = 0, preWval = 0, preval = 0, preCval = 0;
int coolval = 0, brtval = 0, val_dummy = 0, dummyval = 0, tempval = 0, dl_onoff=0,grp=0,grp_dummy=0,grp_empty=0,grp_cnt=0;
String tempstring, coolwhitestring, brtstring,dl_onoffstring,ip;
unsigned long previousMillis = 0;
unsigned long interval = (180 * 1000);
unsigned int StringLength=0; 
int count = 1,count1 = 0,count2 = 0, count3 = 0;  // RGB scene counter
String strings[100];      // an array of pointers to the pieces of the above array after strtok()
char *ptr = NULL;
char mqttip;

/*****************************************************************
   Function Declarations section
******************************************************************/
// UDP function declaration 
int udp_setup(void);

// MQTT function declarations
void connectmqtt();
void reconnect();
void callback(char *topic, byte *payload, unsigned int length);

// Configuration and reconfiguration function declarations
void _setup_configuration(void);
void _bootingprocess(void);
int power_on_sequence(void);
void erase_prev_config(void);

// Dynamic topic subscription function declaration
void subscribe(String home, String light);
void subscribe_grp(String home, String room, String light); 

// RGB and DL function declarations
void setColor(int red, int green, int blue, int white, int onoff);
void setcoolwhite(void);
void _Downlight(int dl_brt, int dl_temp, int onoff_dl);
void delete_(String mymsg);

// Check n/w status function declaration
void check_connect_wifi(void);
void changeState();

// EEPROM writing and reading function declarations 
int writeStringToEEPROM(int addrOffset, String &strToWrite);
int readStringFromEEPROM(int addrOffset, String *strToRead);
void EEPROM_reading();
void eeprom_erase(void);
// RGB scene disable function
void rgb_ticker_disable();
// Multiple group
void multiple_grp(String mymsg, String grp_topic);
// Extractions
void pre_off_state();
void pre_on_state();
void grp_extraction(String mymsg);
void dl_extraction(String mymsg);
void rgb_extraction(String mymsg);
void home_light_extractions(String mymsg);
void EEPROM_writing(void);



// Object declaration
WiFiClient espClient;
PubSubClient client(espClient);
WiFiManager wifiManager;
Ticker blinker;

// RGB scene tickers
Ticker ticker_soft;
Ticker ticker_colorful;
Ticker ticker_dazzling;
Ticker ticker_gorgeous;

/********************************************************************
           Setup()
 ******************************************************************/
/**
 * The standard Arduino setup function used for setup and configuration tasks.
 */
void setup() {
/************************************************************
  Buad rate selection
************************************************************/
  Serial.begin(115200);         // Set software serial baud to 115200;

/*************************************************************
  EEPROM Size selection
*************************************************************/
  EEPROM.begin(512);
  // TO set the EEPROM vaules to Zeros
  EEPROM.get(addr,prev_data);
  if (prev_data.bootup_flag < 0) {
    prev_data.bootup_flag = 0;
    EEPROM.put(addr, prev_data);
    EEPROM.commit();
  }
/************************************************************
  PinMode selection
************************************************************/
  pinMode(CWONOFF, OUTPUT);     //Setting to LED pin as OUTPUT
  pinMode(WWHITE, OUTPUT);     //Setting to BRT pin as OUTPUT
  pinMode(RED, OUTPUT);       // Setting RGB pins as OUTPUT   
  pinMode(GREEN, OUTPUT);
  pinMode(BLUE, OUTPUT);
  pinMode(DEVICEINFO, INPUT);    // Device Information

/***********************************************************
            Configure the PINS with default values
************************************************************/
  if (prev_data.control_flag == 0) {
    digitalWrite(CWONOFF, HIGH);
  }
 /***********************************************************
               Reading data from EEPROM
 ************************************************************/
  //Reading Previous values
  EEPROM_reading();
/***********************************************************
                  Configuration setup
************************************************************/
  _setup_configuration();
  long rssi = WiFi.RSSI();
  Serial.print("\nRSSI:");Serial.println(rssi);
  Serial.print("mac id = ");
  Serial.println(WiFi.macAddress());
  
/************************************************************
   Initialize Ticker every 90s
 ************************************************************/
  //Initialize Ticker every 90s
  blinker.attach(IDLETIME, changeState);

} // End of setup

/************************************************************************
              Main loop setup
 ************************************************************************/
/**
 * The standard Arduino loop function used for repeating tasks.
 */
void loop() {           // Main loop 
  // If Wifi is not connected
  int status  = WiFi.status();
  if (!client.connected())
  {
    if ( ( status != WL_CONNECTED) ) {
        WiFi.begin(wifi_cred.creds.c_str(), wifi_cred.credp.c_str());
    }
        Serial.print("\nconnecting to mqtt in loop");
        Serial.print("\nWiFi.status():");Serial.println(status);
        client.setServer(wifi_cred.credurl.c_str(), wifi_cred.credport.toInt()); 
        reconnect();
    if(prev_data.grp_flag == 1){
        subscribe(mqtt_data.Home, mqtt_data.light); 
        client.subscribe(mqtt_data.room.c_str());delay(50); 
        Serial.print("Group subscription topic is....");Serial.println(mqtt_data.room.c_str());
    }else{
        subscribe(mqtt_data.Home, mqtt_data.light);
    }
    client.setCallback(callback);
  }
  client.loop();
} // End of loop

// To check WiFi connection status 
void check_connect_wifi()
{
    int status  = WiFi.status();
    Serial.print("\nWiFi.status():");
    Serial.println(status);
    if (( status != WL_CONNECTED)){
         status = WiFi.begin(wifi_cred.creds.c_str(), wifi_cred.credp.c_str());
    }
   Serial.print("\nWiFi.begin():");
   Serial.println(status);
}// End check_connect_wifi()

/***********************************************************
            Function definitions
 ***********************************************************/
// Reconnect to the client
void reconnect() {
  // Loop until we're reconnected
  while (!client.connected()) 
  {
    //check_connect_wifi();
    String client_id = "esp8266_client:";
    client_id += String(WiFi.macAddress());
    #if WIFIMQTT
    Serial.println("Connecting to MQTT Broker.....");
    #endif
      if (client.connect(client_id.c_str(), mqtt_username, mqtt_password)) {
          client.publish(STATE_TOPIC, "MQTT Broker connected");
          #if WIFIMQTT
          Serial.println("MQTT Broker connected");
          Serial.println();
          #endif
      }else {
          #if WIFIMQTT
          Serial.print("failed with state ");Serial.println(client.state());
          Serial.println("try again in 5 seconds");
          #endif
          delay(500);
      }//else
  }//while
  client.subscribe("config_topic");
  #if WIFIMQTT
  Serial.println("Reconnect() is executed");
  #endif
} // End of reconnect()

// Controlling/ Execution ModuleCallback()
void callback(char *topic, byte *payload, unsigned int length) {
#if WIFICTRL
  Serial.println("Callback() is executed");
  // Topics and Payloads from the server
  Serial.print("Message arrived[");Serial.print(topic);Serial.print("]:");
#endif
  char mytopic[length + 1];
  memcpy(mytopic, payload, length);
  mytopic[length] = NULL;
  String mymsg(mytopic);
#if WIFICTRL
  Serial.println(mymsg);
  Serial.println("-----------------------");Serial.print("prev_data.configtopic:");Serial.println( prev_data.configtopic);
#endif
  prev_data.control_flag = 1;
  prev_data.power_on_sequence_flag = 0;
  prev_data.bootup_flag = 0;
  EEPROM.put(addr, prev_data);
  EEPROM.commit();

if (prev_data.configtopic != 1) {
    home_light_extractions(mymsg);
    // Controlling the device based on Topic and Payload
    if (mymsg == mymsg.substring(mqttip)) {
      if (ip == WiFi.localIP().toString()) {
        if (strcmp(topic, "config_topic") == 0) {
          client.publish(mqtt_data.devres.c_str(), " ");
          client.publish(mqtt_data.devres.c_str(), "config");  // new architecture response
          prev_data.configtopic = 1;
          #if WIFICTRL
          Serial.print("\nprev_data.configtopic:");Serial.println(prev_data.configtopic);
          #endif
          delay(1000);
          client.unsubscribe("config_topic");
        }// End of config topic comparison
      }// End of if block (WiFi.localIP().toString())
    }// End of if block(mymsg.substring(mqttip))     
}// End of if block( prev_data.configtopic != 1)
else if (prev_data.configtopic == 1) { 
#if WIFICTRL
    Serial.print("\nprev_data.configtopic=");Serial.println(prev_data.configtopic);
    Serial.print("mqtt_data.config_flag == 1\n");
#endif
  if (strcmp(topic, mqtt_data.Home.c_str()) == 0)                           
  {     // Home  Topic
    #if WIFICTRL
        Serial.print("\nSubcribed topic:");Serial.println(mqtt_data.Home.c_str());
        Serial.print("\nMymsg:");Serial.println(mymsg);
    #endif
    if(mymsg == String(150))                   // Command for both DL&RGB off at Home 
    {
      pre_off_state();
      client.publish(mqtt_data.devres.c_str(),String("ACK\t"+mymsg).c_str());    
      #if WIFICTRL
      Serial.println("LED val 150 is executed at HOME"); 
      #endif
    }else if(mymsg == String(200)){              // Command for both DL&RGB on at Home
      pre_on_state();
      client.publish(mqtt_data.devres.c_str(),String("ACK\t"+mymsg).c_str());  
      #if WIFICTRL
          Serial.println("LED val 200 is executed at HOME"); 
      #endif 
    }// End of Else if block
    else if ((mymsg.startsWith("g")) && (mymsg.endsWith("&"))) { //Group command gGrp,L1,L2,L3....& (Grp = grouptopic, L1,L2,L3.. are Light ids) 
      grp_extraction(mymsg);
      client.publish(mqtt_data.devres.c_str(),String("ACK\t"+mymsg).c_str()); 
      #if WIFICTRL
      Serial.print("\ngroupedetails with new lights=");Serial.println(grp);
      #endif
    }else if (mymsg == "DELETE") {
            // RGB Ticker disable
            rgb_ticker_disable();  
            delete_(mymsg);
    }
  } // End of Home topic
  if (strcmp(topic, mqtt_data.room.c_str()) == 0){     // Group/Room Topic 
     for(int n = 0; n < prev_data.index_grp; n++){
       if(strcmp(strings[n].c_str(), mqtt_data.light.c_str()) == 0){             
          multiple_grp(mymsg,mqtt_data.room);
       }
     }
  }// End of Group topic
  if (strcmp(topic, mqtt_data.light.c_str()) == 0) // Start of Light topic
  {     // Light Topic
        #if WIFICTRL
        Serial.print("Subcribed topic:");Serial.println(mqtt_data.light.c_str());
        Serial.print("Mymsg:"); Serial.println(mymsg);
        #endif
        if ((mymsg.startsWith("b")) && (mymsg.endsWith("&"))) {                // Downlight command for brightness & temperature bxxtxx@200& //
            dl_extraction(mymsg);
            #if WIFICTRL
              Serial.print("Calling function for Down Light Functionality@individual light");
            #endif
            _Downlight((brtstring.toInt()),(tempstring.toInt()),dl_onoffstring.toInt());
            client.publish(mqtt_data.devres.c_str(),String("ACK\t"+mymsg).c_str());  
        }else if ((mymsg.startsWith("r")) && (mymsg.endsWith("&"))) {      /* RGB command */ // "r201g32b255w100c400&" // RGB command for RGB light on 5 channels
            rgb_extraction(mymsg);
            client.publish(mqtt_data.devres.c_str(),String("ACK\t"+mymsg).c_str());  
            #if WIFIDBUG
              Serial.println("RGB is executed@individual light\nCurrent RGB values is...\n");
              Serial.print("crnt_redvalue:");Serial.println(mqtt_data.redString);
              Serial.print("crnt_greenvalue:");Serial.println(mqtt_data.greenString);
              Serial.print("crnt_bluevalue:");Serial.println(mqtt_data.blueString);
              Serial.print("crnt_Warmwhite value:");Serial.println(mqtt_data.brtString);
              Serial.print("crnt_coolwhite value:");Serial.println(mqtt_data.onoffString);
              // crnt values
              Serial.print("Previous state RGB values is....\nprev_val.red:");Serial.println(crntval.red);
              Serial.print("prev_val.green:");Serial.println(crntval.green);
              Serial.print("prev_val.blue:");Serial.println(crntval.blue);
              Serial.print("prev_val.warm:");Serial.println(crntval.warm);
              Serial.print("prev_val.cool:");Serial.println(crntval.cool);
            #endif
        }else if (mymsg == "DELETE") {       // Delete command for lights
            // RGB Ticker disable
            rgb_ticker_disable();
            delete_(mymsg);
        }else if (mymsg == "ACTIVE") {      // check network status
          //rgb_ticker_disable();
          client.publish(mqtt_data.devres.c_str(),String("ACK\t"+mymsg+"@"+mqtt_data.light).c_str());
        }// End of check network status
        else if(mymsg == "night"){  // Night scene
          if(prev_data.device_type == 1){
            setColor(0,0,0,510,50);
          }else{
            _Downlight(50,510,200);
          }
        }else if(mymsg == "read"){  // Read scene
          if(prev_data.device_type = 1){
            setColor(0,0,0,1020,50);
          }else{
            _Downlight(50,1020,200);
          }  
        }else if(mymsg == "working"){  // Working scene
          if(prev_data.device_type = 1){
            setColor(0,0,0,1020,100);
          }else{
            _Downlight(100,1020,200);
          }    
        }else if(mymsg == "leisure"){  // leisure scene
          if(prev_data.device_type = 1){
            setColor(0,0,0,1020,75);
          }else{
            _Downlight(75,1020,200);
          }   
        }else if(mymsg == "soft"){    // Soft scene
            rgb_ticker_disable();
            Serial.println("rgb_soft");
            ticker_soft.attach_ms(1000, rgb_soft);
        }else if(mymsg == "colorful"){  // Colorful scene
            rgb_ticker_disable();
            Serial.println("colorful");
            ticker_colorful.attach_ms(3000, rgb_colorful);
        }else if(mymsg == "dazzling") {  // Dazzling scene
            rgb_ticker_disable();
            Serial.println("dazzling");
            ticker_dazzling.attach_ms(2000, rgb_dazzling);
        }else if(mymsg == "gorgeous"){  // Gorgeous scene
            rgb_ticker_disable();
            Serial.println("gorgeous");
            ticker_gorgeous.attach_ms(1000, rgb_gorgeous);
        }      
  }// End of Light topic
 }// End of Config topic 
  // EEPROM writing
  EEPROM_writing();  
  subscribe(mqtt_data.Home, mqtt_data.light); 
}// End of callback()

// Dynamic topics subscription @ Group creation  //
void subscribe_grp(String home, String room, String light) {
  client.subscribe(home.c_str());delay(50);
  client.subscribe(room.c_str());delay(50);
  client.subscribe(light.c_str());
  #if WIFIDBUG
  Serial.println("After subscribing the dynamic topics");
  Serial.print("Subcribed topic:");Serial.println(mqtt_data.Home.c_str());
  Serial.print("Subcribed topic:");Serial.println(mqtt_data.room.c_str());
  Serial.print("Subcribed topic:");Serial.println(mqtt_data.light.c_str());
  Serial.print("prev_data.configtopic:");Serial.println(prev_data.configtopic);
  #endif
} // End of Dynamic topics subscription

void subscribe(String home, String light) {  // Dynamic topics subscription  //
  client.subscribe(home.c_str());delay(50);
  client.subscribe(light.c_str());
  #if WIFIDBUG
  Serial.println("After subscribing the dynamic topics");
  Serial.print("Subcribed topic:");Serial.println(mqtt_data.Home.c_str());
  Serial.print("Subcribed topic:");Serial.println(mqtt_data.light.c_str());
  Serial.print("prev_data.configtopic:");Serial.println(prev_data.configtopic);
  #endif
} // End of Dynamic topics subscription

// To set RGB values to zeros  Coolwhite()
void setcoolwhite(void)
{
  analogWrite(CWONOFF, 1023);
  analogWrite(WWHITE, LOW);
  analogWrite(RED, 0);analogWrite(GREEN, 0); analogWrite(BLUE, 0);
  #if WIFICTRL
    Serial.print("\nsetcoolwhite applied\n");
  #endif
}// End of setcoolwhite
//  Down light function with brightness and temperature and on & off status //
void _Downlight(int dl_brt, int dl_temp, int onoff_dl)
{
    prev_data.prev_state_brt = dl_brt;
    prev_data.prev_state_temp = dl_temp;
    prev_data.prev_state_led = onoff_dl;
    #if WIFICTRL
    Serial.print("\nDown light\nprev_data.prev_state_brt:");Serial.println(prev_data.prev_state_brt);
    Serial.print("prev_data.prev_state_temp:");Serial.println(prev_data.prev_state_temp);
    Serial.print("prev_data.prev_state_led:");Serial.println(prev_data.prev_state_led);
    #endif
    if(((prev_data.prev_state_temp >= 0) && (prev_data.prev_state_temp <= 1023)) && 
    (prev_data.prev_state_led == 200) && 
    ((prev_data.prev_state_brt >= 0) && (prev_data.prev_state_brt <= 100)))
    {
      analogWrite(CWONOFF, ((1023 * prev_data.prev_state_brt)/100));
      analogWrite(WWHITE, (1023 - prev_data.prev_state_temp));
      #if WIFICTRL
      Serial.print("\nTemperature values on CWONOFF pin (0 to 1023) is....");Serial.print(((1023 * prev_data.prev_state_brt)/100));
      Serial.print("\t@Brightness is....");Serial.println(prev_data.prev_state_brt);
      Serial.print("\nTemperature values on WWHITE pin (0 to 1023) is....");Serial.println(1023 - prev_data.prev_state_temp);
      #endif
    }// DL for BRT TEMP control
    else if((prev_data.prev_state_brt == 0) && (prev_data.prev_state_temp == 0) && ( prev_data.prev_state_led == 150)){
      digitalWrite(CWONOFF, LOW);
      #if WIFICTRL
      Serial.println("LED val 150 is executed");
      #endif
      }
    prev_data.device_type = 0;
    EEPROM.put(addr, prev_data);
    EEPROM.commit();
}// End of Down light function

/****************************** RGB *********************************************************************************/
void setColor(int red, int green, int blue, int wwhite, int cwhite)   // Function to RGB colours // "r201g32b255w9c400&"
{
  /* "rxxgxxbxxw100c400" // RGB values commands */
  if (((red >= 0) && (red <= 1020)) && ((green >= 0) && (green <= 1020)) && ((blue >= 0) && (blue <= 1020)) && (cwhite == 400))
  {
    if ((cwhite == 400) && (red == 0) && (green == 0) && (blue == 0) && (wwhite == 0)) 
    {
      analogWrite(CWONOFF, LOW);analogWrite(WWHITE, LOW);
      analogWrite(RED, red);analogWrite(GREEN, green);analogWrite(BLUE, blue);
      Serial.print("\nlight off\n");
    } 
    else if (((wwhite >= 0) && (wwhite <= 100)) && 
              ((red >= 0) && (red <= 1020)) && 
              ((green >= 0) && (green <= 1020)) && 
              ((blue >= 0) && (blue <= 1020)) &&
              (cwhite == 400)) 
    {          // Brightness and Temperature
                analogWrite(RED, red);                                               
                analogWrite(GREEN, green);
                analogWrite(BLUE, blue);
                analogWrite(CWONOFF, LOW);analogWrite(WWHITE, LOW);
    }// End of RGB Brightness and Temperature
  }
  else
  {
    // Light on / off Values
    /*if ((cwhite == 500) && (wwhite == 0) && (red == 0) && (green == 0) && (blue == 0)) {
      analogWrite(CWONOFF, HIGH);analogWrite(WWHITE, LOW);
      analogWrite(RED, red);analogWrite(GREEN, green);analogWrite(BLUE, blue);
      Serial.print("\nlight on\n");
    }*/
    // Light off command //
    if ((cwhite == 400) && (wwhite == 0) && (red == 0) && (green == 0) && (blue == 0)) {
      analogWrite(CWONOFF, LOW);analogWrite(WWHITE, LOW);
      analogWrite(RED, red);analogWrite(GREEN, green);analogWrite(BLUE, blue);
      Serial.print("\nlight off\n");
    }
    /* Brightness & Tempature  & ON Control values */
    else if ((wwhite >= 0)  && (wwhite <= 1023) && (cwhite >= 0) && (cwhite <= 100) && (red == 0) && (green == 0) && (blue == 0) )    
    {       /* Downlight command for Temperature bxxtxx&*/
        analogWrite(RED, red);analogWrite(GREEN, green);analogWrite(BLUE, blue);
        prev_data.prev_state_temp = wwhite;
        prev_data.prev_state_brt = cwhite;
        if(((prev_data.prev_state_temp >= 0) && (prev_data.prev_state_temp <= 1023)) && 
            ((prev_data.prev_state_brt >=0) && (prev_data.prev_state_brt <=100)))
        {
          analogWrite(CWONOFF, ((prev_data.prev_state_temp * prev_data.prev_state_brt)/100));
          analogWrite(WWHITE,(((1023 - prev_data.prev_state_temp)*prev_data.prev_state_brt)/100));
          #if WIFICTRL
          Serial.print("\nTemperature values on CWONOFF pin (0 to 1023) is....");Serial.print(((prev_data.prev_state_temp * prev_data.prev_state_brt)/100));
          Serial.print("@Brightness is...");Serial.println(prev_data.prev_state_brt);
          Serial.print("\nBrightness values on WWHITE pin (0 to 1023) is....");Serial.print((((1023 - prev_data.prev_state_temp)*prev_data.prev_state_brt)/100));
          Serial.print("@Brightness is...");Serial.println(prev_data.prev_state_brt);
          #endif
        }// End of RGB_DL_TEMP 0 t0 1023 @ brt 0 to 100
    }// RGB_DL brightness and Temperature
  }// End of RGB_DL
  prev_data.device_type = 1;
  EEPROM.put(addr, prev_data);
  EEPROM.commit();
#if WIFIDBUG
  Serial.print("calling function(setcolor() is ....)\n redvalue:");Serial.println(red);
  Serial.print("greenvalue:");Serial.println(green);
  Serial.print("bluevalue:");Serial.println(blue);
  Serial.print("Warmwhite value:");Serial.println(wwhite);
  Serial.print("coolwhite value:");Serial.println(cwhite);
#endif
} // End of Set color

/*************************************************************************
   Communication Module
 ************************************************************************/
// UDP configuartion
int udp_setup(void)                   // configuration mode
{                                         
  int state = 0;
  #if WIFIUDP
    Serial.print("Configuring....");
  #endif
  WiFi.mode(WIFI_STA);     // Set ESP8266 to WiFi Station mode 
  WiFi.beginSmartConfig(); // start SmartConfig 
  //Wait for SmartConfig packet from mobile
  Serial.println("\nWaiting for SmartConfig.");
  unsigned long currentMillis = millis();
  interval = (interval + currentMillis);
  #if WIFIUDP
    Serial.print("interval:");Serial.println(interval);
  #endif;
  while (!WiFi.smartConfigDone()) 
  {
      delay(250);analogWrite(CWONOFF, 1023);
      delay(250);analogWrite(CWONOFF, 0);
      #if WIFIUDP
        Serial.print(".");
      #endif
        unsigned long currentMillis = millis();
      #if WIFIUDP
        Serial.print("millis(currentMillis):");Serial.println(currentMillis);
      #endif
      if (currentMillis - previousMillis >= interval)
      {
        // Save the last time a new reading was published
        previousMillis = currentMillis;
        #if WIFIUDP
        Serial.print("currentMillis:");Serial.println(currentMillis);
        Serial.print("previousMillis:");Serial.println(previousMillis);
        #endif
        state = 1;
        break;
      }
  }
  // Got the credentials
  Serial.print("\nstate");Serial.println(state);
  if (state) {
    digitalWrite(CWONOFF, 1023);
    #if WIFIUDP
          Serial.println(state);
    #endif
    return 1;
  }
  #if WIFIUDP
  Serial.print("\nssid:");Serial.println(WiFi.SSID());
  Serial.print("pswd:");Serial.println(WiFi.psk());
  #endif
  eeprom_erase();
  wifi_cred.creds = WiFi.SSID();
  String password = WiFi.psk();
  #if WIFIUDP
  Serial.print("\nwifi_cred.creds:");Serial.print(wifi_cred.creds);
  Serial.print("\npassword:");Serial.print(password);
  #endif
  String publicurl;
  for (int i = 0; i < password.length(); i++) {
      if (password.substring(i, i+1) == ",") {
      wifi_cred.credp = password.substring(0, i);
      publicurl = password.substring(i+1);
      break;
      }
  }
  if(publicurl.startsWith("U")){
      char url  = publicurl.indexOf("U");
      char port  = publicurl.indexOf("P");
      wifi_cred.credurl = publicurl.substring(url+1,port);
      wifi_cred.credport = publicurl.substring(port+1);
      #if WIFIUDP
      Serial.print("\nwifi_cred.credp:");Serial.print(wifi_cred.credp);
      Serial.print("\nwifi_cred.credurl:");Serial.print(wifi_cred.credurl);
      Serial.print("\nwifi_cred.credport:");Serial.print(wifi_cred.credport);
      #endif
  }
  Serial.println("");Serial.println("SmartConfig done.");
  Serial.println("Waiting for WiFi");   // Wait for WiFi to connect to AP //
  WiFi.begin(wifi_cred.creds.c_str(), wifi_cred.credp.c_str());
  while (WiFi.status() != WL_CONNECTED)
  {
    delay(500);digitalWrite(CWONOFF, 1023);
    Serial.print(".");
  }
  // WiFi connected status
  Serial.println("");Serial.println("WiFi connected");Serial.println();
  prev_data.config_flag = 1;  // Now Device is configured
 // EEPROM writing  for the N/W Credentials
  EEPROM.put(addr,prev_data);
  int credsAddrOffset = writeStringToEEPROM((addr + sizeof(prev_data)), wifi_cred.creds);
  int credpAddrOffset = writeStringToEEPROM(credsAddrOffset, wifi_cred.credp);
  int credurlAddrOffset = writeStringToEEPROM(credpAddrOffset, wifi_cred.credurl);
  int credportAddrOffset = writeStringToEEPROM(credurlAddrOffset, wifi_cred.credport);
  EEPROM.commit();
  // Default state of LED is HIGH  //
  digitalWrite(CWONOFF, 1023);

  return 0;
} // End of UDP configuration mode

/***************************************************************************************
                       Configuration Module
*****************************************************************************************/
void _setup_configuration(void) {
  if (prev_data.config_flag == 0)
  {
    prev_data.bootup_flag = power_on_sequence();
    #if WIFICONFIG
    Serial.print("\nNew device\nprev_data.power_on_sequence_flag:");
    Serial.println(prev_data.bootup_flag);
    #endif
    if (prev_data.bootup_flag == CONFIGTIME) {
      if(!udp_setup()){
        erase_prev_config();
        setcoolwhite();
        Serial.print("\nUDP setup");
      }
      //connecting to a mqtt broker
      client.setServer(wifi_cred.credurl.c_str(), wifi_cred.credport.toInt());
      reconnect();
      client.setCallback(callback);     // Initialize the callback routine
    }
  }
  else if ((prev_data.config_flag == 1) && (prev_data.control_flag == 0))        //   Reconfigured and not controlled device
  {
    prev_data.bootup_flag = power_on_sequence();
    if (prev_data.bootup_flag == CONFIGTIME) 
    {
      #if WIFICONFIG
        Serial.print("\nReconfigured & not controlled Device\nprev_data.control_flag:");
        Serial.println(prev_data.control_flag);
      #endif
      wifiManager.resetSettings();
      if(!udp_setup())
      {
        erase_prev_config();
        setcoolwhite();
        Serial.println("\nUDP setup");
      }
      //connecting to a mqtt broker
      client.setServer(wifi_cred.credurl.c_str(), wifi_cred.credport.toInt());
      reconnect();
      client.setCallback(callback);     // Initialize the callback routine
      #if WIFICONFIG
      Serial.print("\nprev_data.configtopic:");Serial.println(prev_data.configtopic);
      Serial.print("prev_data.control_flag:");Serial.println( prev_data.control_flag);
      #endif
    }
    else {
      WiFi.begin(wifi_cred.creds.c_str(),wifi_cred.credp.c_str());
      //connecting to a mqtt broker
      client.setServer(wifi_cred.credurl.c_str(), wifi_cred.credport.toInt());
      reconnect();
      //subscribe(mqtt_data.Home, mqtt_data.room, mqtt_data.light);
        if(prev_data.grp_flag == 1){
            subscribe(mqtt_data.Home, mqtt_data.light);
            client.subscribe(mqtt_data.room.c_str());delay(50); 
            Serial.print("Group subscription topic is....");Serial.println(mqtt_data.room.c_str());
        }else{
          subscribe(mqtt_data.Home, mqtt_data.light);
        }
        client.setCallback(callback);     // Initialize the callback routine
    }
  }
  else if ((prev_data.config_flag == 1) && (prev_data.control_flag == 1))      
  { // Reconfigured and  controlled device
    prev_data.bootup_flag = power_on_sequence();
    #if WIFICONFIG
      Serial.print("\nReconfigured and  controlled device\nbootup_flag:");Serial.println(prev_data.bootup_flag);
      Serial.print("prev_data.control_flag:");Serial.println(prev_data.control_flag);
      Serial.print("on reset Boot flag:");Serial.println(prev_data.bootup_flag);
    #endif
    if (prev_data.bootup_flag == CONFIGTIME) 
    {
        wifiManager.resetSettings();
        if(!udp_setup()){
          erase_prev_config();
          setcoolwhite();
          Serial.print("\nUDP setup");
        }
        #if WIFICONFIG
        Serial.print("\nprev_data.configtopic:");Serial.println(prev_data.configtopic);
        Serial.print("prev_data.control_flag:");Serial.println( prev_data.control_flag);
        #endif
        //connecting to a mqtt broker
        client.setServer(wifi_cred.credurl.c_str(), wifi_cred.credport.toInt());
        reconnect();
        client.setCallback(callback);     // Initialize the callback routine
        Serial.println("mosquito mqtt callback executed"); 
    }
    else { // Reconfigured and controlled device
      WiFi.begin(wifi_cred.creds.c_str(), wifi_cred.credp.c_str());
        if (prev_data.device_type == 1) 
        { // Confirm on the previous state is 1
            delay(10);
            if ((mqtt_data.redString.toInt() == 0)  &&
                (mqtt_data.greenString.toInt() == 0) &&
                (mqtt_data.blueString.toInt() == 0)  &&
                (mqtt_data.brtString.toInt() == 0)   &&
                (mqtt_data.onoffString.toInt() == 400)) {
                #if WIFICONFIG
                Serial.print("power socket off condition in RGB:");
                #endif
                setColor(crntval.red, crntval.green, crntval.blue, crntval.warm, crntval.cool);
                #if WIFICONFIG
                // crnt values
                Serial.print("\ncrntval.red:");Serial.println(crntval.red);
                Serial.print("crntval.green:");Serial.println(crntval.green);
                Serial.print("crntval.blue:");Serial.println(crntval.blue);
                Serial.print("crntval.warm:");Serial.println(crntval.warm);
                Serial.print("crntval.cool:");Serial.println(crntval.cool);
                #endif
            }
            else {
              setColor(mqtt_data.redString.toInt(),
                       mqtt_data.greenString.toInt(),
                       mqtt_data.blueString.toInt(),
                       mqtt_data.brtString.toInt(),
                       mqtt_data.onoffString.toInt());
                      #if WIFICONFIG
                      Serial.print("power socket on condition in RGB:");
                      // crnt values
                      Serial.print("\ncrntval.red:");Serial.println(crntval.red);
                      Serial.print("crntval.green:");Serial.println(crntval.green);
                      Serial.print("crntval.blue:");Serial.println(crntval.blue);
                      Serial.print("crntval.warm:");Serial.println(crntval.warm);
                      Serial.print("crntval.cool:");Serial.println(crntval.cool);
                      #endif
            }// End of else(power socket on condition in RGB)
        }// End of prev_data.device_type == 1
        else {
             if((prev_data.prev_state_brt == 0) && (prev_data.prev_state_temp == 0) && (prev_data.prev_state_led == 150)){
                  _Downlight(crntval.brt,crntval.temp,crntval.dlonoff);
                  #if WIFICONFIG
                  Serial.print("power socket off condition in Down light:");
                  #endif
             }else{
                  _Downlight(prev_data.prev_state_brt,prev_data.prev_state_temp,prev_data.prev_state_led);
                  #if WIFICONFIG
                  Serial.print("power socket on condition in Down light:");
                  #endif
             }
       } 
      //connecting to a mqtt broker
      client.setServer(wifi_cred.credurl.c_str(), wifi_cred.credport.toInt());
      reconnect();
      //subscribe(mqtt_data.Home, mqtt_data.room, mqtt_data.light);
      if(prev_data.grp_flag == 1){
        subscribe(mqtt_data.Home, mqtt_data.light);
        client.subscribe(mqtt_data.room.c_str());delay(50); 
        Serial.print("Group subscription topic is....");Serial.println(mqtt_data.room.c_str());
      }else{
        subscribe(mqtt_data.Home, mqtt_data.light);
      }
      client.setCallback(callback);     // Initialize the callback routine
      #if WIFICONFIG
      Serial.println("Mosquito MQTT Broker callback executed"); 
      #endif
    }// previous state holding(Reconfigured and contrilled device)
  }// Reconfigured and contrilled device
  else if (prev_data.config_flag < 0) {
    eeprom_erase();
    #if WIFICONFIG
      Serial.print("\nConfiguration enter into -ve values\n");
    #endif
  }
} // end of _setup_configuration

// Power_on_sequence
int power_on_sequence(void) {                          // Power_on_sequence
  // Booting process in the middle of controlling
  if ((digitalRead(0)) && (digitalRead(2)) && (!digitalRead(15))) 
  {
    prev_data.bootup_flag +=1;
    #if WIFICONFIG
      Serial.print("power_on_sequenceflag@power_on_sequence() is...");
      Serial.println(prev_data.bootup_flag);
    #endif
    EEPROM.put(addr, prev_data);
    EEPROM.commit();
    if (prev_data.bootup_flag == CONFIGTIME) {
    #if WIFICONFIG
          Serial.print("Boot flag equals(CONFIGTIME) = ");
          Serial.println(prev_data.bootup_flag);
    #endif
      return prev_data.bootup_flag;
    }
    else if (prev_data.bootup_flag > CONFIGTIME) {
      prev_data.bootup_flag = 1;
      prev_data.power_on_sequence_flag = 1;
      //prev_data.configtopic = 0;
      EEPROM.put(addr, prev_data);
      EEPROM.commit();
      return prev_data.bootup_flag;
    }
  }
} // End of Power_on_sequence
void erase_prev_config(void) {
  prev_data.power_on_sequence_flag = 0;
  prev_data.bootup_flag = 0;
  prev_data.configtopic = 0;
  prev_data.control_flag = 0;
  prev_data.device_type = 0;
  prev_data.grp_flag = 0;
  EEPROM.put(addr, prev_data);
  EEPROM.commit();
  //eeprom_erase();
}
// EEPROM writing and Reading functions
/**
 * Retrieves WriteStringToEEPROM.
 *
 * @param addrOffset   The value of addrOffset.
 * @param strToWrite  The value of strToWrite.
 *
 * @return  The result addrOffset and lengh.
 */
int writeStringToEEPROM(int addrOffset, String &strToWrite)
{
  byte len = strToWrite.length();
  EEPROM.write(addrOffset, len);
  for (int i = 0; i < len; i++)
  {
    EEPROM.write(addrOffset + 1 + i, strToWrite[i]);
  }
  return addrOffset + 1 + len;
}
/**
 * Retrieves readStringFromEEPROM.
 *
 * @param addrOffset   The value of addrOffset.
 * @param strToRead  The value of strToRead.
 *
 * @return  The result addrOffset and lengh.
 */
int readStringFromEEPROM(int addrOffset, String *strToRead)
{
  int newStrLen = EEPROM.read(addrOffset);
  char data[newStrLen + 1];
  for (int i = 0; i < newStrLen; i++)
  {
    data[i] = EEPROM.read(addrOffset + 1 + i);
  }
  data[newStrLen] = '\0';
  *strToRead = String(data);
  return addrOffset + 1 + newStrLen;
}
/**
 * EEPROM_reading 
 *
 * */
 
void EEPROM_reading() {
  //  Reading Previous values
  //  Reading N/W credentials and public url and port
  int newcredsAddrOffset = readStringFromEEPROM((addr + sizeof(prev_data)), &wifi_cred.creds);
  int newcredpAddrOffset = readStringFromEEPROM(newcredsAddrOffset, &wifi_cred.credp);
  int newcredurlAddrOffset = readStringFromEEPROM(newcredpAddrOffset, &wifi_cred.credurl);
  int newcredportAddrOffset = readStringFromEEPROM(newcredurlAddrOffset, &wifi_cred.credport);
  
  // Reading dynamic topics like Home & light and Response 
  int newhomeAddrOffset   = readStringFromEEPROM((addr + sizeof(prev_data) + sizeof(wifi_cred)), &mqtt_data.Home);
  int newlightAddrOffset  = readStringFromEEPROM(newhomeAddrOffset, &mqtt_data.light);
  int newdevicenameaddroffset  = readStringFromEEPROM(newlightAddrOffset, &mqtt_data.devres);
  // Reading Data on RGB 5 channels
  int newredstringAddrOffset   = readStringFromEEPROM(newdevicenameaddroffset, &mqtt_data.redString);
  int newgreenstringAddrOffset = readStringFromEEPROM(newredstringAddrOffset, &mqtt_data.greenString);
  int newbluestringAddrOffset  = readStringFromEEPROM(newgreenstringAddrOffset, &mqtt_data.blueString);
  int newbrtstringAddrOffset   = readStringFromEEPROM(newbluestringAddrOffset, &mqtt_data.brtString);
  int newonoffstringAddrOffset = readStringFromEEPROM(newbrtstringAddrOffset, &mqtt_data.onoffString);
  // Group topic Reading from EEPROM
  int newroomAddrOffset   = readStringFromEEPROM(newonoffstringAddrOffset, &mqtt_data.room); 

  EEPROM.get((addr + sizeof(prev_data) + sizeof(wifi_cred) + sizeof(mqtt_data)), crntval);
  Serial.print("\nWiFi_ssid:");Serial.println(wifi_cred.creds);
  Serial.print("\nWiFi_password:");Serial.println(wifi_cred.credp);
  Serial.print("\nMQTT_URL:");Serial.println(wifi_cred.credurl);
  Serial.print("\nMQTT_port:");Serial.println(wifi_cred.credport);
}
/**
 * Change State 
 *
 * In this state the flag is reset every 90sec.
 */
void changeState()
{
  Serial.print("\nchangeState:");
  Serial.println(prev_data.control_flag);
  if ((!prev_data.control_flag) || (prev_data.control_flag))
  {
    prev_data.power_on_sequence_flag = 0;
    prev_data.bootup_flag = 0;
    EEPROM.put(addr, prev_data);
    EEPROM.commit();
  }
}
// Delete functionality
void delete_(String mymsg){
  client.publish(mqtt_data.devres.c_str(),String("ACK\t"+mymsg).c_str());  
  delay(1000);
  wifiManager.resetSettings();
  prev_data.configtopic = 0;
  EEPROM.put(addr, prev_data);
  EEPROM.commit();
  eeprom_erase();
  setcoolwhite();
  udp_setup();
  #if WIFICTRL
  Serial.println("Delete command is executed");
  #endif
}
// RGB scenes
void rgb_soft()
{
  count1=count2=count3=0;
  analogWrite(CWONOFF, 0);
  analogWrite(WWHITE, 0);
  analogWrite(RED, 0);
  analogWrite(GREEN,153*count); 
  analogWrite(BLUE, 0);
  if(count == 5){
  count = 1;
  }else{
  count++;
  }
}
void rgb_colorful()
{
  count=count2=count3=0;
  switch(count1){
    case 0: analogWrite(CWONOFF, 0);
            analogWrite(WWHITE, 0);
            analogWrite(RED, 1020);
            analogWrite(GREEN,0); 
            analogWrite(BLUE, 0);
            break;
    case 1: analogWrite(CWONOFF, 0);
            analogWrite(WWHITE, 0);
            analogWrite(RED, 0);
            analogWrite(GREEN,765); 
            analogWrite(BLUE, 0);
            break;
    case 2: analogWrite(CWONOFF, 0);
            analogWrite(WWHITE, 0);
            analogWrite(RED, 0);
            analogWrite(GREEN,0); 
            analogWrite(BLUE, 765);
            break;
    case 3: analogWrite(CWONOFF, 0);
            analogWrite(WWHITE, 0);
            analogWrite(RED, 1020);
            analogWrite(GREEN,0); 
            analogWrite(BLUE, 765);
            break;
    case 4: analogWrite(CWONOFF, 0);
            analogWrite(WWHITE, 0);
            analogWrite(RED, 1020);
            analogWrite(GREEN,765); 
            analogWrite(BLUE, 0);
            break;
    case 5: analogWrite(CWONOFF, 0);
            analogWrite(WWHITE, 0);
            analogWrite(RED, 0);
            analogWrite(GREEN,765); 
            analogWrite(BLUE, 765);
            break; 
     default: break; 
  }
  if(count1 == 6){
    count1=0;
  }else{
      count1++;
  }
}
void rgb_dazzling()
{
  count=count1=count3=0;
  switch(count2){
    case 0: analogWrite(CWONOFF, 0);
            analogWrite(WWHITE, 0);
            analogWrite(RED, 1020);
            analogWrite(GREEN,0); 
            analogWrite(BLUE, 0);
            break;
    case 1: analogWrite(CWONOFF, 0);
            analogWrite(WWHITE, 0);
            analogWrite(RED, 0);
            analogWrite(GREEN,765); 
            analogWrite(BLUE, 0);
            break;
    case 2: analogWrite(CWONOFF, 0);
            analogWrite(WWHITE, 0);
            analogWrite(RED, 0);
            analogWrite(GREEN,0); 
            analogWrite(BLUE, 765);
            break;
    default: break; 
  }
  if(count2 == 3){
    count2=0;
  }else{
      count2++;
  }
}
void rgb_gorgeous()
{
  count=count1=count2=0;
  /*switch(count3 | count4 | count5){
    switch(count3){
          case 0:   analogWrite(CWONOFF, 0);
                    analogWrite(WWHITE, 0);
                    analogWrite(RED, 1020);
                    analogWrite(GREEN,255*count3); 
                    analogWrite(BLUE, 255*count3); 
                    break;
          case 1:   analogWrite(CWONOFF, 0);
                    analogWrite(WWHITE, 0);
                    analogWrite(RED, 1020);
                    analogWrite(GREEN,255*count3); 
                    analogWrite(BLUE, 255*count3); 
                    break;
          case 2:   analogWrite(CWONOFF, 0);
                    analogWrite(WWHITE, 0);
                    analogWrite(RED, 1020);
                    analogWrite(GREEN,255*count3); 
                    analogWrite(BLUE, 255*count3); 
                    break;
          case 3:   analogWrite(CWONOFF, 0);
                    analogWrite(WWHITE, 0);
                    analogWrite(RED, 1020);
                    analogWrite(GREEN,255*count3); 
                    analogWrite(BLUE, 255*count3); 
                    break;
          if(count3 == 4){
              count4=0;
          }else{
            count3++;
          }
    }
    switch(count4){
          case 0:   analogWrite(CWONOFF, 0);
                    analogWrite(WWHITE, 0);
                    analogWrite(RED, 1020);
                    analogWrite(GREEN,255*count3); 
                    analogWrite(BLUE, 255*count3); 
                    break;
          case 1:   analogWrite(CWONOFF, 0);
                    analogWrite(WWHITE, 0);
                    analogWrite(RED, 1020);
                    analogWrite(GREEN,255*count3); 
                    analogWrite(BLUE, 255*count3); 
                    break;
          case 2:   analogWrite(CWONOFF, 0);
                    analogWrite(WWHITE, 0);
                    analogWrite(RED, 1020);
                    analogWrite(GREEN,255*count3); 
                    analogWrite(BLUE, 255*count3); 
                    break;
          case 3:   analogWrite(CWONOFF, 0);
                    analogWrite(WWHITE, 0);
                    analogWrite(RED, 1020);
                    analogWrite(GREEN,255*count3); 
                    analogWrite(BLUE, 255*count3); 
                    break;
          if(count4 == 4){
              count5=0;
          }else{
            count4++;
          }
    }
    switch(count5){
          case 0:   analogWrite(CWONOFF, 0);
                    analogWrite(WWHITE, 0);
                    analogWrite(RED, 1020);
                    analogWrite(GREEN,255*count5); 
                    analogWrite(BLUE, 255*count5); 
                    break;
          case 1:   analogWrite(CWONOFF, 0);
                    analogWrite(WWHITE, 0);
                    analogWrite(RED, 1020);
                    analogWrite(GREEN,255*count5); 
                    analogWrite(BLUE, 255*count5); 
                    break;
          case 2:   analogWrite(CWONOFF, 0);
                    analogWrite(WWHITE, 0);
                    analogWrite(RED, 1020);
                    analogWrite(GREEN,255*count5); 
                    analogWrite(BLUE, 255*count5); 
                    break;
          case 3:   analogWrite(CWONOFF, 0);
                    analogWrite(WWHITE, 0);
                    analogWrite(RED, 1020);
                    analogWrite(GREEN,255*count5); 
                    analogWrite(BLUE, 255*count5); 
                    break;
          if(count5 == 4){
              count3=0;
          }else{
            count5++;
          }
    }

     
  }*/
  analogWrite(CWONOFF, 0);
  analogWrite(WWHITE, 0);
  analogWrite(RED, 1020);
  analogWrite(GREEN,204*count3); 
  analogWrite(BLUE, 204*count3);           
  if(count3 == 5){
    count3=0;
  }else{
      count3++;
  }
}// End of RGB scenes

// EEPROM Erase function
void eeprom_erase(void)         // EEPROM erase
{
  for (int i = 0 ; i < 512 ; i++) {
    EEPROM.write(i, 0);
  }
  EEPROM.commit();
}// End of eeprom_erase

// RGB Ticker disable function
void rgb_ticker_disable(){
    ticker_soft.detach();
    ticker_colorful.detach();
    ticker_dazzling.detach();
    ticker_gorgeous.detach();
}
void multiple_grp(String mymsg, String grp_topic){
  #if WIFICTRL
        Serial.print("Subcribed topic:");Serial.println(mqtt_data.room.c_str());
        Serial.print("Mymsg:");Serial.println(mymsg);
  #endif
      if ((mymsg.startsWith("b")) && (mymsg.endsWith("&"))) 
      { 
        // RGB Ticker disable
        rgb_ticker_disable();           
        brtval = mymsg.indexOf('b');      // Downlight command for brightness & temperature bxxtxx@200& //
        tempval =  mymsg.indexOf('t');
        dl_onoff = mymsg.indexOf('@');
        val_dummy = mymsg.indexOf('&');
        brtstring = mymsg.substring(brtval + 1, tempval);
        tempstring = mymsg.substring(tempval + 1, dl_onoff);
        dl_onoffstring = mymsg.substring(dl_onoff + 1, val_dummy);
        #if WIFICTRL
            Serial.print("brtstring:");Serial.println(brtstring);
            Serial.print("tempstring :");Serial.println(tempstring);
            Serial.print("dl_onoffstring :");Serial.println(dl_onoffstring); 
        #endif
           if((brtstring.toInt() == 0)&& (tempstring.toInt() == 0 ) && (dl_onoffstring.toInt() == 150)){
            delay(50);
           }else{
              crntval.brt = brtstring.toInt();
              crntval.temp = tempstring.toInt();
              crntval.dlonoff = dl_onoffstring.toInt();
           }
        EEPROM.put((addr + sizeof(prev_data) + sizeof(wifi_cred) + sizeof(mqtt_data)), crntval);
        EEPROM.commit();
        #if WIFICTRL
        Serial.print("Calling function for Down Light Functionality@group light");
        #endif
        _Downlight((brtstring.toInt()),(tempstring.toInt()),dl_onoffstring.toInt());
        client.publish(mqtt_data.devres.c_str(),String("ACK\t"+mymsg).c_str());  
      }else if ((mymsg.startsWith("r")) && (mymsg.endsWith("&"))) {      /* RGB command */ // "r201g32b255w100c400&" // RGB command for RGB light
        // RGB Ticker disable
        rgb_ticker_disable();
        Rval = mymsg.indexOf('r');
        Gval = mymsg.indexOf('g');
        Bval = mymsg.indexOf('b');
        Wval = mymsg.indexOf('w');
        Cval = mymsg.indexOf('c');
        val = mymsg.indexOf('&');            
        mqtt_data.redString = mymsg.substring(Rval + 1, Gval);
        mqtt_data.greenString = mymsg.substring(Gval + 1, Bval);
        mqtt_data.blueString = mymsg.substring(Bval + 1, Wval);
        mqtt_data.brtString = mymsg.substring(Wval + 1, Cval);
        mqtt_data.onoffString = mymsg.substring(Cval + 1, val);
        
        if ((mqtt_data.redString.toInt() == 0)   &&
          (mqtt_data.greenString.toInt() == 0) &&
          (mqtt_data.blueString.toInt() == 0) &&
          (mqtt_data.brtString.toInt() == 0)&&
          (mqtt_data.onoffString.toInt()== 400)){
          delay(50);
        }else {
          crntval.red = mqtt_data.redString.toInt();
          crntval.green = mqtt_data.greenString.toInt();
          crntval.blue = mqtt_data.blueString.toInt();
          crntval.warm = mqtt_data.brtString.toInt();
          crntval.cool = mqtt_data.onoffString.toInt();
        }
        setColor(mqtt_data.redString.toInt(),
             mqtt_data.greenString.toInt(),
             mqtt_data.blueString.toInt(),
             mqtt_data.brtString.toInt(),
             mqtt_data.onoffString.toInt());
        //prev_data.device_type = 1;
        EEPROM.put(addr, prev_data);
        EEPROM.put((addr + sizeof(prev_data) + sizeof(wifi_cred) + sizeof(mqtt_data)), crntval);
        EEPROM.commit();
        client.publish(mqtt_data.devres.c_str(),String("ACK\t"+mymsg).c_str());  
        #if WIFIDBUG
        Serial.println("RGB is executed@Group light\nCurrent RGB values is...\n");
        Serial.print("crnt_redvalue:");Serial.println(mqtt_data.redString);
        Serial.print("crnt_greenvalue:");Serial.println(mqtt_data.greenString);
        Serial.print("crnt_bluevalue:");Serial.println(mqtt_data.blueString);
        Serial.print("crnt_Warmwhite value:");Serial.println(mqtt_data.brtString);
        Serial.print("crnt_coolwhite value:");Serial.println(mqtt_data.onoffString);
        // crnt values
        Serial.print("Previous state RGB values is....\nprev_val.red:");Serial.println(crntval.red);
        Serial.print("prev_val.green:");Serial.println(crntval.green);
        Serial.print("prev_val.blue:");Serial.println(crntval.blue);
        Serial.print("prev_val.warm:");Serial.println(crntval.warm);
        Serial.print("prev_val.cool:");Serial.println(crntval.cool);
        #endif
      }
      else if (mymsg == "ACTIVE") 
      {                                // check network status
        client.publish(mqtt_data.devres.c_str(),String("ACK\t"+mymsg+"@"+mqtt_data.room).c_str());
      }// End of check network status  
}
// Dl previous state maintaining
void pre_off_state()
{
    //rgb_ticker_disable();
    rgb_ticker_disable(); 
    if(prev_data.device_type == 1){
      setColor(0,0,0,0,400);
    }else{
      //digitalWrite(CWONOFF,LOW);
       _Downlight(0,0,150);
    }
}
// RGB previous state maintaining
void pre_on_state()
{
      //rgb_ticker_disable();
     rgb_ticker_disable();
     if (prev_data.device_type == 1){
          if ((mqtt_data.redString.toInt() == 0)  &&
              (mqtt_data.greenString.toInt() == 0) &&
              (mqtt_data.blueString.toInt() == 0)  &&
              (mqtt_data.brtString.toInt() == 0)   &&
              (mqtt_data.onoffString.toInt() == 400)) {
              setColor(crntval.red, crntval.green, crntval.blue, crntval.warm, crntval.cool);
          }else{
              setColor(mqtt_data.redString.toInt(),
                   mqtt_data.greenString.toInt(),
                   mqtt_data.blueString.toInt(),
                   mqtt_data.brtString.toInt(),
                   mqtt_data.onoffString.toInt());
          }
     }else{
          if((prev_data.prev_state_brt == 0) && 
            (prev_data.prev_state_brt == 0) && 
            (prev_data.prev_state_led == 150)){
              _Downlight(crntval.brt,crntval.temp,crntval.dlonoff);
          }else{
              _Downlight(prev_data.prev_state_brt,prev_data.prev_state_temp,prev_data.prev_state_led);
          }
     }
}
// Group topic extractions
void grp_extraction(String mymsg)
{
      // RGB Ticker disable                                    //new command gGrouptopic,light1,light2..&
      rgb_ticker_disable(); 
      grp = mymsg.indexOf('g');
      grp_cnt = mymsg.indexOf(',');
      grp_empty = mymsg.indexOf('&');
      mqtt_data.room = mymsg.substring(grp+1,grp_cnt);
      String grp_tot = mymsg.substring(grp_cnt+1,grp_empty);
      Serial.print("\nBefore strtok()");Serial.println(grp_tot);
      byte indx_grp=0;
      int grp_len = grp_tot.length() + 1;
      char grp_array[grp_len];
      grp_tot.toCharArray(grp_array,grp_len);
      ptr = strtok(grp_array, ",");  // delimiter
      while (ptr != NULL)
      {
        strings[indx_grp] = ptr;
        indx_grp++;
        ptr = strtok(NULL, ","); 
      }
      client.subscribe(mqtt_data.room.c_str());delay(50); 
      Serial.print("Group subscription topic is....");Serial.println(mqtt_data.room.c_str());
      Serial.print("Group topic length is....");Serial.println((mqtt_data.room).length());          
      prev_data.index_grp = indx_grp;
      prev_data.grp_flag = 1;
      EEPROM.put(addr, prev_data);
      EEPROM.commit(); 
}
// Downlight extraction
void dl_extraction(String mymsg)
{
    // RGB Ticker disable
    rgb_ticker_disable();
    brtval = mymsg.indexOf('b');tempval =  mymsg.indexOf('t');
    dl_onoff = mymsg.indexOf('@');val_dummy = mymsg.indexOf('&');
    brtstring = mymsg.substring(brtval + 1, tempval);
    tempstring = mymsg.substring(tempval + 1, dl_onoff);
    dl_onoffstring = mymsg.substring(dl_onoff + 1, val_dummy);
    #if WIFICTRL
          Serial.print("brtstring:");Serial.println(brtstring);
          Serial.print("tempstring :");Serial.println(tempstring);
          Serial.print("dl_onoffstring :");Serial.println(dl_onoffstring); 
    #endif
         if((brtstring.toInt() == 0)&& (tempstring.toInt() == 0 ) && (dl_onoffstring.toInt() == 150)){
            delay(50);
         }else{
              crntval.brt = brtstring.toInt();
              crntval.temp = tempstring.toInt();
              crntval.dlonoff = dl_onoffstring.toInt();
         }
    EEPROM.put((addr + sizeof(prev_data) + sizeof(wifi_cred) + sizeof(mqtt_data)), crntval);
    EEPROM.commit();
}
// Rgb data extraction
void rgb_extraction(String mymsg)
{
    // RGB Ticker disable
    rgb_ticker_disable();
    Rval = mymsg.indexOf('r');Gval = mymsg.indexOf('g');Bval = mymsg.indexOf('b');
    Wval = mymsg.indexOf('w');Cval = mymsg.indexOf('c');val = mymsg.indexOf('&');            
    mqtt_data.redString = mymsg.substring(Rval + 1, Gval);
    mqtt_data.greenString = mymsg.substring(Gval + 1, Bval);
    mqtt_data.blueString = mymsg.substring(Bval + 1, Wval);
    mqtt_data.brtString = mymsg.substring(Wval + 1, Cval);
    mqtt_data.onoffString = mymsg.substring(Cval + 1, val);
    if ((mqtt_data.redString.toInt() == 0)   &&
        (mqtt_data.greenString.toInt() == 0) &&
        (mqtt_data.blueString.toInt() == 0) &&
        (mqtt_data.brtString.toInt() == 0)&&
        (mqtt_data.onoffString.toInt()== 400)){
        delay(50);
    }else {
      crntval.red = mqtt_data.redString.toInt();
      crntval.green = mqtt_data.greenString.toInt();
      crntval.blue = mqtt_data.blueString.toInt();
      crntval.warm = mqtt_data.brtString.toInt();
      crntval.cool = mqtt_data.onoffString.toInt();
    }
    setColor(mqtt_data.redString.toInt(),
             mqtt_data.greenString.toInt(),
             mqtt_data.blueString.toInt(),
             mqtt_data.brtString.toInt(),
             mqtt_data.onoffString.toInt());
    //prev_data.device_type = 1;
    EEPROM.put(addr, prev_data);
    EEPROM.put((addr + sizeof(prev_data) + sizeof(wifi_cred) + sizeof(mqtt_data)), crntval);
    EEPROM.commit();
}
void home_light_extractions(String mymsg)
{
  // Extracting the actual topics from the config topic       // Default command /IP&HOME$ROOM*LIGHT#resdynamictopic%  // old architecture
    mqttip = mymsg.indexOf("/");              // Default command /IP&HOME*LIGHT#resdynamictopic%  // new architecture
    char mqtthome = mymsg.indexOf("&");
    //char mqttroom = mymsg.indexOf("$");
    char mqttlight = mymsg.indexOf("*");
    char lightname = mymsg.indexOf("#");
    //String ip = mymsg.substring(mqttip + 1, mqtthome);
    ip = mymsg.substring(mqttip + 1, mqtthome);
    mqtt_data.Home = mymsg.substring(mqtthome + 1, mqttlight);
    //mqtt_data.room = mymsg.substring(mqttroom + 1, mqttlight);
    mqtt_data.light = mymsg.substring(mqttlight + 1, lightname);
    mqtt_data.devres = mymsg.substring(lightname + 1);
    Serial.print("\nmqtt_data.devicename=");Serial.println(mqtt_data.devres);
}
void EEPROM_writing(void)
{
  /******************** EEPROM writing************************************************************/
  EEPROM.put(addr, prev_data);
  // Writing Dynamic topics into EEPROM
  int homeAddrOffset = writeStringToEEPROM((addr + sizeof(prev_data) + sizeof(wifi_cred)), mqtt_data.Home);
  //int roompAddrOffset = writeStringToEEPROM(homeAddrOffset, mqtt_data.room);
  int lightAddrOffset = writeStringToEEPROM(homeAddrOffset, mqtt_data.light);
  int devicenameaddroffset = writeStringToEEPROM(lightAddrOffset, mqtt_data.devres);
  // Writing RGB values into EEPROM
  int redstringAddrOffset = writeStringToEEPROM(devicenameaddroffset, mqtt_data.redString);
  int greenstringAddrOffset = writeStringToEEPROM(redstringAddrOffset, mqtt_data.greenString);
  int bluestringAddrOffset = writeStringToEEPROM(greenstringAddrOffset, mqtt_data.blueString);
  int brtstringAddrOffset = writeStringToEEPROM(bluestringAddrOffset, mqtt_data.brtString);
  int onoffstringAddrOffset = writeStringToEEPROM(brtstringAddrOffset, mqtt_data.onoffString);
  int roompAddrOffset = writeStringToEEPROM(onoffstringAddrOffset,mqtt_data.room); // Group topic writing into EEPROM
  EEPROM.commit();
}