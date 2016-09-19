import aiml
import os

kernel = aiml.Kernel()

sessionId = 12345


#Aiden was born on September 16th, 2016.

# Get session info as dictionary. Contains the input
# and output history as well as any predicates known
sessionData = kernel.getSessionData(sessionId)

# Each session ID needs to be a unique value
# The predicate name is the name of something/someone
# that the bot knows about in your session with the bot
# The bot might know you as "Billy" and that your "dog" is named "Brandy"
#kernel.setPredicate("dog", "Brandy", sessionId)
#clients_dogs_name = kernel.getPredicate("dog", sessionId)

#kernel.setBotPredicate("hometown", "127.0.0.1")
#bot_hometown = kernel.getBotPredicate("hometown")

if os.path.isfile("aidens_brain.brn"):
    kernel.bootstrap(brainFile = "aidens_brain.brn")
else:
    kernel.bootstrap(learnFiles = "std-startup.xml")
    #kernel.saveBrain("aidens_brain.brn")
    print "Dad, I can't load the .brn file - I can't find one. What should I do?"

# kernel now ready for use
while True:
	
    message = raw_input(">> ")
    
    if message == "quit":
        exit()
    elif message == "save":
        kernel.saveBrain("aidens_brain.brn")
    elif message == "clear":
    	os.system("clear")
    elif message == "reset Aiden":
    	os.system("rm aidens_brain.brn")
    elif message == "reload xml":
    	kernel.bootstrap(learnFiles = "std-startup.xml")
    else:
        bot_response = kernel.respond(message)
        print bot_response