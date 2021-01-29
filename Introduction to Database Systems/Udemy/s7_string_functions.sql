SELECT CONCAT(author_fname, ' ', author_lname) AS 'full_name' FROM books;
SELECT author_fname AS 'first', author_lname AS 'last', CONCAT(author_fname, ' ', author_lname) AS 'full' FROM books;
SELECT CONCAT_WS(' - ', title, author_fname, author_lname) FROM books;

SELECT SUBSTRING('Hello World', -7);
SELECT SUBSTRING(title, 1, 10) AS "short title" FROM books;
SELECT SUBSTR(title, 1, 10) AS "short title" FROM books;
SELECT CONCAT(SUBSTRING(title, 1, 10), "...") AS "short title" FROM books;

SELECT REPLACE("Hello world", 'l', '7');
SELECT REPLACE(title, 'e', '3') FROM books;

SELECT REVERSE("Hello World");
SELECT CONCAT("Hello", REVERSE("Hello"));
SELECT CONCAT(author_fname, REVERSE(author_fname)) FROM books;

SELECT CHAR_LENGTH("Hello world");
SELECT author_fname, CHAR_LENGTH(author_fname) AS "length" FROM books;

SELECT UPPER(title) FROM books;
SELECT LOWER(title) FROM books;