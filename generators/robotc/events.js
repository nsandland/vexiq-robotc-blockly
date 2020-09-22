Blockly.RobotC.typedefs_.push(`
typedef ubyte Event;
`);

Blockly.RobotC.events = `

Event EVENT_ACTIVE = 0x01;
Event EVENT_QUEUED = 0x02;

void queue_event(Event &event) {
  event |= EVENT_QUEUED;
}

void dequeue_event(Event &event) {
  event &= ~EVENT_QUEUED;
}

void activate_event(Event &event) {
  event |= EVENT_ACTIVE;
}

void deactivate_event(Event &event) {
  event &= ~EVENT_ACTIVE;
}

bool event_is_queued(Event event) {
  return (bool)(event & EVENT_QUEUED);
}

bool event_is_active(Event event) {
  return (bool)(event & EVENT_ACTIVE);
}

void advance_event(Event &event) {
  if (event_is_queued(event)) {
    dequeue_event(event);
    activate_event(event);
  } else {
    deactivate_event(event);
  }
}

`;

Blockly.RobotC.addReservedWords(
  'Event,' +
  'EVENT_ACTIVE,EVENT_QUEUED,' +
  'queue_event,dequeue_event,' +
  'activate_event,deactiveate_event,' + 
  'advance_event,' +
  'event_is_queued,event_is_active');
  