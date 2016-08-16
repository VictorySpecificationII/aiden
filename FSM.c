//enumerating states
typedef enum {STATE_ENTRY, STATE_SLEEPING, STATE_AWAKE, STATE_MONITORING, STATE_IDLE, STATE_INTERACTING, STATE_EXIT, NUM_STATES} state_t;

//enumerating process codes
//typedef enum {STATE_CHANGE_OK, STATE_CHANGE_FAILED, STATE_REPEATED} state_status_t;

//declaring instance data structure
typedef struct instance_data instance_data_t;

//declaring struct
struct instance_data {
	double fuel;
	double temp;
	double EGT;
	int knock;
	double AFR;
	double boost;
	double tripAvgSpeed;
	int firstBoot;
	int boot;
	int shutDown;
	char[] msg;
};

//declaring state type
typedef state_t state_func_t(instance_data_t *data);
//declaring transaction type
typedef void transition_func_t(instance_data_t *data);

//declare transaction functions
void do_initial_to_sleeping(instance_data_t *data);
void do_sleeping_to_awake(instance_data_t *data);
void do_awake_to_sleeping(instance_data_t *data);
void do_idle_to_awake(instance_data_t *data);
void do_awake_to_idle(instance_data_t *data);
void do_idle_to_monitoring(instance_data_t *data);
void do_idle_to_interacting(instance_data_t *data);
void do_sleep_to_exit(instance_data_t *data);


//declaring state and data to be used in state
state_t do_state_entry(instance_data_t *data);
state_t do_state_sleeping(instance_data_t *data);
state_t do_state_awake(instance_data_t *data);
state_t do_state_monitoring(instance_data_t *data);
state_t do_state_idle(instance_data_t *data);
state_t do_state_interacting(instance_data_t *data);
state_t do_state_exit(instance_data_t *data);

//------------------------STATE FUNCTIONALITY BELOW------------------------//
//TODO: add functionality here
state_t do_state_entry(instance_data_t *data){

}

state_t do_state_sleeping(instance_data_t *data){

}
state_t do_state_awake(instance_data_t *data){

}
state_t do_state_monitoring(instance_data_t *data){

}
state_t do_state_idle(instance_data_t *data){

}
state_t do_state_interacting(instance_data_t *data){

}
state_t do_state_exit(instance_data_t *data){

}


//------------------------STATE FUNCTIONALITY ABOVE------------------------//

//state table declaration
state_func_t* const state_table[NUM_STATES]={
	do_state_entry, do_state_sleeping, do_state_awake, do_state_idle, do_state_monitoring, do_state_interacting, do_state_exit
};

//transition table declaration

transition_func_t * const transition_table[NUM_STATES][NUM_STATES]={
	
	{do_state_entry, do_state_sleeping},
	{do_state_sleeping, do_state_exit},
	
	{do_state_sleeping, do_state_awake},
	{do_state_awake, do_state_sleeping},
	
	{do_state_awake, do_state_idle},
	{do_state_idle, do_state_awake},
	
	{do_state_idle, do_state_monitoring},
	{do_state_idle, do_state_interacting},
	
	{do_state_monitoring, do_state_idle},
	{do_state_interacting, do_state_idle}
	
};

//function to run state with data needed for state to run
state_t run_state( state_t cur_state, instance_data_t *data ) {
    state_t new_state = state_table[ cur_state ]( data );
    transition_func_t *transition =
               transition_table[ cur_state ][ new_state ];

    if ( transition ) {
        transition( data );
    }

    return new_state;
};

int main( void ) {
    state_t cur_state = STATE_ENTRY;
    instance_data_t data;

    while ( 1 ) {
        cur_state = run_state( cur_state, &data );
        //todo:refer to design file to implement state switching
        //todo: implement state status codes too!
        // do other program logic, run other state machines, etc
    }
}