SELECT COUNT(DISTINCT author_lname) FROM books;
SELECT COUNT(DISTINCT author_lname, author_fname) FROM books;
SELECT COUNT(*) FROM books WHERE title LIKE "%the%";

SELECT author_lname, COUNT(*) FROM books GROUP BY author_lname;
SELECT author_fname, author_lname, COUNT(*) FROM books GROUP BY author_fname, author_lname;
SELECT released_year, COUNT(*) FROM books GROUP BY released_year;