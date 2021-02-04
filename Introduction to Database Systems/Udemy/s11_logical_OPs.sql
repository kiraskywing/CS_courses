SELECT title, released_year FROM books WHERE released_year = 2017;
SELECT title, released_year FROM books WHERE released_year != 2017;
SELECT title, author_lname FROM books WHERE author_lname = 'Harris';
SELECT title, author_lname FROM books WHERE author_lname != 'Harris';

SELECT title FROM books WHERE title LIKE 'W%';
SELECT title FROM books WHERE title LIKE '%W%';
SELECT title FROM books WHERE title NOT LIKE 'W%';

SELECT title, released_year FROM books WHERE released_year > 2000 ORDER BY released_year;
SELECT title, released_year FROM books WHERE released_year >= 2000 ORDER BY released_year;
SELECT title, released_year FROM books WHERE released_year < 2000;
SELECT title, released_year FROM books WHERE released_year <= 2000;
SELECT title, author_lname, released_year FROM books WHERE author_lname='Eggers' AND released_year > 2010;
SELECT title, author_lname, released_year, stock_quantity FROM books WHERE author_lname='Eggers' OR released_year > 2010 OR stock_quantity > 100;

SELECT title, released_year FROM books WHERE released_year BETWEEN 2004 AND 2015; 
SELECT title, released_year FROM books WHERE released_year NOT BETWEEN 2004 AND 2015;
SELECT name, birthdt FROM people WHERE birthdt BETWEEN '1980-01-01' AND '2000-01-01';
SELECT name, birthdt FROM people WHERE birthdt BETWEEN CAST('1980-01-01' AS DATETIME) AND CAST('2000-01-01' AS DATETIME);  -- datatype conversion, recommend