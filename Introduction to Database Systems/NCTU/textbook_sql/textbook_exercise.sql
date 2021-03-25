-- 3.1.a
select title from course where dept_name = 'Comp. Sci.' and credits = 3;
-- 3.1.b
select A.ID from takes A left join teaches B on A.course_id = B.course_id left join instructor C on B.ID = C.ID where C.name = 'Einstein';
-- 3.1.c
select max(salary) from instructor;
-- 3.1.d
select ID, name from instructor where salary = (select max(salary) from instructor);
-- 3.1.e
select A.course_id, A.sec_id, count(A.ID)
from takes A inner join section B 
on (A.course_id = B.course_id 
   and A.sec_id = B.sec_id
   and A.semester = 'Fall' and B.semester = 'Fall'
   and A.year = 2017 and B.year = 2017)
group by A.course_id, A.sec_id
-- 3.1.f
select max(prev.enrollment)
from 
(select count(A.ID) as enrollment
from takes A inner join section B 
on (A.course_id = B.course_id 
   and A.sec_id = B.sec_id
   and A.semester = 'Fall' and B.semester = 'Fall'
   and A.year = 2017 and B.year = 2017)
group by A.course_id, A.sec_id) as prev
-- 3.1.g
with prev as (
select A.course_id, A.sec_id, count(A.ID) as enrollment
from takes A inner join section B 
on (A.course_id = B.course_id 
   and A.sec_id = B.sec_id
   and A.semester = 'Fall' and B.semester = 'Fall'
   and A.year = 2017 and B.year = 2017)
group by A.course_id, A.sec_id)

select course_id, sec_id from prev 
where enrollment = (select max(enrollment) from prev)