#include <stdio.h>

/* Define the states and events. If your state machine program has multiple
source files, you would probably want to put these definitions in an "include"
file and #include it in each source file. This is because the action
procedures need to update current_state, and so need access to the state
definitions. */

//            STATE    STATE    STATE    STATE    STATE  
//            ENTRY    IDLE     MONITOR  INTERACT EXIT
enum states { STATE_1, STATE_2, STATE_3, STATE_4, STATE_5, MAX_STATES } current_state;
enum events { EVENT_1, EVENT_2, MAX_EVENTS } new_event;

/* Provide the fuction prototypes for each action procedure. In a real
program, you might have a separate source file for the action procedures of 
each state. Then you could create a .h file for each of the source files, 
and put the function prototypes for the source file in the .h file. Instead 
of listing the prototypes here, you would just #include the .h files. */

void action_s1_e1 (void);
void action_s1_e2 (void);

void action_s2_e1 (void);
void action_s2_e2 (void);

void action_s3_e1 (void);
void action_s3_e2 (void);

void action_s4_e1 (void);
void action_s4_e2 (void);

void action_s5_e1 (void);
void action_s5_e2 (void);

/*
void checkForFirstBoot (void);
void calculateAverageTripSpeed (void);

void checkForShutDown (void);
void checkFuel (void);

void checkBoost (void);
void checkForKnock (void);

void checkForEngineTemp(void);
void checkForMixture (void);

void checkForEGT (void);
*/



enum events get_new_event (void);

/* Define the state/event lookup table. The state/event order must be the
same as the enum definitions. Also, the arrays must be completely filled - 
don't leave out any events/states. If a particular event should be ignored in 
a particular state, just call a "do-nothing" function. */

void (*const state_table [MAX_STATES][MAX_EVENTS]) (void) = {

    { action_s1_e1, action_s1_e2 }, /* procedures for state 1 */
    { action_s2_e1, action_s2_e2 }, /* procedures for state 2 */
    { action_s3_e1, action_s3_e2 },  /* procedures for state 3 */
    { action_s4_e1, action_s4_e2 }, /* procedures for state 4 */
    { action_s5_e1, action_s5_e2 }  /* procedures for state 5 */
};

/* This is the heart of the state machine - where you execute the proper 
action procedure based on the new event you have to process and your current 
state. It's important to make sure the new event and current state are 
valid, because unlike "switch" statements, the lookup table method has no 
"default" case to catch out-of-range values. With a lookup table, 
out-of-range values cause the program to crash! */

void main (void)
{
    new_event = get_new_event (); /* get the next event to process */

    if (((new_event >= 0) && (new_event < MAX_EVENTS))
    && ((current_state >= 0) && (current_state < MAX_STATES))) {

        state_table [current_state][new_event] (); /* call the action procedure */

    } else {

        /* invalid event/state - handle appropriately */
    }
}

/* In an action procedure, you do whatever processing is required for the
particular event in the particular state. Among other things, you might have
to set a new state. */

void action_s1_e1 (void)
{
    /* do some processing here */

   char greeting[6] = {'H', 'e', 'l', 'l', 'o', '\0'};
   printf("Greeting message: %s\n", greeting );

    current_state = STATE_2; /* set new state, if necessary */
}

void action_s1_e2 (void) {}  /* other action procedures */
void action_s2_e1 (void) {}
void action_s2_e2 (void) {}
void action_s3_e1 (void) {}
void action_s3_e2 (void) {}
void action_s4_e1 (void) {}
void action_s4_e2 (void) {}
void action_s5_e1 (void) {}
void action_s5_e2 (void) {}




/*
void action_checkForFirstBoot (void){
    //check for first boot of the day
}

void action_calculateAverageTripSpeed (void){
    //calculate average trip speed
}
void action_checkForShutDown (void){
    //check for shutdown conditions
}
void action_checkFuel (void){
    //check fuel level
}

void action_checkBoost (void){
    //check boost level
}

void action_checkForKnock (void){
    //check for knock
} 

void action_checkForEngineTemp (void){
    //check for engine temp
}

void action_checkForMixture (void){
    //check for mixture
}

void action_checkForEGT (void){
    //check for EGT
}

*/



/* Return the next event to process - how this works depends on your
application. */

enum events get_new_event (void)
{
    return EVENT_1;
}