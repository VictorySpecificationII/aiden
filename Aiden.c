//Author: Antreas Christofi
//Name: Project Aiden
//Function: Companion with voice recognition and responses
//Inputs: Gearbox Control, Engine Management System, User(Voice/Text)
//Outputs: Voice, Text

//On boot: If first boot of day, use certain responses for time of day.
//On boot: If not first boot of the day, do not use certain responses only meant for first boot.

//States:
//Sleeping
//Idle
//Awake
//Monitoring
//Interacting

//State Transitions:
//Sleeping -> Awake(Key turn)
//Awake -> Sleeping(Key turn)

//Monitoring -> Idle
//Interacting -> Idle

//Cycle:
//Sleeping -> Awake -> Monitoring <-> Idle <-> Interacting
//Idle -> Sleeping

//Strings
char greeting[] = "Hello, I'm Aiden - Andrew's car. \n \n Caught you by surprise, didn't it?";

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

char lowenginetemp[]="Time to warm up! Give me five minutes."
char rightenginetemp[]="That's about right. Time to go?"
char highenginetemp[]="My system is heating up, I need to cool down for a bit.";

char highEGT[]="My exhaust temperatures are high. Check the maps.";

char leanmix[]="I'm scared. I'm running too lean..."
char richmix[]="*Coughs* I'm getting too much fuel, please tweak my map."

char overboost[]="I'm having fun too, but please check my boost level. Something feels odd here."
char knock[]="Something hurts, I don't think that's good." 


//todo: define types for functions
checkTime(){
	//check current time
}

checkForFirstBoot(){
	//check for first boot of the day
}

calculateAverageTripSpeed(){
	//calculate average trip speed
}
checkForShutDown(){
	//check for shutdown conditions
}
checkFuel(){
	//check fuel level
}

checkBoost(){
	//check boost level
}

checkForKnock(){
	//check for knock
} 

checkForEngineTemp(){
	//check for engine temp
}

checkForMixture(){
	//check for mixture
}

checkForEGT(){
	//check for EGT
}


int main(){
//int main(int argc, char *argv[]){
	printf("%s\n", greeting );
	return 0;
}



