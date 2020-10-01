#ifndef _RELAY_EVENTS_
#define _RELAY_EVENTS_

#include<stdint.h>

struct _Event
{
    uint8_t RelayNo;
    uint8_t State;
};
typedef struct _Event event_t;


#endif