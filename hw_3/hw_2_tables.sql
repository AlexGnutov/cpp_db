DROP TABLE IF exists genre CASCADE;
CREATE TABLE genre (
	id 		SERIAL PRIMARY KEY,
	name 	varchar(256)
);

DROP TABLE IF EXISTS artist CASCADE;
CREATE TABLE artist (
	id			SERIAL PRIMARY KEY,
	name		varchar(256) NOT NULL UNIQUE	
);

DROP TABLE IF EXISTS artist_to_genre;
CREATE TABLE artist_to_genre (
	id 			SERIAL PRIMARY KEY,
	genre_id	integer NOT NULL REFERENCES genre(id),
	artist_id	integer NOT NULL REFERENCES artist(id)
);

DROP TABLE IF EXISTS album CASCADE;
CREATE TABLE album (
	id			SERIAL PRIMARY KEY,
	name		varchar(256) NOT NULL,
	year		integer NOT NULL
);

DROP TABLE IF EXISTS album_to_artist;
CREATE TABLE album_to_artist (
	id 			SERIAL PRIMARY KEY,
	album_id	integer NOT NULL REFERENCES album(id),
	artist_id	integer NOT NULL REFERENCES artist(id)
);

DROP TABLE IF EXISTS song CASCADE;
CREATE TABLE song (
	id 			SERIAL PRIMARY KEY,
	name		varchar(256) NOT NULL,
	duration	integer NOT NULL,
	album_id	integer NOT NULL REFERENCES album(id)
);

drop table if exists collection CASCADE;
create table collection (
	id 		serial primary key,
	name 	varchar(256) not null,
	year	integer not null
);

drop table if exists collection_to_song;
create table collection_to_song (
	id				serial primary key,
	collection_id	integer not null references collection(id),
	song_id			integer not null references song(id)
);




