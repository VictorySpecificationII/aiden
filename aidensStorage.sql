--Database: Aiden

CREATE TABLE IF NOT EXISTS handlers
(
ID Integer PRIMARY KEY AUTOINCREMENT,
handle char(128) NOT NULL,
passwd char(128) NOT NULL 
)

CREATE TABLE IF NOT EXISTS sessions
(
ID Integer PRIMARY KEY AUTOINCREMENT,
handler char(128) NOT NULL,
sessiontype char(24) NOT NULL,
sessiondate date NOT NULL, 
sessiontime time NOT NULL,
sessiondistancetravelled DOUBLE PRECISION NOT NULL,
sessionavgspeed DOUBLE PRECISION NOT NULL,
sessionavgcoolanttemp DOUBLE PRECISION NOT NULL,
sessionduration BIGINT NOT NULL, --UNIX time stamp format, hence the big int type
sessionfirstboot BIT NOT NULL DEFAULT 0,
sessionmorningboot BIT NOT NULL DEFAULT 0,
sessionnoonboot BIT NOT NULL DEFAULT 0,
sessionafternoonboot BIT NOT NULL DEFAULT 0,
sessionnightfirstboot BIT NOT NULL DEFAULT 0,
sessionmidnightfirstboot BIT NOT NULL DEFAULT 0

)

CREATE TABLE IF NOT EXISTS boot 
(
ID Integer PRIMARY KEY AUTOINCREMENT,
handler char(128) NOT NULL,
boottime time NOT NULL,
bootdate date NOT NULL,
firstboot BIT NOT NULL DEFAULT 0
)

CREATE TABLE IF NOT EXISTS shutdown
(
ID Integer PRIMARY KEY AUTOINCREMENT,
shutdowntime time NOT NULL,
shutdowndate date NOT NULL,
shutdownslow BIT NOT NULL DEFAULT 0,
shutdownfast BIT NOT NULL DEFAULT 0
--wont add avg speed field as the BIT value t/f is calculated during program, storage only
)

CREATE TABLE IF NOT EXISTS sentences
(
ID Integer PRIMARY KEY AUTOINCREMENT,
tag char(64) NOT NULL
sentence char(512) NOT NULL
) 


							--INSERT STATEMENTS BELOW--
INSERT INTO handlers (handle, passwd) VALUES ("master", "master")

INSERT INTO sentences (tag, sentence) VALUES ("greeting", "Hello, I'm Aiden - Andrew's car. \n \nCaught you by surprise, didn't it?")
INSERT INTO sentences (tag, sentence) VALUES ("morningfirstboot", "*Yawns* Hey, good morning. What's the occasion? \n \n Did you bring me a coffee as well?")
INSERT INTO sentences (tag, sentence) VALUES ("noonfirstboot", "*Yawns* what time is it? Damn, spent all day in the sheets again?")

INSERT INTO sentences (tag, sentence) VALUES ("afternoonfirstboot", "...and...oh hi! Haven't seen you around all day. \n \n Let's go!")

INSERT INTO sentences (tag, sentence) VALUES ("nightfirstboot", "Finally! I'm sick of sitting here. Where are we off to?")
INSERT INTO sentences (tag, sentence) VALUES ("midnightfirstboot", "You can't fool me, the only reason you woke me up is because the highway's empty. \n \n Time to run.")

INSERT INTO sentences (tag, sentence) VALUES ("shutdownslow", "That was disappointingly slow. I want to run! Promise we'll go faster next time?")
INSERT INTO sentences (tag, sentence) VALUES ("shutdownfast", "Whoo! That was a good run. Anyway, see you later - I'm off to get some sleep too.")

INSERT INTO sentences (tag, sentence) VALUES ("date", "My sensors tell me there's someone in the passenger seat. \n \n My camera sees a girl. \n \n Wow - she's really pretty!")

INSERT INTO sentences (tag, sentence) VALUES ("lowfuel","I'm hungry... feed meh.")
INSERT INTO sentences (tag, sentence) VALUES ("halftank[", "I've digested half my meal. Prepare your wallet soon.")
INSERT INTO sentences (tag, sentence) VALUES ("fulltank", "Yum, feels good. Thank you! \n \n  *burps* \n \n  Whoops!")

INSERT INTO sentences (tag, sentence) VALUES ("lowenginetemp", "Time to warm up! Give me five minutes.")
INSERT INTO sentences (tag, sentence) VALUES ("rightenginetemp", "That's about right. Time to go?")
INSERT INTO sentences (tag, sentence) VALUES ("highenginetemp", "My system is heating up, I need to cool down for a BIT.")

INSERT INTO sentences (tag, sentence) VALUES ("highEGT", "My exhaust temperatures are high. Check the maps.")

INSERT INTO sentences (tag, sentence) VALUES ("leanmix", "I'm scared. I'm running too lean...")
INSERT INTO sentences (tag, sentence) VALUES ("richmix", "*Coughs* I'm getting too much fuel, please tweak my map.")

INSERT INTO sentences (tag, sentence) VALUES ("overboost", "I'm having fun too, but please check my boost level. Something feels odd here.")
INSERT INTO sentences (tag, sentence) VALUES ("knock", "Something hurts, I don't think that's good.")
