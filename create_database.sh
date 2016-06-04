#!/bin/bash

sqlite3 db.sql "CREATE TABLE IF NOT EXISTS sensor_list (id INTEGER PRIMARY KEY AUTOINCREMENT, name VARCHAR(30) NOT NULL);"
sqlite3 db.sql "CREATE TABLE IF NOT EXISTS measurements (id INTEGER PRIMARY KEY AUTOINCREMENT, value INT NOT NULL, id_sensor INTEGER NOT NULL, FOREIGN KEY(id_sensor) REFERENCES sensor_list(id));"
sqlite3 db.sql "CREATE VIEW IF NOT EXISTS global AS SELECT s.name, m.value FROM measurements AS m JOIN sensor_list AS s ON m.id_sensor = s.id;"

sqlite3 db.sql "INSERT INTO sensor_list (name) VALUES ('new_sensor');"
sqlite3 db.sql "INSERT INTO measurements (value, id_sensor) VALUES ('1111', '1');"
