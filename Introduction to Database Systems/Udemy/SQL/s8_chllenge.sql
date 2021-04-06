SELECT title FROM books WHERE title LIKE '%stories%';

SELECT title, pages FROM books ORDER BY pages DESC LIMIT 1;

SELECT concat(title, ' - ', released_year) as summary FROM books 
order by released_year desc limit 3;

SELECT title, author_lname FROM books  where author_lname like "% %";

select title, released_year, stock_quantity from books order by stock_quantity, title limit 3;

SELECT title, author_lname FROM books ORDER BY author_lname, title;

select upper(concat('MY FAVORITE AUTHOR IS ', author_fname, ' ', author_lname, '!')) as yell from books order by author_lname;