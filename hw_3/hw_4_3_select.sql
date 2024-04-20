-- из ссылки на странице задания: https://github.com/netology-code/sqlcpp-homeworks/tree/sqlcpp-7/04

-- Количество исполнителей в каждом жанре.
select name, count(atg.artist_id) from genre g join artist_to_genre atg on (atg.genre_id  = g.id) group by g.name;

--  Количество треков, вошедших в альбомы 2019–2020 годов.
select count(song.id) from song join album a on song.album_id = a.id and (a.year >= 2019 and a.year <= 2020); 

-- Средняя продолжительность треков по каждому альбому.
select a.name as album_name, avg(s.duration) from song s join album a on s.album_id = a.id group by a.name;

-- Все исполнители, которые не выпустили альбомы в 2020 году.
select a.name, a2.name, a2.year  from artist a 
	join album_to_artist ata on a.id = ata.artist_id
	join album a2 on ata.album_id = a2.id AND a2.year != 2020;

-- Названия сборников, в которых присутствует конкретный исполнитель (выберите его сами).
select c.name from collection c 
	join collection_to_song cts on c.id = cts.collection_id 
	join song s  on s.id = cts.song_id
	join album a on s.album_id = a.id 
	join album_to_artist ata on ata.album_id = a.id
	join artist a2 on ata.artist_id = a2.id and a2.name like '%Закадром%' group by c.name;



 