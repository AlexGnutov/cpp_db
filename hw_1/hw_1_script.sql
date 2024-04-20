DROP TABLE IF EXISTS genre;
CREATE TABLE genre (
	id 		SERIAL PRIMARY KEY,
	name 	varchar(256)
);

DROP TABLE IF EXISTS artist;
CREATE TABLE artist (
	id			SERIAL PRIMARY KEY,
	name		varchar(256) NOT NULL UNIQUE,
	genre_id	integer NOT NULL REFERENCES genre(id)
);

DROP TABLE IF EXISTS album;
CREATE TABLE album (
	id			SERIAL PRIMARY KEY,
	name		varchar(256) NOT NULL,
	year		integer NOT NULL,
	artist_id	integer NOT NULL REFERENCES artist(id)
);

DROP TABLE IF EXISTS song;
CREATE TABLE song (
	id 			SERIAL PRIMARY KEY,
	name		varchar(256) NOT NULL,
	duration	integer NOT NULL,
	album_id	integer NOT NULL REFERENCES album(id)
);
