CREATE TABLE cats 
( 
    cat_id INT NOT NULL AUTO_INCREMENT, 
    name   VARCHAR(100), 
    breed  VARCHAR(100), 
    age    INT, 
    PRIMARY KEY (cat_id) 
); 

INSERT INTO cats(name, breed, age) 
VALUES ('Ringo', 'Tabby', 4),
       ('Cindy', 'Maine Coon', 10),
       ('Dumbledore', 'Maine Coon', 11),
       ('Egg', 'Persian', 4),
       ('Misty', 'Tabby', 13),
       ('George Michael', 'Ragdoll', 9),
       ('Jackson', 'Sphynx', 7);

SELECT cat_id, name, age FROM cats;
SELECT * FROM cats WHERE age=4;
SELECT * FROM cats WHERE name='Egg';
SELECT * FROM cats WHERE cat_id=age;
SELECT name AS 'cat name', breed AS 'kitty breed' FROM cats;
UPDATE cats SET breed='Shorthair' WHERE breed='Tabby';
UPDATE cats SET age=14 WHERE name='Misty'; 
DELETE FROM cats WHERE name='Egg';
DELETE FROM cats; -- Delete every entry in the table, but the table still exists.