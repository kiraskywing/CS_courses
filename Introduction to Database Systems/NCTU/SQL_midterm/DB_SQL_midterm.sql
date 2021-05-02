-- Q1.
select dept_name, avg(salary) as average_salary from department 
natural left join instructor 
group by dept_name 
order by average_salary desc;

-- Q2.
select title, count(ID) as cnt from takes 
natural join course 
where (semester, year) = ('Fall', 2017) 
group by course_id;

-- Q3.
select B.name as 'student name', C.name as 'instructor name' 
from advisor A
join student B on A.s_ID = B.ID
join instructor C on A.i_ID = C.ID
order by C.name;

-- Q4.
select B.name as 'name', A.course_id, B.dept_name as 'student dept', C.dept_name as 'course dept'
from takes A 
natural join student B
join course C on A.course_id = C.course_id
where B.dept_name != C.dept_name
order by name;

-- Q5.
select name, (salary - budget) as more from instructor
natural join department
where salary - budget > 0
order by salary - budget desc;

-- Q6.
select dept_name, count(course_id) as 'num_course' 
from course
group by dept_name
order by num_course desc;

-- Q7.
select A.course_id, B.title as 'course_title', A.prereq_id, C.title as 'prereq_title'
from prereq A
join course B on A.course_id = B.course_id
join course C on A.prereq_id = C.course_id;

-- Q8.
with subq as 
(
select B.name, B.ID as 'st_id', C.title, D.ID as 'in_id'
from takes A natural join student B natural join course C
left join teaches D on (A.course_id, A.sec_id, A.semester, A.year) = (D.course_id, D.sec_id, D.semester, D.year)
)
select name as student_name, title as course_title from subq, advisor 
where (st_id, in_id) = (s_ID, i_ID);

-- Q9.
select time_slot_id, building, room_number 
from takes natural join section natural join student
where (name, semester, year) = ('Shankar', 'Fall', 2017);

-- Q10.
select sum((end_hr - start_hr) * 60 + (end_min - start_min)) as 'sum(total)' 
from teaches 
natural join section natural join instructor natural join time_slot
where (name, semester, year, day) = ('Srinivasan', 'Fall', 2017, 'W');

-- Q11.
with subq as 
(
select course_id, year,
case
	when grade = 'F' then 0.0
	when grade != 'F' then 1.0
end as rate
from takes
where grade is not null
)
select course_id, floor(sum(rate) / count(*) * 100) as 'pass_rate'
from subq
group by course_id;