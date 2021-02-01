SELECT DISTINCT author_fname, author_lname FROM books;

SELECT author_lname FROM books ORDER BY author_lname;
SELECT author_lname FROM books ORDER BY author_lname DESC;
SELECT released_year FROM books ORDER BY released_year;
SELECT title, author_fname, author_lname FROM books ORDER BY 2;
SELECT author_fname, author_lname FROM books ORDER BY author_lname, author_fname;
SELECT * FROM books LIMIT 4, 5;
SELECT * FROM books LIMIT 4, 18446744073709551615; -- go to the end
SELECT title, released_year FROM books ORDER BY released_year DESC LIMIT 5;
SELECT title, released_year FROM books ORDER BY released_year LIMIT 6, 5;

SELECT title, author_fname FROM books WHERE author_fname LIKE "%da%";
SELECT title, stock_quantity FROM books WHERE stock_quantity LIKE "____";
SELECT title FROM books WHERE title LIKE "%\%%";