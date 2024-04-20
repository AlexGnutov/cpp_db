delete from genre;
insert into genre (name) values
	('jazz'),
	('rock'),
	('pop'),
	('blues'),
	('funk');
	
delete from artist;
insert into artist (name) values
	('Пергаментов К.П.'),
	('Ажоров Пётр'),
	('Закадром'),
	('Киркоров'),
	('Светикова'),
	('Стрелки'),
	('Перлы Упрыг'),
	('Свирестелки');

delete from artist_to_genre;
insert into artist_to_genre (artist_id, genre_id) values
	(1,1),
	(2,2),
	(3,3),
	(4,4),
	(5,5),
	(6,1),
	(7,2),
	(8,3);

delete from album;
insert into album (name, year) values
	('Навсегда ушло пройдя',2001),
	('Как же ты я мог',1991),
	('Любовь пробила люка дно',2019),
	('Хреноторий', 1925),
	('Жар',2018),
	('Пар',2018),
	('Вар',2023),
	('Бар',2021);

delete from album_to_artist;
insert into album_to_artist (album_id, artist_id) values
	(1,1),
	(2,2),
	(3,3),
	(4,4),
	(5,5),
	(6,6),
	(7,7),
	(8,8);

delete from song;
insert into song (name, duration, album_id) values 
	('Нет не правда, Серафим!', 100, 1),
	('Сколько можно через раз?',250,1),
	('Шанс нелепости',300,2),
	('Проза',500,2),
	('Нескончаемое утомление',1200,3),
	('Бздох',10,3),
	('Сизость', 160, 4),
	('Мурв - not my!', 156, 4),
	('Рыбоход', 210, 5),
	('Козинаки', 45, 5),
	('Шапы', 332, 6),
	('Трыктыква', 22, 6),
	('Риккоритм', 456, 7),
	('Полиандрас', 12, 7),
	('Совесть мой кругозор', 200, 8),
	('Правда', 100, 8);

delete from collection;
insert into collection (name, year) values 
	('18 best', 2018),
	('19 best', 2019),
	('2025 best', 2025),
	('2026 best', 2026),
	('2027 best', 2027),
	('2028 best', 2028),
	('2029 best', 2029),
	('2030 best', 2030);

delete from collection_to_song;
insert into collection_to_song (collection_id, song_id) values 
	(1, 1),
	(1, 2),
	(2, 3),
	(2, 4),
	(3, 5),
	(3, 6),
	(4, 7),
	(4, 8),
	(5, 9),
	(5, 10),
	(6, 11),
	(6, 12),
	(7, 13),
	(7, 14),
	(8, 15),
	(8, 16);




