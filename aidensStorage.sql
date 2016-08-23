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


)

CREATE TABLE IF NOT EXISTS sentences
(
ID Integer PRIMARY KEY AUTOINCREMENT,
tag char(64) NOT NULL
sentence char(512) NOT NULL

) 

INSERT INTO handlers (handle, passwd) VALUES ("", "")
INSERT INTO sentences (sentence) VALUES ("")
