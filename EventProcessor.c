#include "EventProcessor.h"


void processEvents(EventQueue_t *dispatchQueue)
{
    event_t *processedEvent=deQueue(dispatchQueue);
    dispatchQueue->event_cb(processedEvent);
}
uint32_t getNofEvents(EventQueue_t *dispatchQueue)
{
    return dispatchQueue->size;
}