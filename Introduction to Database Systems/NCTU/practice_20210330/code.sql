-- Q1
select A.time_slot_id, A.building, A.room_number from section A
join teaches B on (A.sec_id = B.sec_id and A.course_id = B.course_id)
join instructor C on B.ID = C.ID
where (A.year = 2017 and A.semester = 'Fall' and C.name = 'Srinivasan');

-- Q2
select distinct B.name as instructor_name, A.course_id, C.title from teaches A
join instructor B on A.ID = B.ID 
join course C on A.course_id = C.course_id
order by B.name;

-- Q3
select takes.ID, student.name, count(course_id) as num from takes 
join student on takes.ID = student.ID
where takes.grade != 'F'
group by takes.ID; 