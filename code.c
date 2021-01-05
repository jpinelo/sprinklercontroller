
int solenoidPin_1 = 11; 
int solenoidPin_2 = 12;                           //This is the output pin on the Arduino for Zone 1
int solenoidPin_3 = 13;                           //This is the output pin on the Arduino for Zone 2
int ledPin_blue = 2;
unsigned long duration_watering = 1800000;           // Duration of each watering (sprinklers on)
unsigned long wait_betwneen_zones = 300000;                // Delay between finishing one zone ans starting next (time to cool off system)
unsigned long wait_between_cycles = 36000000;              // Delay between watering cycles, to give the plants time to soak in before new cycle
unsigned long daily_op_time = duration_watering * 6 + wait_betwneen_zones * 4 + wait_between_cycles;  // Sum of duration of all daily operations minus the main wait
unsigned long daily_wait = 86400000 - daily_op_time;       // 24 hours minus daily_op_time = wait to start tomorro at approx. same time = starting time +24hrs - operation time


void setup() {
  // put your setup code here, to run once:
    pinMode(solenoidPin_1, OUTPUT);           //Sets the pins as outputs
    pinMode(solenoidPin_2, OUTPUT);
    pinMode(solenoidPin_3, OUTPUT);
    pinMode(ledPin_blue, OUTPUT);
}

void loop() {
  // code run repeatedly: 
// watering zone 1 - Trees
  digitalWrite(solenoidPin_1, HIGH);                   //Switch Solenoid ON
  digitalWrite(ledPin_blue, HIGH);                     //turn on LED
  delay(duration_watering);                            //Wait - water for 30 Minutes 
  digitalWrite(solenoidPin_1, LOW);                    //Switch Solenoid OFF
  digitalWrite(ledPin_blue, LOW);                      //turn off LED
  delay(wait_betwneen_zones);                          //Wait for next zone

// watering zone 2 - Back Gate
  digitalWrite(solenoidPin_2, HIGH);                   //Switch Solenoid ON
  digitalWrite(ledPin_blue, HIGH);                     //turn on LED
  delay(duration_watering);                            //Wait - water for 30 Minutes 
  digitalWrite(solenoidPin_2, LOW);                    //Switch Solenoid OFF
  digitalWrite(ledPin_blue, LOW);                      //turn off LED
  delay(wait_betwneen_zones);                          //Wait for next zone

// Watering zone 3 - Living Room
  digitalWrite(solenoidPin_3, HIGH);                    //Switch Solenoid ON
  digitalWrite(ledPin_blue, HIGH);
  delay(duration_watering);                             //Wait - water for 30 Minutes
  digitalWrite(solenoidPin_3, LOW);                     //Switch Solenoid OFF
  digitalWrite(ledPin_blue, LOW);
  delay(wait_between_cycles);                           //Wait for next cycle


// watering zone 1 - Trees
  digitalWrite(solenoidPin_1, HIGH);                    //Switch Solenoid ON
  digitalWrite(ledPin_blue, HIGH);
  delay(duration_watering);                            //Wait - water for 30 Minutes 
  digitalWrite(solenoidPin_1, LOW);                     //Switch Solenoid OFF
  digitalWrite(ledPin_blue, LOW);
  delay(wait_betwneen_zones);                           //Wait for next zone

// Watering zone 2 - Back Gate
  digitalWrite(solenoidPin_2, HIGH);                    //Switch Solenoid ON
  digitalWrite(ledPin_blue, HIGH);
  delay(duration_watering);                             //Wait - water for 30 Minutes
  digitalWrite(solenoidPin_2, LOW);                     //Switch Solenoid OFF
  digitalWrite(ledPin_blue, LOW);
  delay(wait_betwneen_zones);                            //Wait for next zone 

// Watering zone 3 - Living Room
  digitalWrite(solenoidPin_3, HIGH);                    //Switch Solenoid ON
  digitalWrite(ledPin_blue, HIGH);
  delay(duration_watering);                             //Wait - water for 30 Minutes
  digitalWrite(solenoidPin_3, LOW);                     //Switch Solenoid OFF
  digitalWrite(ledPin_blue, LOW);
  delay(daily_wait);                                     //Wait for next day 

}

// 24 hours = 86400000
// 600 Minutes = 10 Hours = 36000000
// 480 Minutes = 8 hours = 28800000
// 240 Minutes  = 4 Hours = 14400000 
// 120 Minutes = 2 Hours = 7200000
// 60 Minutes = 3600000
// 30 Minutes = 1800000
// 15 Minutes = 900000
// 5 Minutes = 300000
// 1 Minute = 60000
// 30 secs = 30000
// 15 secs = 15000
