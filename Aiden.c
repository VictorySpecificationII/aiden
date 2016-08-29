//Author: Antreas Christofi
//Name: Project Aiden
//Function: Companion with voice recognition and responses
//Inputs: Gearbox Control, Engine Management System, User(Voice/Text)
//Outputs: Voice, Text

//On boot: If first boot of day, use certain responses for time of day.
//On boot: If not first boot of the day, do not use certain responses only meant for first boot.

//States:
//Entry
//Idle
//Monitoring
//Interacting
//Exit

//Entry and Exit states do have functionality - Entry loads up the database among other things, exit saves everything then exits

//State Transitions:
//Entry -> Interacting(Key turn, boot)

//Monitoring <-> Idle
//Interacting <-> Idle

//Idle -> Exit(Program terminates)


//Events during states
//--------------------------

//Entry
//Load database
//Check for first boot

//-----------------------------LOOP----------------------------//
//Idle
//If came from entry, go to interact for message
//While idle, keep monitoring
//Check if ignition key off
//If ignition key off, interact with user, save logs and exit

//Monitoring
//scan inputs
//if any parameters off, go to interacting state

//Interacting
//get parameters that are off
//choose response from database 
//interact with user
//go to idle state
//-----------------------------LOOP----------------------------//

#include <stdio.h>
#include <time.h>

#define SIZE 256

//Strings
char greeting[] = "Hello, I'm Aiden - Andrew's car. \n \nCaught you by surprise, didn't it?";

char morningfirstboot[] = "*Yawns* Hey, good morning. What's the occasion? \n \n Did you bring me a coffee as well?";
char noonfirstboot[]="*Yawns* what time is it? Damn, spent all day in the sheets again?";
char afternoonfirstboot[]="...and...oh hi! Haven't seen you around all day. \n \n Let's go!";
char nightfirstboot[]="Finally! I'm sick of sitting here. Where are we off to?";
char midnightfirstboot[]="You can't fool me, the only reason you woke me up is because the highway's empty. \n \n Time to run.";

char shutdownslow[] ="That was disappointingly slow. I want to run! Promise we'll go faster next time?";
char shutdownfast[]="Whoo! That was a good run. Anyway, see you later - I'm off to get some sleep too.";

char date[]="My sensors tell me there's someone in the passenger seat. \n \n My camera sees a girl. \n \n Wow - she's really pretty!";

char lowfuel[]="I'm hungry... feed meh.";
char halftank[]="I've digested half my meal. Prepare your wallet soon.";
char fulltank[]="Yum, feels good. Thank you! \n \n  *burps* \n \n  Whoops!";

char lowenginetemp[]="Time to warm up! Give me five minutes.";
char rightenginetemp[]="That's about right. Time to go?";
char highenginetemp[]="My system is heating up, I need to cool down for a bit.";

char highEGT[]="My exhaust temperatures are high. Check the maps.";

char leanmix[]="I'm scared. I'm running too lean...";
char richmix[]="*Coughs* I'm getting too much fuel, please tweak my map.";

char overboost[]="I'm having fun too, but please check my boost level. Something feels odd here.";
char knock[]="Something hurts, I don't think that's good.";


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
  

}


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


int main(){
//int main(int argc, char *argv[]){
	printf("%s\n", greeting);
	checkTime();
	printTime();
	return 0;
}



