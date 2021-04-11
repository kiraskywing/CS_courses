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

-- 3.2.a
select sum(credits * points)
from takes, course, grade_points
where takes.grade = grade_points.grade
      and takes.course_id = course.course_id
      and ID = '12345';
-- 3.2.b
select round(prev.GPA, 2) as GPA 
from (select sum(credits * points) / sum(credits) as GPA
      from takes, course, grade_points
      where takes.grade = grade_points.grade
            and takes.course_id = course.course_id
            and ID = '12345') as prev;
-- 3.2.c
select ID, round(sum(points * credits) / sum(credits), 2) as GPA
from takes, course, grade_points
where takes.grade = grade_points.grade
and takes.course_id = course.course_id
group by ID;

-- 3.3.a
update instructor set salary = salary * 1.1 where dept_name = 'Comp. Sci.';
-- 3.3.b
delete from course where course_id not in (select course_id from section);
-- 3.3.c
insert into instructor (select ID, name, dept_name, 30000 from student where tot_cred > 100);

-- 4.1
select distinct C.title, B.name from teaches A
join instructor B on A.ID = B.ID
join course C on A.course_id = C.course_id
where semester = 'Spring' and year = 2017;
-- 4.2.a
select A.ID, count(B.sec_id) as '# of sections' from instructor A
left join teaches B on A.ID = B.ID
group by A.ID;
-- 4.2.c
select A.course_id, A.sec_id, C.ID, C.name from section A
left join teaches B 
    on A.course_id = B.course_id 
    and A.sec_id = B.sec_id 
    and A.semester = B.semester 
    and A.year = B.year
left join instructor C
    on B.ID = C.ID
where A.semester = 'Spring' and A.year = 2018;
-- 4.2.d
select A.dept_name, count(B.ID) as '# of instructors' from department A
left join instructor B 
on A.dept_name = B.dept_name 
group by A.dept_name;
-- 4.8.a
select ID, name, sec_id, semester, year, time_slot_id,
count(distinct building, room_number)
from instructor natural join teaches natural join section
group by ID, name, sec_id, semester, year, time_slot_id
having count(distinct building, room_number) > 1;