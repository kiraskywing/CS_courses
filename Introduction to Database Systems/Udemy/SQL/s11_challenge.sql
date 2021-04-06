select * from books where released_year < 1980;

select * from books where author_lname in ('Eggers', 'Chabon');

select * from books where author_lname = 'Lahiri' and released_year > 2000;

select * from books where pages between 100 and 200;

select * from books where author_lname like 'C%' or author_lname like 'S%';

select title, author_lname, 
case when title like '%stories' then 'Short stories'
     when title like '%Just Kids%' or title like '%A Heartbreaking Work%' then 'Memoir'
     else 'Novel'
     end as TYPE
from books;

select author_lname, 
case when count(*) <= 1 then concat(count(*), ' book') 
else concat(count(*), ' books') 
end as COUNT 
from books group by author_lname, author_fname;