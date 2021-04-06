DROP TABLE shirts;
CREATE TABLE shirts
(
    shirt_id INT NOT NULL AUTO_INCREMENT,
    article VARCHAR(100),
    color VARCHAR(100),
    shirt_size VARCHAR(100),
    last_worn INT,
    PRIMARY KEY(shirt_id)
);
    
insert into shirts(article, color, shirt_size, last_worn)
values 
('t-shirt', 'white', 'S', 10),
('t-shirt', 'green', 'S', 200),
('polo shirt', 'black', 'M', 10),
('tank top', 'blue', 'S', 50),
('t-shirt', 'pink', 'S', 0),
('polo shirt', 'red', 'M', 5),
('tank top', 'white', 'S', 200),
('tank top', 'blue', 'M', 15);

INSERT INTO shirts(color, article, shirt_size, last_worn) 
VALUES('purple', 'polo shirt', 'M', 50);

select color, article, shirt_size, last_worn from shirts where shirt_size = 'M';

update shirts set shirt_size='L' where article = 'polo shirt';

update shirts set last_worn = 0 where last_worn = 15;

update shirts set shirt_size='XS', color='off white' where color='white';

delete from shirts where last_worn >= 200;

delete from shirts where article='tank top';

delete from shirts;