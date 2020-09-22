Blockly.RobotC.events = `

var EVENT_ACTIVE = ltov(1);
var EVENT_QUEUED = ltov(2);

void queue_event(var event) {
  vset(event, vbitwiseor(event, EVENT_QUEUED));
}

void dequeue_event(var event) {
  vset(event, vbitwiseand(event, EVENT_ACTIVE));
}

void activate_event(var event) {
  vset(event, vbitwiseor(event, EVENT_ACTIVE);
}

void deactiveate_event(var event) {
  vset(event, vbitwiseand(event, EVENT_QUEUED))
}

void advance_event(var event) {
  if (event_is_queued(event)) {
    dequeue_event(event);
    activate_event(event);
  } else {
    deactivate_event();
  }
}

void event_is_queued(var event) {
  return vbitwiseand(event, EVENT_QUEUED) > 0;
}

void event_is_active(var event) {
  return vbitwiseand(event, EVENT_ACTIVE) > 0;
}

`;

Blockly.RobotC.addReservedWords(
  'EVENT_ACTIVE,EVENT_QUEUED,' +
  'queue_event,dequeue_event,' +
  'activate_event,deactiveate_event,' + 
  'advance_event,' +
  'event_is_queued,event_is_active');
  