# EventLib
Event library written for  MCU to process same type of event  

This Repository contains event procesing Library for same type of event.

Example Code with Arduino
```
#include "EventProcessor.h"


void my_callback(event_t *ev)
{
  Serial.print("Relay No : ");
  Serial.print(ev->RelayNo);
  Serial.print(" State : ");
  Serial.print(ev->State?"On":"Off");
  Serial.println();
}


EventQueue_t *myEvents;
event_t testEvents[2];
bool state1=0,state2=0;
void setup()
{
  Serial.begin(115200);
  pinMode(2,OUTPUT);
  pinMode(3,OUTPUT);
  myEvents=Queue_Init(10);
  myEvents->event_cb=my_callback;
  delay(3000);
  attachInterrupt(digitalPinToInterrupt(2), interruptHandlerPin2, RISING );
  attachInterrupt(digitalPinToInterrupt(3), interruptHandlerPin3, RISING );


}

void loop() 
{
  if(getNofEvents(myEvents)>0)
  {
    processEvents(myEvents);
  }
}
void interruptHandlerPin2()
{
  state1=state1 ? 0:1;
  testEvents[0].RelayNo=2;
  testEvents[0].State=state1;
  enQueue(myEvents,&testEvents[0]);

}
void interruptHandlerPin3()
{
  state2=state2 ? 0:1;
  testEvents[1].RelayNo=3;
  testEvents[1].State=state2;
  enQueue(myEvents,&testEvents[1]);

}
```
