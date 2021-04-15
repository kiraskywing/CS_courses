-- 3.1.a
select title from course where dept_name = 'Comp. Sci.' and credits = 3;
-- 3.1.b
select distinct A.ID from takes A
join teaches B on (A.course_id, A.sec_id, A.semester, A.year) = (B.course_id, B.sec_id, B.semester, B.year)
join instructor C on B.ID = C.ID
where C.name = 'Einstein';
-- 3.1.c
select max(salary) from instructor;
-- 3.1.d
select ID, name from instructor where salary = (select max(salary) from instructor);
-- 3.1.e
select sec_id, semester, year, count(ID) from takes 
where (semester, year) = ('Fall', 2017)
group by sec_id, semester, year;
-- 3.1.f
with subq as 
(
    select count(ID) as enrollment from takes 
    where (semester, year) = ('Fall', 2017)
    group by sec_id, semester, year
)
select max(enrollment) from subq;
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
select sum(credits * points) from takes 
natural join course
natural join grade_points where ID = '12345';
-- 3.2.b
select ID, round(sum(credits * points) / sum(credits), 2) as GPA from takes 
natural join course
natural join grade_points 
where ID = '12345';
-- 3.2.c
select ID, round(sum(credits * points) / sum(credits), 2) as GPA from takes 
natural join course
natural join grade_points 
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
select ID, count(sec_id) from instructor natural left join teaches group by ID;
-- 4.2.c
select sec_id, ID, name from section 
natural left join teaches 
natural left join instructor
where (semester, year) = ('Spring', 2018);
-- 4.2.d
select dept_name, count(ID) from department 
natural left join instructor group by dept_name;
-- 4.8.a
select ID, name, sec_id, semester, year, time_slot_id,
count(distinct building, room_number)
from instructor natural join teaches natural join section
group by ID, name, sec_id, semester, year, time_slot_id
having count(distinct building, room_number) > 1;