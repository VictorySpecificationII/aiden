//------------------------STATE TRANSITION FUNCTIONALITY BELOW------------------------//

void do_initial_to_sleeping(instance_data_t *data){

}
void do_sleeping_to_awake(instance_data_t *data){

}
void do_awake_to_sleeping(instance_data_t *data){

}
void do_idle_to_awake(instance_data_t *data){

}
void do_awake_to_idle(instance_data_t *data){

}
void do_idle_to_monitoring(instance_data_t *data){

}
void do_idle_to_interacting(instance_data_t *data){

}
void do_sleep_to_exit(instance_data_t *data){
	
}

void printState(int i){
  printf("Current state is:%d", i);  
}


//------------------------STATE TRANSITION FUNCTIONALITY ABOVE------------------------//


//------------------------STATE FUNCTIONALITY BELOW------------------------//
//TODO: add functionality here
state_t do_state_entry(instance_data_t *data){
int i = 0;
printState(i);
}

state_t do_state_sleeping(instance_data_t *data){
int i = 1;
printState(i);
}
state_t do_state_awake(instance_data_t *data){
int i = 2;
printState(i);
}
state_t do_state_monitoring(instance_data_t *data){
int i = 3;
printState(i);
}
state_t do_state_idle(instance_data_t *data){
int i = 4;
printState(i);
}
state_t do_state_interacting(instance_data_t *data){
int i = 5;
printState(i);
}
state_t do_state_exit(instance_data_t *data){
int i = 6;
printState(i);
}
