SELECT COUNT(DISTINCT author_lname) FROM books;
SELECT COUNT(DISTINCT author_lname, author_fname) FROM books;
SELECT COUNT(*) FROM books WHERE title LIKE "%the%";

SELECT author_lname, COUNT(*) FROM books GROUP BY author_lname;
SELECT author_fname, author_lname, COUNT(*) FROM books GROUP BY author_fname, author_lname;
SELECT released_year, COUNT(*) FROM books GROUP BY released_year;

SELECT MIN(released_year) FROM books;
SELECT MAX(pages) FROM books;
SELECT title, pages FROM books WHERE pages = (SELECT MIN(pages) FROM books);
SELECT title, pages FROM books ORDER BY pages ASC LIMIT 1;

SELECT author_fname, author_lname, MIN(released_year) FROM books GROUP BY author_fname, author_lname;
SELECT CONCAT(author_fname, ' ', author_lname) AS author, MAX(pages) AS 'longest book' FROM books GROUP BY author_lname, author_fname;

SELECT author_fname, author_lname, SUM(pages) FROM books GROUP BY author_fname, author_lname;

SELECT released_year, AVG(stock_quantity) FROM books GROUP BY released_year;
SELECT CONCAT(author_fname, " ", author_lname) AS full_name, AVG(pages) FROM books GROUP BY author_fname, author_lname;
SELECT released_year AS "year", COUNT(*) AS "# books", AVG(pages) AS "avg pages" FROM books GROUP BY released_year ORDER BY released_year;