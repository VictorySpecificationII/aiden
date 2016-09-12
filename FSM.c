#include <stdio.h>
#include <stdlib.h>

/* Define the states and events. If your state machine program has multiple
source files, you would probably want to put these definitions in an "include"
file and #include it in each source file. This is because the action
procedures need to update current_state, and so need access to the state
definitions. */
            
enum states { STATE_0, STATE_1, STATE_2, STATE_3, MAX_STATES }current_state;
enum events { EVENT_0, EVENT_1, EVENT_2, MAX_EVENTS }new_event;


/* Provide the fuction prototypes for each action procedure. In a real
program, you might have a separate source file for the action procedures of 
each state. Then you could create a .h file for each of the source files, 
and put the function prototypes for the source file in the .h file. Instead 
of listing the prototypes here, you would just #include the .h files. */

void action_s0_e0(void);
void action_s0_e1(void);
void action_s0_e2(void);
void action_s1_e0(void);
void action_s1_e1(void);
void action_s1_e2(void);
void action_s2_e0(void);
void action_s2_e1(void);
void action_s2_e2(void);
void action_s3_e0(void);
void action_s3_e1(void);
void action_s3_e2(void);

enum events get_new_event (void);

/* Define the state/event lookup table. The state/event order must be the
same as the enum definitions. Also, the arrays must be completely filled - 
don't leave out any events/states. If a particular event should be ignored in 
a particular state, just call a "do-nothing" function. */

void (*const state_table [MAX_STATES][MAX_EVENTS]) (void) = {

    { action_s0_e0, action_s0_e1, action_s0_e2 },
    { action_s1_e0, action_s1_e1, action_s1_e2 },
    { action_s2_e0, action_s2_e1, action_s2_e2 },
    { action_s3_e0, action_s3_e1, action_s3_e2 }
};

/* This is the heart of the state machine - where you execute the proper 
action procedure based on the new event you have to process and your current 
state. It's important to make sure the new event and current state are 
valid, because unlike "switch" statements, the lookup table method has no 
"default" case to catch out-of-range values. With a lookup table, 
out-of-range values cause the program to crash! */

void main (void)
{
        printf("Current state %u\n",current_state);
        printf("Current event %u\n",new_event);
        printf("---------------\n");
    

    while((current_state < 4)&&(new_event <3)){
    //while(current_state < STATE_2){ //Original statement, ends at State 2 Event 0

        

    if (((new_event >= 0) && (new_event < MAX_EVENTS))
    && ((current_state >= 0) && (current_state < MAX_STATES))) {

        state_table [current_state][new_event] (); /* call the action procedure */
        
        new_event = get_new_event (); /* get the next event to process */

    } 

    else {

        /* invalid event/state - handle appropriately */
        printf("invalid event/state %u/%u\n",new_event,current_state);
        exit(0);
    }
}
    printf("STATE_2, scheduled exit %u %u\n",current_state,new_event);
    exit(0);
}

/* In an action procedure, you do whatever processing is required for the
particular event in the particular state. Among other things, you might have
to set a new state. */

void action_s0_e0(void)
{
    printf("action_s0_e0() %u %u\n",current_state,new_event);
    //current_state = STATE_0;
}

void action_s0_e1(void)
{
    printf("action_s0_e1() %u %u\n",current_state,new_event);
    //current_state = STATE_0;
}


void action_s0_e2(void)
{
    printf("action_s0_e2() %u %u\n",current_state,new_event);
    //current_state = STATE_0;
}


void action_s1_e0(void)
{
    printf("action_s1_e0() %u %u\n",current_state,new_event);
    //current_state = STATE_1;
}


void action_s1_e1(void)
{
    printf("action_s1_e1() %u %u\n",current_state,new_event);
    //current_state = STATE_1;
}


void action_s1_e2(void)
{
    printf("action_s1_e2() %u %u\n",current_state,new_event);
    //current_state = STATE_1;
}


void action_s2_e0(void)
{
    printf("action_s2_e0() %u %u\n",current_state,new_event);
    //current_state = STATE_2;
}


void action_s2_e1(void)
{
    printf("action_s2_e1() %u %u\n",current_state,new_event);
    //current_state = STATE_2;
}


void action_s2_e2(void)
{
    printf("action_s2_e2() %u %u\n",current_state,new_event);
    //current_state = STATE_2;
}

void action_s3_e0(void)
{
    printf("action_s3_e0() %u %u\n", current_state, new_event);
}

void action_s3_e1(void)
{
    printf("action_s3_e1() %u %u\n", current_state, new_event);
}
void action_s3_e2(void)
{
    printf("action_s3_e2() %u %u\n", current_state, new_event);
}


/* Return the next event to process - how this works depends on your
application. */

enum events get_new_event (void)
{
        if(new_event == 2){
            new_event = 0;
            current_state++;
            return new_event;
        }
        else
        return (++new_event);
}