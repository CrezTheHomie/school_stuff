create table World
  (name varchar(25) not null,
  continent varchar(25),
  area integer,
  population integer,
  gdp integer,
  primary key (name));
  
  insert into World values('Afghanistan', 'Asia', 652230, 25500100, 20343);
  insert into World values('Albania', 'Europe', 28748, 2831741, 12960);
  insert into World values('Algeria','Africa',2381741,37100000,188681);
  insert into World values('Andorra','Europe',468,78115,3712);
  insert into World values('Angola','Africa',1246700,20609294,100990);
  
  select * from World;
  select name from World where continent = 'Africa';
  select name, gdp from World where area < 50000;
  
  update World set gdp = gdp + 1000 where continent = 'Europe';
  
  select sum (gdp) as total from World where continent <> 'Europe';