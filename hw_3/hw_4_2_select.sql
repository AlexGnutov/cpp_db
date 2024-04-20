
-- Название и продолжительность самого длительного трека.
select name, duration from song where duration = (select max(duration) from song);

-- Название треков, продолжительность которых не менее 3,5 минут.
select name, duration from song where duration > cast(3.5*60 as int);

-- Названия сборников, вышедших в период с 2018 по 2020 годы включительно.
select name from collection where year >= 2018 and year <= 2020;

-- Исполнители, чьё имя состоит из одного слова.
select name from artist where name not like '% %';

-- Название треков, которые содержат слова «мой» или «my».
select name from song where name like '%мой%' or name like '%my%';