select count(*) from books;

SELECT released_year, COUNT(*) FROM books GROUP BY released_year;

SELECT Sum(stock_quantity) FROM BOOKS;

select concat(author_fname, ' ', author_lname) as full_name, avg(released_year) 
from books group by author_fname, author_lname;

select pages, concat(author_fname, ' ', author_lname) as full_name
from books order by pages desc limit 1;

select released_year as 'year', count(*) as '# books', avg(pages) as 'avg pages' from books
group by released_year order by released_year;