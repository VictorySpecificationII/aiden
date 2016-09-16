//Author: Antreas Christofi
//Name: Project Aiden
//Function: Companion with voice recognition and responses
//Inputs: Gearbox Control, Engine Management System, User(Voice/Text)
//Outputs: Voice, Text

//On boot: If first boot of day, use certain responses for time of day.
//On boot: If not first boot of the day, do not use certain responses only meant for first boot.

//structure equivalent to Arduino's setup() and loop() functions, setup called from inside main in this case

//FSM states

//Entry(from setup)
//Monitoring
//Interacting
//Exit(from loop)

//Entry and Exit states do have functionality - Entry loads up the database among other things, exit saves everything then exits

//State Transitions:
//Entry -> Interacting(Key turn, boot)

//Monitoring <-> Interacting

//Monitoring -> Exit(Program terminates)


//Events during states
//--------------------------

//Setup:

//Load database

//-----------------------------LOOP----------------------------//
//check db for first boot of the day
//go to interact for message
//wait for user input
//exit interacting state, go to monitoring state
//Check if ignition key off
//If ignition key off, interact with user, save logs and exit

//Monitoring
//get sample rate in Hz
//set thresholds for alarms
//while (monitoring)
//run all monitoring functions
//scan inputs
//compare results to threshold values set by user
//if any violations happen, flag violations and go to interacting state

//Interacting
//if came from boot, check boot and issue response
//boolean camefromboot turns false so it doesn't run again for the session

//get flags
//choose response from database 
//interact with user
//go to monitoring state

//Exit
//Save session results
//turn camefromboot to true so it can run through the greeting routine on next startup

//-----------------------------LOOP----------------------------//

#include <stdio.h>
#include <time.h>

#define SIZE 256


//todo: define types for functions
void checkTime(){
  //FUNCTION VARIABLES, caps so your blind ass can see them
  time_t curtime;//current time
  struct tm *loctime;//struct that converts time to local time representation using time.h

  /* Get the current time. */
  curtime = time (NULL);
}

void printTime(){
  char buffer[SIZE];//buffer for output
  time_t curtime;//current time
  struct tm *loctime;//struct that converts time to local time representation using time.h

  /* Convert it to local time representation. */
  loctime = localtime (&curtime);

  /* Print out the date and time in the standard format. */
  //fputs (asctime (loctime), stdout);
  /*Print out raw time*/
  printf("Raw time converted to long long is: %lld\n", (long long) curtime);

  /* Print it out in a nice format. */
  strftime (buffer, SIZE, "Today is %A, %B %d", loctime);
  fputs (buffer, stdout);
  strftime (buffer, SIZE, " and the time is %I:%M %p.\n", loctime);
  fputs (buffer, stdout);
  
  //flush output to keep things clean
  fflush(stdout);
  

//checkForFirstBoot(){
	//check for first boot of the day
//}

//calculateAverageTripSpeed(){
	//calculate average trip speed
//}
//checkForShutDown(){
	//check for shutdown conditions
//}
//checkFuel(){
	//check fuel level
//}

//checkBoost(){
	//check boost level
//}

//checkForKnock(){
	//check for knock
//} 

//checkForEngineTemp(){
	//check for engine temp
//}

//checkForMixture(){
	//check for mixture
//}

//checkForEGT(){
	//check for EGT
//}

//EQUAL TO SETUP METHOD IN ARDUINO
void setup(){
  //stub, implement startup behaviour
}


//EQUAL TO LOOP METHOD IN ARDUINO CODE
int main(int argc, char *argv[]){
	printf("%s\n", greeting);
	checkTime();
	printTime();
	return 0;
}



