#ifndef _EVENT_QUEUE_
#define _EVENT_QUEUE_

#include "EventDef.h"
#include <stdbool.h>
#include <stdlib.h>

struct _EQueue
{
    uint32_t front,rear,size,capacity;
    event_t *events;
    void (*event_cb)(event_t *mustProcessedEvent);
};
typedef struct _EQueue EventQueue_t;

EventQueue_t *Queue_Init(uint32_t m_capacity);
void Queue_Deinit(EventQueue_t *self);
bool isFull(EventQueue_t *self);
bool isEmpty(EventQueue_t *self);
void enQueue(EventQueue_t *self,event_t *ev);
event_t *deQueue(EventQueue_t *self);

#endif