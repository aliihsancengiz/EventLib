#include "EventProcessor.h"
#include <stdio.h>

void my_callback(event_t *ev)
{
    printf("Relay No %d State %d\n",ev->RelayNo,ev->State);
}

int main()
{
    event_t relay_events[3]={{0,0},{2,1},{1,0}};
    EventQueue_t *My_events=Queue_Init(5);
    My_events->event_cb=my_callback;
    for (size_t i = 0; i < 3; i++)
    {
        enQueue(My_events,&relay_events[i]);
    }
    while(getNofEvents(My_events)>0)
    {
        processEvents(My_events);
    }
    Queue_Deinit(My_events);
    return 0;
}