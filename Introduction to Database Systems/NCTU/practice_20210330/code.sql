-- Q1
select time_slot_id, building, room_number from section 
natural join teaches natural join instructor
where (semester, year, name) = ('Fall', 2017, 'Srinivasan');

-- Q2
select distinct name as instructor_name, course_id, title from teaches 
natural join course 
left join instructor on teaches.ID = instructor.ID 
order by name;

-- Q3
select takes.ID, student.name, count(course_id) as num from takes 
join student on takes.ID = student.ID
where takes.grade != 'F'
group by takes.ID; 